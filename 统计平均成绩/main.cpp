#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double grade[4][4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>grade[i][j];
		}
	}
	
	for(int i=0;i<4;i++)
	{
		double sum=0;
		for(int j=0;j<4;j++)
		{
			sum+=grade[i][j];
		}
		printf("%.2f\n",sum/4);
	}
	return 0;
}
