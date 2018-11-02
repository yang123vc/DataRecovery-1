#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDir>
#include <QFileInfo>
#include <QtDebug>
#include <windows.h>
#include <process.h>
#include "globlevariable.h"
#include <direct.h>
#include <qt_windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SetPanalDuretionTime(300);
    SetStyleSheet();
    GetDrive();

    ui->driveCharTxt->setVisible(false);
    ui->DriveFreeTxt->setVisible(false);
    ui->DriveNameTxt->setVisible(false);
    ui->DriveTotelTxt->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);

    ui->SelectedDriveGrupB->setGeometry(60,10,451,151);
    ui->centralWidget->setGeometry(0,0,577,653);
    ui->FileExtenTionPanal->setGeometry(50,10,531,631);
     ui->FindItemPanal->setGeometry(60,168,461,410);

    Qt::WindowFlags flags =0;
    flags |= Qt::MSWindowsFixedSizeDialogHint;
    ui->centralWidget->setWindowFlags(flags);

  // ui->progressBar->setRange(0,100);
  // ui->StartRecovery->setEnabled(FALSE);
   ui->SelectedDriveGrupB->setVisible(false);
   ui->ProgressPanal->setVisible(false);
   ui->FindItemPanal->setVisible(false);


//  ui->FindItemPanal->items.clear();
     on_DrivePanalButton_clicked();
     ui->ButtonFrame->setVisible(false);
}
void MainWindow::on_StartRecovery_clicked()
{

   if(QDrive == "\\\\.\\ :")
   {
       QMessageBox::warning(this,"Informetion","Please Select Drive");
       on_FileExtPanalButton_clicked();
       on_DrivePanalButton_clicked();
   }
   else if((Chbox_ppt_var == false) && (Chbox_doc_var == false) && (Chbox_pst_var == false) && (Chbox_chm_var == false)
           && (Chbox_pdf_var == false) && (Chbox_one_var == false) && (Chbox_fb2_var == false) && (Chbox_njx_var == false)
           && (Chbox_txt_var == false)&& (Chbox_nk2_var == false) && (Chbox_ps_var == false) && (Chbox_7z_var == false)
            && (Chbox_tar_var == false) && (Chbox_bz2_var == false) && (Chbox_rar_var == false) && (Chbox_zip_var == false)
            && (Chbox_cab_var == false) && (Chbox_a_var == false) && (Chbox_arj_var == false) && (Chbox_myi_var == false)
            && (Chbox_mdb_var == false) && (Chbox_abcdb_var == false) && (Chbox_db_var == false) && (Chbox_fp7_var == false)
            && (Chbox_ldf_var == false) && (Chbox_edb_var == false) && (Chbox_mdf_var == false) && (Chbox_sqlite_var == false)
            && (Chbox_asf_var == false) && (Chbox_amv_var == false) && (Chbox_avi_var == false) && (Chbox_mp4_var == false)
            && (Chbox_flv_var == false) && (Chbox_mpg_var == false) && (Chbox_mxf_var == false) && (Chbox_jpg_var == false)
            && (Chbox_mng_var == false) && (Chbox_png_var == false) && (Chbox_swf_var == false) && (Chbox_aep_var == false)
            && (Chbox_psd_var == false) && (Chbox_bmp_var == false) && (Chbox_gif_var == false) && (Chbox_ico_var == false)
            && (Chbox_flac_var == false) && (Chbox_mid_var == false) && (Chbox_ape_var == false) && (Chbox_ogg_var == false)
            && (Chbox_ra_var == false) && (Chbox_au_var == false) && (Chbox_mp3_var == false) && (Chbox_aif_var == false)
            && (Chbox_max_var == false) && (Chbox_dwg_var == false) && (Chbox_dxf_var == false) && (Chbox_eps_var == false)
            && (Chbox_fdb_var == false) && (Chbox_stl_var == false) && (Chbox_crw_var == false) && (Chbox_orf_var == false)
            && (Chbox_raf_var == false) && (Chbox_mrw_var == false) && (Chbox_raw_var == false) && (Chbox_x3f_var == false))
   {
        QMessageBox::warning(this,"Informetion "," Please Select File Type To Recover ");
   }
   else
   {
        ui->ButtonFrame->setVisible(true);
        ui->ProgressPanal->setVisible(true);

       FindIterms = 0;
       Percent = 0;
    //   Percent2 = 0;

       ButtonStartStatus  =  1;


       ui->FindItemPanal->setVisible(true);
       //ui->FindItemPanal->items.clear();
       on_FileExtPanalButton_clicked();
       ui->RecoverBack->setEnabled(true);

   }

}

void MainWindow::on_SeectAllCh_clicked()
{
    if(!ui->SeectAllCh->isChecked())
    {
        QListWidgetItem* item = 0;
        for(int i = 0; i < ui->FindItemPanal->count(); i++)
        {
              item = ui->FindItemPanal->item(i);
              item->setCheckState(Qt::Unchecked);
        }
    }
    else
    {
        QListWidgetItem* item = 0;
        for(int i = 0; i < ui->FindItemPanal->count(); i++)
        {
              item = ui->FindItemPanal->item(i);
              item->setCheckState(Qt::Checked);
        }
    }
}


void MainWindow::Add_Recover_Items()
{
      //     MessageBox(0,L"One Item Added",L"",MB_OK);

           QString FileSi = FileSi.number(File_Size/(1024*1024.0));
           QString FileSS = FileSS.number(File_Start_Sector);
           QString FileES = FileES.number(File_End_Sector);
           QString FileN = FileN.number(FindIterms);

           QString Add  = FileSi + "MB,    " + FileSS + ",    " + FileES;

           ui->FindItemPanal->addItem("FIlE"+FileN+ext+",    "+Add+",     "+ext);


           QListWidgetItem* item = 0;
           for(int i = 0; i < ui->FindItemPanal->count(); i++)
           {
               item = ui->FindItemPanal->item(i);
               item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
               item->setCheckState(Qt::Unchecked);
           }

          FindIterms = FindIterms +1;

          ui->FindFileNo->setText(QString::number(FindIterms));

}
void MainWindow::Write_Percent()
{
      ui->s->setText(QString::number(Percent));

}
void MainWindow::RecoverSelectedItems()
{

    //  QString SelectOF;
   //   SelectOF =  QFileDialog::getOpenFileName(this,"Select .bla File",QDir::currentPath(),tr("Black Recovery File(*.bla)"));

       QFileDialog dir;
       DirOF =   dir.getExistingDirectory(this,"Select Location ","Select Location To Recover File Save",QFileDialog::ShowDirsOnly);
       DirOF =  DirOF + "\\Recovered Files";
       _mkdir(DirOF.toAscii().data());

      FindIterms = 0;
      QListWidgetItem* item = 0;

      for(int i = 0; i < ui->FindItemPanal->count(); i++)
      {
          item = ui->FindItemPanal->item(i);
          if(item->checkState() == Qt::Checked)
          {
                qApp->processEvents();

               QString str =  item->text();
               QStringList Token = str.split(',',QString::SkipEmptyParts);

               QString TFileName =Token[0];
            //   QString TFileSize =Token[1];
               QString TStartClus =Token[2];
               QString TEndClus =Token[3];
               //QString TEndClus =Token[3];


               //File_Size = TFileSize.toLongLong();
               File_Start_Sector = TStartClus.toLongLong();
               File_End_Sector = TEndClus.toLongLong();

               FindIterms = FindIterms +1;

               RecoverItems(TFileName);

               ui->FindFileNo->setText(QString::number(FindIterms));

          }
      }

       QMessageBox::information(this,"Informetion ! ","Selected Item Recoverd sucessfull ! ");

}

void MainWindow::on_RecoverBack_clicked()
{
      ButtonStartStatus  = 0;
      ui->RecoverBack->setEnabled(false);
   //   ui->SelectedDriveGrupB->setVisible(false);

}



void MainWindow::save()
{

    QString SelectSF;
    SelectSF =  QFileDialog::getSaveFileName(this,"Export File",QDir::currentPath(),tr("Black Recovery File(*.bla)"));

    QFile file(SelectSF.toAscii().data());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << DriveCombo_Var << "\n";

    QListWidgetItem* item = 0;
    for(int i = 0; i < ui->FindItemPanal->count(); i++)
    {
        item = ui->FindItemPanal->item(i);
      //  if(item->checkState() == Qt::Checked)
            out << item->text() << "\n";
    }

    QMessageBox::information(this, tr("Checkable list in BlackRecovery"),
                                   tr("BlackRecovery Export were saved."),
                                   QMessageBox::Ok);
}


void MainWindow::on_RecoverItems_clicked()
{

  // ButtonStartStatus = 2 ;
     RecoverSelectedItems();
}
void MainWindow::on_ExportInDrive_clicked()
{
    if(DriveCombo_Var == "")
    {
         QMessageBox::information(this,"Informetion ! ","Select A Drive ");
    }
    else
    {
         save();
    }

}
void MainWindow::on_ImportDetails_clicked()
{

    //  QMessageBox::critical(this,"Error !  ",QDir::currentPath());
       QString SelectOF;
    SelectOF =  QFileDialog::getOpenFileName(this,"Select .bla File",QDir::currentPath(),tr("Black Recovery File(*.bla)"));

     ui->FindItemPanal->setVisible(true);

    QFile file(SelectOF.toAscii().data());
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        int i = 0;
        QTextStream in(&file);
        while(!in.atEnd())
        {

           QString ImportStr =  in.readLine();
           if(i==0)
           {

              try
               {
                   if(ImportStr == "")
                   {
                        QMessageBox::critical(this,"Error !  ","Wrong Drive Try Again");

                   }
                   else
                   {
                        char DrivrQ1[4];
                        sprintf(DrivrQ1,"%.4s",ImportStr.toAscii().data());
                        QString st;
                        st.sprintf("%s",DrivrQ1);

                        st =st.mid(1,3);
                        sprintf(val,"%s",st.toAscii().data());

                        QDrive[4] = st[0];


                        dGetFreeSize(st);

                        ui->driveCharTxt->setText(st);
                        ui->DriveNameTxt->setText(GetDriveName(st));
                        QString Free = Free.number(Drive_Free_Size/(1024*1024*1024.0));
                        QString Totel = Totel.number(Drive_Totel_size/(1024*1024*1024.0));
                        ui->DriveFreeTxt->setText(Free+" GB ");
                        ui->DriveTotelTxt->setText(Totel +" GB");

                        ui->driveCharTxt->setVisible(true);
                        ui->DriveFreeTxt->setVisible(true);
                        ui->DriveNameTxt->setVisible(true);
                        ui->DriveTotelTxt->setVisible(true);
                        ui->label_2->setVisible(true);
                        ui->label_3->setVisible(true);
                        ui->label_4->setVisible(true);
                        ui->label_5->setVisible(true);

                        on_DrivePanalButton_clicked();

                        ui->SelectedDriveGrupB->setVisible(true);
                        ui->ProgressPanal->setVisible(false);
                         ui->RecoverBack->setEnabled(false);

                      DriveCombo_Var = ImportStr;
               }


               }
               catch(QString e)
               {
                   QMessageBox::critical(this,"Error ! Find ",e);
               }
           }
           else
           {
                  ui->FindItemPanal->addItem(ImportStr);
           }

           i++;
        }
      file.close();
    }
    else
    {
          QMessageBox::information(this,"Error ! ","File Importing Error ! ");
    }

    QListWidgetItem* item = 0;
    for(int i = 0; i < ui->FindItemPanal->count(); i++)
    {
        item = ui->FindItemPanal->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

      ui->ButtonFrame->setVisible(true);
    ui->FindFN->setText("Recoverd Item : ");
    ui->ProgressPanal->setVisible(true);

}

void MainWindow::RecoverItems(QString TFileName)
{

         HANDLE hSrc;
         DWORD dwRead,pp;
         char buffer[512];

         hSrc = CreateFile((WCHAR*)QDrive.utf16(),  GENERIC_READ | GENERIC_WRITE , FILE_SHARE_READ|FILE_SHARE_WRITE, NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
           if (hSrc == INVALID_HANDLE_VALUE)
           {
               CloseHandle(hSrc);
               QMessageBox::information(this,"Error ! ", "Unable To Open Drive To Read");
           }
           else
           {

            unsigned long i;
            FILE *fp;

             char FileN[MAX_PATH];

             sprintf(FileN,"%s\\%s",DirOF.toAscii().data(),TFileName.toAscii().data());

            if((fp=fopen(FileN, "wb"))==NULL)
            {
                    QMessageBox::information(this,"Error ! ", "Error Opening File");
            }

            pp =  SetFilePointer(hSrc,File_Start_Sector*512, NULL, 0);
            if(pp == -1)
            {
                  QMessageBox::information(this,"Error ! ", " Erroor Reading File ! Try again ! ");

            }
            if(File_Start_Sector != File_End_Sector)
              {
                  unsigned long long j = 0;
                   for(i=File_Start_Sector;i<=File_End_Sector;i++)
                   {
                         j++;

                         Percent = (100*j)/(File_End_Sector-File_Start_Sector);
                           ui->s->setText(QString::number(Percent));

                         ReadFile(hSrc, buffer, sizeof(buffer), &dwRead, NULL);
                         fwrite(buffer, sizeof(buffer),1, fp);
                   }
              }



              Percent = 0;
             fclose(fp);

          }

         CloseHandle(hSrc);

   //  QMessageBox::information(this," Sucessfull ! ", " Selected Item Recover SucessFull ! ");

}


void MainWindow::GetDrive()
{

    foreach (QFileInfo drive, QDir::drives())
    {
        if(drive.isReadable())
        {
           //  qDebug()<<"Drive :"<<rive.absoluteFilePath().toAscii().data());

                QString st = drive.absoluteFilePath().toAscii().data();
                QString st1 = st;
                QString vName = GetDriveName(st);

                  st = "("+ st + ") " + vName +" ";

                 ULARGE_INTEGER freeByte;
                 ULARGE_INTEGER totelByte;
                 freeByte.QuadPart = 0L;
                 totelByte.QuadPart = 0L;
                if(GetDiskFreeSpaceEx((WCHAR*)st1.utf16(),&freeByte,&totelByte,NULL))
                {
                    Drive_Free_Size = freeByte.QuadPart;
                    Drive_Totel_size = totelByte.QuadPart;
                    Drive_Totel_Sector = totelByte.QuadPart/512;
                }

                float freeSpace_ingb = freeByte.QuadPart/(1024*1024*1024.0);
                float totelSpace_inGB = totelByte.QuadPart/(1024*1024*1024.0);

                 QString Qs_freeSpace_ingb = Qs_freeSpace_ingb.number(freeSpace_ingb);
                 QString QS_totelSpace_inGB = QS_totelSpace_inGB.number(totelSpace_inGB);


                 st = st + "(" + Qs_freeSpace_ingb.mid(0,QS_totelSpace_inGB.indexOf(".")+3) +" GB Free Of "+QS_totelSpace_inGB.mid(0,QS_totelSpace_inGB.indexOf(".")+3)+" GB )";
                 ui->DriveListCombo->addItem(st);
/*
                 qDebug()<<"Drive_Totel_Sector : "<<Drive_Free_Size;
                qDebug()<<"Drive_Totel_Sector b: "<<Drive_Totel_size;
                qDebug()<<"Drive_Totel_Sector b: "<<Drive_Totel_Sector; */
          }
     }

}
QString MainWindow::GetDriveName(QString Drive)
{
    QString vName ;

    WCHAR szVolumeName[256];
    WCHAR szFileSystemName[256];
    DWORD dwSerialNumber = 0;
    DWORD dwMaxFileNameLangth = 256;
    DWORD dwFileSystemFlages = 0;
    bool ret = GetVolumeInformation((WCHAR*)Drive.utf16(),szVolumeName,
                                    256,&dwSerialNumber,&dwMaxFileNameLangth,
                                    &dwFileSystemFlages,szFileSystemName,256);
    if(!ret)
      return QString("");
    else
        vName = QString::fromUtf16((const ushort*)szVolumeName);

    if(vName == "")
        vName = "No_Name";

    return vName;
}

int MainWindow::dGetFreeSize(QString Drive)
{

    ULARGE_INTEGER freeByte;
    ULARGE_INTEGER totelByte;
    freeByte.QuadPart = 0L;
    totelByte.QuadPart = 0L;
   if(!GetDiskFreeSpaceEx((WCHAR*)Drive.utf16(),&freeByte,&totelByte,NULL))
   {
       return 0;
   }
   else
   {
       Drive_Free_Size = freeByte.QuadPart;
       Drive_Totel_size = totelByte.QuadPart;
       Drive_Totel_Sector = totelByte.QuadPart/512;
   }
   return 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::SetStyleSheet()
 {

   ui->StylePannalButton->setStyleSheet("min-width:10px;"
                                        "height:10px;"
                                        "background-color:none;"
                                        "border-width: 2px;"
                                        "border-color:black;"
                                        "border-style: solid;"
                                        "border-radius: 5;"
                                        "padding: 3px;"
                                        "border-image: url(:/images/Settingico.png);");


   ui->DrivePanalButton->setStyleSheet("min-width:10px;"
                                        "height:10px;"
                                        "background-color:none;"
                                        "border-width: 2px;"
                                        "border-color:black;"
                                        "border-style: solid;"
                                        "border-radius: 5;"
                                        "padding: 3px;"
                                        "border-image: url(:/images/Drive.png);");

   ui->FileExtPanalButton->setStyleSheet("min-width:10px;"
                                        "height:10px;"
                                        "background-color:none;"
                                        "border-width: 2px;"
                                        "border-color:black;"
                                        "border-style: solid;"
                                        "border-radius: 5;"
                                        "padding: 3px;"
                                        "border-image: url(:/images/fileext.png);");
 }

void MainWindow::loadStyleSheet(const QString &sheetName)
{
    QFile file(":/css/" + sheetName.toLower() + ".css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

      qApp->setStyleSheet(styleSheet);
     //  ui->centralWidget->setStyleSheet(styleSheet);

     ui->centralWidget->setStyleSheet("font: 12pt Times New Roman;");

}
void MainWindow::SetPanalDuretionTime(int Mics)
{
    PA.setPropertyName("geometry");
    PA.setDuration(Mics);
    PA1.setPropertyName("geometry");
    PA1.setDuration(Mics);
    PA2.setPropertyName("geometry");
    PA2.setDuration(Mics);
    StylePanalStatus = Close1;
    DriveListStatus = Close1;
    FileExtentionPanalStatus = Open1;
    on_StylePannalButton_clicked();
    on_DrivePanalButton_clicked();
    on_FileExtPanalButton_clicked();
     SReadFile();

     qApp->setStyle(SStyleSheet);
     loadStyleSheet(SStyleSheetName);

      ui->SStyleCombo->addItems(QStyleFactory::keys());
}


void MainWindow::on_StylePannalButton_clicked()
{
    if(StylePanalStatus == Close1)
    {
        PA.setTargetObject(ui->StyleFrame);
        PA.setStartValue(QRect(-10, 450, 521, 141));
        PA.setEndValue(QRect(-482, 450, 521, 141));
        PA.start();
        StylePanalStatus  = Open1;
    }
    else
    {
        PA.setTargetObject(ui->StyleFrame);
        PA.setStartValue(QRect(-482, 450, 521, 141));
        PA.setEndValue(QRect(-10, 450, 521, 141));
        PA.start();
          StylePanalStatus  = Close1;
    }
}
void MainWindow::on_SStyleCombo_activated(const QString &StyleName)
{
    qApp->setStyle(StyleName);
     SStyleSheet = StyleName;
    ui->centralWidget->setStyleSheet("font: 12pt Times New Roman;");
    SWriteFile();
}

void MainWindow::on_SStyleSheetCombo_activated(const QString &StyleName)
{
   loadStyleSheet(StyleName);
   SStyleSheetName = StyleName;
   ui->centralWidget->setStyleSheet("font: 12pt Times New Roman;");
   SWriteFile();
}

void MainWindow::SWriteFile()
{

  //  QFile fileW("C:\\Users\\Public\\Documents\\Qt Project\\BlackRicovery\\sta\\SSetting.sta");
     QFile fileW("SSetting.sta");
  //  QTextStream in(&fileW);
     if(fileW.open(QFile::WriteOnly))
    {
       QTextStream out(&fileW);
       out<<SStyleSheetName+"\n"+SStyleSheet;
    }
}
void MainWindow::SReadFile()
{
   // QFile file("C:\\Users\\Public\\Documents\\Qt Project\\BlackRicovery\\sta\\SSetting.sta");
     QFile file("SSetting.sta");
    if(file.open(QFile::ReadOnly | QFile::Text))
    {
        int i = 0;
        QTextStream in(&file);
        while(!in.atEnd())
        {
           QString SSetting =  in.readLine();
           if(i==0)
           {
               SStyleSheetName = SSetting;
           }
           else if(i == 1)
           {
                 SStyleSheet = SSetting;
           }
           else
           {}
           i++;
        }
      file.close();
    }
}

void MainWindow::on_DrivePanalButton_clicked()
{
    if(DriveListStatus == Close1)
    {
        PA1.setTargetObject(ui->DriveFrame);
        PA1.setStartValue(QRect(-482, 80, 521, 311));
        PA1.setEndValue(QRect(-10, 80, 521, 311));
        PA1.start();
        DriveListStatus  = Open1;
    }
    else
    {
        PA1.setTargetObject(ui->DriveFrame);
        PA1.setStartValue(QRect(-10, 80, 521, 311));
        PA1.setEndValue(QRect(-482, 80, 521, 311));
        PA1.start();
          DriveListStatus  = Close1;
    }
}

void MainWindow::on_DriveListCombo_activated(const QString &arg1)
{
    try
    {
        if(arg1 == "SelectDrive")
        {
             QMessageBox::critical(this,"Error !  ","Wrong Drive Try Again");

        }
        else
        {
             char DrivrQ1[4];
             sprintf(DrivrQ1,"%.4s",arg1.toAscii().data());
             QString st;
             st.sprintf("%s",DrivrQ1);

             st =st.mid(1,3);
             sprintf(val,"%s",st.toAscii().data());

             QDrive[4] = st[0];


             dGetFreeSize(st);

             ui->driveCharTxt->setText(st);
             ui->DriveNameTxt->setText(GetDriveName(st));
             QString Free = Free.number(Drive_Free_Size/(1024*1024*1024.0));
             QString Totel = Totel.number(Drive_Totel_size/(1024*1024*1024.0));
             ui->DriveFreeTxt->setText(Free+" GB ");
             ui->DriveTotelTxt->setText(Totel +" GB");

             ui->driveCharTxt->setVisible(true);
             ui->DriveFreeTxt->setVisible(true);
             ui->DriveNameTxt->setVisible(true);
             ui->DriveTotelTxt->setVisible(true);
             ui->label_2->setVisible(true);
             ui->label_3->setVisible(true);
             ui->label_4->setVisible(true);
             ui->label_5->setVisible(true);

             on_DrivePanalButton_clicked();
             on_FileExtPanalButton_clicked();

             ui->SelectedDriveGrupB->setVisible(true);
             ui->ProgressPanal->setVisible(false);
              ui->RecoverBack->setEnabled(false);

           DriveCombo_Var = arg1;
    }


    }
    catch(QString e)
    {
        QMessageBox::critical(this,"Error ! Find ",e);
    }
}


void MainWindow::on_FileExtPanalButton_clicked()
{

    if(FileExtentionPanalStatus == Close1)
    {
        PA2.setTargetObject(ui->FileExtenTionPanal);
        PA2.setStartValue(QRect(535, 10, 531, 631));
        PA2.setEndValue(QRect(50, 10, 531, 631));
        PA2.start();
        FileExtentionPanalStatus  = Open1;

        ui->ButtonFrame->setVisible(false);
        ui->FindItemPanal->setVisible(false);
        ui->SelectedDriveGrupB->setVisible(false);

    }
    else
    {
        PA2.setTargetObject(ui->FileExtenTionPanal);
        PA2.setStartValue(QRect(50, 10, 531, 631));
        PA2.setEndValue(QRect(535, 10, 531, 631));
        PA2.start();
          FileExtentionPanalStatus  = Close1;

          ui->ButtonFrame->setVisible(true);
          ui->FindItemPanal->setVisible(true);
          ui->SelectedDriveGrupB->setVisible(true);
    }
    if(DriveListStatus == Open1)
    {
        on_DrivePanalButton_clicked();
    }
}
void MainWindow::Microsoft_Office_And_Doc_chcedStat(bool ch)
{
    Chbox_ppt_var  = ch;  ui->Chbox_ppt->setChecked(ch);
    Chbox_doc_var  = ch;  ui->Chbox_doc->setChecked(ch);
    Chbox_pst_var  = ch;  ui->Chbox_pst->setChecked(ch);
    Chbox_chm_var  = ch;  ui->Chbox_chm->setChecked(ch);
    Chbox_pdf_var  = ch;  ui->Chbox_pdf->setChecked(ch);
    Chbox_one_var  = ch;  ui->Chbox_one->setChecked(ch);
    Chbox_wpd_var  = ch;  ui->Chbox_wpd->setChecked(ch);
    Chbox_fb2_var  = ch;  ui->Chbox_fb2->setChecked(ch);
    Chbox_njx_var  = ch;  ui->Chbox_njx->setChecked(ch);
    Chbox_txt_var  = ch;   ui->Chbox_nk2->setChecked(ch);
    Chbox_nk2_var  = ch;  ui->Chbox_txt->setChecked(ch);
    Chbox_ps_var   = ch;  ui->Chbox_ps->setChecked(ch);
}

void MainWindow::on_Microsoft_Office_And_Doc_clicked()
{
    if(ui->Microsoft_Office_And_Doc->isChecked())
    {
        Microsoft_Office_And_Doc_chcedStat(true);
    }
    else
    {
         Microsoft_Office_And_Doc_chcedStat(false);
    }
}

void MainWindow::Comppress_Archives_chcedStat(bool ch)
{
     ui->Chbox_7z->setChecked(ch);
     ui->Chbox_tar->setChecked(ch);
     ui->Chbox_bz2->setChecked(ch);
     ui->Chbox_rar->setChecked(ch);
     ui->Chbox_zip->setChecked(ch);
     ui->Chbox_cab->setChecked(ch);
     ui->Chbox_a->setChecked(ch);
     ui->Chbox_arj->setChecked(ch);

    Chbox_7z_var   = ch;
    Chbox_tar_var  = ch;
    Chbox_bz2_var   = ch;
    Chbox_rar_var   = ch;
    Chbox_zip_var   = ch;
    Chbox_cab_var   = ch;
    Chbox_a_var     = ch;
    Chbox_arj_var  = ch;
}
void MainWindow::on_Comppress_Archives_clicked()
{
    if(ui->Comppress_Archives->isChecked())
    {
        Comppress_Archives_chcedStat(true);
    }
    else
    {
         Comppress_Archives_chcedStat(false);
    }
}
void MainWindow::Database_file_chcedStat(bool ch)
{
     ui->Chbox_myi->setChecked(ch);
     ui->Chbox_mdb->setChecked(ch);
     ui->Chbox_abcdb->setChecked(ch);
     ui->Chbox_db->setChecked(ch);
     ui->Chbox_fp7->setChecked(ch);
     ui->Chbox_ldf->setChecked(ch);
     ui->Chbox_edb->setChecked(ch);
     ui->Chbox_mdf->setChecked(ch);
      ui->Chbox_sqlite->setChecked(ch);

      Chbox_myi_var  = ch;
      Chbox_mdb_var  = ch;
       Chbox_abcdb_var  = ch;
       Chbox_db_var  = ch;
       Chbox_fp7_var  = ch;
       Chbox_ldf_var  = ch;
       Chbox_edb_var  = ch;
       Chbox_mdf_var   = ch;
       Chbox_sqlite_var  = ch;
}
void MainWindow::on_Database_file_clicked()
{
    if(ui->Database_file->isChecked())
    {
        Database_file_chcedStat(true);
    }
    else
    {
         Database_file_chcedStat(false);
    }
}
void MainWindow::Videows_files_chcedStat(bool ch)
{
     ui->Chbox_asf->setChecked(ch);
     ui->Chbox_amv->setChecked(ch);
     ui->Chbox_avi->setChecked(ch);
     ui->Chbox_mp4->setChecked(ch);
     ui->Chbox_mpg->setChecked(ch);
     ui->Chbox_flv->setChecked(ch);
     ui->Chbox_mxf->setChecked(ch);

        Chbox_asf_var   = ch;
        Chbox_amv_var  = ch;
        Chbox_avi_var   = ch;
        Chbox_mp4_var  = ch;
        Chbox_mpg_var  = ch;
        Chbox_flv_var  = ch;
        Chbox_mxf_var  = ch;
}
void MainWindow::on_Videows_files_clicked()
{
    if(ui->Videows_files->isChecked())
    {
        Videows_files_chcedStat(true);
    }
    else
    {
         Videows_files_chcedStat(false);
    }
}
void MainWindow::Photo_And_Image_chcedStat(bool ch)
{
     ui->Chbox_jpg->setChecked(ch);
     ui->Chbox_mng->setChecked(ch);
     ui->Chbox_png->setChecked(ch);
     ui->Chbox_swf->setChecked(ch);
     ui->Chbox_aep->setChecked(ch);
     ui->Chbox_psd->setChecked(ch);
     ui->Chbox_bmp->setChecked(ch);
     ui->Chbox_gif->setChecked(ch);
     ui->Chbox_ico->setChecked(ch);

       Chbox_jpg_var = ch;
       Chbox_mng_var  = ch;
       Chbox_png_var = ch;
       Chbox_swf_var = ch;
       Chbox_aep_var = ch;
       Chbox_psd_var = ch;
       Chbox_bmp_var  = ch;
       Chbox_gif_var = ch;
       Chbox_ico_var = ch;
}
void MainWindow::on_Photo_And_Image_clicked()
{
    if(ui->Photo_And_Image->isChecked())
    {
        Photo_And_Image_chcedStat(true);
    }
    else
    {
         Photo_And_Image_chcedStat(false);
    }
}
void MainWindow::Music_And_Audio_chcedStat(bool ch)
{
    ui->Chbox_flac->setChecked(ch);
    ui->Chbox_mid->setChecked(ch);
    ui->Chbox_ape->setChecked(ch);
    ui->Chbox_ogg->setChecked(ch);
    ui->Chbox_ra->setChecked(ch);
    ui->Chbox_au->setChecked(ch);
    ui->Chbox_mp3->setChecked(ch);
    ui->Chbox_aif->setChecked(ch);

      Chbox_flac_var  = ch;
      Chbox_mid_var  = ch;
      Chbox_ape_var  = ch;
      Chbox_ogg_var  = ch;
      Chbox_ra_var  = ch;
      Chbox_au_var  = ch;
      Chbox_mp3_var = ch;
      Chbox_aif_var  = ch;

}
void MainWindow::on_Music_And_Audio_clicked()
{
     if(ui->Music_And_Audio->isChecked())
    {
        Music_And_Audio_chcedStat(true);
    }
    else
    {
         Music_And_Audio_chcedStat(false);
    }
}
void MainWindow::Miscellneous_and_camara_chcedStat(bool ch)
{
    ui->Chbox_max->setChecked(ch);
    ui->Chbox_dwg->setChecked(ch);
    ui->Chbox_dxf->setChecked(ch);
    ui->Chbox_eps->setChecked(ch);
    ui->Chbox_fdb->setChecked(ch);
    ui->Chbox_stl->setChecked(ch);
    ui->Chbox_crw->setChecked(ch);
    ui->Chbox_orf->setChecked(ch);
    ui->Chbox_raf->setChecked(ch);
    ui->Chbox_mrw->setChecked(ch);
    ui->Chbox_raw->setChecked(ch);
    ui->Chbox_x3f->setChecked(ch);

      Chbox_max_var   = ch;
      Chbox_dwg_var  = ch;
      Chbox_dxf_var   = ch;
      Chbox_eps_var = ch;
      Chbox_fdb_var  = ch;
      Chbox_stl_var   = ch;
      Chbox_crw_var  = ch;
      Chbox_orf_var  = ch;
      Chbox_raf_var   = ch;
      Chbox_mrw_var  = ch;
      Chbox_raw_var  = ch;
      Chbox_x3f_var  = ch;
}
void MainWindow::on_Miscellneous_and_camara_clicked()
{
    if(ui->Miscellneous_and_camara->isChecked())
   {
        Miscellneous_and_camara_chcedStat(true);
   }
   else
   {
        Miscellneous_and_camara_chcedStat(false);
   }
}

void MainWindow::on_Chbox_All_clicked()
{
    if(ui->Chbox_All->isChecked())
    {
        Microsoft_Office_And_Doc_chcedStat(true);
        Comppress_Archives_chcedStat(true);
        Database_file_chcedStat(true);
         Videows_files_chcedStat(true);
          Photo_And_Image_chcedStat(true);
           Music_And_Audio_chcedStat(true);
             Miscellneous_and_camara_chcedStat(true);

            Chbox_selectAll_var = true;

            ui->Microsoft_Office_And_Doc->setChecked(true);
             ui->Comppress_Archives->setChecked(true);
              ui->Database_file->setChecked(true);
               ui->Videows_files->setChecked(true);
                ui->Photo_And_Image->setChecked(true);
                 ui->Music_And_Audio->setChecked(true);
                  ui->Miscellneous_and_camara->setChecked(true);



    }
    else
    {
         Microsoft_Office_And_Doc_chcedStat(false);
         Comppress_Archives_chcedStat(false);
          Database_file_chcedStat(false);
           Videows_files_chcedStat(false);
            Photo_And_Image_chcedStat(false);
             Music_And_Audio_chcedStat(false);
              Miscellneous_and_camara_chcedStat(false);
               ui->Chbox_All->setChecked(false);

               Chbox_selectAll_var = false;

               ui->Microsoft_Office_And_Doc->setChecked(false);
                ui->Comppress_Archives->setChecked(false);
                 ui->Database_file->setChecked(false);
                  ui->Videows_files->setChecked(false);
                   ui->Photo_And_Image->setChecked(false);
                    ui->Music_And_Audio->setChecked(false);
                     ui->Miscellneous_and_camara->setChecked(false);

    }

}


void MainWindow::on_Chbox_ppt_clicked()
{
    Chbox_ppt_var = ui->Chbox_ppt->isChecked();
}

void MainWindow::on_Chbox_doc_clicked()
{
   Chbox_doc_var = ui->Chbox_doc->isChecked();
}

void MainWindow::on_Chbox_pst_clicked()
{
     Chbox_pst_var = ui->Chbox_pst->isChecked();
}

void MainWindow::on_Chbox_chm_clicked()
{
    Chbox_chm_var = ui->Chbox_chm->isChecked();
}

void MainWindow::on_Chbox_pdf_clicked()
{
    Chbox_pdf_var = ui->Chbox_pdf->isChecked();
}

void MainWindow::on_Chbox_one_clicked()
{
    Chbox_one_var = ui->Chbox_one->isChecked();
}

void MainWindow::on_Chbox_wpd_clicked()
{
     Chbox_wpd_var = ui->Chbox_wpd->isChecked();
}

void MainWindow::on_Chbox_njx_clicked()
{
      Chbox_njx_var = ui->Chbox_njx->isChecked();
}

void MainWindow::on_Chbox_fb2_clicked()
{
     Chbox_fb2_var = ui->Chbox_fb2->isChecked();
}

void MainWindow::on_Chbox_nk2_clicked()
{
    Chbox_nk2_var = ui->Chbox_nk2->isChecked();
}

void MainWindow::on_Chbox_txt_clicked()
{
     Chbox_txt_var = ui->Chbox_txt->isChecked();
}

void MainWindow::on_Chbox_ps_clicked()
{
     Chbox_ps_var = ui->Chbox_ps->isChecked();
}


void MainWindow::on_Chbox_7z_clicked()
{
     Chbox_7z_var = ui->Chbox_7z->isChecked();
}

void MainWindow::on_Chbox_tar_clicked()
{
     Chbox_tar_var = ui->Chbox_tar->isChecked();
}

void MainWindow::on_Chbox_bz2_clicked()
{
    Chbox_bz2_var = ui->Chbox_bz2->isChecked();
}

void MainWindow::on_Chbox_rar_clicked()
{
     Chbox_rar_var = ui->Chbox_rar->isChecked();
}

void MainWindow::on_Chbox_zip_clicked()
{
      Chbox_zip_var = ui->Chbox_zip->isChecked();
}

void MainWindow::on_Chbox_cab_clicked()
{
     Chbox_cab_var = ui->Chbox_ps->isChecked();
}

void MainWindow::on_Chbox_a_clicked()
{
     Chbox_a_var = ui->Chbox_a->isChecked();
}

void MainWindow::on_Chbox_arj_clicked()
{
     Chbox_arj_var = ui->Chbox_arj->isChecked();
}

void MainWindow::on_Chbox_myi_clicked()
{
     Chbox_myi_var = ui->Chbox_myi->isChecked();
}

void MainWindow::on_Chbox_mdb_clicked()
{
     Chbox_mdb_var = ui->Chbox_mdb->isChecked();
}

void MainWindow::on_Chbox_abcdb_clicked()
{
     Chbox_abcdb_var = ui->Chbox_abcdb->isChecked();
}

void MainWindow::on_Chbox_db_clicked()
{
     Chbox_db_var = ui->Chbox_db->isChecked();
}

void MainWindow::on_Chbox_fp7_clicked()
{
     Chbox_fp7_var = ui->Chbox_fp7->isChecked();
}

void MainWindow::on_Chbox_ldf_clicked()
{
     Chbox_ldf_var = ui->Chbox_ldf->isChecked();
}

void MainWindow::on_Chbox_edb_clicked()
{
     Chbox_edb_var = ui->Chbox_edb->isChecked();
}

void MainWindow::on_Chbox_mdf_clicked()
{
     Chbox_mdf_var = ui->Chbox_mdf->isChecked();
}

void MainWindow::on_Chbox_sqlite_clicked()
{
     Chbox_sqlite_var = ui->Chbox_sqlite->isChecked();
}

void MainWindow::on_Chbox_asf_clicked()
{
     Chbox_asf_var = ui->Chbox_asf->isChecked();
}

void MainWindow::on_Chbox_amv_clicked()
{
     Chbox_amv_var = ui->Chbox_amv->isChecked();
}

void MainWindow::on_Chbox_avi_clicked()
{
     Chbox_avi_var = ui->Chbox_avi->isChecked();
}

void MainWindow::on_Chbox_mp4_clicked()
{
     Chbox_mp4_var = ui->Chbox_mp4->isChecked();
}

void MainWindow::on_Chbox_mpg_clicked()
{
     Chbox_mpg_var = ui->Chbox_mpg->isChecked();
}

void MainWindow::on_Chbox_flv_clicked()
{
     Chbox_flv_var = ui->Chbox_flv->isChecked();
}

void MainWindow::on_Chbox_mxf_clicked()
{
     Chbox_mxf_var = ui->Chbox_mxf->isChecked();
}

void MainWindow::on_Chbox_jpg_clicked()
{
     Chbox_jpg_var = ui->Chbox_jpg->isChecked();
}

void MainWindow::on_Chbox_mng_clicked()
{
     Chbox_mng_var = ui->Chbox_mng->isChecked();
}

void MainWindow::on_Chbox_png_clicked()
{
     Chbox_png_var = ui->Chbox_png->isChecked();
}

void MainWindow::on_Chbox_swf_clicked()
{
     Chbox_swf_var = ui->Chbox_swf->isChecked();
}

void MainWindow::on_Chbox_aep_clicked()
{
     Chbox_aep_var = ui->Chbox_aep->isChecked();
}

void MainWindow::on_Chbox_psd_clicked()
{
     Chbox_psd_var = ui->Chbox_psd->isChecked();
}

void MainWindow::on_Chbox_bmp_clicked()
{
     Chbox_bmp_var = ui->Chbox_bmp->isChecked();
}

void MainWindow::on_Chbox_gif_clicked()
{
     Chbox_gif_var = ui->Chbox_gif->isChecked();
}

void MainWindow::on_Chbox_ico_clicked()
{
     Chbox_ico_var = ui->Chbox_ico->isChecked();
}

void MainWindow::on_Chbox_flac_clicked()
{
     Chbox_flac_var = ui->Chbox_flac->isChecked();
}

void MainWindow::on_Chbox_mid_clicked()
{
         Chbox_mid_var = ui->Chbox_mid->isChecked();
}

void MainWindow::on_Chbox_ape_clicked()
{
        Chbox_ape_var = ui->Chbox_ape->isChecked();
}

void MainWindow::on_Chbox_ogg_clicked()
{
       Chbox_ogg_var = ui->Chbox_ogg->isChecked();
}

void MainWindow::on_Chbox_ra_clicked()
{
       Chbox_ra_var = ui->Chbox_ra->isChecked();
}

void MainWindow::on_Chbox_au_clicked()
{
       Chbox_au_var = ui->Chbox_au->isChecked();
}

void MainWindow::on_Chbox_mp3_clicked()
{
      Chbox_mp3_var = ui->Chbox_mp3->isChecked();
}

void MainWindow::on_Chbox_aif_clicked()
{
       Chbox_aif_var = ui->Chbox_aif->isChecked();
}

void MainWindow::on_Chbox_max_clicked()
{
       Chbox_max_var = ui->Chbox_max->isChecked();
}

void MainWindow::on_Chbox_dwg_clicked()
{
       Chbox_dwg_var = ui->Chbox_dwg->isChecked();
}

void MainWindow::on_Chbox_dxf_clicked()
{
       Chbox_dxf_var = ui->Chbox_dxf->isChecked();
}

void MainWindow::on_Chbox_eps_clicked()
{
       Chbox_eps_var = ui->Chbox_eps->isChecked();
}

void MainWindow::on_Chbox_fdb_clicked()
{
      Chbox_fdb_var = ui->Chbox_fdb->isChecked();
}

void MainWindow::on_Chbox_stl_clicked()
{
       Chbox_stl_var = ui->Chbox_stl->isChecked();
}

void MainWindow::on_Chbox_crw_clicked()
{
       Chbox_crw_var = ui->Chbox_crw->isChecked();
}

void MainWindow::on_Chbox_orf_clicked()
{
       Chbox_orf_var = ui->Chbox_orf->isChecked();
}

void MainWindow::on_Chbox_raf_clicked()
{
       Chbox_raf_var = ui->Chbox_raf->isChecked();
}

void MainWindow::on_Chbox_mrw_clicked()
{
       Chbox_mrw_var = ui->Chbox_mrw->isChecked();
}

void MainWindow::on_Chbox_raw_clicked()
{
       Chbox_raw_var = ui->Chbox_raw->isChecked();
}

void MainWindow::on_Chbox_x3f_clicked()
{
       Chbox_x3f_var = ui->Chbox_x3f->isChecked();
}



void MainWindow::on_About_clicked()
{
    QMessageBox::information(this,"About Me"," GOVT. Polytechnic Unnao \n \
                                             Deep Govind  CSE Final Year  - 2015 / 2016 \n\
                                             Email - deepgovind4@gmailo.com  Mo. - 7388966141 \n\
                                          ",MB_OK);
}
