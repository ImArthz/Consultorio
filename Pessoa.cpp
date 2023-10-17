#include "Pessoa.hpp"
#include <iostream>
#include <string>

using namespace std;

Pessoa::Pessoa(string nome,string endereco,string cpf,char sexo, int telefone,int identidade):nome(nome),endereco(endereco),sexo(sexo),telefone(telefone),identidade(identidade){}

Pessoa::Pessoa(){}

void Pessoa:: setNome(string nome){
    this -> nome = nome;
}
string Pessoa:: getNome(){
    return nome;
}
void Pessoa:: setEndereco(string endereco){
    this -> endereco = endereco;
}
string Pessoa:: getEndereco(){
    return endereco;
}
void Pessoa:: setCpf(string cpf){
  this -> cpf = cpf;
  
}
string Pessoa:: getCpf(){
  return cpf;
  
}
void Pessoa:: setSexo(char sexo){
  this -> sexo = sexo;
  
} 
char Pessoa:: getSexo(){
  return sexo;
  
}
void Pessoa:: setTel(int telefone){
  this -> telefone = telefone;
} 
int Pessoa:: getTel(){
  return telefone;
  
}
void Pessoa:: setID(int identidade){
  this -> identidade = identidade;
  
} 
int Pessoa:: getID(){
  return identidade;
  
}
void Pessoa :: imprimir()
{
    cout << "Nome: \t\t" << getNome() << endl;
    cout << "Sexo: \t" << getSexo() << endl;
    cout << "Endereço: \t" << getEndereco() << endl;
    cout << "CPF: \t" << getCpf() << endl;
    cout << "Telefone: \t" << getTel() << endl;
    cout << "Identidade: \t" << getID() << endl;

}