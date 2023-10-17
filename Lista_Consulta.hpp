#ifndef __LISTA_CONSULTA_HPP
#define __LISTA_CONSULTA_HPP
#include "Consulta.hpp"

using namespace std;
class ListaConsulta{
private:
    Consulta* head;
    Consulta* tail;
public:
    ListaConsulta(string data,string hora, int cpfPaciente, int crmMedico,int identificador);
    ListaConsulta();

    void add_Consulta(string data,string hora, int cpfPaciente, int crmMedico,int identificador);
    void Imprimir_Consulta();
    void Remover_Consulta(int identificador);
    virtual ~ListaConsulta();
    bool vazia();
    

bool existe(string data,string hora,int crmMedico, int cpfPaciente,int identificador);
    Consulta* getHead();
    void setHead(Consulta* head);
    Consulta* getTail();
    void setTail(Consulta* tail);
};
#endif