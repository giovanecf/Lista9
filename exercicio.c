#include <stdio.h>

float somar(float numero1, float numero2);
float subtrair(float numero1, float numero2);
float multiplicar(float numero1, float numero2);
float dividir(float numero1, float numero2);
void obterNumeros(float* numero1, float* numero2, char* sinal_operacao);
void obterResultado(float total, float numero1, float numero2, char* sinal_operacao);
void organizarNumeros(float* numero1, float* numero2);
void sair(int* var);

void main(){

    int loop = 1, opcao = 0;
    float numero1 = 0, numero2 = 0;

    printf("\nCalculadora 0.0.1\n");
    printf("Bem-vindo(a)!!\n");

    while(loop == 1){

        printf("\n--- MENU ---\n");
        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Mutiplicar\n");
        printf("4 - Dividir\n");
        printf("5 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                obterNumeros(&numero1, &numero2, "SOMAR");
                obterResultado(somar(numero1, numero2), numero1, numero2, "+");
            break;
            
            case 2:
                obterNumeros(&numero1, &numero2, "SUBTRAIR");
                organizarNumeros(&numero1, &numero2);
                obterResultado(subtrair(numero1, numero2), numero1, numero2, "-");
            break;
        
            case 3:
                obterNumeros(&numero1, &numero2, "MULTIPLICAR");
                obterResultado(multiplicar(numero1, numero2), numero1, numero2, "x");
            break;
            case 4:
                obterNumeros(&numero1, &numero2, "DIVIDIR");
                organizarNumeros(&numero1, &numero2);
                obterResultado(dividir(numero1, numero2), numero1, numero2, "÷");
            break;
            case 5:
                sair(&opcao);
                return;
            break;
            default:
                printf("\nOpção inválida!\n");
            break;
        }
    }
}

void obterNumeros(float* numero1, float* numero2, char* sinal_operacao){

        printf("\n");
        printf("Opção: %s\n", sinal_operacao);
        printf("Numero 1: ");
        scanf("%f", numero1);
        printf("Numero 2: ");
        scanf("%f", numero2);
}

void obterResultado(float total, float numero1, float numero2, char* sinal_operacao){
    printf("\n");
    printf("%.2f %s %.2f = \n%.2f", numero1, sinal_operacao, numero2, total);
    printf("\n");
}

void organizarNumeros(float* numero1, float* numero2){
    float auxiliar = 0;
    if(*numero1 < *numero2){
        auxiliar = *numero1;
        *numero1 = *numero2;
        *numero2 = auxiliar;
    }
}

void sair(int* var){
    *var = 0;
}

float somar(float numero1, float numero2){
    return numero1+numero2;
}

float subtrair(float numero1, float numero2){
    return numero1 - numero2;
}

float multiplicar(float  numero1, float numero2){
    return numero1*numero2;
}

float dividir(float numero1, float numero2){
    return numero1 / numero2;
}