#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Lista {

    No* inicio;
    No* fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void inserirInicio(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        n++;
    }

    void inserirFinal(int valor) {
        No* novo = new No(valor);
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
        n++;
    }

    void removerInicio() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    void removerFinal() {
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n--;
            return;
        }
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        delete(fim);
        fim = aux;
        aux->prox = NULL;
        n--;
    }

    void imprimir() {
        No* aux = inicio;
        //printf("%d %d\n", aux, aux->valor);
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            //printf("%d %d\n", aux->prox, aux->valor);
            aux = aux->prox;
        }
    }

    void removeNNumero(int num){
        if(n < num){
            for(int i = 0; i < num; i++){
                removerInicio();
            }
        }else{
            for(int i = 0; i < num; i++){
                removerFinal();
            }
        }
    }

    void removeSegundo(){
        if(n <= 1) return;
        No* aux = inicio->prox;
        if(aux != NULL){
            inicio->prox = aux->prox;
            delete aux;
            n--;
        }
    }

    void inserirNoFimTamanhoDaLista(){
        inserirFinal(n);
    }

    void inserirNumerosDeUmAteN(int tamanho){
        for(int i = 1; i <= tamanho; i++){
            inserirInicio(i);
        }
    }

    void inserirPenultimo(int valor){
        if(n <= 1) return;
        No* aux = inicio;
        while (aux->prox != fim) {
            aux = aux->prox;
        }
        No* novo = new No(valor);
        novo->prox = aux->prox;
        aux->prox = novo;
        n++;
    }
};

int main() {

    Lista l;

    l.inserirInicio(10);
    l.inserirInicio(5);
    l.inserirInicio(1);
    l.inserirInicio(8);
    l.inserirFinal(7);
    l.inserirFinal(3);

    l.imprimir();

    l.inserirPenultimo(50);
    l.imprimir();
    l.removeNNumero(4);
    l.imprimir();
    l.removeSegundo();
    l.imprimir();
    l.inserirNoFimTamanhoDaLista();
    l.imprimir();
    l.inserirNumerosDeUmAteN(3);
    l.imprimir();
    l.inserirPenultimo(20);
    l.imprimir();

    return 0;
}
