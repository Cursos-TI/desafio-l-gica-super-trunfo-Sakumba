#include <stdio.h>
#include <string.h>

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

// --- Novas Funções para Melhor Organização ---

// Função para cadastrar os dados de uma carta
void cadastrarCarta(struct CartaCidade *carta, int numero) {
    printf("--- Cadastro da Carta %d ---\n", numero);
    printf("Digite o código do estado: ");
    scanf("%d", &carta->codigoEstado);

    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigoCarta);
    
    while (getchar() != '\n'); // Limpa o buffer de entrada

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

// Função para exibir as cartas cadastradas
void exibirCartas(struct CartaCidade c1, struct CartaCidade c2) {
    printf("========================================\n");
    printf("         CARTAS CADASTRADAS\n");
    printf("========================================\n");
    printf("--- Carta 1: %s ---\n", c1.nomeCidade);
    printf("População: %ld\n", c1.populacao);
    printf("Área: %.2f km²\n", c1.area);
    printf("PIB: R$ %.2f bilhões\n", c1.pib);
    printf("Pontos Turísticos: %d\n\n", c1.pontosTuristicos);

    printf("--- Carta 2: %s ---\n", c2.nomeCidade);
    printf("População: %ld\n", c2.populacao);
    printf("Área: %.2f km²\n", c2.area);
    printf("PIB: R$ %.2f bilhões\n", c2.pib);
    printf("Pontos Turísticos: %d\n", c2.pontosTuristicos);
    printf("========================================\n\n");
}

int main() {
    struct CartaCidade carta1, carta2;
    int escolha;

    printf("========================================\n");
    printf("    JOGO DE COMPARAÇÃO DE CIDADES\n");
    printf("            NÍVEL AVENTUREIRO\n");
    printf("========================================\n\n");

    // ### Cadastro de Cartas ###
    // Chama a função para preencher os dados das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibe as cartas que foram cadastradas
    exibirCartas(carta1, carta2);

    // ### Menu Interativo ###
    // O usuário escolhe o atributo para a comparação
    printf("Escolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);
    printf("\n");

    // ### Comparação com Switch e Lógica Aninhada ###
    printf("### RESULTADO DA COMPARAÇÃO ###\n");

    switch (escolha) {
        case 1: // Comparar por População
            printf("Atributo escolhido: POPULAÇÃO\n");
            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: '%s' (Maior População).\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Vencedor: '%s' (Maior População).\n", carta2.nomeCidade);
            } else {
                // Comparação Aninhada (desempate por PIB)
                printf("Empate na população! Desempatando por PIB...\n");
                if (carta1.pib > carta2.pib) {
                    printf("Vencedor no desempate: '%s' (Maior PIB).\n", carta1.nomeCidade);
                } else if (carta2.pib > carta1.pib) {
                    printf("Vencedor no desempate: '%s' (Maior PIB).\n", carta2.nomeCidade);
                } else {
                    printf("Empate duplo! Não há vencedor.\n");
                }
            }
            break;

        case 2: // Comparar por Área
            printf("Atributo escolhido: ÁREA\n");
            if (carta1.area > carta2.area) {
                printf("Vencedor: '%s' (Maior Área).\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Vencedor: '%s' (Maior Área).\n", carta2.nomeCidade);
            } else {
                 // Comparação Aninhada (desempate por População)
                printf("Empate na área! Desempatando por População...\n");
                if (carta1.populacao > carta2.populacao) {
                    printf("Vencedor no desempate: '%s' (Maior População).\n", carta1.nomeCidade);
                } else if (carta2.populacao > carta1.populacao) {
                    printf("Vencedor no desempate: '%s' (Maior População).\n", carta2.nomeCidade);
                } else {
                    printf("Empate duplo! Não há vencedor.\n");
                }
            }
            break;

        case 3: // Comparar por PIB
            printf("Atributo escolhido: PIB\n");
            if (carta1.pib > carta2.pib) {
                printf("Vencedor: '%s' (Maior PIB).\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Vencedor: '%s' (Maior PIB).\n", carta2.nomeCidade);
            } else {
                // Comparação Aninhada (desempate por Pontos Turísticos)
                printf("Empate no PIB! Desempatando por Pontos Turísticos...\n");
                if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                    printf("Vencedor no desempate: '%s' (Mais Pontos Turísticos).\n", carta1.nomeCidade);
                } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                    printf("Vencedor no desempate: '%s' (Mais Pontos Turísticos).\n", carta2.nomeCidade);
                } else {
                    printf("Empate duplo! Não há vencedor.\n");
                }
            }
            break;

        case 4: // Comparar por Pontos Turísticos
            printf("Atributo escolhido: PONTOS TURÍSTICOS\n");
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedor: '%s' (Mais Pontos Turísticos).\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Vencedor: '%s' (Mais Pontos Turísticos).\n", carta2.nomeCidade);
            } else {
                printf("Empate! As duas cidades têm o mesmo número de pontos turísticos.\n");
            }
            break;

        default:
            printf("Opção inválida! Por favor, execute novamente e escolha um número de 1 a 4.\n");
            break;
    }

    return 0;
}