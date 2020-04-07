#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <llde.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonInserirFim_clicked();

    void on_pushButtonRetirarFim_clicked();

    void on_pushButtonAcessarValor_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
