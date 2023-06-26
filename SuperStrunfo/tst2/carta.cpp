#include "carta.h"

Carta::Carta()
    : ID(""), nome(""), atributo1(Atributo()), atributo2(Atributo()), atributo3(Atributo()), atributo4(Atributo()), atributo5(Atributo()) {}

Carta::Carta(const std::string& ID, const std::string& nome, const Atributo& atributo1, const Atributo& atributo2, const Atributo& atributo3, const Atributo& atributo4, const Atributo& atributo5)
    : ID(ID), nome(nome), atributo1(atributo1), atributo2(atributo2), atributo3(atributo3), atributo4(atributo4), atributo5(atributo5) {}

std::string Carta::getID() const {
    return ID;
}

std::string Carta::getNome() const {
    return nome;
}

Atributo Carta::getAtributo1() const {
    return atributo1;
}

Atributo Carta::getAtributo2() const {
    return atributo2;
}

Atributo Carta::getAtributo3() const {
    return atributo3;
}

Atributo Carta::getAtributo4() const {
    return atributo4;
}

Atributo Carta::getAtributo5() const {
    return atributo5;
}

Atributo Carta::getAtributo(int x) const {
    switch(x) {
    case 0:
        return atributo1;
    case 1:
        return atributo2;
    case 2:
        return atributo3;
    case 3:
        return atributo4;
    case 4:
        return atributo5;
    default:
        return atributo1;
    }
}
