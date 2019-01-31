#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node
{
	bool quarantine;
	bool infect;
	vector<int> child;
};

void Infect(Node* tree,int current,int& infected);

int main(int argc, char** argv) {
	Node tree[1000];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		int t=x;
		if(x>y)
		{
			x=y;
			y=t;
		}
		tree[x].quarantine=false;
		tree[x].infect=false;
		tree[x].child.push_back(y);
	}
	tree[1].infect=true;
	int infected=0;
	Infect(tree,1,infected);
	cout<<infected;
	return 0;
}

void Infect(Node* tree,int current,int& infected)
{
	int maxChild=0;
	infected++;
	tree[current].infect=true;
	for(int i=0;i<tree[current].child.size();i++)
	{
		if(tree[tree[current].child[i]].child.size()>tree[tree[current].child[maxChild]].child.size())
		{
			maxChild=i;			
		}
	}
	if(tree[current].child.size()>0)
		tree[tree[current].child[maxChild]].quarantine=true;
	for(int i=0;i<tree[current].child.size();i++)
	{
		if(i==maxChild)
			continue;
		Infect(tree,tree[current].child[i],infected);
	}
}
