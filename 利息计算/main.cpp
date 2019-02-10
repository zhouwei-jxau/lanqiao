#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double prinpical,accrualRate;
	cin>>prinpical>>accrualRate;
	double accrual=prinpical*accrualRate*0.8/100;
	cout<<accrual+prinpical;
	
	return 0;
}
