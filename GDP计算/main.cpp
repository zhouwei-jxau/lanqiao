#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	double multiple=1;
	for(int i=0;i<n;i++)
	{
		multiple=multiple*1.1;
	}
	printf("%.2f",multiple);
	return 0;
}
