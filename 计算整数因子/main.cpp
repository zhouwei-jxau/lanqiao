#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

inline bool isPrimer(int x);

int main(int argc, char** argv) {
	int n;
	cin>>n;
	while(!isPrimer(n))
	{
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				cout<<i<<" ";
				n/=i;
			}
		}
	}
	cout<<n;
	return 0;
}

bool isPrimer(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
