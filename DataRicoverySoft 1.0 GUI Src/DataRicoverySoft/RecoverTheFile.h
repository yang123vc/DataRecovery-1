#ifndef RECOVERTHEFILE_H
#define RECOVERTHEFILE_H
 
 
void Recover_the_file()
{         
	try
	{
		 
      HANDLE hSrc ,hDest;
      DWORD dwRead, dwWritten;
      DWORD  dwBytesRead, dwBytesWritten, dwPos ,pp;
    
      hSrc = CreateFile((LPCSTR)Drive,  GENERIC_READ | GENERIC_WRITE , FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
        if (hSrc == INVALID_HANDLE_VALUE)
        {
            
             sprintf(er,"Unable To Read Drive :%s",Drive);
			 SetDlgItemText(MainW,IDC_STATIC3,er);
			 MessageBox(MainW,er,"Error !",MB_OK | MB_ICONERROR);
           goto last1;
		}
         
		hDest = CreateFile(filename1, GENERIC_WRITE, 0, NULL,  CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
          if (hDest == INVALID_HANDLE_VALUE)
          {
		        sprintf(er,"Unable To Read File :%s",filename1);
			    SetDlgItemText(MainW,IDC_STATIC3,er);
			    goto last1;
          }



		    	  sprintf(ResultV," File Found : %ld",FileNo);
	              SetDlgItemText(MainW,IDC_STATIC6,ResultV);
          
         unsigned long i;
        /* FILE *fp;
         
         if((fp=fopen(filename1, "wb"))==NULL)
         {
              
			 sprintf(er,"Unable To Read File :%s",filename1);
			   SetDlgItemText(MainW,IDC_STATIC3,er);
			   fclose(fp);
			    goto last1;
         }*/
        
         pp =  SetFilePointer(hSrc,start_file*512, NULL, 0);
         if(pp == -1)
         {
			   sprintf(er,"Unable To Read Drive :%s",Drive);
			   SetDlgItemText(MainW,IDC_STATIC3,"Error Reading Sector ! ");
			  goto last1;
         }

          if(start_file != end_file)
           {
           	   unsigned long long j = 0;
                for(i=start_file;i<=end_file;i++)
                { 
                	  j++;
                	 
					  sprintf(ResultV,"%d%%",(100*j)/(end_file-start_file));
					  SetDlgItemText(MainW,IDC_STATIC7,ResultV);
                    
				
					  ReadFile(hSrc, buffer, sizeof(buffer), &dwRead, NULL);
                      WriteFile(hDest, buffer,sizeof(buffer), &dwWritten, NULL);
		               
					//  fwrite(buffer, sizeof(buffer),1, fp);
                }
           }
       
       //   fclose(fp);
    
last1:

      CloseHandle(hSrc);
	   CloseHandle(hDest);
    }
	catch(char err[])
	{
		MessageBox(MainW,err,"Error !",MB_OK | MB_ICONERROR);
	}
}
#endif