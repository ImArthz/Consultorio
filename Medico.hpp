#ifndef MEDICO_HPP
#define MEDICO_HPP
#include "Pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;
class Medico : public Pessoa
{
public:
    void setCrm(int crm);

    int getCrm();

    void setEsp(string especializacao);

    string getEsp();

    void setProx(Medico *prox);

    Medico *getProx();

    Medico();

    Medico(string nome, char sexo, string endereco, string cpf, int telefone, int identidade, int crm, string especializacao);

private:
    int crm;
    string especializacao;
    Medico *prox;
};
#endif