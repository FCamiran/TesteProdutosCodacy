#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    float preco;
} Produto;

typedef struct {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos;
} SistemaProdutos;

void inicializarSistema(SistemaProdutos *sistema) {
    sistema->totalProdutos = 0;
}

void adicionarProduto(SistemaProdutos *sistema, const char *nome, float preco) {
    if (sistema->totalProdutos >= MAX_PRODUTOS) {
        printf("Não é possível adicionar mais produtos.\n");
        return;
    }
    if (strlen(nome) == 0 || preco < 0) {
        printf("Nome inválido ou preço não pode ser negativo.\n");
        return;
    }

    Produto novoProduto;
    strcpy(novoProduto.nome, nome);
    novoProduto.preco = preco;
    sistema->produtos[sistema->totalProdutos] = novoProduto;
    sistema->totalProdutos++;
    printf("Produto %s adicionado com sucesso.\n", nome);
}

void listarProdutos(SistemaProdutos *sistema) {
    if (sistema->totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Produtos cadastrados:\n");
    for (int i = 0; i < sistema->totalProdutos; i++) {
        printf("Nome: %s, Preço: %.2f\n", sistema->produtos[i].nome, sistema->produtos[i].preco);
    }
}

float calcularMediaPrecos(SistemaProdutos *sistema) {
    if (sistema->totalProdutos == 0)
        return 0;

    float soma = 0;
    for (int i = 0; i < sistema->totalProdutos; i++) {
        soma += sistema->produtos[i].preco;
    }
    return soma / sistema->totalProdutos;
}

void erroExemplo() {
    // Este método nunca é chamado
    int erro = 10 / 0; // Gera uma exceção de divisão por zero
}

int main() {
    SistemaProdutos sistema;
    inicializarSistema(&sistema);

    adicionarProduto(&sistema, "Produto A", 50);
    adicionarProduto(&sistema, "Produto B", -10); // Preço inválido
    adicionarProduto(&sistema, "Produto C", 100);

    listarProdutos(&sistema);

    float media = calcularMediaPrecos(&sistema);
    printf("A média de preços é: %.2f\n", media);

    erroExemplo(); // Chamada do método que gera erro, mas nunca é chamado
    return 0;
}
