#ifndef GLOBLEVARIABLES_G
#define GLOBLEVARIABLES_G

typedef unsigned long long   uint64_t;

 

#define le32(x)  (x)
#define be32(x)  ((((x)&0xff000000L)>>24)                | \
    (((x)&0x00ff0000L)>>8)                  | \
    (((x)&0x0000ff00L)<<8)                  | \
    (((x)&0x000000ffL)<<24))
 

#define le32(x)  ((((x)&0xff000000L)>>24)                | \
    (((x)&0x00ff0000L)>>8)                  | \
    (((x)&0x0000ff00L)<<8)                  | \
    (((x)&0x000000ffL)<<24))
#define be32(x)  (x)

 
int isstopt;
 
  // HBITMAP  SelectionBG ;
   HBRUSH hbrBackground = NULL;
   HANDLE hSrc;
   HWND  BtnStop ,BtnStart,wFileSystem,BtnQuick;
   HWND cbList,MainW;

	char ResultV[MAX_PATH];
    char dDriveChar[MAX_PATH]; 
	char Drive[9] = "\\\\.\\E:";

	char er[MAX_PATH]; 
    char buffer[512],filename1[MAX_PATH];
    char Tfil[MAX_PATH];
	char bu[40];

    int nX1;
    int nY1;
    int c;
    int mb;
    int dn = -1 ;
    
	float Percent;

	DWORD dwRead;

	UINT64 FileNo = 0;
	unsigned long long start_file=0, end_file=0 ,loop = 0,file_size,i;

  __int64  dTotelMemory;

	RECT wRect1;

       typedef struct 
      { 
	     char DriveChar[MAX_PATH]; 
         char DriveName[MAX_PATH]; 
         char ValumeNamefs[12]; 
		 char ValumeName[MAX_PATH]; 
       __int64  FreeMemory; 
       __int64  TotelMemory; 
      } Player; 

	   Player Roster[]=  { 0 }; 
  	 
   int OthAll,All;
   int jpg,png,bmp,gif,tif,othI;
   int mp4,mkv,gp3,avi,flv,othV;
   int doc,xls,pdf,ppt,othD;
   int mp3,amr,id3,othA;
   int zip,rar,z7,OthC;
   int mdf,ldf,othdb;

   HWND ImageW,VideoW[6],DocW[5],AudioW[4],compressW[4],databW[2],AllW,OthAllW;


   int QAll,QSize,QsizeExt,Qext;

   #define AllDATA 1
   #define SizeCondation 2
   #define ExtensionCondation 3
   #define SizeAndExtension 4
   #define Recover 1
   #define ListDelete 0

#define MAX_CHARS_PER_LINE  512
 #define MAX_TOKENS_PER_LINE  10
   HWND wBUTT;
   int ValumeFileSystem;

   	fat32mbr fat32m ;//= {};
	HANDLE  hVolume1;

	

#endif 