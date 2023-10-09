#ifndef CONSULTA_HPP
#define CONSULTA_HPP
#include "Medico.hpp"
#include "Paciente.hpp" 
#include <iostream>
#include <string>
using namespace std;

class Consulta {
public:
    Consulta(string data,string hora,Paciente paciente,Medico medico);

    Consulta();
    void setData(string data);
    string getData();
    void setHora(string hora);
    string getHora();
    bool imprimir();


private:
    string data,hora;//talvez int
    Paciente paciente;
    Medico medico;
};

#endif