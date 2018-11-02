 #ifndef DRIVESLIST_H
#define DTIVELIST_H

void ListDriveCB()
{
   try
  {
          int drives,i=0;
      __int64 nFree, nTotal;
        char dName[20],volName[40];
	    char volumeName[MAX_PATH + 1];

     drives = GetLogicalDrives();
     while(drives != 0)
      {
             if((drives&1) == 1)
            {
                sprintf(dName,"%c:\\",'A'+i);
                 if(GetDiskFreeSpaceEx(dName,(PULARGE_INTEGER)&nFree,(PULARGE_INTEGER)&nTotal,NULL)!= 0)
                  {
					    dn++;
						strcpy(Roster[dn].DriveChar,dName);

                       // fprintf(WriteDrive,"\n%10s",dName);
                     //   nHDFree += nFree;
                     //   nHDTotal += nTotal;

						Roster[dn].FreeMemory = nFree;
						Roster[dn].TotelMemory = nTotal;
					 
                      //  fprintf(WriteDrive,"%30u ", nFree/512);
                      //   fprintf(WriteDrive,"%30u ", nTotal/512);
                       
                         if(GetVolumeInformation(  dName,    NULL,    0,  NULL,  NULL,  NULL,
                              volName,
                              sizeof(volName)) !=0)

							  strcpy(Roster[dn].ValumeNamefs,volName);
                             // fprintf(WriteDrive,"%20s",volName);
            /*--------------------------------------------------------------------*/
                              
                            DWORD serialNumber = 0;
                            DWORD maxComponentLen = 0;
                            DWORD fileSystemFlags = 0;
                            char fileSystemName[MAX_PATH + 1] = { 0 };
   
                          if (GetVolumeInformation(  dName,  volumeName,  sizeof(volumeName),   &serialNumber,
                            &maxComponentLen,
                            &fileSystemFlags,
                            fileSystemName,
                            sizeof(fileSystemName)) == TRUE)
                          {
      	                               if(strlen(volumeName) == 0)
									   {
										    char arr[20];
                                            
                                            strcpy(Roster[dn].ValumeName,"No_Name");

										      strcpy(Roster[dn].DriveName,dName);
						                      strcat(Roster[dn].DriveName," (No_Name)  " );
											 
											   sprintf(arr,"%.3f GB",nFree/(1024*1024*1014.0));

						                      strcat(Roster[dn].DriveName, arr);
											   strcat(Roster[dn].DriveName, "/");

											   sprintf(arr,"%.3f GB",nTotal/(1024*1024*1014.0));
											      
											    strcat(Roster[dn].DriveName, arr);
											 
									   }
                                      else
									  {   
										  char arr[20];
										    strcpy(Roster[dn].ValumeName,volName);
                                         
											strcpy(Roster[dn].DriveName,dName);
						                      strcat(Roster[dn].DriveName," ( " );
											  strcat(Roster[dn].DriveName,volumeName);
										       strcat(Roster[dn].DriveName," )   " );
											  
											    sprintf(arr,"%.3f GB",nFree/(1024*1024*1014.0));

						                      strcat(Roster[dn].DriveName, arr);
											   strcat(Roster[dn].DriveName, "/");

											   sprintf(arr,"%.3f GB",nTotal/(1024*1024*1014.0));
											      
											    strcat(Roster[dn].DriveName, arr);
									 }
                                       
         
                          }
                          else
                          {       
                                MessageBox (NULL, TEXT ("\nGetVolumeInformation() failed, Error !"), TEXT ("Error !"), MB_ICONERROR) ;
                                exit(0);
                          }
  
              /*--------------------------------------------------------------------*/
						  
                             
                  }
            }
            drives>>=1;
            i++;
      }
	 
     // fclose(WriteDrive);
  }
   catch(int ex)
  {
        MessageBox (NULL, TEXT ("\nSoftware  Error !"), TEXT ("Error !"), MB_ICONERROR) ;
        exit(0);
  }
}

#endif