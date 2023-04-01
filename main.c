/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
  int matricula;
  char nome[50];
  char celular[15];
  float peso;
  float altura;
};

void inicializarAlunos (struct Aluno *alunos, int tamanho);
void incluirAluno (struct Aluno *alunos, int *tamanho);
void excluirAluno (struct Aluno *alunos, int *tamanho);
void imprimirAlunos (struct Aluno *alunos, int tamanho);
void buscarAluno (struct Aluno *alunos, int tamanho);
void imprimirDadosAluno (struct Aluno aluno);

void main () {
  struct Aluno alunos[500];
  int tamanho = 0;
  int opcao;

  inicializarAlunos (alunos, 500);

  do {
      printf ("\nCadastro de Alunos\n");
      printf ("-------------------\n");
      printf ("1 - Incluir aluno\n");
      printf ("2 - Excluir aluno\n");
      printf ("3 - Imprimir relação de alunos\n");
      printf ("4 - Buscar aluno por nome\n");
      printf ("5 - Sair\n");
      printf ("Escolha uma opção: ");
      scanf ("%d", &opcao);

      switch (opcao) {
	case 1:
	  incluirAluno (alunos, &tamanho);
	  break;
	case 2:
	  excluirAluno (alunos, &tamanho);
	  break;
	case 3:
	  imprimirAlunos (alunos, tamanho);
	  break;
	case 4:
	  buscarAluno (alunos, tamanho);
	  break;
	case 5:
	  printf ("\nEncerrando o programa...\n");
	  break;
	default:
	  printf ("\nOpção invalida! Tente novamente.\n");
	  break;
	}
  } while (opcao != 5);
}

void inicializarAlunos (struct Aluno *alunos, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
      alunos[i].matricula = 0;
      strcpy (alunos[i].nome, "");
      strcpy (alunos[i].celular, "");
      alunos[i].peso = 0.0;
      alunos[i].altura = 0.0;
    }
}

void incluirAluno (struct Aluno *alunos, int *tamanho) {
  if (*tamanho == 500) {
      printf("\nNão foi possivel incluir mais alunos! O limite foi atingido.\n");
      return;
  }

  printf ("\nInclusão de novo aluno:\n");

  printf ("Matricula: ");
  scanf ("%d", &alunos[*tamanho].matricula);
  printf ("Nome: ");
  scanf (" %[^\n]s", alunos[*tamanho].nome);
  printf ("Celular: ");
  scanf (" %[^\n]s", alunos[*tamanho].celular);
  printf ("Peso (em kg): ");
  scanf ("%f", &alunos[*tamanho].peso);
  printf ("Altura (em metros): ");
  scanf ("%f", &alunos[*tamanho].altura);

  (*tamanho)++;

  printf ("\nAluno incluido com sucesso!\n");
}

void excluirAluno (struct Aluno *alunos, int *tamanho) {
  int matricula, i, j;
  printf ("\nExclusão de aluno:\n");
  printf ("Digite a matricula do aluno a ser excluido: ");
  scanf ("%d", &matricula);
  for (i = 0; i < *tamanho; i++) {
      if (alunos[i].matricula == matricula) {
	  for (j = i; j < (*tamanho) - 1; j++) {
	      alunos[j] = alunos[j + 1];
	  }

	  (*tamanho)--;

	  printf ("\nAluno excluido com sucesso!\n");
	  return;
	}
  }

  printf ("\nMatricula %d não encontrada!\n", matricula);
}

void imprimirAlunos (struct Aluno *alunos, int tamanho) {
  int i;
  printf ("\nRelação de alunos:\n");
  printf("Matricula  Nome                  Celular            Peso    Altura\n");
  for (i = 0; i < tamanho; i++) {
      printf ("%-10d %-20s %-18s %-7.2f %.2f\n", alunos[i].matricula,
	      alunos[i].nome, alunos[i].celular, alunos[i].peso,
	      alunos[i].altura);
    }
}


void buscarAluno (struct Aluno *alunos, int tamanho) {
  char nome[50];
  int i;
  printf ("\nBusca de aluno:\n");
  printf ("Digite o nome do aluno: ");
  scanf (" %[^\n]s", nome);
  for (i = 0; i < tamanho; i++) {
      if (strcmp (alunos[i].nome, nome) == 0) {
	  imprimirDadosAluno (alunos[i]);
	  return;
	}
  }

  printf ("\nAluno %s não encontrado!\n", nome);
}

void imprimirDadosAluno (struct Aluno aluno) {
  printf ("\nDados do aluno:\n");
  printf ("Matricula: %d\n", aluno.matricula);
  printf ("Nome: %s\n", aluno.nome);
  printf ("Celular: %s\n", aluno.celular);
  printf ("Peso: %.2f kg\n", aluno.peso);
  printf ("Altura: %.2f m\n", aluno.altura);
}
