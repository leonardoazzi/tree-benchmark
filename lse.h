typedef struct TipoInfoNo InfoNo;
typedef struct TipoPtNo PtNo;

struct TipoInfoNo{
       double valor;
       char arv[40];
       char ord[40];
       };

struct TipoPtNo{
       InfoNo info;
       PtNo *prox;
       };

PtNo* cria_lista(void);
PtNo* insere_ord (PtNo *l, InfoNo dados);
void sortedInsert(PtNo* ptLista, PtNo* novo);
void imprime(PtNo* l);
PtNo* remover(PtNo* l, char titulo[]);
PtNo* destroi(PtNo* l);
