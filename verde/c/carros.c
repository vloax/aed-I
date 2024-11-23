#include <stdio.h>
#include <string.h>

#define MAX_STR 100
#define MAX_CARROS 100

typedef struct
{
  char marca[MAX_STR];
  int ano;
  float preco;
} Carro;

void escreveCarro(Carro carro)
{
  printf("Marca: %s, Ano: %i, Preco: %.2f\n", carro.marca, carro.ano, carro.preco);
}

void filtrarCarro(float valorMaximo, Carro carros[], int max)
{
  for (int i = 0; i < max; i++)
  {
    if (carros[i].preco < valorMaximo)
    {
      escreveCarro(carros[i]);
    }
  }
}

int main()
{
  int max;
  float price_max;
  Carro carrosLista[MAX_CARROS];
  char line[MAX_STR];

  scanf("%d", &max);

  for (int i = 0; i < max; i++)
  {
    scanf(" %s", carrosLista[i].marca);
    scanf(" %i", &carrosLista[i].ano);
    scanf(" %f", &carrosLista[i].preco);
  }

  scanf("%f", &price_max);

  printf("Carros com preco menor que %.2f:\n", price_max);

  filtrarCarro(price_max, carrosLista, max);

  return 0;
}
