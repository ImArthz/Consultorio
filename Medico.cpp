#include "Medico.hpp"
#include <iostream>>
#include <string>
using namespace std;
Medico::Medico(){}
Medico::Medico(string nome,char sexo,string endereco,string cpf,int telefone,int identidade,int crm,string especializacao):Pessoa( nome, endereco, cpf, sexo,  telefone, identidade),crm(crm),especializacao(especializacao)
{
  this->prox=NULL;
}
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
void Medico::setProx(Medico* prox){
    this->prox=prox;
}
Medico* Medico::getProx(){
    return this->prox;
}