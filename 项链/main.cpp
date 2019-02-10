#include <iostream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node
{
	char data;
	Node* previous;
	Node* next;
};
int main(int argc, char** argv) {
	char chain[101];
	cin>>chain;
	Node* head=NULL;
	Node* tail=NULL;
	Node* link=new Node;
	link->data=chain[0];
	link->next=NULL;
	link->previous=NULL;
	head=link;
	tail=link;
	int len=strlen(chain);
	for(int i=1;i<len;i++)
	{
		Node* node=new Node;
		node->data=chain[i];
		node->previous=tail;
		node->next=NULL;
		tail->next=node;
		tail=node;
	}
	head->previous=tail;
	tail->next=head;
	//从头开始查找
	int max=0;
	Node* current=head;
	bool flag=false;
	while(!flag||current!=head)
	{
		if(head==current)
			flag=true;
		char initial=current->data;
		Node* last=current;
		Node* next=current->next;
		int count=0;
		while(true)
		{
			if(initial=='w')
			{
				if(last->data!='w')
					initial=last->data;
				count++;
				last=last->previous;
			}
			else
			{
				if(last->data!=initial&&last->data!='w')
				{
					break;
				}
				last=last->previous;
				count++;
			}
		}

		initial=next->data;
		while(true)
		{
			if(initial=='w')
			{
				if(next->data!='w')
					initial=next->data;
				count++;
				next=next->next;	
			}
			else
			{
				if(next->data!=initial&&next->data!='w')
				{
					break;
				}
				next=next->next;
				count++;
			}
		}

		if(count>max)
			max=count;
		current=current->next;	
	} 
	tail->next=head;
	while(head->next!=head)
	{
		Node* t=head->next;
		head->next=t->next;
		delete t;
	}
	delete head;
	cout<<max;
	return 0;
}
