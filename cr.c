#include <stdio.h>
#include <stdlib.h>

// cálculo do coeficiente de rendimento
// fórmula: Somatório n de credido * nota / soma n de creditos

typedef struct disciplina
{
	char nome[20];
	int credito;
	float p1, p2, pf, media, pr, corte;
}	disciplina;

//protótipos
void ler_materias(disciplina [], int);
void media_final(disciplina *, int);
void cr(disciplina *, int);
void mostrar_dados (disciplina [], int);

int main ( void )
{
	int qtd;
	puts("Digite a quantidade de disciplinas:");
	scanf ("%d", &qtd);
	disciplina * vetor = ( disciplina * ) malloc ( qtd * sizeof( disciplina ) );
	ler_materias(vetor, qtd);
	media_final(vetor, qtd);
	mostrar_dados(vetor, qtd);
	cr(vetor, qtd);
}

void ler_materias(disciplina vetor[], int qtd)
{
	int i;
	for (i = 0; i < qtd; i++)
	{
		printf ("MATÉRIA / CRÉDITO / NOTA DE CORTE / P1 / P2 / PR / PF: \n");
		scanf("%s %d %f %f %f %f %f", vetor[i].nome, &(vetor[i].credito), &(vetor[i].corte), &(vetor[i].p1) , &(vetor[i].p2), &(vetor[i].pr), &(vetor[i].pf));
	}
}

void mostrar_dados (disciplina vetor[], int qtd)
{
	int i;
	puts(" MATÉRIA | CRÉDITO | CORTE |  P1  |  P2  |  PR  |  PF  | MÉDIA");
	for (i = 0; i <  qtd; i++)
	{
		printf(" %s |    %d    | %4.2f  | %4.2f | %4.2f | %4.2f | %4.2f | %4.2f\n",
		vetor[i].nome, vetor[i].credito, vetor[i].corte, vetor[i].p1, vetor[i].p2, vetor[i].pr, vetor[i].pf, vetor[i].media);
	}
}

void media_final(disciplina vetor[], int qtd)
{
	int i;
	float media = 0;
	for (i = 0; i < qtd; i++)
	{
		if (vetor[i].pr != 0)
		{
			if (vetor[i].pr > vetor[i].p1 && vetor[i].pr < vetor[i].p2)
				vetor[i].p1 = vetor[i].pr;
			else if ( vetor[i].pr > vetor[i].p2 && vetor[i].pr < vetor[i].p1)
				vetor[i].p2 = vetor[i].pr;
		}
		media = (vetor[i].p1 + vetor[i].p2) / 2;

		if ( media < vetor[i].corte )
		{
			media = (media + vetor[i].pf) / 2;
		}

		vetor[i].media = media;
	}
}

void cr(disciplina vetor[], int qtd)
{
	int i;
	float credito = 0, media = 0;
	for (i = 0; i < qtd ; i++)
	{
		credito += vetor[i].credito;
		media  += (vetor[i].media * vetor[i].credito);
	}
	printf("Coeficiente de Rendimento:  %.2f\n", (media / credito));

}



