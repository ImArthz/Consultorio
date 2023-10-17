#ifndef Consultorio_HPP
#define Consultorio_HPP
#include <iostream>
#include "Consulta.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include <string>
#include <vector>
using namespace std;

class Consultorio
{
    private:
        int telefone;
        string nome, endereco;
        vector<Medico*> listadeMedicos;
        vector<Paciente*> listadePacientes;
        vector<Consulta*> listadeconsultas;

    
    public:
        Consultorio(int telefone, string nome, string endereco);
        Consultorio();
        ~Consultorio();
        void setTelefone(int telefone);
        int getTelefone();
        void setNome(string nome);
        string getNome();
        void setEndereco(string endereco);
        string getEndereco();

        bool cadastraPaciente(Paciente* paciente);
        bool removerPaciente(Paciente* paciente);

        bool cadastrarMedico(Medico* medico);
        bool removerMedico(Medico* medico);

        bool cadastrarConsulta(Consulta* consulta);
        bool removerConsulta(Consulta* consulta);

        void imprimirListaDePacientes();
        void imprimirConsultas();
        void imprimirConsultasDoMedico();
        void imprimirListaDeMedicos();
        void imprimirDadosConsultaEspecifica(Consultorio consultorio)
        
        bool pacienteExiste(int cpf);
        bool medicoExiste(int crm);

};
#endif