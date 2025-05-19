#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta do Super Trunfo
struct Carta {
    char estado[3];                // Sigla do estado
    char codigo[10];               // Código da carta
    char cidade[50];               // Nome da cidade
    int populacao;                 // População
    float area;                    // Área em km²
    float pib;                     // PIB em bilhões
    int pontosTuristicos;          // Número de pontos turísticos
    float densidadePopulacional;   // População / Área
    float pibPerCapita;            // PIB / População
};

// Função para exibir os dados da carta 
void calcularDados(struct Carta *carta){
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os dados da carta

void exibirCarta(struct Carta carta) {
    printf("Cidade: %s (%s)\n", carta.cidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %2.f km²\n", carta.area);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.6f bilhões por habitante\n", carta.pibPerCapita);
    printf("\n");
}

int main(){
    // Inicializando duas cartas com cidades diferentes 
    struct Carta carta1 = {"PR", "003", "Curitiba", 1963716, 434.9, 64.0, 15};
    struct Carta carta2 = {"CE", "004", "Fortaleza", 2452185, 314.9, 50.0, 20};

    // Calculando densidade populacional e PIB per capita
    calcularDados(&carta1);
    calcularDados(&carta2);

    // Exibindo os dados das cartas 
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);

    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Comparação por PIB per capita
    printf("---- Comparação de cartas (Atributo: PIB per capita) ----\n\n");
    printf("Carta 1 - %s (%s): %.6f bilhões por habitantes\n", carta1.cidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): %.6f bilhões por habitantes\n", carta2.cidade, carta2.estado, carta2.pibPerCapita);


    if (carta1.pibPerCapita > carta2.pibPerCapita) {
         printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) { 
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
          
    }  
      



    return 0;
}
















