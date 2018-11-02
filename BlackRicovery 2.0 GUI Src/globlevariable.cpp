#include "globlevariable.h"
#include <stdio.h>
#include <QString>


  // char Drive[9] = "\\\\.\\D:";
   char val[4] = "D:\\";

   QString QDrive = "\\\\.\\ :";

   unsigned long long Drive_Free_Size = 0;
   unsigned long long Drive_Totel_size = 0;
   unsigned long long Drive_Totel_Sector = 0;
   QString ext  ="";

   QString DriveCombo_Var = 0;

    int ButtonStartStatus = 0;

     char Name[14] = {0};


     int Percent = 0;
   //  int Percent2  =0;
     int FindIterms = 0;
   //  unsigned long long MaxFilesize = 0;
     unsigned long long File_Size = 0;
     unsigned long long File_Start_Sector = 0;
     unsigned long long File_End_Sector = 0;
      bool Status = FALSE;
     QString DirOF = "";

     bool Chbox_ppt_var  = false;
     bool Chbox_doc_var  = false;
     bool Chbox_pst_var  = false;
     bool Chbox_chm_var  = false;
     bool Chbox_pdf_var  = false;
     bool Chbox_one_var  = false;
     bool Chbox_wpd_var  = false;
     bool Chbox_fb2_var  = false;
     bool Chbox_njx_var  = false;
     bool Chbox_txt_var  = false;
     bool Chbox_nk2_var  = false;
     bool Chbox_ps_var   = false;

       bool Chbox_7z_var  = false;
       bool Chbox_tar_var  = false;
       bool Chbox_bz2_var  = false;
       bool Chbox_rar_var  = false;
       bool Chbox_zip_var  = false;
       bool Chbox_cab_var  = false;
       bool Chbox_a_var  = false;
       bool Chbox_arj_var  = false;

       bool Chbox_myi_var  = false;
       bool Chbox_mdb_var  = false;
       bool Chbox_abcdb_var  = false;
       bool Chbox_db_var  = false;
       bool Chbox_fp7_var  = false;
       bool Chbox_ldf_var  = false;
       bool Chbox_edb_var  = false;
       bool Chbox_mdf_var  = false;
       bool Chbox_sqlite_var  = false;

       bool Chbox_asf_var  = false;
       bool Chbox_amv_var  = false;
       bool Chbox_avi_var  = false;
       bool Chbox_mp4_var  = false;
       bool Chbox_mpg_var  = false;
       bool Chbox_flv_var  = false;
       bool Chbox_mxf_var  = false;

       bool Chbox_jpg_var  = false;
       bool Chbox_mng_var  = false;
       bool Chbox_png_var  = false;
       bool Chbox_swf_var  = false;
       bool Chbox_aep_var  = false;
       bool Chbox_psd_var  = false;
       bool Chbox_bmp_var  = false;
       bool Chbox_gif_var  = false;
       bool Chbox_ico_var  = false;

       bool Chbox_flac_var  = false;
       bool Chbox_mid_var  = false;
       bool Chbox_ape_var  = false;
       bool Chbox_ogg_var  = false;
       bool Chbox_ra_var  = false;
       bool Chbox_au_var  = false;
       bool Chbox_mp3_var  = false;
       bool Chbox_aif_var  = false;

       bool Chbox_max_var  = false;
       bool Chbox_dwg_var  = false;
       bool Chbox_dxf_var  = false;
       bool Chbox_eps_var  = false;
       bool Chbox_fdb_var  = false;
       bool Chbox_stl_var  = false;
       bool Chbox_crw_var  = false;
       bool Chbox_orf_var  = false;
       bool Chbox_raf_var  = false;
       bool Chbox_mrw_var  = false;
       bool Chbox_raw_var  = false;
       bool Chbox_x3f_var  = false;

       bool Chbox_selectAll_var  = false;
