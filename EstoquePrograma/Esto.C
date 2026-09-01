#include <stdio.h>
#include <stdlib.h>

char nomeproduto [10][50];
float quantidade [10];
float valor [10];
int totalprodutos = 0;

int cadastrarproduto() {

    if (totalprodutos == 10) {
        printf("Limite de produtos atingido.\n");
        return -1;
    } 
    else {
        
        printf("Digite o nome do produto: ");
        scanf("%s", nomeproduto[totalprodutos]);
        printf("Digite a quantidade do produto: ");
        scanf("%f", &quantidade[totalprodutos]);
        printf("Digite o valor do produto: ");
        scanf("%f", &valor[totalprodutos]);
        printf("-------------------------\n");
        printf("Produto cadastrado com sucesso: %s\n", nomeproduto[totalprodutos]);
        printf("Quantidade: %.2f Kg \n", quantidade[totalprodutos]);
        printf("Valor: %.2f R$ \n ", valor[totalprodutos]);
        printf("-------------------------\n");

        totalprodutos++;
        return 0;
    }
}

int listarprodutos() {

    printf (">Lista de Produtos Cadastrados<\n");

    if (totalprodutos == 0) {
        printf("-------------------------\n");
        printf("Nenhum produto cadastrado!\n");
        printf("-------------------------\n");
    } else {
        for (int i = 0; i < totalprodutos; i++) {
            printf("-------------------------\n");
            printf("Produto %d: %s\n", i + 1, nomeproduto[i]);
            printf("Quantidade: %.2f Kg\n", quantidade[i]);
            printf("Valor: %.2f R$\n", valor[i]);
            printf("-------------------------\n");
        }
    }
    return 0;
}

int venda(){
    printf("Qual produto deseja vender? (Digite o numero do produto): \n");
    if (totalprodutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return -1;
    } else {
        for (int i = 0; i < totalprodutos; i++) {
            printf("%d. %s\n", i + 1, nomeproduto[i]);
        }
    }
    scanf("%d", &totalprodutos);
    if (totalprodutos < 1 || totalprodutos > 10) {
        printf("Produto invalido.\n");
        return -1;
    } else {
        int produtoindex = totalprodutos - 1;
        float quantidadevendida;
        printf("Digite a quantidade a ser vendida: ");
        scanf("%f", &quantidadevendida);

        if(quantidadevendida > quantidade) {
            printf("Quantidade inserida maior do que possue!");
            return -1;
        } else {
            //PAREI AQUI!!!!!!!!!!!!!!
        }

    }
    

    printf("Venda realizada com sucesso!\n");
    return 0;
}

int main() {
    
    
    do {
        printf("\nMenu Principal\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Venda de Produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        
        int opcaomenu;
        scanf("%d", &opcaomenu);

        switch (opcaomenu) {
            case 1:
                cadastrarproduto();
                break;
            case 2:
                listarprodutos();
                break;
            case 3:
                venda();
                break;
            case 4:
                printf("Saindo do programa.\n");
                exit(0);
            default:
                printf("Opcao invalida. Tente novamente.\n");
            
        }
    } while (totalprodutos < 11);

    return 0;
}
