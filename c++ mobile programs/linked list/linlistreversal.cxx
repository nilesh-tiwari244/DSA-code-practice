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

void displaylinlist(node* head)
{if (head==NULL)
{cout<<"empty";
return;
}
while(head->next!=NULL)
{cout<<head->data<<" -> ";
head=head->next;
}
cout<<head->data<<" -> NULL";
return;
}

node* deleteval(node* head,int val)
{
 if (head==NULL)
{cout<<"no linlist";
return head;
}

if (head->next==NULL)
{if(val==head->data)
 {delete head;
 return NULL;
 }
 else
 {cout<<"element not found";
 return head;
 }
}

if(head->data==val)
{return head->next;
delete head;
}

node* pp=head;
node* gg=pp->next;

while(pp->next!=NULL)
{if (gg->data==val)
{pp->next=gg->next;
delete gg;
return head;
}
pp=gg;
if(gg->next!=NULL)
gg=gg->next;
}
cout<<"element not found";
return head;
}

/*
node* reverselinlist(node* head)//recursio
{if ((head==NULL)|| (head->next==NULL))
return head;
node* kk=reverselinlist(head->next);
head->next->next=head;
head->next=NULL;
return kk;  
}
*/
node* reverselinlist(node* head)//iteration
{if ((head==NULL)|| (head->next==NULL))
return head;
node* pp=head;
node* gg=pp->next;
node* hh=gg->next;
while(gg!=NULL)
{ gg->next=pp;
    pp=gg;  
    gg=hh;
    if (hh!=NULL)
hh=hh->next;
}
head->next=NULL;
return pp; 
}

int main()
{node* head;
head=new node(0);
head->next= new node(1);
head->next->next= new node(2);
head->next->next->next= new node(3);
displaylinlist(head);
head=reverselinlist(head);
cout<<endl;
head=deleteval(head,3);
cout<<endl;
displaylinlist(head);
return 0;
}
