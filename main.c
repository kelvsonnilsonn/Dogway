#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OPTIONS_CQ 4
#define MAX_OPTIONS_CQ_30CM 4
#define MAX_OPTIONS_CQ_PREMIUNS 4
#define MAX_OPTIONS_CQ_30CM_PREMIUNS 4
#define MAX_OPTIONS_PR 2

char produto[30];
double valor;

struct Produto{
    char nome[40];
    double valor;
};

struct Produto cachorro_quente_opcoes[MAX_OPTIONS_CQ + MAX_OPTIONS_CQ_30CM] = {
    {"C.Q. Tradicional", 25.00},
    {"C.Q. Carne ", 28.00},
    {"C.Q. Frango", 28.00},
    {"C.Q. Charque", 29.00},
    {"C.Q. Tradicional 30CM", 15.00},
    {"C.Q. Carne 30CM", 16.50},
    {"C.Q. Frango 30CM", 16.50},
    {"C.Q. Charque 30CM", 17.00}
};


struct Produto cachorro_quente_premium_opcoes[MAX_OPTIONS_CQ_PREMIUNS + MAX_OPTIONS_CQ_30CM_PREMIUNS] = {
    {"C.Q. Tradicional PREMIUM", 30.00},
    {"C.Q. Carne PREMIUM ", 33.00},
    {"C.Q. Frango PREMIUM", 33.00},
    {"C.Q. Charque PREMIUM", 34.00},
    {"C.Q. Tradicional 30CM PREMIUM", 18.00},
    {"C.Q. Carne 30CM PREMIUM", 19.50},
    {"C.Q. Frango 30CM PREMIUM", 19.50},
    {"C.Q. Charque 30CM PREMIUM", 20.00}
};

struct Produto prensado_opcoes[MAX_OPTIONS_PR] = {
    {"Prensado de Frango", 14.00},
    {"Prensado de Bacon", 15.00}
};

struct Pessoa{
    char nome[20];
    int bloco;
    int apt;
};

int menu();
int quantidade();

void cachorro_quente();
void cachorro_quente_premium(int quantidade);
void prensado();

int main(){

    int c;
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
        if(scanf("%d", &t) != 1){
            printf("Opcao invalida! Tente novamente.");
        }

        system("cls");
    } while(t < 0 || t > 3);

    return t;

}


// Quantidade de produtos:
int quantidade(){
    int total;
    printf("Digite a quantidade que deseja: ");
    while(scanf("%d", &total) != 1){
        printf("\nEntrada invalida. Por favor, entre com um numero inteiro valido: ");
        fflush(stdin);
    }
    return total;
}


// Momento do Cachorro quente:
void cachorro_quente(){
    int selectedoption;
    int qntd = quantidade();

    fflush(stdin);

    do{
        printf("%5sCachorros Quentes\n", " ");
        printf("%10sSabores:\n\n", " ");
        
        for(int i=1; i<=MAX_OPTIONS_CQ; i++) printf("[%d] %s \t[%d] %s\n", i, cachorro_quente_opcoes[i-1].nome, i+4, cachorro_quente_opcoes[i+3].nome);

        printf("Escolha o sabor [0 para voltar][%d para os premiuns]: ", MAX_OPTIONS_CQ+MAX_OPTIONS_CQ_30CM+1); // Para caso adicione mais produtos

        if(scanf("%d", &selectedoption) != 1){
            printf("Entrada invalida. Tente novamente: ");
            selectedoption -= 1;
        }
    
        if(selectedoption == 0) menu();
    } while(selectedoption < 0 || selectedoption > MAX_OPTIONS_CQ + MAX_OPTIONS_CQ_30CM + 1);

    if(selectedoption == MAX_OPTIONS_CQ+MAX_OPTIONS_CQ_30CM+1) cachorro_quente_premium(qntd);

    else {
        valor = cachorro_quente_opcoes[selectedoption - 1].valor * qntd;
        strcpy(produto, cachorro_quente_opcoes[selectedoption - 1].nome);
    }

}

// Cachorros quente premiuns:
void cachorro_quente_premium(int quantidade){
    int selectedoptionp;
    
    fflush(stdin);

    do{
        system("cls");
        for(int i=1; i<=MAX_OPTIONS_CQ; i++) printf("[%d] %s \t[%d] %s\n", i, cachorro_quente_premium_opcoes[i-1].nome, i+4, cachorro_quente_premium_opcoes[i+3]);
        printf("Escolha o sabor do cachorro quente premium [0 para voltar]: ");

        if(scanf("%d", &selectedoptionp) != 1){
            printf("Entrada invalida. Tente novamente.");
            selectedoptionp -= 1;
        }

        if(selectedoptionp == 0) menu();
    } while(selectedoptionp < 0 || selectedoptionp > MAX_OPTIONS_CQ_PREMIUNS+MAX_OPTIONS_CQ_30CM_PREMIUNS);

    valor = cachorro_quente_premium_opcoes[selectedoptionp - 1].valor * quantidade;
    strcpy(produto, cachorro_quente_premium_opcoes[selectedoptionp - 1].nome);
    
}

// Momento do Prensado:
void prensado(){
    int selectedoption;
    int qntd = quantidade();

    fflush(stdin);
        
    do{
        printf("%5sCachorros Quentes\n", " ");
        printf("%10sSabores:\n\n", " ");

        for(int i = 1; i<MAX_OPTIONS_PR; i++) printf("[%d] %s\n", i, prensado_opcoes[i-1].nome);

        printf("Escolha o sabor [0 para voltar]: ");

        if(scanf("%d", &selectedoption) != 1){
            printf("Entrada invalida. Tente novamente: ");
            selectedoption -= 1;
        }
    
        if(selectedoption == 0) menu();
    } while(selectedoption < 0 || selectedoption > MAX_OPTIONS_PR);

    valor = prensado_opcoes[selectedoption - 1].valor * qntd;
    strcpy(produto, prensado_opcoes[selectedoption - 1].nome);
}
