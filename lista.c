#include <stdio.h>
#include <stdlib.h>


typedef struct NO
{
    int valor;
    struct No *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

// inserçao no inicio da lista
void inserirInicio(Lista *lista, int valor)
{
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;

}

// imprimir a lista
void imprimir(Lista *lista)
{
    No *inicio = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tam);
    while(inicio != NULL)
    {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}


int main()
{
    Lista lista;
    int opcao, valor;

    lista.inicio = NULL;
    lista.tam = 0;


    do
    {
        printf("1 - inserir no inicio\n2 - imprimir\n5 - sair\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            imprimir(&lista);
            break;
        case 5:
            printf("Finalizando...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

    }while(opcao != 5);



    return 0;
}


