#include <stdio.h>
#include "lista_dupla.h"

int main() {
    ListaDupla* lista = criarLista();

    inserirFim(lista, 10);
    inserirFim(lista, 20);
    inserirInicio(lista, 5);
    inserirPosicao(lista, 15, 2);

    exibirFrente(lista);
    exibirTras(lista);

    removerValor(lista, 15);
    exibirFrente(lista);

    destruirLista(lista);
    return 0;
}
