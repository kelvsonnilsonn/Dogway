#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OPTIONS_CQ 3
#define MAX_OPTIONS_PR 2

char produto[30];
double valor;

int menu();
int quantidade();

void cachorro_quente();
void prensado();
void cachorro_quente_nomes(int index);
void prensado_nomes(int index);


int main(){

    int c = 1;
    double soma = 0;
    char end_cliente[20];

    for(;;){

        fflush(stdin);
        c = menu();

        switch(c){
            case 1:
                cachorro_quente();
                break;
            case 2:
                prensado();
                break;
        }

        if(c == 0) break;

        soma += valor;
    }

    printf("%.2f\n", soma);
    return 0;
}


// Menu de entrada: 
int menu(){

    int t;
    system("cls");

    do{
        printf("%5sDogway\n\n", " ");
        printf("[1] Cachorros Quente.\n");
        printf("[2] Prensados.\n");
        printf("[0] Deslogar.\n");
        printf("Digite a opcao: ");

        fflush(stdin);
        if(scanf("%d", &t) != 1) t -= 1;

        system("cls");
    } while(t < 0 || t > 3);

    return t;

}


// Quantidade de produtos:

int quantidade(){
    int qntd, c = 0;
    do{
        printf("Entre aqui a quantidade desejada: ");
        if(scanf("%d", &qntd) != 1) qntd -= 1;
    } while(qntd != 1);
    return qntd;
}

// Momento do Cachorro quente:
void cachorro_quente(){
    int qntd = quantidade();
    double valores[MAX_OPTIONS_CQ] = { 25.00, 28.00, 31.00 };
    int selectedoption;

    fflush(stdin);
        
    do{
        printf("%5sCachorros Quentes\n", " ");
        printf("%10sSabores:\n\n", " ");
        printf("[1] Tradicional\n");
        printf("[2] Carne\n");
        printf("[3] Premium\n");
        printf("Escolha o sabor [0 para voltar]: ");

        if(scanf("%d", &selectedoption) != 1) selectedoption -= 1;
    
        if(selectedoption == 0) menu();
    } while(selectedoption < 0 || selectedoption > MAX_OPTIONS_CQ);

    cachorro_quente_nomes(selectedoption);
    valor = valores[selectedoption - 1] * qntd;
}

// Nome do cachorro quente:
void cachorro_quente_nomes(int index){
    char nomes[MAX_OPTIONS_CQ][20] = {"C.Q Tradicional", "C.Q Carne", "Q.C Premium"};
    strcpy(produto, nomes[index - 1]);
}


// Momento do Prensado:
void prensado(){
    double valores[MAX_OPTIONS_PR] = { 14.00, 15.00 };
    int selectedoption;
    int qntd = quantidade();

    fflush(stdin);
        
    do{
        printf("%5sCachorros Quentes\n", " ");
        printf("%10sSabores:\n\n", " ");
        printf("[1] Frango\n");
        printf("[2] Bacon\n");
        printf("Escolha o sabor [0 para voltar]: ");

        if(scanf("%d", &selectedoption) != 1) selectedoption -= 1;
    
        if(selectedoption == 0) menu();
    } while(selectedoption < 0 || selectedoption > MAX_OPTIONS_PR);

    prensado_nomes(selectedoption);
    valor = valores[selectedoption - 1] * qntd;
}

void prensado_nomes(int index){
    char nomes[MAX_OPTIONS_PR][20] = {"Prens. Frango", "Prens. Bacon"};
    strcpy(produto, nomes[index - 1]);
}

