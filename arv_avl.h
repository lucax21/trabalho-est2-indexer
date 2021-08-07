typedef struct No *ArvAVL;

ArvAVL *cria_arvAVL();
void libera_arvAVL(ArvAVL *a);
int altura_arvAVL(ArvAVL *a);
//void rotacaoLL(ArvAVL *a);
//void rotacaoRR(ArvAVL *a);
//void rotacaoLR(ArvAVL *a);
//void rotacaoRL(ArvAVL *a);
//int maior(int a, int b);
//int altura_no(struct No *no);
int insere_arvAVL(ArvAVL *a, int valor);
//int fatorBalanceamento_no(struct No *no);
void emOrdem_print(ArvAVL *a);
