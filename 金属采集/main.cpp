#include <iostream>
#include <List>
#include <queue>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//������Ҫ����̰���㷨��⣬��dijkstra�㷨�����ľ��� 
//�����ˣ��ȴ�1�������˵������ʼ������
//��������˵������ʡ������ 
//�ڵ�һ�������˷���ԭ���Ľ�㵽��һ�������˵���ý��ʱ�����������ȵ�һ���������٣�
//��ô�����˿���ֱ�ӷ��ص��� �������ط�����һ����㣬�Ӷ���ʡ����
//��ô���Եõ������㷨
//0.���һ�����С�Ľڵ㣬����ʼ����ɻ�����ǰ�� 
//1.�ɳ��Ļ����˼���Ѱ����������ǰ���Ľ��
//2.�жϻ����˴ӵ�ǰλ�ú���㣬�ĸ�����Ŀ����Ļ�����
//3.����ӵ�ǰλ�û����٣���ô�ɻ����˼���̽��
//4.����������������ô�ɻ����˷��ص��򣬴�����ɳ��»�����
//5.�ص���һ����ֱ�����н�㶼��̽���� 
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
	//ͳ����㵽��������ľ���
	CalculateCost(nodes,s);
	for(int i=1;i<=n;i++)
	{
		cout<<i<<"\t"<<nodes[i].weight<<"\t"<<nodes[i].cost<<endl;
	}
	cout<<Dijkstra(edges,n,2*(n-1),6,2)<<endl;
	//������̾���
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
	//����ǰ�������Ϊ��̽��
	node[current].checked=true; 
	//����һ��ʼ����ˣ�Ӧ����̰���㷨
	//��һ�����뵱ǰ�������Ľ��
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
	//������н�㶼��̽�����ˣ���ôֱ���˳�
	if(nearestNode==-1)
		return; 
	//�Ƚϵ�ǰ�����˼���̽��������ѡ�ɻ����˵Ļ���
	if(numOfRebort>1)
	{
		if(node[nearestNode].cost<minCost)
		{
			//�������ѡ�ɻ����˸���Ļ�
			//����ѡ�ɻ�����,�ɻ����˷��� 
			Explore(node,edges,numOfNode,numOfEdge,start,numOfRebort-1,start);
			return;
		}
	}
	tCost+=minCost;
	//�ɻ����˼���̽��
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
