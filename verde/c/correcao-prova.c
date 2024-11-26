#include <stdio.h>
#include <stdlib.h>

void cadastrarRespostas(int n_alunos, int n_questoes, char respostas[][n_questoes]);
void cadastrarGabarito(int n_questoes, char gabarito[]);
int *calcularPontuacao(int n_alunos, int n_questoes, char respostas[][n_questoes], char gabarito[]);

int main()
{
  int n_alunos;
  int n_questoes;

  scanf("%d %d", &n_alunos, &n_questoes);

  char respostas[n_alunos][n_questoes];
  char gabarito[n_questoes];

  cadastrarRespostas(n_alunos, n_questoes, respostas);

  cadastrarGabarito(n_questoes, gabarito);

  int *pontuacoes = calcularPontuacao(n_alunos, n_questoes, respostas, gabarito);

  for (int i = 0; i < n_alunos; i++)
  {
    // No VERDE possui uma segunda linha vazia na saída.
    printf("%d%s", pontuacoes[i], (i == n_alunos - 1) ? "\n" : " ");
  }

  return 0;
}

void cadastrarRespostas(int n_alunos, int n_questoes, char respostas[][n_questoes])
{
  for (int i = 0; i < n_alunos; i++)
  {
    for (int j = 0; j < n_questoes; j++)
    {
      scanf(" %c", &respostas[i][j]);
    }
  }
}

void cadastrarGabarito(int n_questoes, char gabarito[])
{
  for (int i = 0; i < n_questoes; i++)
  {
    scanf(" %c", &gabarito[i]);
  }
}

int *calcularPontuacao(int n_alunos, int n_questoes, char respostas[][n_questoes], char gabarito[])
{
  int *pontuacoes_alunos = (int *)malloc(n_alunos * sizeof(int));

  for (int i = 0; i < n_alunos; i++)
  {
    pontuacoes_alunos[i] = 0;
    for (int j = 0; j < n_questoes; j++)
    {
      if (respostas[i][j] == gabarito[j])
      {
        pontuacoes_alunos[i]++;
      }
    }
  }

  return pontuacoes_alunos;
}
