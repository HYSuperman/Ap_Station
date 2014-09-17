#ifndef COMMAND_H
#define COMMAND_H

#include <QDialog>

class QProcess;
class QPushButton;

namespace Ui {
class Command;
}

class Command : public QDialog
{
    Q_OBJECT

public:
    explicit Command(QWidget *parent = 0);
    ~Command();


private slots:
    void run_rmmod_sPciDriver();
    void run_modprobe_mac80211();
    void run_insmod_grt_ko();
    void run_ap();
    void run_stop_ap();
    void run_rmmod_ath9k();
    void run_rmmod_grt();
    void run_scan_wifi();
    void run_make_clean();
    void run_make();

    void set();

private:
    Ui::Command *ui;
    QProcess *externalProcess;
    QString prefix;
    void setable(bool tf);
};

#endif // COMMAND_H
