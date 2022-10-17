#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node *next;
}*head;
class circularlink
{
	private:
		node *head;
	public:
		circularlink()
		{
			head=NULL;
		}
		circularlink(int a[],int n)
		{
			int i;
			node *t,*last;
			head=new node;
			head->data=a[0];
			head->next=head;
			last=head;
			
			for(i=1;i<n;i++)
			{
				t=new node;
				t->data=a[i];
				t->next=last->next;
				last->next=t;
				last=t;
				
			}
			}
	void display(node *p)
	{
		p=head;//why
	
		do
		{
			cout<<p->data<<" ";
			p=p->next;
		}while(p!=head);
	}
	int length()
	{
		int l=0;
		node *p=head;
		do
		{
		l++;
		p=p->next;	
		}while(p!=head);
		
		return l;
		
	}
	void insert(node *p,int index,int x)
	{
		p=head;
		node *t;
		int i;
		t=new node;
		t->data=x;
		if(index<0 || index>length())
		return ;
		else
		{
			if(index==0)
			{
				if(head==NULL)
				{
					head=t;
					head->next=head;
				}
				else
				
				while(p->next!=head)
				{
					p=p->next;
				}
				p->next=t;
				t->next=head;
				head=t;
			}
			else
			{
				for(i=1;i<index-1;i++)
				{
					p=p->next;
				}
				t->next=p->next;
				p->next=t;
			}
		}
		
	}
	void rdisplay(node *p)
	{
		p=head;
		static int flag=0;
		if(p!=head || flag==0)
		{
			flag=1;
			cout<<p->data;
			rdisplay(p->next);
		}
		flag=0;
	}
	int delet(node *p,int index)
	{
		p=head;//why
		int x,i;
		node *q,*t;
		if(index<0 || index>length())
		return -1;
			if(index==1)
			{
				while(p->next!=head)
				{
					p=p->next;
				}
				x=head->data;
				if(head==p)
				{
				delete head;
				head=NULL;	
				}
				else
				{
				p->next=head->next;
				delete head;
				head=p->next;	
				}
			}
			else
			{
			 
				for(i=0;i<index-2;i++)
					p=p->next;
				q=p->next;
				x=q->data;
				p->next=q->next;
				delete q;
				
			}
		return x;
		
	}
		 
};
int main()
{
	int a[]={1,3,5,7,9};
	circularlink c(a,5);
//	c.display(head);
//	cout<<c.length();
   // c.insert(head,0,8);
   c.delet(head,1);
    c.display(head);
    //c.rdisplay(head);	
}
