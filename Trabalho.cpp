#include <stdio.h>

int main() {
    int senha_cadastrada;
    int senha_validacao;
    int opcao;
    float saldo = 500.00;
    float valordeposito;
    float valorsaque;
    float maiordeposito = 0;

    printf("Crie uma senha numerica: \n");
    scanf("%d", &senha_cadastrada);

    do {
       
        printf("\n___________BANCO DIGITAL___________\n");
        printf("SALDO ATUAL: R$ %.2f \n", saldo);
        printf("1 - DEPOSITAR\n");
        printf("2 - SACAR\n");
        printf("3 - CONSULTAR SALDO E ESTATISTICAS\n");
        printf("4 - SAIR\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            printf("\nDigite o valor do deposito: R$ ");
        	scanf("%f", &valordeposito);
                
            if (valordeposito <= 0) {
                printf("Erro! O valor deve ser maior que zero.\n");
            } else {
            saldo += valordeposito;
            if (valordeposito > maiordeposito) {
                maiordeposito = valordeposito;
            }
            printf("Deposito de R$ %f realizado com sucesso\n", valordeposito);
            }
            break;

            case 2:
                printf("\nDigite sua senha para autorizar o saque: ");
                scanf("%d", &senha_validacao);
                
                if (senha_validacao == senha_cadastrada) {
                printf("Digite o valor do saque: R$ ");
                scanf("%f", &valorsaque);
                    
                if (valorsaque > saldo) {
                    printf("insuficiente\n");
                } else if (valorsaque <= 0) {
                    printf("invalido\n");
                } else {
                    saldo -= valorsaque;
                	printf("Saque realizado com sucesso!\n", valorsaque);
                }
                } else {
                    printf("Senha incorreta!\n");
                }
                break;

            case 3:
                printf("EXTRATO E ESTATISTICAS\n");
                printf("Saldo atual: R$ %f\n", saldo);
                printf("Maior deposito realizado: R$ %f\n", maiordeposito);
                break;

            case 4:
                printf("\nSair!\n");
                break;

            default:
                printf("\nOpcao invalida\n");
        }
        
    } while(opcao != 4);

    return 0;
}

