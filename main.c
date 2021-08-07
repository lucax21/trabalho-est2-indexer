#include <stdio.h>
#include "arv_avl.h"

int main()
{
	ArvAVL *a;
	int i, res, N = 10, dados[10] = {1, 2, 3, 10, 4, 5, 7, 7, 8, 6};

	a = cria_arvAVL();

	for (i = 0; i < N; i++)
	{

		//printf("========================\n");

		//printf("Inserindo: %d\n",dados[i]);

		res = insere_arvAVL(a, dados[i]);

		//printf("\n\nres = %d\n",res);

		//preOrdem_ArvAVL(avl);

		//printf("\n\n");
	}
	emOrdem_print(a);
	libera_arvAVL(a);
	return 0;
}
