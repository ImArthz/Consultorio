#include "Paciente.hpp"

Paciente:: Paciente(string nome,string endereco,string cpf,char sexo, int telefone,int identidade,string relato,string Med_controlada):Pessoa( nome, endereco, cpf, sexo,  telefone, identidade),relato(relato),Med_controlada(Med_controlada){}

Paciente :: Paciente(){}

void Paciente :: setRelato(string relato)
{
    this->relato=relato;
}

string Paciente :: getRelato()
{
    return relato;
}

void Paciente :: setMedCon(string Med_controlada)
{
    this->Med_controlada=Med_controlada;
}

string Paciente :: getMedCon()
{
    return  Med_controlada;
}