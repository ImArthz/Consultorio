#include "Consultorio.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"
#include "Consulta.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Consultorio::Consultorio(int telefone, string nome,string endereco):telefone(telefone),nome(nome),endereco(endereco){}
Consultorio::Consultorio(){}
void Consultorio::setTelefone(int telefone){
    this->telefone=telefone;
}
int Consultorio::getTelefone(){
    return telefone;
}
void Consultorio::setNome(string nome){
    this->nome=nome;
}
string Consultorio::getNome(){
    return nome;
}
void Consultorio::setEndereco(string endereco){
    this->endereco=endereco;
}
string Consultorio::getEndereco(){
    return endereco;
}
bool Consultorio::cadastrarMedico(Medico* medico) {
    for (Medico* m : listadeMedicos)
        {
            if (m->getCrm() == medico->getCrm())
            {
                throw std::runtime_error("Erro ao cadastrar Medico"); // Já existe um medico com o mesmo Crm
            }
        }
        listadeMedicos.push_back(medico);
        return true; // medico adicionado com sucesso
}
bool Consultorio::removerMedico(int crm)
    {
        while(true){
            string op;
            bool encontrado = false;
            cout << "Tem certeza disso ?  (S/N)?" << endl;
            cout <<" Ao digitar sim o Medico de crm"<<crm<< " sera permanentemente excluido"<<endl;
            //cin.ignore(); não é nescessario pois é tratado se nao for s/n
            getline(cin, op);
            if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
                for (size_t i = 0; i < listadeMedicos.size(); i++)
                {
                    if (listadeMedicos[i]->getCrm() == crm)
                    {
                        delete listadeMedicos[i]; // Libera a memória do médico
                        listadeMedicos.erase(listadeMedicos.begin() + i);
                        bool encontrado = true;
                        return true; // Médico removido com sucesso
                    }
                }
                throw std::runtime_error("Erro ao remover médico"); 
                return false; 
            
                if (!encontrado) {
                    cout << "O Medico de crm: " << crm << " não foi encontrado" << endl;
                }
            }
            else if (op == "Não" || op == "nao" || op == "N" || op == "n") {
                cout << "Voltando ao menu" << endl;
                return; // Sai da função se o usuário decide não excluir o Medico;
            }
    
            else 
            {
                cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
            }
        }
        
    }  
bool Consultorio::cadastraPaciente(Paciente* paciente)
    {
        for (Paciente* p : listadePacientes)
        {
            if (p->getCpf() == paciente->getCpf())
            {
                throw std::runtime_error("Erro ao cadastrar Paciente"); // Já existe um paciente com o mesmo CPF
            }
        }
        listadePacientes.push_back(paciente);
        return true; // Paciente adicionado com sucesso
    }
bool Consultorio::removerPaciente(int cpf)
    {
        while(true){
            string op;
            bool encontrado = false;
            cout << "Tem certeza disso ?  (S/N)?" << endl;
            cout <<" Ao digitar sim o Paciente de cpf "<<cpf<< " sera permanentemente excluido"<<endl;
            //cin.ignore(); não é nescessario pois é tratado se nao for s/n
            getline(cin, op);
            if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
                for (size_t i = 0; i < listadePacientes.size(); i++)
                {
                    if (listadePacientes[i]->getCpf() == cpf)
                    {
                        delete listadePacientes[i]; // Libera a memória do paciente
                        listadePacientes.erase(listadePacientes.begin() + i);
                        encontrado = true;
                        
                        return true; // Paciente removido com sucesso
                    }
                }
                return false; // Paciente não encontrado
            
                if (!encontrado) {
                    cout << "O Paciente de Cpf: " << cpf << " não foi encontrado" << endl;
                }
            }
            else if (op == "Não" || op == "nao" || op == "N" || op == "n") {
                cout << "Voltando ao menu" << endl;
                return; // Sai da função se o usuário decide não excluir o Paciente;
            }
    
            else 
            {
                cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
            }
        }
        
    }  
bool Consultorio::cadastrarConsulta(Consulta* consulta){
    for (Consulta* c : listadeconsultas)
        {
            if (c->getIdentificador() == paciente->getIdentificador())
            {
                throw std::runtime_error("Erro ao cadastrar Consulta"); // Já existe um Consulta com o mesmo Identificador
            }
        }
        listadeconsultas.push_back(consulta);
        return true; // Consulta adicionado com sucesso
}
bool Consultorio::removerConsulta(int identificador)
{
        while(true){
            string op;
            bool encontrado = false;
            cout << "Tem certeza disso ?  (S/N)?" << endl;
            cout <<" Ao digitar sim a consulta de identificador "<<identificador<< " sera permanentemente excluida"<<endl;
            //cin.ignore(); não é nescessario pois é tratado se nao for s/n
            getline(cin, op);
            if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
                for (size_t i = 0; i < listadeconsultas.size(); i++)
                {
                    if (listadeconsultas[i]->getIdentificador() == identificador)
                    {
                        delete listadeconsultas[i]; // Libera a memória da consulta
                        listadeconsultas.erase(listadeconsultas.begin() + i);
                        encontrado = true;
                        
                        return true; // Consulta removida com sucesso
                    }
                }
                return false; // Consulta não encontrada
            
                if (!encontrado) {
                    cout << "A Consulta de Identificador: " << Identificador<< " não foi encontrada" << endl;
                }
            }
            else if (op == "Não" || op == "nao" || op == "N" || op == "n") {
                cout << "Voltando ao menu" << endl;
                return; // Sai da função se o usuário decide não excluir a consulta;
            }
    
            else 
            {
                cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
            }
        }
        
    }  
void Consultorio:: imprimirDadosConsultaEspecifica(Consultorio consultorio) {
    int identificador;
    cout << "Digite o identificador da consulta: ";
    cin >> identificador;

    bool consultaEncontrada = false;

    for (const Consulta* consulta : consultorio.listadeconsultas) {
        if (consulta->getIdentificador() == identificador) {
            consultaEncontrada = true;

            cout << "\tDados da Consulta" << endl;
            cout << "Identificador: " << consulta->getIdentificador() << endl;
            cout << "Data: " << consulta->getData() << endl;
            cout << "Hora: " << consulta->getHora() << endl;
            cout << "CPF do Paciente: " << consulta->getcpfPaciente() << endl;
            cout << "CRM do Médico: " << consulta->getcrmMedico() << endl;
            break;  // Encerra o loop após encontrar a consulta
        }
    }

    if (!consultaEncontrada) {
        cout << "Consulta com identificador " << identificador << " não encontrada." << endl;
    }
}
bool Consultorio::pacienteExiste(int cpf) {
    for (Paciente* paciente : listaPacientes) {
        if (paciente->getCpf() == cpf) {
            return true; // O paciente com o CPF fornecido existe
        }
    }
    return false; // O paciente com o CPF fornecido não existe
}
bool Medico::medicoExiste(int crm) {
    for (Medico* medico : listaMedicos) {
        if (medico->getCrm() == crm) {
            return true; // O médico com o CRM fornecido existe
        }
    }
    return false; // O médico com o CRM fornecido não existe
}
~Consultorio()
    {
        // Libera a memória alocada para pacientes, médicos e consultas
        for (Medico* medico : listadeMedicos)
        {
            delete medico;
        }
        for (Paciente* paciente : listadePacientes)
        {
            delete paciente;
        }
        for (Consulta* consulta : listadeconsultas)
        {
            delete consulta;
        }
    }