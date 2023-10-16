#include "Consulta.hpp"
#include <iostream>
#include <string>
using namespace std;

Consulta::Consulta(string data, string hora, int cpfPaciente, int crmMedico,int identificador):data(data),hora(hora),cpfPaciente(cpfPaciente),crmMedico(crmMedico),identificador(identificador){}
Consulta:: Consulta(){}
void Consulta :: setData(string data){
  this -> data = data;
}
string Consulta :: getData(){
  return data;
}
void Consulta :: setHora(string hora){
  this-> hora = hora ;
}
string Consulta :: getHora(){
  return hora;
}
void Consulta :: setIdentificador(int identificador){
    this->identificador=identificador;
}
int Consulta :: getIdentificador(){
    return identificador;
}
void Consulta :: setcpfPaciente(int cpfPaciente)
{
    this->cpfPaciente=cpfPaciente;
}

int Consulta :: getcpfPaciente()
{
    return cpfPaciente;
}
void Consulta :: setcrmMedico(int crmMedico)
{
    this->crmMedico=crmMedico;
}

int Consulta :: getcrmMedico()
{
    return crmMedico;
}
void Consulta :: imprimir_consulta()
{
    cout << "\t\tConsulta"<<endl;
    cout << "-------------------------"<<endl;
    cout << "Identificador: \t"<<getIdentificador()<<endl;
    cout << "Data: \t" << getData<< endl;
    cout << "Hora: \t" << getHora << endl;
    cout << "Cpf do Paciente: \t" << getcpfPaciente() << endl;
    cout << "Crm do Médico: \t" << getcrmMedico() << endl;
    cout << "-------------------------"<<endl;

}