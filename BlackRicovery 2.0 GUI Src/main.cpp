#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <QApplication>
#include <QString>

#include "globlevariable.h"
#include "mainwindow.h"
#include "headerfuncation.h"


void FindHeader(MainWindow* w1,unsigned long long Start_Scan_Sector_From,unsigned long long Stop_Scan_Sector_To)
{
  char buffer[512] = {0};
  unsigned long dwRead;
  HANDLE  hSrc;


        hSrc = CreateFile((WCHAR*)QDrive.utf16(),  GENERIC_READ | GENERIC_WRITE , FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
     if (hSrc == INVALID_HANDLE_VALUE)
      {
          MessageBox(0,L"Unable to Read Drive ",L"",MB_OK);
      }
      else
      {
         while(Start_Scan_Sector_From<=Stop_Scan_Sector_To)
        {

              Percent = (Start_Scan_Sector_From*100)/Stop_Scan_Sector_To;

             SetFilePointer(hSrc,Start_Scan_Sector_From*sizeof(buffer), NULL, 0);
             ReadFile(hSrc, buffer, sizeof(buffer), &dwRead, NULL);


             if(Chbox_selectAll_var)
             {
                  doc_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  pst_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  chm_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  pdf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  one_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  wpd_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  fbk_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  njx_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  text_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  nk2_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                   ps_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

                  z7_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  tar_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  bz2_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  rar_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  zip_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  cab_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  a_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  arj_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

                  MYI_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mdb_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mdf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  abcdp_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  DB_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  dbf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  fp7_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  idf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  edb_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  sqlite_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

                  asf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  riff_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mp4_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mpg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  flv_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mxf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

                  jpg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mng_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  jng_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  swf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  psd_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  gif_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  ico_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  jng_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

                  flac_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mid_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  ape_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  ogg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  ra_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  au_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mp3_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  aif_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  max_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

                  dwg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  dxf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  fdb_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  stl_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  crw_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  orf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  raf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  raw_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mrw_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  x3f_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

                  cwk_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  asm_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  blend_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  frm_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  hr9_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mfa_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  mfg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                  prt_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
             }
             else
             {
                 if(Chbox_ppt_var || Chbox_doc_var )
                   doc_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_pst_var)
                     pst_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_chm_var )
                     chm_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_pdf_var)
                     pdf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_one_var)
                     one_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_wpd_var)
                     wpd_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_fb2_var)
                     fbk_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_njx_var)
                     njx_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_txt_var)
                     text_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_nk2_var)
                     nk2_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_ps_var)
                     ps_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_7z_var)
                     z7_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_tar_var)
                     tar_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_bz2_var)
                     bz2_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_rar_var)
                     rar_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_zip_var)
                     zip_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_cab_var)
                     cab_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_a_var)
                     a_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_arj_var)
                     arj_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_myi_var)
                     MYI_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mdb_var)
                     mdb_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_abcdb_var)
                     abcdp_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_db_var)
                     DB_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_fp7_var)
                     fp7_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_ldf_var)
                     idf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_edb_var)
                     edb_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mdf_var)
                     mdf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_sqlite_var)
                     sqlite_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_asf_var)
                     asf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
               //  if(Chbox_amv_var)
               //     amv_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_avi_var)
                     riff_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mp4_var)
                     mp4_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mpg_var)
                     mpg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_flv_var)
                     flv_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mxf_var)
                     mxf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_jpg_var)
                     jpg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mng_var)
                     mng_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_png_var)
                     png_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_swf_var)
                     swf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_aep_var)
                     ape_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_psd_var)
                     psd_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_bmp_var)
                     bmp_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_gif_var)
                     gif_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_ico_var)
                     ico_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_flac_var)
                     flac_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mid_var)
                     mid_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_ape_var)
                     ape_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_ogg_var)
                     ogg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_ra_var)
                     ra_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_au_var)
                     au_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mp3_var)
                     mp3_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_aif_var)
                     aif_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_max_var)
                     max_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_dwg_var)
                     dwg_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_dxf_var)
                     dxf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
        //         if(Chbox_eps_var)
        //             eps_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_fdb_var)
                     fdb_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_stl_var)
                     stl_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_crw_var)
                     crw_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_orf_var)
                     orf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_raf_var)
                     raf_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_mrw_var)
                     mrw_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_raw_var)
                     raw_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);
                 if(Chbox_x3f_var)
                     x3f_header_check(&hSrc,w1,buffer,&Start_Scan_Sector_From);

             }

              WriteDetails(w1);
              if( ButtonStartStatus ==  0)
                    break;
              Start_Scan_Sector_From++;
        }

      }

}
void RecoverItem(MainWindow* w1)
{
    // w1->RecoverSelectedItems();
}
void ListDel(MainWindow* w1)
{
     while(1)
    {
        while(1)
        {
            if(ButtonStartStatus == 1)
                break;
            if(ButtonStartStatus == 2)
                break;
        }
          if(ButtonStartStatus == 1)
         {
             FindHeader(w1,0,Drive_Totel_Sector);
         }
         else
         {
             RecoverItem(w1);
         }

        ButtonStartStatus = 0;
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
   w.setFixedHeight(653);
   w.setFixedWidth(577);


    _beginthread((void(*)(void*))ListDel, 0, (void*)&w) ;


    return a.exec();
}
