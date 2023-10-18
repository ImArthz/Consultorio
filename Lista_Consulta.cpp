#include<iostream> 
#include "Lista_Consulta.hpp"
#include <string>
using namespace std;

ListaConsulta::ListaConsulta(string data,string hora, string cpfPaciente, int crmMedico,int identificador){
    head = new Consulta(data, hora, cpfPaciente, crmMedico,identificador);
	tail = head;  
}
ListaConsulta::ListaConsulta(){
    head = NULL;
	tail = NULL;
}

bool ListaConsulta::vazia() 
{
    return (head==NULL);
}
ListaConsulta::~ListaConsulta(){
    delete head;
}

Consulta* ListaConsulta::getHead(){
    return this->head;
}
void ListaConsulta::setHead(Consulta* head){
    this->head=head;
}
Consulta* ListaConsulta::getTail(){
    return this->tail;
}
void ListaConsulta::setTail(Consulta* tail){
    this->tail=tail;
}
void ListaConsulta:: add_Consulta(string data, string hora, string cpfPaciente, int crmMedico,int identificador){
    Consulta* cons=new Consulta(data, hora, cpfPaciente, crmMedico,identificador);
    if(vazia())
    {
        head=cons;
        tail=cons;
    }
    else if(!existe(cons->getData(), hora,crmMedico, cpfPaciente,identificador)){
        tail->setProx(cons);
        tail=cons;
    }
    else{
        cout<<"Consulta ja existe neste dia e horario";
    }
}
void ListaConsulta::Remover_Consulta(int identificador){


    if(vazia())
	cout << "Não há nenhum paciente agendado para consulta\n";
	else if(head->getProx()==NULL && head->getIdentificador() == identificador)
		head=NULL;
	else if(head->getProx()->getProx()==NULL && head->getIdentificador()==identificador){
		head=head->getProx();
	}
	else if(head->getProx()->getProx()==NULL && head->getProx()->getIdentificador()==identificador){
		head->setProx(NULL);
		tail=head;
	}
	else{
		Consulta* previous=head;
		Consulta* i=head->getProx();
		Consulta* next=head->getProx()->getProx();
		while(next){
			if(head->getIdentificador()==identificador){
				head=head->getProx();
			}
			else if(i->getIdentificador()==identificador){
				previous->setProx(next);
				free(i);
			}
			previous=i;
			i=next;
			next=next->getProx();
		}
		if(i->getIdentificador()==identificador)
        {
			previous->setProx(NULL);
			free(i);
			tail=previous;
	    }
    }
}
void ListaConsulta:: Imprimir_Consulta(){
    Consulta* cons=head;
    if(vazia())
    {
        head=cons;
        tail=cons;
        cout<<"\n Não ha consultas!! \n";
    }
    else{
        while(cons){
        cout<<"---------------------------------------------------------------";
        cout<<endl;
        cout << "Identificador :" << cons->getIdentificador()<<endl;
        cout << "Data : " << cons->getData()<<endl;
        cout << "Hora: " << cons->getHora() << endl;
        cout << "CPF do paciente: " << cons->getcpfPaciente() << endl;
        cout << "CRM do medico: "<< cons->getcrmMedico() << endl;
        cout<<endl;
        cout<<"---------------------------------------------------------------";
        cons=cons->getProx();
        }
    }
}

bool ListaConsulta::existe(string data,string hora,int crmMedico, string cpfPaciente,int identificador)
{
    if(vazia())
    return false;

    Consulta*aux= head;

    while(aux)
    {
        if(aux->getcrmMedico()== crmMedico && aux->getData()==data && aux->getHora()==hora)
        {
            return true;
        }
        aux=aux->getProx();
    }
	aux=head;
	while(aux)
    {
        if(aux->getcpfPaciente()==cpfPaciente && aux->getData()==data && aux->getHora()==hora)
        {
            return true;
        }
        aux=aux->getProx();
    }
    return false;
}