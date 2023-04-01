/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno
{
  char nome[20];
  float nota;
  char status;
};

struct Aluno listaChamada[40];
int numAlunos = 0;

void incluirAluno(char status)
{
  char name[20];
  float nota = 0.0;

  if (numAlunos >= 40)
  {
    printf("Não é possível incluir mais alunos na lista.\n");
    return;
  }

  printf("Qual o nome do aluno? \n");
  scanf("%c", &name[20]);
  strcpy(listaChamada[numAlunos].nome, name);
  printf("Qual a nota do aluno? \n");
  scanf("%f", &nota);
  listaChamada[numAlunos].nota = nota;
  listaChamada[numAlunos].status = status;
  numAlunos++;
}

void excluirAluno(int indice)
{
  if (indice < 0 || indice >= numAlunos)
  {
    printf("Índice inválido.\n");
    return;
  }

  int i;
  for (i = indice; i < numAlunos - 1; i++)
  {
    listaChamada[i] = listaChamada[i + 1];
  }
  numAlunos--;
}

void ordenarPorNota()
{
  int i, j;
  struct Aluno temp;
  for (i = 0; i < numAlunos - 1; i++)
  {
    for (j = 0; j < numAlunos - i - 1; j++)
    {
      if (listaChamada[j].nota < listaChamada[j + 1].nota)
      {
        temp = listaChamada[j];
        listaChamada[j] = listaChamada[j + 1];
        listaChamada[j + 1] = temp;
      }
    }
  }
}

void imprimirAlunos()
{
  int i;
  printf("Relação de alunos:\n");
  printf("Nome\t\tNota\tStatus\n");
  for (i = 0; i < numAlunos; i++)
  {
    printf("%-20s %-5.2f %c\n", listaChamada[i].nome, listaChamada[i].nota, listaChamada[i].status);
  }
}

void imprimirAlunosAtivos()
{
  int i;
  printf("Relação de alunos ativos:\n");
  printf("Nome\t\tNota\n");
  for (i = 0; i < numAlunos; i++)
  {
    if (listaChamada[i].status == 'A')
    {
      printf("%-20s %-5.2f\n", listaChamada[i].nome, listaChamada[i].nota);
    }
  }
}

void ordenarLista(struct Aluno lista[], int tamanho)
{
  int i, j;
  struct Aluno temp;

  for (i = 0; i < tamanho - 1; i++)
  {
    for (j = i + 1; j < tamanho; j++)
    {
      if (lista[i].nota < lista[j].nota)
      {
        temp = lista[i];
        lista[i] = lista[j];
        lista[j] = temp;
      }
    }
  }
}

void imprimirLista(struct Aluno lista[], int tamanho)
{
  int i, totalAtivos = 0;

  printf("\nRelação total de alunos:\n");
  printf("Nome\t\tNota\tStatus\n");
  for (i = 0; i < tamanho; i++)
  {
    printf("%s\t%.2f\t%c\n", lista[i].nome, lista[i].nota, lista[i].status);
    if (lista[i].status == 'A')
    {
      totalAtivos++;
    }
  }
  printf("Total de alunos ativos: %d\n", totalAtivos);
}

void inicializarLista(struct Aluno lista[], int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    strcpy(lista[i].nome, "");
    lista[i].nota = 0.0;
    strcpy(lista[i].status, "");
  }
}

void main()
{
  int opcao, tamanho = 0;
  struct Aluno lista[40];
  char statusEnum[2][10]; 
  strcpy(statusEnum[0], "ATIVO");
  strcpy(statusEnum[1], "EXCLUIDO"); 

  inicializarLista(lista, 40);

  do
  {
    printf("\nEscolha uma opção:\n");
    printf("1 - Incluir aluno\n");
    printf("2 - Excluir aluno\n");
    printf("3 - Ordenar lista por nota decrescente\n");
    printf("4 - Imprimir relação total de alunos e de alunos ativos\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
      incluirAluno(statusEnum[0]);
      break;
    case 2:
      excluirAluno(lista, &tamanho, statusEnum[1]);
      break;
    case 3:
      ordenarLista(lista, tamanho);
      printf("\nLista ordenada com sucesso!\n");
      break;
    case 4:
      imprimirLista(lista, tamanho);
      break;
    case 0:
      printf("\nEncerrando programa...\n");
      break;
    default:
      printf("\nOpção inválida, tente novamente.\n");
      break;
    }
  } while (opcao != 5);
}
