#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

// ===== Definição da struct Aluno =====
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

// ===== Variáveis globais =====
struct Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0; // controla quantos alunos já foram cadastrados

// ===== Protótipos das funções =====
void cadastrarAluno();
void listarAlunos();
void buscarPorMatricula();
void buscarPorNome();
void editarAluno();
void removerAluno();
void limparBufferEntrada();
int buscarIndicePorMatricula(int matricula);
int buscarIndicePorNome(char nome[]);
void exibirAluno(int indice);

int main() {
    int opcao;

    do {
        printf("\n===== SISTEMA DE CADASTRO DE ALUNOS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno por matricula\n");
        printf("4 - Buscar aluno por nome\n");
        printf("5 - Editar aluno\n");
        printf("6 - Remover aluno\n");
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
                buscarPorMatricula();
                break;
            case 4:
                buscarPorNome();
                break;
            case 5:
                editarAluno();
                break;
            case 6:
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

    printf("Disciplina: ");
    fgets(novoAluno.disciplina, sizeof(novoAluno.disciplina), stdin);
    novoAluno.disciplina[strcspn(novoAluno.disciplina, "\n")] = '\0';

    printf("Nota: ");
    scanf("%f", &novoAluno.nota);
    limparBufferEntrada();

    alunos[totalAlunos] = novoAluno;
    totalAlunos++;

    printf("Aluno cadastrado com sucesso!\n");
}

// Exibe todos os dados de um aluno pelo indice no vetor
void exibirAluno(int indice) {
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Idade: %d\n", alunos[indice].idade);
    printf("Matricula: %d\n", alunos[indice].matricula);
    printf("Curso: %s\n", alunos[indice].curso);
    printf("CPF: %s\n", alunos[indice].cpf);
    printf("Telefone: %s\n", alunos[indice].telefone);
    printf("Email: %s\n", alunos[indice].email);
    printf("Disciplina: %s\n", alunos[indice].disciplina);
    printf("Nota: %.2f\n", alunos[indice].nota);
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
        exibirAluno(i);
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

// Retorna o indice do primeiro aluno no vetor com esse nome, ou -1 se nao existir
int buscarIndicePorNome(char nome[]) {
    for (int i = 0; i < totalAlunos; i++) {
        if (strcmp(nome, alunos[i].nome) == 0) {
            return i; // encontrou: retorna e para a busca aqui mesmo
        }
    }
    return -1;
}

// Busca um aluno pela matricula e mostra os dados dele
void buscarPorMatricula() {
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
    exibirAluno(indice);
}

// Busca um aluno pelo nome e mostra os dados dele
void buscarPorNome() {
    char nome[60];
    printf("\nDigite o nome do aluno: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int indice = buscarIndicePorNome(nome);

    if (indice == -1) {
        printf("Registro nao encontrado!\n");
        return;
    }

    printf("\n--- Registro encontrado ---\n");
    exibirAluno(indice);
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

    printf("Nova disciplina: ");
    fgets(alunos[indice].disciplina, sizeof(alunos[indice].disciplina), stdin);
    alunos[indice].disciplina[strcspn(alunos[indice].disciplina, "\n")] = '\0';

    printf("Nova nota: ");
    scanf("%f", &alunos[indice].nota);
    limparBufferEntrada();

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
