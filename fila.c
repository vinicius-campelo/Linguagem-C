#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *proximo;
}No;

typedef struct Fila{
    No *inicio, *fim;
}Fila;

No* novoNo(int k)
{
    No *temp = (No*)malloc(sizeof (No));
    temp->chave = k;
    temp->proximo = NULL;
    return temp;
};

Fila* inicia_fila(){
    Fila *q = (Fila*)malloc(sizeof (Fila));
    q->inicio = q->fim = NULL;
    return q;
};

void insere_fila(Fila* q, int k){
    No *temp = novoNo(k);
    if(q->fim == NULL){
        q->inicio = q->fim = temp;
        return;
    }
    q->fim->proximo = temp;
    q->fim = temp;
}


void remove_fila(Fila* q){
    if(q->inicio == NULL){
        return;
    }

    No *temp = q->inicio;
    q->inicio = q->inicio->proximo;

    if(q->inicio == NULL){
        q->fim = NULL;
    }

    free(temp);
}

/*
int main(){

    Fila* q = inicia_fila();
    insere_fila(q, 10);
    insere_fila(q, 20);
    remove_fila(q);
    remove_fila(q);
    insere_fila(q, 30);
    insere_fila(q, 40);
    insere_fila(q, 50);
    remove_fila(q);
    printf("Fila Inicio: %d \n", q->inicio->chave);
    printf("Fila Fim: %d", q->fim->chave);

    return 0;
}*/
