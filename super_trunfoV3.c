#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clean () {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main () {
	srand(time(0)); // Inicializa o gerador de números aleatórios
	//indices aleatórios
	int indice1 = rand() % 8; // Gera um índice aleatório entre 0 e 5
	int indice2 = rand() % 8; // Gera um índice aleatório entre 0 e 5
	//Nomeando variaveis das cartas
	int opcao,categoria1,categoria2,opcao_jogo,aceitar;
	// Estados aleatórios entre A e H
	char estado1 = 'A' + indice1, estado2 = 'A' + indice2;
	char categoria1_nome[30], categoria2_nome[30];
	// Vetores com nomes das cidades
	const char *cidade1[] = { // Cidades dos estados A a H da carta 1
		"São Paulo", 
		"Rio de Janeiro",
		"Belo Horizonte",
		"Salvador",
		"Fortaleza",
		"Curitiba",
		"Vitória",
		"João Pessoa"
			};
	const char *cidade2[] = { // Cidades dos estados A a H da carta 2
		"Manaus", 
		"Recife",
		"Porto Alegre",
		"Brasília",
		"Goiânia",
		"Belém",
		"Campinas",
		"São Luís"
			};
	const char *categoria_nome[] = { // Nomes das categorias
		"População",
		"Área",
		"PIB",
		"Número de pontos turísticos",
		"Densidade demográfica",
		"PIB per capita",
		"Superpoder"
			};
	// Códigos aleatórios entre 1 e 4
	int codigo1 = rand() % 4+1,codigo2 = rand() % 4+1;
	// Número aleatório de pontos turísticos entre 1 e 100
	int turismo1 = rand() % 100+1,turismo2 = rand() % 100+1;
	// Números aleatórios para população entre 300.000 e 5.300.000
	unsigned long int populacao1 = rand () % 5000000+300000,
	populacao2 = rand () % 5000000+300000;
	// Números aleatórios para área entre 1000 e 8000 em km²
	float area1 = rand () % 7000+1000, area2 = rand () % 7000+1000;
	// Números aleatórios para PIB entre 50 e 500 em bilhões de reais
	float pib1 = rand () % 450+50, pib2 = rand () % 450+50;
	float densidade1,densidade2,pib_percapita1,pib_percapita2;
	float atributo_jogador1, atributo_jogador2, atributo_mestre1, atributo_mestre2;
	float atributo_jogador, atributo_mestre;
	short int resultado1 = 0, resultado2 = 0; //Variáveis para o resultado final
	
	//Carta 1
	//Cálculo da densidade demográfica e PIB per capita da carta 1
	densidade1 = (float) populacao1/area1;
	pib_percapita1 = (float) pib1*1000000000/populacao1;
	
	// Carta 2
	//Cálculo da densidade demográfica e PIB per capita da carta 2
	densidade2 = (float) populacao2/area2;
	pib_percapita2 = (float) pib2*1000000000/populacao2;
	
	//Cálculo do superpoder das cartas
	double inverso_densidade1 = 1 / densidade1;
	double inverso_densidade2 = 1 / densidade2;
	double superpoder1 = (double) populacao1 + (double) area1 + (double) pib1 + (double) turismo1 + 
		(double) inverso_densidade1 + (double) pib_percapita1;
	double superpoder2 = (double) populacao2 + (double) area2 + (double) pib2 + (double) turismo2 + 
		(double) inverso_densidade2 + (double) pib_percapita2;
	
	int i;
	
	//Titulo do desafio proposto
	printf("***Bem-vindo ao Desafio Supertrunfo***\n\n");

	// Menu de opções
	
do {
    i=0;
    clean();
	printf("Menu de opções:\n");
	printf("1 - Iniciar o jogo\n");
	printf("2 - Instruções do jogo\n");
	printf("3 - Sair do jogo\n");
	printf("Digite a opção desejada: \n");
	scanf("%d", &opcao);

	// Processamento da opção escolhida
	switch (opcao) {
		case 1:
			printf("Iniciando o jogo...\n");
			printf("O Mestre Trunfo desafiará você com uma carta de uma cidade aleatória!\n");
			printf("Prepare-se para a batalha!\n");
			printf("Boa sorte!\n");
			printf("Mas lembre-se, a única verdadeira vitória é o Desafio Final!\n");
			printf("Digita Enter para continuar...\n");
			getchar(); // Captura o Enter
			getchar(); // Aguarda o Enter para continuar
			break;
		case 2:
			printf("Instruções do jogo:\n");
			printf("1. O jogador receberá uma carta de uma cidade aleatória que desafiará o Mestre Trunfo.\n");
			printf("2. Cada carta possui as seguintes categorias: População, Área, PIB, Número de pontos turísticos, Densidade demográfica e PIB per capita.\n");
			printf("3. O jogador receberá uma carta e poderá escolher entre três modos de jogo:\n");
			printf("   a) Modo Clássico: O jogador escolhe uma categoria e desafia o Mestre Trunfo em uma categoria específica.\n");
			printf("   b) Modo #Extra# DESAFIO FINAL: O jogador desafia o Mestre Trunfo em todas as categorias.\n");
			printf("   c) Modo #Extra# MODO + DÍFICIL: O jogador desafia o Mestre Trunfo em todas as categorias, mas o Mestre Trunfo tem uma GRANDE vantagem extra.\n");
			printf("4. O jogador vence o jogo se sua carta tiver um valor maior na categoria escolhida, exceto na densidade demográfica, onde o valor menor vence.\n");
			printf("5. Nos Modos #Extras#, a letra do Estado pode influenciar no resultado, porque a a letra A tem a vantagem de ser o SuperTrunfo, garantindo dois pontos extras ao jogador se ele obter essa categoria.\n");
			printf("6. Boa sorte e que o melhor vença!\n");
			getchar ();
			getchar();
			i++;
			break;
		case 3:
			printf("Saindo do jogo. Até a próxima!\n");
		getchar ();
			getchar();
			i++;
		    break;
		default:
			printf("Opção inválida! O programa será reiniciado.\n");
			getchar ();
			getchar();
			i++;
		    break;
	}
	} while (i != 0);

	// Início do jogo
	printf("\n");
	printf("Veja a carta que você teve sorte de receber!\n");
	printf("\n");
	// Apresentação da Carta 1
	// Esta apresentação servirá para todos os modos de jogo
	printf("\n");
	printf("Aperte enter para revelar sua carta...\n");
	getchar(); // Captura o Enter
	printf("\n");
	printf("Carta 1:\n");
	printf("Estado: %c\n",estado1 = 'A' + indice1);
	printf("Código: %c%.2d\n",estado1,codigo1);
	printf("Nome da cidade: %s\n",cidade1[indice1]);
	printf("População: %lu\n",populacao1);
	printf("Área: %.2f km²\n",area1);
	printf("PIB: %.2f bilhões de reais\n",pib1);
	printf("Número de pontos turísticos: %d\n",turismo1);
	printf("Densidade demográfica: %.2f hab/km²\n",densidade1);
	printf("PIB per capita: %.2f reais\n",pib_percapita1);
	printf("Superpoder: %.2f\n",superpoder1);
	printf("Digite Enter para continuar...\n");
	getchar(); // Captura o Enter
	//Finalização do cadastro da carta 1

	//Início do menu do jogo
	printf("\n");
	printf("Menu do jogo:\n");
	printf("Escolha em qual modo de jogo deseja continuar:\n");
	printf("\n");
	printf("1 - Modo Clássico - ESTÁCIO\n");
	printf("2 - #Extra# Modo DESAFIO FINAL\n");
	printf("3 - #Extra# Modo + DÍFICIL\n");
	printf("\n");
	printf("Digite a opção desejada: \n");
	scanf("%d", &opcao_jogo);

	// Processamento da opção escolhida
	
do {
    i=0;
    clean();    
	switch (opcao_jogo) {
		case 1: // Modo Clássico
			printf("Iniciando o Modo Clássico...\n");
			printf("Você terá a chance de escolher duas categorias para desafiar o Mestre Trunfo!\n");
			printf("1 - População\n");
			printf("2 - Área\n");
			printf("3 - PIB\n");
			printf("4 - Número de pontos turísticos\n");
			printf("5 - Densidade demográfica\n");
			printf("6 - PIB per capita\n");
			printf("Digite o número da primeira categoria que deseja desafiar: \n");
			scanf("%d", &categoria1);
			printf("Você escolheu a categoria %s\n", categoria_nome[categoria1 - 1]);
			printf("Agora escolha a segunda categoria que deseja desafiar: \n");
			scanf("%d", &categoria2);
			if (categoria2 == categoria1) {
				printf("Você não pode escolher a mesma categoria duas vezes! O programa será reiniciado.\n");
                getchar ();
                getchar();
				i++;
                break;
            }
			printf("Você escolheu a categoria %s\n", categoria_nome[categoria2 - 1]);
			printf("Prepare-se para a batalha!\n");
			printf("Boa sorte!\n");
			printf("Digite Enter para continuar...\n");
			getchar(); // Captura o Enter
			getchar(); // Aguarda o Enter para continuar
				switch (categoria1) {
					case 1:
					printf("\n");
					printf("Comparando a população:\n");
					printf("A cidade da sua carta é %s com população de %lu habitantes\n", cidade1[indice1],populacao1);
					printf("A cidade da carta do Mestre Trunfo é %s com população de %lu habitantes\n", cidade2[indice2],populacao2);
						if (populacao1 > populacao2) {
						printf("Parabéns, você venceu essa categoria!\n");
							resultado1++;
						} else if (populacao1 < populacao2) {
							printf("O Mestre Trunfo venceu essa categoria!\n");
							resultado2++;
						} else {
							printf("Empate nessa categoria!\n");
						}
				break;
					case 2:
					printf("\n");
					printf("Comparando a área:\n");
					printf("A cidade da sua carta é %s com área de %.2f km²\n", cidade1[indice1],area1);
					printf("A cidade da carta do Mestre Trunfo é %s com área de %.2f km²\n", cidade2[indice2],area2);
						if (area1 > area2) {
						printf("Parabéns, você venceu essa categoria!\n");
							resultado1++;
						} else if (area1 < area2) {
							printf("O Mestre Trunfo venceu essa categoria!\n");
							resultado2++;
						} else {
							printf("Empate nessa categoria!\n");
						}
				break;
					case 3:
					printf("\n");
					printf("Comparando o PIB:\n");
					printf("A cidade da sua carta é %s com PIB de %.2f bilhões de reais\n", cidade1[indice1],pib1);
					printf("A cidade da carta do Mestre Trunfo é %s com PIB de %.2f bilhões de reais\n", cidade2[indice2],pib2);
						if (pib1 > pib2) {
						printf("Parabéns, você venceu essa categoria!\n");
							resultado1++;
						} else if (pib1 < pib2) {
							printf("O Mestre Trunfo venceu essa categoria!\n");
							resultado2++;
						} else {
							printf("Empate nessa categoria!\n");
						}
				break;
					case 4:
					printf("\n");
					printf("Comparando o número de pontos turísticos:\n");
					printf("A cidade da sua carta é %s com %d pontos turísticos\n", cidade1[indice1],turismo1);
					printf("A cidade da carta do Mestre Trunfo é %s com %d pontos turísticos\n", cidade2[indice2],turismo2);
						if (turismo1 > turismo2) {
						printf("Parabéns, você venceu essa categoria!\n");
						resultado1++;
					} else if (turismo1 < turismo2) {
						printf("O Mestre Trunfo venceu essa categoria!\n");
						resultado2++;
					} else {
						printf("Empate nessa categoria!\n");
					}
				break;
					case 5:
					printf("\n");
					printf("Comparando a densidade demográfica:\n");
					printf("A cidade da sua carta é %s com densidade demográfica de %.2f hab/km²\n", cidade1[indice1],densidade1);
					printf("A cidade da carta do Mestre Trunfo é %s com densidade demográfica de %.2f hab/km²\n", cidade2[indice2],densidade2);
					if (inverso_densidade1 > inverso_densidade2) {
						printf("Parabéns, você venceu essa categoria!\n");
						resultado1++;
					} else if (inverso_densidade1 < inverso_densidade2) {
						printf("O Mestre Trunfo venceu essa categoria!\n");
						resultado2++;
					} else {
						printf("Empate nessa categoria!\n");
					}
				break;
					case 6:
					printf("\n");
					printf("Comparando o PIB per capita:\n");
					printf("A cidade da sua carta é %s com PIB per capita de %.2f reais\n", cidade1[indice1],pib_percapita1);
					printf("A cidade da carta do Mestre Trunfo é %s com PIB per capita de %.2f reais\n", cidade2[indice2],pib_percapita2);
					if (pib_percapita1 > pib_percapita2) {
						printf("Parabéns, você venceu essa categoria!\n");
						resultado1++;
					} else if (pib_percapita1 < pib_percapita2) {
						printf("O Mestre Trunfo venceu essa categoria!\n");
						resultado2++;
					} else {
						printf("Empate nessa categoria!\n");
					}
				break;
					default:
					printf("Opção inválida! O programa será encerrado.\n");
					return 1; // Encerra o programa com código de erro
				}
				switch (categoria2) {
					case 1:
					printf("\n");
					printf("Comparando a população:\n");
					printf("A cidade da sua carta é %s com população de %lu habitantes\n", cidade1[indice1],populacao1);
					printf("A cidade da carta do Mestre Trunfo é %s com população de %lu habitantes\n", cidade2[indice2],populacao2);
						if (populacao1 > populacao2) {
						printf("Parabéns, você venceu essa categoria!\n");
							resultado1++;
						} else if (populacao1 < populacao2) { 
							printf("O Mestre Trunfo venceu essa categoria!\n");
							resultado2++;
						} else {
							printf("Empate nessa categoria!\n");
						}
				break;
					case 2:
					printf("\n");
					printf("Comparando a área:\n");
					printf("A cidade da sua carta é %s com área de %.2f km²\n", cidade1[indice1],area1);
					printf("A cidade da carta do Mestre Trunfo é %s com área de %.2f km²\n", cidade2[indice2],area2);
						if (area1 > area2) {
						printf("Parabéns, você venceu essa categoria!\n");
							resultado1++;
						} else if (area1 < area2) {
							printf("O Mestre Trunfo venceu essa categoria!\n");
							resultado2++;
						} else {
							printf("Empate nessa categoria!\n");
						}
				break;
					case 3:
					printf("\n");
					printf("Comparando o PIB:\n");
					printf("A cidade da sua carta é %s com PIB de %.2f bilhões de reais\n", cidade1[indice1],pib1);
					printf("A cidade da carta do Mestre Trunfo é %s com PIB de %.2f bilhões de reais\n", cidade2[indice2],pib2);
						if (pib1 > pib2) {
						printf("Parabéns, você venceu essa categoria!\n");
							resultado1++;
						} else if (pib1 < pib2) {
							printf("O Mestre Trunfo venceu essa categoria!\n");
							resultado2++;
						} else {
							printf("Empate nessa categoria!\n");
						}
				break;
					case 4:
					printf("\n");
					printf("Comparando o número de pontos turísticos:\n");
					printf("A cidade da sua carta é %s com %d pontos turísticos\n", cidade1[indice1],turismo1);
					printf("A cidade da carta do Mestre Trunfo é %s com %d pontos turísticos\n", cidade2[indice2],turismo2);
						if (turismo1 > turismo2) {
						printf("Parabéns, você venceu essa categoria!\n");
						resultado1++;
					} else if (turismo1 < turismo2) {
						printf("O Mestre Trunfo venceu essa categoria!\n");
						resultado2++;
					} else {
						printf("Empate nessa categoria!\n");
					}
				break;
					case 5:
					printf("\n");
					printf("Comparando a densidade demográfica:\n");
					printf("A cidade da sua carta é %s com densidade demográfica de %.2f hab/km²\n", cidade1[indice1],densidade1);
					printf("A cidade da carta do Mestre Trunfo é %s com densidade demográfica de %.2f hab/km²\n", cidade2[indice2],densidade2);
					if (inverso_densidade1 > inverso_densidade2) {
						printf("Parabéns, você venceu essa categoria!\n");
						resultado1++;
					} else if (inverso_densidade1 < inverso_densidade2) {
						printf("O Mestre Trunfo venceu essa categoria!\n");
						resultado2++;
					} else {
						printf("Empate nessa categoria!\n");
					}
				break;
					case 6:
					printf("\n");
					printf("Comparando o PIB per capita:\n");
					printf("A cidade da sua carta é %s com PIB per capita de %.2f reais\n", cidade1[indice1],pib_percapita1);
					printf("A cidade da carta do Mestre Trunfo é %s com PIB per capita de %.2f reais\n", cidade2[indice2],pib_percapita2);
					if (pib_percapita1 > pib_percapita2) {
						printf("Parabéns, você venceu essa categoria!\n");
						resultado1++;
					} else if (pib_percapita1 < pib_percapita2) {
						printf("O Mestre Trunfo venceu essa categoria!\n");
						resultado2++;
					} else {
						printf("Empate nessa categoria!\n");
					}
				break;
					default:
					printf("Opção inválida! O programa será encerrado.\n");
					return 1; // Encerra o programa com código de erro
				}

				//Finalização da comparação entre as categorias
				//Cálculo de atributo total das cartas
				if (categoria1 == 1) {
					 atributo_jogador1 = populacao1;
					 atributo_mestre1 = populacao2;
				} else if (categoria1 == 2) {
					atributo_jogador1 = area1;
					atributo_mestre1 = area2;
				} else if (categoria1 == 3) {
					atributo_jogador1 = pib1;
					atributo_mestre1 = pib2;
				} else if (categoria1 == 4) {
					atributo_jogador1 = turismo1;
					atributo_mestre1 = turismo2;
				} else if (categoria1 == 5) {
					atributo_jogador1 = inverso_densidade1;
					atributo_mestre1 = inverso_densidade2;
				} else {
					atributo_jogador1 = pib_percapita1;
					atributo_mestre1 = pib_percapita2;
				}
				if (categoria2 == 1) {
					atributo_jogador2 = populacao1;
					atributo_mestre2 = populacao2;
				} else if (categoria2 == 2) {
					atributo_jogador2 = area1;
					atributo_mestre2 = area2;
				} else if (categoria2 == 3) {
					atributo_jogador2 = pib1;
					atributo_mestre2 = pib2;
				} else if (categoria2 == 4) {
					atributo_jogador2 = turismo1;
					atributo_mestre2 = turismo2;
				} else if (categoria2 == 5) {
					atributo_jogador2 = inverso_densidade1;
					atributo_mestre2 = inverso_densidade2;
				} else {
					atributo_jogador2 = pib_percapita1;
					atributo_mestre2 = pib_percapita2;
				}

				atributo_jogador = (atributo_jogador1) + (atributo_jogador2);
				atributo_mestre = (atributo_mestre1) + (atributo_mestre2);
				// Finalização do cálculo de atributo total das cartas

				//Resultado final
				printf("\n");
				printf("A soma dos atributos definirá o vencedor final!\n");
				printf("Digite Enter para ver o resultado final...\n");
				getchar(); // Captura o Enter 

				//Apresentação do resultado final
				printf("Você venceu %d categoria(s).\n", resultado1);
				printf("O Mestre Trunfo venceu %d categoria(s).\n", resultado2);
				printf("\n");
				printf("A soma dos atributos da sua carta é: %.2f\n", atributo_jogador);
				printf("A soma dos atributos da carta do Mestre Trunfo é: %.2f\n", atributo_mestre);
				printf("\n");
				printf("****************************");
				printf("\n");
				//Determinação do vencedor final
				if (atributo_jogador == atributo_mestre) {
					printf("As cartas empataram!\n");
					printf("Ninguém venceu essa batalha!\n");
					printf("Incrível! Vocês são igualmente poderosos!\n");
				} else { (atributo_jogador > atributo_mestre) ?
					printf("### Parabéns! A sua carta é a grande vencedora! ###\n"),
					printf("### Você derrotou o Mestre Trunfo! ###\n"),
					printf("### Você é o verdadeiro Mestre Trunfo! ###\n") :
					printf("A carta do Mestre Trunfo é a grande vencedora!\n"),
					printf("O Mestre Trunfo derrotou você!\n"),
					printf("O Mestre Trunfo continua sendo o maior de todos!\n"),
					printf("\n"),
					printf("GAME OVER!\n");
					}
			//Finalização do jogo no Modo Clássico
			return 0; // Encerra o programa com sucesso
			break;
			
		case 2: // Modo Desafio Final
			printf("Iniciando o DESAFIO FINAL!\n");
			printf("Prepare-se para a batalha final!\n");
			printf("Escolha sabiamente se quer continuar ou desistir!\n");
			printf("Você aceita o desafio? (Digite 1 para Sim ou 2 para Não): \n");
			scanf("%d", &aceitar);
			if (aceitar != 1) {
				printf("Você desistiu do desafio. O Mestre Trunfo agradece sua fraqueza!\n");
				return 0; // Encerra o programa
			}

	//Carta do Mestre Trunfo
	// Apresentação da Carta 2

	printf("\n");
	printf("Aperte enter para revelar a carta do Mestre Trunfo...\n");
	getchar(); // Captura o Enter
	printf("\n");
	printf("Carta 2:\n");
	printf("Estado: %c\n",estado2 = 'A' + indice2);
	printf("Código: %c%.2d\n",estado2,codigo2);
	printf("Nome da cidade: %s\n",cidade2[indice2]);
	printf("População: %lu\n",populacao2);
	printf("Área: %.2f km²\n",area2);
	printf("PIB: %.2f bilhões de reais\n",pib2);
	printf("Número de pontos turísticos: %d\n",turismo2);
	printf("Densidade demográfica: %.2f hab/km²\n",densidade2);
	printf("PIB per capita: %.2f reais\n",pib_percapita2);
	printf("Superpoder: %.2f\n",superpoder2);
	//Finalização do cadastro da carta 2

	//Comparação entre as cartas
	printf("\n");
	printf("Digite Enter para iniciar a comparação entre as cartas...\n");
	getchar(); // Captura o Enter

	break;

	case 3: // Modo + Difícil
			printf("Iniciando o Modo + Difícil!\n");
			printf("Prepare-se para desafios ainda maiores!\n");
			printf("Escolha sabiamente se quer continuar ou desistir!\n");
			printf("Você aceita o desafio? (Digite 1 para Sim ou 2 para Não): \n");
			scanf("%d", &aceitar);
			if (aceitar != 1) {
				printf("Você desistiu do desafio. O Mestre Trunfo compreende sua fraqueza!\n");
				return 0; // Encerra o programa
			}

	//Carta do Mestre Trunfo Modo + Difícil
	// Apresentação da Carta 2 Modo + Difícil

	printf("\n");
	printf("Aperte enter para revelar a carta do Mestre Trunfo...\n");
	getchar(); // Captura o Enter
	printf("\n");
	printf("Carta 2:\n");
	printf("Estado: %c\n",estado2 = 'A' + indice2);
	printf("Código: %c%.2d\n",estado2,codigo2);
	printf("Nome da cidade: %s\n",cidade2[indice2]);
	printf("População: %lu\n",populacao2 = populacao1 + (rand () % 100000+1)); // Vantagem extra para o Mestre Trunfo
	printf("Área: %.2f km²\n",area2);
	printf("PIB: %.2f bilhões de reais\n",pib2 = pib1 + (rand () % 50+1)); // Vantagem extra para o Mestre Trunfo
	printf("Número de pontos turísticos: %d\n",turismo2 = turismo1 + (rand () % 10+1)); // Vantagem extra para o Mestre Trunfo
	// Recalculo da densidade demográfica e PIB per capita da carta 2 com as vantagens extras
	densidade2 = (float) populacao2/area2;
	pib_percapita2 = (float) pib2*1000000000/populacao2;
	printf("Densidade demográfica: %.2f hab/km²\n",densidade2);
	printf("PIB per capita: %.2f reais\n",pib_percapita2);
	printf("Superpoder: %.2f\n",superpoder2);
	//Finalização do cadastro da carta 2

	//Comparação entre as cartas
	printf("\n");
	printf("Digite Enter para iniciar a comparação entre as cartas...\n");
	getchar(); // Captura o Enter

	break;
	default :
			printf("Opção inválida! O programa será encerrado.\n");
			return 1; // Encerra o programa com código de erro
	}
    } while (i != 0);
    
	printf("\n");
	printf("Comparação entre as cartas:\n");
	if (opcao_jogo == 2 || opcao_jogo == 3) {
		printf("Mestre Trunfo está impressionado por você ter aceito o %s\n", (opcao_jogo == 2) ? "DESAFIO FINAL" : "MODO + DÍFICIL");
		printf("Comparando todas as categorias:\n");
	}
	printf("\n");

	//Início da comparação entre as categorias
	//Vantagem extra para o jogador se ele tiver a letra A no estado
	if (estado1 == 'A') {
		resultado1 += 2;
		printf("Vantagem extra: Você tem a letra A no estado! Ganhou 2 pontos extras!\n");
	}
	if (estado2 == 'A') {
		resultado2 += 2;
		printf("Vantagem extra: O Mestre Trunfo tem a letra A no estado! Ganhou 2 pontos extras!\n");
	}
	//Comparação das categorias
	//População
	if (populacao1 > populacao2) {
		resultado1++;
		printf("População: A sua carta venceu!\n");
	} else if (populacao1 < populacao2) {
		resultado2++;
		printf("População: A carta do Mestre Trunfo venceu!\n");
	} else {
		printf("População: Empate!\n");
		}
	//Área
	if (area1 > area2) {
		resultado1++;
		printf("Área: A sua carta venceu!\n");
	} else if (area1 < area2) {
		resultado2++;
		printf("Área: A carta do Mestre Trunfo venceu!\n");
	} else {
		printf("Área: Empate!\n");
		}
	//PIB
	if (pib1 > pib2) {
		resultado1++;
		printf("PIB: A sua carta venceu!\n");
	} else if (pib1 < pib2) {
		resultado2++;
		printf("PIB: A carta do Mestre Trunfo venceu!\n");
	} else {
		printf("PIB: Empate!\n");
	}
	//Número de pontos turísticos
	if (turismo1 > turismo2) {
		resultado1++;
		printf("Número de pontos turísticos: A sua carta venceu!\n");
	} else if (turismo1 < turismo2) {
		resultado2++;
		printf("Número de pontos turísticos: A carta do Mestre Trunfo venceu!\n");
	} else {
		printf("Número de pontos turísticos: Empate!\n");
		}
	//Densidade demográfica
	if (inverso_densidade1 > inverso_densidade2) {
		resultado1++;
		printf("Densidade demográfica: A sua carta venceu!\n");
	} else if (inverso_densidade1 < inverso_densidade2) {
		resultado2++;
		printf("Densidade demográfica: A carta do Mestre Trunfo venceu!\n");
	} else {
		printf("Densidade demográfica: Empate!\n");
		}
	//PIB per capita
	if (pib_percapita1 > pib_percapita2) {
		resultado1++;
		printf("PIB per capita: A sua carta venceu!\n");
	} else if (pib_percapita1 < pib_percapita2) {
		resultado2++;
		printf("PIB per capita: A carta do Mestre Trunfo venceu!\n");
	} else {
		printf("PIB per capita: Empate!\n");
	}
	//Superpoder
	if (superpoder1 > superpoder2) {
		resultado1++;
		printf("Superpoder: A sua carta venceu!\n");
	} else if (superpoder1 < superpoder2) {
		resultado2++;
		printf("Superpoder: A carta do Mestre Trunfo venceu!\n");
	} else {
		printf("Superpoder: Empate!\n");
		}
	//Finalização da comparação entre as categorias
	//Resultado final
	printf("\n");
	printf("Digite Enter para ver o resultado final...\n");
	getchar(); // Captura o Enter
	//Apresentação do resultado final
	printf("Você venceu %d categoria(s).\n", resultado1);
	printf("O Mestre Trunfo venceu %d categoria(s).\n", resultado2);
	printf("\n");
	//Determinação do vencedor final
	if (resultado1 > resultado2) {
		printf("### Parabéns! A sua carta é a grande vencedora! ###\n");
		printf("### Você derrotou o Mestre Trunfo! ###\n");
		printf("### Você é o verdadeiro Mestre Trunfo! ###\n");
	} else {
		if (resultado1 < resultado2) {
			printf("A carta do Mestre Trunfo é a grande vencedora!\n");
			printf("O Mestre Trunfo derrotou você!\n");
			printf("O Mestre Trunfo continua sendo o maior de todos!\n");
			printf("\n");
			printf("GAME OVER!\n");
		} else {
			printf("As cartas empataram!\n");
			printf("Ninguém venceu essa batalha!\n");
			printf("Incrível! Vocês são igualmente poderosos!\n");
		}
    } 
	
	//Finalização do jogo nos Modos Extras
	return 0; // Encerra o programa com sucesso
}
