#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char op;
	int x,y;
	cin>>op>>x>>y;
	switch(op)
	{
		case '+':cout<<x+y<<endl;
		case'-':cout<<x-y<<endl;
		case '*':cout <<x*y<<endl;
		case '/':cout<<x/y<<endl;
	}
	return 0;
}
