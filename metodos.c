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

void reversa(double **M, int dim)
{
	double b, x[dim+1], aux;
	int i, j;

	b=M[dim-1][dim];
	x[3]=b/M[dim-1][dim-2];

	for(i=dim-1; i>=0; i--)
	{
		b=M[i][dim];
		for(j=i+1; j<dim; j++)
			aux+=M[i][j]*x[j];

		x[i]=(b-aux)/M[i][i];
		aux=0;
	}

	printf("\n Solução: \n");
	for(i=0; i<dim; i++)
		printf("X%d = %lf\t", i+1, x[i]);
	printf("\n\n");
}

void determinante(double **M, int dim, int cont)
{
	double det=1;
	int i;

	for(i=0; i<dim; i++)
		det*=M[i][i];

	printf("\n Determinante: ");
	if(cont%2==0)
		printf("%.2lf \n", det);
	else
		printf("%.2lf \n", -1.0*det);
}

double **decompLU(double **M, int dim)
{
	int i, j, k;
	double **L, **U, pivo, r;

	L=malloc(dim*sizeof(double*));
	U=malloc(dim*sizeof(double*));

	for(k=0; k<dim; k++)
	{
		L[k][1]=M[k][1];
		U[k][k]=1;

		for(j=1; j<dim; j++)
			U[1][j]=M[1][j]/L[1][1];
	}

	for(k=0; k<dim; k++)
	{
		for(i=1; i<dim; i++)
			r+=L[i][k]*U[i][k];
	}

	for(i=1; i<dim; i++)
	{
		for(j=1; j<dim; j++)
			L[i][j]=M[i][j]-r;
	}

	imprime(L,dim);
}

double jacobi(double **M, int dim)
{
	double er=1e-5, x0[dim], soma=0, b[dim], x[dim], dis;
	int i, j, k;

	for(i=0; i<dim; i++)
	{
		x[i]=0;
		b[i]=M[i][4];
	}

	do
	{
		for(i=0; i<dim; i++)
			x0[i]=x[i];

		dis=0;

		for(i=0; i<dim; i++)
		{
			soma=0;
			for(j=0; j<dim; j++)
			{
				if(j!=i)
					soma+=M[i][j]*x0[j];
			}
			x[i]=(1/M[i][i])*(b[i]-soma);
			dis+=fabs(x0[i]-x[i]);
		}
	} while(dis<er);

	printf(" %.2g\t", dis);
	printf("\n %.2g\t", er);

	for(i=0; i<dim; i++)
		printf("%.2lf\t", x[i]);
	printf("\n\n");
}
