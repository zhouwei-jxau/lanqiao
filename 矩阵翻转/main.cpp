#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Maximization(int** matrix,int n,int x);
void filp(int** matrix,int i,int j,int x);
int nSum(int** matrix,int i,int j,int x);

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int**matrix=new int*[n];
	for(int i=0;i<n;i++)
	{
		matrix[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>matrix[i][j];
		}
	}
	int x=(n+1)/2;
	Maximization(matrix,n,x);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sum+=matrix[i][j];
		}
	}
	cout<<sum;
	for(int i=0;i<n;i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}

void Maximization(int** matrix,int n,int x)
{
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=0;i<=n-x;i++)
		{
			
			for(int j=0;j<=n-x;j++)
			{
				int sum=nSum(matrix,i,j,x);
				filp(matrix,i,j,x);
				int fSum=nSum(matrix,i,j,x);
				if(sum>=fSum)
				{
					filp(matrix,i,j,x);	
				}				
				else
				{
					flag=true;
				}
			}
		}
	}
}

void filp(int** matrix,int i,int j,int x)
{
	for(int s=i;s<i+x;s++)
	{
		for(int k=j;k<j+x;k++)
		{
			matrix[s][k]=-matrix[s][k];
		}
	}
}

int nSum(int** matrix,int i,int j,int x)
{
	int count=0;
	for(int s=i;s<i+x;s++)
	{
		for(int k=j;k<j+x;k++)
		{
			count+=matrix[s][k];
		}
	}
	return count;
}

