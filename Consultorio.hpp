#ifndef Consultorio_HPP
#define Consultorio_HPP
#include <iostream>
#include "Consulta.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include <string>
#include "Lista_Medico.hpp"
#include "Lista_Paciente.hpp"
#include "excessaoMedicoInexistente.hpp"
#include "Lista_Consulta.hpp"
using namespace std;

class Consultorio
{
    public:
        Consultorio(ListaMedico* medicos, ListaPaciente* pacientes, ListaConsulta* consultas, string nome, string endereco, int telefone);
        Consultorio();
        ~Consultorio();
        void setTelefone(int telefone);
        int getTelefone();
        void setNome(string nome);
        string getNome();
        void setEndereco(string endereco);
        string getEndereco();

        bool cadastraPaciente();
        bool removerPaciente(string cpf);

        bool cadastrarMedico();
        bool removerMedico(int crm);

        bool cadastrarConsulta();
        bool removerConsulta(int identificador);

        void imprimirListaDePacientes();
        void imprimirConsultas();
        void imprimirConsultasPorIdentificador();
        void imprimirListaDeMedicos();
        
    private:
        int telefone;
        string nome, endereco;
        ListaMedico* medicos;
        ListaPaciente* pacientes;
        ListaConsulta* consultas;
        static int contador_paciente;

};
#endif
