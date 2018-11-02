#ifndef DATAHEADER_H
#define DATAHEADER_H

             char mbr_header[2]  = {0x55,0xaa};
             
             char jpg_header_app0[4]= { 0xff,0xd8,0xff,0xe0};
             char jpg_header_app1[4]= { 0xff,0xd8,0xff,0xe1};
             char jpg_header_com[4]= { 0xff,0xd8,0xff,0xfe};
             char jpg_footer[2]= { 0xff,0xd9};
             char jpg_header_app0_avi[0x14]= { 0xff, 0xd8, 0xff, 0xe0, 0x00, 0x10, 'A', 'V', 'I', '1', 0x00, 0x00,0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
             
             char gif_header[6]=  { 'G','I','F','8','7','a'};
             char gif_header2[6]= { 'G','I','F','8','9','a'};
             char gif_footer[2]= {0x00, 0x3b};
             
            char exe_header[2]  = {'M','Z'};
              
            char png_header[8]= { 0x89, 'P', 'N','G', 0x0d, 0x0a, 0x1a, 0x0a};
            char mng_header[8]= { 0x8a, 'M', 'N','G', 0x0d, 0x0a, 0x1a, 0x0a};
            char jng_header[8]= { 0x8b, 'J', 'N','G', 0x0d, 0x0a, 0x1a, 0x0a};
            char mng_footer[4]= {'M','E','N','D'};
            char png_footer[4]= {'I','E','N','D'};
            char jng_footer[4]= {'J','E','N','D'};
            
            char id3_header[3]= {'I','D','3'};
            char mp3_header[1]= {0xFF};
            
            char rar_header[7]={0x52, 0x61, 0x72, 0x21, 0x1a, 0x07, 0x00 };
            char rar_footer[7]={0xc4, 0x3d, 0x7b, 0x00, 0x40, 0x07, 0x00 };
            
            char zip_header[4]  = { 'P', 'K', 0x03, 0x04};
            char zip_header2[8]  = { 'P', 'K', '0', '0', 'P', 'K', 0x03, 0x04}; 
            
            char header_7z[6]  = {'7','z', 0xbc, 0xaf, 0x27, 0x1c};
            
            char ctg_header[7]= {':','\\','D','C','I','M','\\'};
            
            char cwk_header[4]= {'B','O','B','O'};
            char cwk_footer[4]= {0xf0, 0xf1, 0xf2, 0xf3};
            
            char a_header[8]  = { '!','<','a','r','c','h','>','\n'};
            
            char deb_header_debian[14]  = { '!','<','a','r','c','h','>','\n','d','e','b','i','a','n'};
            
            char ab_header[2]={ 'L', 'J' };
            
            char abcdp_header[8]=  { 'b', 'p', 'l', 'i', 's', 't', '0', '0'};
            
            char ace_header[7] = { '*','*','A','C','E','*','*'};
            
            char ahn_header[4]	= {'d','b','f',0x00};
            char ahn_magic[10]	= {'A','H','N','E','N','B','L','A','T','T'};
            
            char aif_header[4]= {'F','O','R','M'};
            
            char all_header[8]= { 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x06, 0x04};
            
            char als_header[5]= { 0xab, 0x1e,  'V',  'x', 0x03 };
            char als_header2[13]= { 0x0c, 'L', 'i', 'v', 'e', 'D',  'o',  'c','u', 'm', 'e', 'n', 't'};
            char als_footer[0x16]= {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,0x80, 0x00, 0x00, 0x00, 0x80, 0x01};
            
            char amd_header[16]={  'L', 'i', 'c', 'o', 'm', '-', 'A', 'P', 'S', ' ', 'F', 'i', 'l', 'e', ' ', 'V' };
 
            char amt_header[20]={ 'L', 'i', 'c', 'o', 'm', '-', 'A', 'P',  'S', ' ', 'T', 'o', 'o', 'l', ' ', 'F', 'i', 'l', 'e', ' '};
            
            char amr_header[6]= {'#','!','A','M','R','\n'};
            
            char apa_magic[16]= { 'c', 'o', 'm', '.', 'a', 'p', 'a', '.',  'D', 'o', 'c', 'u', 'm', 'e', 'n', 't'};
            
            char ape_header[4]= { 'M', 'A', 'C', ' '};
            
            char apple_header[8]= { 0x00, 0x05, 0x16, 0x07, 0x00, 0x02, 0x00, 0x00};
            
            char arj_header[2]={0x60, 0xEA};
            char arj_footer[4]={0x60, 0xEA, 0x00, 0x00 };
            
            char asf_header[4]= { 0x30,0x26,0xB2,0x75};
            
            char asm_header[16]= { '#', 'U', 'G', 'C', ':', '2', ' ', 'A', 'S', 'S', 'E', 'M', 'B', 'L', 'Y', ' '};
            char asm_footer[11]= {'#', 'E', 'N', 'D', '_', 'O', 'F', '_', 'U', 'G', 'C'};
            
            char atd_header[16]= {'A' ,'B' ,'S' ,'0' ,'L' ,'U' ,'T' ,'E' ,'D' ,'A' ,'T' ,'A' ,'B' ,'A' ,'S' ,'E' };
            
            char au_header[4]= {'.','s','n','d'};
            
            char bkf_header[4]= { 'T','A','P','E'};
            
            char blend_header[7]  = { 'B', 'L', 'E', 'N', 'D', 'E', 'R'};
            char blend_header_footer[4]  = { 'E', 'N', 'D', 'B'};
            
            char bmp_header[2]= {'B','M'};
            
            char bz2_header[3]= {'B','Z','h'};
            
            char cab_header[4]  = { 'M','S','C','F'};
            
            char cam_header[4]= {0x07, 0x20, 'M', 'M'};
            
            char chm_header[16]={ 'I', 'T', 'S', 'F', 0x03, 0x00, 0x00, 0x00,0x60, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
            
            char class_magic[4]= { 0xCA, 0xFE, 0xBA, 0xBE };
            
            char cm_header[8]	= { 'f','L','m','C','0','0','0','1'};
            
            char compress_header[10]	= {'S', 'Z', 'D', 'D', 0x88, 0xf0, 0x27, 0x33, 'A', 0x00};
            
            char crw_header_be[2]= {'I','I'};
            char crw_header_le[2]= {'M','M'};
            char crw_footer[2]= { 0x0A, 0x30};
            
            char evt_header[8]= {0x30, 0x00, 0x00, 0x00, 'L', 'f', 'L', 'e'};
            
            char ext2_sb_header[2]= {0x53, 0xEF};
            
            char d2s_header[8]= {0x55, 0xaa, 0x55, 0xaa, 0x60, 0x00, 0x00, 0x00};
            
            char dat_header[8]= {0x30, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            char datIE_header[0x1c]= {'C', 'l', 'i', 'e', 'n', 't', ' ', 'U', 'r', 'l', 'C', 'a', 'c', 'h', 'e', ' ','M', 'M', 'F', ' ', 'V', 'e', 'r', ' ','5', '.', '2', 0x00};
            
            char DB_header[6]= {0x19, 0x01, 0x00, 0x08, 0x02, 0x20};
            
            char dbf_header[1]= {0x3};
            
            char dim_header[4]= { 'S', 'P','C','I'};
            
            char *dir_header=(char *)".          ";
            
            char djv_header[8]= { 'A','T','&','T','F','O','R','M'};
            
            char doc_header[8]= { 0xd0, 0xcf, 0x11, 0xe0, 0xa1, 0xb1, 0x1a, 0xe1};
            char doc_footer[14]= {0x57, 0x6F, 0x72, 0x64, 0x2E, 0x44, 0x6F, 0x63, 0x75, 0x6D, 0x65, 0x6E, 0x74, 0x2E};
            char xls_footer[28]= {0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x00, 0x6F, 0x00, 0x72, 0x00, 0x6B, 0x00, 0x62, 0x00, 0x6F, 0x00, 0x6F, 0x00 , 0x6B, 0x00};
            char ppt_footer[37]= {0x50, 0x00, 0x6F, 0x00, 0x77, 0x00, 0x65, 0x00, 0x72, 0x00, 0x50, 0x00, 0x6F, 0x00, 0x69, 0x00, 0x6E, 0x00, 0x74, 0x00, 0x20, 0x00, 0x44, 0x00, 0x6F, 0x00, 0x63, 0x00, 0x75, 0x00, 0x6D, 0x00, 0x65, 0x00, 0x6E, 0x00, 0x74};
           
            char sdpx_header[4]= {'S', 'D', 'P', 'X'};
            char xpds_header[4]= {'X', 'P', 'D', 'S'};
            char ver10[8]= 	   {'V', '1', '.', '0', 0x00, 0x00, 0x00, 0x00};
            
            char drw_header[14]= {'#', 'U', 'G', 'C', ':', '2', ' ', 'D','R', 'A', 'W', 'I', 'N', 'G'};
            char drw_footer[11]= {'#', 'E', 'N', 'D', '_', 'O', 'F', '_','U', 'G', 'C'};
            
            char ds2_header[4]= { 0x03, 'd','s','2'};
            
            char dsc_header[3]= { 'M','L','T'};
            
            char dss_header[4]= { 0x02, 'd','s','s'};
            
            char dta_header_71le[3]= {0x71, 0x02, 0x01};
            char dta_header_72le[3]= {0x72, 0x02, 0x01};
            
            char dump_header_le_old_fs[4]  = { 0x6b, 0xea, 0x00, 0x00};
            char dump_header_le_new_fs[4]  = { 0x6c, 0xea, 0x00, 0x00};
            
            char dv_header[3]= {0x1f, 0x07, 0x00};
            
            char dwg_header_12[11]= {'A', 'C', '1', '0', '1', '2', 0x00, 0x00, 0x00, 0x00, 0x00};
            char dwg_header_13[11]= {'A', 'C', '1', '0', '1', '3', 0x00, 0x00, 0x00, 0x00, 0x00};
            char dwg_header_14[11]= {'A', 'C', '1', '0', '1', '4', 0x00, 0x00, 0x00, 0x00, 0x00};
            char dwg_header_15[11]= {'A', 'C', '1', '0', '1', '5', 0x00, 0x00, 0x00, 0x00, 0x00};
            
            char header_dxflib[10]= 	{'9', '9', '9', '\n', 'd', 'x', 'f', 'l', 'i', 'b'};
            char header_dxflib_dos[11]= 	{'9', '9', '9', '\r', '\n','d', 'x', 'f', 'l', 'i', 'b'};
            char header_dxf[11]= 	{' ', ' ', '0', '\n','S', 'E', 'C', 'T', 'I', 'O', 'N'};
            char header_dxf_dos[12]= 	{' ', ' ', '0', '\r', '\n',  'S', 'E', 'C', 'T', 'I', 'O', 'N'};
            char dxf_footer[4]= {'\n', 'E', 'O', 'F'};
            
            char edb_magic[8]= { 0xef, 0xcd, 0xab, 0x89, 0x20, 0x06, 0x00, 0x00};
            
            char elf_header[4]  = { 0x7f, 'E','L','F'};
            
            char emf_header[4]= { 0x01, 0x00, 0x00, 0x00};
            char emf_sign[4]= { ' ','E', 'M','F'};
            
            char fbk_header[10]	= {'T','a','b','l','e','D','a','t','a',' '};
			
			char fcp_header[5]= { 0xA2, 'K','e','y','G'};
			
			char fcs_signature[6]= {'F','C','S','3','.','0'}; 
            
            char fdb_header[7]	= { 0x00, 0x00, 0x00, 0x5c, 0xa0, 0x83, 0x02};
            
            char fh5_header[8]  = { 0x41, 0x47, 0x44, 0x31, 0xbe, 0xb8, 0xbb, 0xce };
            
            char fh10_header[]  = { 0x1c, 0x01 ,0x00, 0x00, 0x02, 0x00, 0x04, 0x1c, 0x01 , 0x14, 0x00, 0x02, 0x00, 0x14, 0x1c, 0x01, 0x16, 0x00 ,0x02, 0x00, 0x08, 0x1c, 0x01, 0x1e, 0x00 , 0xa , 0x46, 0x72, 0x65, 0x65, 0x48, 0x61, 0x6e, 0x64, 0x31, 0x30};
            
            char fits_header[9]=  { 'S','I','M','P','L','E',' ',' ','='};
            
            char flac_header[4]= {'f', 'L', 'a', 'C'};
            
            char flp_header[8]= {'F', 'L', 'h', 'd', 0x06, 0x00, 0x00, 0x00};
            
            char flv_header[4]= {'F', 'L', 'V', 0x01};
           
            char sign_navnl[5]	= {'N','A','V','N','L'};
            char sign_navw[4]		= {'N','A','V','W'};
            char magic_codeunit[9]	= {'C','o','d','e','u','n','i','t',' '};
            char magic_dataport[9]	= {'D','a','t','a','p','o','r','t',' '};
            char magic_form[5]	= {'F','o','r','m',' '};
            char magic_menusuite[10]	= {'M','e','n','u','S','u','i','t','e',' '};
            char magic_report[7]	= {'R','e','p','o','r','t',' '};
            char magic_table[6]	= {'T','a','b','l','e',' '};
            char magic_xmlport[8]	= {'X','M','L','p','o','r','t',' '};
            
            char fp7_header[0x14]= { 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,  0x00, 0x05, 0x00, 0x02, 0x00, 0x02, 0xc0,  'H',  'B',  'A',  'M',  '7'};
            
            char frm_header[14]= { '#', 'U', 'G', 'C', ':', '2', ' ', 'D', 'W', 'G', 'F', 'O', 'R', 'M'};
            char frm_footer[11]= {  '#', 'E', 'N', 'D', '_', 'O', 'F', '_', 'U', 'G', 'C'};
            
            char fs_header[4]={ 'F', 'S','2','1' };
            
            char gho_header[3]= { 0xfe, 0xef, 0x01 };
            char gho_header_next[8]= { 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
            
            char gz_header_magic[3]= {0x1F, 0x8B, 0x08};
         
		    char hds_header[20]= { 'W','i','t','h','o','u','t','F','r','e','e','S','p','a','c','e',  0x02, 0x00, 0x00, 0x00};
            
            char hr9_header[17]= { 0xc0, 0xde, 0xca, 0xfe, 0x00, 0x00, 0x00, 0x00,  'H',  'e',  'r',  'e',  'd',  'i',  's', 0x99, 0x20};
            char hr9_footer[4]= {0xc0, 0xde, 0xca, 0xfe};
            
            char header_ico[4]= 	{0x00 , 0x00, 0x01, 0x00};
            
            char ifo_header_vmg[12]=  { 'D', 'V', 'D', 'V', 'I', 'D', 'E', 'O', '-', 'V', 'M', 'G'};
            char ifo_header_vts[12]=  { 'D', 'V', 'D', 'V', 'I', 'D', 'E', 'O', '-', 'V', 'T', 'S'};
            
            char imb_header[15]= { 0x00, 0x00, 0x00, 'I','n','c','r','e','d','i','m','a','i','l',' '};
            
            char indd_header[24]={ 0x06, 0x06, 0xed, 0xf5, 0xd8, 0x1d, 0x46, 0xe5,  0xbd, 0x31, 0xef, 0xe7, 0xfe, 0x74, 0xb7, 0x1d,  0x44, 0x4f, 0x43, 0x55, 0x4d, 0x45, 0x4e, 0x54 };
            
            char iso_header[6]= { 0x01, 'C', 'D', '0', '0', '1'}; 
            
            char itunes_header[8]= {'m', 'h', 'b', 'd', 0x68, 0x00, 0x00, 0x00};
            
            char kdb_header[8]= {0x03, 0xd9, 0xa2, 0x9a, 0x65, 0xfb, 0x4b, 0xb5};
            
            char ldf_header[4]= { 0x01, 0x0f, 0x00, 0x00 };
            
            char lnk_header[20]= {  'L', 0x00, 0x00, 0x00,   0x01, 0x14, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46  };
            
            char logic_header[12]= { 0xab, 0xc0, 0x47, 0x13, 0x05, 0x17, 0x00, 0x15, 0x00, 0x04, 0x00, 0x24};
            
            char m2ts_header[4]=  { 'H','D','M','V'};
            char m2t_header[4] =  { 'T','S','H','V'};
            
            char max_header[4]  = { 'V','i','G','F'};
            
            char mb_header[8]= {'M','a','y','a','F','O','R','4'};
            char mb_header2[8]= {'M','A','Y','A','F','O','R','4'};
            char mp_header[8]= {'M','P','L','E','F','O','R','4'};
            
            char mcd_header[11]= { 'V', 'e','c','t','o','r','W','o','r','k','s'};
            
            char mdb_header[]= { 0x00, 0x01, 0x00, 0x00, 'S', 't', 'a', 'n', 'd','a','r','d',' ','J','e','t',' ', 'D','B', 0x00};
            char accdb_header[]= { 0x00, 0x01, 0x00, 0x00, 'S', 't', 'a', 'n', 'd','a','r','d',' ','A','C','E',' ', 'D','B', 0x00};

            char mdf_header[4]= { 0x01, 0x0f, 0x00, 0x00 };
            
            char mfa_header[8]= { 'M', 'M', 'F', '2', 0x04, 0x00, 0x00, 0x00};
            char mfa_footer[5]= {'!','D','N','E', '!'};
            
            char mfg_header[16]= { '#', 'U', 'G', 'C', ':', '2', ' ', 'M', 'F', 'G', '_', 'A', 'S', 'S', 'E', 'M'};
            char mfg_footer[11]= {  '#', 'E', 'N', 'D', '_', 'O', 'F', '_',  'U', 'G', 'C'};
            
            char mid_header[4]  = { 'M','T','h','d'};
            char mid_footer[3]= {0xff, 0x2f, 0x00};
            
            char mk5_header[4]= { 0x36, 0xff, 0xff, 0xff }; 
            char mk5_header2[4]= { 0x00, 0x40, 0x1c, 0x46 };
            
            char mkv_header[4]= { 0x1a,0x45,0xdf,0xa3};
            
            char mpg_header[3]= {0x00, 0x00, 0x01};
            
            char mrw_header[4]= { 0x00,'M','R','M'};
            
            char mus_header[18]  = { 'E','N','I','G','M','A',' ','B','I','N','A','R','Y',' ','F','I','L','E' };
            
            char mxf_header[11]= {  0x06, 0x0e, 0x2b, 0x34, 0x02, 0x05, 0x01, 0x01, 0x0d, 0x01, 0x02};

            char mysql_header[4]= {0xfe, 0xfe, 0x07, 0x01};
            char mysql_header_def[2]= {0xfe, 0x01};
            
            char njx_header[4]= {0x04, 'N', 'j', 0x0f};
            char njx_footer[4]= {'N', 'J', '*', 0x04};
            
            char nk2_header[8]=  { 0x0d, 0xf0, 0xad, 0xba, 0x0a, 0x00, 0x00, 0x00 };
            
            char ogg_header[4]= {'O','g','g','S'};
            
            char one_header[16]= { 0xe4, 0x52, 0x5c, 0x7b, 0x8c, 0xd8, 0xa7, 0x4d, 0xae, 0xb1, 0x53, 0x78, 0xd0, 0x29, 0x96, 0xd3 };

            char orf_header[4]=  { 0x49, 0x49, 0x52, 0x53};
            char orf_header2[4]= { 'I', 'I', 'R', 'O'};
            
            char paf_header[11]= {'5', '0', '0', '\0', '5', '0', '0', '\0', 'P','A','F'};
            
            char pap_header[]  = {'P','A','P','1'};
            
            char pcap_header[4]	= {0xd4, 0xc3, 0xb2, 0xa1};
            
            char pdf_header[6]  = { '%','P','D','F','-','1'};
            char pdf_footer[4]= { '%', 'E', 'O', 'F'};
            
             char pfx_header[11]= { 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01};
            
            char prc_header[16]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,'a','p','p','l'};

            char prt_header[12]= { '#', 'U', 'G', 'C', ':', '2', ' ', 'P', 'A', 'R', 'T', ' '};
            char prt_footer[11]= {  '#', 'E', 'N', 'D', '_', 'O', 'F', '_', 'U', 'G', 'C'};
            
            char ps_header[11]= { '%','!','P','S','-','A','d','o','b','e','-'};
            
            char psd_header[4]={'8','B','P','S' };
            
            char psp_header[] =  "Paint Shop Pro Image File";
                 
            char pst_header[4]= { '!','B','D','N'};
            char dbx_header[4]= { 0xCF, 0xAD, 0x12, 0xFE };
            char wab_header[16] = { 0x9c, 0xcb, 0xcb, 0x8d, 0x13, 0x75, 0xd2, 0x11, 0x91, 0x58, 0x00, 0xc0, 0x4f, 0x79, 0x56, 0xa4 };
            
            char ptb_header[4]= {'p', 't', 'a', 'b'};
            
            char pyc_15_magic[4]= { 0x99, 0x4e, '\r', '\n'};
            char pyc_20_magic[4]= { 0x87, 0xc6, '\r', '\n'};
            char pyc_21_magic[4]= { 0x2a, 0xeb, '\r', '\n'};
            char pyc_22_magic[4]= { 0x2d, 0xed, '\r', '\n'};
            char pyc_23_magic[4]= { 0x3b, 0xf2, '\r', '\n'};
            char pyc_24_magic[4]= { 0x6d, 0xf2, '\r', '\n'};
            char pyc_25_magic[4]= { 0xb3, 0xf2, '\r', '\n'};
            
            char qbb_header[10]= {0x45, 0x86, 0x00, 0x00, 0x06, 0x00, 0x02, 0x00, 0x01, 0x00};
            char qbw_header[4]= {0x56, 0x00, 0x00, 0x00};
            
            char qdf_header[6]  = { 0xAC, 0x9E, 0xBD, 0x8F, 0x00, 0x00};
            
            char qxd_header[4]={'X','P','R','3' };
            char qxp_header_be[6]={'I','I','X','P','R','3' };
            char qxp_header_le[6]={'M','M','X','P','R','3' };
            
            char ra_header[4]  = { '.', 'r', 'a', 0xfd};
            
            char raf_header[8]= {'F','U','J','I','F','I','L','M'};
            
            char raw_header_contax[7]= {'A','R','E','C','O','Y','K'};
            char raw_header_panasonic[4]= {'I','I','U','\0'};
            
            char rdc_header[9]= {'D','S','C','-','I','m','a','g','e'};
           
            char reg_header_nt[4]  = { 'r','e','g','f'};
            char reg_header_9x[4]  = { 'C','R','E','G'};
            
            char MS_res_header[9]= {0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xFF};
            
            char riff_header[4]= {'R','I','F','F'};
            
            char rm_header[9]  = { '.', 'R', 'M', 'F', 0x00, 0x00, 0x00, 0x12, 0x00};
            
            char rns_header[]  = "Propellerheads Reason Song File";
            
            char rpm_header[5]= {0xed, 0xab, 0xee, 0xdb, 0x3};
            
            char ses_magic[8]= { 'C', 'O', 'O', 'L', 'N', 'E', 'S', 'S'};
            
            char sib_header[9]= {0x0F, 'S', 'I', 'B', 'E', 'L', 'I', 'U', 'S'};
            
            char sit_header[14]  = { '7','1','0','0',' ','3','.','3','D',' ','7','1','0','0'};
            
            char skd_header[29]= { 'A',  'u',  't',  'o',  'S',  'k',  'e',  't',  'c',  'h', 0x20,  'd',  'r',  'a',  'w',  'i',   'n',  'g', 0x20,  'd',  'a',  't',  'a',  'b',  'a',  's',  'e', 0x0d, 0x0a };
            
            char skp_header[32]= {  0xff, 0xfe, 0xff, 0x0e, 'S', 0x00, 'k', 0x00, 'e', 0x00, 't', 0x00, 'c', 0x00, 'h', 0x00, 'U',  0x00,  'p', 0x00, ' ', 0x00, 'M', 0x00, 'o', 0x00, 'd', 0x00, 'e', 0x00, 'l', 0x00 };
            
            char sp31_header[8]=  { 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            char sp32_header[8]=  { 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
            
            //char spe_header[4]= {0x67, 0x45, 0x23, 0x01};
            
             char spf_header[12]= { 'S', 'P', 'F', 'I', 0x00, 0x02, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00};
            
            char spss_header[4]= {'$', 'F', 'L', '2'};
            
            char sqlite_header[15]= {'S','Q','L','i','t','e',' ','f','o','r','m','a','t',' ','3'}; 
            
            char sqm_header[6]=  { 'M', 'S', 'Q', 'M', 'x', 0x00};
            
            char stl_header[6]={ 's', 'o', 'l', 'i', 'd', ' '};
            char spaces[16] =   { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
            
            char stuffit_header[7] = { 'S', 't', 'u', 'f', 'f', 'I', 't'};
            
            char swf_header_compressed[3]= {'C','W','S'};
            char swf_header[3]= {'F','W','S'};
            
            char tar_header_gnu[6]	= { 'u','s','t','a','r',0x00};
            char tar_header_posix[8]  = { 'u','s','t','a','r',' ',' ',0x00};
            
            char tax_header[6]=  { 'T', 'T', 'F', 'N', 0x01, 0x01};
            
            char tib_header[4]= { 0xb4, 0x6e, 0x68, 0x44};
            
            char tiff_header_be[4]= { 'M','M',0x00, 0x2a};
            char tiff_header_le[4]= { 'I','I',0x2a, 0x00};
            
            char tph_header[20]= { '#', 'U', 'G', 'C', ':', '2', ' ', 'M', 'F', 'G', '_', 'T', 'O', 'O', 'L', '_', 'P', 'A', 'T', 'H'};
            char tph_footer[11]= {  '#', 'E', 'N', 'D', '_', 'O', 'F', '_',  'U', 'G', 'C'};
            
            char header_ttf[5]= 	{0x00 , 0x01, 0x00, 0x00, 0x00};
            //txt files
            char header_adr[]	= "Opera Hotlist version 2.0";
            char header_bash[]  	= "#!/bin/bash";
            char header_cls[24]	= {'V','E','R','S','I','O','N',' ','1','.','0',' ','C','L','A','S','S','\r','\n','B','E','G','I','N'};
            char header_cue[]	= "REM GENRE ";
            char header_dc[]		= "SC V10";
            char header_dif[12]	= { 'T', 'A', 'B', 'L', 'E', '\r', '\n', '0', ',', '1', '\r', '\n'};
            char header_ers[]	= "DatasetHeader Begin";
            char header_ics[]	= "BEGIN:VCALENDAR";
            char header_imm[13]	= {'M','I','M','E','-','V','e','r','s','i','o','n',':'};
            char header_lyx[7]	= {'#', 'L', 'y', 'X', ' ', '1', '.'};
            char header_m3u[7]	= {'#','E','X','T','M','3','U'};
            char header_mail[5]	= {'F','r','o','m',' '};
            char header_msf[]	= "// <!-- <mdb:mork:z";
            char header_perlm[] 	= "package";
            char header_ram[]	= "rtsp://";
            char header_ReceivedFrom[14]= {'R','e','c','e','i','v','e','d',':',' ','f','r','o','m'};
            char header_reg[]  	= "REGEDIT4";
            char header_ReturnPath[13]= {'R','e','t','u','r','n','-','P','a','t','h',':',' '};
            char header_rpp[16]	= { '<', 'R', 'E', 'A', 'P', 'E', 'R', '_', 'P', 'R', 'O', 'J', 'E', 'C', 'T', ' '};
            char header_rtf[5]	= { '{','\\','r','t','f'};
            char header_sh[]  	= "#!/bin/sh";
            char header_slk[]  	= "ID;PSCALC3";
            char header_stl[]	= "solid ";
            char header_stp[]  	= "ISO-10303-21;";
            char header_wpl[21]	= { '<', '?', 'w', 'p', 'l', ' ', 'v', 'e', 'r', 's', 'i', 'o', 'n', '=', '"', '1', '.', '0', '"', '?', '>' };
            char header_xml[]	= "<?xml version=";
            
            char header_asp[]	= "<%@ language=\"vbscript";
            char header_bat[]  	= "@echo off";
            char header_vcf[]	= "begin:vcard";
            char header_sig_perl[] = "perl";
            char header_sig_python[] = "python";
            char header_sig_ruby[] = "ruby";
            char sign_c[]			= "#include";
            char sign_h[]			= "/* ";
            char sign_jsp[]			= "<%@";
            char sign_jsp2[]		= "<%=";
            char sign_php[]			= "<?php";
            char sign_tex[]			= "\\begin{";
            char sign_html[]		= "<html";
            char html_footer[7]= {'<', '/', 'h', 't', 'm', 'l', '>'};
       
	        char tz_header[20]={ 'T', 'Z', 'i', 'f', 0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, };
            char tz2_header[20]={ 'T', 'Z', 'i', 'f',  '2', 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00,  0x00, 0x00, 0x00, 0x00, };
            
            char veg_header[4]= {'r','i','f','f'};
            
            char vmdk_header4[4]= { 'K','D','M','V'};
            char vmdk_header3[4]= { 'C','O','W','D'};
            
            char wks_header[10]  = { 0x00, 0x00, 0x02, 0x00, 0x04, 0x04, 0x06, 0x00, 0x08, 0x00};
            char wk4_header[8]  = { 0x00, 0x00, 0x1a, 0x00, 0x02, 0x10, 0x04, 0x00};
            
            char apm_header[6] = { 0xd7, 0xcd, 0xc6, 0x9a, 0x00, 0x00 };
            char emff_header[6] = { 0x20, 0x45, 0x4D, 0x46, 0x00, 0x00 };
            char wmf_header[6] = { 0x01, 0x00, 0x09, 0x00, 0x00, 0x03 };
            
            char wnk_header[6]= {'R','P','K','W','I',0x02};
            
            char wpd_header[4]= {0xff, 'W','P','C'};
            
           // char wv_header[4]=  { 'w', 'v', 'p', 'k'};
            
            char x3f_header[4]= {'F','O','V','b'};
            
            char xcf_header_v0[13]= {'g','i','m','p',' ','x','c','f',' ','f','i','l','e'};
            char xcf_header_v1[10]= {'g','i','m','p',' ','x','c','f',' ','v'};
            
            char xm_header[17]  = { 'E','x','t','e','n','d','e','d',' ','M','o','d','u','l','e',':',' '};
            
            char xpt_header[16]={  'X', 'P', 'C', 'O', 'M', '\n', 'T', 'y', 'p', 'e', 'L', 'i', 'b', '\r', '\n', 0x1a};
            
            char xsv_header[9]= {'B','L','O','C', 'K', 'L', 0xDC, 0x1D, 'd'};
            
            char xv_header[7]= 	{'P', '7', ' ', '3', '3', '2', '\n'};
            
 

#endif  