# Sistema de Cadastro de Alunos em C

Sistema simples de cadastro de alunos desenvolvido em linguagem C, utilizando **structs** e **vetores**, como prática da disciplina de Estrutura de Dados / Programação (3º período).

## 📋 Funcionalidades

- Cadastrar aluno (nome, idade, matrícula, curso, CPF, telefone, email, disciplina e nota)
- Listar todos os alunos cadastrados
- Buscar aluno por matrícula
- Buscar aluno por nome
- Editar dados de um aluno
- Remover aluno
- Validação para não permitir matrícula duplicada

## 🗂️ Estrutura da struct

```c
struct Aluno {
    char nome[60];
    int idade;
    int matricula;
    char curso[40];
    char cpf[20];
    char telefone[20];
    char email[60];
    char disciplina[40];
    float nota;
};
```

## ▶️ Como compilar e executar

Requisitos: compilador **GCC** instalado.

```bash
gcc -Wall -o cadastro_alunos cadastro_alunos.c
./cadastro_alunos
```

No Windows (usando o executável gerado):

```bash
gcc -Wall -o cadastro_alunos.exe cadastro_alunos.c
cadastro_alunos.exe
```

## 🖥️ Exemplo de uso

```
===== SISTEMA DE CADASTRO DE ALUNOS =====
1 - Cadastrar aluno
2 - Listar alunos
3 - Buscar aluno por matricula
4 - Buscar aluno por nome
5 - Editar aluno
6 - Remover aluno
0 - Sair
Escolha uma opcao:
```

## 🚀 Possíveis melhorias futuras

- Salvar os dados em arquivo (persistência com `.txt` ou `.csv`)
- Usar alocação dinâmica de memória (`malloc`/`realloc`) em vez de vetor fixo
- Migrar o vetor para uma lista encadeada
- Adicionar validação de CPF e email

## 🛠️ Tecnologias

- Linguagem C
- Compilador GCC

## 👤 Autor

Projeto acadêmico desenvolvido como prática de structs em C.
