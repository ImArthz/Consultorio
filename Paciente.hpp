#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include "Pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;
class Paciente: public Pessoa {
    public:
    void setRelato(string relato);
    string getRelato();
    void setMedCon(string Med_controlada);
    string getMedCon();
    Paciente();
    Paciente(string nome,string endereco,string cpf,char sexo, int telefone,int identidade,string relato,string Med_controlada);
    bool imprimir();
    void getPaciente(unsigned long int i);

    
    private:
    string relato;
    string Med_controlada;