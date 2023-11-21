#ifndef _EXCESSAOMEDICOINEXISTENTE_HPP // se o header não está definido
#define _EXCESSAOMEDICOINEXISTENTE_HPP// define o header
#include "excessaoMedicoInexistente.hpp"
#include <stdexcept> // arquivo de cabeçalho stdexcept contém runtime_error 
using namespace std;

class medicoInexistente : public runtime_error 
{
public:
   // construtor especifica a mensagem de erro padrão
   medicoInexistente();
};



#endif
