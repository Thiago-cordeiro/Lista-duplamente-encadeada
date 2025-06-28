#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

typedef struct No {
    int valor;
        struct No* proximo;
            struct No* anterior;
            } No;

            typedef struct {
                No* cabeca;
                    No* cauda;
                        int tamanho;
                        } ListaDupla;

                        // Funções principais
                        ListaDupla* criarLista();
                        void inserirInicio(ListaDupla* lista, int valor);
                        void inserirFim(ListaDupla* lista, int valor);
                        void inserirPosicao(ListaDupla* lista, int valor, int pos);

                        // Remoções
                        void removerInicio(ListaDupla* lista);
                        void removerFim(ListaDupla* lista);
                        void removerPosicao(ListaDupla* lista, int pos);
                        void removerValor(ListaDupla* lista, int valor);

                        // Busca e exibição
                        No* buscar(ListaDupla* lista, int valor);
                        void exibirFrente(ListaDupla* lista);
                        void exibirTras(ListaDupla* lista);

                        // Utilidade
                        void destruirLista(ListaDupla* lista);

                        #endif