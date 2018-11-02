
#ifndef ALLCHACK_H
#define ALLCHACK_H


int allcheck(char buffer[])
 {
     /*      MaxFilesize = MaxFilesize + 512;
          //Percent2  =   Percent2 + 1;
          if(MaxFilesize>=3368709120)
          {
              MaxFilesize = 0;
              return 1;
          }
     */
          if((memcmp(buffer, gif_header,sizeof(gif_header)))==0 || (memcmp (buffer, gif_header2,sizeof(gif_header2)))==0 )
         {

                 return 1;
         }

 /* 	    if( (memcmp(buffer, exe_header,sizeof(exe_header)))==0 )
        {

                 return 1;
        }   */
        if(memcmp(buffer,png_header,sizeof(png_header))==0)
        {

                 return 1;
        }
        if(memcmp(buffer,jng_header,sizeof(jng_header))==0)
        {

                 return 1;
        }
        if(memcmp(buffer,mng_header,sizeof(mng_header))==0)
        {

                 return 1;
        }
        if(buffer[0]=='I' && buffer[1]=='D' && buffer[2]=='3' && (buffer[3]==2 || buffer[3]==3 || buffer[3]==4) && buffer[4]==0)
        {

                 return 1;
         }
        if(buffer[0]==0xFF && ((buffer[1]&0xFE)==0xFA ||(buffer[2]&0xFE)==0xF2 || (buffer[3]&0xFE)==0xE2))
         {

                 return 1;
        }
        if(memcmp(buffer,rar_header,sizeof(rar_header))==0)
         {

                 return 1;
        }
         if(memcmp(buffer,zip_header2,sizeof(zip_header2))==0 || memcmp(buffer,zip_header,sizeof(zip_header))==0)
        {

                 return 1;
         }
         if(memcmp(buffer,  jpg_header_app0, sizeof(jpg_header_app0))==0 || memcmp(buffer, jpg_header_app1, sizeof(jpg_header_app1))==0 || memcmp(buffer, jpg_header_com,  sizeof(jpg_header_com))==0)
        {

                 return 1;
        }
          if(memcmp(buffer,header_7z,sizeof(header_7z))==0)
        {



                 return 1;
        }
         if(memcmp(buffer+1, ctg_header,sizeof(ctg_header))==0)
        {



                 return 1;
        }
          if(memcmp(buffer+4, cwk_header, sizeof(cwk_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,a_header,sizeof(a_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,deb_header_debian,sizeof(deb_header_debian))==0)
          {



                 return 1;
          }
          if(buffer[0]=='L' && buffer[1]=='J' && (buffer[2]==0x1a || buffer[2]==0x0a) && buffer[3]==0x00)
         {



                 return 1;
         }
           if(memcmp(buffer, abcdp_header, sizeof(abcdp_header))==0 && buffer[9]==0x01)
         {



                 return 1;
         }
          if(memcmp(&buffer[7],ace_header,sizeof(ace_header))==0 && buffer[4]==0)
          {



                 return 1;
          }
          if(memcmp(buffer, ahn_header, sizeof(ahn_header))==0 && memcmp(&buffer[8], ahn_magic, sizeof(ahn_magic))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,aif_header,sizeof(aif_header))==0 && buffer[8]=='A' && buffer[9]=='I' && buffer[10]=='F' && (buffer[11]=='F' || buffer[11]=='C'))
         {



                 return 1;
         }
    /* 	   if(memcmp(buffer,all_header,sizeof(aif_header))==0)
         {



                 return 1;
         }
         */

         if(memcmp(buffer,als_header,sizeof(als_header))==0 &&  memcmp(buffer+11,als_header2,sizeof(als_header2))==0)
        {



                 return 1;
        }
          if(memcmp(buffer, amd_header, sizeof(amd_header))==0)
          {



                 return 1;
          }
           if(memcmp(buffer, amt_header, sizeof(amt_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer,amr_header,sizeof(amr_header))==0)
         {



                 return 1;
         }
          if(memcmp(&buffer[8], apa_magic, sizeof(apa_magic))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,ape_header,sizeof(ape_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,apple_header,sizeof(apple_header))==0)
          {



                 return 1;
          }
    /* 	  if(memcmp(buffer, arj_header, sizeof(arj_header))==0)
         {



                 return 1;
         }*/
          if(memcmp(buffer,asf_header,sizeof(asf_header))==0)
         {



                 return 1;
         }

         if(memcmp(buffer,asm_header,sizeof(asm_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer,atd_header,sizeof(atd_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,au_header,sizeof(au_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,bkf_header,sizeof(bkf_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer,blend_header,sizeof(blend_header))==0 && (buffer[7]=='_' || buffer[7]=='-'))
         {



                 return 1;
         }

          if(buffer[0]=='B' && buffer[1]=='M' && buffer[6]==0x00 && buffer[7]==0x00 && buffer[8]==0x00 && buffer[9]==0x00)
         {



                 return 1;
         }
          if(buffer[0]=='B' && buffer[1]=='Z' && buffer[2]=='h' && buffer[3]>='0' && buffer[4]=='1' && buffer[5]=='A' && buffer[6]=='Y' && buffer[7]=='&' && buffer[8]=='S' && buffer[9]=='Y')
          {



                 return 1;
          }

          if(memcmp(buffer,cab_header,sizeof(cab_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,cam_header,sizeof(cam_header))==0)
        {



                 return 1;
        }
        if(memcmp(buffer, chm_header, sizeof(chm_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer, class_magic, sizeof(class_magic))==0)
          {



                 return 1;
          }

          if(memcmp(&buffer[0x0],cm_header,sizeof(cm_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer, compress_header, sizeof(compress_header))==0)
          {



                 return 1;
          }
/* 		 if((memcmp(buffer, crw_header_be, sizeof(crw_header_be))==0) || (memcmp(buffer, crw_header_le, sizeof(crw_header_le)) == 0) && (memcmp(buffer+6,"HEAPCCDR",8)==0))
          {



                 return 1;
          }*/
           if(memcmp(buffer,evt_header,sizeof(evt_header))==0)
         {



                 return 1;
         }

    /* 	  if(memcmp(buffer,ext2_sb_header,sizeof(ext2_sb_header))==0)
         {



                 return 1;
         }*/
           if(memcmp(buffer,d2s_header,sizeof(d2s_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer,dat_header,sizeof(dat_header))==0)
          {



                 return 1;
          }
            if(memcmp(buffer,datIE_header,sizeof(datIE_header))==0)
          {



             return 1;
           }

          if(memcmp(buffer,DB_header,sizeof(DB_header))==0)
          {



             return 1;
          }
/*		   if(buffer[0]==0x3 && (buffer[1]>80 || buffer[1]<20) && (buffer[2]>=1 && buffer[2]<=12) && (buffer[3]>=1 && buffer[3]<=31))
         {



             return 1;
         }   */
          if(memcmp(&buffer[0x0c],dim_header,sizeof(dim_header))==0)
          {



             return 1;
          }
            if(memcmp(buffer,dir_header,8+3)==0 && memcmp(&buffer[0x20],"..         ",8+3)==0)
          {



             return 1;
          }
          if(memcmp(buffer,djv_header,sizeof(djv_header))==0)
         {



            return 1;
         }
           if(memcmp(buffer,doc_header,sizeof(doc_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,sdpx_header,sizeof(sdpx_header))==0 || memcmp(buffer,xpds_header,sizeof(xpds_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,drw_header,sizeof(drw_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer,ds2_header,sizeof(ds2_header))==0)
         {



                 return 1;
         }
           if(memcmp(buffer,dsc_header,sizeof(dsc_header))==0)
         {



                 return 1;
         }
          if(memcmp(buffer,dss_header,sizeof(dss_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer,dta_header_71le,sizeof(dta_header_71le))==0 ||  memcmp(buffer,dta_header_72le,sizeof(dta_header_72le))==0)
          {



                 return 1;
          }
           if(memcmp(buffer+0x18,dump_header_le_old_fs,sizeof(dump_header_le_old_fs))==0 || memcmp(buffer+0x18,dump_header_le_new_fs,sizeof(dump_header_le_new_fs))==0)
            {



                 return 1;
           }

           if(buffer[0]==0x1f && buffer[1]==0x07 && buffer[2]==0x00 && buffer[5]==0x78 && buffer[6]==0x78 && buffer[7]==0x78)
          {



                 return 1;
          }

          if(memcmp(buffer,dwg_header_12,sizeof(dwg_header_12))==0 || memcmp(buffer,dwg_header_13,sizeof(dwg_header_13))==0 ||  memcmp(buffer,dwg_header_14,sizeof(dwg_header_14))==0 ||  memcmp(buffer,dwg_header_15,sizeof(dwg_header_15))==0)
         {



                 return 1;
         }

           if(memcmp(buffer, header_dxf, sizeof(header_dxf))==0 || memcmp(buffer, header_dxf_dos, sizeof(header_dxf_dos))==0 || memcmp(buffer, header_dxflib, sizeof(header_dxflib))==0 ||  memcmp(buffer, header_dxflib_dos, sizeof(header_dxflib_dos))==0)
           {



                 return 1;
           }
            if(memcmp(&buffer[4], edb_magic, sizeof(edb_magic))==0)
           {



                 return 1;
           }
          if(memcmp(buffer,elf_header,sizeof(elf_header))==0)
           {



                 return 1;
           }

          if(memcmp(buffer,emf_header,sizeof(emf_header))==0 &&  memcmp(&buffer[0x28],emf_sign,sizeof(emf_sign))==0)
           {



                 return 1;
           }
          if(memcmp(buffer, fbk_header, sizeof(fbk_header))==0)
           {



                 return 1;
           }

          if(memcmp(buffer,fcp_header,sizeof(fcp_header))==0)
           {



                 return 1;
           }

           if(memcmp(buffer, fcs_signature, sizeof(fcs_signature))==0)
             {



                 return 1;
             }

           if(memcmp(&buffer[5], fdb_header, sizeof(fdb_header))==0)
           {



                 return 1;
           }

         if(memcmp(buffer,fh10_header,sizeof(fh10_header))==0)
           {



                 return 1;
           }
           if(memcmp(buffer,fits_header,sizeof(fits_header))==0)
           {



                 return 1;
           }

          if(memcmp(buffer, flac_header, sizeof(flac_header))==0)
           {



                 return 1;
           }
         if(memcmp(buffer, flp_header, sizeof(flp_header))==0)
           {



                 return 1;
           }
          if(memcmp(buffer, flv_header, sizeof(flv_header))==0 && (buffer[4]==1 || buffer[4]==5))
           {



                 return 1;
           }

          if((memcmp(buffer, magic_codeunit, sizeof(magic_codeunit))==0 ||
               memcmp(buffer, magic_dataport, sizeof(magic_dataport))==0 ||
               memcmp(buffer, magic_form, sizeof(magic_form))==0 ||
               memcmp(buffer, magic_menusuite, sizeof(magic_menusuite))==0 ||
               memcmp(buffer, magic_report, sizeof(magic_report))==0 ||
               memcmp(buffer, magic_table, sizeof(magic_table))==0 ||
               memcmp(buffer, magic_xmlport, sizeof(magic_xmlport))==0))
            {



                 return 1;
            }

          if(memcmp(buffer,fp7_header,sizeof(fp7_header))==0)
           {



                 return 1;
           }
           if(memcmp(buffer,frm_header,sizeof(frm_header))==0)
           {



                 return 1;
           }
             if(memcmp(buffer,fs_header,sizeof(fs_header))==0)
           {



                 return 1;
           }

          if((memcmp(buffer, gho_header, sizeof(gho_header))==0) &&  memcmp (buffer+8, gho_header_next, sizeof(gho_header_next))==0)
           {



                 return 1;
           }
          if((memcmp(buffer, gz_header_magic, sizeof(gz_header_magic))==0)  && (buffer[3]&0xe0)==0)
           {



                 return 1;
           }
           if(memcmp(buffer,hds_header,sizeof(hds_header))==0)
           {



                 return 1;
           }

           if(memcmp(buffer,hr9_header,sizeof(hr9_header))==0)
           {



                 return 1;
           }
/*		  if(memcmp(buffer,header_ico,sizeof(header_ico))==0)
          {



                 return 1;
          }
          */
          if(memcmp(buffer, ifo_header_vmg, sizeof(ifo_header_vmg))==0 ||  memcmp(buffer, ifo_header_vts, sizeof(ifo_header_vts))==0)
           {



                 return 1;
           }

          if(memcmp(buffer+1,imb_header,sizeof(imb_header))==0)
           {



                 return 1;
           }

    /*	    if (memcmp(hdr->id,indd_header,sizeof(indd_header))==0)
            {



                return 1;
            }     */
    /*
          if(memcmp (&buffer[0x8000], iso_header, sizeof(iso_header))==0)
          {



                 return 1;
          }
            */
           if(memcmp(buffer, itunes_header, sizeof(itunes_header))==0)
            {



                 return 1;
            }

           if(memcmp(buffer, kdb_header, sizeof(kdb_header))==0)
            {



                 return 1;
            }

         if(buffer[0x00]==0x01 && buffer[0x01]==0x0f && buffer[0x02]==0x00 && buffer[0x03]==0x00 &&
               buffer[0x08]==0x00 && buffer[0x09]==0x00 && buffer[0x0a]==0x00 && buffer[0x0b]==0x00 &&
               buffer[0x0c]==0x00 && buffer[0x0d]==0x00 && buffer[0x0e]==0x00 && buffer[0x0f]==0x00 &&
               buffer[0x10]==0x00 && buffer[0x11]==0x00 && buffer[0x12]==0x00 && buffer[0x13]==0x00 &&
               buffer[0x14]==0x00 && buffer[0x15]==0x00 && buffer[0x16]==0x02 && buffer[0x17]==0x00 &&
               buffer[0x18]==0x63 && buffer[0x19]==0x00 && buffer[0x1A]==0x00 && buffer[0x1B]==0x00)
               {



                 return 1;
               }

          if(memcmp(buffer,lnk_header,sizeof(lnk_header))==0)
            {



                 return 1;
            }

          if(memcmp(buffer,logic_header,sizeof(logic_header))==0)
           {



                 return 1;
           }

           if(buffer[4]==0x47 && buffer[4+192]==0x47 && buffer[4+2*192]==0x47 &&  memcmp(&buffer[0xd7], m2ts_header, sizeof(m2ts_header))==0 &&  memcmp(&buffer[0xe8], m2ts_header, sizeof(m2ts_header))==0)
            {



                 return 1;
            }

           if(buffer[0]==0x47 && buffer[188]==0x47 && buffer[2*188]==0x47 &&  memcmp(&buffer[0x18b], m2t_header, sizeof(m2t_header))==0)
           {



                 return 1;

           }
           if(memcmp(buffer,max_header,sizeof(max_header))==0)
           {




                 return 1;
           }

          if(memcmp(&buffer[8], mb_header, sizeof(mb_header))==0 ||  memcmp(&buffer[8], mb_header2, sizeof(mb_header2))==0)
             {



                 return 1;
             }
             if(memcmp(&buffer[8], mp_header, sizeof(mp_header))==0)
             {



                 return 1;
             }

           if(buffer[0]==0x00 && buffer[1]==0x00 &&   memcmp(buffer+0x0e,mcd_header,sizeof(mcd_header))==0)
            {



                 return 1;
            }

           if(memcmp (buffer, mdb_header, sizeof(mdb_header))==0)
            {



                 return 1;
            }
             else if(memcmp (buffer, accdb_header, sizeof(accdb_header))==0)
            {



                 return 1;
            }
          if(buffer[0x00]==0x01 && buffer[0x01]==0x0f && buffer[0x02]==0x00 && buffer[0x03]==0x00 &&
              buffer[0x08]==0x00 && buffer[0x09]==0x00 && buffer[0x0a]==0x00 && buffer[0x0b]==0x00 &&
              buffer[0x0c]==0x00 && buffer[0x0d]==0x00 && buffer[0x0e]==0x00 && buffer[0x0f]==0x00 &&
              buffer[0x10]==0x00 && buffer[0x11]==0x00 && buffer[0x12]==0x00 && buffer[0x13]==0x00 &&
              buffer[0x14]==0x00 && buffer[0x15]==0x00 && buffer[0x16]==0x01 && buffer[0x17]==0x00 &&
              buffer[0x18]==0x63 && buffer[0x19]==0x00 && buffer[0x1A]==0x00 && buffer[0x1B]==0x00)
              {



                 return 1;
              }

          if(memcmp(buffer,mfa_header,sizeof(mfa_header))==0)
           {



                 return 1;
           }
          if(memcmp(buffer,mfg_header,sizeof(mfg_header))==0)
           {



                 return 1;
           }

          if(memcmp(buffer,mid_header,sizeof(mid_header))==0)
           {



                 return 1;
           }
          if(memcmp(buffer,mk5_header,sizeof(mk5_header))==0 &&  memcmp(buffer+0x1c,mk5_header2,sizeof(mk5_header2))==0)
              {



                 return 1;
              }
/*
          if(memcmp(buffer,mkv_header,sizeof(mkv_header))==0 && memcmp(buffer+24,"matroska",8)==0)
          {



                 return 1;
          }

           if(
             (buffer[i+4]=='c' && buffer[i+5]=='m' && buffer[i+6]=='o' && buffer[i+7]=='v') ||
             (buffer[i+4]=='c' && buffer[i+5]=='m' && buffer[i+6]=='v' && buffer[i+7]=='d') ||
             (buffer[i+4]=='d' && buffer[i+5]=='c' && buffer[i+6]=='o' && buffer[i+7]=='m') ||
             (buffer[i+4]=='f' && buffer[i+5]=='r' && buffer[i+6]=='e' && buffer[i+7]=='e') ||
             (buffer[i+4]=='f' && buffer[i+5]=='t' && buffer[i+6]=='y' && buffer[i+7]=='p') ||
            (buffer[i+4]=='j' && buffer[i+5]=='p' && buffer[i+6]=='2' && buffer[i+7]=='h') ||
             (buffer[i+4]=='m' && buffer[i+5]=='d' && buffer[i+6]=='a' && buffer[i+7]=='t') ||
             (buffer[i+4]=='m' && buffer[i+5]=='d' && buffer[i+6]=='i' && buffer[i+7]=='a') ||
             (buffer[i+4]=='m' && buffer[i+5]=='o' && buffer[i+6]=='o' && buffer[i+7]=='v') ||
             (buffer[i+4]=='P' && buffer[i+5]=='I' && buffer[i+6]=='C' && buffer[i+7]=='T') ||
             (buffer[i+4]=='p' && buffer[i+5]=='n' && buffer[i+6]=='o' && buffer[i+7]=='t') ||
             (buffer[i+4]=='s' && buffer[i+5]=='k' && buffer[i+6]=='i' && buffer[i+7]=='p') ||
             (buffer[i+4]=='s' && buffer[i+5]=='t' && buffer[i+6]=='b' && buffer[i+7]=='l') ||
             (buffer[i+4]=='t' && buffer[i+5]=='r' && buffer[i+6]=='a' && buffer[i+7]=='k') ||
             (buffer[i+4]=='u' && buffer[i+5]=='u' && buffer[i+6]=='i' && buffer[i+7]=='d') ||
             (buffer[i+4]=='w' && buffer[i+5]=='i' && buffer[i+6]=='d' && buffer[i+7]=='e')  )
           {



                 return 1;
           }
*/
           if(buffer[0]==0x00 && buffer[1]==0x00 && buffer[2]==0x01 &&   (buffer[3]==0xB0 || (buffer[3]==0xB3 && ((buffer[4]<<8)+(buffer[5]>>8)>0) && ((buffer[5]<<8)+buffer[6]>0)) ||  buffer[3]==0xB5 ||   buffer[3]==0xBA || (buffer[3]==0xBB && (buffer[4]<<8)+(buffer[5]>>8)>0 && (buffer[6]&0x80)==0x80)))
            {



                 return 1;
            }
          if(memcmp(buffer,mrw_header,sizeof(mrw_header))==0)
           {



                 return 1;
           }
         if(memcmp(buffer,mus_header,sizeof(mus_header))==0)
           {



                 return 1;
           }

           if(memcmp(buffer,mxf_header,sizeof(mxf_header))==0)
           {



                 return 1;
           }
           if(buffer[0]==0xfe && buffer[1]==0xfe && buffer[2]==0x07 && buffer[3]==0x01)
           {



                 return 1;
           }
          /* MySQL table definition file Version 7 up to 10 */
           if(buffer[0]==0xfe && buffer[1]==0x01 && (buffer[2]>=0x07 && buffer[2]<=0x0A) && buffer[3]==0x09)
          {



                 return 1;
          }
            if(buffer[0]==0x04 && buffer[1]=='N' && buffer[2]=='j' && buffer[3]==0x0f &&  buffer[6]=='N' && buffer[7]=='J' && buffer[8]=='S' && buffer[9]=='t' && buffer[10]=='a' && buffer[11]=='r')
            {



                 return 1;
            }
             if(memcmp(buffer, nk2_header, sizeof(nk2_header))==0)
             {



                 return 1;
             }

           if(memcmp(buffer,ogg_header,sizeof(ogg_header))==0)
             {



                 return 1;
             }
          if(memcmp(buffer,one_header,sizeof(one_header))==0)
            {



                 return 1;
            }
             if(memcmp(buffer, orf_header, sizeof(orf_header))==0 || memcmp(buffer, orf_header2, sizeof(orf_header2))==0)
              {



                 return 1;
              }

           if(memcmp(buffer,paf_header,sizeof(paf_header))==0)
             {



                 return 1;
             }

             if(memcmp(buffer,pap_header,sizeof(pap_header))==0)
             {



                 return 1;
             }

           if(memcmp(buffer, pcap_header, sizeof(pcap_header))==0)
             {



                 return 1;
             }
          if(memcmp(buffer,pdf_header,sizeof(pdf_header))==0)
             {



                 return 1;
             }
          if(memcmp(buffer,pfx_header,sizeof(pfx_header))==0)
             {



                 return 1;
             }
          if(memcmp(&buffer[0x30],prc_header,sizeof(prc_header))==0)
             {



                 return 1;
             }
           if(memcmp(buffer,prt_header,sizeof(prt_header))==0)
             {



                 return 1;
             }

          if(memcmp(buffer,ps_header,sizeof(ps_header))==0)
             {



                 return 1;
             }

          if(memcmp(buffer,psd_header,sizeof(psd_header))==0)
          {



                 return 1;
          }
          if(memcmp(buffer, psp_header, sizeof(psp_header)-1)==0)
              {



                 return 1;
              }
         if(memcmp(buffer,wab_header,sizeof(wab_header))==0)
             {



                 return 1;
             }
               if(memcmp(buffer,dbx_header,sizeof(dbx_header))==0)
               {



                 return 1;
               }
                 if(memcmp(buffer,pst_header,sizeof(pst_header))==0)
                 {



                 return 1;
                 }

           if(memcmp(buffer,ptb_header,sizeof(ptb_header))==0)
             {



                 return 1;
             }
           if(memcmp(buffer,pyc_15_magic,sizeof(pyc_15_magic))==0 || (memcmp(buffer,pyc_20_magic,sizeof(pyc_20_magic))==0 ) ||  (memcmp(buffer,pyc_21_magic,sizeof(pyc_21_magic))==0 ) ||  (memcmp(buffer,pyc_22_magic,sizeof(pyc_22_magic))==0 ) || (memcmp(buffer,pyc_23_magic,sizeof(pyc_23_magic))==0 ) || (memcmp(buffer,pyc_24_magic,sizeof(pyc_24_magic))==0 ) || (memcmp(buffer,pyc_25_magic,sizeof(pyc_25_magic))==0 ))
             {



                 return 1;
             }

   /*		    if(memcmp(buffer, qbb_header, sizeof(qbb_header))==0)
              {



                 return 1;
              }   */
            if(buffer[4]==0x56 && buffer[5]==0x00 && buffer[6]==0x00 && buffer[7]==0x00 && buffer[0x60]=='M' && buffer[0x61]=='A' && buffer[0x62]=='U' && buffer[0x63]=='I')
            {



                 return 1;
            }
          if(memcmp(buffer,qdf_header,sizeof(qdf_header))==0)
              {



                 return 1;
              }

           if(memcmp(buffer,qxd_header,sizeof(qxd_header))==0)
             {



                 return 1;
             }
              if(memcmp(buffer+2,qxp_header_be,sizeof(qxp_header_be))==0 ||  memcmp(buffer+2,qxp_header_le,sizeof(qxp_header_le))==0)
             {



                 return 1;

             }

             if(memcmp(buffer,ra_header,sizeof(ra_header))==0)
             {



                 return 1;
             }

              if(memcmp(buffer, raf_header, sizeof(raf_header))==0)
             {



                 return 1;
             }

               if(memcmp (buffer+25, raw_header_contax, 7)==0)
             {



                 return 1;
             }
               if(memcmp(buffer, raw_header_panasonic, sizeof(raw_header_panasonic))==0)
               {



                 return 1;
               }

              if(memcmp(buffer, rdc_header, sizeof(rdc_header))==0)
              {



                 return 1;
              }
      if(memcmp(buffer,reg_header_9x,sizeof(reg_header_9x))==0 ||  memcmp(buffer,reg_header_nt,sizeof(reg_header_nt))==0)
      {




          return 1;

      }
    /*      if(memcmp(buffer,MS_res_header,sizeof(MS_res_header))==0)
             {



                 return 1;
             }
            */
            if(memcmp(buffer,riff_header,sizeof(riff_header))==0)
             {



                 return 1;
            }
              if(memcmp(buffer,rm_header,sizeof(rm_header))==0)
              {



                 return 1;
              }

               if(memcmp(buffer,rns_header,sizeof(rns_header)-1)==0)
              {



                 return 1;
              }

              if(memcmp(buffer, rpm_header, sizeof(rpm_header))==0)
             {



                 return 1;
             }
               if(memcmp(buffer, ses_magic, sizeof(ses_magic))==0)
             {



                 return 1;
             }

             if(memcmp(buffer, sib_header, sizeof(sib_header))==0)
             {



                 return 1;
             }

              if(memcmp(buffer,sit_header,sizeof(sit_header))==0)
             {



                 return 1;
             }
             if(memcmp(buffer,skd_header,sizeof(skd_header))==0)
               {



                 return 1;
               }
              if(memcmp(buffer,skp_header, sizeof(skp_header))==0)
             {



                 return 1;
             }
      /*        if(memcmp(buffer, sp31_header, sizeof(sp31_header))==0 ||	memcmp(buffer, sp32_header, sizeof(sp32_header))==0)
            {



                 return 1;
            }*/
             if(memcmp(buffer,spf_header,sizeof(spf_header))==0)
             {



                 return 1;
             }
              if(memcmp(buffer,spss_header,sizeof(spss_header))==0)
                  {



                 return 1;
                  }
                 if(memcmp(buffer,sqlite_header,sizeof(sqlite_header))==0)
                {



                 return 1;
                }
               if(memcmp(buffer, sqm_header, sizeof(sqm_header))==0)
             {



                 return 1;
             }
              if(memcmp(buffer, stl_header, sizeof(stl_header))==0 &&    memcmp(buffer+0x40, spaces, sizeof(spaces))==0)
             {



                 return 1;
             }
              if(memcmp(buffer,stuffit_header,sizeof(stuffit_header))==0)
             {



                 return 1;
             }
           if(memcmp(buffer, swf_header_compressed, sizeof(swf_header_compressed))==0)
          {



                 return 1;
          }
         if(memcmp(buffer, swf_header, sizeof(swf_header))==0)
         {



                 return 1;
         }

            if(memcmp(&buffer[0x101],tar_header_gnu,sizeof(tar_header_gnu))==0 ||    memcmp(&buffer[0x101],tar_header_posix,sizeof(tar_header_posix))==0)
              {



                 return 1;
              }

              if(memcmp(buffer, tax_header, sizeof(tax_header))==0)
             {



                 return 1;
             }
              if(memcmp(buffer,tib_header, sizeof(tib_header))==0)
             {



                 return 1;
             }
           if(memcmp(buffer,tiff_header_be,sizeof(tiff_header_be))==0 ||   memcmp(buffer,tiff_header_le,sizeof(tiff_header_le))==0)
           {



                 return 1;
           }
             if(memcmp(buffer,tph_header,sizeof(tph_header))==0)
               {



                 return 1;
               }

        /*       if(memcmp(buffer, header_ttf, sizeof(header_ttf))==0)
              {



                 return 1;
              }
             */
              if(memcmp(buffer,header_cls,sizeof(header_cls))==0)
             {



                 return 1;
             }
              if(memcmp(buffer,header_adr,sizeof(header_adr)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_imm,sizeof(header_imm))==0 ||   memcmp(buffer,header_ReturnPath,sizeof(header_ReturnPath))==0 ||   memcmp(buffer,header_mail,sizeof(header_mail))==0)
             {



                 return 1;
             }
            if(memcmp(buffer,header_perlm,sizeof(header_perlm)-1)==0 && (buffer[sizeof(header_perlm)]==' ' || buffer[sizeof(header_perlm)]=='\t'))
             {



                 return 1;
             }
             if(memcmp(buffer,header_rpp,sizeof(header_rpp))==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_rtf,sizeof(header_rtf))==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_reg,sizeof(header_reg)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_sh,sizeof(header_sh)-1)==0 ||   memcmp(buffer,header_bash,sizeof(header_bash)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_slk,sizeof(header_slk)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer, header_stl, sizeof(header_stl)-1)==0 &&   memcmp(buffer+0x40, spaces, sizeof(spaces))!=0)
             {



                 return 1;
             }
             if(memcmp(buffer, header_ers, sizeof(header_ers)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_stp,sizeof(header_stp)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_wpl,sizeof(header_wpl))==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_ram,sizeof(header_ram)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_xml,sizeof(header_xml)-1)==0)
             {



                 return 1;
             }
             if(buffer[0]=='0' && buffer[1]=='0' && memcmp(&buffer[4],header_dc,sizeof(header_dc)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_dif,sizeof(header_dif))==0)
             {



                 return 1;
             }
             if(memcmp(buffer, header_ics, sizeof(header_ics)-1)==0)
             {



                 return 1;
             }

             if(memcmp(buffer, header_lyx, sizeof(header_lyx))==0)
             {



                 return 1;
             }

             if(memcmp(buffer, header_m3u, sizeof(header_m3u))==0)
             {



                 return 1;
             }

             if(memcmp(buffer, header_msf, sizeof(header_msf)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer, header_cue, sizeof(header_cue)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_bat,sizeof(header_bat)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_asp,sizeof(header_asp)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_vcf,sizeof(header_vcf)-1)==0)
             {



                 return 1;
             }
              if(memcmp(buffer,header_sig_python,sizeof(header_sig_python)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,header_sig_perl,sizeof(header_sig_perl)-1)==0)
             {



                 return 1;
             }
              if(memcmp(buffer,header_sig_ruby,sizeof(header_sig_ruby)-1)==0)
             {



                 return 1;
             }
              if(memcmp(buffer,sign_c,sizeof(sign_c)-1)==0)
             {



                 return 1;
             }
              if(memcmp(buffer,sign_h,sizeof(sign_h)-1)==0)
             {



                 return 1;
             }
             if(memcmp(buffer,sign_jsp,sizeof(sign_jsp)-1)==0 || memcmp(buffer,sign_jsp2,sizeof(sign_jsp2)-1)==0)
             {



                 return 1;
             }
              if(memcmp(buffer,sign_php,sizeof(sign_php)-1)==0)
             {



                 return 1;
             }
            if(memcmp(buffer,sign_tex,sizeof(sign_tex)-1)==0)
             {



                 return 1;
             }
              if(memcmp(buffer,sign_html,sizeof(sign_html)-1)==0)
             {



                 return 1;
             }

             if(memcmp(buffer,tz_header,sizeof(tz_header))==0 ||  memcmp(buffer,tz2_header,sizeof(tz2_header))==0)
            {



                 return 1;
            }

             if(memcmp(buffer,veg_header,sizeof(veg_header))==0)
             {



                 return 1;
              }

               if(memcmp(buffer,vmdk_header3, sizeof(vmdk_header3))==0 ||   memcmp(buffer,vmdk_header4, sizeof(vmdk_header4))==0)
             {



                 return 1;
             }

              if(memcmp(buffer,wks_header,sizeof(wks_header))==0)
              {



                 return 1;
              }
               if(memcmp(buffer,wk4_header,sizeof(wk4_header))==0)
              {



                 return 1;
              }
               if(memcmp(buffer,apm_header,sizeof(apm_header))==0 ||  memcmp(buffer,emff_header,sizeof(emf_header))==0 ||  memcmp(buffer,wmf_header,sizeof(wmf_header))==0)
             {



                 return 1;
             }

              if(memcmp(buffer, wnk_header, sizeof(wnk_header))==0)
             {



                 return 1;
             }
             if(memcmp(buffer, wpd_header, sizeof(wpd_header))==0)
             {



                 return 1;
             }
              if(memcmp(buffer,x3f_header,sizeof(x3f_header))==0)
               {



                 return 1;
               }
               if(memcmp(buffer,xcf_header_v0, sizeof(xcf_header_v0))==0 ||   memcmp(buffer,xcf_header_v1, sizeof(xcf_header_v1))==0)
                {



                 return 1;

                }
              if(memcmp(buffer,xm_header,sizeof(xm_header))==0)
              {



                 return 1;
              }
          if(memcmp(buffer, xpt_header, sizeof(xpt_header))==0)
              {



                 return 1;
              }
           if(memcmp(buffer + 20, xsv_header, sizeof(xsv_header))==0)
              {



                 return 1;
              }

           if(memcmp(buffer,xv_header,sizeof(xv_header))==0)
              {



                 return 1;
              }


           return 0;
 }


#endif // ALLCHACK_H
