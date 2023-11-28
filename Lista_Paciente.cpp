#include<iostream> 
#include "Lista_Paciente.hpp"
#include "excessaoPacienteInexistente.hpp"
int ListaPaciente:: contador_Paciente=1;
using namespace std;

ListaPaciente::ListaPaciente(string nome,string endereco, string cpf,char sexo, int telefone, int identidade, string relato, string Med_controlada){
    head = new Paciente(nome,endereco, cpf,sexo, telefone, identidade, relato, Med_controlada); 
    tail = head;  
}
ListaPaciente::ListaPaciente(){
    head = NULL;
	tail = NULL;
}

bool ListaPaciente::vazia() 
{
    return (head==NULL);
}
ListaPaciente::~ListaPaciente(){
  Paciente* atual = head;
  while (atual != NULL)
  {
  Paciente* temp = atual;
  atual = atual->getProx();
  delete temp;
  }
}

Paciente* ListaPaciente::getHead(){
    return head;
}
void ListaPaciente::setHead(Paciente* head){
    this->head=head;
}
Paciente* ListaPaciente::getTail(){
    return tail;
}
void ListaPaciente::setTail(Paciente* tail){
    this->tail=tail;
}
void ListaPaciente:: addPaciente(string nome,string endereco, string cpf,char sexo, int telefone, int identidade, string relato, string Med_controlada){
    Paciente* p=new Paciente(nome,endereco, cpf, sexo, telefone, identidade, relato, Med_controlada);
    if(vazia())
{
        head=p;
        tail=p;
}
    else{
        tail->setProx(p);
        tail=head;
}

}
void ListaPaciente::Remover_Paciente(string cpf){
    bool encontrado = false;

    if(vazia())
	cout << "Não há nenhum paciente cadastrado\n";
	else if(head->getProx()==NULL && head->getCpf()==cpf)
	{
		delete head; // Libera memória
                head = NULL;
                tail = NULL; // A cauda também deve ser atualizada
        }
        else if(head->getProx()==NULL && head->getCpf()!=cpf)
        {
          throw pacienteInexistente();
        }
	else if(head->getProx()->getProx()==NULL && head->getCpf()==cpf){
		head=head->getProx();
	}
	else if(head->getProx()->getProx()==NULL && head->getProx()->getCpf()==cpf){
		head->setProx(NULL);
        tail=head;
	}
	else{
		Paciente* previous=head;
		Paciente* i=head->getProx();
		Paciente* next=head->getProx()->getProx();
		while(next){
			if(head->getCpf()==cpf){
				head=head->getProx();
			}
			else if(i->getCpf()==cpf){
				previous->setProx(next);
				free(i);
			}
			previous=i;
			i=next;
			next=next->getProx();
		}
		if(i->getCpf()==cpf)
        {               
                        encontrado = true;
			previous->setProx(NULL);
			free(i);
			tail=previous;
	    }
	    if(!encontrado)
	    {
	      throw pacienteInexistente();
	    }
    }
}

void ListaPaciente:: Imprimir_Paciente(){
    Paciente* p=head;
    if(vazia())
    {
        head=p;
        tail=p;
        cout<<"\n Não tem pacientes cadastrados!! \n";
    }
    else{
        while(p){
        cout<<"----------------Paciente "<<contador_Paciente++<<"----------------";
        cout<<endl;
        cout << "nome: \t\t" << p->getNome() << endl;
        cout << "sexo: " << p->getSexo() << endl;
        cout << "endereço: "<< p->getEndereco() << endl;
        cout << "cpf: " << p->getCpf() << endl;
        cout << "telefone " << p->getTel() << endl;
        cout << "identidade: "<< p->getID() << endl;
        cout << "relato: " << p->getRelato() << endl;
        cout << "Medicação Controlada consumida: " << p->getMedCon() << endl;
        cout<<endl;
        cout<<"---------------------------------------------------\n";
        p=p->getProx();
        }
    }
}
