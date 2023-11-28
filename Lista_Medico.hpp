#ifndef __LISTA_MEDICO_HPP
#define __LISTA_MEDICO_HPP
#include "Medico.hpp"
using namespace std;
class ListaMedico
{
public:
    ListaMedico(string nome, char sexo, string endereco, string cpf, int telefone, int identidade, int crm, string especializacao);
    ListaMedico();

    void addMedico(string nome, char sexo, string endereco, string cpf, int telefone, int identidade, int crm, string especializacao);
    void Imprimir_Medico();
    void Remover_Medico(int crm);
    virtual ~ListaMedico();
    bool vazia();

    Medico *getHead();
    void setHead(Medico *head);
    Medico *getTail();
    void setTail(Medico *tail);

private:
    Medico *head;
    Medico *tail;
    static int contador_Medico;
};
#endif