#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

// ===== Definição da struct Aluno =====
struct Aluno {
    char nome[50];
    int idade;
    int matricula;
    char curso[30];
    char cpf[15];
    char telefone[15];
    char email[50];
};

// ===== Variáveis globais =====
struct Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0; // controla quantos alunos já foram cadastrados

// ===== Protótipos das funções =====
void cadastrarAluno();
void listarAlunos();
void buscarAluno();
void editarAluno();
void removerAluno();
void limparBufferEntrada();
int buscarIndicePorMatricula(int matricula);

int main() {
    int opcao;

    do {
        printf("\n===== SISTEMA DE CADASTRO DE ALUNOS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno por matricula\n");
        printf("4 - Editar aluno\n");
        printf("5 - Remover aluno\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                buscarAluno();
                break;
            case 4:
                editarAluno();
                break;
            case 5:
                removerAluno();
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

// Limpa o buffer do teclado (evita problemas ao misturar scanf e fgets)
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastra um novo aluno no vetor de structs
void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite maximo de alunos atingido!\n");
        return;
    }

    struct Aluno novoAluno;

    printf("\n--- Cadastro de novo aluno ---\n");

    printf("Nome: ");
    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0'; // remove o \n do fgets

    printf("Idade: ");
    scanf("%d", &novoAluno.idade);
    limparBufferEntrada();

    printf("Matricula: ");
    scanf("%d", &novoAluno.matricula);
    limparBufferEntrada();

    // Verifica se ja existe aluno com essa matricula
    if (buscarIndicePorMatricula(novoAluno.matricula) != -1) {
        printf("Erro: ja existe um aluno cadastrado com essa matricula!\n");
        return;
    }

    printf("Curso: ");
    fgets(novoAluno.curso, sizeof(novoAluno.curso), stdin);
    novoAluno.curso[strcspn(novoAluno.curso, "\n")] = '\0';

    printf("CPF: ");
    fgets(novoAluno.cpf, sizeof(novoAluno.cpf), stdin);
    novoAluno.cpf[strcspn(novoAluno.cpf, "\n")] = '\0';

    printf("Telefone: ");
    fgets(novoAluno.telefone, sizeof(novoAluno.telefone), stdin);
    novoAluno.telefone[strcspn(novoAluno.telefone, "\n")] = '\0';

    printf("Email: ");
    fgets(novoAluno.email, sizeof(novoAluno.email), stdin);
    novoAluno.email[strcspn(novoAluno.email, "\n")] = '\0';

    alunos[totalAlunos] = novoAluno;
    totalAlunos++;

    printf("Aluno cadastrado com sucesso!\n");
}

// Lista todos os alunos cadastrados
void listarAlunos() {
    if (totalAlunos == 0) {
        printf("\nNenhum aluno cadastrado ainda.\n");
        return;
    }

    printf("\n=== Dados dos Alunos Cadastrados (%d) ===\n", totalAlunos);
    for (int i = 0; i < totalAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n", alunos[i].curso);
        printf("CPF: %s\n", alunos[i].cpf);
        printf("Telefone: %s\n", alunos[i].telefone);
        printf("Email: %s\n", alunos[i].email);
    }
}

// Retorna o indice do aluno no vetor a partir da matricula, ou -1 se nao existir
int buscarIndicePorMatricula(int matricula) {
    for (int i = 0; i < totalAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

// Busca um aluno pela matricula e mostra os dados dele
void buscarAluno() {
    int matricula;
    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &matricula);
    limparBufferEntrada();

    int indice = buscarIndicePorMatricula(matricula);

    if (indice == -1) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    printf("\n--- Aluno encontrado ---\n");
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Idade: %d\n", alunos[indice].idade);
    printf("Matricula: %d\n", alunos[indice].matricula);
    printf("Curso: %s\n", alunos[indice].curso);
    printf("CPF: %s\n", alunos[indice].cpf);
    printf("Telefone: %s\n", alunos[indice].telefone);
    printf("Email: %s\n", alunos[indice].email);
}

// Edita os dados de um aluno ja cadastrado
void editarAluno() {
    int matricula;
    printf("\nDigite a matricula do aluno que deseja editar: ");
    scanf("%d", &matricula);
    limparBufferEntrada();

    int indice = buscarIndicePorMatricula(matricula);

    if (indice == -1) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    printf("Editando aluno: %s\n", alunos[indice].nome);

    printf("Novo nome: ");
    fgets(alunos[indice].nome, sizeof(alunos[indice].nome), stdin);
    alunos[indice].nome[strcspn(alunos[indice].nome, "\n")] = '\0';

    printf("Nova idade: ");
    scanf("%d", &alunos[indice].idade);
    limparBufferEntrada();

    printf("Novo curso: ");
    fgets(alunos[indice].curso, sizeof(alunos[indice].curso), stdin);
    alunos[indice].curso[strcspn(alunos[indice].curso, "\n")] = '\0';

    printf("Novo telefone: ");
    fgets(alunos[indice].telefone, sizeof(alunos[indice].telefone), stdin);
    alunos[indice].telefone[strcspn(alunos[indice].telefone, "\n")] = '\0';

    printf("Novo email: ");
    fgets(alunos[indice].email, sizeof(alunos[indice].email), stdin);
    alunos[indice].email[strcspn(alunos[indice].email, "\n")] = '\0';

    printf("Dados atualizados com sucesso!\n");
}

// Remove um aluno do vetor, deslocando os elementos seguintes uma posicao para tras
void removerAluno() {
    int matricula;
    printf("\nDigite a matricula do aluno que deseja remover: ");
    scanf("%d", &matricula);
    limparBufferEntrada();

    int indice = buscarIndicePorMatricula(matricula);

    if (indice == -1) {
        printf("Aluno com matricula %d nao encontrado.\n", matricula);
        return;
    }

    for (int i = indice; i < totalAlunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    totalAlunos--;
    printf("Aluno removido com sucesso!\n");
}
