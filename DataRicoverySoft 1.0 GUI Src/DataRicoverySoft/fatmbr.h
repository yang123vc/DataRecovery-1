
//#include <windows.h>

#pragma pack(1)
typedef struct
{

	  UCHAR Jump[3];
      UCHAR Format[8];
      USHORT BytesPerSector;
      UCHAR SectorsPerCluster;
      USHORT ResverdSector;
      UCHAR NumberOfFat;
      USHORT RootEntries;
      USHORT Sectors_SmallValues;
      UCHAR MediaType;
      USHORT SectorPerFat_SnallValue;
      USHORT SectorPreTrack;
      USHORT NumberOfHeads;
      ULONG HiddenSector;
      ULONG Sectors_LargeValues;
      ULONG  SectorPerFAT;
      USHORT Flags;
      USHORT Version;
      ULONG RootDir1stCluster;
      USHORT FSInfoSector;
      USHORT BackupBootSector;
      UCHAR  Reseverd[0xC];
      UCHAR LogicDriveNo;
      UCHAR Unused;
      UCHAR ExtenedSignature;
      ULONG SerialNumber;
      UCHAR  ValumeName[0xB];
      UCHAR FATName[8];
      UCHAR ExecutableCode[0x1A4];
      USHORT BootSignature;

}fat32mbr,*Pfat32mbr;

/*
#pragma pack(push, 1)
typedef struct
{

	  UCHAR Jump[3];
      UCHAR Format[8];
      USHORT BytesPerSector;
      UCHAR SectorsPerCluster;
      USHORT ResverdSector;
      UCHAR NumberOfFat;
      USHORT RootEntries;
      USHORT Sectors_SmallValues;
      UCHAR MediaType;
      USHORT SectorPerFat_SnallValue;
      USHORT SectorPreTrack;
      USHORT NumberOfHeads;
      ULONG HiddenSector;
      ULONG Sectors_LargeValues;
      char DriveNo;
      char CurrentHead;
      char EBootSignature;
      ULONG VolumeSerialNo;
      UCHAR VolumeLable[11];
      UCHAR FileSystem[8];
      UCHAR Code[0x1C0];
      USHORT BootSignature;
  }fat12mbr,*Pfat12mbr;

  #pragma pack(pop)
*/
#pragma pack(push, 1)
typedef struct
{
    UCHAR	name[8],ext[3];
	UCHAR Attribute;
    UCHAR Resverd[0xA];
	USHORT FileTime;
    USHORT FileDate;
    USHORT   StartClusterNo;
	ULONG FileLength;
}DirectoryEntry,*PDiorectoryEntry;
    #pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
    DirectoryEntry F[16*16];

}SDirectory;
#pragma pack(pop)