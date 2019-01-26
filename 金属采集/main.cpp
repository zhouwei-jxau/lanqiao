#include <iostream>
#include <List>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//这题主要利用贪心算法求解，用dijkstra算法求结点间的距离 
//明白了，先从1个机器人的情况开始分析，
//多个机器人的情况节省的能量 
//在第一个机器人返回原来的结点到另一个机器人到达该结点时所花的能量比第一个机器人少，
//那么机器人可以直接返回地球 ，而不必返回上一个结点，从而节省能量
//那么可以得到如下算法
//0.查找花费最小的节点，从起始结点派机器人前往 
//1.派出的机器人继续寻找其他可以前往的结点
//2.判断机器人从当前位置和起点，哪个距离目标结点的花费少
//3.如果从当前位置花费少，那么旧机器人继续探索
//4.如果从起点距离近，那么旧机器人返回地球，从起点派出新机器人
//5.回到第一步，直到所有结点都被探索过 
struct Node
{
	int weight;
	int cost;
	bool checked;
	list<int> child;
};
struct Edge
{
	 int source;
	 int destnation;
	 int weight;
};
void CalculateCost(Node* node,int start=0);
void Explore(Node* node,Edge* edges,int numOfNode,int numOfEdge,int current,int numOfRebort,int start);
int Dijkstra(Edge* edges,int numOfVert,int numOfEdge,int start,int end);
int tCost=0;
int main(int argc, char** argv) {
	Node* nodes;
	Edge* edges;
	int n,s,k;
	cin>>n>>s>>k;
	nodes=new Node[n+1];
	edges=new Edge[2*(n-1)];
	for(int i=0;i<n-1;i++)
	{
		int p,c,w;
		cin>>p>>c>>w;
		edges[2*i].source=p;
		edges[2*i].destnation=c;
		edges[2*i].weight=w;
		edges[2*i+1].source=c;
		edges[2*i+1].destnation=p;
		edges[2*i+1].weight=w;
		nodes[c].weight=w;
		nodes[c].checked=false;
		nodes[p].child.push_back(c);
	}
	nodes[s].weight=0;
	nodes[s].checked=true;
	//统计起点到各个顶点的距离
	CalculateCost(nodes,s);
	for(int i=1;i<=n;i++)
	{
		cout<<i<<"\t"<<nodes[i].weight<<"\t"<<nodes[i].cost<<endl;
	}
	cout<<Dijkstra(edges,n,2*(n-1),6,2)<<endl;
	//计算最短距离
	Explore(nodes,edges,n,2*(n-1),s,k,s); 
	delete[] nodes;			
	return 0;
}

void CalculateCost(Node* node,int start)
{
	if(node[start].child.size()!=0)
	{
		for(list<int>::iterator itor=node[start].child.begin();itor!=node[start].child.end();itor++)
		{
			node[*itor].cost=node[start].weight+node[*itor].weight;
			CalculateCost(node,*itor);	
		}
	}
}

void Explore(Node* node,Edge* edges,int numOfNode,int numOfEdge,int current,int numOfRebort,int start)
{
	//将当前结点设置为以探索
	node[current].checked=true; 
	//看来一开始想错了，应该用贪心算法
	//找一个距离当前结点最近的结点
	int minCost=-1;
	int nearestNode=-1;
	for(int i=1;i<=numOfNode;i++)
	{
		if(node[i].checked==false)
		{
			if(nearestNode==-1)
			{
				nearestNode=i;
				minCost=Dijkstra(edges,numOfNode,numOfEdge,current,i);
			}
			else
			{
				if(Dijkstra(edges,numOfNode,numOfEdge,current,i)<minCost)
				{
					nearestNode=i;
					minCost=Dijkstra(edges,numOfNode,numOfEdge,current,i);
				}
			}
		}
	}
	//如果所有结点都被探索过了，那么直接退出
	if(nearestNode==-1)
		return; 
	//比较当前机器人继续探索和重新选派机器人的花费
	if(numOfRebort>1)
	{
		if(node[nearestNode].cost<minCost)
		{
			//如果重新选派机器人更快的话
			//重新选派机器人,旧机器人返回 
			Explore(node,edges,numOfNode,numOfEdge,start,numOfRebort-1,start);
			return;
		}
	}
	tCost+=minCost;
	//旧机器人继续探索
	Explore(node,edges,numOfNode,numOfEdge,nearestNode,numOfRebort,start); 
}

int Dijkstra(Edge* edges,int numOfVert,int numOfEdge,int start,int end)
{
	int* dist=new int[numOfVert+1];
	for(int i=0;i<numOfVert+1;i++)
		dist[i]=-1;
	dist[start]=0;
	queue<int> q;
	q.push(start);
	while(!q.empty())
	{
		int current=q.front();
		q.pop();
		for(int i=0;i<numOfEdge;i++)
		{
			if(edges[i].source==current)
			{
				if(dist[edges[i].destnation]==-1)
				{
					q.push(edges[i].destnation);
				}
				if(dist[edges[i].destnation]>0)
				{
					if(dist[edges[i].destnation]>dist[current]+edges[i].weight)
						dist[edges[i].destnation]=dist[current]+edges[i].weight;
				}
				else
				{
					dist[edges[i].destnation]=dist[current]+edges[i].weight;
				}
			}
		}
	}
	int d=dist[end];
	delete[] dist;
	return d;
}
