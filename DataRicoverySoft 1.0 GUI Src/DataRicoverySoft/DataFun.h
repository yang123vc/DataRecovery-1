#ifndef DATAFUN_H
#define DATAFUN_H

#include "allcheck.h"


  void gif_header_check()
  {
  
              if((memcmp (buffer, gif_header,sizeof(gif_header)))==0 || (memcmp (buffer, gif_header2,sizeof(gif_header2)))==0 )
             {
                    fName();
                    strcat(filename1,".gif");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	    whileloop();
                 	 
                         if(file_size>=5000000)
                       {
                          end_file=start_file;  
                          Recover_the_file();
                           break;
                       }  
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,gif_footer,sizeof(gif_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
             }
  }
    
  void exe_header_check()
  {
  	       if((memcmp (buffer, exe_header,sizeof(exe_header)))==0)
             {
                    fName();
                    strcat(filename1,".exe");
                    fName1();
                   while( file_size>=0)
                 {
                 	  whileloop();
                 	  
                         if(file_size>=5000000)
                       {
                       	  
                          end_file=start_file;  
                          Recover_the_file();
                           break;
                       }  
                       
                         int j = allcheck();
                              if(j==1)
                                 break;
                  }
             }
              
  }

   void png_header_check()
   {
        if(memcmp(buffer,png_header,sizeof(png_header))==0)
         {
                       fName();
                    strcat(filename1,".png");
                       fName1();
                       
                   while(file_size>=0)
                 {
                 	   whileloop();
                 	  
                       if(file_size>=5000000)
                       {
                          end_file=start_file;  
                          Recover_the_file();
                           break;
                       }  
                       
                        int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,png_footer,sizeof(png_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                       int j = allcheck();
                              if(j==1)
                                 break;
                  }
          }
   }
   
    void jng_header_check()
   {
             if(memcmp(buffer,jng_header,sizeof(jng_header))==0)
              {
                              fName();
                        strcat(filename1,".png");
                        fName1();
                   while(file_size>=0)
                 {      
                       whileloop();
                       
                      if(file_size>=5000000)
                       {
                          end_file=start_file;  
                          Recover_the_file();
                           break;
                       }  
                     
                        int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,jng_footer,sizeof(jng_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                     int j = allcheck();
                              if(j==1)
                                 break;
                  }
              }
   }
    void mng_header_check()
   {
      
                 if(memcmp(buffer,mng_header,sizeof(mng_header))==0)
                 {
                          fName();
                    strcat(filename1,".png");
                       fName1();
                  while(file_size>=0)
                 {
                 	
                       whileloop();
                       
                       if(file_size>=5000000)
                       {
                          end_file=start_file;  
                          Recover_the_file();
                           break;
                       }  
                   
                        int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,mng_footer,sizeof(mng_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                        
                      int j = allcheck();
                              if(j==1)
                                 break;
                  }
                 }
             
              
   }
    void id3_header_check()
   {
        if(buffer[0]=='I' && buffer[1]=='D' && buffer[2]=='3' && (buffer[3]==2 || buffer[3]==3 || buffer[3]==4) && buffer[4]==0)
        {          
        
                      fName();
                    strcat(filename1,".mp3");
                     fName1();
                   while(file_size>=0)
                 {      
                       whileloop();
                      if(file_size>=50000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                       }  
                         int j = allcheck();
                              if(j==1)
                                 break;
                  }
        }
   }
    void mp3_header_check()
   {
            if(buffer[0]==0xFF && ((buffer[1]&0xFE)==0xFA ||(buffer[2]&0xFE)==0xF2 || (buffer[3]&0xFE)==0xE2))
            {
            	 
            	      fName();
                    strcat(filename1,".mp3");
                    fName1();
                   while(file_size>=0)
                 {      
                       whileloop();
                       
                       if(file_size>=50000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                       }  
                       
                       int j = allcheck();
                              if(j==1)
                                 break;
                 }
                 
            }
 
   }
    void rar_header_check()
   {
          if(memcmp(buffer,rar_header,sizeof(rar_header))==0)
          {
                
            	       fName();
                    strcat(filename1,".rar");
                      fName1();
                  while(file_size>=0)
                 {      
                       whileloop();
                      
                        int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,rar_footer,sizeof(rar_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                        
                  }
          }
   }
    void zip_header_check()
   {
            if(memcmp(buffer,zip_header2,sizeof(zip_header2))==0 || memcmp(buffer,zip_header,sizeof(zip_header))==0)
            {
            	    fName();
                    strcat(filename1,".zip");
                   fName1();
                   while(file_size>=0)
                 {      
                       whileloop();
                       
					 int j = allcheck();
                              if(j==1)
                                 break;
                       
                  }
             }
   } 
   void jpg_header_check()
   {
         if(memcmp(buffer,  jpg_header_app0, sizeof(jpg_header_app0))==0 || memcmp(buffer, jpg_header_app1, sizeof(jpg_header_app1))==0 || memcmp(buffer, jpg_header_com,  sizeof(jpg_header_com))==0)
         {
                    fName();
                    strcat(filename1,".jpg");
                    fName1();
                    
                   while(file_size>=0)
                 {      
                       whileloop();
                       
                        if(file_size>=5000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                       }  
                       
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,jpg_footer,sizeof(jpg_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                  }
         
         }
}
     void z7_header_check()  //7z
   {
        if(memcmp(buffer,header_7z,sizeof(header_7z))==0)
        {
        	        fName();
                    strcat(filename1,".7z");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                     
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }             
        }
   }
    void ctg_header_check()
   {
         if(memcmp(buffer+1, ctg_header,sizeof(ctg_header))==0)
        {
                    fName();
                    strcat(filename1,".ctg");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                    
                      int j = allcheck();
                              if(j==1)
                              break;
                  } 
        }
   }
    void cwk_header_check()
   {
         if(memcmp(buffer+4, cwk_header, sizeof(cwk_header))==0)
         {
         	    fName();
                    strcat(filename1,".cwk");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,cwk_footer,sizeof(cwk_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                  }
         }
   }
    void a_header_check()
   {
         if(memcmp(buffer,a_header,sizeof(a_header))==0)
         {
         	        fName();
                    strcat(filename1,".a");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                    
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
         }
   }
    void deb_header_check()
   {
          if(memcmp(buffer,deb_header_debian,sizeof(deb_header_debian))==0)
          {
          	        fName();
                    strcat(filename1,".deb");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                     
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
          }
   }
    void ab_header_check()
   {
         if(buffer[0]=='L' && buffer[1]=='J' && (buffer[2]==0x1a || buffer[2]==0x0a) && buffer[3]==0x00)
         {
         	        fName();
                    strcat(filename1,".ab");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                      
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
         }
   }
    void abcdp_header_check()
   {
         if(memcmp(buffer, abcdp_header, sizeof(abcdp_header))==0 && buffer[9]==0x01)
         {
         	  fName();
                    strcat(filename1,".abcdp");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                       int i;
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
         }
   }
    void ace_header_check()
   {
          if(memcmp(&buffer[7],ace_header,sizeof(ace_header))==0 && buffer[4]==0)
          {
          	    fName();
                    strcat(filename1,".ace");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                      
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
          }
   }
    void ahn_header_check()
   {
         if(memcmp(buffer, ahn_header, sizeof(ahn_header))==0 && memcmp(&buffer[8], ahn_magic, sizeof(ahn_magic))==0)
         {
         	 fName();
                    strcat(filename1,".ahn");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                      
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
         }
   }
    void aif_header_check()
   {
         if(memcmp(buffer,aif_header,sizeof(aif_header))==0 && buffer[8]=='A' && buffer[9]=='I' && buffer[10]=='F' && (buffer[11]=='F' || buffer[11]=='C'))
         {
         	   fName();
                    strcat(filename1,".aif");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                     
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
         }
   }
    void all_header_check()
   {
         if(memcmp(buffer,all_header,sizeof(aif_header))==0)
         {
         	   fName();
                    strcat(filename1,".all");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                      
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
         }
   }
    void als_header_check()
   {
         if(memcmp(buffer,als_header,sizeof(als_header))==0 &&  memcmp(buffer+11,als_header2,sizeof(als_header2))==0)
        {
        	        fName();
                    strcat(filename1,".als");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,als_footer,sizeof(als_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
        }
   }
    void amd_header_check()
   {
          if(memcmp(buffer, amd_header, sizeof(amd_header))==0)
          {
                 
		      if(buffer[16]=='1' && buffer[17]=='.' && buffer[18]=='1' && buffer[19]=='9')
              {
                    fName();
                    strcat(filename1,".atd");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                     
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
             }
              else
              {
                   	     fName();
                    	 strcat(filename1,".amd");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
               }
                   
                         
          }
   }
    void amt_header_check()
   {
          if(memcmp(buffer, amt_header, sizeof(amt_header))==0)
          {
          	
               if(buffer[21]=='1' && buffer[22]=='.' && buffer[23]=='0' && buffer[24]=='8')
                {
                	    fName();
                    	 strcat(filename1,".att");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                }
               else
                  {
                   	 fName();
                    	 strcat(filename1,".amt");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                  }
                
                   
          }
   }
    void amr_header_check()
   {
         if(memcmp(buffer,amr_header,sizeof(amr_header))==0)
         {
         	             fName();
                    	 strcat(filename1,".amr");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void apa_header_check()
   {
         if(memcmp(&buffer[8], apa_magic, sizeof(apa_magic))==0)
         {
         	             fName();
                    	 strcat(filename1,".apa");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void ape_header_check()
   {
         if(memcmp(buffer,ape_header,sizeof(ape_header))==0)
         {
         	              fName();
                    	 strcat(filename1,".ape");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void apple_header_check()
   {
          if(memcmp(buffer,apple_header,sizeof(apple_header))==0)
          {
          	              fName();
                    	 strcat(filename1,".apple");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void arj_header_check()
   {
         if(memcmp(buffer, arj_header, sizeof(arj_header))==0)
         {
         	            fName();
                    strcat(filename1,".arj");
                    fName1();
                    
                   while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,arj_footer,sizeof(arj_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                }
         }
   }
    void asf_header_check()
   {
         if(memcmp(buffer,asf_header,sizeof(asf_header))==0)
         {
         	             fName();
                    	 strcat(filename1,".asf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void asm_header_check()
   {
          if(memcmp(buffer,asm_header,sizeof(asm_header))==0)
          {
          	 	           fName();
                    strcat(filename1,".asm");
                    fName1();
                    
                   while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,asm_footer,sizeof(asm_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
          }
   }
   void atd_header_check()
   {
         if(memcmp(buffer,atd_header,sizeof(atd_header))==0)
         {
         	             fName();
                    	 strcat(filename1,".atd");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void au_header_check()
   {
         if(memcmp(buffer,au_header,sizeof(au_header))==0)
         {
         	            fName();
                    	 strcat(filename1,".au");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void bkf_header_check()
   {
          if(memcmp(buffer,bkf_header,sizeof(bkf_header))==0)
          {
          	             fName();
                    	 strcat(filename1,".bkf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void blend_header_check()
   {
        if(memcmp(buffer,blend_header,sizeof(blend_header))==0 && (buffer[7]=='_' || buffer[7]=='-'))
        {
        //	if(memcmp(&buffer[i],blend_header_footer,sizeof(blend_header_footer))==0)
                     fName();
                    strcat(filename1,".blend");
                    fName1();
                    
                   while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,blend_header_footer,sizeof(blend_header_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                             break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
        }
   }
   void bmp_header_check()
   {
         if(buffer[0]=='B' && buffer[1]=='M' && buffer[6]==0x00 && buffer[7]==0x00 && buffer[8]==0x00 && buffer[9]==0x00)
         {
         	              fName();
                    	 strcat(filename1,".bmp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void bz2_header_check()
   {
          if(buffer[0]=='B' && buffer[1]=='Z' && buffer[2]=='h' && buffer[3]>='0' && buffer[4]=='1' && buffer[5]=='A' && buffer[6]=='Y' && buffer[7]=='&' && buffer[8]=='S' && buffer[9]=='Y')
          {
          	              fName();
                    	 strcat(filename1,".bz2");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void cab_header_check()
   {
         if(memcmp(buffer,cab_header,sizeof(cab_header))==0)
         {
         	            fName();
                    	 strcat(filename1,".cab");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void cam_header_check()
   {
        if(memcmp(buffer,cam_header,sizeof(cam_header))==0)
        {
        	                        fName();
                    	 strcat(filename1,".cam");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
        }
   }
   void chm_header_check()
   {
          if(memcmp(buffer, chm_header, sizeof(chm_header))==0)
          {
          	      unsigned long long siz =(buffer[104]<<0)+(buffer[105]<<8)+(buffer[106]<<16)+(buffer[107]<<24);
           
          	        fName();
                    strcat(filename1,".chm");
                    fName1();
                    
                   while(file_size>=0)
                 {      
                       whileloop();
                       
                        if(file_size>=siz)
                       {
                       	    end_file=loop;  
                            Recover_the_file();
                            break;
                       }
                     
                      if(file_size>=40000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                      }  
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
          	 
          }
   }
    void class_header_check()
   {
          if(memcmp(buffer, class_magic, sizeof(class_magic))==0)
          {
          	         fName();
                    strcat(filename1,".class");
                    fName1();
                     
                  while(file_size>=0)
                 {      
                       whileloop();
                       
                       if(file_size>=5000000)
                       {
                       	    end_file=loop;  
                            Recover_the_file();
                            break;
                       }
                     
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
          	     
          }
   }
    void comicdoc_header_check()
   {
         if(memcmp(&buffer[0x0],cm_header,sizeof(cm_header))==0)
         {
         	           fName();
                    	 strcat(filename1,".comicdoc");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void compress_header_check()
   {
          if(memcmp(buffer, compress_header, sizeof(compress_header))==0)
          {
          	             fName();
                    	 strcat(filename1,".compress");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void crw_header_check()
   {
          if((memcmp(buffer, crw_header_be, sizeof(crw_header_be))==0) || (memcmp(buffer, crw_header_le, sizeof(crw_header_le)) == 0) && (memcmp(buffer+6,"HEAPCCDR",8)==0))
          {
          	          fName();
                    strcat(filename1,".crw");
                    fName1();
                    
                   while(file_size>=0)
                 {
                 	  whileloop();
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,crw_footer,sizeof(crw_footer))==0)
                           {
                               end_file=loop;  
                               Recover_the_file();  
                              break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
				 }    
          }
   }
    void evt_header_check()
   {
         if(memcmp(buffer,evt_header,sizeof(evt_header))==0)
         {
     
                  if((buffer[4]=='L' && buffer[5]=='f' && buffer[6]=='L' && buffer[7]=='e')  ||
	              (buffer[4]==0x11 && buffer[5]==0x11 && buffer[6]==0x11 && buffer[7]==0x11) ||
	              (buffer[4]==0x22 && buffer[5]==0x22 && buffer[6]==0x22 && buffer[7]==0x22) ||
            	  (buffer[4]==0x33 && buffer[5]==0x33 && buffer[6]==0x33 && buffer[7]==0x33) ||
	              (buffer[4]==0x44 && buffer[5]==0x44 && buffer[6]==0x44 && buffer[7]==0x44))
                  {
                      unsigned int length=(buffer[0] + (buffer[1]<<8) + (buffer[2]<<16) + (buffer[3]<<24));
                 
				                   fName();
                                   strcat(filename1,".evt");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=length)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }    
				  
				  }
              
         }
   }
    void ext_header_check()
   {
         if(memcmp(buffer,ext2_sb_header,sizeof(ext2_sb_header))==0)
         {
         	            fName();
                    	 strcat(filename1,".ext");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void d2s_header_check()
   {
          if(memcmp(buffer,d2s_header,sizeof(d2s_header))==0)
          {
          	 unsigned long long  siz = (buffer[8]<<0)+(buffer[9]<<8)+(buffer[10]<<16)+(buffer[11]<<24);
          	                      fName();
                                   strcat(filename1,".d2s");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=siz)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }    
          }
   }
    void dat_header_check()
   {
          if(memcmp(buffer,dat_header,sizeof(dat_header))==0)
          {
          	             fName();
                    	 strcat(filename1,".dat");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
            if(memcmp(buffer,datIE_header,sizeof(datIE_header))==0)
           {
   
              unsigned long long  siz = (unsigned long long)buffer[0x1C]+(((unsigned long long)buffer[0x1D])<<8)+(((unsigned long long)buffer[0x1E])<<16)+(((unsigned long long)buffer[0x1F])<<24);
                 	               fName();
                                   strcat(filename1,".dat");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=siz)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }    
           }
          
   }
    void DB_header_check()
   {
          if(memcmp(buffer,DB_header,sizeof(DB_header))==0)
          {
          	             fName();
                    	 strcat(filename1,".db");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void dbf_header_check()
   {
         if(buffer[0]==0x3 && (buffer[1]>80 || buffer[1]<20) && (buffer[2]>=1 && buffer[2]<=12) && (buffer[3]>=1 && buffer[3]<=31))
         {
         	             fName();
                    	 strcat(filename1,".dbf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                         
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void diskimage_header_check()
   {
          if(memcmp(&buffer[0x0c],dim_header,sizeof(dim_header))==0)
          {
          	             fName();
                    	 strcat(filename1,".dim");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void _header_check() //  ""
   {
          if(memcmp(buffer,dir_header,8+3)==0 && memcmp(&buffer[0x20],"..         ",8+3)==0)
          {
          	             fName();
                    	 strcat(filename1,"");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void djv_header_check()
   {
         if(memcmp(buffer,djv_header,sizeof(djv_header))==0)
         {
             unsigned long long  siz = ((unsigned long long)buffer[8]<<24)+((unsigned long long)buffer[8+1]<<16)+((unsigned long long)buffer[8+2]<<8)+(unsigned long long)buffer[8+3]+12;
                                   fName();
                                   strcat(filename1,".djv");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=siz)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }      
    
         }
   }
    void doc_header_check()
   {
         if(memcmp(buffer,doc_header,sizeof(doc_header))==0)
         {
         		    fName();
                  //  strcat(filename1,".doc");
                    printf(".doc");
                    fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       if(file_size>=50000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                       }  
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,doc_footer,sizeof(doc_footer))==0)
                           {
                           	   strcat(filename1,".doc");
                               end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                             if(memcmp(buffer+i,ppt_footer,sizeof(ppt_footer))==0)
                           {
                           	   strcat(filename1,".ppt");
                               end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                            if(memcmp(buffer+i,xls_footer,sizeof(xls_footer))==0)
                           {
                           	    strcat(filename1,".xls");
                               end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
         }
   }
    void dpx_header_check()
   {
         if(memcmp(buffer,sdpx_header,sizeof(sdpx_header))==0 || memcmp(buffer,xpds_header,sizeof(xpds_header))==0)
         {
            unsigned long long  siz = (buffer[16]<<0)+(buffer[17]<<8)+(buffer[18]<<16)+(buffer[19]<<24);
                                   fName();
                                   strcat(filename1,".dpx");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=siz)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }      
         }
   }
    void drw_header_check()
   {
          if(memcmp(buffer,drw_header,sizeof(drw_header))==0)
          {
          		   	    fName();
                    strcat(filename1,".drw");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,drw_footer,sizeof(drw_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
          }
   }
    void ds2_header_check()
   {
         if(memcmp(buffer,ds2_header,sizeof(ds2_header))==0)
         {
         	           fName();
                    	 strcat(filename1,".ds2");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void dsc_header_check()
   {
        if(memcmp(buffer,dsc_header,sizeof(dsc_header))==0)
         {
         	             fName();
                    	 strcat(filename1,".dsc");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
    void dss_header_check()
   {
          if(memcmp(buffer,dss_header,sizeof(dss_header))==0)
          {
          	             fName();
                    	 strcat(filename1,".dss");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void dta_header_check()
   {
          if(memcmp(buffer,dta_header_71le,sizeof(dta_header_71le))==0 ||  memcmp(buffer,dta_header_72le,sizeof(dta_header_72le))==0)
          {
          	              fName();
                    	 strcat(filename1,".dta");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
    void dump_header_check()
   {
          if(memcmp(buffer+0x18,dump_header_le_old_fs,sizeof(dump_header_le_old_fs))==0 || memcmp(buffer+0x18,dump_header_le_new_fs,sizeof(dump_header_le_new_fs))==0)
     	{
		                fName();
                    	 strcat(filename1,".dump");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
	    }
   }
    void dv_header_check()
   {
          if(buffer[0]==0x1f && buffer[1]==0x07 && buffer[2]==0x00 && buffer[5]==0x78 && buffer[6]==0x78 && buffer[7]==0x78)
          {
          	                fName();
                    	 strcat(filename1,".dv");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
   void dwg_header_check()
   {
         if(memcmp(buffer,dwg_header_12,sizeof(dwg_header_12))==0 || memcmp(buffer,dwg_header_13,sizeof(dwg_header_13))==0 ||  memcmp(buffer,dwg_header_14,sizeof(dwg_header_14))==0 ||  memcmp(buffer,dwg_header_15,sizeof(dwg_header_15))==0)
         {
         	             fName();
                    	 strcat(filename1,".dwg");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
         }
   }
   void dxf_header_check()
   {
         if(memcmp(buffer, header_dxf, sizeof(header_dxf))==0 || memcmp(buffer, header_dxf_dos, sizeof(header_dxf_dos))==0 || memcmp(buffer, header_dxflib, sizeof(header_dxflib))==0 ||  memcmp(buffer, header_dxflib_dos, sizeof(header_dxflib_dos))==0)
         {
         			   	    fName();
                    strcat(filename1,".dxf");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,dxf_footer,sizeof(dxf_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
         }
   }
   void edb_header_check()
   {
           if(memcmp(&buffer[4], edb_magic, sizeof(edb_magic))==0)
           {
           	               fName();
                    	 strcat(filename1,".edb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void elf_header_check()
   {
           if(memcmp(buffer,elf_header,sizeof(elf_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".elf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void emf_header_check()
   {
           if(memcmp(buffer,emf_header,sizeof(emf_header))==0 &&  memcmp(&buffer[0x28],emf_sign,sizeof(emf_sign))==0)
           {
           	                      fName();
                                   strcat(filename1,".emf");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=5000000)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }   
		 
		   }
   }
 /*  void MYI_header_check()
   {
         if(buffer[0]==0xfe && buffer[1]==0xfe && buffer[2]==0x07 && buffer[3]==0x01)
         {
         	 //myi
         }
        if(buffer[0]==0xfe && buffer[1]==0x01 && (buffer[2]>=0x07 && buffer[2]<=0x0A) && buffer[3]==0x09)
         {
           	//frm
         }
         
   } */
   void fbk_header_check()
   {
           if(memcmp(buffer, fbk_header, sizeof(fbk_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".fbk");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void fcp_header_check()
   {
           if(memcmp(buffer,fcp_header,sizeof(fcp_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".fcp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void fcs_header_check()
   {
             if(memcmp(buffer, fcs_signature, sizeof(fcs_signature))==0)
             {
             	            fName();
                    	 strcat(filename1,".fcs");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
   }
   void fdb_header_check()
   {
           if(memcmp(&buffer[5], fdb_header, sizeof(fdb_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".fdb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void fh5_header_check()
   {
	       #pragma pack(push, 1)
   	        struct fh5_header_s
           {
                unsigned char   id[8];
                unsigned        datalen;  
           };
			 #pragma pack(pop)

           typedef struct fh5_header_s fh5_header_t;
           const fh5_header_t *fh5_buffer=(const fh5_header_t *) buffer;
           
           if(memcmp(fh5_buffer->id,fh5_header,sizeof(fh5_header))==0)
           {
           	    unsigned long long  siz =be32(fh5_buffer->datalen) + 4096;
           	                       fName();
                                   strcat(filename1,".fh5");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=siz)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }   
           }
   }
   void fh10_header_check()
   {
           if(memcmp(buffer,fh10_header,sizeof(fh10_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".fh10");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void fits_header_check()
   {
           if(memcmp(buffer,fits_header,sizeof(fits_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".fits");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void flac_header_check()
   {
           if(memcmp(buffer, flac_header, sizeof(flac_header))==0)
           {
           	             fName();
                    	 strcat(filename1,".flac");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void flp_header_check()
   {
           if(memcmp(buffer, flp_header, sizeof(flp_header))==0)
           {
           	      unsigned long long  siz =(unsigned long long)buffer[0x12]+(((unsigned long long)buffer[0x13])<<8)+(((unsigned long long)buffer[0x14])<<16)+(((unsigned long long)buffer[0x15])<<24) + 0x16;
                                   fName();
                                   strcat(filename1,".flp");
                                   fName1();
                    
                                  while(file_size>=0)
                                {
                                	  whileloop();
                                      
                                      if(file_size>=siz)
                                      {
                                      	    end_file=loop;  
                                            Recover_the_file();  
                                            break ;
                                      }
                                     int j = allcheck();
                                             if(j==1)
                                                break;
			                   }   
        	 
		   }
   }
   void flv_header_check()
   {
           if(memcmp(buffer, flv_header, sizeof(flv_header))==0 && (buffer[4]==1 || buffer[4]==5))
           {
           	              fName();
                    	 strcat(filename1,".flv");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void fob_header_check()
   {
           if((memcmp(buffer, magic_codeunit, sizeof(magic_codeunit))==0 ||
               memcmp(buffer, magic_dataport, sizeof(magic_dataport))==0 ||
               memcmp(buffer, magic_form, sizeof(magic_form))==0 ||
               memcmp(buffer, magic_menusuite, sizeof(magic_menusuite))==0 ||
               memcmp(buffer, magic_report, sizeof(magic_report))==0 ||
               memcmp(buffer, magic_table, sizeof(magic_table))==0 ||
               memcmp(buffer, magic_xmlport, sizeof(magic_xmlport))==0))    /* &&
             (td_memmem(buffer, buffer_size, sign_navnl, sizeof(sign_navnl))!=NULL ||
             td_memmem(buffer, buffer_size, sign_navw, sizeof(sign_navw))!=NULL))  */
            {
      	                   fName();
                    	 strcat(filename1,".fob");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
   }
   void fp7_header_check()
   {
           if(memcmp(buffer,fp7_header,sizeof(fp7_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".fp7");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void frm_header_check()
   {
           if(memcmp(buffer,frm_header,sizeof(frm_header))==0)
           {
           	   	   	    fName();
                    strcat(filename1,".frm");
                      fName1();
                    
                   while( file_size<5368709120)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,frm_footer,sizeof(frm_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
           }
   }
   void fs_header_check()
   {
            if(memcmp(buffer,fs_header,sizeof(fs_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".fs");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void gho_header_check()
   {
           if((memcmp(buffer, gho_header, sizeof(gho_header))==0) &&  memcmp (buffer+8, gho_header_next, sizeof(gho_header_next))==0)
           {
      	                    fName();
                    	 strcat(filename1,".gho");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void gz_header_check()
   {
           if((memcmp(buffer, gz_header_magic, sizeof(gz_header_magic))==0)  && (buffer[3]&0xe0)==0)
           {
           	               fName();
                    	 strcat(filename1,".gz");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void hds_header_check()
   {
           if(memcmp(buffer,hds_header,sizeof(hds_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".hds");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void hr9_header_check()
   {
           if(memcmp(buffer,hr9_header,sizeof(hr9_header))==0)
           {
           	  	    	    fName();
                    strcat(filename1,".hr9");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,hr9_footer,sizeof(hr9_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
           }
   }
   void ico_header_check()
   {
   	       if(memcmp(buffer,header_ico,sizeof(header_ico))==0)
          {
                      fName();
                    strcat(filename1,".ico");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                      
                       if(file_size>=1000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                       }  
                    
                        if(file_size >= 500000)
                        {
                        	  end_file=loop;  
                               Recover_the_file();  
                               break ;
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
          }

   }
   void ifo_header_check()
   {
           if(memcmp(buffer, ifo_header_vmg, sizeof(ifo_header_vmg))==0 ||  memcmp(buffer, ifo_header_vts, sizeof(ifo_header_vts))==0)
           {
           	              fName();
                    	 strcat(filename1,".ifo");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void imb_header_check()
   {
           if(memcmp(buffer+1,imb_header,sizeof(imb_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".imb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void indd_header_check()
   {
	      #pragma pack(push, 1)
           struct indd_header_s 
		   {
               unsigned char   id[24];  unsigned char   unknown[256];  unsigned    blocks;  char    headblocks;
           };
		     #pragma pack(pop)

           typedef struct indd_header_s indd_header_t;
          
           const indd_header_t *hdr = (const indd_header_t *)buffer;
          
            if (memcmp(hdr->id,indd_header,sizeof(indd_header))==0)
            {
               unsigned long long siz=(unsigned long long)(1+le32(hdr->blocks))*4096 + 10*4096;
                      fName();
                    strcat(filename1,".indd");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                     
                        if(file_size >= siz)
                        {
                        	  end_file=loop;  
                               Recover_the_file();  
                               break ;
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
		   
		    }
     
   }
   void iso_header_check()
   {
           
	try
	{
		 
	
              
               if(memcmp (&buffer[0x8000], iso_header, sizeof(iso_header))==0)
                {
                	
                 
                              fName();
                    	 strcat(filename1,".iso");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
              
                }

		}
	catch(char err[])
	{
		MessageBox(MainW,err,"Error !",MB_OK | MB_ICONERROR);
	}
              
   }
   void itu_header_check()
   {
            if(memcmp(buffer, itunes_header, sizeof(itunes_header))==0)
            {
                      unsigned long long siz =(unsigned long long)buffer[8] +  (((unsigned long long)buffer[9])<<8) + (((unsigned long long)buffer[10])<<16) + (((unsigned long long)buffer[11])<<24);
                       fName();
                    strcat(filename1,".itu");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                     
                        if(file_size >= siz)
                        {
                        	  end_file=loop;  
                               Recover_the_file();  
                               break ;
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
		    }
   }
   void kdb_header_check()
   {
            if(memcmp(buffer, kdb_header, sizeof(kdb_header))==0)
            {
            	            fName();
                    	 strcat(filename1,".kdb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
   }
   void idf_header_check()
   {
           if(buffer[0x00]==0x01 && buffer[0x01]==0x0f && buffer[0x02]==0x00 && buffer[0x03]==0x00 &&
               buffer[0x08]==0x00 && buffer[0x09]==0x00 && buffer[0x0a]==0x00 && buffer[0x0b]==0x00 &&
               buffer[0x0c]==0x00 && buffer[0x0d]==0x00 && buffer[0x0e]==0x00 && buffer[0x0f]==0x00 &&
               buffer[0x10]==0x00 && buffer[0x11]==0x00 && buffer[0x12]==0x00 && buffer[0x13]==0x00 &&
               buffer[0x14]==0x00 && buffer[0x15]==0x00 && buffer[0x16]==0x02 && buffer[0x17]==0x00 &&
               buffer[0x18]==0x63 && buffer[0x19]==0x00 && buffer[0x1A]==0x00 && buffer[0x1B]==0x00)
               {
               	               fName();
                    	 strcat(filename1,".idf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
               }
   }
   void lnk_header_check()
   {
            if(memcmp(buffer,lnk_header,sizeof(lnk_header))==0)
            {
            	           fName();
                    	 strcat(filename1,".lnk");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
   }
   void logic_header_check()
   {
           if(memcmp(buffer,logic_header,sizeof(logic_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".logic");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void m2ts_header_check()
   {
           if(buffer[4]==0x47 && buffer[4+192]==0x47 && buffer[4+2*192]==0x47 &&  memcmp(&buffer[0xd7], m2ts_header, sizeof(m2ts_header))==0 &&  memcmp(&buffer[0xe8], m2ts_header, sizeof(m2ts_header))==0)
            {
      	                 fName();
                    	 strcat(filename1,".m2ts");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
            
           if(buffer[0]==0x47 && buffer[188]==0x47 && buffer[2*188]==0x47 &&  memcmp(&buffer[0x18b], m2t_header, sizeof(m2t_header))==0)
           {
                              fName();
                    	 strcat(filename1,".m2t");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void max_header_check()
   {
           if(memcmp(buffer,max_header,sizeof(max_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".max");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void mb_header_check()
   {
            if(memcmp(&buffer[8], mb_header, sizeof(mb_header))==0 ||  memcmp(&buffer[8], mb_header2, sizeof(mb_header2))==0)
             {
      	            unsigned long long siz  =(unsigned long long)(buffer[4]<<24)+(buffer[5]<<16)+(buffer[6]<<8)+buffer[7]+8;
                       fName();
                    strcat(filename1,".mb");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                     
                        if(file_size >= siz)
                        {
                        	  end_file=loop;  
                               Recover_the_file();  
                               break ;
                        }
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
			
			 }
             if(memcmp(&buffer[8], mp_header, sizeof(mp_header))==0)
             {
               	            fName();
                    	 strcat(filename1,".mp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
   }
   void mcd_header_check()
   {
            if(buffer[0]==0x00 && buffer[1]==0x00 &&   memcmp(buffer+0x0e,mcd_header,sizeof(mcd_header))==0)
            {
            	           fName();
                    	 strcat(filename1,".mcd");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
      
   }
   void mdb_header_check()
   {
            if(memcmp (buffer, mdb_header, sizeof(mdb_header))==0)
            {
            	           fName();
                    	 strcat(filename1,".mdb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
             else if(memcmp (buffer, accdb_header, sizeof(accdb_header))==0)
            {
                 	           fName();
                    	 strcat(filename1,".accdb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
            
   }
   void mdf_header_check()
   {
           if(buffer[0x00]==0x01 && buffer[0x01]==0x0f && buffer[0x02]==0x00 && buffer[0x03]==0x00 &&
              buffer[0x08]==0x00 && buffer[0x09]==0x00 && buffer[0x0a]==0x00 && buffer[0x0b]==0x00 &&
              buffer[0x0c]==0x00 && buffer[0x0d]==0x00 && buffer[0x0e]==0x00 && buffer[0x0f]==0x00 &&
              buffer[0x10]==0x00 && buffer[0x11]==0x00 && buffer[0x12]==0x00 && buffer[0x13]==0x00 &&
              buffer[0x14]==0x00 && buffer[0x15]==0x00 && buffer[0x16]==0x01 && buffer[0x17]==0x00 &&
              buffer[0x18]==0x63 && buffer[0x19]==0x00 && buffer[0x1A]==0x00 && buffer[0x1B]==0x00)
              {
              	             fName();
                    	 strcat(filename1,".mdf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
              }
   }
   void mfa_header_check()
   {
           if(memcmp(buffer,mfa_header,sizeof(mfa_header))==0)
           {
           	 	       fName();
                    strcat(filename1,".mfa");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,mfa_footer,sizeof(mfa_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
           }
   }
   void mfg_header_check()
   {
           if(memcmp(buffer,mfg_header,sizeof(mfg_header))==0)
           {
           	             fName();
                    strcat(filename1,".mfg");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,mfg_footer,sizeof(mfg_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
           }
   }
   void mid_header_check()
   {
           if(memcmp(buffer,mid_header,sizeof(mid_header))==0)
           {
           		          fName();
                    strcat(filename1,".mid");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,mid_footer,sizeof(mid_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
           }
   }
   void mk5_header_check()
   {
             if(memcmp(buffer,mk5_header,sizeof(mk5_header))==0 &&  memcmp(buffer+0x1c,mk5_header2,sizeof(mk5_header2))==0)
              {
              	
              		  fName();
                    strcat(filename1,".mk5");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                     
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
              }
   }
   void mkv_header_check()
   {
   	      
          if(memcmp(buffer,mkv_header,sizeof(mkv_header))==0 && memcmp(buffer+24,"matroska",8)==0)
          {
          	 // calculated_file_size=(uint64_t)(buffer[0x20]<<24)+(((uint64_t)buffer[0x21])<<16)+(((uint64_t)buffer[0x22])<<8)+((uint64_t)buffer[0x23])+0x24;
                            fName();
                    	 strcat(filename1,".mkv");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
	      }
   }
   void mp4_header_check()
   {
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
                     fName();
                    	 strcat(filename1,".mp4");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
      }
   }
   void mpg_header_check()
   {
           if(buffer[0]==0x00 && buffer[1]==0x00 && buffer[2]==0x01 &&   (buffer[3]==0xB0 || (buffer[3]==0xB3 && ((buffer[4]<<8)+(buffer[5]>>8)>0) && ((buffer[5]<<8)+buffer[6]>0)) ||  buffer[3]==0xB5 ||   buffer[3]==0xBA || (buffer[3]==0xBB && (buffer[4]<<8)+(buffer[5]>>8)>0 && (buffer[6]&0x80)==0x80)))
            {
            	             fName();
                    	 strcat(filename1,".mpg");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
   }
   void mrw_header_check()
   {
           if(memcmp(buffer,mrw_header,sizeof(mrw_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".mrw");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void mus_header_check()
   {
           if(memcmp(buffer,mus_header,sizeof(mus_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".mus");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void mxf_header_check()
   {
           if(memcmp(buffer,mxf_header,sizeof(mxf_header))==0)
           {
           	              fName();
                    	 strcat(filename1,".mxf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void MYI_header_check()
   {
           /* MySQL MYISAM compressed data file Version 1 */
           if(buffer[0]==0xfe && buffer[1]==0xfe && buffer[2]==0x07 && buffer[3]==0x01)
           {
                           fName();
                    	 strcat(filename1,".myi");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
          /* MySQL table definition file Version 7 up to 10 */
           if(buffer[0]==0xfe && buffer[1]==0x01 && (buffer[2]>=0x07 && buffer[2]<=0x0A) && buffer[3]==0x09)
          {
                             fName();
                    	 strcat(filename1,".frm");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
          }
   }
  
   void njx_header_check()
   {
   	         if(buffer[0]==0x04 && buffer[1]=='N' && buffer[2]=='j' && buffer[3]==0x0f &&  buffer[6]=='N' && buffer[7]=='J' && buffer[8]=='S' && buffer[9]=='t' && buffer[10]=='a' && buffer[11]=='r')
            {
      	               fName();
                    strcat(filename1,".njx");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,njx_footer,sizeof(njx_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
            }
   }
   void nk2_header_check()
   {
   	         if(memcmp(buffer, nk2_header, sizeof(nk2_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".nk2");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void ogg_header_check()
   {
   	         if(memcmp(buffer,ogg_header,sizeof(ogg_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".ogg");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void one_header_check()
   {
   	        if(memcmp(buffer,one_header,sizeof(one_header))==0)
   	        {
   	        	             fName();
                    	 strcat(filename1,".one");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	        }
   }
   void orf_header_check()
   {
   	       if(memcmp(buffer, orf_header, sizeof(orf_header))==0 || memcmp(buffer, orf_header2, sizeof(orf_header2))==0)
   	      {
   	          		          fName();
                    strcat(filename1,".orf");
                      fName1();
                    
                   while(file_size>=0)
                 {      
                       whileloop();
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
   	        }
   }
   void paf_header_check()
   {
   	         if(memcmp(buffer,paf_header,sizeof(paf_header))==0)
   	         {
   	         	             fName();
                    	 strcat(filename1,".paf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void pap_header_check()
   {
   	         if(memcmp(buffer,pap_header,sizeof(pap_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".pap");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void pcap_header_check()
   {
   	         if(memcmp(buffer, pcap_header, sizeof(pcap_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".pcap");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void pdf_header_check()
   {
   	          if(memcmp(buffer,pdf_header,sizeof(pdf_header))==0)
   	          {
   	         		    fName();
                    strcat(filename1,".pdf");
                      fName1();
                    
                   while(file_size>=0)
                 {      
                       whileloop();
                     
                       if(file_size>=100000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                       }  
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,pdf_footer,sizeof(pdf_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
   	           }
   }
   void pfx_header_check()
   {
   	        if(memcmp(buffer,pfx_header,sizeof(pfx_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".pfx");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void prc_header_check()
   {
   	         if(memcmp(&buffer[0x30],prc_header,sizeof(prc_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".prc");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void prt_header_check()
   {
   	         if(memcmp(buffer,prt_header,sizeof(prt_header))==0)
   	         {
   	         		          fName();
                    strcat(filename1,".prt");
                      fName1();
                    
                  while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(memcmp(buffer+i,prt_footer,sizeof(prt_footer))==0)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
   	           }
   }
   void ps_header_check()
   {
   	         if(memcmp(buffer,ps_header,sizeof(ps_header))==0)
   	         {
   	          
   	                        fName();
                    strcat(filename1,".ps");
                      fName1();
                    
                 while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(buffer[i]=='%' && buffer[i+1]=='%' && buffer[i+2]=='E' && buffer[i+3]=='O' && buffer[i+4]=='F')
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
			  
		     }
   }
   void psd_header_check()
   {
   	      if(memcmp(buffer,psd_header,sizeof(psd_header))==0)
   	      {
   	      	              fName();
                    	 strcat(filename1,".psd");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	      }
   }
   void psp_header_check()
   {
   	          if(memcmp(buffer, psp_header, sizeof(psp_header)-1)==0)
   	          {
   	          	              fName();
                    	 strcat(filename1,".psp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
   void pst_header_check()
   {
   	         if(memcmp(buffer,wab_header,sizeof(wab_header))==0)
   	         {
   	         	             fName();
                    	 strcat(filename1,".pst");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   	           if(memcmp(buffer,dbx_header,sizeof(dbx_header))==0)
   	           {
   	           	              fName();
                    	 strcat(filename1,".dbx");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	           }
   	             if(memcmp(buffer,pst_header,sizeof(pst_header))==0)
   	             {
   	             	              fName();
                    	 strcat(filename1,".pst");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	             }
   }
   void ptb_header_check()
   {
   	         if(memcmp(buffer,ptb_header,sizeof(ptb_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".ptb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void pyc_header_check()
   {
   	         if(memcmp(buffer,pyc_15_magic,sizeof(pyc_15_magic))==0 || (memcmp(buffer,pyc_20_magic,sizeof(pyc_20_magic))==0 ) ||  (memcmp(buffer,pyc_21_magic,sizeof(pyc_21_magic))==0 ) ||  (memcmp(buffer,pyc_22_magic,sizeof(pyc_22_magic))==0 ) || (memcmp(buffer,pyc_23_magic,sizeof(pyc_23_magic))==0 ) || (memcmp(buffer,pyc_24_magic,sizeof(pyc_24_magic))==0 ) || (memcmp(buffer,pyc_25_magic,sizeof(pyc_25_magic))==0 ))
   	         {
   	         	             fName();
                    	 strcat(filename1,".pyc");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void qbb_header_check()
   {
   	  /*        if(memcmp(buffer, qbb_header, sizeof(qbb_header))==0)
   	          {
   	          	              fName();
                    	 strcat(filename1,".qbb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          } */
   	            if(buffer[4]==0x56 && buffer[5]==0x00 && buffer[6]==0x00 && buffer[7]==0x00 && buffer[0x60]=='M' && buffer[0x61]=='A' && buffer[0x62]=='U' && buffer[0x63]=='I')
   	            {
   	            	           fName();
                    	 strcat(filename1,".qbb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	            }
   }
   void qdf_header_check()
   {
   	          if(memcmp(buffer,qdf_header,sizeof(qdf_header))==0)
   	          {
   	          	              fName();
                    	 strcat(filename1,".qdf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
   void qxd_header_check()
   {
   	         if(memcmp(buffer,qxd_header,sizeof(qxd_header))==0)
   	         {
   	                        fName();
                    	 strcat(filename1,".qxd");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   	          if(memcmp(buffer+2,qxp_header_be,sizeof(qxp_header_be))==0 ||  memcmp(buffer+2,qxp_header_le,sizeof(qxp_header_le))==0) 
   	         {
   	         	           fName();
                    	 strcat(filename1,".qsp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void ra_header_check()
   {
   	         if(memcmp(buffer,ra_header,sizeof(ra_header))==0)
   	         {
   	         	            fName();
                    	 strcat(filename1,".ra");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void raf_header_check()
   {
   	         if(memcmp(buffer, raf_header, sizeof(raf_header))==0)
   	         {
   	         	           fName();
                    	 strcat(filename1,".raf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void raw_header_check()
   {
   	         if(memcmp (buffer+25, raw_header_contax, 7)==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".raw");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   	           if(memcmp(buffer, raw_header_panasonic, sizeof(raw_header_panasonic))==0)
   	           {
   	           	                 fName();
                    	 strcat(filename1,".raw");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	           }
   	         
   }
   void rdc_header_check()
   {
   	          if(memcmp(buffer, rdc_header, sizeof(rdc_header))==0)
   	          {
   	          	              fName();
                    	 strcat(filename1,".rdc");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
   void reg_header_check()
   {
   	         if(memcmp(buffer,reg_header_9x,sizeof(reg_header_9x))==0 ||
      memcmp(buffer,reg_header_nt,sizeof(reg_header_nt))==0)
      {
      	                 fName();
                    	 strcat(filename1,".reg");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
      }
   }
   void res_header_check()
   {
   	         if(memcmp(buffer,MS_res_header,sizeof(MS_res_header))==0)
   	         {
   	         	              fName();
                    	 strcat(filename1,".res");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void riff_header_check()
   {
   	         if(memcmp(buffer,riff_header,sizeof(riff_header))==0)
   	         {
   	         	     if(memcmp(&buffer[8],"AVI ",4)==0)
				    {
				          fName();
                    	 strcat(filename1,".avi");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                  	
   	         	    }
                    else if(memcmp(&buffer[8],"CDDA",4)==0)
                    {
                                 fName();
                    	 strcat(filename1,".cda");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                  	
                    }
                   else if(memcmp(&buffer[8],"CDR",3)==0)
                   {
                   	          fName();
                    	 strcat(filename1,".cdr");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                   }
                   else if(memcmp(&buffer[8],"NUND",4)==0)
                   {
                   	           fName();
                    	 strcat(filename1,".cpr");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                   }
                  else if(memcmp(&buffer[8],"RMP3",4)==0 || memcmp(&buffer[8],"WAVE",4)==0)
                  {
                  	         fName();
                    	 strcat(filename1,".wav");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                  }
                    else
                    {
                             fName();
                    	 strcat(filename1,".avi");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                    }
                 
   	           }
   }
   void rm_header_check()
   {
   	          if(memcmp(buffer,rm_header,sizeof(rm_header))==0)
   	          {
   	          	           fName();
                    	 strcat(filename1,".rm");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
   void rns_header_check()
   {
   	          if(memcmp(buffer,rns_header,sizeof(rns_header)-1)==0)
   	          {
   	          	          fName();
                    	 strcat(filename1,".rns");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
   void rpm_header_check()
   {
   	         if(memcmp(buffer, rpm_header, sizeof(rpm_header))==0)
   	         {
   	         	         fName();
                    	 strcat(filename1,".rpm");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void ses_header_check()
   {
   	         if(memcmp(buffer, ses_magic, sizeof(ses_magic))==0)
   	         {
   	         	         fName();
                    	 strcat(filename1,".ses");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void sid_header_check()
   {
   	         if(memcmp(buffer, sib_header, sizeof(sib_header))==0)
   	         {
   	         	        fName();
                    	 strcat(filename1,".sid");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void sit_header_check()
   {
   	         if(memcmp(buffer,sit_header,sizeof(sit_header))==0)
   	         {
   	         	         fName();
                    	 strcat(filename1,".sit");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void skd_header_check()
   {
   	            if(memcmp(buffer,skd_header,sizeof(skd_header))==0)
   	            {
   	            	         fName();
                    	 strcat(filename1,".skd");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	            }
   }
   void skp_header_check()
   {
   	         if(memcmp(buffer,skp_header, sizeof(skp_header))==0)
   	         {
   	         	         fName();
                    	 strcat(filename1,".skp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void sp3_header_check()
   {
   	         if(memcmp(buffer, sp31_header, sizeof(sp31_header))==0 ||	memcmp(buffer, sp32_header, sizeof(sp32_header))==0)
	        {
	            	        fName();
                    	 strcat(filename1,".sp3");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
	        }
   }
   void spf_header_check()
   {
   	         if(memcmp(buffer,spf_header,sizeof(spf_header))==0)
   	         {
   	         	         fName();
                    	 strcat(filename1,".spf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void sav_header_check()
   {
   	              if(memcmp(buffer,spss_header,sizeof(spss_header))==0)
   	              {
   	              	         fName();
                    	 strcat(filename1,".sav");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	              }
   }
   void sqlite_header_check()
   {
   	            if(memcmp(buffer,sqlite_header,sizeof(sqlite_header))==0)
   	            {
   	                        fName();
                    	 strcat(filename1,".sqlite");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	            }
   }
   void sqm_header_check()
   {
   	         if(memcmp(buffer, sqm_header, sizeof(sqm_header))==0)
   	         {
   	         	        fName();
                    	 strcat(filename1,".sqm");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void stl_header_check()
   {
   	         if(memcmp(buffer, stl_header, sizeof(stl_header))==0 &&    memcmp(buffer+0x40, spaces, sizeof(spaces))==0)
             {
             	         fName();
                    	 strcat(filename1,".stl");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
   }
   void stu_stu_header_check()
   {
   	         if(memcmp(buffer,stuffit_header,sizeof(stuffit_header))==0)
   	         {
   	         	         fName();
                    	 strcat(filename1,".stu");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void swf_header_check()
   {
   	      if(memcmp(buffer, swf_header_compressed, sizeof(swf_header_compressed))==0)
   	      {
   	      	            fName();
                    	 strcat(filename1,".swc");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                      
                       if(file_size>=50000000)
                       {
                       	  end_file=loop;  
                           Recover_the_file();
                             break;
                       }  
                    
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	      }
   	     if(memcmp(buffer, swf_header, sizeof(swf_header))==0)
   	     {
   	     	 unsigned long long siz =(uint64_t)buffer[4]+(((uint64_t)buffer[5])<<8)+(((uint64_t)buffer[6])<<16)+(((uint64_t)buffer[7])<<24);
   	         	    fName();
                    strcat(filename1,".swf");
                      fName1();
                    
                 while(file_size>=0)
                 {      
                       whileloop();
                    
                       int i;
                        for(i=0;i<sizeof(buffer);i++)
                        {
                          if(file_size >= siz)
                           {
                           	    end_file=loop;  
                               Recover_the_file();  
                               break ;
                           }
                        }
                       
                      int j = allcheck();
                              if(j==1)
                                 break;
                 }
		   
		 }   
   }
   void tar_header_check()
   {
   	          if(memcmp(&buffer[0x101],tar_header_gnu,sizeof(tar_header_gnu))==0 ||    memcmp(&buffer[0x101],tar_header_posix,sizeof(tar_header_posix))==0)
              {
              	          fName();
                    	 strcat(filename1,".tar");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
              }
   }
   void tax_header_check()
   {
   	         if(memcmp(buffer, tax_header, sizeof(tax_header))==0)
   	         {
   	         	         fName();
                    	 strcat(filename1,".tax");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void tib_header_check()
   {
   	         if(memcmp(buffer,tib_header, sizeof(tib_header))==0)
   	         {
   	         	               fName();
                    	 strcat(filename1,".tib");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void tic_header_check()
   {
   	       if(memcmp(buffer,tiff_header_be,sizeof(tiff_header_be))==0 ||   memcmp(buffer,tiff_header_le,sizeof(tiff_header_le))==0)
           {
           	     if(buffer[8]=='C' && buffer[9]=='R' && buffer[10]==2)
           	     {
           	     	       fName();
                    	 strcat(filename1,".rc2");
                     	  fName1();
           	     }
           	     else
           	     {
           	     	     fName();
                    	 strcat(filename1,".tiff");
                     	  fName1();
                 }
                 
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
           }
   }
   void tph_header_check()
   {
   	             if(memcmp(buffer,tph_header,sizeof(tph_header))==0)
   	             {
   	            	 	    fName();
                       strcat(filename1,".tph");
                      fName1();
                    
                        while(file_size>=0)
                       {      
                             whileloop();
                    
                             int i;
                              for(i=0;i<sizeof(buffer);i++)
                              {
                                if(memcmp(buffer+i,tph_footer,sizeof(tph_footer))==0)
                                 {
                                 	    end_file=loop;  
                                     Recover_the_file();  
                                     break ;
                                 }
                              }
                       
                            int j = allcheck();
                                    if(j==1)
                                       break;
                       }
   	               }
   }
   void ttf_header_check()
   {
   	          if(memcmp(buffer, header_ttf, sizeof(header_ttf))==0)
   	          {
   	          	             fName();
                    	 strcat(filename1,".ttf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
   void text_header_check()
   {
   	         if(memcmp(buffer,header_cls,sizeof(header_cls))==0)
  	         {
    	                   fName();
                    	 strcat(filename1,".cls");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                 	   	
                   	 	  whileloop();
                     
                 	   	  if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
              if(memcmp(buffer,header_adr,sizeof(header_adr)-1)==0)
  	         {
    	                   fName();
                    	 strcat(filename1,".adr");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                   	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_imm,sizeof(header_imm))==0 ||   memcmp(buffer,header_ReturnPath,sizeof(header_ReturnPath))==0 ||   memcmp(buffer,header_mail,sizeof(header_mail))==0)
             {
                          fName();
                    	 strcat(filename1,".imm");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
            if(memcmp(buffer,header_perlm,sizeof(header_perlm)-1)==0 && (buffer[sizeof(header_perlm)]==' ' || buffer[sizeof(header_perlm)]=='\t'))
             {
                        fName();
                    	 strcat(filename1,".pm");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                           if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_rpp,sizeof(header_rpp))==0)
             {
                        fName();
                    	 strcat(filename1,".rpp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_rtf,sizeof(header_rtf))==0)
             {
                         fName();
                    	 strcat(filename1,".rtf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                            if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_reg,sizeof(header_reg)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".reg");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                   	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_sh,sizeof(header_sh)-1)==0 ||   memcmp(buffer,header_bash,sizeof(header_bash)-1)==0)
             {
                          fName();
                    	 strcat(filename1,".sh");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_slk,sizeof(header_slk)-1)==0)
             {
                           fName();
                    	 strcat(filename1,".slk");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer, header_stl, sizeof(header_stl)-1)==0 &&   memcmp(buffer+0x40, spaces, sizeof(spaces))!=0)
             {
                          fName();
                    	 strcat(filename1,".stl");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer, header_ers, sizeof(header_ers)-1)==0)
             {
                            fName();
                    	 strcat(filename1,".ers");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_stp,sizeof(header_stp)-1)==0)
             {
                        fName();
                    	 strcat(filename1,".stp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_wpl,sizeof(header_wpl))==0)
             {
                           fName();
                    	 strcat(filename1,".wpl");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_ram,sizeof(header_ram)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".ram");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_xml,sizeof(header_xml)-1)==0)
             {
                          fName();
                    	 strcat(filename1,".xml");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(buffer[0]=='0' && buffer[1]=='0' && memcmp(&buffer[4],header_dc,sizeof(header_dc)-1)==0)
             {  
                         fName();
                    	 strcat(filename1,".dc");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_dif,sizeof(header_dif))==0)
             {  
                             fName();
                    	 strcat(filename1,".dif");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer, header_ics, sizeof(header_ics)-1)==0)
             {
                            fName();
                    	 strcat(filename1,".ics");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
 
             if(memcmp(buffer, header_lyx, sizeof(header_lyx))==0)
             { 
                         fName();
                    	 strcat(filename1,".lyx");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
 
             if(memcmp(buffer, header_m3u, sizeof(header_m3u))==0)
             { 
                         fName();
                    	 strcat(filename1,".m3u");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
 
             if(memcmp(buffer, header_msf, sizeof(header_msf)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".msf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer, header_cue, sizeof(header_cue)-1)==0)
             { 
                         fName();
                    	 strcat(filename1,".cue");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_bat,sizeof(header_bat)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".bat");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_asp,sizeof(header_asp)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".asp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_vcf,sizeof(header_vcf)-1)==0)
             {
                            fName();
                    	 strcat(filename1,".vcf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
              if(memcmp(buffer,header_sig_python,sizeof(header_sig_python)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".py");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,header_sig_perl,sizeof(header_sig_perl)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".pl");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
              if(memcmp(buffer,header_sig_ruby,sizeof(header_sig_ruby)-1)==0)
             {
                          fName();
                    	 strcat(filename1,".rb");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
              if(memcmp(buffer,sign_c,sizeof(sign_c)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".c");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
              if(memcmp(buffer,sign_h,sizeof(sign_h)-1)==0)
             {
                             fName();
                    	 strcat(filename1,".h");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
             if(memcmp(buffer,sign_jsp,sizeof(sign_jsp)-1)==0 || memcmp(buffer,sign_jsp2,sizeof(sign_jsp2)-1)==0)
             {
                          fName();
                    	 strcat(filename1,".jsp");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
              if(memcmp(buffer,sign_php,sizeof(sign_php)-1)==0)
             {
                        fName();
                    	 strcat(filename1,".php");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
            if(memcmp(buffer,sign_tex,sizeof(sign_tex)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".tex");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
              if(memcmp(buffer,sign_html,sizeof(sign_html)-1)==0)
             {
                         fName();
                    	 strcat(filename1,".html");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     	 	  
                          if(file_size >= 4000000)
                 	   	  {
                 	   	  	      end_file=loop;  
                                   Recover_the_file();  
                                   break ;
                 	   	  }
                 	   	  
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
               
   }
   void tz_header_check()
   {
   	         if(memcmp(buffer,tz_header,sizeof(tz_header))==0 ||  memcmp(buffer,tz2_header,sizeof(tz2_header))==0)
            {
            	        fName();
                    	 strcat(filename1,".tz");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
            }
  
   }
   void veg_header_check()
   {
   	         if(memcmp(buffer,veg_header,sizeof(veg_header))==0)
   	         {
   	         	  unsigned long long  siz=(uint64_t)buffer[0x10] + (((uint64_t)buffer[0x11])<<8) +  (((uint64_t)buffer[0x12])<<16) + (((uint64_t)buffer[0x13])<<24);
   	             	    fName();
                       strcat(filename1,".veg");
                      fName1();
                    
                       while(file_size>=0)
                       {      
                             whileloop();
                    
                             int i;
                              for(i=0;i<sizeof(buffer);i++)
                              {
                                if(file_size >= siz)
                                 {
                                 	    end_file=loop;  
                                     Recover_the_file();  
                                     break ;
                                 }
                              }
                       
                            int j = allcheck();
                                    if(j==1)
                                       break;
                       }
			  }
   }
   void vmdk_header_check()
   {
   	          if(memcmp(buffer,vmdk_header3, sizeof(vmdk_header3))==0 ||   memcmp(buffer,vmdk_header4, sizeof(vmdk_header4))==0)
             {
             	           fName();
                    	 strcat(filename1,".vmdk");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
  
   }
   void vks_header_check()
   {
   	          if(memcmp(buffer,wks_header,sizeof(wks_header))==0)
   	          {
   	          	           fName();
                    	 strcat(filename1,".vks");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   	           if(memcmp(buffer,wk4_header,sizeof(wk4_header))==0)
		  	  {
				  	        fName();
                    	 strcat(filename1,".wk4");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
			  } 
   	          
   }
   void wmf_header_check()
   {
   	         if(memcmp(buffer,apm_header,sizeof(apm_header))==0 ||  memcmp(buffer,emff_header,sizeof(emf_header))==0 ||  memcmp(buffer,wmf_header,sizeof(wmf_header))==0)
             {
             	          fName();
                    	 strcat(filename1,".wmf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
             }
   
   }
   void wnk_header_check()
   {
   	         if(memcmp(buffer, wnk_header, sizeof(wnk_header))==0)
   	         {
   	         	          fName();
                    	 strcat(filename1,".wnk");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	         }
   }
   void wpd_header_check()
   {
   	         if(memcmp(buffer, wpd_header, sizeof(wpd_header))==0)
   	         {
   	                unsigned long long  siz=(uint64_t)buffer[20]+(((uint64_t)buffer[21])<<8)+(((uint64_t)buffer[22])<<16)+(((uint64_t)buffer[23])<<24);
                    	    fName();
                       strcat(filename1,".wpd");
                      fName1();
                    
                       while(file_size>=0)
                       {      
                             whileloop();
                    
                             int i;
                              for(i=0;i<sizeof(buffer);i++)
                              {
                                if(file_size >= siz)
                                 {
                                 	    end_file=loop;  
                                     Recover_the_file();  
                                     break ;
                                 }
                              }
                       
                            int j = allcheck();
                                    if(j==1)
                                       break;
                       }
   	         }
   }
   void x3f_header_check()
   {
   	           if(memcmp(buffer,x3f_header,sizeof(x3f_header))==0)
   	           {
   	           	            fName();
                    	 strcat(filename1,".x3f");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	           }
   }
   void xcf_header_check()
   {
   	             if(memcmp(buffer,xcf_header_v0, sizeof(xcf_header_v0))==0 ||   memcmp(buffer,xcf_header_v1, sizeof(xcf_header_v1))==0)
                {
                	          fName();
                    	 strcat(filename1,".xcf");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
                }
 
   }
    void xm_header_check()
   {
   	          if(memcmp(buffer,xm_header,sizeof(xm_header))==0)
   	          {
   	          	          fName();
                    	 strcat(filename1,".xm");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
    void xpt_header_check()
   {
   	          if(memcmp(buffer, xpt_header, sizeof(xpt_header))==0)
   	          {
   	          	           fName();
                    	 strcat(filename1,".xpt");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
    void xsv_header_check()
   {
   	          if(memcmp(buffer + 20, xsv_header, sizeof(xsv_header))==0)
   	          {
   	          	          fName();
                    	 strcat(filename1,".xsv");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
    void xv_header_check()
   {
   	          if(memcmp(buffer,xv_header,sizeof(xv_header))==0)
   	          {
   	          	          fName();
                    	 strcat(filename1,".xv");
                     	  fName1();
                    
                   	   while(file_size>=0)
                 	   {
                   	 	  whileloop();
                     
                   	      int j = allcheck();
                     	            if(j==1)
                       	             break;
			  	      }    
   	          }
   }
   
   
#endif