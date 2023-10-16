#ifndef CONSULTA_HPP
#define CONSULTA_HPP
#include "Medico.hpp"
#include "Paciente.hpp" 
#include <iostream>
#include <string>
using namespace std;

class Consulta {
public:
    Consulta(string data, string hora, int cpfPaciente, int crmMedico,int identificador);

    Consulta();

    void setData(string data);

    string getData();

    void setHora(string hora);

    string getHora();

    void setIdentificador(int identificador);

    int getIdentificador();

    void setcpfPaciente(int cpfPaciente);

    int getcpfPaciente();

    void setcrmMedico(int crmMedico);

    int getcrmMedico();

    void imprimir_consulta();

private:
    string data,hora;
    int cpfPaciente, crmMedico,identificador;
};

#endif