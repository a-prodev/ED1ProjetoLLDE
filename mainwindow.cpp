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
QString elementoRetirado = "(vazio)";
int i;
bool ok;

void MainWindow::on_pushButtonInserirInicio_clicked()
{
    int valor = QInputDialog::getInt(this,"Inserção no Inicio","Insira um valor:",0,-2147483647,2147483647,1, &ok);

    while (ok){
    lista.inserirInicio(valor);

    saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
            "\nValor do último elemento removido: " + QString(elementoRetirado) +
            "\nValores dos elementos inseridos: ";
    for(i = 0; i < lista.getQuantidade(); i++)
        saida += QString::number(lista[i + 1]) + ", ";
    ui->textEditResultado->setText(saida);
    saida = "";
    valor = QInputDialog::getInt(this,"Inserção no Inicio","Insira um valor:",0,-2147483647,2147483647,1, &ok);
    }

    if (lista.getQuantidade() > 0){
    saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
            "\nValor do último elemento removido: " + QString(elementoRetirado) +
            "\nValores dos elementos inseridos: ";
    for(i = 1; i < lista.getQuantidade(); i++)
        saida += QString::number(lista[i]) + ", ";
    saida += QString::number(lista[i]) + ".";
    ui->textEditResultado->setText(saida);
    }
}

void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try {
        int elemento = lista.retirarInicio();

        saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
                "\nValor do último elemento removido: " + QString::number(elemento) +
                "\nValores dos elementos inseridos: ";
        if (lista.getQuantidade() > 0){
        for(i = 1; i < lista.getQuantidade(); i++)
            saida += QString::number(lista[i]) + ", ";
        saida += QString::number(lista[i]) + ".";
        ui->textEditResultado->setText(saida);
        } else {
            saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
                    "\nValor do último elemento removido: " + QString::number(elemento) +
                    "\nValores dos elementos inseridos: (vazio)";
            ui->textEditResultado->setText(saida);            
        }
        elementoRetirado = QString::number(elemento);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO NO PROGRAMA",erro);
    }
}

void MainWindow::on_pushButtonInserirFim_clicked()
{
    int valor = QInputDialog::getInt(this,"Inserção no Inicio","Insira um valor:",0,-2147483647,2147483647,1, &ok);

    while (ok){
    lista.inserirFim(valor);

    saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
            "\nValor do último elemento removido: " + QString(elementoRetirado) +
            "\nValores dos elementos inseridos: ";
    for(i = 0; i < lista.getQuantidade(); i++)
        saida += QString::number(lista[i + 1]) + ", ";
    ui->textEditResultado->setText(saida);
    saida = "";
    valor = QInputDialog::getInt(this,"Inserção no Inicio","Insira um valor:",0,-2147483647,2147483647,1, &ok);
    }

    if (lista.getQuantidade() > 0){
    saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
            "\nValor do último elemento removido: " + QString(elementoRetirado) +
            "\nValores dos elementos inseridos: ";
    for(i = 1; i < lista.getQuantidade(); i++)
        saida += QString::number(lista[i]) + ", ";
    saida += QString::number(lista[i]) + ".";
    ui->textEditResultado->setText(saida);
    }
}

void MainWindow::on_pushButtonRetirarFim_clicked()
{
    try {
        int elemento = lista.retirarFim();

        saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
                "\nValor do último elemento removido: " + QString::number(elemento) +
                "\nValores dos elementos inseridos: ";
        if (lista.getQuantidade() > 0){
        for(i = 1; i < lista.getQuantidade(); i++)
            saida += QString::number(lista[i]) + ", ";
        saida += QString::number(lista[i]) + ".";
        ui->textEditResultado->setText(saida);
        } else {
            saida = "Quantidade de elementos: " + QString::number(lista.getQuantidade()) +
                    "\nValor do último elemento removido: " + QString::number(elemento) +
                    "\nValores dos elementos inseridos: (vazio)";
            ui->textEditResultado->setText(saida);
        }
        elementoRetirado = QString::number(elemento);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO NO PROGRAMA",erro);
    }
}

void MainWindow::on_pushButtonAcessarValor_clicked()
{
    try {
        int valor = QInputDialog::getInt(this,"Acessar valor espec...","Posição:",0,-2147483647,2147483647,1, &ok);
        if (ok){
            saida = "Valor do elemento na Posição \"" + QString::number(valor) + "\" = " + QString::number(lista[valor]) +
                    "\nQuantidade de elementos: " + QString::number(lista.getQuantidade()) +
                    "\nValor do último elemento removido: " + QString(elementoRetirado) +
                    "\nValores dos elementos inseridos: ";
            for(i = 1; i < lista.getQuantidade(); i++)
                saida += QString::number(lista[i]) + ", ";
            saida += QString::number(lista[i]) + ".";
            ui->textEditResultado->setText(saida);
        }
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO NO PROGRAMA",erro);
    }
}
