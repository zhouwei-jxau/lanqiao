#include <iostream>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
	{
		cout<<"("<<x<<","<<i<<")";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"("<<i<<","<<y<<")";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(abs(i-x)==abs(j-y))
			{
				if((i>=x&&j>=y)||(i<=x&&j<=y))
				{
					cout<<"("<<i<<","<<j<<")";
				}
			}
		}
	}
	cout<<endl;
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(abs(i-x)==abs(j-y))
			{
				if((i>=x&&j<=y)||(i<=x&&j>=y))
				{
					cout<<"("<<i<<","<<j<<")";
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
