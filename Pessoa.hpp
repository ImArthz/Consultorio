#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include <string>

using namespace std;
class Pessoa {
    private:
        string nome;
        string endereco;
        string cpf;
        char sexo;
        int telefone;
        int identidade;   
    public:
        void setNome(string nome);
    
        string getNome();
    
        void setEndereco(string endereco);
    
        string getEndereco();

        void setCpf(string cpf);
    
        string getCpf();

        void setSexo(char sexo);
    
        char getSexo();

        void setTel(int telefone);
    
        int getTel();

        void setID(int identidade);
    
        int getID();

        Pessoa(string nome,string endereco,string cpf,char sexo, int telefone,int identidade);
        Pessoa();

        void imprimir();
};
#endif