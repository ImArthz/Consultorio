#ifndef EXCESSAOCONSULTAINEXISTENTE // se o header não está definido
#define EXCESSAOCONSULTAINEXISTENTE // define o header
#include "excessaoConsultaInexistente.hpp"
#include <stdexcept> // arquivo de cabeçalho stdexcept contém runtime_error
using namespace std;

class ConsultaInexistente : public runtime_error
{
public:
   // construtor especifica a mensagem de erro padrão
   ConsultaInexistente();
};

#endif
