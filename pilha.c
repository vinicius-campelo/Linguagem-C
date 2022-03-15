#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct No {
    int info;
    struct No *proximo;
}No;

typedef struct Pilha {
    struct No *topo;
    int tamanho;
}Pilha;


Pilha* criar_pilha(){
    Pilha* nova_pilha = (Pilha*) malloc(sizeof(Pilha));
    if (nova_pilha != NULL) {
        nova_pilha->topo = NULL;
        nova_pilha->tamanho = 0;
    }
    return nova_pilha;
}

void push_pilha(Pilha *pilha, int item){
    assert(pilha != NULL);
    No *novo_no = (No*)malloc(sizeof(No));
    if(novo_no != NULL){
        novo_no->info = item;
        novo_no->proximo = pilha->topo;
        pilha->topo = novo_no;
        pilha->tamanho++;

    }
}


int pop_pilha(struct Pilha *pilha){
    assert(pilha != NULL);
    assert(pilha->topo != NULL);
    No* aux = pilha->topo;
    int elemento = aux->info;
    pilha->topo = aux->proximo;
    pilha->tamanho--;
    free(aux);
    return elemento;
}




int main(){

    Pilha* inicio = criar_pilha();
    push_pilha(inicio, 1);
    push_pilha(inicio, 2);
    push_pilha(inicio, 3);

    printf("%d ", pop_pilha(inicio));
    printf("%d ", pop_pilha(inicio));
    return 0;
}
