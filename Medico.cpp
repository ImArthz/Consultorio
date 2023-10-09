#include "Medico.hpp"
#include <iostream>>
#include <string>
using namespace std;
Medico:Medico(){}
Medico:Medico(string nome,string endereco,string cpf,char sexo, int telefone,int identidade,int crm,string especializacao):Pessoa( nome, endereco, cpf, sexo,  telefone, identidade),crm(crm),especializacao(especializacao){}
void Medico:: setCrm(int crm){
  this-> crm = crm;
}
int Medico:: getCrm(){
  return crm;
}
void Medico::setEsp(string especializacao){
  this-> especializacao = especializacao;
}
string Medico::getEsp(){
  return especializacao;
}
bool Medico::imprimir(){
  if(/*lista_De_Medicos.empty()*/){
    cout << "\t\tNão há Medicos cadastrados ." << endl;
    return false;
  }
  else{
    for (unsigned long int i = 0; i < /*lista_De_Medicos.size()*/; i++) 
    {
        cout << "\t--------------------------------" << endl;
        cout << "\t Nome: \t" << getMedico(i).getNome() << endl;
        cout << "\t Crm: \t" << getMedico(i).getCrm() << endl;
        cout << "\t Cpf: \t "<<getMedico(i).getCpf()<<endl;
        cout << "\t Sexo: \t "<<getMedico(i).getSexo()<<endl;
        cout << "\t Endereço: \t "<<getMedico(i).getEndereco()<<endl;
        cout << "\t Telefone: \t "<<getMedico(i).getTel()<<endl;
        cout << "\t Especialização: \t "<<getMedico(i).getEsp()<<endl;
        cout << "\t--------------------------------" << endl;
    }

    return true;
  }
}
void Medico::getMedico(unsigned long int i) {
    if (i >= lista_De_Medicos.size()) {
        throw std::runtime_error("Índice inválido");
    }
    return lista_De_Medicos[i];
}