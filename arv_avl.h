typedef struct No *ArvAVL;

ArvAVL *cria_arvAVL();
void libera_arvAVL(ArvAVL *a);
int altura_arvAVL(ArvAVL *a);

int insere_arvAVL(ArvAVL *a, int hash, char pala[]);
// int insere_arvAVL(ArvAVL *a, char pala[]);

void emOrdem_print(ArvAVL *a);
