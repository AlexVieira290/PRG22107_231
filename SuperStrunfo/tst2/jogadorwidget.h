#ifndef JOGADORWIDGET_H
#define JOGADORWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QGridLayout>
#include <QFrame>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <string>
#include <fstream>
#include <iostream>
#include "deck.h"
#include "carta.h"

class JogadorWidget : public QWidget {
    Q_OBJECT

public:
    JogadorWidget(QWidget* parent = nullptr);
    void criarDeck(const std::string& caminhoArquivoCSV);
    void criarmãos();
    void lerCarta();
    void lerCarta1();
    void lerCarta2();


private slots:
    void desafiar();
    void proximo();
    void ApagarCarta1();
    void ApagarCarta2();
    void SetupJogadores(QHBoxLayout* gameLayout);
    void Jogador1_recebecartas();
    void Jogador2_recebecartas();
    void Limparcheckbox();

private:
    QVBoxLayout* cartaLayout1;
    QVBoxLayout* cartaLayout2;
    QLabel* cartaImagem1;
    QLabel* cartaImagem2;
    QLabel* lblJogador1;
    QLabel* lblJogador2;
    QLabel* lblCartasDeck1;
    QLabel* lblCartasDeck2;
    QLabel* lblNomeCarta1;
    QLabel* lblNomeCarta2;
    QLabel* lblNomeCarta1ID;
    QLabel* lblNomeCarta2ID;
    QLabel* lblValorAtributos1[5];
    QLabel* lblValorAtributos2[5];
    QCheckBox* chkAtributos1[5];
    QCheckBox* chkAtributos2[5];
    QGroupBox* supertrunfoGroupBox1;
    QGroupBox* supertrunfoGroupBox2;
    QPushButton* btnDesafiar1;
    QPushButton* btnProximo1;
    QPushButton* btnDesafiar2;
    QPushButton* btnProximo2;
    QGridLayout* layout;
    Carta primeiraCarta_1;
    Carta primeiraCarta_2;
    Deck hand1;
    Deck hand2;
    Deck deck;

};

#endif // JOGADORWIDGET_H
