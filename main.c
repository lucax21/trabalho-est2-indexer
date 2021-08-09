#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "arv_avl.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char c, palavra[128];
	ArvAVL *a;
	int i = 0, res, N = 10, dados[10] = {1, 2, 3, 10, 4, 5, 7, 7, 8, 6};
	int test_hash = 0;

	file = fopen("test.txt", "r");
	a = cria_arvAVL();

	// carrega os dados
	if (file == NULL)
	{
		printf("\n Erro ao tentar abrir o arquivo txt\n");
	}
	else
	{
		while ((c = getc(file)) != EOF)
		{
			c = tolower(c);
			if ((c > 47) && (c < 58))
			{
				test_hash = test_hash + palavra[i];
				palavra[i] = c;
				i++;
			}
			else if ((c >= 97) && (c <= 122))
			{
				test_hash = test_hash + palavra[i];
				palavra[i] = c;
				i++;
			}
			else if ((c == ' ') && (i == 0))
			{
			}
			else if ((c == '\n') || (c == 32))
			{
				palavra[i] = '\0';
				//inserir na arv
				res = insere_arvAVL(a, test_hash, palavra);
				// res = insere_arvAVL(a, palavra);
				printf("res %d\n", res);
				printf("%s\n", palavra);
				i = 0;
				test_hash = 0;
			}
		}

		// while ((fgets(palavra, sizeof(palavra), file)) != NULL)
		// {
		// 	int i = 0, c = 0; /*contador e variavel que armazena a soma dos caracteres da linha, respectivamente*/
		// 	while (i < strlen(palavra) - 1)
		// 	{ /* -1, pois o fgets captura também \n, dessa forma, evita a soma de +10 ao valor*/
		// 		c = c + palavra[i];
		// 		i++;
		// 	}
		// 	res = insere_arvAVL(a, c, palavra);
		// }
	}

	// exibe dados
	emOrdem_print(a);

	// area de teste
	// for (i = 0; i < N; i++)
	// {

	// 	//printf("========================\n");

	// 	//printf("Inserindo: %d\n",dados[i]);

	// 	res = insere_arvAVL(a, dados[i]);

	// 	//printf("\n\nres = %d\n",res);

	// 	//preOrdem_ArvAVL(avl);

	// 	//printf("\n\n");
	// }

	//libera memoria
	fclose(file);
	libera_arvAVL(a);
	return 0;
}
