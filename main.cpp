#include <iostream>
#include "Medico.hpp"
#include "Paciente.hpp"
#include "Consulta.hpp"
#include "Consultorio.hpp"
#include <cstdlib> // For the system function
#include <limits> // Biblioteca para lidar com erros de leitura de inteiro

using namespace std;

int main() {
    Consultorio consultorio;
    bool saida = true;
    int opcao;

    while (saida) {
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

        switch (opcao) {
            case 1:
                // Cadastrar médico
                {
                    Medico* medico = new Medico();
                    cin.ignore(); // Limpar o buffer de entrada
                    // Preencha os dados do médico
                    string nome, endereco, cpf, especializacao;
                    char sexo;
                    int telefone, identidade, crm;

                    cout << "Nome do médico: ";
                    getline(cin, nome);
                    medico->setNome(nome);

                    cout << "Endereço: ";
                    getline(cin, endereco);
                    medico->setEndereco(endereco);

                    cout << "CPF: ";
                    getline(cin, cpf);
                    medico->setCpf(cpf);

                    cout << "Sexo: ";
                    cin >> sexo;
                    medico->setSexo(sexo);
                    while (true) {
                        cout << "Telefone: ";
                        cin >> telefone;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }
                    medico->setTel(telefone);
                    while (true) {
                        cout << "Identidade: ";
                        cin >> identidade;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }
                    medico->setID(identidade);
                    while (true) {
                        cout << "CRM: ";
                        cin >> crm;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }
                    medico->setCrm(crm);

                    cout << "Especialização: ";
                    cin.ignore();
                    getline(cin, especializacao);
                    medico->setEsp(especializacao);

                    if (consultorio.cadastrarMedico(medico)) {
                        cout << "Médico cadastrado com sucesso." << endl;
                    } else {
                        cout << "Erro ao cadastrar o médico." << endl;
                        delete medico; // Liberar memória em caso de erro
                    }
                }
                break;

            case 2:
                // Cadastrar paciente
                {
                    Paciente* paciente = new Paciente();
                    cin.ignore(); // Limpar o buffer de entrada
                    // Preencha os dados do paciente
                    string nome, endereco, cpf, relato, med_controlada;
                    char sexo;
                    int telefone, identidade;

                    cout << "Nome do paciente: ";
                    getline(cin, nome);
                    paciente->setNome(nome);

                    cout << "Endereço: ";
                    getline(cin, endereco);
                    paciente->setEndereco(endereco);

                    cout << "CPF: ";
                    getline(cin, cpf);
                    paciente->setCpf(cpf);

                    cout << "Sexo: ";
                    cin >> sexo;
                    paciente->setSexo(sexo);
                    while (true) {
                        cout << "Telefone: ";
                        cin >> telefone;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }

                    paciente->setTel(telefone);
                    while (true) {
                        cout << "Identidade: ";
                        cin >> identidade;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }
                    paciente->setID(identidade);

                    cout << "Relato: ";
                    cin.ignore();
                    getline(cin, relato);
                    paciente->setRelato(relato);

                    cout << "Medicação Controlada: ";
                    getline(cin, med_controlada);
                    paciente->setMedCon(med_controlada);

                    if (consultorio.cadastrarPaciente(paciente)) {
                        cout << "Paciente cadastrado com sucesso." << endl;
                    } else {
                        cout << "Erro ao cadastrar o paciente." << endl;
                        delete paciente; // Liberar memória em caso de erro
                    }
                }
                break;

            case 3:
                // Cadastrar consulta
                {
                    Consulta* consulta = new Consulta();
                    // Preencha os dados da consulta
                    string data, hora;
                    int cpfPaciente, crmMedico, identificador;

                    cin.ignore(); // Limpar o buffer de entrada

                    cout << "Data da consulta (DD/MM/AAAA): ";
                    getline(cin, data);
                    consulta->setData(data);

                    cout << "Hora da consulta (HH:MM): ";
                    getline(cin, hora);
                    consulta->setHora(hora);

                    cout << "Identificador da consulta: ";
                    cin >> identificador;
                    consulta->setIdentificador(identificador);
                    while (true) {
                        cout << "CPF do paciente: ";
                        cin >> cpfPaciente;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }
                    // Verificar se o CPF do paciente corresponde a um paciente válido
                    if (!consultorio.pacienteExiste(cpfPaciente)) {
                        cout << "CPF do paciente não corresponde a um paciente cadastrado." << endl;
                        delete consulta;
                        break;
                    }
                    while (true) {
                        cout << "CRM do médico: ";
                        cin >> crmMedico;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }
                    // Verificar se o CRM do médico corresponde a um médico válido
                    if (!consultorio.medicoExiste(crmMedico)) {
                        cout << "CRM do médico não corresponde a um médico cadastrado." << endl;
                        delete consulta;
                        break;
                    }
                    consulta->setcpfPaciente(cpfPaciente);
                    consulta->setcrmMedico(crmMedico);
                    if (consultorio.cadastrarConsulta(consulta)) {
                        cout << "Consulta cadastrada com sucesso." << endl;
                    } else {
                        cout << "Erro ao cadastrar a consulta." << endl;
                        delete consulta; // Liberar memória em caso de erro
                    }
                }
                break;

            case 4:
                // Imprimir dados do médico
                consultorio.imprimirListaDeMedicos();
                break;

            case 5:
                // Imprimir consultas
                consultorio.imprimirConsultas();
                break;

            case 6:
                // Imprimir dados do paciente
                consultorio.imprimirListaDePacientes();
                break;

            case 7:
                // Imprimir dados de uma consulta em específico
                consultorio.imprimirDadosConsultaEspecifica(consultorio);
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
                // Remover médico
                {
                    int crm;
                    while (true) {
                        cout << "Digite o CRM do médico a ser removido: ";
                        cin >> crm;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }

                    if (consultorio.removerMedico(crm)) {
                        cout << "Médico removido com sucesso." << endl;
                    } else {
                        cout << "Médico não encontrado ou erro ao remover." << endl;
                    }
                }
                break;

            case 10:
                // Remover paciente
                {
                    int cpf;
                    cout << "Digite o CPF do paciente a ser removido: ";
                    cin.ignore();
                    getline(cin, cpf);
                    if (consultorio.removerPaciente(cpf)) {
                        cout << "Paciente removido com sucesso." << endl;
                    } else {
                        cout << "Paciente não encontrado ou erro ao remover." << endl;
                    }
                }
                break;

            case 11:
                // Remover consulta
                {
                    int identificador;
                    while (true) {
                        cout << "Digite o identificador da consulta a ser removida: ";
                        cin >> identificador;
                        if (cin.fail()) {
                            cin.clear();  // Limpa o estado de erro
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            // Entrada válida, podemos sair do loop
                            break;
                        }
                    }
                    if (consultorio.removerConsulta(identificador)) {
                        cout << "Consulta removida com sucesso." << endl;
                    } else {
                        cout << "Consulta não encontrada ou erro ao remover." << endl;
                    }
                }
                break;

            case 12:
                //Programa por Arthur Mendonça =)
                saida = false;
                return 0;
                break;

            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}
