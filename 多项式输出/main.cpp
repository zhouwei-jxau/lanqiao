#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int array[100];
	int n;
	cin>>n;
	for(int i=0;i<n+1;i++)
	cin>>array[i];
	if(array[0]<0)
	{
		cout<<'-';
		array[0]=-array[0];
	}
	if(array[0]!=0)
		cout<<array[0]<<"x^"<<n;
	for(int i=1;i<n;i++)
	{
		if(array[i]!=0)
		{
			if(array[i]>0)
			cout<<"+";
			if(array[i]!=1&&array[i]!=-1)
			{
				cout<<array[i];
			}
			else if(array[i]==-1)
			{
				cout<<"-";
			}
			cout<<"x^"<<n-i;
		}
	}
	if(array[n]!=0)
	{
		if(array[n]>0)
		{
			cout<<"+";
		}
		cout<<array[n];
	}

	return 0;
}
