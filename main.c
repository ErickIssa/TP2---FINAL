#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaSondas.h"
#include <time.h>

#define PESO_MAXIMO 40
int minhaVariavelGlobal = 1;

int main(){

    clock_t inicio = clock();
    SondaMarte sonda1;
    listaSonda sondasL;
    ListaRochas compartimentoL;
    int qntdSondas = 3;
    
    inicializarListaComp(&compartimentoL);
    iniciaListaSonda(&sondasL);

    for(int i = 0;i < qntdSondas;i++){
        insereSonda(&sondasL, inicializaSonda(&sonda1));
    }

    FILE *arq = NULL;
    arq = fopen("testerocha.txt", "r");
    if(arq == NULL){
        printf("falha leitura");
        exit(0);
    }
    int nRochas; 
    float peso, valor;
    fscanf(arq, "%d", &nRochas);

    for(int i = 0; i<nRochas;i++){
        fscanf(arq,"%f %f", &peso, &valor);
        insere_Rocha(&compartimentoL, valor, peso, 0);
    }

    for(int i = 1; i < (qntdSondas+1); i++){
        printf("Sonda %d: ", i);
        melhor_rocha(&compartimentoL);
        printf("\n");
    }


    clock_t fim = clock();
    double tempo_decorrido = (double)(fim - inicio) / 1000000;
    printf("Tempo gasto: %f segundos\n", tempo_decorrido);
    printf("\n"); 

    // oi Altamiro ou Paulo :), testa com 200 rochas ai
    return 0;
}