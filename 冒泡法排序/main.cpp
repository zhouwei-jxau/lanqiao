#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int array[10];
	for(int i=0;i<10;i++)
	{
		cin>>array[i];
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				int t=array[j];
				array[j]=array[j+1];
				array[j+1]=t;
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		cout<<array[i]<<" ";
	}
	return 0;
}
