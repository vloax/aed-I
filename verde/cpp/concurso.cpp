#include <iostream>
#include <string>

using namespace std;

#define _MAX 100

class CANDIDATO
{
public:
  string nome;
  double nota;

  CANDIDATO(string _nome, double _nota)
  {
    nome = _nome;
    nota = _nota;
  }

  CANDIDATO()
  {
    nome = "";
    nota = 0;
  }

private:
  void setNome(string _nome)
  {
    nome = _nome;
  }

  void setNota(double _nota)
  {
    nota = _nota;
  }

  string getNome()
  {
    return nome;
  }

  double getNota()
  {
    return nota;
  }
};

CANDIDATO *cadastrarCandidato(string nome, double nota)
{
  return new CANDIDATO(nome, nota);
}

double calcularMedia(CANDIDATO *candidatos[], int n)
{
  double soma = 0;

  for (int i = 0; i < n; i++)
  {
    soma += candidatos[i]->nota;
  }

  return soma / n;
}

void listarCandidatosAcimaMedia(CANDIDATO *candidatos[], int n, double media)
{
  for (int i = 0; i < n; i++)
  {
    if (candidatos[i]->nota > media)
    {
      cout << candidatos[i]->nome << " " << candidatos[i]->nota << endl;
    }
  }
}

int main()
{
  CANDIDATO *candidatos[_MAX];

  int n;
  string nome;
  double nota, media;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> nome >> nota;
    candidatos[i] = cadastrarCandidato(nome, nota);
  }

  media = calcularMedia(candidatos, n);

  listarCandidatosAcimaMedia(candidatos, n, media);

  return 0;
}
