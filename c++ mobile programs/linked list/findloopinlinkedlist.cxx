#include<iostream>
using namespace std;

class node{
public:
int data;
node* next;

    node(int a)   
    {data=a;
    next=NULL;
    }   
};
void displaylinked(node* head)
{cout<<head->data<<" -> ";
    while(head->next!=NULL)
{head=head->next;
    cout<<head->data<<" -> ";
}
cout<<"NULL";
return;
}
    
void removecycle(node* &head)
{node* tr;
node* ha;
tr=head;
ha=head;
tr=tr->next;
ha=(ha->next)->next;
while(tr!=ha)
{if (tr==NULL)
return;
tr=tr->next;
if ((ha==NULL) || (ha->next==NULL) || (ha->next->next==NULL))
return;
ha=ha->next->next;   
}
   ha=head;
   while(ha->next != tr->next)
   {ha=ha->next;
   tr=tr->next;
   }
   tr->next=NULL;
   return;
}
    
bool ifcycleinlinkedlist(node* head)
{node* tr;
node* ha;
tr=head;
ha=head;
tr=tr->next;
ha=(ha->next)->next;
while(tr!=ha)
{if (tr==NULL)
return 0;
tr=tr->next;
if ((ha==NULL) || (ha->next==NULL) || (ha->next->next==NULL))
return 0;
ha=ha->next->next;   
}
   return 1; 
}

int main()
{node* head=new node(1);
bool jj;
node* pp;
node* qq;
node* gg;
qq=head;
for (int i=2;i<8;i++)
{pp=new node(i);
if (i==3)
gg=pp;
qq->next=pp;
qq=pp;
}
displaylinked(head);
cout<<endl;
cout<<"looping is from end to "<<gg->data;
qq->next=gg;
//displaylinked(head);
jj=ifcycleinlinkedlist(head);
cout<<endl;
cout<<"is there a cycle= ";
cout<<jj;
removecycle(head);
cout<<endl;
displaylinked(head);
return 0;
}

// for checking for looping
// take hare and tortoise pointer (moving 2 node and 1 node at a time respectively).
// if tr/ha/ha->next become null then no looping
//if tr=ha then loop present

//for removing loop
//after tr=ha set ja again to jead and then increment both by 1 bode up until ha->next =tr->next. thereafter set tr->next=NULL
