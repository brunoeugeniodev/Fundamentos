#include<stdio.h>

struct No {

    int valor;
    No* prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor) {
        valor = _valor;
        prox = NULL;
    }

};

struct Fila {

    No* inicio;
    No* fim;
    int n;

    Fila() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    void enfileirar(int valor) {
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

    void desenfileirar(){
        if (n == 0) return;
        if (n == 1) {
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No* aux = inicio;
        inicio = inicio->prox;
        delete(aux);
        n--;
    }

    int frente() {
        if (inicio == NULL) return 0;
        return inicio->valor;
    }

    void imprimir(){
        No* aux = inicio;
        while(aux != NULL){
            printf("%d ", aux->valor);
            aux = aux->prox;
        }
    }

    int informarN(){
        return n;
    }

};

struct Pilha {

    No* topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    void inserir(int valor) {
        No* novo = new No(valor);
        if (topo == NULL) {
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    void remover() {
        if (n == 0) return;
        if (n == 1) {
            delete(topo);
            topo = NULL;
            n = 0;
            return;
        }
        No* aux = topo;
        topo = topo->prox;
        delete(aux);
        n--;
    }

    int topoPilha() {
        if (topo == NULL) return 0;
        return topo->valor;
    }

    int informarN(){
        return n;
    }

};

int main() {

    Fila f;
    Pilha p;
    int num;

    f.enfileirar(1);
    f.enfileirar(2);
    f.enfileirar(3);
    f.enfileirar(4);
    f.enfileirar(5);
    f.enfileirar(6);
    f.enfileirar(7);
    f.enfileirar(8);
    f.enfileirar(9);
    f.enfileirar(10);
    f.enfileirar(11);

    num = f.informarN();

    while(num--){
        p.inserir(f.frente());
        f.desenfileirar();
    }

    num = p.informarN();

    while(num--){
        f.enfileirar(p.topoPilha());
        p.remover();
    }

    f.imprimir();

    return 0;
}
