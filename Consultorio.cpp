#include "Consultorio.hpp"
#include "Medico.hpp"
#include "Paciente.hpp"
#include "Consulta.hpp"
#include <iostream>
#include <string>
#include <limits> // Biblioteca para lidar com erros de leitura de inteiro
#include <random>// Biblioteca para gerar numeros aleatorios
#include "excessaoMedicoInexistente.hpp"
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
        cin.ignore();
        cout<<"->endereco: ";
        getline(cin,EnderecoMed);
        while (true) {
            cout << "->Digite o cpf do paciente : ";
            cin >> cpfMed;
            // Verifique o comprimento da string para garantir que seja um CPF válido
            if (cpfMed.length() == 11) {
                // CPF tem 11 dígitos, o que é um CPF válido
                break;
            }   else {
                cout << "CPF inválido. Digite um CPF com 11 dígitos." << endl;
            }
        }
        while (true) {
            cout << "->Telefone : ";
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
            cout << "->Identitidade : ";
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
    return true;
}

bool Consultorio::removerMedico(int crm) {
    while (true) {
        string op;
        bool encontrado = false;
        cout << "Tem certeza disso? (S/N)?" << endl;
        cout << "Ao digitar sim, o médico de CRM " << crm << " será permanentemente excluído" << endl;
        cin.ignore();
        getline(cin, op);
        if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
            try {
                medicos->Remover_Medico(crm);
                encontrado = true;
                return true;
            } catch (...) {
                throw medicoInexistente();
            }
            if (!encontrado) {
                cout << "O médico de CRM " << crm << " não foi encontrado" << endl;
            }
        } else if (op == "Não" || op == "nao" || op == "N" || op == "n") {
            cout << "Voltando ao menu" << endl;
            return false; // Sai da função se o usuário decide não excluir o médico;
        } else {
            cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
        }
    }
}
bool Consultorio::cadastraPaciente()
{
    int FonePaci,IdPaci;
    char SexoPaci;
    string cpfPaci,NomePaci, EnderecoPaci, Relato, UltimaConsu, Medicacao;
    Paciente* paciente=NULL;
    Paciente* paci=pacientes->getHead();
    while (true) {
            cout << "->Digite o cpf do paciente : ";
            cin >> cpfPaci;
            // Verifique o comprimento da string para garantir que seja um CPF válido
            if (cpfPaci.length() == 11) {
                // CPF tem 11 dígitos, o que é um CPF válido
                break;
            }   else {
                cout << "CPF inválido. Digite um CPF com 11 dígitos." << endl;
            }
        }
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
        cin.ignore();
        getline(cin, NomePaci);
        cout<<"->sexo: ";
        cin>>SexoPaci;
        cin.ignore();
        cout<<"->endereco: ";
        getline(cin,EnderecoPaci);
        while (true) {
            cout << "->Telefone : ";
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
            cout << "->Identidade : ";
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
        cin.ignore();
        getline(cin,Relato);
        cout<<"->medicação controlada consumida: ";
        getline(cin,Medicacao);
        pacientes->addPaciente(NomePaci,EnderecoPaci,cpfPaci,SexoPaci,FonePaci,IdPaci, Relato, Medicacao);
        return true;

    }

    return true;
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
                return false; // Sai da função se o usuário decide não excluir o Paciente;
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
    int crmMedico;
    int dia=0, mes=0, ano=0 ,anoaux=0;
    int horaaux,horaaux2,identificador;
    Consulta* con=consultas->getHead();
    Paciente* paci=pacientes->getHead();
    Medico* med=medicos->getHead();

    while (true) {
            cout << "->Digite o crm do medico : ";
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
            cout << "->Digite o cpf do paciente : ";
            cin >> cpfPaciente;
            // Verifique o comprimento da string para garantir que seja um CPF válido
            if (cpfPaciente.length() == 11) {
                // CPF tem 11 dígitos, o que é um CPF válido
                break;
            }   else {
                cout << "CPF inválido. Digite um CPF com 11 dígitos." << endl;
            }
        }
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
        while (true) {
            bool saidaaux= true;
            cout << "->Digite o dia da consulta : ";
            cin.ignore();
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
            cout << "->Digite o mes da consulta";
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
            cout << "->Digite o ano da consulta";
            cin >> ano;

            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
                saidaaux=false;
            } else {
                if(ano>2035 || ano<2022){
                cout<<"ano invalido\n";
                cout<<"Nossa agenda permite cadastro de consultas de 2023 até 2034"<<endl;
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
            cout << "->Digite a hora : ";
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
                else if(horaaux>=18||horaaux<=6){
                    cout<<"Desculpa so atendemos nos horarios de 06:00 até as 18:00"<<endl;
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
            cout << "->Digite os minutos : " ;
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
        int identificador = anoaux*1000 + dist(mt);
        cout<<"Numero identificador da Consulta = "<<identificador<<endl;

        string hora = to_string(horaaux)+":"+to_string(horaaux2);

        
        consultas->add_Consulta(data, hora,cpfPaciente,crmMedico,identificador);
        return true;
    }
    return true;
}

bool Consultorio::removerConsulta(int identificador)
    {
        while(true){
            string op;
            bool encontrado = false;
            cout << "Tem certeza disso ?  (S/N)?" << endl;
            cout <<" Ao digitar sim a consulta de identificador "<<identificador<< " sera permanentemente excluida"<<endl;
            cin.ignore();
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
                return false ; // Sai da função se o usuário decide não excluir a consulta;
            }
    
            else 
            {
                cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
            }
        }
        
    }
void Consultorio::imprimirListaDePacientes(){
    cout << "\tImprimindo paciente...\t\n";
	pacientes->Imprimir_Paciente();
}
void Consultorio::imprimirListaDeMedicos(){
    cout << "\tImprimindo medicos...\t\n";
			medicos->Imprimir_Medico();

}
void Consultorio::imprimirConsultas(){
    cout << "\tImprimindo Consultas...\t\n";
			consultas->Imprimir_Consulta();
}
void Consultorio::imprimirConsultasPorIdentificador(){
    int identificador;
    Consulta* consu=consultas->getHead();
    while (true) {
            cout << "->Digite o identificador da Consulta: " << endl;
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
    while(consu)
    {
        if(consu->getIdentificador()==identificador){
        cout<<"=====================================================";
        cout<<endl;
	cout<< "Identificador  :"<<consu->getIdentificador()<<endl;
        cout << "data  : " << consu->getData()<< endl;
        cout << "horario : " << consu->getHora() << endl;
        cout << "CPF do paciente : " << consu->getcpfPaciente() << endl;
        cout << "CRM do medico : "<< consu->getcrmMedico() << endl;
        cout<<endl;
        cout<<"=====================================================\n";
        }
        consu=consu->getProx();
    }
}
