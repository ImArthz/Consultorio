#include "Consultorio.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Consultorio::Consultorio(int telefone, string nome,string endereco):telefone(telefone),nome(nome),endereco(endereco){}
Consultorio::Consultorio(){}
void Consultorio::setTelefone(int telefone){
    this->telefone=telefone;
}
int Consultorio::getTelefone(){
    return telefone;
}
void Consultorio::setNome(string nome){
    this->nome=nome;
}
string Consultorio::getNome(){
    return nome;
}
void Consultorio::setEndereco(string endereco){
    this->endereco=endereco;
}
string Consultorio::getEndereco(){
    return endereco;
}
bool Consultorio::cadastrarMedico(Medico* medico) {
    listadeMedicos.push_back(medico);
    
    for (Medico* a : listadeMedicos) {
        if (a->getCrm() == medico->getCrm()) {
            return true; // Médico adicionado com sucesso
        }
    }
    
    // Se não foi possível adicionar o médico, lance uma exceção ou retorne falso
    throw std::runtime_error("Erro ao cadastrar médico");
}
bool Consultorio::cadastraPaciente(Paciente* paciente){
    listadePacientes.push_back(paciente);
    
    for (Paciente* a : listadePacientes) {
        if (a->getCpf() == paciente->getCpf()) {
            return true; // Paciente adicionado com sucesso
        }
    }
    
    // Se não foi possível adicionar o Paciente, lance uma exceção ou retorne falso
    throw std::runtime_error("Erro ao cadastrar Paciente");
}
bool Consultorio::cadastrarConsulta(Consulta* consulta){
    listadeconsultas.push_back(consulta);

    for(Consulta* a:listadeconsultas){
        if(a->getIdentificador() == consulta->getIdentificador()){
            return true;//Consulta adicionada com sucesso
        }
    }
    // Se não foi possível adicionar a consulta, lance uma exceção ou retorne falso
    throw std::runtime_error("Erro ao cadastrar consulta");
}