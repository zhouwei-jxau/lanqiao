#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Edge
{
	int sourceVert;
	int destnationVert;
	int weight;
};
int MAX_INT=(~(unsigned int)0)/2; 
int main(int argc, char** argv) {
	Edge edges[1000];
	int t,r,p,s;
	int minWeight=MAX_INT;
	int* dist=NULL;
	cin>>t>>r>>p>>s;
	dist=new int[t+1];
	for(int i=1;i<=t;i++)
	{
		dist[i]=MAX_INT;
	}
	dist[s]=0;
	for(int i=0;i<r;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		edges[2*i].sourceVert=s;
		edges[2*i].destnationVert=d;
		edges[2*i].weight=w;
		edges[2*i+1].sourceVert=d;
		edges[2*i+1].destnationVert=s;
		edges[2*i+1].weight=w;
		if(w<minWeight)
		{
			minWeight=w;
		}
	}
	for(int i=2*r;i<2*r+p;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		edges[i].sourceVert=s;
		edges[i].destnationVert=d;
		edges[i].weight=w;
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<2*r+p;j++)
		{
			int u=edges[j].sourceVert;
			int v=edges[j].destnationVert;
			long long w=edges[j].weight;
			long long d=dist[u];
			d=d+w;
			if(d<((long long)dist[v]))
			{
				dist[v]=d;
			}
		}
	}
	//检测负权回路 
	for(int i=0;i<2*r+p;i++)
	{
		int u=edges[i].sourceVert;
		int v=edges[i].destnationVert;
		long long w=edges[i].weight;
		long long d=dist[u];
		d=d+w;
		if(d<((long long)dist[v]))
		{
			cout<<"存在负权回路!无法计算"<<endl;
		}
			
	}
	for(int i=1;i<=t;i++)
	{
		if(dist[i]>=min((long long)MAX_INT+minWeight,(long long)MAX_INT))
		{
			cout<<"NO PATH"<<endl;
		}
		else
		{
			cout<<dist[i]<<endl;
		}
	}
	delete[] dist;
	return 0;
}
