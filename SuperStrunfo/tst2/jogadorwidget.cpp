#include "jogadorwidget.h"
#include <QString>

JogadorWidget::JogadorWidget(QWidget* parent)
    : QWidget(parent) {

    // Layouts
    QHBoxLayout* gameLayout = new QHBoxLayout;

    SetupJogadores(gameLayout);

    setLayout(gameLayout);

    //Conectar sinais aos slots
    for (int i = 0; i < 5; i++) {
        connect(chkAtributos1[i], &QCheckBox::stateChanged, this, [=](int state) {
            if (state == Qt::Checked) {
                // Marcar o checkbox correspondente do jogador 2
                chkAtributos2[i]->setChecked(true);
                for (int j = 0; j < 5; j++) {
                    if (j != i) {
                        chkAtributos1[j]->setEnabled(false);
                    }
                }
            } else {
                // Desmarcar o checkbox correspondente do jogador 2
                chkAtributos2[i]->setChecked(false);
                for (int j = 0; j < 5; j++) {
                    chkAtributos1[j]->setEnabled(true);
                    chkAtributos2[j]->setEnabled(true);
                }
            }
        });
    }
    for (int i = 0; i < 5; i++) {
        connect(chkAtributos2[i], &QCheckBox::stateChanged, this, [=](int state) {
            if (state == Qt::Checked) {
                // Marcar o checkbox correspondente do jogador 1
                chkAtributos1[i]->setChecked(true);
                for (int j = 0; j < 5; j++) {
                    if (j != i) {
                        chkAtributos2[j]->setEnabled(false);
                    }
                }
            } else {
                // Desmarcar o checkbox correspondente do jogador 1
                chkAtributos1[i]->setChecked(false);
                for (int j = 0; j < 5; j++) {
                    chkAtributos1[j]->setEnabled(true);
                    chkAtributos2[j]->setEnabled(true);
                }
            }
        });
    }

    connect(btnDesafiar1, SIGNAL(clicked()), this, SLOT(desafiar()));
    connect(btnDesafiar2, SIGNAL(clicked()), this, SLOT(desafiar()));
    connect(btnProximo1, SIGNAL(clicked()), this, SLOT(proximo()));
    connect(btnProximo2, SIGNAL(clicked()), this, SLOT(proximo()));
}

void JogadorWidget::criarDeck(const std::string& caminhoArquivoCSV) {
    deck = Deck("Baralho", caminhoArquivoCSV); // Cria um deck
    deck.embaralharCartas();
}

void JogadorWidget::criarmãos() {
    hand1 = Deck();
    hand2 = Deck();
    deck.distribuirCartas(hand1, hand2);
}

void JogadorWidget::desafiar() {

    // Lógica desafio
    for (int i = 0; i < 5; i++) {
        if (chkAtributos1[i]->isChecked()) {
            if (btnDesafiar1->isEnabled() && !btnProximo1->isEnabled()) {
                btnDesafiar1->setEnabled(false);
                btnProximo1->setEnabled(true);
                lerCarta();
            } else if (btnDesafiar2->isEnabled() && !btnProximo2->isEnabled()){
                btnDesafiar2->setEnabled(false);
                btnProximo2->setEnabled(true);
                lerCarta();
            }
        }
    }
}

void JogadorWidget::proximo() {
    // Lógica de conferir jogada do jogador 2 ???
    if((lblJogador1->text() =="Jogador 1 Venceu") || (lblJogador2->text() =="Jogador 2 Venceu") ){
        close();
    }

    if((lblNomeCarta1ID->text() =="1B")){               //Verificar se jogador 1 possui supertrunfo e se jogador 2 possuia cartas "XA"
        if (lblNomeCarta2ID->text() != "1A" || lblNomeCarta2ID->text() != "2A" || lblNomeCarta2ID->text() != "3A" || lblNomeCarta2ID->text() != "4A" ||
            lblNomeCarta2ID->text() != "5A" || lblNomeCarta2ID->text() != "6A" || lblNomeCarta2ID->text() != "7A" || lblNomeCarta2ID->text() != "8A"){
            Jogador1_recebecartas();
            lerCarta1();
            QMessageBox::information(nullptr, "Supertrunfo", "Jogador 1 Venceu");
        }
    }else if (lblNomeCarta2ID->text() =="1B"){          //Verificar se jogador 2 possui supertrunfo e se jogador 1 possuia cartas "XA"
        if (lblNomeCarta1ID->text() != "1A" || lblNomeCarta1ID->text() != "2A" || lblNomeCarta1ID->text() != "3A" || lblNomeCarta1ID->text() != "4A" ||
            lblNomeCarta1ID->text() != "5A" || lblNomeCarta1ID->text() != "6A" || lblNomeCarta1ID->text() != "7A" || lblNomeCarta1ID->text() != "8A"){
            Jogador2_recebecartas();
            lerCarta2();
            QMessageBox::information(nullptr, "Supertrunfo", "Jogador 2 Venceu");
        }
    }else{
        for (int i = 0; i < 5; i++) {
            if (chkAtributos1[i]->isChecked()) {
                switch(i) {
                case 0:
                    if (primeiraCarta_1.getAtributo1().getValor() > primeiraCarta_2.getAtributo1().getValor()) {
                        // Valor do atributo do jogador 1 é maior, mover ambas as cartas para hand1
                        Jogador1_recebecartas();
                        lerCarta1();
                    } else {
                        // Valor do atributo do jogador 2 é maior ou igual, mover ambas as cartas para hand2
                        Jogador2_recebecartas();
                        lerCarta2();
                    }
                    break;
                case 1:
                    if (primeiraCarta_1.getAtributo2().getValor() > primeiraCarta_2.getAtributo2().getValor()) {
                        // Valor do atributo do jogador 1 é maior, mover ambas as cartas para hand1
                        Jogador1_recebecartas();
                        lerCarta1();
                    } else {
                        // Valor do atributo do jogador 2 é maior ou igual, mover ambas as cartas para hand2
                        Jogador2_recebecartas();
                        lerCarta2();
                    }
                    break;
                case 2:
                    if (primeiraCarta_1.getAtributo3().getValor() > primeiraCarta_2.getAtributo3().getValor()) {
                        // Valor do atributo do jogador 1 é maior, mover ambas as cartas para hand1
                        Jogador1_recebecartas();
                        lerCarta1();
                    } else {
                        // Valor do atributo do jogador 2 é maior ou igual, mover ambas as cartas para hand2
                        Jogador2_recebecartas();
                        lerCarta2();
                    }
                    break;
                case 3:
                    if (primeiraCarta_1.getAtributo4().getValor() > primeiraCarta_2.getAtributo4().getValor()) {
                        // Valor do atributo do jogador 1 é maior, mover ambas as cartas para hand1
                        Jogador1_recebecartas();
                        lerCarta1();
                    } else {
                        // Valor do atributo do jogador 2 é maior ou igual, mover ambas as cartas para hand2
                        Jogador2_recebecartas();
                        lerCarta2();
                    }
                    break;
                case 4:
                    if (primeiraCarta_1.getAtributo5().getValor() > primeiraCarta_2.getAtributo5().getValor()) {
                        // Valor do atributo do jogador 1 é maior, mover ambas as cartas para hand1
                        Jogador1_recebecartas();
                        lerCarta1();
                    } else {
                        // Valor do atributo do jogador 2 é maior ou igual, mover ambas as cartas para hand2
                        Jogador2_recebecartas();
                        lerCarta2();
                    }
                    break;
                default:
                    break;
                }
                Limparcheckbox();
            }
        }
    }
}

void JogadorWidget::lerCarta() {
    float temp;
    QString temp_string;

    if (btnProximo2->isEnabled()) {
        lblNomeCarta1->setText(QString::fromStdString(primeiraCarta_1.getNome()));
        lblNomeCarta1ID->setText(QString::fromStdString(primeiraCarta_1.getID()));
        temp_string = ":/csv/" + QString::fromStdString(primeiraCarta_1.getID()) + ".PNG";
        QPixmap pixmap(temp_string);
        QPixmap scaledPixmap = pixmap.scaled(cartaImagem1->size());
        cartaImagem1->setPixmap(scaledPixmap);
        for (int i = 0; i < 5; i++) {
            chkAtributos1[i]->setText(QString::fromStdString(primeiraCarta_1.getAtributo(i).getNome()));
            temp = primeiraCarta_1.getAtributo(i).getValor();
            temp_string = QString::number(temp, 'f', 1);
            lblValorAtributos1[i]->setText( temp_string);
        }
    }

    if (btnProximo1->isEnabled()) {
        lblNomeCarta2->setText(QString::fromStdString(primeiraCarta_2.getNome()));
        lblNomeCarta2ID->setText(QString::fromStdString(primeiraCarta_2.getID()));
        temp_string = ":/csv/" + QString::fromStdString(primeiraCarta_2.getID()) + ".PNG";
        QPixmap pixmap(temp_string);
        QPixmap scaledPixmap = pixmap.scaled(cartaImagem2->size());
        cartaImagem2->setPixmap(scaledPixmap);
        for (int i = 0; i < 5; i++) {
            chkAtributos2[i]->setText(QString::fromStdString(primeiraCarta_2.getAtributo(i).getNome()));
            temp = primeiraCarta_2.getAtributo(i).getValor();
            temp_string = QString::number(temp, 'f', 1);
            lblValorAtributos2[i]->setText( temp_string);
        }
    }
}

void JogadorWidget::lerCarta1() {
    float temp;
    QString temp_string;

    if (!hand2.vazio()) {
        // pegar a primeira carta
        primeiraCarta_1 = hand1.removerCarta();
        primeiraCarta_2 = hand2.removerCarta();

        // ler Informações das cartas
        temp = hand1.getTamanho()+1;
        temp_string = "Cartas:" + QString::number(temp, 'f', 0);
        lblCartasDeck1->setText(temp_string);
        temp = hand2.getTamanho()+1;
        temp_string = "Cartas:" + QString::number(temp, 'f', 0);
        lblCartasDeck2->setText(temp_string);

        lblNomeCarta1->setText(QString::fromStdString(primeiraCarta_1.getNome()));
        lblNomeCarta1ID->setText(QString::fromStdString(primeiraCarta_1.getID()));
        temp_string = ":/csv/" + QString::fromStdString(primeiraCarta_1.getID()) + ".PNG";
        QPixmap pixmap(temp_string);
        QPixmap scaledPixmap = pixmap.scaled(cartaImagem1->size());
        cartaImagem1->setPixmap(scaledPixmap);
        for (int i = 0; i < 5; i++) {
            chkAtributos1[i]->setText(QString::fromStdString(primeiraCarta_1.getAtributo(i).getNome()));
            temp = primeiraCarta_1.getAtributo(i).getValor();
            temp_string = QString::number(temp, 'f', 1);
            lblValorAtributos1[i]->setText( temp_string);
        }
        //criado get atributo para permitir a utilização do laço for ()
        /*chkAtributos1[0]->setText(QString::fromStdString(primeiraCarta_1.getAtributo1().getNome()));
        chkAtributos1[1]->setText(QString::fromStdString(primeiraCarta_1.getAtributo2().getNome()));
        chkAtributos1[2]->setText(QString::fromStdString(primeiraCarta_1.getAtributo3().getNome()));
        chkAtributos1[3]->setText(QString::fromStdString(primeiraCarta_1.getAtributo4().getNome()));
        chkAtributos1[4]->setText(QString::fromStdString(primeiraCarta_1.getAtributo5().getNome()));
        temp = primeiraCarta_1.getAtributo1().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos1[0]->setText( temp_string);
        temp = primeiraCarta_1.getAtributo2().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos1[1]->setText( temp_string);
        temp = primeiraCarta_1.getAtributo3().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos1[2]->setText(temp_string);
        temp = primeiraCarta_1.getAtributo4().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos1[3]->setText( temp_string);
        temp = primeiraCarta_1.getAtributo5().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos1[4]->setText( temp_string);*/
    }else {
        ApagarCarta1();
        ApagarCarta2();
        cartaImagem1->setPixmap(QPixmap(":/csv/Duck1.PNG"));
        lblJogador1->setText("Jogador 1 Venceu");
        btnDesafiar1->setEnabled(false);
        btnProximo1->setEnabled(true);

    }

}

void JogadorWidget::lerCarta2() {
    float temp;
    QString temp_string;

    if (!hand1.vazio()) {
        // pegar a primeira carta
        primeiraCarta_1 = hand1.removerCarta();
        primeiraCarta_2 = hand2.removerCarta();

        // ler Informações das cartas
        temp = hand1.getTamanho()+1;
        temp_string = "Cartas:" + QString::number(temp, 'f', 0);
        lblCartasDeck1->setText(temp_string);
        temp = hand2.getTamanho()+1;
        temp_string = "Cartas:" + QString::number(temp, 'f', 0);
        lblCartasDeck2->setText(temp_string);

        lblNomeCarta2->setText(QString::fromStdString(primeiraCarta_2.getNome()));
        lblNomeCarta2ID->setText(QString::fromStdString(primeiraCarta_2.getID()));
        temp_string = ":/csv/" + QString::fromStdString(primeiraCarta_2.getID()) + ".PNG";
        QPixmap pixmap(temp_string);
        QPixmap scaledPixmap = pixmap.scaled(cartaImagem2->size());
        cartaImagem2->setPixmap(scaledPixmap);
        for (int i = 0; i < 5; i++) {
            chkAtributos2[i]->setText(QString::fromStdString(primeiraCarta_2.getAtributo(i).getNome()));
            temp = primeiraCarta_2.getAtributo(i).getValor();
            temp_string = QString::number(temp, 'f', 1);
            lblValorAtributos2[i]->setText( temp_string);
        }
        //criado get atributo para permitir a utilização do laço for ()
        /*chkAtributos2[0]->setText(QString::fromStdString(primeiraCarta_2.getAtributo1().getNome()));
        chkAtributos2[1]->setText(QString::fromStdString(primeiraCarta_2.getAtributo2().getNome()));
        chkAtributos2[2]->setText(QString::fromStdString(primeiraCarta_2.getAtributo3().getNome()));
        chkAtributos2[3]->setText(QString::fromStdString(primeiraCarta_2.getAtributo4().getNome()));
        chkAtributos2[4]->setText(QString::fromStdString(primeiraCarta_2.getAtributo5().getNome()));
        temp = primeiraCarta_2.getAtributo1().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos2[0]->setText( temp_string);
        temp = primeiraCarta_2.getAtributo2().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos2[1]->setText( temp_string);
        temp = primeiraCarta_2.getAtributo3().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos2[2]->setText(temp_string);
        temp = primeiraCarta_2.getAtributo4().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos2[3]->setText( temp_string);
        temp = primeiraCarta_2.getAtributo5().getValor();
        temp_string = QString::number(temp, 'f', 1);
        lblValorAtributos2[4]->setText( temp_string);*/
    }else {
        ApagarCarta1();
        ApagarCarta2();
        cartaImagem2->setPixmap(QPixmap(":/csv/Duck2.PNG"));
        lblJogador2->setText("Jogador 2 Venceu");
        btnDesafiar2->setEnabled(false);
        btnProximo2->setEnabled(true);
    }
}

void JogadorWidget::ApagarCarta1() {
    lblNomeCarta1->setText(" ");
    lblNomeCarta1ID->setText(" ");
    cartaImagem1->setPixmap(QPixmap(" "));
    for (int i = 0; i < 5; i++) {
        lblValorAtributos1[i]->setText(" ");
    }
}

void JogadorWidget::ApagarCarta2() {
    lblNomeCarta2->setText(" ");
    lblNomeCarta2ID->setText(" ");
    cartaImagem2->setPixmap(QPixmap(" "));
    for (int i = 0; i < 5; i++) {
        lblValorAtributos2[i]->setText(" ");
    }
}

void JogadorWidget::SetupJogadores(QHBoxLayout* gameLayout) {
    // Informações do jogador
    lblJogador1 = new QLabel("Jogador 1");
    lblJogador2 = new QLabel("Jogador 2");
    lblCartasDeck1 = new QLabel("Cartas: 0");
    lblCartasDeck2 = new QLabel("Cartas: 0");

    // Cartas de Supertrunfo
    supertrunfoGroupBox1 = new QGroupBox("Carta de Supertrunfo - Jogador 1");
    supertrunfoGroupBox2 = new QGroupBox("Carta de Supertrunfo - Jogador 2");

    cartaImagem1 = new QLabel;
    cartaImagem1->setFixedSize(280, 130);
    cartaImagem1->setPixmap(QPixmap(" "));


    lblNomeCarta1 = new QLabel("temp", this);
    lblNomeCarta1ID = new QLabel("temp", this);
    for (int i = 0; i < 5; i++) {
        lblValorAtributos1[i] = new QLabel("TEMP", this);
        chkAtributos1[i] = new QCheckBox("TEMP", this);
    }
    btnDesafiar1 = new QPushButton("Desafiar", this);
    btnProximo1 = new QPushButton("Próximo", this);

        // Configurar layout
        cartaLayout1 = new QVBoxLayout(supertrunfoGroupBox1);
    cartaLayout1->addWidget(cartaImagem1);
    cartaLayout1->addWidget(lblNomeCarta1);
    cartaLayout1->addWidget(lblNomeCarta1ID);

    // Adicionar os atributos e valores em linhas individuais
    for (int i = 0; i < 5; i++) {
        QHBoxLayout* attributeLayout = new QHBoxLayout();
        attributeLayout->addWidget(chkAtributos1[i]);
        attributeLayout->addWidget(lblValorAtributos1[i]);
        attributeLayout->setAlignment(lblValorAtributos1[i], Qt::AlignRight);
        cartaLayout1->addLayout(attributeLayout);
    }
    cartaLayout1->addWidget( btnDesafiar1);
    cartaLayout1->addWidget( btnProximo1);
    btnProximo1->setEnabled(false);

    cartaImagem2 = new QLabel;
    cartaImagem2->setFixedSize(280, 130);
    cartaImagem2->setPixmap(QPixmap(" "));


    lblNomeCarta2 = new QLabel("temp", this);
    lblNomeCarta2ID = new QLabel("temp", this);
    for (int i = 0; i < 5; i++) {
        lblValorAtributos2[i] = new QLabel("TEMP", this);
        chkAtributos2[i] = new QCheckBox("TEMP", this);
    }
    btnDesafiar2 = new QPushButton("Desafiar", this);
    btnProximo2 = new QPushButton("Próximo", this);


    // Configurar layout
    cartaLayout2 = new QVBoxLayout(supertrunfoGroupBox2);
    cartaLayout2->addWidget(cartaImagem2);
    cartaLayout2->addWidget(lblNomeCarta2);
    cartaLayout2->addWidget(lblNomeCarta2ID);

    // Adicionar os atributos e valores em linhas individuais
    for (int i = 0; i < 5; i++) {
        QHBoxLayout* attributeLayout = new QHBoxLayout();
        attributeLayout->addWidget(chkAtributos2[i]);
        attributeLayout->addWidget(lblValorAtributos2[i]);
        attributeLayout->setAlignment(lblValorAtributos2[i], Qt::AlignRight);
        cartaLayout2->addLayout(attributeLayout);
    }
    cartaLayout2->addWidget( btnDesafiar2);
    cartaLayout2->addWidget( btnProximo2);
    btnDesafiar2->setEnabled(false);
    btnProximo2->setEnabled(false);

    // Adicionar widgets aos layouts
    QVBoxLayout* player1Layout = new QVBoxLayout;
    player1Layout->addWidget( lblJogador1);
    player1Layout->addWidget(lblCartasDeck1);
    player1Layout->addWidget(supertrunfoGroupBox1);

    QVBoxLayout* player2Layout = new QVBoxLayout;
    player2Layout->addWidget( lblJogador2);
    player2Layout->addWidget(lblCartasDeck2);
    player2Layout->addWidget(supertrunfoGroupBox2);

    gameLayout->addLayout(player1Layout);
    gameLayout->addLayout(player2Layout);
}

void JogadorWidget::Jogador1_recebecartas() {
    hand1.adicionarCarta(primeiraCarta_1);
    hand1.adicionarCarta(primeiraCarta_2);
    ApagarCarta2();
    btnDesafiar1->setEnabled(true);
    btnProximo1->setEnabled(false);
    btnDesafiar2->setEnabled(false);
    btnProximo2->setEnabled(false);
}

void JogadorWidget::Jogador2_recebecartas() {
    hand2.adicionarCarta(primeiraCarta_1);
    hand2.adicionarCarta(primeiraCarta_2);
    ApagarCarta1();
    btnDesafiar2->setEnabled(true);
    btnProximo2->setEnabled(false);
    btnDesafiar1->setEnabled(false);
    btnProximo1->setEnabled(false);
}

void JogadorWidget::Limparcheckbox() {
    for (int i = 0; i < 5; i++) {
        chkAtributos1[i]->setChecked(false);
    }
}
