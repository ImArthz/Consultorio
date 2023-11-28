#ifndef EXCESSAOPACIENTEINEXISTENTE // se o header não está definido
#define EXCESSAOPACIENTEINEXISTENTE // define o header
#include "excessaoPacienteInexistente.hpp"
#include <stdexcept> // arquivo de cabeçalho stdexcept contém runtime_error
using namespace std;

class pacienteInexistente : public runtime_error
{
public:
   // construtor especifica a mensagem de erro padrão
   pacienteInexistente();
};

#endif
