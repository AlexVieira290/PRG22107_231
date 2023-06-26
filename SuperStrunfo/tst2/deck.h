#ifndef DECK_H
#define DECK_H

#include <string>
#include <queue>
#include "carta.h"

class Deck {
public:
    Deck();
    Deck(const std::string& nome);
    Deck(const std::string& nome, const std::string& caminhoArquivo);
    void adicionarCarta(const Carta& carta);
    std::string getNome() const;
    Carta removerCarta();
    bool vazio() const;
    int getTamanho() const;
    void embaralharCartas();
    void distribuirCartas(Deck& deck1, Deck& deck2);

private:
    std::string nome;
    std::queue<Carta> cartas;
};

#endif // DECK_H
