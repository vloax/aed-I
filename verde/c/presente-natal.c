#include <stdio.h>
#include <string.h>

#define MAX_STR 100
#define MAX_PRESENTES 100

typedef struct
{
  char presente[MAX_STR];
  float valor;
  int preferencia;
} Lista;

void ordenarLista(Lista listaPresentes[], int tamanho)
{
  Lista item_temp;
  for (int i = 0; i < tamanho - 1; i++)
  {
    for (int j = i + 1; j < tamanho; j++)
    {
      if (listaPresentes[j].preferencia > listaPresentes[i].preferencia ||
          (listaPresentes[j].preferencia == listaPresentes[i].preferencia &&
           listaPresentes[j].valor < listaPresentes[i].valor) ||
          (listaPresentes[j].preferencia == listaPresentes[i].preferencia &&
           listaPresentes[j].valor == listaPresentes[i].valor &&
           strcmp(listaPresentes[j].presente, listaPresentes[i].presente) < 0))
      {
        item_temp = listaPresentes[i];
        listaPresentes[i] = listaPresentes[j];
        listaPresentes[j] = item_temp;
      }
    }
  }
}

int main()
{
  char nomeDono[MAX_STR];
  char line[MAX_STR];
  int q;

  while (fgets(line, MAX_STR, stdin) != NULL)
  {
    if (sscanf(line, "%s %d", nomeDono, &q) != 2)
      continue;

    Lista presentes[MAX_PRESENTES];

    for (int i = 0; i < q; i++)
    {
      fgets(presentes[i].presente, MAX_STR, stdin);
      size_t len = strlen(presentes[i].presente);
      if (len > 0 && presentes[i].presente[len - 1] == '\n')
        presentes[i].presente[len - 1] = '\0';

      fgets(line, MAX_STR, stdin);
      sscanf(line, "%f %d", &presentes[i].valor, &presentes[i].preferencia);
    }

    ordenarLista(presentes, q);

    printf("Lista de %s\n", nomeDono);
    for (int i = 0; i < q; i++)
    {
      printf("%s - R$%.2f\n", presentes[i].presente, presentes[i].valor);
    }
    printf("\n");
  }

  return 0;
}
