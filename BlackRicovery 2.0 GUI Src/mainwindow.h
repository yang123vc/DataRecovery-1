#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <process.h>
#include <windows.h>


#define Open1  1
#define Close1 0

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{

     Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  void Add_Recover_Items();
  void Write_Percent();
 void  RecoverSelectedItems();


private slots:

    void on_StylePannalButton_clicked();

    void on_SStyleCombo_activated(const QString &StyleName);

    void on_SStyleSheetCombo_activated(const QString &StyleName);

    void on_DrivePanalButton_clicked();

    void on_DriveListCombo_activated(const QString &arg1);


    void on_RecoverItems_clicked();

    void on_ExportInDrive_clicked();



    void on_FileExtPanalButton_clicked();

    void on_Microsoft_Office_And_Doc_clicked();

     void on_StartRecovery_clicked();

    void on_Comppress_Archives_clicked();

    void on_Database_file_clicked();

    void on_Videows_files_clicked();

    void on_Photo_And_Image_clicked();

    void on_Music_And_Audio_clicked();

    void on_Miscellneous_and_camara_clicked();


    void on_Chbox_All_clicked();

    void on_RecoverBack_clicked();

    void on_Chbox_ppt_clicked();

    void on_Chbox_doc_clicked();

    void on_Chbox_pst_clicked();

    void on_Chbox_chm_clicked();

    void on_Chbox_pdf_clicked();

    void on_Chbox_one_clicked();

    void on_Chbox_wpd_clicked();

    void on_Chbox_njx_clicked();

    void on_Chbox_fb2_clicked();

    void on_Chbox_nk2_clicked();

    void on_Chbox_txt_clicked();

    void on_Chbox_ps_clicked();


    void on_ImportDetails_clicked();

    void on_Chbox_7z_clicked();

    void on_Chbox_tar_clicked();

    void on_Chbox_bz2_clicked();

    void on_Chbox_rar_clicked();

    void on_Chbox_zip_clicked();

    void on_Chbox_cab_clicked();

    void on_Chbox_a_clicked();

    void on_Chbox_arj_clicked();

    void on_Chbox_myi_clicked();

    void on_Chbox_mdb_clicked();

    void on_Chbox_abcdb_clicked();

    void on_Chbox_db_clicked();

    void on_Chbox_fp7_clicked();

    void on_Chbox_ldf_clicked();

    void on_Chbox_edb_clicked();

    void on_Chbox_mdf_clicked();

    void on_Chbox_sqlite_clicked();

    void on_Chbox_asf_clicked();

    void on_Chbox_amv_clicked();

    void on_Chbox_avi_clicked();

    void on_Chbox_mp4_clicked();

    void on_Chbox_mpg_clicked();

    void on_Chbox_flv_clicked();

    void on_Chbox_mxf_clicked();

    void on_Chbox_jpg_clicked();

    void on_Chbox_mng_clicked();

    void on_Chbox_png_clicked();

    void on_Chbox_swf_clicked();

    void on_Chbox_aep_clicked();

    void on_Chbox_psd_clicked();

    void on_Chbox_bmp_clicked();

    void on_Chbox_gif_clicked();

    void on_Chbox_ico_clicked();

    void on_Chbox_flac_clicked();

    void on_Chbox_mid_clicked();

    void on_Chbox_ape_clicked();

    void on_Chbox_ogg_clicked();

    void on_Chbox_ra_clicked();

    void on_Chbox_au_clicked();

    void on_Chbox_mp3_clicked();

    void on_Chbox_aif_clicked();

    void on_Chbox_max_clicked();

    void on_Chbox_dwg_clicked();

    void on_Chbox_dxf_clicked();

    void on_Chbox_eps_clicked();

    void on_Chbox_fdb_clicked();

    void on_Chbox_stl_clicked();

    void on_Chbox_crw_clicked();

    void on_Chbox_orf_clicked();

    void on_Chbox_raf_clicked();

    void on_Chbox_mrw_clicked();

    void on_Chbox_raw_clicked();

    void on_Chbox_x3f_clicked();


    void on_SeectAllCh_clicked();

    void on_About_clicked();

private:
     void loadStyleSheet(const QString &sheetName);
     void SetStyleSheet();
     void SWriteFile();
     void  SReadFile();
     void SetPanalDuretionTime(int Mics);
     void GetDrive();
     int  dGetFreeSize(QString Drive);
     QString GetDriveName(QString Drive);

     void  Microsoft_Office_And_Doc_chcedStat(bool ch);
     void  Miscellneous_and_camara_chcedStat(bool ch);
     void  Music_And_Audio_chcedStat(bool ch);
     void  Photo_And_Image_chcedStat(bool ch);
     void  Videows_files_chcedStat(bool ch);
     void  Database_file_chcedStat(bool ch);
     void  Comppress_Archives_chcedStat(bool ch);
     void  RecoverItems(QString i);

      Ui::MainWindow *ui;

     int StylePanalStatus,DriveListStatus ,FileExtentionPanalStatus;
     QPropertyAnimation PA,PA1,PA2;

     QString SStyleSheet,SStyleSheetName;



 void highlightChecked(QListWidgetItem* item);
 void save();


};

#endif // MAINWINDOW_H
