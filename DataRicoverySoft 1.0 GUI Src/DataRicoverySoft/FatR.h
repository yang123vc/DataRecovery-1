#ifndef FATR_H
#define FATR_H

//#include <iostream>
//using namespace std;

FILE     *pFLogf;

void ListDeleted(ULONG StartCluster)
  {
         ULONG Read;
         SDirectory SDir;
         ULONG RootDirectoryCluster = (fat32m.ResverdSector+fat32m.SectorPerFAT*fat32m.NumberOfFat+(fat32m.RootDir1stCluster-2)*fat32m.SectorsPerCluster +StartCluster)*  fat32m.BytesPerSector ;
         ULARGE_INTEGER Offset;
         OVERLAPPED Overlap = {0};

         Offset.QuadPart   = RootDirectoryCluster ;
         Overlap.Offset   = Offset.LowPart;

      if(ReadFile(hVolume1, &SDir, 512*16, &Read, &Overlap) == 0)
      {
		 /* SetDlgItemText(MainW,IDC_STATIC2,"Drive Reading Error !");
              exit(1);*/
		  
      }
        ULONG g;
      for(g =0;g<16*16;g++)
      {    
          if((int)SDir.F[g].name[0] == 229 && (int)SDir.F[g].StartClusterNo != 0)
               fprintf(pFLogf,"\n %15u %30u Byte %10.3s %15.2f MB  %20.8s ",SDir.F[g].StartClusterNo ,(SDir.F[g].FileLength),SDir.F[g].ext,(double)(SDir.F[g].FileLength)/(1024*1024),SDir.F[g].name);
           if((int)SDir.F[g].StartClusterNo != 0 && (int)SDir.F[g].FileLength == 4096 || (int)SDir.F[g].FileLength == 8192 )
           {
                ListDeleted(((int)SDir.F[g].StartClusterNo-2)*fat32m.SectorsPerCluster);
           }
     }
  }
void RecoverFilesFat1(char *Drive,unsigned long int Location,ULONGLONG sizez,  char *Name)
{
	
	      char te[MAX_PATH];
		 sprintf(te,"Scanning Sector Number : %ld",Location);
			 SetDlgItemText(MainW,IDC_STATIC2,te);
		     sprintf(te,"Recoverd File : %d",++FileNo);
            SetDlgItemText(MainW,IDC_STATIC6,te);
  
			 sprintf(te,"Copy File ->   File Size :%ld KB .....", (sizez)/1024);
            SetDlgItemText(MainW,IDC_STATIC4,te);
        sprintf(te," File Found..., Save As %s",Name);
			 SetDlgItemText(MainW,IDC_STATIC3,te);
		    
         
      
     ULONG StartCluster = (fat32m.ResverdSector+fat32m.SectorPerFAT*fat32m.NumberOfFat+(fat32m.RootDir1stCluster-2)*fat32m.SectorsPerCluster+(Location-2)*fat32m.SectorsPerCluster)* fat32m.BytesPerSector ;
      HANDLE hSrc, hDest;
      DWORD dwRead, dwWritten;
      DWORD  dwBytesRead, dwBytesWritten, dwPos ,pp;
      char pBuffer[512];

      hSrc = CreateFile((LPCSTR)Drive,  GENERIC_READ | GENERIC_WRITE ,
                        FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,
           OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

      if (hSrc == INVALID_HANDLE_VALUE)
      {
		  sprintf(er,"Unable to open :",Drive);
		  SetDlgItemText(MainW,IDC_STATIC2,er);
          exit(1);
      }

      hDest = CreateFile( Name, GENERIC_WRITE ,
                        FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,
                        CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

      if (hDest == INVALID_HANDLE_VALUE)
       {
             cout << "Unable to create File : "  <<Name;
             CloseHandle(hSrc);
             exit(1);
       }

     int i;
     for(i=0;i<sizez;i=i+512)
      {
           pp = SetFilePointer(hSrc,StartCluster, NULL, 0);
           ReadFile(hSrc, pBuffer, sizeof(pBuffer), &dwRead, NULL);
           dwPos = SetFilePointer(hDest,0, NULL,FILE_END);
               WriteFile(hDest, pBuffer, dwRead, &dwWritten, NULL);
               StartCluster =  StartCluster +512;
      }

      FileNo++;
   
      CloseHandle(hSrc);
      CloseHandle(hDest);
}

void fat(char *Drive,unsigned long StartingClusterNo,char *FileName,int Choice,ULONGLONG Sizet)
{
        pFLogf  = fopen("lodf.txt", "w");
        fprintf(pFLogf,"\n  %10s %30s      %10s   %15s  %20s\n","Id Number","Size In Byte","Exte","Size In MB","Incripted Name");
         char FileN[MAX_PATH+16] = {0};
		 sprintf(FileN,"%s\\",Tfil);
        strcat(FileN,FileName);
       // hVolume1 = CreateFile( Drive,  GENERIC_READ  , FILE_SHARE_READ , 0,  OPEN_EXISTING, 0, 0);
		 hVolume1= CreateFile((LPCSTR)Drive,  GENERIC_READ , FILE_SHARE_READ , NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
     
      if( hVolume1 == INVALID_HANDLE_VALUE)
      {
		  MessageBox(MainW,"Unable To Open Drive , Error !","Error !",MB_OK | MB_ICONERROR);
          goto f1;
      }

	  if(ReadFile(hVolume1, &fat32m, sizeof(fat32mbr), (LPDWORD)loop, 0) == 0)
      {
              printf("\n\nDrive Reading, Error : %u\n", GetLastError());
            //  getch();
              goto f1;
      }
      if(Choice == 0)
      {
              ListDeleted(0);
      }
       else if(Choice == 1)
      {
           ListDeleted(0);
           RecoverFilesFat1(Drive,StartingClusterNo,Sizet,FileN);
      }
f1:
 fclose(pFLogf);
}

void fatRecover(char *Drive,unsigned long StartingClusterNo,char *FileName,int Choice,ULONGLONG Sizet)
{
     fat(Drive,StartingClusterNo,FileName,Choice,Sizet);
     CloseHandle(hVolume1);
}

#endif