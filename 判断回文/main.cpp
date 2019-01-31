#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string s;
	cin>>s;
	bool flag=true;
	for(int i=0;i<s.length()/2;i++)
	{
		if(s.at(i)!=s.at(s.length()-i-1))
		{
			flag=false;
			break;
		}
	}
	if(flag)
	cout<<"yes!";
	else
	cout<<"no!";
	return 0;
}
