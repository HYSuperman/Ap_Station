#include "command.h"
#include "ui_command.h"
#include <QProcess>
#include <iostream>

Command::Command(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Command)
{
    ui->setupUi(this);
    setable(false);

    externalProcess = new QProcess(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(run_rmmod_sPciDriver()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(run_modprobe_mac80211()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(run_insmod_grt_ko()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(run_ap()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(run_stop_ap()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(run_rmmod_sPciDriver()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(run_rmmod_ath9k()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(run_insmod_grt_ko()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(run_rmmod_grt()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(run_scan_wifi()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(run_make_clean()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(run_make()));
    connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(set()));
    connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(set()));
}

void Command::setable(bool tf){
    ui->pushButton->setEnabled(tf);
    ui->pushButton_2->setEnabled(tf);
    ui->pushButton_3->setEnabled(tf);
    ui->pushButton_4->setEnabled(tf);
    ui->pushButton_5->setEnabled(tf);
    ui->pushButton_6->setEnabled(tf);
    ui->pushButton_7->setEnabled(tf);
    ui->pushButton_8->setEnabled(tf);
    ui->pushButton_9->setEnabled(tf);
    ui->pushButton_10->setEnabled(tf);
    ui->pushButton_11->setEnabled(tf);
    ui->pushButton_12->setEnabled(tf);

}

void Command::set(){
    if(ui->radioButton->isChecked()){prefix = "./GRT_Driver_12.5/";}
    if(ui->radioButton_2->isChecked()){prefix = "./GRT_Driver_20M/";}
    setable(true);
}

void Command::run_rmmod_sPciDriver(){
    QString para = "rmmod " +prefix + "sPciDriver";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start rmmod sPciDriver" << std::endl;
    else
    std::cout << "rmmod sPciDriver started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished rmmod sPciDriver" << std::endl;
    else
        std::cout << "Failed rmmod sPciDriver" << std::endl;
}

void Command::run_modprobe_mac80211(){
    QString para = "modprobe " + prefix + "mac80211";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start modprobe mac80211" << std::endl;
    else
    std::cout << "modprobe mac80211 started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished modprobe mac80211" << std::endl;
    else
        std::cout << "Failed modprobe mac80211" << std::endl;

}
void Command::run_insmod_grt_ko(){
    QString para = "insmod "+prefix +"grt.ko";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start insmod grt.ko" << std::endl;
    else
    std::cout << "insmod grt.ko started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished insmod grt.ko" << std::endl;
    else
        std::cout << "Failed insmod grt.ko" << std::endl;

}
void Command::run_ap(){
    QString para = prefix + "run_ap.sh";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start run_ap.sh" << std::endl;
    else
        std::cout << "run_ap.sh started" << std::endl;
}
void Command::run_stop_ap(){
    if(externalProcess->state() == QProcess::Running){
        externalProcess->close();
        std::cout << "Stopped run_ap" << std::endl;
    }
    else
        std::cout << "Nothing is running" << std::endl;
}
void Command::run_rmmod_ath9k(){
    QString para = "rmmod " + prefix + "ath9k";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start rmmod ath9k" << std::endl;
    else
    std::cout << "rmmod ath9k started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished rmmod ath9k" << std::endl;
    else
        std::cout << "Failed rmmod ath9k" << std::endl;

}
void Command::run_rmmod_grt(){
    QString para = "rmmod "+ prefix + "grt";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start rmmod grt" << std::endl;
    else
    std::cout << "rmmod grt started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished rmmod grt" << std::endl;
    else
        std::cout << "Failed rmmod grt" << std::endl;

}
void Command::run_scan_wifi(){
    QString para = "iw wlan0 scan";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start iw wlan0 scan" << std::endl;
    else
    std::cout << "iw wlan0 scan started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished iw wlan0 scan" << std::endl;
    else
        std::cout << "Failed iw wlan0 scan" << std::endl;

}
void Command::run_make_clean(){
    QString para = "make -C " + prefix + " clean";
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start make clean" << std::endl;
    else
    std::cout << "make clean started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished make clean" << std::endl;
    else
        std::cout << "Failed make clean" << std::endl;

}
void Command::run_make(){
    QString para = "make -C " + prefix;
    externalProcess->start(para);
    if(!externalProcess->waitForStarted())
        std::cout << "Failed to start make" << std::endl;
    else
    std::cout << "make started" << std::endl;
    if(externalProcess->waitForFinished())
        std::cout << "Finished make" << std::endl;
    else
        std::cout << "Failed make" << std::endl;

}

Command::~Command()
{
    delete ui;
}
