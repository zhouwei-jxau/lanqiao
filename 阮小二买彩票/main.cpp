#include <iostream>
#include <string>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Char
{
	char ch;
	bool arrayed;
};

void array(string current,Char* n,int len);

map<string,int> m;

int main(int argc, char** argv) {
	Char n[10];
	char ch;
	int len;
	for(len=0;(ch=getchar())!='\n';len++)
	{
		n[len].ch=ch;
		n[len].arrayed=false;
	}
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(n[i].ch>n[j].ch)
			{
				Char t=n[i];
				n[i]=n[j];
				n[j]=t;
			}
		}
	}
	array(string(""),n,len);
	for(map<string,int>::iterator itor=m.begin();itor!=m.end();itor++)
	{
		cout<<itor->first<<endl;
	}
	return 0;
}

void array(string current,Char* n,int len)
{
	bool flag=false;
	for(int i=0;i<len;i++)
	{
		if(n[i].arrayed==false)
		{
			Char* tn=new Char[len];
			for(int j=0;j<len;j++)
				tn[j]=n[j];
			tn[i].arrayed=true;
			array(current+n[i].ch,tn,len);
			delete[] tn;
			flag=true;
		}
	}
	
	if(!flag)
	m.insert(pair<string,int>(current,m.size()));
}
