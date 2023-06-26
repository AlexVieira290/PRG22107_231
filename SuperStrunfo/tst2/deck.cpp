#include "deck.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include "carta.h"
#include "atributo.h"

Deck::Deck() {
    nome = "";
}

Deck::Deck(const std::string& nome)
    : nome(nome) {}

Deck::Deck(const std::string& nome, const std::string& caminhoArquivo)
    : nome(nome) {
    std::ifstream arquivo(caminhoArquivo, std::ios::in | std::ios::binary);

    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::stringstream ss(linha);
            std::string item;

            std::string id;
            std::string nomeCarta;
            Atributo atributo1("", 0.0f, 0);
            Atributo atributo2("", 0.0f, 0);
            Atributo atributo3("", 0.0f, 0);
            Atributo atributo4("", 0.0f, 0);
            Atributo atributo5("", 0.0f, 0);

            std::getline(ss, item, ':');
            id = item;
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            nomeCarta = item;
            std::cout << item << std::endl;

            std::getline(ss, item, ':');
            atributo1.setNome(item);
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo1.setValor(std::stof(item));
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo1.setTipo(std::stoi(item));
            std::cout << item << std::endl;

            std::getline(ss, item, ':');
            atributo2.setNome(item);
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo2.setValor(std::stof(item));
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo2.setTipo(std::stoi(item));
            std::cout << item << std::endl;

            std::getline(ss, item, ':');
            atributo3.setNome(item);
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo3.setValor(std::stof(item));
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo3.setTipo(std::stoi(item));
            std::cout << item << std::endl;

            std::getline(ss, item, ':');
            atributo4.setNome(item);
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo4.setValor(std::stof(item));
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo4.setTipo(std::stoi(item));
            std::cout << item << std::endl;

            std::getline(ss, item, ':');
            atributo5.setNome(item);
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo5.setValor(std::stof(item));
            std::cout << item << std::endl;
            std::getline(ss, item, ':');
            atributo5.setTipo(std::stoi(item));
            std::cout << item << std::endl;

            Carta carta(id, nomeCarta, atributo1, atributo2, atributo3, atributo4, atributo5);
            adicionarCarta(carta);
        }

        arquivo.close();
        int tamanhoDeck = getTamanho();
        std::cout << "Cartas no deck: " << tamanhoDeck << std::endl;
    }
}

void Deck::adicionarCarta(const Carta& carta) {
    cartas.push(carta);
}

std::string Deck::getNome() const {
    return nome;
}

Carta Deck::removerCarta() {
    Carta carta = cartas.front();
    cartas.pop();
    return carta;
}

bool Deck::vazio() const {
    return cartas.empty();
}

int Deck::getTamanho() const {
    return cartas.size();
}

// Declaração da função para embaralhar as cartas
void Deck::embaralharCartas() {
    // Cria um vetor temporário para armazenar as cartas
    std::vector<Carta> temp;

    // Transfere as cartas da fila para o vetor temporário
    while (!cartas.empty()) {
        temp.push_back(cartas.front());
        cartas.pop();
    }

    // Embaralha as cartas no vetor temporário
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(temp.begin(), temp.end(), g);

    // Transfere as cartas do vetor temporário de volta para a fila
    for (const auto& carta : temp) {
        cartas.push(carta);
    }
}

void Deck::distribuirCartas(Deck& deck1, Deck& deck2) {
    while (!cartas.empty()) {
        deck1.adicionarCarta(removerCarta());
        if (!cartas.empty()) {
            deck2.adicionarCarta(removerCarta());
        }
    }
}
