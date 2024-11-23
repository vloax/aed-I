#include <stdio.h>

/*1. Considere uma turma com N alunos, sendo N um valor lido. Para cada aluno, ler a nota obtida em
uma avaliação de valor igual a 100. Ao final das leituras, calcular e escrever a nota média da turma e
o número de alunos com nota superior à nota média da turma.*/

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

  printf("A média da turma é %.2f e %d alunos tiraram nota maior que a média.\n", media, qntdAlunosSuperiorMedia(n, notas, media));

  return 0;
}