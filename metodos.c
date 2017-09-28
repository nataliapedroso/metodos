#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

FILE *op;

void imprime(double **M, int dim)
{
	int i, j;

	for(i=0; i<dim; i++)
	{
		for(j=0; j<dim+1; j++)
			printf("%lf\t", M[i][j]);
		printf("\n");
	}
	printf("\n");
}
int troca(double **M, int dim, int n)
{
	int i, j, cont=0, k;
	double aux;

	for(i=n; i<dim; i++)
	{
		if(M[i][n]!=0)
		{
			for(j=0; j<dim+1; j++)
			{
				aux=M[n][j];
				M[n][j]=M[i][j];
				M[i][j]=aux;
			}
			i=dim;
		}
	}
	cont++;
	return(cont);
}
double escalonamento(double **M, int dim, int n)
{
	int i, j;
	double pivo;

	for(i=n+1; i<dim; i++)
	{
		pivo=-1*(M[i][n]/M[n][n]);

		for(j=n; j<dim+1; j++)
			M[i][j]=M[i][j]+(pivo*M[n][j]);
	}
}

