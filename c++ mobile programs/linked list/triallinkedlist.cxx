#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  
    node(int a)
    {next=NULL;
    data=a;
    } 
};

node* addelementstart(node* head, int a)
{if (head==NULL)
{head=new node (a);
return head;    
}
node* pp;
pp=new node(a);
pp->next=head;
return pp;  
}

node* addelementlast(node* head,int a)
{if (head==NULL)
{head=new node(a);
return head;
}
if (head->next==NULL)
{  node* kk=new node(a);
    head->next=kk;
    return head;
}
node* zz=head;
while (head->next!=NULL)
head=head->next;
node* kk=new node(a);
    head->next=kk;
    return zz;   
}

node* reverseinsetk(node* head,int k)
{if (head==NULL)
return head;
int si=1;
node* pp=head;
while (pp->next!=NULL)
{pp=pp->next;
si++;
}
int kkk=k;
if (k>si)
return head;

pp=head;
node* gg;
node* hh; 
node* kk;
gg=pp->next;
hh=gg->next;
while(k>1)
{
  gg->next=pp;
  pp=gg;
  gg=hh;
  if (hh!=NULL)
  hh=hh->next;
  k--;   
}
head->next=reverseinsetk(gg,kkk); 
head=pp;
   
return head;      
}

void displaylinked (node* head)
{if (head==NULL)
{cout<<" no linked list";
return;
}
 cout<<"Linked list = ";
cout<<head->data<<" -> ";
    while (head->next != NULL)
    {head=head->next;
    cout<<head->data<<" -> ";   
}
cout<<"NULL";
return;
}

int main()
{int i;
node* head;
head=NULL;
head=addelementstart(head,1);
head=addelementstart(head,0);
head=addelementlast(head,2);
head=addelementlast(head,3);
head=addelementlast(head,4);
head=addelementlast(head,5);
head=addelementlast(head,6);
head=addelementlast(head,7);
displaylinked(head);  
cout<<endl;
head=reverseinsetk(head,4);
displaylinked(head);  
    
    
    
    
 return 0;   
}