#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a,b,result;
	cin>>a>>b;
	printf("%4d\n",a);
	result=a*b;
	printf("x%3d\n",b);
	cout<<"---------"<<endl;
	int bit=4;
	while(b>0)
	{
		char buf[10];
		sprintf(buf,"%d",bit);
		string format=string("%")+string(buf)+string("d\n");
		int t=(b%10)*a;
		printf(format.c_str(),t);
		b/=10;
		bit--;
	}
	if(bit<3)
	{
		cout<<"---------"<<endl;
		printf("%4d",result);
	}
	return 0;
}
