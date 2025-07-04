#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

ListaDupla* criarLista() {
    ListaDupla* lista = (ListaDupla*)malloc(sizeof(ListaDupla));
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserirInicio(ListaDupla* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = lista->cabeca;

    if (lista->cabeca != NULL)
        lista->cabeca->anterior = novo;
    else
        lista->cauda = novo;

    lista->cabeca = novo;
    lista->tamanho++;
}

void inserirFim(ListaDupla* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->cauda;

    if (lista->cauda != NULL)
        lista->cauda->proximo = novo;
    else
        lista->cabeca = novo;

    lista->cauda = novo;
    lista->tamanho++;
}

void inserirPosicao(ListaDupla* lista, int valor, int pos) {
    if (pos <= 0) {
        inserirInicio(lista, valor);
    } else if (pos >= lista->tamanho) {
        inserirFim(lista, valor);
    } else {
        No* atual = lista->cabeca;
        for (int i = 0; i < pos - 1; i++) {
            atual = atual->proximo;
        }
        No* novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->proximo = atual->proximo;
        novo->anterior = atual;

        atual->proximo->anterior = novo;
        atual->proximo = novo;
        lista->tamanho++;
    }
}

void removerInicio(ListaDupla* lista) {
    if (lista->cabeca == NULL) return;
    No* temp = lista->cabeca;
    lista->cabeca = lista->cabeca->proximo;

    if (lista->cabeca != NULL)
        lista->cabeca->anterior = NULL;
    else
        lista->cauda = NULL;

    free(temp);
    lista->tamanho--;
}

void removerFim(ListaDupla* lista) {
    if (lista->cauda == NULL) return;
    No* temp = lista->cauda;
    lista->cauda = lista->cauda->anterior;

    if (lista->cauda != NULL)
        lista->cauda->proximo = NULL;
    else
        lista->cabeca = NULL;

    free(temp);
    lista->tamanho--;
}

void removerPosicao(ListaDupla* lista, int pos) {
    if (pos < 0 || pos >= lista->tamanho) return;
    if (pos == 0) {
        removerInicio(lista);
    } else if (pos == lista->tamanho - 1) {
        removerFim(lista);
    } else {
        No* atual = lista->cabeca;
        for (int i = 0; i < pos; i++) {
            atual = atual->proximo;
        }
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
        free(atual);
        lista->tamanho--;
    }
}

void removerValor(ListaDupla* lista, int valor) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (atual == lista->cabeca)
                removerInicio(lista);
            else if (atual == lista->cauda)
                removerFim(lista);
            else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                free(atual);
                lista->tamanho--;
            }
            return;
        }
        atual = atual->proximo;
    }
}

No* buscar(ListaDupla* lista, int valor) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        if (atual->valor == valor)
            return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void exibirFrente(ListaDupla* lista) {
    No* atual = lista->cabeca;
    printf("Lista [Frente]: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void exibirTras(ListaDupla* lista) {
    No* atual = lista->cauda;
    printf("Lista [Trás]: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("\n");
}

void destruirLista(ListaDupla* lista) {
    while (lista->cabeca != NULL) {
        removerInicio(lista);
    }
    free(lista);
}
