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

void intersection (node* head1,node* head2)
{node* pp=head1;
node*qq=head2;
int s1=1,s2=1,fl;
while(pp->next!=NULL)
{s1++;
pp=pp->next;
}
pp=head1;
while(qq->next!=NULL)
{s2++;
qq=qq->next;
}
qq=head2;
if (s1>=s2)
{int ch=s1-s2;
while(ch>0)
{pp=pp->next;
ch--;
}
while((pp->next!=qq->next)&&(pp!=NULL))
{pp=pp->next;
qq=qq->next;    
}
if (pp==NULL)
{cout<<"no intersection";
return;
}
cout<<"intersection is there"<<endl;
cout<<"point of intersection= "<<pp->next->data;
return;
}
else
{pp=head2;
qq=head1;
fl=s1;
s1=s2;
s2=fl;
int ch=s1-s2;
while(ch>0)
{pp=pp->next;
ch--;
}
while((pp->next!=qq->next)&&(pp!=NULL))
{pp=pp->next;
qq=qq->next;    
}
if (pp==NULL)
{cout<<"no intersection";
return;
}
cout<<endl;
cout<<"intersection is there"<<endl;
cout<<"point of intersection= "<<pp->next->data;
return;        
}
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
{node* head1=new node(1);
node* pp;
node* qq;
node* gg;
qq=head1;
for (int i=2;i<8;i++)
{pp=new node(i);
if (i==5)
gg=pp;
qq->next=pp;
qq=pp;
}

node* head2=new node(15);
head2->next=new node(10);
head2->next->next=gg;
cout<<"first linked list is= "<<endl;
displaylinked(head1);
cout<<endl<<"2nd linkedlist is= "<<endl;
displaylinked(head2);
cout<<endl;
intersection(head2,head1);
cout<<endl;

return 0;
}