#include "Paciente.hpp".hpp"
#include <iostream>>
#include <string>
using namespace std;
Paciente:Paciente(){}
Paciente:Paciente(string nome,string endereco,string cpf,char sexo, int telefone,int identidade,string relato,string Med_controlada):Pessoa( nome, endereco, cpf, sexo,  telefone, identidade),relato(relato),Med_controlada(Med_controlada){}
void Paciente::setRelato(string relato){
  this-> relato = relato;
}
string Paciente::getRelato(){
  return relato;
}
void Paciente::setMedCon(string Med_controlada){
  this->Med_controlada=Med_controlada;
}
string Paciente::getMedCon(){
  return Med_controlada;
}
bool Paciente::imprimir(){
  if(/*lista_De_Paciente.empty()*/){
    cout << "\t\tNão há Paciente cadastrados ." << endl;
    return false;
  }
  else{
    for (unsigned long int i = 0; i < /*lista_De_Paciente.size()*/; i++) 
    {
        cout << "\t--------------------------------" << endl;
        cout << "\t Nome: \t" << getPaciente(i).getNome() << endl;
        cout << "\t Cpf: \t "<<getPaciente(i).getCpf()<<endl;
        cout << "\t Sexo: \t "<<getPaciente(i).getSexo()<<endl;
        cout << "\t Endereço: \t "<<getPaciente(i).getEndereco()<<endl;
        cout << "\t Telefone: \t "<<getPaciente(i).getTel()<<endl;
        cout << "\t Medicação Controlada usualmente consomida :\n \t \t "<<getPaciente(i).getMedCon()<<endl;
        cout << "\t Relato:\n\t \t" << getPaciente(i).getRelato() << endl;
        cout << "\t--------------------------------" << endl;
    }

    return true;
  }
}
void Paciente::getPaciete(unsigned long int i) {
    if (i >= lista_De_Paciente.size()) {
        throw std::runtime_error("Índice inválido");
    }
    return lista_De_Paciente[i];
}