#ifndef CARTA_H
#define CARTA_H

#include <string>
#include <vector>
#include "atributo.h"

class Carta {
public:
    Carta();
    Carta(const std::string& ID, const std::string& nome, const Atributo& atributo1, const Atributo& atributo2, const Atributo& atributo3, const Atributo& atributo4, const Atributo& atributo5);
    std::string getID() const;
    std::string getNome() const;
    Atributo getAtributo1() const;  //não utilizado, substituido por get atributo(int)
    Atributo getAtributo2() const;
    Atributo getAtributo3() const;
    Atributo getAtributo4() const;
    Atributo getAtributo5() const;
    Atributo getAtributo(int) const;


private:
    std::string ID;
    std::string nome;
    Atributo atributo1;
    Atributo atributo2;
    Atributo atributo3;
    Atributo atributo4;
    Atributo atributo5;
};

#endif // CARTA_H
