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

void appendlastk(node* &head,int k)
{node* pp=head;
int si=1;
while(pp->next!=NULL)
{si++;
pp=pp->next;
}
if (si==k)
return;
if(si<k)
{cout<<"NOT POSSIBLE";
return;
}
pp=head;
int i=1;
while (i<si-k)
{pp=pp->next;
i++;   
}
node* jo=head;
head=pp->next;
pp->next=NULL;
pp=head;
    while(pp->next!=NULL)
    pp=pp->next;
    pp->next=jo;
   return;     
}

void displaylinked(node* head)
{cout<<head->data<<" -> ";
    while(head->next!=NULL)
{head=head->next;
    cout<<head->data<<" -> ";
}
cout<<"NULL";
return;
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
qq->next=pp;
qq=pp;
}
displaylinked(head);
appendlastk(head,2);
cout<<endl;
displaylinked(head);

return 0;
}