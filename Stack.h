#include<iostream>
using namespace std;
struct node
{
	int num;
	node *next;
};
class Stack
{
	node *top;
	public:
	Stack()
	{
		top=NULL;	
	}	
	void push(int num);
	int pop(char op);
	void display();
};
void Stack::push(int num)
{
	node *t;
	t->num=num;
	if(top==NULL)
	{
		top=t;
	}
	else
	{
		top->next=t;
		top=t;
	}
}
int Stack :: pop(char op)
{
	int fnum ,snum, result;
	fnum = top->num;
	top=top->next;
	snum=top->num;
	top=top->next;
	switch(op)
	{
		case '-':
			result=fnum-snum;
			break;
		case '+':
			result=fnum+snum;
			break;
		case '/':
			result=fnum/snum;
			break;
		case '%':
			result=fnum%snum;
			break;
		case '^':
			result=fnum^snum;
			break;
	}
	push(result);
}
void Stack :: display()
{
	node *t=top;
	while(t!=NULL)
	{
		cout<<t->num<<" ";
		t=t->next;
	}
}
