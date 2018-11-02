///ntfs.h

typedef struct {
      ULONG Type;
      USHORT UsaOffset;
      USHORT UsaCount;
      USN Usn;
} NTFS_RECORD_HEADER, *PNTFS_RECORD_HEADER;

typedef struct {
      NTFS_RECORD_HEADER Ntfs;
      USHORT SequenceNumber;
      USHORT LinkCount;
      USHORT AttributesOffset;
      USHORT Flags;
      ULONG BytesInUse;
      ULONG BytesAllocated;
      ULONGLONG BaseFileRecord;
      USHORT NextAttributeNumber;
} FILE_RECORD_HEADER, *PFILE_RECORD_HEADER;

typedef enum {
      AttributeStandardInformation = 0x10,
      AttributeAttributeList = 0x20,
      AttributeFileName = 0x30,
      AttributeObjectId = 0x40,
      AttributeSecurityDescriptor = 0x50,
      AttributeVolumeName = 0x60,
      AttributeVolumeInformation = 0x70,
      AttributeData = 0x80,
      AttributeIndexRoot = 0x90,
      AttributeIndexAllocation = 0xA0,
      AttributeBitmap = 0xB0,
      AttributeReparsePoint = 0xC0,
      AttributeEAInformation = 0xD0,
      AttributeEA = 0xE0,
      AttributePropertySet = 0xF0,
      AttributeLoggedUtilityStream = 0x100
} ATTRIBUTE_TYPE, *PATTRIBUTE_TYPE;

typedef struct {
      ATTRIBUTE_TYPE AttributeType;
      ULONG Length;
      BOOLEAN Nonresident;
      UCHAR NameLength;
      USHORT NameOffset;
      USHORT Flags;
      USHORT AttributeNumber;
} ATTRIBUTE, *PATTRIBUTE;

typedef struct {
      ATTRIBUTE Attribute;
      ULONG ValueLength;
      USHORT ValueOffset;
      USHORT Flags;
} RESIDENT_ATTRIBUTE, *PRESIDENT_ATTRIBUTE;

typedef struct {
      ATTRIBUTE Attribute;
      ULONGLONG LowVcn;
      ULONGLONG HighVcn;
      USHORT RunArrayOffset;
      UCHAR CompressionUnit;
      UCHAR AlignmentOrReserved[5];
      ULONGLONG AllocatedSize;
      ULONGLONG DataSize;
      ULONGLONG InitializedSize;
      ULONGLONG CompressedSize;
} NONRESIDENT_ATTRIBUTE, *PNONRESIDENT_ATTRIBUTE;

typedef struct {
      ULONGLONG CreationTime;
      ULONGLONG ChangeTime;
      ULONGLONG LastWriteTime;
      ULONGLONG LastAccessTime;
      ULONG FileAttributes;
      ULONG AlignmentOrReservedOrUnknown[3];
      ULONG QuotaId;
      ULONG SecurityId;
      ULONGLONG QuotaCharge;
      USN Usn;
} STANDARD_INFORMATION, *PSTANDARD_INFORMATION;

typedef struct {
      ATTRIBUTE_TYPE AttributeType;
      USHORT Length;
      UCHAR NameLength;
      UCHAR NameOffset;
      ULONGLONG LowVcn;
      ULONGLONG FileReferenceNumber;
      USHORT AttributeNumber;
      USHORT AlignmentOrReserved[3];
} ATTRIBUTE_LIST, *PATTRIBUTE_LIST;

typedef struct {
      ULONGLONG DirectoryFileReferenceNumber;
      ULONGLONG CreationTime;
      ULONGLONG ChangeTime;
      ULONGLONG LastWriteTime;
      ULONGLONG LastAccessTime;
      ULONGLONG AllocatedSize;
      ULONGLONG DataSize;
      ULONG FileAttributes;
      ULONG AlignmentOrReserved;
      UCHAR NameLength;
      UCHAR NameType;
      WCHAR Name[1];
} FILENAME_ATTRIBUTE, *PFILENAME_ATTRIBUTE;

typedef struct {
      GUID ObjectId;
      union {
            struct {
                  GUID BirthVolumeId;
                  GUID BirthObjectId;
                  GUID DomainId;
            };
            UCHAR ExtendedInfo[48];
      };
} OBJECTID_ATTRIBUTE, *POBJECTID_ATTRIBUTE;

typedef struct {
      ULONG Unknown[2];
      UCHAR MajorVersion;
      UCHAR MinorVersion;
      USHORT Flags;
} VOLUME_INFORMATION, *PVOLUME_INFORMATION;

typedef struct {
      ULONG EntriesOffset;
      ULONG IndexBlockLength;
      ULONG AllocatedSize;
      ULONG Flags;
} DIRECTORY_INDEX, *PDIRECTORY_INDEX;

typedef struct {
      ULONGLONG FileReferenceNumber;
      USHORT Length;
      USHORT AttributeLength;
      ULONG Flags;


} DIRECTORY_ENTRY, *PDIRECTORY_ENTRY;

typedef struct {
      ATTRIBUTE_TYPE Type;
      ULONG CollationRule;
      ULONG BytesPerIndexBlock;
      ULONG ClustersPerIndexBlock;
      DIRECTORY_INDEX DirectoryIndex;
} INDEX_ROOT, *PINDEX_ROOT;

typedef struct {
      NTFS_RECORD_HEADER Ntfs;
      ULONGLONG IndexBlockVcn;
      DIRECTORY_INDEX DirectoryIndex;
} INDEX_BLOCK_HEADER, *PINDEX_BLOCK_HEADER;

typedef struct {
      ULONG ReparseTag;
      USHORT ReparseDataLength;
      USHORT Reserved;
      UCHAR ReparseData[1];
} REPARSE_POINT, *PREPARSE_POINT;

typedef struct {
      ULONG EaLength;
      ULONG EaQueryLength;
} EA_INFORMATION, *PEA_INFORMATION;

typedef struct {
      ULONG NextEntryOffset;
      UCHAR Flags;
      UCHAR EaNameLength;
      USHORT EaValueLength;
      CHAR EaName[1];
      // UCHAR EaData[];
} EA_ATTRIBUTE, *PEA_ATTRIBUTE;

typedef struct {
      WCHAR AttributeName[64];
      ULONG AttributeNumber;
      ULONG Unknown[2];
      ULONG Flags;
      ULONGLONG MinimumSize;
      ULONGLONG MaximumSize;
} ATTRIBUTE_DEFINITION, *PATTRIBUTE_DEFINITION;

#pragma pack(push, 1)

typedef struct {
      UCHAR Jump[3];
      UCHAR Format[8];
      USHORT BytesPerSector;
      UCHAR SectorsPerCluster;
      USHORT BootSectors;
      UCHAR Mbz1;
      USHORT Mbz2;
      USHORT Reserved1;
      UCHAR MediaType;
      USHORT Mbz3;
      USHORT SectorsPerTrack;
      USHORT NumberOfHeads;
      ULONG PartitionOffset;
      ULONG Reserved2[2];
      ULONGLONG TotalSectors;
      ULONGLONG MftStartLcn;
      ULONGLONG Mft2StartLcn;
      ULONG ClustersPerFileRecord;
      ULONG ClustersPerIndexBlock;
      LARGE_INTEGER VolumeSerialNumber;
      UCHAR Code[0x1AE];
      USHORT BootSignature;

} BOOT_BLOCK, *PBOOT_BLOCK;

#pragma pack(pop)


  unsigned long long fileNo1 = 0;
  
  void gotoXY1(int x ,int y)
{
	   COORD newPosition = { x , y};
	   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),newPosition);
}