#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv_avl.h"

struct No
{
	int hash;
	char palavra[128];
	int altura;
	int qtd;
	struct No *esq;
	struct No *dir;
};

ArvAVL *cria_arvAVL()
{
	ArvAVL *raiz = (ArvAVL *)malloc(sizeof(ArvAVL));
	if (raiz != NULL)
		*raiz = NULL;
	return raiz;
}

void libera_no(struct No *no)
{
	if (no == NULL)
		return;
	//percorre recursivamente esq e dir
	libera_no(no->esq);
	libera_no(no->dir);
	//depois de percorrer esq e dir remove nodo
	free(no);
	no = NULL;
}

void libera_arvAVL(ArvAVL *a)
{
	if (a == NULL)
		return;
	libera_no(*a); //libera cada no existente
	free(a);	   //libera raiz da arvore
}

int altura_arvAVL(ArvAVL *a)
{
	if (a == NULL || *a == NULL)
		return 0;
	int alt_esq = altura_arvAVL(&((*a)->esq));
	int alt_dir = altura_arvAVL(&((*a)->dir));
	if (alt_esq > alt_dir)
		return (alt_esq + 1);
	else
		return (alt_dir + 1);
}

int maior(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int altura_no(struct No *no)
{
	if (no == NULL)
		return -1;
	else
		return no->altura;
}

void rotacaoLL(ArvAVL *a)
{
	struct No *no;
	no = (*a)->esq;
	(*a)->esq = no->dir;
	no->dir = *a;
	(*a)->altura = maior(altura_no((*a)->esq), altura_no((*a)->dir)), +1;
	no->altura = maior(altura_no(no->esq), (*a)->altura) + 1;
	*a = no;
}

void rotacaoRR(ArvAVL *a)
{
	struct No *no;
	no = (*a)->dir;
	(*a)->dir = no->esq;
	no->esq = (*a);
	(*a)->altura = maior(altura_no((*a)->esq), altura_no((*a)->dir)), +1;
	no->altura = maior(altura_no(no->dir), (*a)->altura) + 1;
	(*a) = no;
}

void rotacaoLR(ArvAVL *a)
{
	rotacaoRR(&(*a)->esq);
	rotacaoLL(a);
}

void rotacaoRL(ArvAVL *a)
{
	rotacaoLL(&(*a)->dir);
	rotacaoRR(a);
}

int fatorBalanceamento_no(struct No *no)
{
	return labs(altura_no(no->esq) - altura_no(no->dir));
}

int insere_arvAVL(ArvAVL *a, int hash, char pala[])
{
	int res;
	if (*a == NULL)
	{
		struct No *add;
		add = (struct No *)malloc(sizeof(struct No));
		if (add == NULL)
			return 0;

		add->hash = hash;
		// add->palavra = pala;
		strcpy(add->palavra, pala);
		add->altura = 0;
		add->qtd = 1;
		add->esq = NULL;
		add->dir = NULL;
		*a = add;
		return 1;
	}
	struct No *atual = *a;

	// inicio test
	// // if (valor < atual->info)
	// if (strcmp(pala, atual->palavra) < 0)
	// {
	// 	if ((res = insere_arvAVL(&(atual->esq), pala)) == 1)
	// 	{
	// 		if (fatorBalanceamento_no(atual) >= 2)
	// 		{
	// 			// if (valor < (*a)->esq->info)
	// 			if (strcmp(pala, (*a)->esq->palavra))
	// 			{
	// 				rotacaoLL(a);
	// 			}
	// 			else
	// 			{
	// 				rotacaoLR(a);
	// 			}
	// 		}
	// 	}
	// }
	// else
	// {
	// 	// if (valor > atual->info)
	// 	if (strcmp(pala, (*a)->esq->palavra) > 0)
	// 	{
	// 		if ((res = insere_arvAVL(&(atual->dir), pala)) == 1)
	// 		{
	// 			if (fatorBalanceamento_no(atual) >= 2)
	// 			{
	// 				// if ((*a)->dir->info < valor)
	// 				if (strcmp((*a)->dir->palavra, pala) < 0)
	// 				{
	// 					rotacaoRR(a);
	// 				}
	// 				else
	// 				{
	// 					rotacaoRL(a);
	// 				}
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		atual->qtd++;
	// 		return 0;
	// 	}
	// }
	//fim test

	//inicio test 2
	if (hash < atual->hash)
	{
		if ((res = insere_arvAVL(&(atual->esq), hash, pala)) == 1)
		{
			if (fatorBalanceamento_no(atual) >= 2)
			{
				if (hash < (*a)->esq->hash)
				{
					rotacaoLL(a);
				}
				else
				{
					rotacaoLR(a);
				}
			}
		}
	}
	else
	{
		if (hash > atual->hash)
		{
			if ((res = insere_arvAVL(&(atual->dir), hash, pala)) == 1)
			{
				if (fatorBalanceamento_no(atual) >= 2)
				{
					if ((*a)->dir->hash < hash)
					{
						rotacaoRR(a);
					}
					else
					{
						rotacaoRL(a);
					}
				}
			}
		}
		else
		{
			atual->qtd++;
			return 0;
		}
	}
	//fim test 2

	// codigo que funciona hasuhsa
	// if (valor < atual->info)
	// {
	// 	if ((res = insere_arvAVL(&(atual->esq), valor)) == 1)
	// 	{
	// 		if (fatorBalanceamento_no(atual) >= 2)
	// 		{
	// 			if (valor < (*a)->esq->info)
	// 			{
	// 				rotacaoLL(a);
	// 			}
	// 			else
	// 			{
	// 				rotacaoLR(a);
	// 			}
	// 		}
	// 	}
	// }
	// else
	// {
	// 	if (valor > atual->info)
	// 	{
	// 		if ((res = insere_arvAVL(&(atual->dir), valor)) == 1)
	// 		{
	// 			if (fatorBalanceamento_no(atual) >= 2)
	// 			{
	// 				if ((*a)->dir->info < valor)
	// 				{
	// 					rotacaoRR(a);
	// 				}
	// 				else
	// 				{
	// 					rotacaoRL(a);
	// 				}
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		atual->qtd++;
	// 		return 0;
	// 	}
	// }
	atual->altura = maior(altura_no(atual->esq), altura_no(atual->dir)) + 1;

	return res;
}

// int insere_arvAVL(ArvAVL *a, char pala[])
// {
// 	int res;
// 	if (*a == NULL)
// 	{
// 		struct No *add;
// 		add = (struct No *)malloc(sizeof(struct No));
// 		if (add == NULL)
// 			return 0;

// 		// add->hash = hash;
// 		// add->palavra = pala;
// 		strcpy(add->palavra, pala);
// 		add->altura = 0;
// 		add->qtd = 1;
// 		add->esq = NULL;
// 		add->dir = NULL;
// 		*a = add;
// 		return 1;
// 	}
// 	struct No *atual = *a;

// 	// inicio test
// 	// // if (valor < atual->info)
// 	if (strcmp(pala, atual->palavra) < 0)
// 	{
// 		if ((res = insere_arvAVL(&(atual->esq), pala)) == 1)
// 		{
// 			if (fatorBalanceamento_no(atual) >= 2)
// 			{
// 				// if (valor < (*a)->esq->info)
// 				if (strcmp(pala, (*a)->esq->palavra))
// 				{
// 					rotacaoLL(a);
// 				}
// 				else
// 				{
// 					rotacaoLR(a);
// 				}
// 			}
// 		}
// 	}
// 	else
// 	{
// 		// if (valor > atual->info)
// 		if (strcmp(pala, (*a)->esq->palavra) > 0)
// 		{
// 			if ((res = insere_arvAVL(&(atual->dir), pala)) == 1)
// 			{
// 				if (fatorBalanceamento_no(atual) >= 2)
// 				{
// 					// if ((*a)->dir->info < valor)
// 					if (strcmp((*a)->dir->palavra, pala) < 0)
// 					{
// 						rotacaoRR(a);
// 					}
// 					else
// 					{
// 						rotacaoRL(a);
// 					}
// 				}
// 			}
// 		}
// 		else
// 		{
// 			atual->qtd++;
// 			return 0;
// 		}
// 	}
// 	//fim test

// 	//inicio test 2
// 	// if (hash < atual->hash)
// 	// {
// 	// 	if ((res = insere_arvAVL(&(atual->esq), hash, pala)) == 1)
// 	// 	{
// 	// 		if (fatorBalanceamento_no(atual) >= 2)
// 	// 		{
// 	// 			if (hash < (*a)->esq->hash)
// 	// 			{
// 	// 				rotacaoLL(a);
// 	// 			}
// 	// 			else
// 	// 			{
// 	// 				rotacaoLR(a);
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }
// 	// else
// 	// {
// 	// 	if (hash > atual->hash)
// 	// 	{
// 	// 		if ((res = insere_arvAVL(&(atual->dir), hash, pala)) == 1)
// 	// 		{
// 	// 			if (fatorBalanceamento_no(atual) >= 2)
// 	// 			{
// 	// 				if ((*a)->dir->hash < hash)
// 	// 				{
// 	// 					rotacaoRR(a);
// 	// 				}
// 	// 				else
// 	// 				{
// 	// 					rotacaoRL(a);
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		atual->qtd++;
// 	// 		return 0;
// 	// 	}
// 	// }
// 	//fim test 2

// 	// codigo que funciona hasuhsa
// 	// if (valor < atual->info)
// 	// {
// 	// 	if ((res = insere_arvAVL(&(atual->esq), valor)) == 1)
// 	// 	{
// 	// 		if (fatorBalanceamento_no(atual) >= 2)
// 	// 		{
// 	// 			if (valor < (*a)->esq->info)
// 	// 			{
// 	// 				rotacaoLL(a);
// 	// 			}
// 	// 			else
// 	// 			{
// 	// 				rotacaoLR(a);
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }
// 	// else
// 	// {
// 	// 	if (valor > atual->info)
// 	// 	{
// 	// 		if ((res = insere_arvAVL(&(atual->dir), valor)) == 1)
// 	// 		{
// 	// 			if (fatorBalanceamento_no(atual) >= 2)
// 	// 			{
// 	// 				if ((*a)->dir->info < valor)
// 	// 				{
// 	// 					rotacaoRR(a);
// 	// 				}
// 	// 				else
// 	// 				{
// 	// 					rotacaoRL(a);
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		atual->qtd++;
// 	// 		return 0;
// 	// 	}
// 	// }
// 	atual->altura = maior(altura_no(atual->esq), altura_no(atual->dir)) + 1;

// 	return res;
// }

void emOrdem_print(ArvAVL *a)
{
	if (a == NULL)
		return;
	if (*a != NULL)
	{
		emOrdem_print(&((*a)->esq));
		printf("dado %s qtd %d\n", (*a)->palavra, (*a)->qtd);
		emOrdem_print(&((*a)->dir));
	}
}
