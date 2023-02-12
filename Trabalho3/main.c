#include <stdio.h>
#include <stdlib.h>

#define WATER 0
#define LAND 1

#define MAX_COLS 1024

void *malloc_safe(unsigned nbytes)
{
    void *p;
    p = malloc(nbytes);
    if (p == NULL)
    {
        printf("Nao foi possível alocar!\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

int **create_matrix(int n_rows, int n_cols)
{
    int **m = NULL;
    m = malloc_safe(n_rows * (sizeof(int *)));
    for (int i = 0; i < n_rows; ++i)
        m[i] = malloc_safe(n_cols * sizeof(int));
    return m;
}

void destroy_matrix(int **m, int n_rows)
{
    for (int i = 0; i < n_rows; ++i)
    {
        free(m[i]);
    }
    free(m);
}

void read_input(int **m, int *n_rows, int *n_cols)
{
    char line[MAX_COLS];
    for (int i = 0; i < *n_rows; ++i)
    {
        fgets(line, MAX_COLS, stdin);
        for (int j = 0; j < *n_cols; ++j)
        {
            if (line[j] == '0')
                m[i][j] = WATER;
            else if (line[j] == '1')
                m[i][j] = LAND;
            else
            {
                printf("Wrong char in buffer\n");
                printf("%s\n", line);
                exit(EXIT_FAILURE);
            }
        }
    }
}

void print_matrix(int **m, int n_rows, int n_cols)
{
    printf("Print %d x %d matrix\n", n_rows, n_cols);
    for (int i = 0; i < n_rows; ++i)
    {
        for (int j = 0; j < n_cols; ++j)
        {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int tamanhoIlha(int** m, int i, int j, int linhas, int colunas)
{
    int tamanho;
    if(!m[i][j]) // Verifica se pertence a matriz
        return 0;
    else
    {
        m[i][j] = 0; // Faz com que nao seja mais contabilizado
        tamanho = 1;
        //Percorre os 4 vizinhos
        if(i + 1 < linhas)
            tamanho += tamanhoIlha(m, i+1, j, linhas, colunas);
        if(i > 0)
            tamanho += tamanhoIlha(m, i-1, j, linhas, colunas);
        if(j + 1 < colunas)
            tamanho += tamanhoIlha(m, i, j+1, linhas, colunas);
        if(j > 0)
            tamanho += tamanhoIlha(m, i, j-1, linhas, colunas);
    }
    return tamanho;
}

int search_max_area(int **m, int n_rows, int n_cols){
    int area_max = 0;
    int aux;
    for(int i =  0 ; i < n_rows ; i++){
        for(int j =  0 ; j < n_cols ; j++){
            if (m[i][j] == 1){
                aux = tamanhoIlha(m, i, j, n_rows, n_cols);
                if (aux > area_max)
                    area_max = aux;
            }
        }
    }
    return area_max;
    }

int main()
{
    int n_rows = 0, n_cols = 0;
    scanf("%d %d\n", &n_rows, &n_cols);
    int **m = create_matrix(n_rows, n_cols);
    read_input(m, &n_rows, &n_cols);
    int area = search_max_area(m, n_rows, n_cols);
    printf("%d", area);
    /*Função para desalocar a matriz.*/
    destroy_matrix(m, n_rows);
    return 0;
}
