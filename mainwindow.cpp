#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

jose::LLDE lista;


QString saida;
int i;
bool ok;

void MainWindow::on_pushButtonInserirInicio_clicked()
{
    int valor = QInputDialog::getInt(this,"Inserção no Inicio","Insira um valor:",0,-2147483647,2147483647,1, &ok);
    do{    
    lista.inserirInicio(valor);

    saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
            "\nValor do elemento removido: \nValores dos elementos inseridos: ";
    for(i = 0; i < lista.getQuantidade(); i++)
        saida += QString::number(lista[i + 1]) + ", ";
    ui->textEditResultado->setText(saida);
    saida = "";
    valor = QInputDialog::getInt(this,"Inserção no Inicio","Insira um valor:",0,-2147483647,2147483647,1, &ok);
    } while (ok);

    saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
            "\nValor do elemento removido: \nValores dos elementos inseridos: ";
    for(i = 1; i < lista.getQuantidade(); i++)
        saida += QString::number(lista[i]) + ", ";
    saida += QString::number(lista[i]) + ".";
    ui->textEditResultado->setText(saida);
}

void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try {
        int valor = lista.retirarInicio();

        saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
                "\nValor do elemento removido: " + QString::number(valor) +
                "\nValores dos elementos inseridos: ";
        if (lista.getQuantidade() > 0){
        for(i = 1; i < lista.getQuantidade(); i++)
            saida += QString::number(lista[i]) + ", ";
        saida += QString::number(lista[i]) + ".";
        ui->textEditResultado->setText(saida);
        } else {
            saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
                    "\nValor do elemento removido: " + QString::number(valor) +
                    "\nValores dos elementos inseridos: ";
            ui->textEditResultado->setText(saida);
        }
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO NO PROGRAMA",erro);
    }
}
