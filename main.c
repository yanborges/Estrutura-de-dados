//Nome:Yan Gimenez Borges
//RA:769826
//Curso:Engenharia de Computação
#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa Pessoa ;
    struct pessoa {
    int posicao ;
    Pessoa *prox ;
    };

Pessoa *inicio = NULL ;

//Declaração de funçoes
void insereLista ( int pos ) ;
void removeLista ( Pessoa * p ) ;
void imprimeLista () ;
int resolveJosephus (int n , int m ) ;
void criaLista(int n);
void imprimeMataMorre(Pessoa *matou, Pessoa *morreu);

void imprimeLista(){
    Pessoa *p = inicio;
    do{
        printf("%d ", p->posicao);
        p = p->prox;
    }while (p != inicio);
    printf("\n");
}

void imprimeMataMorre(Pessoa *matou, Pessoa *morreu){
    printf("%d matou %d", matou->posicao, morreu->posicao);
    printf("\n");
}

void insereLista(int pos)
{
    Pessoa *nova;
    nova = malloc(sizeof(Pessoa));
    nova->posicao = pos;
    if(inicio == NULL){
        inicio = nova;
        nova->prox = nova;
    }
    else
        nova->prox = inicio->prox;
        inicio->prox = nova;
}

void criaLista(int n){
    for(int i = n; i >= 1; i--)
        insereLista(i);
}

void removeLista(Pessoa *p){
    Pessoa *morta;
    morta = p->prox;
    p->prox = morta->prox;
    free(morta);
}

 int resolveJosephus(int n, int m){
    int resultado;
    criaLista(n);
    int tam = n;                               // tamanho da lista ainda viva
    Pessoa *mata = inicio->prox;               //Pessoa a matar
    imprimeLista();
    do{
        for(int i = 1; i <= m ; i++)              //pula m passos ate a pessoa a ser morta
            inicio = inicio->prox;              // quem morre
        if(mata == inicio->prox)                  // quem mata é o msm q morre
            inicio = inicio->prox;;
        imprimeMataMorre( mata , inicio->prox );
        removeLista(inicio);
        imprimeLista();
        mata = inicio->prox;                // quem mata é o proximo a ser morto
        tam--;
    }while(tam > 1);
    resultado = mata->posicao;
    inicio = NULL;

 return resultado;                  //ultima pessoa sobrevivente
 }



int main () {
    int nroexecs ;

    scanf ("%d", & nroexecs ) ;
    int * n = malloc ( nroexecs * sizeof (int ) ) ;
    int * m = malloc ( nroexecs * sizeof (int ) ) ;

    for (int i = 0; i < nroexecs ; i ++) {
    scanf ("%d", & n [ i ]) ;
    scanf ("%d", & m [ i ]) ;
    }

    for (int i = 0; i < nroexecs ; i ++) {
    printf ("Usando n=%d, m=%d, resultado=%d\n", n [ i ] , m [i ] , resolveJosephus ( n [ i ] , m [ i ]) ) ;
    }

    return 0;
 }
