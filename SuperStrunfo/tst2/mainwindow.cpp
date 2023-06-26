#include "mainwindow.h"
#include "qapplication.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    btnJogar = new QPushButton("Jogar", this);
    btnJogar->setGeometry(10, 10, 80, 30);
    connect(btnJogar, SIGNAL(clicked()), this, SLOT(jogar()));

    btnSair = new QPushButton("Sair", this);
    btnSair->setGeometry(100, 10, 80, 30);
    connect(btnSair, SIGNAL(clicked()), this, SLOT(sair()));

    jogadorWidget = nullptr;

    // Criar layout vertical para widgets
    QVBoxLayout* layout = new QVBoxLayout();
    setCentralWidget(new QWidget(this));
    centralWidget()->setLayout(layout);

    // Add botões ao layout
    layout->addWidget(btnJogar);
    layout->addWidget(btnSair);

}

void MainWindow::jogar() {
    // Esconder botões jogar e sair
    btnJogar->hide();
    btnSair->hide();

    // Criar o JogadorWidget
    jogadorWidget = new JogadorWidget(this);
    jogadorWidget->criarDeck("Paises.csv"); // ainda não funciona com CSV, apenas se colocar o arquivo na pasta raiz junto ao MAKEFILE ou utilizando caminho direto
    jogadorWidget->criarmãos();
    jogadorWidget->lerCarta1();
    setCentralWidget(jogadorWidget);

    // Conectar o sinal destroyed() ao slot jogadorWidgetFechado()
    connect(jogadorWidget, SIGNAL(destroyed(QObject*)), this, SLOT(jogadorWidgetFechado()));
}

void MainWindow::jogadorWidgetFechado() {
    // Exibir os botões jogar e sair novamente, não esta funcionando ainda
    btnJogar->show();
    btnSair->show();

    qDebug() << "O sinal destroyed() foi emitido pelo jogadorWidget.";
}

void MainWindow::sair() {
    QApplication::quit();
}
