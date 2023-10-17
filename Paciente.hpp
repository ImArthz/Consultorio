#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include "Pessoa.hpp"
#include <iostream>
#include <string>

class Paciente:public Pessoa
{
    private:
        string relato;
        string Med_controlada;

    public:
    void setRelato(string relato);

    string getRelato();

    void setMedCon(string Med_controlada);

    string getMedCon();

    Paciente();

    Paciente(string nome,string endereco,string cpf,char sexo, int telefone,int identidade,string relato,string Med_controlada);

};
#endif