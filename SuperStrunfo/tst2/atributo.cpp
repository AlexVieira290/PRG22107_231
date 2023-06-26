#include "atributo.h"

Atributo::Atributo()
    : valor(0.0f), tipo(0) {}

Atributo::Atributo(const std::string& nome, float valor, int tipo)
    : nome(nome), valor(valor), tipo(tipo) {}

void Atributo::setNome(const std::string& nome) {
    this->nome = nome;
}

void Atributo::setValor(float valor) {
    this->valor = valor;
}

void Atributo::setTipo(int tipo) {
    this->tipo = tipo;
}

std::string Atributo::getNome() const {
    return nome;
}

float Atributo::getValor() const {
    return valor;
}

int Atributo::getTipo() const {
    return tipo;
}
