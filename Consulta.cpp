#include "Consulta.hpp".hpp"
#include <iostream>
#include <string>
using namespace std;

Consulta::Consulta(string data,string hora,Paciente paciente,Medico medico):data(data),hora(hora),paciente(paciente),medico(medico){}
Consulta::Consulta();
void Consulta::setData(string data){
  this -> data = data;
}
string Consulta::getData(){
  return data;
}
void Consulta::setHora(string hora){
  this-> hora = hora ;
}
string Consulta::getHora(){
  return hora;
}
bool Medico::imprimir(){
  if(/*lista_De_Consulta.empty()*/){
    cout << "\t\tNão há Consultas cadastrados ." << endl;
    return false;
  }
  else{
    for (unsigned long int i = 0; i < /*lista_De_Consulta.size()*/; i++) 
    {
        cout << "\t--------------------------------" << endl;
        cout << "\t Data : \t"<< getConsulta(i).getData()<<endl;
        cout << "\t Hora: \t" << getConsulta(i).getHora() << endl;
        cout << "\t--------------------------------" << endl;
    }

    return true;
  }
}
void Consulta::getConsulta(unsigned long int i) {
    if (i >= lista_De_Consulta.size()) {
        throw std::runtime_error("Índice inválido");
    }
    return lista_De_Consulta[i];
}
