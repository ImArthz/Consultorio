#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include "Pessoa.hpp"
#include <iostream>
#include <string>

class Paciente:public Pessoa
{
    public:
    void setRelato(string relato);

    string getRelato();

    void setMedCon(string Med_controlada);

    string getMedCon();

    void setProx(Paciente* prox);

    Paciente* getProx();

    Paciente();

    Paciente(string nome,string endereco,string cpf,char sexo,int telefone,int identidade,string relato,string Med_controlada);
    private:
        string relato;
        string Med_controlada;
        Paciente* prox;
};
#endif