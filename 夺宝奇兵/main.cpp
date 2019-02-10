#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int maxValue(int** matrix,int row,int col,int n);

int main(int argc, char** argv) {
	int n;
	int array[100][100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			cin>>array[i][j];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			int left=0,right=0;
			if(j-1>=0)
				left=array[i-1][j-1];
			if(right<i)
				right=array[i-1][j];
			int max=left>right?left:right;
			array[i][j]+=max;		
		}
	}
	int max=array[n-1][0];
	for(int i=0;i<n;i++)
	{
		if(max<array[n-1][i])
		{
			max=array[n-1][i];
		}
	}
	cout<<max;
	return 0;
}
