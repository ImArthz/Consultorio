#if !defined(EXCESSAOSEXOINDF_HPP)
#define EXCESSAOSEXOINDF_HPP
#include "excessaoSexoindf.hpp"
#include <stdexcept> // arquivo de cabeçalho stdexcept contém runtime_error
using namespace std;
class sexoIndf : public runtime_error
{
public:
    sexoIndf();
};
#endif // MACRO
