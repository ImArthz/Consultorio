#include<iostream> 
#include "Lista_Medico.hpp"
#include "excessaoMedicoInexistente.hpp"
int ListaMedico:: contador_Medico=1;
using namespace std;

ListaMedico::ListaMedico(string nome,char sexo, string endereco, string cpf, int telefone, int identidade, int crm, string especializacao){
    head = new Medico( nome,sexo,endereco, cpf,telefone,identidade,crm,especializacao);
	tail = head;  
}
ListaMedico::ListaMedico(){
    head = NULL;
    tail = NULL;
}
ListaMedico::~ListaMedico() // destrutor
{
Medico* atual = head;
while (atual != NULL)
{
Medico* temp = atual;
atual = atual->getProx();
delete temp;
}
}

bool ListaMedico::vazia() 
{
    return (head==NULL);
}
Medico* ListaMedico::getHead(){
    return head;
}
void ListaMedico::setHead(Medico* head){
    this->head=head;
}
Medico* ListaMedico::getTail(){
    return this->tail;
}
void ListaMedico::setTail(Medico* tail){
    this->tail=tail;
}
void ListaMedico:: addMedico(string nome,char sexo, string endereco, string cpf, int telefone, int identidade, int crm, string especializacao){
    Medico* med=new Medico(nome,sexo,endereco,cpf,telefone,identidade,crm, especializacao); 
    if(vazia())
    {
        head=med;
        tail=med;
    }
    else{
        tail->setProx(med);
        tail=med;
    }

}
void ListaMedico::Remover_Medico(int crm){
    bool encontrada = false;

    if(vazia())
    {
	cout << "Não há nenhum medico cadastrado \n";
        return ;
    }
	else if(head->getProx()==NULL && head->getCrm()==crm)
	{
		delete head; // Libera memória
                head = NULL;
                tail = NULL; // A cauda também deve ser atualizada
        }
	else if(head->getProx()==NULL && head->getCrm()!=crm)
	        throw medicoInexistente();
	else if(head->getProx()->getProx()==NULL && head->getCrm()==crm){
		head=head->getProx();
	}
	else if(head->getProx()->getProx()==NULL && head->getProx()->getCrm()==crm){
		head->setProx(NULL);
        tail=head;
	}
	else{
		Medico* previous=head;
		Medico* i=head;
		Medico* next=head->getProx();
		
		while(next){
			if(head->getCrm()==crm){
				head=head->getProx();
			}
			else if(i->getCrm()==crm){
				previous->setProx(next);
				free(i);
			}
			previous=i;
			i=next;
			next=next->getProx();
		}
		if(i->getCrm()==crm)
        {
                      encontrada = true;
		      previous->setProx(NULL);			
		      tail=previous;
                      free(i);
	    }
	    if (!encontrada)
	    {
	      throw medicoInexistente();
	    }
    }
}


void ListaMedico:: Imprimir_Medico(){
    Medico* med=head;
    if(vazia())
    {
        head=med;
        tail=med;
        cout<<"\n Não há medicos cadastrados!! \n";
    }
    else{
        while(med){
        cout<<"-----------------medicos: "<<contador_Medico++<<"-------------------";
        cout<<endl;
        cout << "nome: " << med->getNome() << endl;
        cout << "sexo: " << med->getSexo() << endl;
        cout << "endereço: "<< med->getEndereco() << endl;
        cout << "cpf : " << med->getCpf() << endl;
        cout << "telefone : " << med->getTel() << endl;
        cout << "identidade: "<< med->getID() << endl;
        cout << "CRM : " << med->getCrm() << endl;
        cout << "especialização : " << med->getEsp() << endl;
        cout<<endl;
        cout<<"--------------------------------------------------------------\n";
        med=med->getProx();
        }
    }
}
