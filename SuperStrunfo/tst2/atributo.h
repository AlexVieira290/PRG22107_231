#ifndef ATRIBUTO_H
#define ATRIBUTO_H

#include <string>

class Atributo {
public:
    Atributo();
    Atributo(const std::string& nome, float valor, int tipo);
    void setNome(const std::string& nome);  // não utilizado, criado para alterar nome
    void setValor(float valor);             // não utilizado, criado para alterar valor
    void setTipo(int tipo);                 // não utilizado, criado para alterar tipo
    std::string getNome() const;
    float getValor() const;
    int getTipo() const;

private:
    std::string nome;
    float valor;
    int tipo;
};

#endif // ATRIBUTO_H
