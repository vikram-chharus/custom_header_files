#include<iostream>
using namespace std;
struct node 
{
	int x,y;
	string word;
	node *next;
};
class Queue
{
	node *front,*rear;
	public:
		Queue()
		{
			front=NULL,rear=NULL;
		}
		void push(int x,int y);
		void push(string word);
		void pop();
		int search(int x,int y);
		void display();
};
void Queue :: display()
{
	node *t=front;
	while(t!=rear||t!=NULL)
	{
		cout<<t->word<<" ";
		t=t->next;
	}
}
void Queue :: push(int x,int y)
{
	node *temp=new node;
	if(temp!=NULL)
	{
		temp->x=x;
		temp->y=y;
		temp->next=NULL;
		if(rear==NULL&&front==NULL)
		{
			rear=temp;
			front=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;	
		}
	}
	else
	{
		return;
	}
}
void Queue :: push(string word)
{
	node *temp=new node;
	if(temp!=NULL)
	{
		temp->word=word;
		temp->next=NULL;
		if(rear==NULL&&front==NULL)
		{
			rear=temp;
			front=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;	
		}
	}
	else
	{
		return;
	}
}
void Queue :: pop()
{
	if(front==NULL)
	{
		rear=NULL;
		front=NULL;
		return;
	}
	else
	{
		front=front->next;
	}
}
int Queue :: search(int x,int y)
{
	if(front==NULL&&rear==NULL)
	{
		return 0;
	}
	else
	{
		node *temp=front;
		int found=0;
		while(temp!=NULL && !found)
		{
			if(temp->x==x&&temp->y==y)
			{
				found=1;
				return 1;
			}
			temp=temp->next;
		}
		if(!found)
		{
			return 0;
		}
	}
}
