#include <stdio.h>
#include <string.h>

// ### Definição da Estrutura da Carta ###
// Estrutura para armazenar os dados de cada carta de cidade.
struct CartaCidade {
    int codigoEstado;
    int codigoCarta;
    char nomeCidade[50];
    long int populacao;
    double area;
    double pib; // Produto Interno Bruto
    int pontosTuristicos;
};

int main() {
    // Declaração das duas cartas que serão comparadas
    struct CartaCidade carta1, carta2;

    printf("========================================\n");
    printf("    JOGO DE COMPARAÇÃO DE CIDADES\n");
    printf("========================================\n\n");

    // ### Entrada de Dados - Carta 1 ###
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o código do estado: ");
    scanf("%d", &carta1.codigoEstado);

    printf("Digite o código da carta: ");
    scanf("%d", &carta1.codigoCarta);
    
    // Limpa o buffer de entrada para ler a string corretamente
    while (getchar() != '\n'); 

    printf("Digite o nome da cidade: ");
    // Usamos fgets para ler nomes com espaços
    fgets(carta1.nomeCidade, 50, stdin);
    // Remove o caractere '\n' que o fgets adiciona no final
    carta1.nomeCidade[strcspn(carta1.nomeCidade, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%ld", &carta1.populacao);

    printf("Digite a área (em km²): ");
    scanf("%lf", &carta1.area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &carta1.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    printf("\n");

    // ### Entrada de Dados - Carta 2 ###
    printf("--- Cadastro da Carta 2 ---\n");
    printf("Digite o código do estado: ");
    scanf("%d", &carta2.codigoEstado);

    printf("Digite o código da carta: ");
    scanf("%d", &carta2.codigoCarta);

    // Limpa o buffer de entrada
    while (getchar() != '\n'); 

    printf("Digite o nome da cidade: ");
    fgets(carta2.nomeCidade, 50, stdin);
    carta2.nomeCidade[strcspn(carta2.nomeCidade, "\n")] = 0;

    printf("Digite a população: ");
    scanf("%ld", &carta2.populacao);

    printf("Digite a área (em km²): ");
    scanf("%lf", &carta2.area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &carta2.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    printf("\n");

    // ### Saída de Dados ###
    // Exibe as propriedades das cartas cadastradas de forma organizada.
    printf("========================================\n");
    printf("         CARTAS CADASTRADAS\n");
    printf("========================================\n");
    printf("--- Carta 1: %s ---\n", carta1.nomeCidade);
    printf("Código da Carta: %d\n", carta1.codigoCarta);
    printf("População: %ld\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: R$ %.2f bilhões\n", carta1.pib);
    printf("Pontos Turísticos: %d\n\n", carta1.pontosTuristicos);

    printf("--- Carta 2: %s ---\n", carta2.nomeCidade);
    printf("Código da Carta: %d\n", carta2.codigoCarta);
    printf("População: %ld\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: R$ %.2f bilhões\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("========================================\n\n");

    // ### Comparação de Cartas e Exibição de Resultados ###
    // A comparação será baseada no PIB. A regra é: maior valor vence.
    // Para comparar outro atributo (ex: população, área), basta trocar 'pib' pela propriedade desejada.
    // Exemplo para população: if (carta1.populacao > carta2.populacao)
    
    printf("### RESULTADO DA COMPARAÇÃO (Atributo: PIB) ###\n");

    if (carta1.pib > carta2.pib) {
        printf("A carta vencedora é a de '%s' com PIB de R$ %.2f bilhões!\n", carta1.nomeCidade, carta1.pib);
    } else if (carta2.pib > carta1.pib) {
        printf("A carta vencedora é a de '%s' com PIB de R$ %.2f bilhões!\n", carta2.nomeCidade, carta2.pib);
    } else {
        printf("Houve um empate! Ambas as cidades têm o mesmo PIB (R$ %.2f bilhões).\n", carta1.pib);
    }
    
    /*
     * NOTA SOBRE A REGRA DA DENSIDADE POPULACIONAL:
     * Conforme as instruções, a regra "menor valor vence" se aplica à densidade populacional.
     * Para implementar isso, você calcularia a densidade (populacao / area) para cada carta
     * e depois compararia, invertendo a lógica: if (densidade1 < densidade2).
    */

    return 0;
}

