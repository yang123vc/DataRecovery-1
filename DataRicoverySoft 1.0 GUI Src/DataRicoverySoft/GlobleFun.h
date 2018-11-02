#ifndef GLOBLEFUNCATION_H
#define GLOBLEFUNCATION_H

#include <time.h>


 #include "NtfsRicover.h"
//void SetMainWindowText(HWND hwnd)
//{
//	  
//					 strcpy(MainWindowText ,"MyDataRicovery - ");
//					 
//						 char to[30];
//					strcat(MainWindowText,dDriveChar);
//					strcat(MainWindowText," : ");
//					   ltoa(loop-1,to,10);
//					strcat(MainWindowText,to);
//					strcat(MainWindowText," / ");
//					  ltoa(dTotelMemory/512-1,to,10);
//					strcat(MainWindowText,to);
//					     sprintf(to,"     %.4f%%",Percent);
//					strcat(MainWindowText,to);
//                  SetWindowText(hwnd,MainWindowText);
//
//}
//void DrawBGImage(HWND hwnd)
//{
//	        BITMAP bm;
//			PAINTSTRUCT ps;
//			HDC hdc;
//		    hdc = BeginPaint(hwnd, &ps);
//			HDC hdcMem = CreateCompatibleDC(hdc);
//			HBITMAP hbmOld = (HBITMAP)SelectObject(hdcMem, SelectionBG);
//			GetObject(SelectionBG, sizeof(bm), &bm);
//			BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
//			SelectObject(hdcMem, hbmOld);
//			DeleteDC(hdcMem);
//			EndPaint(hwnd, &ps);
//}

 void UpdatPricess(HWND hwnd)
 {
	 
	        char arr[MAX_PATH];
			char to[MAX_PATH];
			
		    	ltoa(loop-1,to,10);
			strcpy(arr,to);
			strcat(arr,"/");
			   ltoa(dTotelMemory/512-1,to,10);
			strcat(arr,to);
			strcat(arr,"       ");
			   sprintf(to,"%.4f%%",Percent);
			strcat(arr,to); 
			SetDlgItemText(hwnd,IDC_STATIC2,arr);
	 
 }
 
  char RandomName[9] = {0};
 static const char alphanum[] ="0123456789";

int stringLength = sizeof(alphanum) - 1;
char genRandom()  
{
    return alphanum[rand() % stringLength];
}

 void  RandomN()
 {
       srand(time(0));
    for(int z=0; z < 8; z++)
    {
       RandomName[z]  = genRandom();
    }

 } 
 
 #include <ShlObj.h>
 BOOL PopFolderOpenDlg(PTSTR Tfil)
{  
	               BROWSEINFO bi ={0};
					    bi.lpszTitle =  "Set Location";
						bi.hwndOwner = MainW;
					  LPITEMIDLIST pidl =  SHBrowseForFolder(&bi);
					   if(pidl != NULL)
					   {
						  
						   if(SHGetPathFromIDList(pidl,Tfil) ==FALSE)
						   {
							       MessageBox(MainW,"Please Select Correct  Location !","Error",MB_OK | MB_ICONERROR);
								    CoTaskMemFree(pidl);
								   return FALSE;
						   }
						   else
						   {
                               CoTaskMemFree(pidl);
                               return TRUE;
						   }
                            
					   }
					   return FALSE;
}


 int valumeInfo(char *Drive)
{
   try
  {
      char volumeName[MAX_PATH + 1] = { 0 };
      char fileSystemName[MAX_PATH + 1] = { 0 };
      DWORD serialNumber = 0;
      DWORD maxComponentLen = 0;
      DWORD fileSystemFlags = 0;
      char h[5];

      if (GetVolumeInformation(  Drive, volumeName, sizeof(volumeName), &serialNumber,
        &maxComponentLen,  &fileSystemFlags, fileSystemName, sizeof(fileSystemName)) == TRUE)
      {
               if(fileSystemName[0] == 'F' && fileSystemName[1] == 'A' && fileSystemName[2] == 'T' && fileSystemName[3] == '3' && fileSystemName[4] == '2')
              {
                    return 32;
               }
               else if (fileSystemName[0] == 'N' && fileSystemName[1] == 'T' && fileSystemName[2] == 'F' && fileSystemName[3] == 'S')
               {
                   return 64;
               }
               else if(fileSystemName[0] == 'F' && fileSystemName[1] == 'A' && fileSystemName[2] == 'T' && fileSystemName[3] == '1' && fileSystemName[4] == '2')
               {
                    return 12;
               }
                else if(fileSystemName[0] == 'F' && fileSystemName[1] == 'A' && fileSystemName[2] == 'T' && fileSystemName[3] == '1' && fileSystemName[4] == '6')
               {
                    return 16;
               }
               else
               {
                   return 0;
               }
      }
      else
      {
		    char te[MAX_PATH];
		    sprintf(te,"GetVolumeInformation() failed, error %u\n", GetLastError());
			MessageBox(MainW,te,"Error !",MB_OK | MB_ICONERROR);
            exit(1);
      }
  
  }
  catch(int ex)
  {
       
  }

}

 int ReadListDeletedfile(char *Drive, double Choice_Minium_Size, double Choice_Mixum_Size,char *Exte,int Choice,int nu)
{
           
            char* const DELIMITER = " ,$@€*<>|/?:;""\\";

          unsigned long rid = 0;
          double rsize,rsize1;
          char *chk;

          ifstream fin("lodf.txt");
          if (!fin.good())
          {
          	SetDlgItemText(MainW,IDC_STATIC2,"File opening Failed !");
          	return 1;
          }
          while (!fin.eof())
         {
           char buf[MAX_CHARS_PER_LINE];
           fin.getline(buf, MAX_CHARS_PER_LINE);

           int n = 0;  

   	       char* token[MAX_TOKENS_PER_LINE] = {};

           token[0] = strtok(buf,DELIMITER );  
           if (token[0])  
           {
             for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
             {
               token[n] = strtok(0, DELIMITER );  
               if (!token[n]) break;  
             }
			   rid =  strtol(token[0], &chk,10);
	       
		    if(rid != 0)
           {
          /* }
           else
           {
             */ 
			        if(isstopt == 1)
			            goto end1;

			    if(nu==64)
               {
				       rsize = strtod(token[1], &chk);
                       
                         if(Choice == AllDATA)
                         {
                               NtfsRecoverFile(Drive,rid,token[3],Recover);
                         }
                         else if(Choice == SizeCondation && rsize >= Choice_Minium_Size && rsize <= Choice_Mixum_Size)
                          {
                          	  
                                NtfsRecoverFile(Drive,rid,token[3],Recover);
                         }
                         else
                         {
                         }
                      
                }
               if(nu == 32)
              {  
				   rsize = strtod(token[1], &chk);
                   rsize1 = strtod(token[4], &chk);
			       
                   
                       RandomN();
                       char Nam[MAX_PATH] = {0};
                        strcat(Nam,"R");
                       strcat(Nam,RandomName);
                       strcat(Nam,".");
                       strcat(Nam,token[3]);
                    
                       if(Choice == AllDATA)
                       {
                            fatRecover(Drive,rid,Nam,Recover, rsize);
                        }
                       else if(Choice == SizeCondation && rsize1 >= Choice_Minium_Size && rsize1 <= Choice_Mixum_Size)
                       {
                           fatRecover(Drive,rid,Nam,Recover, rsize);
                       }
					   else if(Choice == ExtensionCondation &&  /*!strcmp(token[3], Exte)*/  !_stricmp(token[3], Exte))
                       {    
                            fatRecover(Drive,rid,Nam,Recover, rsize);
                       }
                       else if(Choice == SizeAndExtension && rsize1 >= Choice_Minium_Size && rsize1 <= Choice_Mixum_Size &&   !_stricmp(token[3], Exte))
                       {
                            fatRecover(Drive,rid,Nam,Recover, rsize);
                       }
                       else
                       {
                            continue;
                       }
                   //    cout << endl;
                  
              }
         }     
        }
	 }
   end1 :
	 isstopt = 0;
}
 void items(char *Drive, int nu)
{
	 
          
	                QAll= IsDlgButtonChecked(wFileSystem, IDC_RADIO1);
					QSize = IsDlgButtonChecked(wFileSystem, IDC_RADIO2);
					QsizeExt = IsDlgButtonChecked(wFileSystem, IDC_RADIO4);
					Qext = IsDlgButtonChecked(wFileSystem, IDC_RADIO3);
					  
               if(QAll)
              {
                     ReadListDeletedfile(Drive,0,0,"",AllDATA,nu);
              }
              else if(QSize)
              {
              	      double Minum,Mixum;
					  int tr;
				 
					  Minum= GetDlgItemInt(wFileSystem,IDC_EDIT1,&tr,0);
                       Mixum =  GetDlgItemInt(wFileSystem,IDC_EDIT2,&tr,0);
                     
                     ReadListDeletedfile(Drive,Minum,Mixum,0,SizeCondation,nu);
              }
              else if(Qext)
              {
                   
                    char ext[5] = {0};
					GetDlgItemText(wFileSystem,IDC_COMBO1,ext,5);
                     ReadListDeletedfile(Drive,0,0,ext,ExtensionCondation,nu);
              }          
              else if(QsizeExt)
              {
                 
                	 int tr;
                    double Minum,Mixum;
                    char ext[5] = {0};
                 
					Minum= GetDlgItemInt(wFileSystem,IDC_EDIT1,&tr,0);
                    Mixum =  GetDlgItemInt(wFileSystem,IDC_EDIT2,&tr,0);
                    GetDlgItemText(wFileSystem,IDC_COMBO1,ext,5);
 
                    ReadListDeletedfile(Drive,Minum,Mixum,ext,SizeAndExtension,nu);

                
              }
              else
              { 

              }
	  QAll =QSize =QsizeExt =Qext = 0;
      
}
#endif 