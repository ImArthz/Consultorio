# Consultório Médico

Este é um sistema simples de consultório médico que permite a gestão de médicos, pacientes e consultas. O sistema foi desenvolvido em C++.
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

## Pré-requisitos
- Um compilador C++ instalado
- Um sistema operacional Linux ou macOS

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

Essa opção abrirá o repositório do projeto no GitHub no navegador da web.

## Como Executar

Para compilar o projeto, abra um terminal no diretório onde estão os arquivos-fonte (arquivos `.cpp` e `.hpp`) e o Makefile. Certifique-se de que o Makefile esteja na mesma pasta que os arquivos-fonte. Em seguida, execute o seguinte comando: 
```bash
make
```

O Makefile irá compilar todos os arquivos `.cpp` e criar o executável `Consultorio`. Os arquivos objeto compilados serão armazenados no diretório `./objects`.

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

**Autor:** Arthur De Oliveira Mendonça 

**Redes Sociais:**

* [GitHub](https://github.com/ImArthz)
* [Twitter](https://twitter.com/Im_Arthz)

**Contato:**

* [WhatsApp](https://api.whatsapp.com/send?phone=37988528423)
* [Discord](https://discordapp.com/users/imarthz)
