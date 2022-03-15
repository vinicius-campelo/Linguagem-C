#include <stdio.h>
#include <stdlib.h>



typedef struct ALUNO {

    char *nome;
    char *serie;
    int idade;
    float nota;
    struct ALUNO *proximo;
}ALUNO;



void Inserir_aluno_inicio(ALUNO** ref_inicio, ALUNO aluno){

    ALUNO *novo = (ALUNO*)malloc(sizeof(ALUNO));
    novo->nome = aluno.nome;
    novo->idade = aluno.idade;
    novo->nota = aluno.nota;
    novo->serie = aluno.serie;
    novo->proximo = (*ref_inicio);
    (*ref_inicio) = novo;
}


void Inserir_aluno_fim(ALUNO** ref_inicio, ALUNO aluno){

    ALUNO *novo = (ALUNO*)malloc(sizeof(ALUNO));

    ALUNO *ultimo = (*ref_inicio);

    novo->nome = aluno.nome;
    novo->idade = aluno.idade;
    novo->nota = aluno.nota;
    novo->serie = aluno.serie;
    novo->proximo = NULL;

    if(*ref_inicio == NULL){

        *ref_inicio = novo;
        return;
    }

    while(ultimo->proximo != NULL){

        ultimo = ultimo->proximo;
        ultimo->proximo = novo;
    }
}



void Imprimir(ALUNO *aluno){
    while(aluno != NULL){
        printf("\n%s", aluno->nome);
        printf("\n%d", aluno->idade);
        printf("\n%.2f", aluno->nota);
        printf("\n%s", aluno->serie);

        aluno = aluno->proximo;
        printf("\n\n");
    }
    printf("\n\n");
}

/*
int main(){
    ALUNO* inicio = NULL;
    struct ALUNO alunos;


    alunos.nome = "joao vieira";
    alunos.idade = 50,
    alunos.nota = 8.9;
    alunos.serie = "7 Ano";
    Inserir_aluno_fim(&inicio, alunos);

    alunos.nome = "vinicius campelo";
    alunos.idade = 40,
    alunos.nota = 7.8;
    alunos.serie = "9 Ano";
    Inserir_aluno_inicio(&inicio, alunos);

    alunos.nome = "fernando meireles";
    alunos.idade = 35,
    alunos.nota = 7.9;
    alunos.serie = "1 Ano";
    Inserir_aluno_inicio(&inicio, alunos);


    printf("\nLista Criada: ");
    Imprimir(inicio);

    return 0;
}*/

