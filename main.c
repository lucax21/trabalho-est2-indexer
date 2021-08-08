#include <stdio.h>
#include <ctype.h>
#include "arv_avl.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char c, palavra[128];
	ArvAVL *a;
	int i = 0, res, N = 10, dados[10] = {1, 2, 3, 10, 4, 5, 7, 7, 8, 6};

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
				palavra[i] = c;
				i++;
			}
			else if ((c >= 97) && (c <= 122))
			{
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

				i = 0;
			}
		}
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
