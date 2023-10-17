#include "Consultorio.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"
#include "Consulta.hpp"
#include <iostream>
#include <string>
#include <limits> // Biblioteca para lidar com erros de leitura de inteiro
#include <random>// Biblioteca para gerar numeros aleatorios
using namespace std;

Consultorio::Consultorio(ListaMedico* medicos, ListaPaciente* pacientes, ListaConsulta* consultas, string nome, string endereco, int telefone){
    this-> medicos=medicos;
    this->pacientes=pacientes;
    this->consultas=consultas;
    this->nome=nome;
    this->endereco=endereco;
    this->telefone=telefone;
}
Consultorio::Consultorio()
{
    this->medicos=new ListaMedico();
    this->pacientes= new ListaPaciente();
    this->consultas= new ListaConsulta();
}
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
bool Consultorio::cadastrarMedico() {
    char SexoMed;
    string NomeMed, EnderecoMed, cpfMed,especialidade;
    int CRM, CRMverifica,FoneMed, IdMed;
    Medico* medico=NULL;
    Medico* med=medicos->getHead();
    while (true) {
            cout << "->Digite o crm do medico: " << endl;
            cin >> CRMverifica;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
    while(med)
    {
        if(med->getCrm()==CRMverifica){
            medico=med;
            cout<<"\nMedico ja foi cadastrado\n";
            return false;
        }
        med=med->getProx();
    }
    if(medico==NULL)
    {
        cout<<"\n->nome completo: ";
        cin.ignore();
        getline(cin, NomeMed);
        cout<<"->sexo: ";
        cin>>SexoMed;
        cout<<"->endereco: ";
        getline(cin,EnderecoMed);
        cout<<"->CPF: ";
        getline(cin,cpfMed);
        while (true) {
            cout << "->Telefone : " << endl;
            cin >> FoneMed;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
        while (true) {
            cout << "->Identitidade" << endl;
            cin >> IdMed;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
        //crm usada a anterior
        cout<<"->especialização : ";
        cin.ignore();
        getline(cin,especialidade);
        medicos->addMedico( NomeMed, SexoMed, EnderecoMed, cpfMed, FoneMed, IdMed, CRMverifica, especialidade);
        return true;
    }
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
                
                medicos->Remover_Medico(crm);
                encontrado=true;
                return true;
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
bool Consultorio::cadastraPaciente()
{
    int FonePaci,IdPaci;
    char SexoPaci;
    string cpfPaci,NomePaci, EnderecoPaci, Relato, UltimaConsu, Medicacao ;
    Paciente* paciente=NULL;
    Paciente* paci=pacientes->getHead();
    cout<<"->digite o cpf do paciente :"<<endl;
    cin.ignore();
    getline(cin,cpfPaci);
    while(paci)
    {
        if(paci->getCpf()==cpfPaci){
            paciente=paci;
            cout<<"\n Paciente ja esta cadastrado\n";
            return false ;
        }
        paci=paci->getProx();
    }
    if(paciente==NULL)
    {
        cout<<"\n->nome completo: ";
        getline(cin, NomePaci);
        cout<<"->sexo: ";
        cin>>SexoPaci;
        cout<<"->endereco: ";
        getline(cin,EnderecoPaci);
        //usado o cpf anterior 
        while (true) {
            cout << "->Telefone" << endl;
            cin >> FonePaci;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
        while (true) {
            cout << "->Identidade" << endl;
            cin >> IdPaci;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
        cout<<"->Informe os sintomas: ";
        getline(cin,Relato);
        cout<<"->medicação controlada consumida: ";
        getline(cin,Medicacao);
    
        pacientes->addPaciente(NomePaci,SexoPaci,EnderecoPaci,cpfPaci, FonePaci, IdPaci, Relato, Medicacao);
        return true;

    }
}
bool Consultorio::removerPaciente(string cpf)
    {
        while(true){
            string op;
            bool encontrado = false;
            cout << "Tem certeza disso ?  (S/N)?" << endl;
            cout <<" Ao digitar sim o Paciente de cpf "<<cpf<< " sera permanentemente excluido"<<endl;
            //cin.ignore(); não é nescessario pois é tratado se nao for s/n
            getline(cin, op);
            if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
                pacientes->Remover_Paciente(cpf);
                encontrado = true;    
                return true; // Paciente removido com sucesso
            
                if (!encontrado) {
                    cout << "O Paciente de Cpf: " << cpf << " não foi encontrado" << endl;
                    return false; // Paciente não encontrado

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
bool Consultorio::cadastrarConsulta(){
    string hora,data,cpfPaciente; 
    bool verificaMed=false, verificaPaci=false;
    int crmMedico,cpfPaciente_;
    int dia=0, mes=0, ano=0 ,anoaux=0;
    int horaaux,horaaux2,identificador;
    Consulta* con=consultas->getHead();
    Paciente* paci=pacientes->getHead();
    Medico* med=medicos->getHead();

    while (true) {
            cout << "->Digite o crm do medico" << endl;
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

    while (true) {
            cout << "->Digite o cpf do paciente" << endl;
            cin >> cpfPaciente_;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
        cpfPaciente = cpfPaciente_;
    while(med)
    {
        if(med->getCrm()==crmMedico){
            verificaMed=true;
            cout<<"\nMedico esta atendendo! proxima etapa...";
            break;
        }
        med=med->getProx();
    }
    while(paci){
        if(paci->getCpf()==cpfPaciente){
            verificaPaci=true;
            cout<<"\nPaciente esta cadastrado! Vamos para a proxima etapa...\n";
            break;
        }
        paci=paci->getProx();
    }
    if(!verificaMed){
        cout<<"\n Desculpe não temos medicos atendendo no momento";
        return false;
    }
    if(!verificaPaci){
        cout<<"\n Vocẽ ainda não é um paciente cadastrado";
        return false;
    }
    if(verificaMed && verificaPaci)
    {
        cout<<"\n-> Informe o CPF do paciente: ";
        cin.ignore();
        getline(cin, cpfPaciente);
        while (true) {
            cout << "->Digite o crm do medico" << endl;
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
        while (true) {
            bool saidaaux= true;
            cout << "->Digite o dia da consulta" << endl;
            cin >> dia;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
                saidaaux = false;
            } else {
                if(dia>31 || dia<1){
                cout<<"Dia invalido\n";
                saidaaux = false;
                
            }
                if(saidaaux)
                {
                    // Entrada válida, podemos sair do loop
                    break;
                }
            }   
        }
        while (true) {
            bool saidaaux= true;
            cout << "->Digite o mes da consulta" << endl;
            cin >> mes;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
                saidaaux = false;
            } else {
                if(mes>12 || mes<1){
                cout<<"mes invalido\n";
                saidaaux = false;
                }
            }
                if(saidaaux)
                {
                    break;
                }
            }
            
        while (true) {
            bool saidaaux= true;
            cout << "->Digite o ano da consulta" << endl;
            cin >> ano;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
                saidaaux=false;
            } else {
                if(ano>2035 || ano<2022){
                cout<<"ano invalido\n";
                saidaaux = false;
                
            }
                if(saidaaux)
                {
                    // Entrada válida, podemos sair do loop
                    break;
                }
            }   
        }
        anoaux = ano;
        string data = to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano);
        while (true) {
            bool aux = true;
            cout << "->Digite a hora " << endl;
            cin >> horaaux;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
                aux = false;
            } else {
                if(horaaux>24 || horaaux<0){
                    cout<<"Hora invalida!\n";  
                    aux = false;
                    }
            }
            if (aux)
            {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
            while (true) {
            bool aux = true;
            cout << "->Digite os minutos" << endl;
            cin >> horaaux2;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
                aux = false;
            } else {
                if(horaaux2>60 || horaaux2<0){
                    cout<<"minutos invalida!\n";  
                    aux = false;
                    }
            }
            if (aux)
            {
                // Entrada válida, podemos sair do loop
                break;
            }
        }
        //funções da biblioteca para gerar numero identificador 
        random_device rd;
        mt19937 mt(rd());
        // Defina o intervalo e gere números inteiros com até 3 dígitos.
        std::uniform_int_distribution<int> dist(100, 999);
        int identificador = anoaux + dist(mt);
        cout<<"Numero identificador da Consulta = "<<identificador<<endl;

        string hora = to_string(horaaux)+":"+to_string(horaaux2);

        
        consultas->add_Consulta(data, hora,crmMedico,cpfPaciente_,identificador);
        return true;
    }
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
                consultas->Remover_Consulta(identificador);
                encontrado = true;
                return true; // Consulta removida com sucesso     
                if (!encontrado) {
                    cout << "A Consulta de Identificador: " << identificador<< " não foi encontrada" << endl;
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
