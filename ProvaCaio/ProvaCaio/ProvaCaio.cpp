#include <iostream>
#include <stdlib.h>
#include <string.h>
typedef struct Serie {
	char nome[100];
	int temporada;
} Serie;
typedef struct No {
	Serie serie;
	struct No* prox;
} No;
typedef struct {
	No* inicial;
} Lista;
Lista* criacao() {
	Lista* l = (Lista*)calloc
	(1, sizeof(Lista));
	l->inicial = NULL;
	return l;
}
void adicionar_desejos(Lista* lista_de_desejos, Serie serie) {
	No* novoNo = (No*)calloc(1, sizeof(No));
	novoNo->serie = serie;
	novoNo->prox = NULL;
	if (lista_de_desejos->inicial == NULL) {
		lista_de_desejos->inicial = novoNo;
	}
	else {
		No* temp = lista_de_desejos->inicial;
		while (temp->prox != NULL) {
			temp = temp->prox;
		}
		temp->prox = novoNo;
	}
}
bool adicionar_assistidas(Lista* lista_de_desejos, Serie serie, Lista* lista_series_assistidas) {
	No* aux = lista_de_desejos->inicial;
	while (aux != NULL) {
		if (strcmp(serie.nome, aux->serie.nome) == 0) {
			No* novoNo = (No*)calloc(1, sizeof(No));
			novoNo->serie = aux->serie;
			novoNo->prox = lista_series_assistidas->inicial;
			lista_series_assistidas->inicial = novoNo;
			return true;
		}
		aux = aux->prox;
	}
}
void remover_primeira_serie(Lista* lista_de_desejos) {
	No* inicial = lista_de_desejos->inicial;
	if (inicial == NULL) {
		printf("Lista vazia\n");
	}
	else {
		lista_de_desejos->inicial = inicial->prox;
		printf("A serie removida foi %s\n", inicial->serie.nome);
		free(inicial);
	}
}
void listar_desejos(Lista* lista_de_desejos) {
	No* aux = lista_de_desejos->inicial;
	while (aux != NULL) {
		printf("%s -> ", aux->serie.nome);
		printf("%d -> ", aux->serie.temporada);
		aux = aux->prox;
	}
	printf("NULL\n");
}
void listar_assistidas(Lista* lista_series_assistidas) {
	No* temp = lista_series_assistidas->inicial;
	while (temp != NULL) {
		printf("%s -> ", temp->serie.nome);
		printf("%d -> ", temp->serie.temporada);
		temp = temp->prox;
	}
	printf("NULL\n");
}
void listar_creditos() {
	printf("Davi Aguilar da Silva 1989281\n");
	printf("Gabriel Zanguettin Costa 2006643\n");
}
int main()
{
	Lista* lista_de_desejos;
	lista_de_desejos = criacao();
	Lista* lista_series_assistidas;
	lista_series_assistidas = criacao();
	bool sair = false;
	while (!sair) {
		printf("1 - Adicionar na lista de desejos\n");
		printf("2 - Adicionar na lista de series assistidas\n");
		printf("3 - Listar series\n");
		printf("4 - Remover da lista de desejos\n");
		printf("5 - Creditos\n");
		printf("6 - Sair\n");
		printf("Escolha uma opcao: ");
		int numero;
		scanf_s("%d", &numero);
		if (numero == 6) {
			sair = true;
		}
		else {
			switch (numero) {
			case 1:
				Serie serie;
				printf("Digite o nome da serie: ");
				scanf_s("%s", serie.nome, sizeof(serie.nome));
				printf("Digite o numero de temporadas: ");
				scanf_s("%d", &serie.temporada);
				adicionar_desejos(lista_de_desejos, serie);
				system("pause");
				system("cls");
				break;
			case 2:
				Serie serie2;
				printf("Digite o nome da serie que voce quer colocar na lista de series assistidas: ");
				scanf_s("%s", serie2.nome, sizeof(serie2.nome));
				if (adicionar_assistidas(lista_de_desejos, serie2, lista_series_assistidas)) {
					printf("Serie adicionada com sucesso\n");
					system("pause");
					system("cls");
				}
				else {
					printf("A serie nao foi encontrada na lista de desejos. Digite quantas temporadas tem a serie: ");
					scanf_s("%d", &serie2.temporada);
					No* novoNo = (No*)calloc(1, sizeof(No));
					novoNo->prox = lista_series_assistidas->inicial;
					novoNo->serie = serie2;
					lista_series_assistidas->inicial = novoNo;
					printf("Serie adicionada\n");
					system("pause");
					system("cls");
				}
				break;
			case 3:
				listar_desejos(lista_de_desejos);
				listar_assistidas(lista_series_assistidas);
				system("pause");
				system("cls");
				break;
			case 4:
				remover_primeira_serie(lista_de_desejos);
				system("pause");
				system("cls");
				break;
			case 5:
				listar_creditos();
				system("pause");
				system("cls");
				break;
			}
		}
	}
	return 1;
}