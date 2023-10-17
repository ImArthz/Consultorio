#ifndef __LISTA_PACIENTE_HPP
#define __LISTA_PACIENTE_HPP
#include "Paciente.hpp"
using namespace std;
class ListaPaciente{

public:
    ListaPaciente(string nome,char sexo, string endereco, string cpf, int telefone, int identidade, string relato, string Med_controlada);

    ListaPaciente();


    void addPaciente(string nome,char sexo, string endereco, string cpf, int telefone, int identidade, string relato, string Med_controlada);

    void Imprimir_Paciente();

    void Remover_Paciente(string cpf);

    virtual ~ListaPaciente();

    bool vazia();
    
    Paciente* getHead();

    void setHead(Paciente* head);

    Paciente* getTail();

    void setTail(Paciente* tail);
private:
    Paciente* head;
    Paciente* tail;
    static int contador_Paciente;
};
#endif