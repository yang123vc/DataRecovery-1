#ifndef NTFSR_
#define NTFSR_

 
//#include <windows.h>
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//#include <direct.h>

#include "ntfs.h"



#define FIXOFFSET(x, y) ((CHAR*)(x) + (y))

ULONG     BytesPerFileRecord;
UINT     BytesPerCluster;
BOOT_BLOCK    BootBlk;
PFILE_RECORD_HEADER MFT;
HANDLE     hVolume;
FILE     *pFLog;

BOOL BitSet(PUCHAR Bitmap, ULONG Idx)
{
      return (Bitmap[Idx >> 3] & (1 << (Idx & 7))) != 0;
}

void FixupUpdateSequenceArray(PFILE_RECORD_HEADER FileRecord)
{
      PUSHORT UsAry = PUSHORT(FIXOFFSET(FileRecord, FileRecord->Ntfs.UsaOffset));
      PUSHORT Sector = PUSHORT(FileRecord);

      for (ULONG Idx = 1; Idx < FileRecord->Ntfs.UsaCount; Idx++)
      {
             Sector[255] = UsAry[Idx];
             Sector += 256;
      }
}
void ReadSector(ULONGLONG Sector, ULONG Cnt, PVOID Buffer)
{
      ULARGE_INTEGER Offset;
      OVERLAPPED Overlap = {0};
      ULONG ReadBytes, CntIdx = 0, NeedReadByte = Cnt * BootBlk.BytesPerSector;

       Offset.QuadPart   = Sector * BootBlk.BytesPerSector;
       Overlap.Offset   = Offset.LowPart;
      Overlap.OffsetHigh = Offset.HighPart;

      ReadFile(hVolume, Buffer, NeedReadByte, &ReadBytes, &Overlap);

      if(ReadBytes != NeedReadByte)
      {
            while(CntIdx < Cnt)
            {
                    Overlap.Offset   = Offset.LowPart;
                  Overlap.OffsetHigh = Offset.HighPart;

                  ReadFile(hVolume, Buffer, BootBlk.BytesPerSector, &ReadBytes, &Overlap);

                  if(ReadBytes != BootBlk.BytesPerSector)
                  {
					    char te[MAX_PATH];
					    sprintf(te,"Read Sector failed: %d:%d:%d\n", Offset.LowPart, Cnt * BootBlk.BytesPerSector, ReadBytes);
                         MessageBox(MainW,te,"Error !",MB_OK | MB_ICONERROR);
						return;
                  }

                  Buffer = (UCHAR*)Buffer + BootBlk.BytesPerSector;
                   Offset.QuadPart += BootBlk.BytesPerSector;
                  ++CntIdx;
            }
      }
      return;
}

void ReadLCN(ULONGLONG LCN, ULONG Cnt, PVOID Buffer)
{
      ReadSector(LCN * BootBlk.SectorsPerCluster, Cnt * BootBlk.SectorsPerCluster, Buffer);
}


ULONG AttributeLength(PATTRIBUTE Attr)
{
      return Attr->Nonresident == FALSE
            ? PRESIDENT_ATTRIBUTE(Attr)->ValueLength: ULONG(PNONRESIDENT_ATTRIBUTE(Attr)->DataSize);
}

ULONG AttributeLengthAllocated(PATTRIBUTE Attr)
{

      return Attr->Nonresident == FALSE? PRESIDENT_ATTRIBUTE(Attr)->ValueLength:
            ULONG(PNONRESIDENT_ATTRIBUTE(Attr)->AllocatedSize);
}

ULONG RunLength(PUCHAR Run)
{
      return (*Run & 0xf) + ((*Run >> 4) & 0xf) + 1;
}

ULONGLONG RunCount(PUCHAR Run)
{
      
      UCHAR Idx = *Run & 0xF;
      ULONGLONG Cnt = 0;

      for (; Idx > 0; Idx--)
            Cnt = (Cnt << 8) + Run[Idx];
      return Cnt;
}

LONGLONG RunLCN(PUCHAR Run)
{
      UCHAR VCNNumEndIdx = *Run & 0xf;
      UCHAR LCNIdxValNum = (*Run >> 4) & 0xf;

      LONGLONG LCN = LCNIdxValNum == 0 ? 0 : CHAR(Run[VCNNumEndIdx + LCNIdxValNum]);

      for (LONG Idx = VCNNumEndIdx + LCNIdxValNum - 1; Idx > VCNNumEndIdx; Idx--)
            LCN = (LCN << 8) + Run[Idx];
      return LCN;
}

BOOL FindRun(PNONRESIDENT_ATTRIBUTE Attr, ULONGLONG VCN, PULONGLONG LCN, PULONGLONG Cnt)
{
      INT Idx;

      if (VCN < Attr->LowVcn || VCN > Attr->HighVcn)
            return FALSE;

      *LCN = 0;
      ULONGLONG Base = Attr->LowVcn;

      PUCHAR Run = PUCHAR(FIXOFFSET(Attr, Attr->RunArrayOffset));

      for (Idx = 0; *Run != 0; Run += RunLength(Run), ++Idx)
      {
            *LCN += RunLCN(Run);
            *Cnt   = RunCount(Run);

            if (Base <= VCN && VCN < Base + *Cnt)
            {
                  *LCN = RunLCN(Run) == 0 ? 0 : *LCN + VCN - Base;
                  *Cnt    -= ULONG(VCN - Base);
                  return TRUE;
            }
            else
            {
                  Base += *Cnt;
            }
      }
      *Cnt = 0;
      return FALSE;
}


void ReadExternalAttribute(PNONRESIDENT_ATTRIBUTE Attr, ULONGLONG VCN, ULONG Cnt, PVOID Buffer)
{
      ULONGLONG LCN, RunClstrCnt;
      ULONG RdCnt, Left;
      PUCHAR DataPtr = PUCHAR(Buffer);

      for (Left = Cnt; Left > 0; Left -= RdCnt)
      {
            FindRun(Attr, VCN, &LCN, &RunClstrCnt);

            RdCnt = ULONG(min(RunClstrCnt, Left));
            ULONG RdBytes = RdCnt * BytesPerCluster;

            if (LCN == 0)
            {
                  memset(DataPtr, 0, RdBytes);
            }
            else
            {
                   ReadLCN(LCN, RdCnt, DataPtr);
            }

             VCN   += RdCnt;
            DataPtr += RdBytes;
      }
}

void ReadAttribute(PATTRIBUTE Attr, PVOID Buffer)
{
      if (Attr->Nonresident == FALSE)
      {
            PRESIDENT_ATTRIBUTE RAttr = PRESIDENT_ATTRIBUTE(Attr);
            memcpy(Buffer, FIXOFFSET(RAttr, RAttr->ValueOffset), RAttr->ValueLength);
      }
      else
      {
            PNONRESIDENT_ATTRIBUTE NAttr = PNONRESIDENT_ATTRIBUTE(Attr);
            ReadExternalAttribute(NAttr, 0, ULONG(NAttr->HighVcn) + 1, Buffer);
      }
}

PATTRIBUTE FindAttribute(PFILE_RECORD_HEADER FileRecord, ATTRIBUTE_TYPE Tp, PWSTR Name)
{
      for (PATTRIBUTE Attr = PATTRIBUTE(FIXOFFSET(FileRecord, FileRecord->AttributesOffset));
            Attr->AttributeType != -1;
            Attr = PATTRIBUTE(FIXOFFSET(Attr, Attr->Length)))
      {
            if (Attr->AttributeType == Tp)
            {
                   if (Name == 0 && Attr->NameLength == 0)
                  {
                        return Attr;
                  }

                  if (Name != 0 && wcslen(Name) == Attr->NameLength
                        && _wcsicmp(Name, PWSTR(FIXOFFSET(Attr, Attr->NameOffset))) == 0)
                  {
                        return Attr;
                  }
            }
      }
      return NULL;
}

PATTRIBUTE FindAttributeFileName(PFILE_RECORD_HEADER FileRecord, PWSTR Name)
{
      PATTRIBUTE AttrCp = NULL;
      PFILENAME_ATTRIBUTE FileName;

      for (PATTRIBUTE Attr = PATTRIBUTE(FIXOFFSET(FileRecord, FileRecord->AttributesOffset));
            Attr->AttributeType != -1;
            Attr = PATTRIBUTE(FIXOFFSET(Attr, Attr->Length)))
      {
            if (Attr->AttributeType == AttributeFileName)
            {
                 
                  if (Name == 0 && Attr->NameLength == 0)
                  {
                        AttrCp = Attr;
                        FileName = PFILENAME_ATTRIBUTE(FIXOFFSET(AttrCp,
                              PRESIDENT_ATTRIBUTE(AttrCp)->ValueOffset));

                        if(FileName->NameType == 1)
                              return AttrCp;
                  }

                  if (Name != 0 && wcslen(Name) == Attr->NameLength
                        && _wcsicmp(Name, PWSTR(FIXOFFSET(Attr, Attr->NameOffset))) == 0)
                  {
                        AttrCp = Attr;
                        FileName = PFILENAME_ATTRIBUTE(FIXOFFSET(AttrCp,
                              PRESIDENT_ATTRIBUTE(AttrCp)->ValueOffset));

                        if(FileName->NameType == 1)
                              return AttrCp;
                  }
            }
      }
      return AttrCp;
}

void ReadVCN(PFILE_RECORD_HEADER FileRecord, ATTRIBUTE_TYPE Tp, ULONGLONG VCN, ULONG Cnt, PVOID Buffer)
{
      PNONRESIDENT_ATTRIBUTE Attr = PNONRESIDENT_ATTRIBUTE(FindAttribute(FileRecord, Tp, 0));

      if (Attr == 0 || (VCN < Attr->LowVcn || VCN > Attr->HighVcn))
      {
            PATTRIBUTE Attrlist = FindAttribute(FileRecord, AttributeAttributeList, 0);
            DebugBreak();
      }
      ReadExternalAttribute(Attr, VCN, Cnt, Buffer);
}

ULONGLONG GetLCN(ULONG Idx)
{
      ULONGLONG VCN = ULONGLONG(Idx) * BytesPerFileRecord / BytesPerCluster;
      PNONRESIDENT_ATTRIBUTE Attr = PNONRESIDENT_ATTRIBUTE(FindAttribute(MFT, AttributeData, 0));
      ULONGLONG LCN, RunClstrCnt;

      if(FindRun(Attr, VCN, &LCN, &RunClstrCnt) == FALSE)
            return 0;
      return LCN;
}

void ReadFileRecord(ULONG Idx, PFILE_RECORD_HEADER FileRecord)
{
      ULONG ClstrNum = BootBlk.ClustersPerFileRecord;

      if (ClstrNum > 0x80)
            ClstrNum = 1;
      PUCHAR BufPtr = new UCHAR[BytesPerCluster * ClstrNum];

      ULONGLONG VCN = ULONGLONG(Idx) * BytesPerFileRecord / BytesPerCluster;

    ReadVCN(MFT, AttributeData, VCN, ClstrNum, BufPtr);

      LONG FRPerCluster = (BytesPerCluster / BytesPerFileRecord) - 1;
      ULONG FRIdx = FRPerCluster > 0 ? (Idx & FRPerCluster) : 0;

      memcpy(FileRecord, BufPtr + FRIdx * BytesPerFileRecord, BytesPerFileRecord);
      delete [] BufPtr;
}

void ListDeleted()
{
      ULONG Idx;
      PATTRIBUTE Attr = (PATTRIBUTE)FindAttribute(MFT, AttributeBitmap, 0);
      PUCHAR Bitmap   = new UCHAR[AttributeLengthAllocated(Attr)];

      ReadAttribute(Attr, Bitmap);
      ULONG Num = AttributeLength(FindAttribute(MFT, AttributeData, 0)) / BytesPerFileRecord;

        fwprintf(pFLog, L"\nId Number      File Size     File Name \n\n");

      PFILE_RECORD_HEADER FileRecord = PFILE_RECORD_HEADER(new UCHAR[BytesPerFileRecord]);

      for (Idx = 0; Idx < Num; Idx++)
      {
            if (BitSet(Bitmap, Idx))
                  continue;

            ReadFileRecord(Idx, FileRecord);
            FixupUpdateSequenceArray(FileRecord);

            if (FileRecord->Ntfs.Type == 'ELIF' && (FileRecord->Flags & 1) == 0)
            {
                  Attr = (PATTRIBUTE)FindAttributeFileName(FileRecord, 0);
                  if (Attr == 0)
                        continue;

                  PFILENAME_ATTRIBUTE Name = PFILENAME_ATTRIBUTE(FIXOFFSET(Attr, PRESIDENT_ATTRIBUTE(Attr)->ValueOffset));
                 fwprintf(pFLog, L"%8u, %12.2f MB,  %ws\n", Idx, double((Name->AllocatedSize)/(1024*1024.0)), Name->Name);
            }
      }
      delete [] Bitmap;
      delete [] (UCHAR*)FileRecord;
}

void LoadMFT()
{
      BytesPerCluster = BootBlk.SectorsPerCluster * BootBlk.BytesPerSector;
      BytesPerFileRecord = BootBlk.ClustersPerFileRecord < 0x80
            ? BootBlk.ClustersPerFileRecord * BytesPerCluster : (1 << (0x100 - BootBlk.ClustersPerFileRecord));

      MFT = PFILE_RECORD_HEADER(new UCHAR[BytesPerFileRecord]);
      ReadSector(BootBlk.MftStartLcn * BootBlk.SectorsPerCluster,BytesPerFileRecord / BootBlk.BytesPerSector, MFT);
      FixupUpdateSequenceArray(MFT);
}

VOID UnloadMFT()
{
     delete [] (UCHAR*)MFT;
}

void RecoverFile(ULONG Idx, LPCSTR NewFileName)
{
      PFILE_RECORD_HEADER FileRecord = PFILE_RECORD_HEADER(new UCHAR[BytesPerFileRecord]);
      ULONG Written, BufferSize, DataSize, AllocatedSize;
      ReadFileRecord(Idx, FileRecord);
      FixupUpdateSequenceArray(FileRecord);

      if (FileRecord->Ntfs.Type != 'ELIF')
      {
            delete [] (UCHAR*)FileRecord;
		    char te[MAX_PATH];
		     sprintf(te,"\nFailed. FileRecord->Ntfs.Type != 'ELIF'\n");
		   SetDlgItemText(MainW,IDC_STATIC3,te);
			return;
      }


      PATTRIBUTE Attr = FindAttribute(FileRecord, AttributeData, 0);

      if (Attr == 0)
      {
            delete [] (UCHAR*)FileRecord;
		     char te[MAX_PATH];
		     sprintf(te,"\nFailed, Attribute == 0!\n");
		    SetDlgItemText(MainW,IDC_STATIC3,te);
            return;
      }

      DataSize   = AttributeLength(Attr);
      AllocatedSize = AttributeLengthAllocated(Attr);
      BufferSize   = AllocatedSize > DataSize ? AllocatedSize : DataSize;

      BufferSize    = BufferSize / BootBlk.BytesPerSector * BootBlk.BytesPerSector + BootBlk.BytesPerSector;

      PUCHAR Buffer = new UCHAR[BufferSize];

      ReadAttribute(Attr, Buffer);

      HANDLE hFile = CreateFile(NewFileName, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);


      if(hFile == INVALID_HANDLE_VALUE)
      {
             char te[MAX_PATH];
		    sprintf(te,"\n RecoverFile() - CreateFile() failed, Error : %u\n", GetLastError());
			MessageBox(MainW,te,"Error !",MB_OK | MB_ICONERROR);
             goto a1;
      }

      if(WriteFile(hFile, Buffer, DataSize, &Written, 0) == 0)
      {
          	 char te[MAX_PATH];
		     sprintf(te,"\n RecoverFile() - WriteFile() failed, Error : %u\n", GetLastError());
			MessageBox(MainW,te,"Error !",MB_OK | MB_ICONERROR);
             goto a1;
      }

       if(Written != DataSize)
	   {
		     char te[MAX_PATH];
		     sprintf(te,"\n Writing The File Data failed !, Error %u\n", GetLastError());
		    SetDlgItemText(MainW,IDC_STATIC3,te);
	   }
            
a1:
      CloseHandle(hFile);
      delete [] Buffer;
      delete [] (UCHAR*)FileRecord;
}
 
void  NtfsRecoverFile(char *Drive,unsigned long Idx,char *FileName,int Choice)
{
	    ULONG Read;
       LPCSTR OriFileName;
       char FileN[273];

     //  strcpy(FileN,"Recovered Files\\");
	   sprintf(FileN,"%s\\",Tfil);
       strcat(FileN,FileName);
       OriFileName = (LPCSTR)FileN;

      // _mkdir( "Recovered Files" );

      pFLog  = fopen("lodf.txt", "w");
 
      hVolume = CreateFile(
            Drive,
            GENERIC_READ | GENERIC_WRITE , FILE_SHARE_READ | FILE_SHARE_WRITE,
            0,
            OPEN_EXISTING,
            0,
            0);

      if( hVolume == INVALID_HANDLE_VALUE)
      {
		      char te[MAX_PATH];
		    sprintf(te,"\n  Unable To Open Drive : %u\n", GetLastError());
		    MessageBox(MainW,te,"Error !",MB_OK | MB_ICONERROR);
            goto a1;
      }

      if(ReadFile(hVolume, &BootBlk, sizeof(BOOT_BLOCK), &Read, 0) == 0)
      {
              char te[MAX_PATH];
		     sprintf(te,"\n  Drive Reading Error ! : %u\n", GetLastError());
		    MessageBox(MainW,te,"Error !",MB_OK | MB_ICONERROR);
              goto a1;
      }
      if(Choice == 0)
      {
           LoadMFT();
           ListDeleted();
      }
      else if(Choice == 1)
      {
            LoadMFT();
            ListDeleted();
            
            RecoverFile(Idx, OriFileName);
            
             char te[MAX_PATH];
		      sprintf(te,"Scanning Sector Number : %ld",Idx);
			 SetDlgItemText(MainW,IDC_STATIC2,te);
		     sprintf(te,"Recoverd File : %d",++fileNo1);
            SetDlgItemText(MainW,IDC_STATIC6,te);
      }
a1:
       UnloadMFT();
      CloseHandle(hVolume);
      fclose(pFLog);
}
#endif