typedef int TipoInfo;

struct TNodoAVL{
        TipoInfo info;
        int FB;
        struct TNodoAVL *esq;
        struct TNodoAVL *dir;
};

typedef struct TNodoAVL pNodoAVL;

pNodoAVL * InsereArvore(pNodoAVL * a, TipoInfo ch);
int Altura (pNodoAVL * a);
int Calcula_FB(pNodoAVL * a);
void DesenhaAVL(pNodoAVL * a , int nivel);
int is_avl(pNodoAVL * a);
pNodoAVL * rotacao_direita(pNodoAVL * pt);
pNodoAVL * rotacao_esquerda(pNodoAVL * pt);
pNodoAVL * rotacao_dupla_direita (pNodoAVL * pt);
pNodoAVL * rotacao_dupla_esquerda (pNodoAVL * pt);
pNodoAVL * Caso1 (pNodoAVL * a , int *ok);
pNodoAVL * Caso2 (pNodoAVL * a , int *ok);
pNodoAVL * InsereArvoreAVL (pNodoAVL * a, TipoInfo x, int *ok);
void deletaAVL(pNodoAVL **arv);
void CentralE_AVL(pNodoAVL *a);

