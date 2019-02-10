#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void pow(int** matrix,int n,int p);
void mod(int** matrix,int n,int m);
void printMatrix(int** matrix,int n);

int main(int argc, char** argv) {
	int b,m;
	cin>>b>>m;
	int** matrix=new int*[2];
	for(int i=0;i<2;i++)
		matrix[i]=new int[2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>matrix[i][j];
		}
	}
	if(b==0)
	{
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(i==j)
					matrix[i][j]=1;
				else 
					matrix[i][j]=0;
			}
		}
		for(int i=0;i<i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				cout<<matrix[i][j]%m<<" ";
			}
			cout<<endl;
		}
	}
	if(b%2==0)
	{
		pow(matrix,2,b/2);
		mod(matrix,2,m);
		pow(matrix,2,2);
		mod(matrix,2,m);
		printMatrix(matrix,2);
	}
	else
	{
		pow(matrix,2,b-1);
		mod(matrix,2,m);
		pow(matrix,2,2);
		mod(matrix,2,m);
		printMatrix(matrix,2);
	}
	for(int i=0;i<2;i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}

void pow(int** matrix,int n,int p)
{
	int **t=new int*[n];
	for(int i=0;i<n;i++)
	{
		t[i]=new int[n];
	}
	while(p>1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int sum=0;
				for(int x=0;x<n;x++)
				{
					sum+=matrix[i][x]*matrix[x][j];
				}
				t[i][j]=sum;
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				matrix[i][j]=t[i][j];
			}
		}
		p--;
	}

	for(int i=0;i<n;i++)
	{
		delete[] t[i];
	}
	delete[] t;
}

void mod(int** matrix,int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			matrix[i][j]=matrix[i][j]%m;
		}
	}
}

void printMatrix(int** matrix,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
