#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void swap(int* array,int x,int y);

int main(int argc, char** argv) {
	int n,m;
	int array[1000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>array[i];
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		swap(array,x,y);
	}
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<endl;
	}
	return 0;
}

void swap(int* array,int x,int y)
{
	int t=array[x-1];
	array[x-1]=array[y-1];
	array[y-1]=t;
}
