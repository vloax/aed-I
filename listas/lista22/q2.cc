#include <stdio.h>

/*1. Considere uma turma com N alunos, sendo N um valor lido. Para cada aluno, ler a nota obtida em
uma avaliação de valor igual a 100. Ao final das leituras, calcular e escrever a nota média da turma e
o número de alunos com nota superior à nota média da turma.
  2. Construa uma nova versão para o problema anterior de forma que, ao final das leituras, também
sejam informadas a maior e a menor nota da turma.*/

int escreverNotaAluno(int soma, int i, int notas[])
{
  printf("Digite a nota do aluno %d: ", i + 1);
  scanf("%d", &notas[i]);
  soma += notas[i];

  return soma;
}

int qntdAlunosSuperiorMedia(int n, int notas[], float media)
{
  int cont = 0;

  for (int i = 0; i < n; i++)
  {
    if (notas[i] > media)
    {
      cont++;
    }
  }

  return cont;
}

int maiorValor(int notas[], int n)
{
  int maior = notas[0];
  for (int i = 1; i < n; i++)
  {
    if (notas[i] > maior)
    {
      maior = notas[i];
    }
  }

  return maior;
}

int menorValor(int notas[], int n)
{
  int menor = notas[0];

  for (int i = 1; i < n; i++)
  {
    if (notas[i] < menor)
    {
      menor = notas[i];
    }
  }

  return menor;
}

int main()
{
  int n, soma, cont = 0;
  float media;

  printf("Digite o número de alunos: ");
  scanf("%d", &n);

  int notas[n];

  for (int i = 0; i < n; i++)
  {
    soma = escreverNotaAluno(soma, i, notas);
  }

  media = soma / n;

  printf("A média da turma é %.2f e %d alunos tiraram nota maior que a média. A maior nota foi %d e a menor nota foi %d\n", media, qntdAlunosSuperiorMedia(n, notas, media), maiorValor(notas, n), menorValor(notas, n));

  return 0;
}