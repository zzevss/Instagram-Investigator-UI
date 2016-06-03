#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <curl/curl.h>
#include <fstream>
#include <lisrurlbase.h>
#include <QMessageBox>
#include <QUrl>
#include <addurllist.h>
#include <coutoldurls.h>








using namespace std;

/* the function to invoke as the data recieved */
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_getButt_clicked()
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    QString tmpStr;

    curl = curl_easy_init();
    ui->pushButtAnalize->setDisabled(false);
    char outfilename[FILENAME_MAX] = "buffer.str";

    if(curl)
    {
    //"https://api.instagram.com/v1/users/3124248220/media/recent/?access_token=3124248220.1677ed0.d02014c9e9a14235bbb83d1bca2717e7"

    tmpStr = ui->lineEdit->text();

    //maska dlja url validation
    QUrl url = QUrl::fromEncoded(tmpStr.toStdString().c_str());
    if(url.isValid())
    {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, tmpStr.toStdString().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
        ui->plainTextEdit->clear();
        ui->plainTextEdit->appendPlainText("Get Request \n");
        ui->plainTextEdit->appendPlainText("Request done successful!!!");
    }
    else if(!url.isValid())
        {
            ui->plainTextEdit->appendPlainText("Invalid URL");
        }
    }
}

void MainWindow::on_pushButtAnalize_clicked()
{

    FILE *file = fopen("buffer.str","rb+");

    int firstCountUrlDB = 0;
    int lastCountUrlDB = 0;

    long size = 0;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, 0);

    char *pstr = new char[size + 1];


    std::string str;
    fread(pstr,1,size,file);

    str = pstr;

    int startPos = 0;
    int index = 0;
    std::vector<std::string> _vector;
    while(index != std::string::npos)
    {
        index = str.find("standard_resolution", startPos);
        if(index != std::string::npos)
        {
            int i1;
            int i2;
            i1 = str.find("https", index);
            i2 = str.find(".2\"", index);

            _vector.push_back(str.substr(i1,i2 - i1 + 2));
            startPos = i2;
        }
    }

    ui->plainTextEdit->appendPlainText("Image ADDRESS: \n");

    //cout URLS in DB file
    firstCountUrlDB = countUrlsBase();

    addUrl(_vector);

    lastCountUrlDB = countUrlsBase();

    QString countNewUrl = QString::number(lastCountUrlDB - firstCountUrlDB);



    ui->plainTextEdit->appendPlainText("Find new URLs: ");
    ui->plainTextEdit->appendPlainText(countNewUrl);

    ui->pushButtAnalize->setDisabled(true);

    fclose(file);

}





void MainWindow::on_cancelButton_clicked()
{
    this->close();
}
