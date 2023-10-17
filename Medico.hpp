#ifndef MEDICO_HPP
#define MEDICO_HPP
#include "Pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;
class Medico: public Pessoa {
    public:
    void setCrm(int crm);

    int getCrm();

    void setEsp(string especializacao);

    string getEsp();

    Medico();
    
    Medico(string nome,string endereco,string cpf,char sexo, int telefone,int identidade,int crm,string especializacao);

    
    private:
    int crm;
    string especializacao;

    
        
};
#endif