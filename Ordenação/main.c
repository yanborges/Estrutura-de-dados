#include <stdio.h>
#include <stdlib.h>

void ordenacao(int v[], int N){
  int i, aux, muda = 1;
  int trocas = 0;
  while (muda == 1){
    muda = 0;
    for (i = 1; i < N; i++)
    if (v[i - 1] > v[i]) {
      aux = v[i - 1];
      v[i - 1] = v[i];
      v[i] = aux;
      muda = 1;
      trocas+=1;
    }
  }
   printf("%d", trocas);
}

int main(void){
    int N;
    scanf("%d \n", &N);
    int v[N];
    int i;
    for(i=0;i < N;i++){
      scanf("%d", &v[i]);
    }
    ordenacao(v, N);
    return 0;
}
