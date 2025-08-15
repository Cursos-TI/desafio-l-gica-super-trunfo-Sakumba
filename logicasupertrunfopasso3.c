#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar os dados de cada carta de cidade.
struct CartaCidade {
    char nomeCidade[50];
    long int populacao;
    double area;
    double pib;
    int pontosTuristicos;
};

// --- Funções de Cadastro e Exibição (Refatoradas) ---
void cadastrarCarta(struct CartaCidade *carta, int numero) {
    printf("--- Cadastro da Carta %d ---\n", numero);
    while (getchar() != '\n'); // Limpa o buffer de entrada antes de começar
    printf("Digite o nome da cidade: ");
    fgets(carta->nomeCidade, 50, stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = 0;
    printf("Digite a população: ");
    scanf("%ld", &carta->populacao);
    printf("Digite a área (em km²): ");
    scanf("%lf", &carta->area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    printf("\n");
}

void exibirCartas(struct CartaCidade c1, struct CartaCidade c2) {
    printf("========================================\n");
    printf("         CARTAS CADASTRADAS\n");
    printf("========================================\n");
    printf("--- Carta 1: %s ---\n", c1.nomeCidade);
    printf(" População: %ld\n Área: %.2f km²\n PIB: R$ %.2f bilhões\n Pontos Turísticos: %d\n\n", c1.populacao, c1.area, c1.pib, c1.pontosTuristicos);
    printf("--- Carta 2: %s ---\n", c2.nomeCidade);
    printf(" População: %ld\n Área: %.2f km²\n PIB: R$ %.2f bilhões\n Pontos Turísticos: %d\n", c2.populacao, c2.area, c2.pib, c2.pontosTuristicos);
    printf("========================================\n\n");
}

// --- Funções Auxiliares (Nível Mestre) ---

// Menu dinâmico que pode excluir uma opção
int exibirMenu(const char* titulo, int opcaoExcluida) {
    int escolha;
    const char* opcoes[] = {"População", "Área", "PIB", "Pontos Turísticos"};
    
    printf("%s\n", titulo);
    for (int i = 0; i < 4; i++) {
        if ((i + 1) != opcaoExcluida) {
            printf("%d. %s\n", i + 1, opcoes[i]);
        }
    }
    
    while (1) { // Loop para validação de entrada
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        if (escolha >= 1 && escolha <= 4 && escolha != opcaoExcluida) {
            return escolha;
        }
        printf("Opção inválida! Tente novamente.\n");
    }
}

// Retorna o nome do atributo com base na escolha
const char* getNomeAtributo(int escolha) {
    switch (escolha) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        default: return "Desconhecido";
    }
}

// Retorna o valor do atributo da carta com base na escolha
double getValorAtributo(struct CartaCidade carta, int escolha) {
    switch (escolha) {
        case 1: return (double)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (double)carta.pontosTuristicos;
        default: return 0.0;
    }
}

// Função de comparação usando operador ternário
int compararValores(double val1, double val2) {
    // Retorna 1 se val1 > val2, 2 se val2 > val1, 0 se forem iguais.
    return (val1 > val2) ? 1 : ((val2 > val1) ? 2 : 0);
}

// Função para anunciar o resultado de forma clara
void anunciarResultado(int resultado, struct CartaCidade c1, struct CartaCidade c2, const char* atributo) {
    if (resultado == 1) {
        printf("VENCEDOR: '%s' (Maior %s).\n", c1.nomeCidade, atributo);
    } else if (resultado == 2) {
        printf("VENCEDOR: '%s' (Maior %s).\n", c2.nomeCidade, atributo);
    } else {
        printf("EMPATE FINAL! Os dois atributos são iguais.\n");
    }
}


int main() {
    struct CartaCidade carta1, carta2;
    int escolhaPrincipal, escolhaDesempate;

    printf("========================================\n");
    printf("    JOGO DE COMPARAÇÃO DE CIDADES\n");
    printf("             NÍVEL MESTRE\n");
    printf("========================================\n\n");

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    exibirCartas(carta1, carta2);

    // ### Lógica de Decisão Complexa ###
    escolhaPrincipal = exibirMenu("Escolha o ATRIBUTO PRINCIPAL para comparação:", 0);
    escolhaDesempate = exibirMenu("\nEscolha o ATRIBUTO DE DESEMPATE:", escolhaPrincipal);

    const char* nomeAtributoPrincipal = getNomeAtributo(escolhaPrincipal);
    const char* nomeAtributoDesempate = getNomeAtributo(escolhaDesempate);

    printf("\n### RESULTADO DA COMPARAÇÃO ###\n");
    printf("Comparando por '%s', com desempate em '%s'.\n\n", nomeAtributoPrincipal, nomeAtributoDesempate);

    // Pega os valores dos atributos principais
    double val1_p = getValorAtributo(carta1, escolhaPrincipal);
    double val2_p = getValorAtributo(carta2, escolhaPrincipal);
    
    // Compara os valores principais
    int resultadoPrincipal = compararValores(val1_p, val2_p);

    if (resultadoPrincipal != 0) {
        // Se não houver empate, anuncia o vencedor
        anunciarResultado(resultadoPrincipal, carta1, carta2, nomeAtributoPrincipal);
    } else {
        // Se houver empate, usa o critério de desempate
        printf("Empate em '%s'! Usando critério de desempate: '%s'.\n", nomeAtributoPrincipal, nomeAtributoDesempate);

        double val1_d = getValorAtributo(carta1, escolhaDesempate);
        double val2_d = getValorAtributo(carta2, escolhaDesempate);
        
        int resultadoDesempate = compararValores(val1_d, val2_d);
        anunciarResultado(resultadoDesempate, carta1, carta2, nomeAtributoDesempate);
    }
    
    printf("========================================\n");
    
    return 0;
}