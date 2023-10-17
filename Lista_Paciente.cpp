#include<iostream> 
#include "Lista_Paciente.hpp"
int ListaPaciente:: contador_Paciente=1;
using namespace std;

ListaPaciente::ListaPaciente(string nome,char sexo, string endereco, string cpf, int telefone, int identidade, string relato, string Med_controlada){
    head = new Paciente(nome, sexo, endereco, cpf, telefone, identidade, relato, Med_controlada); 
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
    delete head;
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
void ListaPaciente:: addPaciente(string nome,char sexo, string endereco, string cpf, int telefone, int identidade, string relato, string Med_controlada){
   Paciente* p=new Paciente(nome, sexo, endereco, cpf, telefone, identidade, relato, Med_controlada);
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

    if(vazia())
	cout << "Não há nenhum paciente cadastrado\n";
	else if(head->getProx()==NULL && head->getCpf()==cpf)
		head=NULL;
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
			previous->setProx(NULL);
			free(i);
			tail=previous;
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
        cout << "sexo: \t" << p->getSexo() << endl;
        cout << "endereço: \t"<< p->getEndereco() << endl;
        cout << "cpf: \t" << p->getCpf() << endl;
        cout << "telefone \t" << p->getTel() << endl;
        cout << "identidade: \t"<< p->getID() << endl;
        cout << "relato: \t" << p->getRelato() << endl;
        cout << "Medicação Controlada consumida: " << p->getMedCon() << endl;
        cout<<endl;
        cout<<"---------------------------------------------------\n";
        p=p->getProx();
        }
   }
}