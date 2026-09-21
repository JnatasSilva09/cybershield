#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
} ContaBancaria;

void criarConta(ContaBancaria *conta) {
    printf("\n--- Criacao de Conta ---\n");
    printf("Digite o numero da conta: ");
    scanf("%d", &conta->numeroConta);
    printf("Digite o nome do titular: ");
    scanf(" %[^\n]s", conta->nomeTitular);
    conta->saldo = 0.0f;
    printf("Conta criada com sucesso!\n");
}

void depositar(ContaBancaria *conta) {
    float valor;
    printf("\n--- Deposito ---\n");
    printf("Digite o valor a depositar: R$ ");
    scanf("%f", &valor);
    
    if (valor > 0) {
        conta->saldo += valor;
        printf("Deposito realizado com sucesso! Novo saldo: R$ %.2f\n", conta->saldo);
    } else {
        printf("Valor invalido para deposito!\n");
    }
}

void sacar(ContaBancaria *conta) {
    float valor;
    printf("\n--- Saque ---\n");
    printf("Digite o valor a sacar: R$ ");
    scanf("%f", &valor);
    
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso! Novo saldo: R$ %.2f\n", conta->saldo);
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }
}

void consultarSaldo(ContaBancaria conta) {
    printf("\n--- Consulta de Saldo ---\n");
    printf("Titular: %s\n", conta.nomeTitular);
    printf("Conta: %d\n", conta.numeroConta);
    printf("Saldo atual: R$ %.2f\n", conta.saldo);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    ContaBancaria conta;
    int opcao;
    int contaCriada = 0;

    do {
        printf("\n============================\n");
        printf("    SISTEMA BANCARIO SIMPLES\n");
        printf("============================\n");
        printf("1. Criar Conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Consultar Saldo\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarConta(&conta);
                contaCriada = 1;
                break;
            case 2:
                if (contaCriada) depositar(&conta);
                else printf("\nCrie uma conta primeiro!\n");
                break;
            case 3:
                if (contaCriada) sacar(&conta);
                else printf("\nCrie uma conta primeiro!\n");
                break;
            case 4:
                if (contaCriada) consultarSaldo(conta);
                else printf("\nCrie uma conta primeiro!\n");
                break;
            case 5:
                printf("\nSaindo do sistema. Obrigado por usar nossos servicos!\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}