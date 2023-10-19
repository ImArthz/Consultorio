# Consultório Médico

Este é um sistema simples de consultório médico que permite a gestão de médicos, pacientes e consultas. O sistema foi desenvolvido em C++.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Pré-requisitos
- Um compilador C++ instalado
- Um sistema operacional Linux ou macOS

## Diagrama de Classes

Abaixo está o diagrama de classes do projeto:

![Diagrama de Classes](https://github.com/ImArthz/Consultorio/blob/main/Consultorio.drawio.png)

Neste diagrama, você pode visualizar a estrutura e os relacionamentos das classes que compõem o sistema do Consultório.

## Funcionalidades

- Cadastrar médicos
- Remover médicos
- Cadastrar pacientes
- Remover pacientes
- Cadastrar consultas
- Remover consultas
- Imprimir dados dos médicos
- Imprimir dados dos pacientes
- Imprimir informações sobre consultas
- Abrir o repositório no GitHub

## Como Usar

### Cadastrar Médico

O método `cadastrarMedico()` permite que você cadastre um médico no sistema. Ele solicitará as seguintes informações:

- CRM do médico (deve ser um número inteiro)
- Nome completo do médico
- Sexo do médico
- Endereço do médico
- CPF do médico
- Telefone do médico
- Identidade do médico
- Especialidade do médico

Após fornecer as informações, o médico será cadastrado no sistema.

### Remover Médico

O método `removerMedico(int crm)` permite que você remova um médico do sistema. Você precisará fornecer o CRM do médico que deseja remover. Certifique-se de confirmar a remoção, pois ela é permanente.

### Cadastrar Paciente

O método `cadastraPaciente()` permite que você cadastre um paciente no sistema. Ele solicitará as seguintes informações:

- CPF do paciente
- Nome completo do paciente
- Sexo do paciente
- Endereço do paciente
- Telefone do paciente
- Identidade do paciente
- Sintomas relatados pelo paciente
- Medicação controlada consumida pelo paciente

Após fornecer as informações, o paciente será cadastrado no sistema.

### Remover Paciente

O método `removerPaciente(string cpf)` permite que você remova um paciente do sistema. Você precisará fornecer o CPF do paciente que deseja remover. Certifique-se de confirmar a remoção, pois ela é permanente.

### Cadastrar Consulta

O método `cadastrarConsulta()` permite que você agende uma consulta no sistema. Ele solicitará as seguintes informações:

- CRM do médico responsável pela consulta
- CPF do paciente que fará a consulta
- Data da consulta (dia, mês e ano)
- Hora da consulta (horas e minutos)

Após fornecer as informações, a consulta será agendada no sistema.

### Remover Consulta

O método `removerConsulta(int identificador)` permite que você remova uma consulta do sistema. Você precisará fornecer o identificador da consulta que deseja remover. Certifique-se de confirmar a remoção, pois ela é permanente.

### Imprimir Dados dos Médicos

o método `imprimirListaDeMedicos()` permite imprimir no console informações sobre todos os médicos cadastrados no sistema.

### Imprimir Dados dos Pacientes

o método `imprimirListaDePacientes()` permite imprimir no console informações sobre todos os pacientes cadastrados no sistema.

### Imprimir Informações sobre Consultas

o método `imprimirConsultas()` permite imprimir no console informações sobre todas as consultas agendadas no sistema.

### Imprimir Consulta de acordo com o identificador fornecido 

o metodo `imprimirConsultasPorIdentificador()` permite imprimir no console as informações sobre uma especifica consulta localizada através de um numero identificador.

### Abrir o Repositório no GitHub

Nesse trecho abaixo , estamos abrindo o repositório do código no GitHub em um navegador da web padrão. 
```bash
string link = "https://github.com/ImArthz/Consultorio";

// Construindo o comando para abrir a URL no navegador padrão
string command = "xdg-open " + link;

// Usando a função do sistema para executar o comando
int result = system(command.c_str());

// Verificando o resultado da chamada do sistema
if (result == 0) {
    cout << "Navegador da web aberto com sucesso." << endl;
} else {
    cerr << "Falha ao abrir o navegador da web." << endl;
}

break;
```
Aqui está a explicação:

string link contém a URL do seu repositório no GitHub.

string command é uma string que armazena o comando que será executado para abrir a URL no navegador padrão. No seu caso, está usando o comando xdg-open, que é específico para sistemas Linux. Para sistemas Windows, você pode usar start em vez de xdg-open.

system(command.c_str()) é usado para executar o comando do sistema armazenado na variável command. Isso abre o navegador da web padrão e carrega a URL fornecida.

result armazena o valor retornado pela função system. Se a chamada for bem-sucedida, result será 0. Caso contrário, será diferente de 0.

O bloco if (result == 0) verifica se a chamada do sistema foi bem-sucedida e exibe uma mensagem correspondente. Se a abertura do navegador for bem-sucedida, a mensagem "Navegador da web aberto com sucesso" é exibida. Caso contrário, a mensagem "Falha ao abrir o navegador da web" é exibida.

Esse trecho é útil para permitir que os usuários acessem facilmente o repositório do seu código no GitHub, facilitando a visualização, colaboração e download do projeto.

### Tratamento de excessão

Em várias partes do código, estamos fazendo uso da biblioteca #include <limits> para realizar o tratamento de exceções. Esse tratamento é útil para lidar com entradas de dados do usuário e garantir que essas entradas sejam válidas, especialmente quando se espera um número inteiro. O trecho de código abaixo ilustra como isso é feito:
```bash
while (true) {
    cout << "->Digite um número inteiro: " << endl;
    cin >> Nome_da_sua_variavel_inteira;

    if (cin.fail()) {
        cin.clear();  // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
        cout << "Entrada inválida. Por favor, digite um número inteiro." << endl;
    } else {
        // A entrada é válida, e podemos sair do loop
        // Outros tratamentos, como verificar se a variável está dentro de um intervalo desejado, podem ser feitos aqui.
        break;
    }
}
```
Nesse trecho, o programa solicita ao usuário que insira um número inteiro. Se o usuário fornecer um valor inválido (por exemplo, um caractere não numérico), o bloco if (cin.fail()) identifica esse erro. Em seguida, a função cin.clear() é usada para limpar o estado de erro e permitir que o programa continue a execução. Além disso, cin.ignore() é usado para descartar a entrada inválida que causou o erro. Em seguida, uma mensagem de erro é exibida para orientar o usuário.

Se o usuário inserir um número inteiro válido, o programa continuará sua execução normalmente. Esse tratamento de exceção é fundamental para evitar falhas inesperadas no programa devido a entradas incorretas. Além disso, é possível adicionar verificações adicionais, como garantir que o número esteja dentro de um intervalo específico, antes de prosseguir com o processamento dos dados.
## Lista Encadeada em C++

Uma lista encadeada é uma estrutura de dados que pode ser visualizada como uma corrente de elos de bicicleta, onde cada elo (ou nó) contém um valor de informação e uma referência para o próximo elo da corrente. Em C++, podemos criar uma lista encadeada manualmente para organizar e armazenar dados.

![Lista Encadeada](https://upload.wikimedia.org/wikipedia/commons/6/69/ListaEncadeada.jpg)

A imagem mostra como cada nó em uma lista encadeada apartir da cabeça( começo da propria ) contém um objeto e aponta para o próximo nó na lista chegando assim até a cauda(fim da propria) .

### Como Funciona?

Imagine que você tem uma série de caixas, cada uma contendo um item e um papel com um endereço para a próxima caixa. Quando você deseja acessar um item específico, você começa na primeira caixa e segue os endereços até chegar à caixa desejada. É como seguir uma trilha de informações!

### Vantagens da Lista Encadeada

- Flexibilidade: Diferentemente de um array, você pode adicionar ou remover elementos facilmente em qualquer posição da lista, pois cada nó aponta para o próximo.
- Uso eficiente de memória: A lista encadeada aloca memória conforme necessário, o que economiza recursos em comparação com a alocação estática de arrays.
- Acesso rápido ao início: Você pode acessar o primeiro item rapidamente, percorrendo apenas alguns elos.

### Exemplo em C++
```bash
// Vamos criar uma lista encadeada com três elementos
#include <iostream>

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};

    // Agora você tem uma lista com os valores 1, 2 e 3 encadeados.
    // Você pode percorrê-la usando os ponteiros "next".
    
    delete head; // Lembre-se de liberar a memória quando terminar!
    
    return 0;
}
```

Neste exemplo, criamos uma lista encadeada simples com três elementos. Você pode adicionar, remover e acessar os valores da lista usando os ponteiros `next`.

## Uso de Listas Manuais

Neste projeto, utilizo classes personalizadas para gerenciar listas de pacientes, médicos e consultas manualmente. As classes `Lista_Paciente`, `Lista_Medico` e `Lista_Consulta` são responsáveis por criar e gerenciar essas listas de objetos. Estou utilizando ponteiros para estruturar a lista, o que me permite inserir e remover elementos dinamicamente.
`Lista_Paciente.hpp` e `Lista_Medico.hpp`

Nas classes `Lista_Paciente` e `Lista_Medico`, faço uso dos atributos `head` e `tail` para acompanhar o início e o fim da lista. Esses atributos são ponteiros que apontam para o primeiro e o último elemento da lista, respectivamente:

-head: Aponta para o primeiro elemento da lista. Quando adiciono um novo paciente ou médico, ele se torna o novo “cabeça” da lista.
-tail: Aponta para o último elemento da lista. Quando adiciono um novo paciente ou médico, ele se torna o novo “rabo” da lista.

Além disso, estou utilizando o atributo prox em minhas classes de paciente e médico para criar uma relação de lista encadeada entre os elementos. Isso me permite percorrer a lista, de `head` a `tail`, usando essas referências.
`Lista_Consulta.hpp`

A classe Lista_Consulta segue uma estrutura semelhante, com atributos `head` e `tail` para rastrear o início e o fim da lista. Também uso atributos `prox` nas consultas para formar uma lista encadeada de consultas.

### Adicionar à Lista

Ao adicionar um novo elemento à lista, crio uma instância do objeto (por exemplo, um novo paciente, médico ou consulta) e, em seguida, atualizo os ponteiros `prox` para conectar o novo elemento ao último elemento da lista. Também atualizo o ponteiro `tail` para apontar para o novo elemento, indicando que ele agora é o último na lista.

### Remover da Lista

Para remover elementos da lista, encontro o elemento que desejo remover (por exemplo, com base no ID do paciente, CRM do médico ou identificador da consulta), ajusto os ponteiros `prox` para evitar o elemento que será removido e, em seguida, libero a memória alocada para o elemento.

### Benefícios de Listas Manuais

O uso de listas manuais me proporciona uma flexibilidade maior em comparação com contêineres de bibliotecas padrão, como `std::vector` ou `std::list`. Isso permite que eu gerencie os elementos de forma personalizada e implemente lógicas específicas para a aplicação.

No entanto, é importante notar que também requer um maior entendimento e responsabilidade na gestão de memória e manipulação de ponteiros. É necessário lidar corretamente com a alocação e desalocação de memória para evitar vazamentos de memória ou acesso à memória não alocada. Além disso, é preciso garantir que as operações de inserção e remoção da lista sejam tratadas com cuidado para manter a integridade da lista e evitar falhas de segmentação.

## Compilação

Para compilar o projeto, abra um terminal no diretório onde estão os arquivos-fonte (arquivos `.cpp` e `.hpp`) e o Makefile. Certifique-se de que o Makefile esteja na mesma pasta que os arquivos-fonte. Em seguida, execute o seguinte comando: 
```bash
make
```

O Makefile irá compilar todos os arquivos `.cpp` e criar o executável `Consultorio`. Os arquivos objeto compilados serão armazenados no diretório `./Consultorio`.

## Executando o Projeto

Após a compilação bem-sucedida, você pode executar o projeto usando o seguinte comando:
```bash
make run
```

Isso executará o binário `Consultorio`, que é o resultado da compilação.

## Limpeza (Removendo Arquivos Gerados)

Se você desejar remover os arquivos objeto e o binário gerado, você pode usar o comando a seguir:

```bash
make clean
```

Isso excluirá todos os arquivos `.o`, o binário `Consultorio` e quaisquer arquivos temporários (`*~`).

Certifique-se de ter o GCC (GNU Compiler Collection) instalado em seu sistema, pois o Makefile usa o compilador G++ (parte do GCC) para compilar o código C++.





## Contribuições
Contribuições são bem-vindas! Se você deseja contribuir para este projeto, siga estas etapas:

Faça um fork do repositório. Crie uma branch para a sua contribuição:
```bash
git checkout -b minha-contribuicao
```
Faça suas alterações e comite:
```bash
git commit -m "Adicionei recursos incríveis"
```
Envie suas alterações para o seu fork:
```bash
git push origin minha-contribuicao
```
Abra um pull request neste repositório original.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE). Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

**Referencias** :

* [w3school](https://www.w3schools.com/cpp/default.asp)
* [cin.ignore(numeric_limits<streamsize>::max(), '\n')](https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus)
* [lista encadeada](https://www.ime.usp.br/~coelho/mac0122-2012/aulas/aula10-3x2.pdf)

**Diagrama** 
* [Draw.io](https://www.drawio.com/)

## Dados

**Autor:** Arthur De Oliveira Mendonça 

**Redes Sociais:**

* [GitHub](https://github.com/ImArthz)
* [Twitter](https://twitter.com/Im_Arthz)

**Contato:**

* [WhatsApp](https://api.whatsapp.com/send?phone=37988528423)
* [Discord](https://discordapp.com/users/imarthz)
