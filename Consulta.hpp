#ifndef CONSULTA_HPP
#define CONSULTA_HPP
#include "Medico.hpp"
#include "Paciente.hpp" 
#include <iostream>
#include <string>
using namespace std;

class Consulta {
public:
    Consulta(string data, string hora, string cpfPaciente, int crmMedico,int identificador);

    Consulta();

    void setData(string data);

    string getData();

    void setHora(string hora);

    string getHora();

    void setIdentificador(int identificador);

    int getIdentificador();

    void setcpfPaciente(string cpfPaciente);

    string getcpfPaciente();

    void setcrmMedico(int crmMedico);

    int getcrmMedico();

    void imprimir_consulta();

    void setProx(Consulta* prox);
    
    Consulta* getProx();

private:
    string data,hora,cpfPaciente;
    int crmMedico,identificador;
    Consulta* prox;
};

#endif