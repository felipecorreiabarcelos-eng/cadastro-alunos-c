# Sistema de Cadastro de Alunos em C

Sistema simples de cadastro de alunos desenvolvido em linguagem C, utilizando **structs** e **vetores**, como prática da disciplina de Estrutura de Dados / Programação (3º período).

## 📋 Funcionalidades

- Cadastrar aluno (nome, idade, matrícula, curso, CPF, telefone e email)
- Listar todos os alunos cadastrados
- Buscar aluno por matrícula
- Editar dados de um aluno
- Remover aluno
- Validação para não permitir matrícula duplicada

## 🗂️ Estrutura da struct

```c
struct Aluno {
    char nome[50];
    int idade;
    int matricula;
    char curso[30];
    char cpf[15];
    char telefone[15];
    char email[50];
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
4 - Editar aluno
5 - Remover aluno
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
