#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct Edge
{
	int vert1;
	int vert2;
	double weight;
	double sigma;
	bool selected;	
};
int comp(const void* a,const void* b);
int comp_desc(const void* a,const void* b);
int comp_asc(const void* a,const void* b);
int FindEnd(Edge* edges,int numOfEdge,int edge);
int main() {
	double avg=0;
	double sigma=99999999999999999999;
	Edge edges[1000];
	for(int i=0;i<1000;i++)
	{
		edges[i].selected=false;
		edges[i].vert1=-1;
		edges[i].vert2=-1;
		edges[i].sigma=-1;
		edges[i].weight=-1;
	}
	for(int x=0;;x++)
	{
	sigma=99999999999999999999;
	int m,n,maxSum=0,minSum=0;
	cin>>m>>n;
	if(m==0&&n==0)
	break; 
	for(int i=0;i<n;i++)
	{
		cin>>edges[i].vert1>>edges[i].vert2>>edges[i].weight;
	}
	//求最小和
	qsort(edges,n,sizeof(Edge),comp_asc);
	for(int i=0;i<m-1;i++) minSum+=edges[i].weight;
	qsort(edges,n,sizeof(Edge),comp_desc);
	for(int i=0;i<m-1;i++) maxSum+=edges[i].weight;
	for(int j=minSum;j<=maxSum;j++)
	{
		int wSum=0;
		double sSum=0;
		avg=((double)j)/(m-1);
		for(int k=0;k<n;k++)
		{
			edges[k].sigma=fabs(edges[k].weight-avg);
		}
		qsort(edges,n,sizeof(Edge),comp);
		//执行克鲁斯卡尔算法 
		int count=0;
		for(int i=0;i<n;i++)
		{
			int vert1_end=FindEnd(edges,n,edges[i].vert1);
			int vert2_end=FindEnd(edges,n,edges[i].vert2);
			if(vert1_end!=vert2_end)
			{
				edges[i].selected=true;
				avg+=edges[i].weight;
				count++;
			}
			if(count==m-1)
			break;
		}
		for(int i=0;i<n;i++)
		{
			if(edges[i].selected)
			{
				edges[i].selected=false;
				int weight=edges[i].weight;
				double delta=edges[i].sigma;
				delta*=delta; 
				sSum+=delta;
				wSum+=weight;
			}
		}
		if(wSum==j)
		{
			sSum/=count;
			if(sSum<sigma)
				sigma=sSum;
		}
	}
	printf("CASE%d:%.2f\n",x,sigma); 
	}


	return 0;
}
int comp(const void* a,const void* b)
{
	if(((Edge*)a)->sigma-((Edge*)b)->sigma>0)
	{
		return 1;
	}
	else if(((Edge*)a)->sigma-((Edge*)b)->sigma==0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
int comp_asc(const void* a,const void* b)
{
	return ((Edge*)a)->weight-((Edge*)b)->weight;
}
int comp_desc(const void* a,const void* b)
{
	return -((Edge*)a)->weight+((Edge*)b)->weight;
}
int FindEnd(Edge* edges,int numOfEdge,int edge)
{
	int end=edge;
	for(int j=0;j<2;j++)
	for(int i=0;i<numOfEdge;i++)
	{
		if(edges[i].selected)
		{
			if(edges[i].vert1==end)
			{
				if(edges[i].vert2>end)
					end=edges[i].vert2;
			}
			else if(edges[i].vert2==end)
			{
				if(edges[i].vert2>end)
					end=edges[i].vert1;                                                                                                                                                                                                           
			}
		}
	}
	return end;
}
