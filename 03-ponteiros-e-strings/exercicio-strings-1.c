#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void troca(char *nome[], int a, int b) {
    char *aux = nome[a];
    nome[a] = nome[b];
    nome[b] = aux;
}

void bubbleSort(char *nome[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(nome[j], nome[j + 1]) > 0) {
                troca(nome, j, j + 1);
            }
        }
    }
}

void selectionSort(char *nome[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(nome[i], nome[j]) > 0) {
                troca(nome, i, j);
            }
        }
    }
}

void insertionSort(char *nome[], int n) {
    for (int i = 1; i < n; i++) {
        char *aux = nome[i];
        int j = i - 1;
        while(j >= 0 && strcmp(aux, nome[j]) < 0) {
            nome[j + 1] = nome[j];
            j--;
        }
        nome[j + 1] = aux;
    }
}

void merge(char *nome[], int s, int m, int e) {
    char *tmp[(e - s) + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        tmp[k++] = (strcmp(nome[i], nome[j]) < 0) ? nome[i++] : nome[j++];
    }
    while (i <= m) {
        tmp[k++] = nome[i++];
    }
    while (j <= e) {
        tmp[k++] = nome[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        nome[i] = tmp[k];
    }
}

void swap(char *nome[], int a, int b) {
    if (a == b) return;
    char *tmp = nome[a];
    nome[a] = nome[b];
    nome[b] = tmp;
}

int partition(char *nome[], int s, int e) {
    char *pivot = nome[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (strcmp(nome[j], pivot) < 0){
            swap(nome, ++i, j);
        }
    }
    swap(nome, i + 1, e);
    return i + 1;
}

void quickSort(char *nome[], int s, int e) {
    if (s < e) {
        int p = partition(nome, s, e);
        quickSort(nome, s, p - 1);
        quickSort(nome, p + 1, e);
    }

}

void mergeSort(char *nome[], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(nome, s, m);
        mergeSort(nome, m + 1, e);
        merge(nome, s, m, e);
    }
}

void imprimirVetor(char *nome[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", nome[i]);
    }
    printf("\n");
}

int main(){

    int opcao;
    FILE *arquivo;
    char *nome[101];
    int n = 0;

    arquivo = fopen("nomes2.txt", "r");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char buffer[20];
    while(fgets(buffer, sizeof(buffer), arquivo)!= NULL && n<101){
        nome[n] = (char *)malloc(strlen(buffer) + 1);
        strcpy(nome[n], buffer);
        n++;
    }
    fclose(arquivo);

    do{
        printf("1 - Bubble Sort\n");
        printf("2 - Selection Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("6 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                bubbleSort(nome, n);
                imprimirVetor(nome, n);
                break;
            case 2:
                selectionSort(nome, n);
                imprimirVetor(nome, n);
                break;
            case 3:
                insertionSort(nome, n);
                imprimirVetor(nome, n);
                break;
            case 4:
                mergeSort(nome, 0, n-1);
                imprimirVetor(nome, n);
                break;
            case 5:
                quickSort(nome, 0, n-1);
                imprimirVetor(nome, n);
                break;
            case 6:
                printf("Saindo");
                break;
        }
    }while(opcao != 6);

    for(int i = 0; i < n; i++){
        free(nome[i]);
    }

    return 0;
}
