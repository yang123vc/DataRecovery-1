#ifndef HEADERFUNCATION_H
#define HEADERFUNCATION_H

#include "globlevariable.h"
#include "mainwindow.h"
#include "headerfuncation.h"


#include "dataheader.h"
#include "allchack.h"

void WriteDetails(MainWindow* w1)
{
    w1->Write_Percent();
}

void InsertItem(MainWindow* w1,unsigned long long *File_Size1,unsigned long long *File_Start_Sector1,unsigned long long *File_End_Sector1,bool Status1)
{
    File_Size = *File_Size1;
    File_Start_Sector = *File_Start_Sector1;
    File_End_Sector = *File_End_Sector1;
    Status = Status1;

    w1->Add_Recover_Items();

}

void bmp_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
   {
         if(buffer[0]=='B' && buffer[1]=='M' && buffer[6]==0x00 && buffer[7]==0x00 && buffer[8]==0x00 && buffer[9]==0x00)
         {

                   unsigned long long BmpSize =((buffer[2] & 0xff)<<0)+((buffer[3] & 0xff)<<8)+((buffer[4] & 0xff)<<16)+((buffer[5] & 0xff)<<24);
                   ext = ".bmp";

                    unsigned long long startf, file_size = 0;
                    unsigned long dwRead;
                    startf = *Start_Scan_Sector_From ;

                   while(file_size>=0)
                  {
                         *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;
                          file_size+=512;

                       SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                       ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                        if(file_size>=BmpSize)
                       {
                           InsertItem(w1,&BmpSize,&startf,&(*Start_Scan_Sector_From),FALSE);

                            break;
                       }
                         int j = allcheck(buffer);
                                   if(j==1)
                                   {
                                       *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                         InsertItem(w1,&BmpSize,&startf,&(*Start_Scan_Sector_From),TRUE);
                                       break;
                                   }

                 }
          }
   }
void png_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,png_header,sizeof(png_header))==0)
      {
         ext = ".png";

         unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


             if(file_size>=5000000)
            {
                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                   break;
            }
           int i;
             for(i=0;i<sizeof(buffer);i++)
             {
               if(memcmp(buffer+i,png_footer,sizeof(png_footer))==0)
                {
                     InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                     break ;
                }
             }

              int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

      }
}
}

void doc_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,doc_header,sizeof(doc_header))==0)
     {

          ext = ".doc";

         unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


             if(file_size>=5000000)
            {
                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                   break;
            }
             int i;
             for(i=0;i<sizeof(buffer);i++)
             {
                 if(memcmp(buffer+i,doc_footer,sizeof(doc_footer))==0)
                  {
                     ext = ".doc";

                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                      break ;
                  }
                    if(memcmp(buffer+i,ppt_footer,sizeof(ppt_footer))==0)
                  {
                        ext = ".ppt";

                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                      break ;
                  }
                   if(memcmp(buffer+i,xls_footer,sizeof(xls_footer))==0)
                  {
                       ext = ".xls";
                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                      break ;
                  }

             }
              int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

      }


     }
}
void pst_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer,wab_header,sizeof(wab_header))==0)
          {
              ext = ".wab";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
            }
            if(memcmp(buffer,dbx_header,sizeof(dbx_header))==0)
            {
                ext = ".dbx";
                 unsigned long long startf, file_size = 0;
                  unsigned long dwRead;
                startf = *Start_Scan_Sector_From ;

               while(file_size>=0)
              {

                    *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                   file_size+=512;

                   SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                   ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                    int j = allcheck(buffer);
                               if(j==1)
                               {
                                   *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                     InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                     break;
                               }

                }
            }
              if(memcmp(buffer,pst_header,sizeof(pst_header))==0)
              {
                  ext = ".pst";
                   unsigned long long startf, file_size = 0;
                    unsigned long dwRead;
                  startf = *Start_Scan_Sector_From ;

                 while(file_size>=0)
                {

                      *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                     file_size+=512;

                     SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                     ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                      int j = allcheck(buffer);
                                 if(j==1)
                                 {
                                     *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                       break;
                                 }

                  }
              }
}
void chm_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
       if(memcmp(buffer, chm_header, sizeof(chm_header))==0)
       {
               unsigned long long siz =(buffer[104]<<0)+(buffer[105]<<8)+(buffer[106]<<16)+(buffer[107]<<24);

               ext = ".chm";

                unsigned long long startf, file_size = 0;
                unsigned long dwRead;
                startf = *Start_Scan_Sector_From ;

               while(file_size>=0)
              {
                     *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;
                      file_size+=512;

                   SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                   ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                    if(file_size>=siz)
                   {
                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);

                        break;
                   }
                     int j = allcheck(buffer);
                               if(j==1)
                               {
                                   *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                     InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                                   break;
                               }

             }

       }
}
void pdf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
           if(memcmp(buffer,pdf_header,sizeof(pdf_header))==0)
           {

               ext = ".pdf";

               unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                   if(file_size>=100000000)
                  {
                         InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                         break;
                  }
                   int i;
                   for(i=0;i<sizeof(buffer);i++)
                   {
                      if(memcmp(buffer+i,pdf_footer,sizeof(pdf_footer))==0)
                      {

                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                        break ;
                      }
                   }
                    int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

            }

            }
}
void one_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
         if(memcmp(buffer,one_header,sizeof(one_header))==0)
         {
             ext = ".one";
              unsigned long long startf, file_size = 0;
               unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {

                 *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                 int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                  break;
                            }

             }
         }
}
void wpd_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer, wpd_header, sizeof(wpd_header))==0)
          {
                 unsigned long long  siz=(unsigned long long)buffer[20]+(((unsigned long long)buffer[21])<<8)+(((unsigned long long)buffer[22])<<16)+(((unsigned long long)buffer[23])<<24);
                 ext = ".wpd";

                  unsigned long long startf, file_size = 0;
                  unsigned long dwRead;
                  startf = *Start_Scan_Sector_From ;

                 while(file_size>=0)
                {
                       *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;
                        file_size+=512;

                     SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                     ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                      if(file_size>=siz)
                     {
                         InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);

                          break;
                     }
                       int j = allcheck(buffer);
                                 if(j==1)
                                 {
                                     *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                                     break;
                                 }

               }
          }
}
void fbk_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer, fbk_header, sizeof(fbk_header))==0)
        {
            ext = ".fbk";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void njx_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(buffer[0]==0x04 && buffer[1]=='N' && buffer[2]=='j' && buffer[3]==0x0f &&  buffer[6]=='N' && buffer[7]=='J' && buffer[8]=='S' && buffer[9]=='t' && buffer[10]=='a' && buffer[11]=='r')
         {

              ext = ".njx";

              unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                  int i;
                  for(i=0;i<sizeof(buffer);i++)
                  {
                    if(memcmp(buffer+i,njx_footer,sizeof(njx_footer))==0)
                     {

                          InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                       break ;
                     }
                  }
                   int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

           }
         }
}
void text_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer,header_cls,sizeof(header_cls))==0)
          {
              ext = ".cls";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
           if(memcmp(buffer,header_adr,sizeof(header_adr)-1)==0)
          {
               ext = ".adr";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
          }
          if(memcmp(buffer,header_imm,sizeof(header_imm))==0 ||   memcmp(buffer,header_ReturnPath,sizeof(header_ReturnPath))==0 ||   memcmp(buffer,header_mail,sizeof(header_mail))==0)
          {
              ext = ".imm";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
         if(memcmp(buffer,header_perlm,sizeof(header_perlm)-1)==0 && (buffer[sizeof(header_perlm)]==' ' || buffer[sizeof(header_perlm)]=='\t'))
          {
             ext = ".pl";
              unsigned long long startf, file_size = 0;
               unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {

                 *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                 int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                  break;
                            }

             }
          }
          if(memcmp(buffer,header_rpp,sizeof(header_rpp))==0)
          {
              ext = ".rpp";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_rtf,sizeof(header_rtf))==0)
          {
              ext = ".rtf";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_reg,sizeof(header_reg)-1)==0)
          {
              ext = ".reg";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_sh,sizeof(header_sh)-1)==0 ||   memcmp(buffer,header_bash,sizeof(header_bash)-1)==0)
          {
              ext = ".sh";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_slk,sizeof(header_slk)-1)==0)
          {
              ext = ".slk";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer, header_stl, sizeof(header_stl)-1)==0 &&   memcmp(buffer+0x40, spaces, sizeof(spaces))!=0)
          {
              ext = ".stl";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer, header_ers, sizeof(header_ers)-1)==0)
          {
              ext = ".ers";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_stp,sizeof(header_stp)-1)==0)
          {
              ext = ".stp";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_wpl,sizeof(header_wpl))==0)
          {
              ext = ".wpl";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_ram,sizeof(header_ram)-1)==0)
          {
              ext = ".ram";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_xml,sizeof(header_xml)-1)==0)
          {
              ext = ".xml";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(buffer[0]=='0' && buffer[1]=='0' && memcmp(&buffer[4],header_dc,sizeof(header_dc)-1)==0)
          {
              ext = ".dc";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_dif,sizeof(header_dif))==0)
          {
              ext = ".dif";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer, header_ics, sizeof(header_ics)-1)==0)
          {
              ext = ".ics";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }

          if(memcmp(buffer, header_lyx, sizeof(header_lyx))==0)
          {
              ext = ".lyx";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }

          if(memcmp(buffer, header_m3u, sizeof(header_m3u))==0)
          {
              ext = ".m3u";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }

          if(memcmp(buffer, header_msf, sizeof(header_msf)-1)==0)
          {
              ext = ".msf";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer, header_cue, sizeof(header_cue)-1)==0)
          {
              ext = ".cue";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_bat,sizeof(header_bat)-1)==0)
          {
              ext = ".bat";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_asp,sizeof(header_asp)-1)==0)
          {
              ext = ".asp";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
          if(memcmp(buffer,header_vcf,sizeof(header_vcf)-1)==0)
          {
              ext = ".vcf";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
           if(memcmp(buffer,header_sig_python,sizeof(header_sig_python)-1)==0)
          {
               ext = ".py";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
          }
          if(memcmp(buffer,header_sig_perl,sizeof(header_sig_perl)-1)==0)
          {
              ext = ".pl";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }


          }
           if(memcmp(buffer,header_sig_ruby,sizeof(header_sig_ruby)-1)==0)
          {

               ext = ".rb";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
          }
           if(memcmp(buffer,sign_c,sizeof(sign_c)-1)==0)
          {
               ext = ".c";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
          }
           if(memcmp(buffer,sign_h,sizeof(sign_h)-1)==0)
          {
               ext = ".h";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
          }
          if(memcmp(buffer,sign_jsp,sizeof(sign_jsp)-1)==0 || memcmp(buffer,sign_jsp2,sizeof(sign_jsp2)-1)==0)
          {
              ext = ".jsp";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
           if(memcmp(buffer,sign_php,sizeof(sign_php)-1)==0)
          {
               ext = ".php";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
          }
         if(memcmp(buffer,sign_tex,sizeof(sign_tex)-1)==0)
          {
             ext = ".tex";
              unsigned long long startf, file_size = 0;
               unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {

                 *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                 int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                  break;
                            }

             }
          }
           if(memcmp(buffer,sign_html,sizeof(sign_html)-1)==0)
          {
               ext = ".html";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
          }

}
void nk2_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer, nk2_header, sizeof(nk2_header))==0)
          {
              ext = ".nk2";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
}
void ps_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer,ps_header,sizeof(ps_header))==0)
          {

              ext = ".ps";

              unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                  int i;
                  for(i=0;i<sizeof(buffer);i++)
                  {
                      if(buffer[i]=='%' && buffer[i+1]=='%' && buffer[i+2]=='E' && buffer[i+3]=='O' && buffer[i+4]=='F')
                     {

                          InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                       break ;
                     }
                  }
                   int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

           }
          }
}


void z7_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)  //7z
{
   if(memcmp(buffer,header_7z,sizeof(header_7z))==0)
   {
       ext = ".7z";
        unsigned long long startf, file_size = 0;
         unsigned long dwRead;
       startf = *Start_Scan_Sector_From ;

      while(file_size>=0)
     {

           *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

          file_size+=512;

          SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
          ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

           int j = allcheck(buffer);
                      if(j==1)
                      {
                          *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                            InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                            break;
                      }

       }
   }
}
void tar_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
           if(memcmp(&buffer[0x101],tar_header_gnu,sizeof(tar_header_gnu))==0 ||    memcmp(&buffer[0x101],tar_header_posix,sizeof(tar_header_posix))==0)
           {
               ext = ".tar";
                unsigned long long startf, file_size = 0;
                 unsigned long dwRead;
               startf = *Start_Scan_Sector_From ;

              while(file_size>=0)
             {

                   *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                  file_size+=512;

                  SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                  ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                   int j = allcheck(buffer);
                              if(j==1)
                              {
                                  *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                    break;
                              }

               }
           }
}
void bz2_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
      if(buffer[0]=='B' && buffer[1]=='Z' && buffer[2]=='h' && buffer[3]>='0' && buffer[4]=='1' && buffer[5]=='A' && buffer[6]=='Y' && buffer[7]=='&' && buffer[8]=='S' && buffer[9]=='Y')
      {
          ext = ".bz2";
           unsigned long long startf, file_size = 0;
            unsigned long dwRead;
          startf = *Start_Scan_Sector_From ;

         while(file_size>=0)
        {

              *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

             file_size+=512;

             SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
             ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

              int j = allcheck(buffer);
                         if(j==1)
                         {
                             *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                               InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                               break;
                         }

          }
      }
}
void rar_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
      if(memcmp(buffer,rar_header,sizeof(rar_header))==0)
      {

          ext = ".rar";

            unsigned long long startf, file_size = 0;
            unsigned long dwRead;
          startf = *Start_Scan_Sector_From ;

         while(file_size>=0)
        {

              *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

             file_size+=512;

             SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
             ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


              if(file_size>=5000000)
             {
                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                    break;
             }
              int i;
              for(i=0;i<sizeof(buffer);i++)
              {
                  if(memcmp(buffer+i,rar_footer,sizeof(rar_footer))==0)
                 {

                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                   break ;
                 }
              }
               int j = allcheck(buffer);
                         if(j==1)
                         {
                             *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                               InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                               break;
                         }

       }
      }
}
void zip_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer,zip_header2,sizeof(zip_header2))==0 || memcmp(buffer,zip_header,sizeof(zip_header))==0)
        {
            ext = ".zip";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
         }
}
void cab_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,cab_header,sizeof(cab_header))==0)
     {
         ext = ".cab";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}
void a_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,a_header,sizeof(a_header))==0)
     {
         ext = ".a";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}
void arj_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer, arj_header, sizeof(arj_header))==0)
     {

         ext = ".arj";

         unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


             if(file_size>=5000000)
            {
                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                   break;
            }
             int i;
             for(i=0;i<sizeof(buffer);i++)
             {
               if(memcmp(buffer+i,arj_footer,sizeof(arj_footer))==0)
                {

                     InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                  break ;
                }
             }
              int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

      }
     }
}

void MYI_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        /* MySQL MYISAM compressed data file Version 1 */
        if(buffer[0]==0xfe && buffer[1]==0xfe && buffer[2]==0x07 && buffer[3]==0x01)
        {
            ext = ".myi";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
       /* MySQL table definition file Version 7 up to 10 */
        if(buffer[0]==0xfe && buffer[1]==0x01 && (buffer[2]>=0x07 && buffer[2]<=0x0A) && buffer[3]==0x09)
       {
            ext = ".myi";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
       }
}

void mdb_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
         if(memcmp (buffer, mdb_header, sizeof(mdb_header))==0)
         {
             ext = ".mdb";
              unsigned long long startf, file_size = 0;
               unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {

                 *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                 int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                  break;
                            }

             }
         }
          else if(memcmp (buffer, accdb_header, sizeof(accdb_header))==0)
         {
             ext = ".accdb";
              unsigned long long startf, file_size = 0;
               unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {

                 *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                 int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                  break;
                            }

             }
         }

}
void mdf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(buffer[0x00]==0x01 && buffer[0x01]==0x0f && buffer[0x02]==0x00 && buffer[0x03]==0x00 &&
           buffer[0x08]==0x00 && buffer[0x09]==0x00 && buffer[0x0a]==0x00 && buffer[0x0b]==0x00 &&
           buffer[0x0c]==0x00 && buffer[0x0d]==0x00 && buffer[0x0e]==0x00 && buffer[0x0f]==0x00 &&
           buffer[0x10]==0x00 && buffer[0x11]==0x00 && buffer[0x12]==0x00 && buffer[0x13]==0x00 &&
           buffer[0x14]==0x00 && buffer[0x15]==0x00 && buffer[0x16]==0x01 && buffer[0x17]==0x00 &&
           buffer[0x18]==0x63 && buffer[0x19]==0x00 && buffer[0x1A]==0x00 && buffer[0x1B]==0x00)
           {
            ext = ".mdf";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
           }
}
void abcdp_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer, abcdp_header, sizeof(abcdp_header))==0 && buffer[9]==0x01)
     {
         ext = ".abcdb";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}
void DB_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
      if(memcmp(buffer,DB_header,sizeof(DB_header))==0)
      {
          ext = ".DB";
           unsigned long long startf, file_size = 0;
            unsigned long dwRead;
          startf = *Start_Scan_Sector_From ;

         while(file_size>=0)
        {

              *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

             file_size+=512;

             SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
             ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

              int j = allcheck(buffer);
                         if(j==1)
                         {
                             *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                               InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                               break;
                         }

          }
      }
}
void dbf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(buffer[0]==0x3 && (buffer[1]>80 || buffer[1]<20) && (buffer[2]>=1 && buffer[2]<=12) && (buffer[3]>=1 && buffer[3]<=31))
     {
         ext = ".dbf";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}
void fp7_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer,fp7_header,sizeof(fp7_header))==0)
        {
            ext = ".fp7";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void idf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(buffer[0x00]==0x01 && buffer[0x01]==0x0f && buffer[0x02]==0x00 && buffer[0x03]==0x00 &&
            buffer[0x08]==0x00 && buffer[0x09]==0x00 && buffer[0x0a]==0x00 && buffer[0x0b]==0x00 &&
            buffer[0x0c]==0x00 && buffer[0x0d]==0x00 && buffer[0x0e]==0x00 && buffer[0x0f]==0x00 &&
            buffer[0x10]==0x00 && buffer[0x11]==0x00 && buffer[0x12]==0x00 && buffer[0x13]==0x00 &&
            buffer[0x14]==0x00 && buffer[0x15]==0x00 && buffer[0x16]==0x02 && buffer[0x17]==0x00 &&
            buffer[0x18]==0x63 && buffer[0x19]==0x00 && buffer[0x1A]==0x00 && buffer[0x1B]==0x00)
            {
            ext = ".ldf";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
            }
}

void edb_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(&buffer[4], edb_magic, sizeof(edb_magic))==0)
        {
            ext = ".edb";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void sqlite_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
             if(memcmp(buffer,sqlite_header,sizeof(sqlite_header))==0)
             {
                 ext = ".sqlite";
                  unsigned long long startf, file_size = 0;
                   unsigned long dwRead;
                 startf = *Start_Scan_Sector_From ;

                while(file_size>=0)
               {

                     *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                    file_size+=512;

                    SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                    ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                     int j = allcheck(buffer);
                                if(j==1)
                                {
                                    *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                      break;
                                }

                 }
             }
}


void asf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,asf_header,sizeof(asf_header))==0)
     {
         ext = ".asf";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}
void riff_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer,riff_header,sizeof(riff_header))==0)
          {
                  if(memcmp(&buffer[8],"AVI ",4)==0)
                 {
                      ext = ".avi";
                       unsigned long long startf, file_size = 0;
                        unsigned long dwRead;
                      startf = *Start_Scan_Sector_From ;

                     while(file_size>=0)
                    {

                          *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                         file_size+=512;

                         SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                         ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                          int j = allcheck(buffer);
                                     if(j==1)
                                     {
                                         *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                           break;
                                     }

                      }
                 }
                 else if(memcmp(&buffer[8],"CDDA",4)==0)
                 {

                      ext = ".cdda";
                       unsigned long long startf, file_size = 0;
                        unsigned long dwRead;
                      startf = *Start_Scan_Sector_From ;

                     while(file_size>=0)
                    {

                          *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                         file_size+=512;

                         SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                         ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                          int j = allcheck(buffer);
                                     if(j==1)
                                     {
                                         *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                           break;
                                     }

                      }
                 }
                else if(memcmp(&buffer[8],"CDR",3)==0)
                {
                      ext = ".cdr";
                       unsigned long long startf, file_size = 0;
                        unsigned long dwRead;
                      startf = *Start_Scan_Sector_From ;

                     while(file_size>=0)
                    {

                          *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                         file_size+=512;

                         SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                         ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                          int j = allcheck(buffer);
                                     if(j==1)
                                     {
                                         *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                           break;
                                     }

                      }
                }
                else if(memcmp(&buffer[8],"NUND",4)==0)
                {
                      ext = ".avi";
                       unsigned long long startf, file_size = 0;
                        unsigned long dwRead;
                      startf = *Start_Scan_Sector_From ;

                     while(file_size>=0)
                    {

                          *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                         file_size+=512;

                         SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                         ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                          int j = allcheck(buffer);
                                     if(j==1)
                                     {
                                         *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                           break;
                                     }

                      }
                }
               else if(memcmp(&buffer[8],"RMP3",4)==0 || memcmp(&buffer[8],"WAVE",4)==0)
               {
                      ext = ".wav";
                       unsigned long long startf, file_size = 0;
                        unsigned long dwRead;
                      startf = *Start_Scan_Sector_From ;

                     while(file_size>=0)
                    {

                          *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                         file_size+=512;

                         SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                         ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                          int j = allcheck(buffer);
                                     if(j==1)
                                     {
                                         *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                           break;
                                     }

                      }

               }
                 else
                 {
                      ext = ".avi";
                       unsigned long long startf, file_size = 0;
                        unsigned long dwRead;
                      startf = *Start_Scan_Sector_From ;

                     while(file_size>=0)
                    {

                          *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                         file_size+=512;

                         SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                         ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                          int j = allcheck(buffer);
                                     if(j==1)
                                     {
                                         *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                           break;
                                     }

                      }

                 }

            }
}
void mp4_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
    int i =0;
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
      (buffer[i+4]=='w' && buffer[i+5]=='i' && buffer[i+6]=='d' && buffer[i+7]=='e')
     )
   {
         ext = ".mp4";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
   }
}
void mpg_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(buffer[0]==0x00 && buffer[1]==0x00 && buffer[2]==0x01 &&   (buffer[3]==0xB0 || (buffer[3]==0xB3 && ((buffer[4]<<8)+(buffer[5]>>8)>0) && ((buffer[5]<<8)+buffer[6]>0)) ||  buffer[3]==0xB5 ||   buffer[3]==0xBA || (buffer[3]==0xBB && (buffer[4]<<8)+(buffer[5]>>8)>0 && (buffer[6]&0x80)==0x80)))
         {
            ext = ".mpg";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
         }
}
void flv_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer, flv_header, sizeof(flv_header))==0 && (buffer[4]==1 || buffer[4]==5))
        {
            ext = ".flv";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void mxf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer,mxf_header,sizeof(mxf_header))==0)
        {
            ext = ".mxf";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}


void jpg_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
      if(memcmp(buffer,  jpg_header_app0, sizeof(jpg_header_app0))==0 || memcmp(buffer, jpg_header_app1, sizeof(jpg_header_app1))==0 || memcmp(buffer, jpg_header_com,  sizeof(jpg_header_com))==0)
      {

          ext = ".jpg";

          unsigned long long startf, file_size = 0;
            unsigned long dwRead;
          startf = *Start_Scan_Sector_From ;

         while(file_size>=0)
        {

              *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

             file_size+=512;

             SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
             ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


              if(file_size>=5000000)
             {
                    InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                    break;
             }
              int i;
              for(i=0;i<sizeof(buffer);i++)
              {
                if(memcmp(buffer+i,jpg_footer,sizeof(jpg_footer))==0)
                 {

                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                   break ;
                 }
              }
               int j = allcheck(buffer);
                         if(j==1)
                         {
                             *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                               InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                               break;
                         }

       }
      }
}
void mng_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{

             if(memcmp(buffer,mng_header,sizeof(mng_header))==0)
             {

                 ext = ".png";

                 unsigned long long startf, file_size = 0;
                   unsigned long dwRead;
                 startf = *Start_Scan_Sector_From ;

                while(file_size>=0)
               {

                     *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                    file_size+=512;

                    SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                    ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                     if(file_size>=5000000)
                    {
                           InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                           break;
                    }
                     int i;
                     for(i=0;i<sizeof(buffer);i++)
                     {
                         if(memcmp(buffer+i,mng_footer,sizeof(mng_footer))==0)
                        {

                             InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                          break ;
                        }
                     }
                      int j = allcheck(buffer);
                                if(j==1)
                                {
                                    *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                      break;
                                }

              }
             }


}
void jng_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
         if(memcmp(buffer,jng_header,sizeof(jng_header))==0)
          {
              ext = ".png";

             unsigned long long startf, file_size = 0;
               unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {

                 *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                 if(file_size>=5000000)
                {
                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                       break;
                }
                 int i;
                 for(i=0;i<sizeof(buffer);i++)
                 {
                   if(memcmp(buffer+i,jng_footer,sizeof(jng_footer))==0)
                    {

                         InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                      break ;
                    }
                 }
                  int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                  break;
                            }

          }

     }
}
void swf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
       if(memcmp(buffer, swf_header_compressed, sizeof(swf_header_compressed))==0)
       {
           ext = ".swf";
            unsigned long long startf, file_size = 0;
             unsigned long dwRead;
           startf = *Start_Scan_Sector_From ;

          while(file_size>=0)
         {

               *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

              file_size+=512;

              SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
              ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

               int j = allcheck(buffer);
                          if(j==1)
                          {
                              *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                break;
                          }

           }
             //         strcat(filename,".swc");

       }
      if(memcmp(buffer, swf_header, sizeof(swf_header))==0)
      {
          unsigned long long siz =(unsigned long long)buffer[4]+(((unsigned long long)buffer[5])<<8)+(((unsigned long long)buffer[6])<<16)+(((unsigned long long)buffer[7])<<24);
          ext = ".swf";

           unsigned long long startf, file_size = 0;
           unsigned long dwRead;
           startf = *Start_Scan_Sector_From ;

          while(file_size>=0)
         {
                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;
                 file_size+=512;

              SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
              ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

               if(file_size>=siz)
              {
                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);

                   break;
              }
                int j = allcheck(buffer);
                          if(j==1)
                          {
                              *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                              break;
                          }

        }

      }
}

void psd_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
       if(memcmp(buffer,psd_header,sizeof(psd_header))==0)
       {
           ext = ".psd";
            unsigned long long startf, file_size = 0;
             unsigned long dwRead;
           startf = *Start_Scan_Sector_From ;

          while(file_size>=0)
         {

               *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

              file_size+=512;

              SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
              ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

               int j = allcheck(buffer);
                          if(j==1)
                          {
                              *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                break;
                          }

           }
       }
       if(memcmp(buffer, psp_header, sizeof(psp_header)-1)==0)
       {
           ext = ".psp";
            unsigned long long startf, file_size = 0;
             unsigned long dwRead;
           startf = *Start_Scan_Sector_From ;

          while(file_size>=0)
         {

               *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

              file_size+=512;

              SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
              ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

               int j = allcheck(buffer);
                          if(j==1)
                          {
                              *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                break;
                          }

           }
       }
}
void gif_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
             if((memcmp (buffer, gif_header,sizeof(gif_header)))==0 || (memcmp (buffer, gif_header2,sizeof(gif_header2)))==0 )
            {
                 ext = ".gif";

                  unsigned long long startf, file_size = 0;
                  unsigned long dwRead;
                  startf = *Start_Scan_Sector_From ;

                 while(file_size>=0)
                {
                       *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;
                        file_size+=512;

                     SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                     ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                     int j = allcheck(buffer);
                                 if(j==1)
                                 {
                                     *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                                     break;
                                 }

               }
            }
 }
void ico_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer,header_ico,sizeof(header_ico))==0)
       {
            ext = ".ico";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
       }

}


void flac_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer, flac_header, sizeof(flac_header))==0)
        {
            ext = ".flac";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void mid_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer,mid_header,sizeof(mid_header))==0)
        {

            ext = ".mid";

            unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                if(file_size>=5000000)
               {
                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                      break;
               }
                int i;
                for(i=0;i<sizeof(buffer);i++)
                {
                  if(memcmp(buffer+i,mid_footer,sizeof(mid_footer))==0)
                   {

                        InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                     break ;
                   }
                }
                 int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

         }

        }
}
void ape_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,ape_header,sizeof(ape_header))==0)
     {
         ext = ".ape";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}
void ogg_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer,ogg_header,sizeof(ogg_header))==0)
          {
              ext = ".ogg";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
}
void ra_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer,ra_header,sizeof(ra_header))==0)
          {
              ext = ".ra";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
}
void au_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,au_header,sizeof(au_header))==0)
     {
         ext = ".au";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}
void mp3_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(buffer[0]==0xFF && ((buffer[1]&0xFE)==0xFA ||(buffer[2]&0xFE)==0xF2 || (buffer[3]&0xFE)==0xE2))
        {
            ext = ".mp3";

             unsigned long long startf, file_size = 0;
             unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {
                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;
                   file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                break;
                            }

          }
        }
        if(buffer[0]=='I' && buffer[1]=='D' && buffer[2]=='3' && (buffer[3]==2 || buffer[3]==3 || buffer[3]==4) && buffer[4]==0)
        {
            ext = ".id3";

             unsigned long long startf, file_size = 0;
             unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {
                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;
                   file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                break;
                            }

          }
        }

}
void aif_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
     if(memcmp(buffer,aif_header,sizeof(aif_header))==0 && buffer[8]=='A' && buffer[9]=='I' && buffer[10]=='F' && (buffer[11]=='F' || buffer[11]=='C'))
     {
         ext = ".aif";
          unsigned long long startf, file_size = 0;
           unsigned long dwRead;
         startf = *Start_Scan_Sector_From ;

        while(file_size>=0)
       {

             *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

            file_size+=512;

            SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
            ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

             int j = allcheck(buffer);
                        if(j==1)
                        {
                            *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                              InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                              break;
                        }

         }
     }
}

void max_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer,max_header,sizeof(max_header))==0)
        {
            ext = ".max";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void dwg_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
      if(memcmp(buffer,dwg_header_12,sizeof(dwg_header_12))==0 || memcmp(buffer,dwg_header_13,sizeof(dwg_header_13))==0 ||  memcmp(buffer,dwg_header_14,sizeof(dwg_header_14))==0 ||  memcmp(buffer,dwg_header_15,sizeof(dwg_header_15))==0)
      {
          ext = ".dwg";
           unsigned long long startf, file_size = 0;
            unsigned long dwRead;
          startf = *Start_Scan_Sector_From ;

         while(file_size>=0)
        {

              *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

             file_size+=512;

             SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
             ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

              int j = allcheck(buffer);
                         if(j==1)
                         {
                             *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                               InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                               break;
                         }

          }
      }
}
void dxf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
      if(memcmp(buffer, header_dxf, sizeof(header_dxf))==0 || memcmp(buffer, header_dxf_dos, sizeof(header_dxf_dos))==0 || memcmp(buffer, header_dxflib, sizeof(header_dxflib))==0 ||  memcmp(buffer, header_dxflib_dos, sizeof(header_dxflib_dos))==0)
      {
          ext = ".dxf";
           unsigned long long startf, file_size = 0;
            unsigned long dwRead;
          startf = *Start_Scan_Sector_From ;

         while(file_size>=0)
        {

              *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

             file_size+=512;

             SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
             ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

              int j = allcheck(buffer);
                         if(j==1)
                         {
                             *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                               InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                               break;
                         }

          }
      }
}

void fdb_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(&buffer[5], fdb_header, sizeof(fdb_header))==0)
        {
            ext = ".fdb";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void stl_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer, stl_header, sizeof(stl_header))==0 &&    memcmp(buffer+0x40, spaces, sizeof(spaces))==0)
          {
              ext = ".stl";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
}
void crw_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
      if((memcmp(buffer, crw_header_be, sizeof(crw_header_be))==0) || (memcmp(buffer, crw_header_le, sizeof(crw_header_le)) == 0) && (memcmp(buffer+6,"HEAPCCDR",8)==0))
      {

          ext = ".crw";

          unsigned long long startf, file_size = 0;
            unsigned long dwRead;
          startf = *Start_Scan_Sector_From ;

         while(file_size>=0)
        {

              *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

             file_size+=512;

             SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
             ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


              int i;
              for(i=0;i<sizeof(buffer);i++)
              {
                 if(memcmp(buffer+i,crw_footer,sizeof(crw_footer))==0)
                 {

                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                   break ;
                 }
              }
               int j = allcheck(buffer);
                         if(j==1)
                         {
                             *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                               InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                               break;
                         }

       }
      }
}
void orf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer, orf_header, sizeof(orf_header))==0 || memcmp(buffer, orf_header2, sizeof(orf_header2))==0)
       {
            ext = ".orf";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
         }
}
void raf_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp(buffer, raf_header, sizeof(raf_header))==0)
          {
              ext = ".raf";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
}
void raw_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
          if(memcmp (buffer+25, raw_header_contax, 7)==0)
          {
              ext = ".raw";
               unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

              }
          }
            if(memcmp(buffer, raw_header_panasonic, sizeof(raw_header_panasonic))==0)
            {
                ext = ".raw";
                 unsigned long long startf, file_size = 0;
                  unsigned long dwRead;
                startf = *Start_Scan_Sector_From ;

               while(file_size>=0)
              {

                    *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                   file_size+=512;

                   SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                   ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                    int j = allcheck(buffer);
                               if(j==1)
                               {
                                   *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                     InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                     break;
                               }

                }
            }

}
void mrw_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
        if(memcmp(buffer,mrw_header,sizeof(mrw_header))==0)
        {
            ext = ".mrw";
             unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

            }
        }
}
void x3f_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
{
            if(memcmp(buffer,x3f_header,sizeof(x3f_header))==0)
            {
                ext = ".x3f";
                 unsigned long long startf, file_size = 0;
                  unsigned long dwRead;
                startf = *Start_Scan_Sector_From ;

               while(file_size>=0)
              {

                    *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                   file_size+=512;

                   SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                   ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                    int j = allcheck(buffer);
                               if(j==1)
                               {
                                   *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                     InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                     break;
                               }

                }
            }
}


   void cwk_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
        if(memcmp(buffer+4, cwk_header, sizeof(cwk_header))==0)
        {

            ext = ".cwk";

            unsigned long long startf, file_size = 0;
              unsigned long dwRead;
            startf = *Start_Scan_Sector_From ;

           while(file_size>=0)
          {

                *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

               file_size+=512;

               SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
               ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                if(file_size>=5000000)
               {
                      InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                      break;
               }
                int i;
                for(i=0;i<sizeof(buffer);i++)
                {
                  if(memcmp(buffer+i,cwk_footer,sizeof(cwk_footer))==0)
                   {

                        InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                     break ;
                   }
                }
                 int j = allcheck(buffer);
                           if(j==1)
                           {
                               *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                 InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                 break;
                           }

         }
        }
  }
   void asm_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
         if(memcmp(buffer,asm_header,sizeof(asm_header))==0)
         {

             ext = ".asm";

             unsigned long long startf, file_size = 0;
               unsigned long dwRead;
             startf = *Start_Scan_Sector_From ;

            while(file_size>=0)
           {

                 *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                file_size+=512;

                SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                 if(file_size>=5000000)
                {
                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                       break;
                }
                 int i;
                 for(i=0;i<sizeof(buffer);i++)
                 {
                   if(memcmp(buffer+i,asm_footer,sizeof(asm_footer))==0)
                    {

                         InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                      break ;
                    }
                 }
                  int j = allcheck(buffer);
                            if(j==1)
                            {
                                *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                  InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                  break;
                            }

          }
         }
  }   
   void blend_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
       if(memcmp(buffer,blend_header,sizeof(blend_header))==0 && (buffer[7]=='_' || buffer[7]=='-'))
       {
       //	if(memcmp(&buffer[i],blend_header_footer,sizeof(blend_header_footer))==0)

           ext = ".blend";

           unsigned long long startf, file_size = 0;
             unsigned long dwRead;
           startf = *Start_Scan_Sector_From ;

          while(file_size>=0)
         {

               *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

              file_size+=512;

              SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
              ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


               int i;
               for(i=0;i<sizeof(buffer);i++)
               {
                    if(memcmp(buffer+i,blend_header_footer,sizeof(blend_header_footer))==0)
                  {

                       InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                    break ;
                  }
               }
                int j = allcheck(buffer);
                          if(j==1)
                          {
                              *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                break;
                          }

        }
       }
  }
  void frm_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
          if(memcmp(buffer,frm_header,sizeof(frm_header))==0)
          {

              ext = ".frm";

              unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                  int i;
                  for(i=0;i<sizeof(buffer);i++)
                  {
                    if(memcmp(buffer+i,frm_footer,sizeof(frm_footer))==0)
                     {

                          InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                       break ;
                     }
                  }
                   int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

           }

          }
  }
  void hr9_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
          if(memcmp(buffer,hr9_header,sizeof(hr9_header))==0)
          {

              ext = ".hr9";

              unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                  int i;
                  for(i=0;i<sizeof(buffer);i++)
                  {
                   if(memcmp(buffer+i,hr9_footer,sizeof(hr9_footer))==0)
                     {

                          InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                       break ;
                     }
                  }
                   int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

           }

          }
  }
  void mfa_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
          if(memcmp(buffer,mfa_header,sizeof(mfa_header))==0)
          {

              ext = ".mfa";

              unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);


                  int i;
                  for(i=0;i<sizeof(buffer);i++)
                  {
                     if(memcmp(buffer+i,mfa_footer,sizeof(mfa_footer))==0)
                     {

                          InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                       break ;
                     }
                  }
                   int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

           }
          }
  }
  void mfg_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
          if(memcmp(buffer,mfg_header,sizeof(mfg_header))==0)
          {

              ext = ".mfg";

              unsigned long long startf, file_size = 0;
                unsigned long dwRead;
              startf = *Start_Scan_Sector_From ;

             while(file_size>=0)
            {

                  *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                 file_size+=512;

                 SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                 ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                  int i;
                  for(i=0;i<sizeof(buffer);i++)
                  {
                    if(memcmp(buffer+i,mfg_footer,sizeof(mfg_footer))==0)
                     {

                          InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                       break ;
                     }
                  }
                   int j = allcheck(buffer);
                             if(j==1)
                             {
                                 *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                   InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                   break;
                             }

           }

          }
  }
  void prt_header_check(HANDLE *hSrc,MainWindow* w1,char buffer[],unsigned long long *Start_Scan_Sector_From)
  {
            if(memcmp(buffer,prt_header,sizeof(prt_header))==0)
            {

                ext = ".prt";

                unsigned long long startf, file_size = 0;
                  unsigned long dwRead;
                startf = *Start_Scan_Sector_From ;

               while(file_size>=0)
              {

                    *Start_Scan_Sector_From = *Start_Scan_Sector_From +1;

                   file_size+=512;

                   SetFilePointer(*hSrc,(*Start_Scan_Sector_From)*512, NULL, 0);
                   ReadFile(*hSrc, buffer, 512, &dwRead, NULL);

                    int i;
                    for(i=0;i<sizeof(buffer);i++)
                    {
                      if(memcmp(buffer+i,png_footer,sizeof(png_footer))==0)
                       {

                            InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),TRUE);
                         break ;
                       }
                    }
                     int j = allcheck(buffer);
                               if(j==1)
                               {
                                   *Start_Scan_Sector_From  = *Start_Scan_Sector_From -1;
                                     InsertItem(w1,&file_size,&startf,&(*Start_Scan_Sector_From),FALSE);
                                     break;
                               }

             }
              }
  }

#endif // HEADERFUNCATION_H
