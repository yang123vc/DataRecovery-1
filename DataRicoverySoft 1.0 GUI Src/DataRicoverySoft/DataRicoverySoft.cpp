#include <windows.h>
#include <stdio.h>
#include <strsafe.h>
#include <string.h>
#include <direct.h>
#include <iostream>
#include <process.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
 

using namespace std;

#include "resource.h" 
#include  "fatmbr.h"
#include "GlobleVar.h"
#include "FatR.h"
#include "GlobleFun.h"
#include "DriveList.h"
#include "RecoverTheFile.h"
#include "DataHeader.h"
#include "DataFun.h"

#include "NtfsRicover.h"




void ListDel(PVOID pvoid)
{
	               ValumeFileSystem = valumeInfo(dDriveChar) ;
					 if(ValumeFileSystem == 64)
	                 {
						 VideoW[0] = GetDlgItem(wFileSystem, IDC_RADIO3);
						 VideoW[1] = GetDlgItem(wFileSystem, IDC_RADIO4);
					      
						 AudioW[0] = GetDlgItem(wFileSystem, IDC_COMBO1);
						  AudioW[1] = GetDlgItem(wFileSystem, IDC_EDIT1);
						  AudioW[2] = GetDlgItem(wFileSystem, IDC_EDIT2);
						 
						    EnableWindow(VideoW[0],0);
							EnableWindow(VideoW[1],0);

							EnableWindow(AudioW[0],0);
							EnableWindow(AudioW[1],0);
							EnableWindow(AudioW[2],0);
                          
							 SetDlgItemText(MainW,IDC_STATIC2,"Please Wait Delete File Is Listing !...");
						    NtfsRecoverFile(Drive,0,"",ListDelete);
						 SetDlgItemText(MainW,IDC_STATIC2," Delete File Is Listed Sucessfull !...");
						   
						  wBUTT = GetDlgItem(wFileSystem, IDC_BUTTON1);
						 EnableWindow(wBUTT,1);
						  
						  wBUTT = GetDlgItem(wFileSystem, IDC_BUTTON2);
						     EnableWindow(wBUTT,1);

						    ShowWindow(wFileSystem, SW_SHOW);
				   
	                 }
					 else if(ValumeFileSystem == 32)
					 {
						  AudioW[0] = GetDlgItem(wFileSystem, IDC_COMBO1);
						  AudioW[1] = GetDlgItem(wFileSystem, IDC_EDIT1);
						  AudioW[2] = GetDlgItem(wFileSystem, IDC_EDIT2);
						 
						    EnableWindow(AudioW[0],1);
							EnableWindow(AudioW[1],1);
							EnableWindow(AudioW[2],1);

						  VideoW[0] = GetDlgItem(wFileSystem, IDC_RADIO1);
						  VideoW[1] = GetDlgItem(wFileSystem, IDC_RADIO2);
						  VideoW[2] = GetDlgItem(wFileSystem, IDC_RADIO3);
						  VideoW[3] = GetDlgItem(wFileSystem, IDC_RADIO4);
					      
						    EnableWindow(VideoW[0],1);
							EnableWindow(VideoW[1],1);
							EnableWindow(VideoW[2],1);
							EnableWindow(VideoW[3],1);
						  
						    SetDlgItemText(MainW,IDC_STATIC2,"Please Wait Delete File Is Listing !...");
						    fatRecover(Drive,0,"",ListDelete,0);
						    SetDlgItemText(MainW,IDC_STATIC2," Delete File Is Listed Sucessfull !...");
						  

							 AudioW[0] = GetDlgItem(wFileSystem, IDC_RADIO1);
						    SendMessage(AudioW[0] , BM_SETCHECK, 1, 0) ;
						    QAll = 1;

							  wBUTT = GetDlgItem(wFileSystem, IDC_BUTTON1);
						     EnableWindow(wBUTT,1);

							  wBUTT = GetDlgItem(wFileSystem, IDC_BUTTON2);
						     EnableWindow(wBUTT,1);

						   ShowWindow(wFileSystem, SW_SHOW);
				   
					 }
	                else
	                {
	                	MessageBox(MainW,"File System Unknown","Worning ! ",MB_OK | MB_ICONERROR);
	                }
}

void RecoverByFS(PVOID pvoid)
{
	                 EnableWindow(wBUTT,0);
	                 if(ValumeFileSystem == 64)
	                 {  
						   items(Drive,ValumeFileSystem);

	                 }
					 else if(ValumeFileSystem == 32)
					 {
						    fatRecover(Drive,0,"",ListDelete,0);
						    items(Drive,ValumeFileSystem); 
					 }
	                else
	                {
						MessageBox(MainW,"File System Unknown","Worning ! ",MB_OK | MB_ICONERROR);
	                }

			  ShowWindow(wFileSystem,SW_HIDE);
					
}
void RecoverItemsL(PVOID pvoid)
{

	try
	{
		 
	
	        Drive[4] = dDriveChar[0];

        

		   hSrc = CreateFile((LPCSTR)Drive,  GENERIC_READ | GENERIC_WRITE , FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
        if (hSrc == INVALID_HANDLE_VALUE)
        {
		     sprintf(er,"Unable To Read Drive :%s",Drive);
			 SetDlgItemText(MainW,IDC_STATIC3,er);
			 MessageBox(MainW,er,"Error !",MB_OK | MB_ICONERROR);
	   		goto last;
        }
    
	     while(loop<(dTotelMemory/512))
         {
         	  
			 if(isstopt == 1)
			 {
				   EnableWindow(cbList,1);
				 goto last;
			 }
                 double tt = dTotelMemory/512;
			     Percent = (loop*100)/tt;
			     UpdatPricess(MainW);
			 
              SetFilePointer(hSrc,loop*sizeof(buffer), NULL, 0);
              ReadFile(hSrc, buffer, sizeof(buffer), &dwRead, NULL);

			  if(All)
			  {
				       gif_header_check();
             //  exe_header_check();
               png_header_check();
               mng_header_check();
               jng_header_check();
               id3_header_check();
               mp3_header_check();
               rar_header_check();
               zip_header_check();
               jpg_header_check();
               z7_header_check() ;
               ctg_header_check();
               cwk_header_check();
               a_header_check();
               deb_header_check();
               ab_header_check();
               abcdp_header_check();
               ace_header_check();
               ahn_header_check();
               aif_header_check();
   ////            all_header_check();
               als_header_check();
               amd_header_check();
               amt_header_check();
               amr_header_check();
               apa_header_check();
               ape_header_check();
               apple_header_check();
             //  arj_header_check();
               asf_header_check();
               asm_header_check();
               atd_header_check();
               au_header_check();
               bkf_header_check();
               blend_header_check();
               bmp_header_check();
               bz2_header_check();
               cab_header_check();
               cam_header_check();
               chm_header_check();
               class_header_check();
               comicdoc_header_check();
               compress_header_check();
             //  crw_header_check();
               evt_header_check();
             //  ext_header_check();
               d2s_header_check();
               dat_header_check();
			   DB_header_check();
//////		       dbf_header_check();
			   diskimage_header_check();
			   _header_check() ;
			   djv_header_check();
			   doc_header_check();
			   dpx_header_check();
			   drw_header_check();
			   ds2_header_check();
			   dsc_header_check();
			   dss_header_check();
			   dta_header_check();
			   dump_header_check();
			   dv_header_check();
			   dwg_header_check();
			   dxf_header_check();
			   edb_header_check();
			   elf_header_check();
			   emf_header_check();
			   fbk_header_check();
			   fcp_header_check();
			   fcs_header_check();
    		   fdb_header_check();
			   fh5_header_check();
			   fh10_header_check();
			   fits_header_check();
			   flac_header_check();
			   flp_header_check();
			   flv_header_check();
			   fob_header_check();
			   fp7_header_check();
			   frm_header_check();
			   fs_header_check();
    		   gho_header_check();
			   hds_header_check();
			   hr9_header_check();
		//	   ico_header_check();
			   ifo_header_check();
			   imb_header_check();
			   indd_header_check();
			   iso_header_check();
			   itu_header_check();
			   kdb_header_check();
    		   idf_header_check();
			   lnk_header_check();
			   logic_header_check();
			   m2ts_header_check();
			   max_header_check();
			   mb_header_check();
			   mcd_header_check();
			   mcd_header_check();
			   mdb_header_check();
    		   mdf_header_check();
			   mfa_header_check();
			   mfg_header_check();
			   mid_header_check();
			   mk5_header_check();
			   mkv_header_check();
			   mp4_header_check();
		       mpg_header_check();
			   mrw_header_check();
			   mus_header_check();
			   mxf_header_check();
			   MYI_header_check();
		  	   njx_header_check();
               nk2_header_check();
               ogg_header_check();
               one_header_check();
               orf_header_check();
               paf_header_check();
               pap_header_check();
               pcap_header_check();
               pdf_header_check();
               pfx_header_check();
               prc_header_check();
               prt_header_check();
               ps_header_check();
               psd_header_check();
               psp_header_check();
               pst_header_check();
               ptb_header_check();
               pyc_header_check();
               qbb_header_check();
               qdf_header_check();
               qxd_header_check();
               ra_header_check();
               raf_header_check();
               raw_header_check();
               rdc_header_check();
               reg_header_check();
     ////          res_header_check();
               riff_header_check();
               rm_header_check();
               rns_header_check();
               rpm_header_check();
               ses_header_check();
               sid_header_check();
               sit_header_check();
               skd_header_check();
               skp_header_check();
       //        sp3_header_check();
               spf_header_check();
               sav_header_check();
               sqlite_header_check();
               sqm_header_check();
               stl_header_check();
               stu_stu_header_check();
               swf_header_check();
               tar_header_check();
               tax_header_check();
               tib_header_check();
               tic_header_check();
               tph_header_check();
          //     ttf_header_check();
               text_header_check();
               tz_header_check();
               veg_header_check();
               vmdk_header_check();
               vks_header_check();
               wmf_header_check();
               wnk_header_check();
               wpd_header_check();
               x3f_header_check();
               xcf_header_check();
               xm_header_check();
               xpt_header_check();
               xsv_header_check();
               xv_header_check();
			  }
			  else
			  {
				    if(jpg)
			             jpg_header_check();
					 if(png)
						  png_header_check();
					 if(gif)
						  gif_header_check();
					 if(bmp)
						  bmp_header_check();
					 if(tif)
					 {
						  mng_header_check();
						  jng_header_check();
					 }
					 if(othI)
					 {
						 	  cam_header_check();
						   //  crw_header_check();
						  mrw_header_check();
						  orf_header_check();
						  pcap_header_check();
						  psd_header_check();
                          psp_header_check();
			              x3f_header_check();
                          xcf_header_check();
			   
					 }
					 if(mp4)
						  mp4_header_check();
					 if(mkv)
						 mkv_header_check();
					 if(gp3)
                         flp_header_check();
					 if(avi)
						  riff_header_check();
					 if(flv)
						 flv_header_check();
					 if(othV)
					 {  
		                 mpg_header_check();
					 }
					 if(doc)
						  doc_header_check();
					 if(xls)
						 chm_header_check();
					 if(ppt)
						   text_header_check();
					 if(pdf)
						 pdf_header_check();
					 if(othD)
					 {
						    one_header_check();
						   wpd_header_check();
						   pst_header_check();
						   nk2_header_check();
						   njx_header_check();
						   ps_header_check();
					 }
					 if(mp3)
						  mp3_header_check();
					 if(amr)
						    amr_header_check();
					 if(id3)
						  id3_header_check();
					 if(othA)
					 {
						  ogg_header_check();
						  aif_header_check();
							////            all_header_check();
						  ape_header_check();
						  asf_header_check();
						  mus_header_check();
						  ra_header_check();
						  rm_header_check();
                          rns_header_check();
			              mid_header_check();
					 }
					 if(zip)
						  zip_header_check();
					 if(rar)
						  rar_header_check();
					 if(z7)
						  z7_header_check() ;
					 if(OthC)
					 {
						    bz2_header_check();
                            cab_header_check();
							compress_header_check();
							tar_header_check();
							//  iso_header_check();
							a_header_check();
					 }
					 if(mdf)
						   mdf_header_check();
					 if(ldf)
						   idf_header_check();
					 if(othdb)
					 {
				           MYI_header_check();
		  	               mdb_header_check();
    		               abcdp_header_check();
						   DB_header_check();
//////		               dbf_header_check();
						   edb_header_check();
						   sqlite_header_check();
					 }
					if(OthAll)
					 {
						    xm_header_check();
                           xpt_header_check();
                           xsv_header_check();
                           xv_header_check();
						   mcd_header_check();
						   mk5_header_check();
			               mfa_header_check();
			               mfg_header_check();
						   raf_header_check();
						   ptb_header_check();
                           pyc_header_check();
                           qbb_header_check();
                           qdf_header_check();
                           qxd_header_check();
						   pfx_header_check();
                           prc_header_check();
                           prt_header_check();
						   paf_header_check();
                           pap_header_check();
					       spf_header_check();
                           sav_header_check();
						   rpm_header_check();
                           ses_header_check();
                           sid_header_check();
                           sit_header_check();
                           skd_header_check();
                           skp_header_check();
       //                  sp3_header_check();
						   raw_header_check();
                           rdc_header_check();
                           reg_header_check();
     ////                  res_header_check();
                           tz_header_check();
                           veg_header_check();
                           vmdk_header_check();
                           vks_header_check();
                           wmf_header_check();
                           wnk_header_check();
				    	   tax_header_check();
                           tib_header_check();
                           tic_header_check();
                           tph_header_check();
          //               ttf_header_check();
					  	   sqm_header_check();
                           stl_header_check();
                           stu_stu_header_check();
                           swf_header_check();
						   lnk_header_check();
			               logic_header_check();
			               m2ts_header_check();
			               max_header_check();
			               mb_header_check();
						   itu_header_check();
			               kdb_header_check();
						   fob_header_check();
			               fp7_header_check();
			               frm_header_check();
			               fs_header_check();
    		               gho_header_check();
			               hds_header_check();
			               hr9_header_check();
		//	               ico_header_check();
			               ifo_header_check();
			               imb_header_check();
			               indd_header_check();
			               elf_header_check();
			               emf_header_check();
			               fbk_header_check();
			               fcp_header_check();
			               fcs_header_check();
    		               fdb_header_check();
			               fh5_header_check();
			               fh10_header_check();
			               fits_header_check();
			               flac_header_check();
			               flp_header_check();
						  diskimage_header_check();
			              _header_check() ;
			               djv_header_check();
						  ctg_header_check();
						  cwk_header_check();
                          deb_header_check();
                          ab_header_check();
                          ace_header_check();
                          ahn_header_check();
						  als_header_check();
                          amd_header_check();
                          amt_header_check();
			              apa_header_check();
				          apple_header_check();
             //           arj_header_check();
						  asm_header_check();
                          atd_header_check();
                          au_header_check();
                          bkf_header_check();
                          blend_header_check();
			              class_header_check();
                          comicdoc_header_check();
			              evt_header_check();
             //           ext_header_check();
                          d2s_header_check();
                          dat_header_check();
			              dpx_header_check();
			              drw_header_check();
			              ds2_header_check();
			              dsc_header_check();
			              dss_header_check();
			              dta_header_check();
			              dump_header_check();
			              dv_header_check();
			              dwg_header_check();
			              dxf_header_check();
                    }
			  
			     }
                 
            loop++;
        }
      
   last:

		 isstopt = 0;
      CloseHandle(hSrc);

	 }
	catch(char err[])
	{
		MessageBox(MainW,err,"Error !",MB_OK | MB_ICONERROR);
	}

}
 
void listf(PVOID)
{
	               char buf[MAX_PATH];
					char buf1[MAX_PATH];
					GetCurrentDirectory(MAX_PATH,buf);

					sprintf(buf1,"%s\\lodf.txt",buf);
                	system(buf1);
				   
}
BOOL CALLBACK wFileSystemProcess(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
 
	 switch(Message)
	{   
		
		case WM_INITDIALOG:
		{
                
		}
		break;
		 case WM_CTLCOLORSTATIC :
		{
		 	SetBkMode((HDC)wParam,TRANSPARENT);
			return (INT_PTR)(HBRUSH)GetStockObject(NULL_BRUSH);
	    }
		 case WM_COMMAND:
		{
               switch(LOWORD(wParam))
			{  
			   case IDC_BUTTON1 :
				{
					   if(PopFolderOpenDlg(Tfil))
						{
							char te[MAX_PATH];
							sprintf(te,"%s\\Recovered Files",Tfil);
                            _mkdir(te);
							sprintf(Tfil,"%s",te);
						
						     int k;
							 for(k = IDC_CHECK1;k<=IDC_CHECK36;k++)
							 {
								 ImageW = GetDlgItem(hwnd, k);
								 EnableWindow(ImageW,0);
							 }
							  _beginthread (RecoverByFS, 0, NULL) ;
					          ShowWindow(wFileSystem,SW_HIDE);

 	                    }   
					 
					break;
				}
			     case IDC_BUTTON2 :
				{
					  _beginthread (listf, 0, NULL) ;
					
					break;
				}
			   case IDC_RADIO2 :
			   case IDC_RADIO3 :
			   case IDC_RADIO4 :
			  {
				          AudioW[0] = GetDlgItem(wFileSystem, IDC_COMBO1);
						  AudioW[1] = GetDlgItem(wFileSystem, IDC_EDIT1);
						  AudioW[2] = GetDlgItem(wFileSystem, IDC_EDIT2);
						 
						    EnableWindow(AudioW[0],1);
							EnableWindow(AudioW[1],1);
							EnableWindow(AudioW[2],1);
				  break;
			  }
			}
 	   }
	    break;
	  case WM_CLOSE:
			EndDialog(hwnd, 0);
		break;
	 
		 default:
			return FALSE;
	}
	return TRUE;
}
BOOL CALLBACK MainWinProcess(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	
 
     int lb;
	switch(Message)
	{
		case WM_INITDIALOG:
		     hbrBackground = CreateSolidBrush(RGB(50, 50, 50));
			 
			//    SelectionBG = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));

			  MainW = hwnd;
			 BtnStop =  GetDlgItem(hwnd, IDC_BUTTON2);
			 BtnStart =  GetDlgItem(hwnd, IDC_BUTTON1);
		    BtnQuick =  GetDlgItem(hwnd, IDC_BUTTON6);
		 	     
			       cbList = GetDlgItem(hwnd, IDC_COMBO1);

			         ListDriveCB();
		             for(int Count = 0; Count <= dn ; Count++)
                    {
					    SendMessage(cbList,  CB_ADDSTRING,  0,  reinterpret_cast<LPARAM>((LPCTSTR)Roster[Count].DriveName));
                    }
 
					 wFileSystem = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG3),  hwnd, wFileSystemProcess);
		        if(wFileSystem != NULL)
		   	   {
				   ShowWindow(wFileSystem, SW_HIDE);
			    }
		        else
		 	    {
			     	MessageBox(hwnd, "CreateDialog returned NULL", "Warning!", MB_OK | MB_ICONINFORMATION);
		        }

			SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)LoadIcon(NULL, 
				MAKEINTRESOURCE(IDI_ICON1)));
			SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)LoadIcon(NULL, 
				MAKEINTRESOURCE(IDI_ICON1)));
		 
	 	break;
	 	case WM_CLOSE:
			EndDialog(hwnd, 0);
		break;
		case WM_CTLCOLORDLG:	
			return (LONG)hbrBackground;
		case WM_CTLCOLORSTATIC:
		{
			/*SetTextColor((HDC)wParam, RGB(3, 0, 2));
			SetBkMode((HDC)wParam,TRANSPARENT);
			return (INT_PTR)(HBRUSH)GetStockObject(NULL_BRUSH);*/

			/*SetTextColor((HDC)wParam, RGB(3, 0, 2));
			SetBkMode((HDC)wParam,TRANSPARENT);
			return (INT_PTR)(HBRUSH)GetStockObject(NULL_BRUSH);*/
			

			HDC hdcStatic = (HDC)wParam;
			SetTextColor(hdcStatic, RGB(30, 230, 230));
			SetBkMode(hdcStatic, TRANSPARENT);
		 
			return (LONG)hbrBackground;
		}
		break;
		/*case WM_PAINT :
		{
			DrawBGImage(MainW);
			break;
		}*/
		case WM_LBUTTONDOWN :
		 {
			  mb = 1;
		        nX1 = (int)LOWORD(lParam);
	            nY1 = (int)HIWORD(lParam);

			   break;
		 }
		 case WM_MOUSEMOVE :
		  {   
			  if(mb == 1)
			  {
                   int nX;
	               nX = (int)LOWORD(lParam);
	               int nY;
	               nY = (int)HIWORD(lParam);
                   
	                 GetWindowRect(MainW,&wRect1);
				 	 MoveWindow(MainW,wRect1.left+(nX-nX1),wRect1.top+(nY-nY1),wRect1.right-wRect1.left,wRect1.bottom-wRect1.top,1);
			  }

			  break;
		  }
		 case WM_MOUSEHOVER :
		 case WM_LBUTTONUP:
		{
			mb = 0;
			break;
		}
	 	case WM_COMMAND:
			switch(LOWORD(wParam))
			{  
			   case IDC_COMBO1:
              {
                switch (HIWORD(wParam)) 
                { 
                    case CBN_SELCHANGE:
                    {
						
						  HWND hwndCombo = GetDlgItem(hwnd, IDC_COMBO1); 
                          int nItem  =  (int)SendMessage(hwndCombo, CB_GETCURSEL, 0, 0); 
  
						  strcpy(dDriveChar,Roster[nItem].DriveChar);
						  dTotelMemory = Roster[nItem].TotelMemory;
                         
                          UpdatPricess(hwnd);
						  MainW = hwnd;
					      EnableWindow(cbList,0);

						  strcpy(er,dDriveChar);
						  SetDlgItemText(hwnd,IDC_STATIC1,er);

                          EnableWindow(BtnStart,1);
						  EnableWindow(BtnStop,1);
						  EnableWindow(BtnQuick,1);

						  loop = 0;
                    } 
					break;
                }
            }
           break;
			   case IDC_BUTTON1 :
		     {
				     
                   	 jpg = IsDlgButtonChecked(hwnd, IDC_CHECK2);
					 png = IsDlgButtonChecked(hwnd, IDC_CHECK3);
					 gif = IsDlgButtonChecked(hwnd, IDC_CHECK4);
					 bmp = IsDlgButtonChecked(hwnd, IDC_CHECK5);
					 tif = IsDlgButtonChecked(hwnd, IDC_CHECK6);
					 othI = IsDlgButtonChecked(hwnd, IDC_CHECK7);
					
					 mp4 = IsDlgButtonChecked(hwnd, IDC_CHECK9);
					 mkv = IsDlgButtonChecked(hwnd, IDC_CHECK10);
					 gp3 = IsDlgButtonChecked(hwnd, IDC_CHECK11);
					 avi = IsDlgButtonChecked(hwnd, IDC_CHECK12);
					 flv = IsDlgButtonChecked(hwnd, IDC_CHECK29);
					 othV = IsDlgButtonChecked(hwnd, IDC_CHECK14);
					 
					 doc = IsDlgButtonChecked(hwnd, IDC_CHECK16);
					 xls = IsDlgButtonChecked(hwnd, IDC_CHECK18);
					 ppt = IsDlgButtonChecked(hwnd, IDC_CHECK19);
					 pdf = IsDlgButtonChecked(hwnd, IDC_CHECK17);
					 othD = IsDlgButtonChecked(hwnd, IDC_CHECK21);
					
					 mp3 = IsDlgButtonChecked(hwnd, IDC_CHECK23);
					 amr = IsDlgButtonChecked(hwnd, IDC_CHECK24);
					 id3 = IsDlgButtonChecked(hwnd, IDC_CHECK25);
					 othA = IsDlgButtonChecked(hwnd, IDC_CHECK26);
					 
					 
					 zip = IsDlgButtonChecked(hwnd, IDC_CHECK20);
					 rar = IsDlgButtonChecked(hwnd, IDC_CHECK27);
					 z7 = IsDlgButtonChecked(hwnd, IDC_CHECK28);
					 OthC = IsDlgButtonChecked(hwnd, IDC_CHECK30);
					 
					 mdf = IsDlgButtonChecked(hwnd, IDC_CHECK33);
					 ldf = IsDlgButtonChecked(hwnd, IDC_CHECK34);
					 othdb = IsDlgButtonChecked(hwnd, IDC_CHECK35);
					 
					 All = IsDlgButtonChecked(hwnd, IDC_CHECK31);
					 OthAll = IsDlgButtonChecked(hwnd, IDC_CHECK36);

					 int i,j = 0;
					 for(i = IDC_CHECK1;i<=IDC_CHECK36;i++)
					 {
						 if(IsDlgButtonChecked(hwnd, i))
						 {
                            j =1;
							break;
						 }
					 }
					if(!j)
					{
						MessageBox(MainW,"Please Select File Typr To Recover ! ","Worning !",MB_OK | MB_ICONINFORMATION);
					}
					else
					{         
						if(PopFolderOpenDlg(Tfil))
						{
							char te[MAX_PATH];
							sprintf(te,"%s\\Recovered Files",Tfil);
                            _mkdir(te);
							sprintf(Tfil,"%s",te);
						
						     int k;
							 for(k = IDC_CHECK1;k<=IDC_CHECK36;k++)
							 {
								 ImageW = GetDlgItem(hwnd, k);
								 EnableWindow(ImageW,0);
							 }
							 EnableWindow(cbList,0);
                            _beginthread (RecoverItemsL, 0, NULL) ;
 	                    }   
					}

				 break;
		     }
			   case IDC_BUTTON2 :
			 { 
				            isstopt = 1;
				           EnableWindow(BtnStart,1);
						   EnableWindow(BtnStop,1);
						    EnableWindow(cbList,1);
						   int k;
							 for(k = IDC_CHECK1;k<=IDC_CHECK36;k++)
							 {
								 ImageW = GetDlgItem(hwnd, k);
								 EnableWindow(ImageW,1);
							 }
				 break;
			 }
			       case IDC_CHECK1 :
				   {
					   
					 if(IsDlgButtonChecked(hwnd, IDC_CHECK1))
					 {
						 int i ,j;
						 for(  i=0, j = 1015;i<6,j<1021;i++,j++)
						 {
                            ImageW = GetDlgItem(hwnd, j);
		                    SendMessage(ImageW, BM_SETCHECK, 1, 0) ;
						 }
						 
					 }
					 else
					 {
						 int i,j;
						 for(  i=0,  j = 1015;i<6,j<1021;i++,j++)
						 {
                            ImageW = GetDlgItem(hwnd, j);
		                    SendMessage(ImageW, BM_SETCHECK, 0, 0) ;
						 }
					 }
					    break;
				   }
				   case IDC_CHECK8 :
				 {
					  if(IsDlgButtonChecked(hwnd, IDC_CHECK8))
					 {
						 
						 VideoW[0] = GetDlgItem(hwnd, IDC_CHECK9);
						 VideoW[1] = GetDlgItem(hwnd, IDC_CHECK10);
						 VideoW[2] = GetDlgItem(hwnd, IDC_CHECK11);
						 VideoW[3] = GetDlgItem(hwnd, IDC_CHECK12);
						 VideoW[4] = GetDlgItem(hwnd, IDC_CHECK29);
						 VideoW[5] = GetDlgItem(hwnd, IDC_CHECK14);
						 int i;
						 for(i =0;i<6;i++)
						 {
                            SendMessage(VideoW[i], BM_SETCHECK, 1, 0) ;
						 }
		                 
					 }
					 else
					 {
						 VideoW[0] = GetDlgItem(hwnd, IDC_CHECK9);
						 VideoW[1] = GetDlgItem(hwnd, IDC_CHECK10);
						 VideoW[2] = GetDlgItem(hwnd, IDC_CHECK11);
						 VideoW[3] = GetDlgItem(hwnd, IDC_CHECK12);
						 VideoW[4] = GetDlgItem(hwnd, IDC_CHECK29);
						 VideoW[5] = GetDlgItem(hwnd, IDC_CHECK14);
						 int i;
						 for(i =0;i<6;i++)
						 {
                            SendMessage(VideoW[i], BM_SETCHECK, 0, 0) ;
						 }
					 }
					 break;
			     }
				   case IDC_CHECK15 :
				 {
					  if(IsDlgButtonChecked(hwnd, IDC_CHECK15))
					 {
						 DocW[0] = GetDlgItem(hwnd, IDC_CHECK16);
						 DocW[1] = GetDlgItem(hwnd, IDC_CHECK18);
						 DocW[2] = GetDlgItem(hwnd, IDC_CHECK19);
						 DocW[3] = GetDlgItem(hwnd, IDC_CHECK17);
						 DocW[4] = GetDlgItem(hwnd, IDC_CHECK21);
						  int i;
						 for(i =0;i<5;i++)
						 {
                            SendMessage(DocW[i], BM_SETCHECK, 1, 0) ;
						 }
						 
					 }
					 else
					 {
						  DocW[0] = GetDlgItem(hwnd, IDC_CHECK16);
						 DocW[1] = GetDlgItem(hwnd, IDC_CHECK18);
						 DocW[2] = GetDlgItem(hwnd, IDC_CHECK19);
						 DocW[3] = GetDlgItem(hwnd, IDC_CHECK17);
						 DocW[4] = GetDlgItem(hwnd, IDC_CHECK21);
						  int i;
						 for(i =0;i<5;i++)
						 {
                            SendMessage(DocW[i], BM_SETCHECK, 0, 0) ;
						 }
					 }
					 break;
			     }
				   case IDC_CHECK22 :
				 {
					  if(IsDlgButtonChecked(hwnd, IDC_CHECK22))
					 {
						 AudioW[0] = GetDlgItem(hwnd, IDC_CHECK23);
						 AudioW[1] = GetDlgItem(hwnd, IDC_CHECK24);
						 AudioW[2] = GetDlgItem(hwnd, IDC_CHECK25);
						 AudioW[3] = GetDlgItem(hwnd, IDC_CHECK26);
						   int i;
						 for(i =0;i<4;i++)
						 {
                            SendMessage(AudioW[i], BM_SETCHECK, 1, 0) ;
						 }
						 
					 }
					 else
					 {
						 AudioW[0] = GetDlgItem(hwnd, IDC_CHECK23);
						 AudioW[1] = GetDlgItem(hwnd, IDC_CHECK24);
						 AudioW[2] = GetDlgItem(hwnd, IDC_CHECK25);
						 AudioW[3] = GetDlgItem(hwnd, IDC_CHECK26);
						   int i;
						 for(i =0;i<4;i++)
						 {
                            SendMessage(AudioW[i], BM_SETCHECK, 0, 0) ;
						 }
					 }
					 break;
			     }
				   case IDC_CHECK13:
				 {
					  if(IsDlgButtonChecked(hwnd, IDC_CHECK13))
					 {
						 compressW[0] = GetDlgItem(hwnd, IDC_CHECK20);
						 compressW[1] = GetDlgItem(hwnd, IDC_CHECK27);
						 compressW[2] = GetDlgItem(hwnd, IDC_CHECK28);
						 compressW[3] = GetDlgItem(hwnd, IDC_CHECK30);
						   int i;
						 for(i =0;i<4;i++)
						 {
                            SendMessage(compressW[i], BM_SETCHECK, 1, 0) ;
						 }
						 
					 }
					 else
					 {
						 compressW[0] = GetDlgItem(hwnd, IDC_CHECK20);
						 compressW[1] = GetDlgItem(hwnd, IDC_CHECK27);
						 compressW[2] = GetDlgItem(hwnd, IDC_CHECK28);
						 compressW[3] = GetDlgItem(hwnd, IDC_CHECK30);
						   int i;
						 for(i =0;i<4;i++)
						 {
                            SendMessage(compressW[i], BM_SETCHECK, 0, 0) ;
						 }
					 }
					 break;
			     }
				   case IDC_CHECK32 :
				 {
					  if(IsDlgButtonChecked(hwnd, IDC_CHECK32))
					 {
						 databW[0] = GetDlgItem(hwnd, IDC_CHECK33);
						 databW[1] = GetDlgItem(hwnd, IDC_CHECK34);
						 databW[2] = GetDlgItem(hwnd, IDC_CHECK35);
						    int i;
						 for(i =0;i<3;i++)
						 {
                            SendMessage(databW[i], BM_SETCHECK, 1, 0) ;
						 }
						 
					 }
					 else
					 {
						 databW[0] = GetDlgItem(hwnd, IDC_CHECK33);
						 databW[1] = GetDlgItem(hwnd, IDC_CHECK34);
						 databW[2] = GetDlgItem(hwnd, IDC_CHECK35);
						    int i;
						 for(i =0;i<3;i++)
						 {
                            SendMessage(databW[i], BM_SETCHECK, 0, 0) ;
						 }
					 }
					 break;
			     }
				  case IDC_CHECK31 :
				 {
					 if(IsDlgButtonChecked(hwnd, IDC_CHECK31))
					 {
						     int j;
						 for(j = IDC_CHECK1;j<=IDC_CHECK36;j++)
						 {
							 AllW = GetDlgItem(hwnd, j);
                            SendMessage(AllW, BM_SETCHECK, 1, 0) ;
						 }
						 
					 }
					 else
					 {
						    int j;
						 for(j = IDC_CHECK1;j<=IDC_CHECK36;j++)
						 {
							 AllW = GetDlgItem(hwnd, j);
                            SendMessage(AllW, BM_SETCHECK, 0, 0) ;
						 }
					 }
					break;
			     }
				   case IDC_CHECK36 :
				 {
					 if(IsDlgButtonChecked(hwnd, IDC_CHECK36))
					 {
						   int j;
						 for(j = IDC_CHECK1;j<=IDC_CHECK35;j++)
						 {
							 OthAllW = GetDlgItem(hwnd, j);
                            SendMessage(OthAllW, BM_SETCHECK, 0, 0) ;
						 }

						 
					 }
					 else
					 {
						   int j;
						 for(j = IDC_CHECK1;j<=IDC_CHECK35;j++)
						 {
							 OthAllW = GetDlgItem(hwnd, j);
                            SendMessage(OthAllW, BM_SETCHECK, 1, 0) ;
						 }
						  OthAllW = GetDlgItem(hwnd, IDC_CHECK31);
                          SendMessage(OthAllW, BM_SETCHECK, 0, 0) ;
					 }
					 
					break;
			     }
				  case IDC_BUTTON3 :
				{
					EndDialog(hwnd, 0);
					PostQuitMessage(0);
					break;
			    }
				  case IDC_BUTTON4 :
				{
					ShowWindow(MainW,SW_MINIMIZE );
					break;
			    }
				  case IDC_BUTTON5 :
			   {

				    MessageBox(MainW," GOVT. Polytechnic Unnao \n \
									        Deep Govind  CSE Final Year  - 2015 / 2016 \n\
									        Email - deepgovind4@gmailo.com  Mo. - 7388966141 \n\
										 ","About",MB_OK);
				    
				   break;
			   }
				  case IDC_BUTTON6 :
			    {
					    Drive[4] = dDriveChar[0];
					 AudioW[0] = GetDlgItem(wFileSystem, IDC_RADIO1);
						    SendMessage(AudioW[0] , BM_SETCHECK, 1, 0) ;
						   QAll = 1;
					 _beginthread ( ListDel, 0, NULL) ;
				     break;
				}
		 }
		break;
		case WM_DESTROY:
	     	PostQuitMessage(0);
		break;
	default:
			return FALSE;
	}
	return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(DataRicoveryMain), NULL, MainWinProcess);
}
