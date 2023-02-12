// Informações do estudante
// Nome:Yan Gimenez Borges
// Curso:Engenharia de Computação
// RA:769826

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromoR(int i, int f, char *s)
{// implemente essa função recursiva
   if(i > f/2)
    return 1;
   if(s[i] != s[f-i])//Nao é palindromo
    return 0;
   else
    return palindromoR(i+1, f, s);
}

void palindromo(char *s)
{
    int saida = palindromoR(0, strlen(s) - 1, s);

    printf("\"");
    printf("%s", s);
    printf("\" ");

    if (saida)
    {
        printf("eh palindromo\n");
    }
    else
    {
        printf("nao eh palindromo\n");
    }
}

void inversaR(char *str) //Feito
{   if(*str){
        inversaR(str+1);
        putchar(*str);
    }
}

void inversa(char *s)
{
    printf("inversa de \"");
    printf("%s", s);
    printf("\" = ");

    inversaR(s);

    printf("\n");
}

unsigned long stirlingR(unsigned long n, unsigned long k)//Feito
{   if(n==k)
        return 1;
    if((n==0 || k == 0) && n != k)
        return 0;
    if(n > k)
        return (n-1)*stirlingR(n-1,k) + stirlingR(n-1,k-1);
    return 0;
}

void stirling(int n, int k)
{
    printf("%lu\n", stirlingR(n, k));
}

void padraoR(unsigned n)//Feito
{   if(n > 0 ){
        printf("%i",n);
        padraoR(n-1);
        if (n==1)
            printf ("00");
        printf("%i",n);
    }
}

void padrao(int n)
{
    padraoR(n);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int t;

    scanf("%d", &t);

    if (t < 1 || t > 4)
    {
        printf("Parametros incorretos.\n");
        printf("Ex:\n");
        printf("tp01_recursao 1 [para testar palindromo]\n");
        printf("tp01_recursao 2 [para testar inversa]\n");
        printf("tp01_recursao 3 [para testar fibonacci]\n");
        printf("tp01_recursao 4 [para testar pisoLog]\n");
    }

    if (t == 1)
    {
        printf("\nTestando palindromo()\n\n");
        palindromo("");
        palindromo("1");
        palindromo("77");
        palindromo("505");
        palindromo("1111");
        palindromo("2112");
        palindromo("369963");
        palindromo("10101");
        palindromo("1001001");
        palindromo("12");
        palindromo("12451");
        palindromo("100011");
    }
    else if (t == 2)
    {
        printf("\nTestando inversa()\n\n");
        inversaR("");
        inversa("ab");
        inversa("gato");
        inversa("minerva");
        inversa("alucard");

    }
    else if (t == 3)
    {
        printf("\nTestando Stirling()\n\n");
        stirling(0, 0);
        stirling(0, 1);
        stirling(1, 0);
        stirling(5, 5);
        stirling(5, 4);
        stirling(5, 3);
        stirling(9, 4);
        stirling(12, 6);
    }
    else if (t == 4)
    {
        printf("\nTestando padrao()\n\n");
        padrao(1);
        padrao(2);
        padrao(5);
        padrao(10);
        padrao(15);
        padrao(20);
    }

    return 0;
}
