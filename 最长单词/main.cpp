#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char in[10000];
	int max_start=0,max_end=0;
	char ch;
	for(int i=0;(ch=getchar())!='\n';i++)
	{
		in[i]=ch;
	}
	int end=0;
	for(int i=0;in[i];i++)
	{
		if(in[i]==' ')
		{
			if(i-end>max_end-max_start)
			{
				max_end=i;
				max_start=end;
			}
			end=i;
		}
		if(in[i+1]==0)
		{
			if(i+1-end>max_end-max_start)
			{
				max_end=i+1;
				max_start=end;
			}
			end=i;
		}
	}
	for(int i=max_start+1;i<max_end;i++)
	{
		cout<<in[i];
	}
	return 0;
}
