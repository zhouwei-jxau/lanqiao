#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Plus(double& x);
void clamp(double& x,double max,double min=0);

int main(int argc, char** argv) {
	double over100=0;
	double over60;
	double over40;
	double over20;
	double over10;
	double base;
	double x;
	cin>>x;
	over100=x-1000000;
	Plus(over100);
	over60=x-600000;
	clamp(over60,400000,0);
	over40=x-400000;
	clamp(over40,200000,0);
	over20=x-200000;
	clamp(over20,200000,0);
	over10=x-100000;
	clamp(over10,100000,0);
	base=x;
	clamp(base,100000,0);
	printf("%.2f",over100*0.01+over60*0.015+over40*0.03+over20*0.05+over10*0.075+base*0.1);
	return 0;
}

void clamp(double& x,double max,double min)
{
	if(x>max)
	{
		x=max;
	}
	if(x<min)
	{
		x=min;
	}
}
void Plus(double&x)
{
	if(x<0)
	{
		x=0;
	}
}
