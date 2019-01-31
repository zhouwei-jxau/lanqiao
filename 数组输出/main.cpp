#include <iostream>
#include <stdlib.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int max=0;
	int index_x=0,index_y=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			int x;
			cin>>x;
			x=abs(x);
			if(x>max)
			{
				max=x;
				index_x=i+1;
				index_y=j+1;
			}
		}
	}
	cout<<max<<" "<<index_x<<" "<<index_y;
	return 0;
}
