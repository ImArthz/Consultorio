#include <iostream>
#include <locale>
#include <string>
#include "Consultorio.hpp"
#include <cstdlib> // For the system function
#include <limits> // Biblioteca para lidar com erros de leitura de inteiro

using namespace std;

int main() {
    
    Consultorio *consultorio=new Consultorio();
    Medico *medico= new Medico();
    Paciente* paciente=new Paciente();
    bool saida = true;
    int opcao,CrmRemove,IdenRemove;
    string CpfRemove;

    while (saida) {
        cout << "----------------------MENU-------------------------"<<endl;
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Cadastrar médico" << endl;
        cout << "2 - Cadastrar paciente" << endl;
        cout << "3 - Cadastrar consulta" << endl;
        cout << "4 - Imprimir dados do médico" << endl;
        cout << "5 - Imprimir consultas" << endl;
        cout << "6 - Imprimir dados do paciente" << endl;
        cout << "7 - Imprimir dados de uma consulta em específico" << endl;
        cout << "8 - Github" << endl;
        cout << "9 - Remover médico" << endl;
        cout << "10 - Remover paciente" << endl;
        cout << "11 - Remover consulta" << endl;
        cout << "12 - Sair" << endl;
        cout << "----------------------------------------------------"<<endl;

        while (true) {
            cout << "Escolha uma opção: " << endl;
            cin >> opcao;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
        switch(opcao)
        {
            case 1:
                cin.ignore();
                if(consultorio->cadastrarMedico()){
                    cout<<"Medico cadastrado com sucesso"<<endl;
                    break;
                }
                else{
                    cout<<"erro ao cadastrar medico "<<endl;
                }
            case 2:
                cin.ignore();
                if(consultorio->cadastraPaciente()){
                    cout<<"paciente cadastrado com sucesso"<<endl;
                    break;
                }
                else{
                    cout<<"erro ao cadastrar paciente "<<endl;
                    break;
                }
                

            case 3:
                cin.ignore();
                if(consultorio->cadastrarConsulta()){
                    cout<<"consulta cadastrado com sucesso"<<endl;
                    break;
                }
                else{
                    cout<<"erro ao cadastrar consulta "<<endl;
                    break;
                }

            case 4:
                consultorio->imprimirListaDeMedicos();
                break;

            case 5:
                consultorio->imprimirConsultas();
                break;

            case 6:
                consultorio->imprimirListaDePacientes();
                break;

            case 7:
                consultorio->imprimirConsultasPorIdentificador();
                break;

            case 8:
                string link = "https://github.com/ImArthz/Consultorio";

                // Construct the command to open the URL in the default web browser
                string command = "xdg-open " + link;

                // Use the system function to execute the command
                int result = system(command.c_str());

                // Check the result of the system call
                if (result == 0) {
                    cout << "Web browser opened successfully." << endl;
                } else {
                    cerr << "Failed to open web browser." << endl;
                }

                break;

            case 9:
                while (true) {
                    cout << "->Digite o crm do medico que deseja remover: " << endl;
                    cin >> CrmRemove;

                    if (cin.fail()) {
                        cin.clear();  // Limpa o estado de erro
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                        cout << "Entrada inválida. Digite um número inteiro." << endl;
                    } else {
                        // Entrada válida, podemos sair do loop
                        break;
                    }
                }
                consultorio->removerMedico(CrmRemove);

            case 10:
                cout<<"Digite o cpf do paciente que deseja remover: "<<endl;
                cin.ignore();
                getline(cin, CpfRemove);
                consultorio->removerPaciente(CpfRemove);

            case 11:
                while (true) {
                    cout << "->Digite o identificador da consulta  que deseja remover: " << endl;
                    cin >> IdenRemove;

                    if (cin.fail()) {
                        cin.clear();  // Limpa o estado de erro
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                        cout << "Entrada inválida. Digite um número inteiro." << endl;
                    } else {
                        // Entrada válida, podemos sair do loop
                        break;
                    }
                }
                consultorio->removerConsulta(IdenRemove);
                break;
            case 12:
                cout<<"Saindo ..."<<endl;
                saida = false;
                break;

        }
    }
}