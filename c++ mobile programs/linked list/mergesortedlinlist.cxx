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

node* mergingrecursion(node* h1,node* h2)
{node* pp=h1;
node* qq=h2;
node* h3;
node* head;
if ((h1==NULL) && (h2==NULL))
return NULL;
else if (h2==NULL)
return h1;
else if (h1==NULL)
return h2;


if(pp->data<=qq->data)
       { h3=pp;
       head=h3;
       pp=pp->next;
       }
        else
       { h3=qq;
       head=h3;
       qq=qq->next;
       }
node* kk=mergingrecursion(pp,qq);
head->next=kk;
return head;    
}



node* mergesortedlinlist(node* h1,node* h2)
{node* pp=h1;
node* qq=h2;
node* h3;
node* head;
if(pp->data<=qq->data)
       { h3=pp;
       head=h3;
       pp=pp->next;
       }
        else
       { h3=qq;
       head=h3;
       qq=qq->next;
       }
       
while ((pp!=NULL)&&(qq!=NULL))
    {
        if(pp->data<=qq->data)
        {h3->next=pp;
        pp=pp->next;
        h3=h3->next;
        }
     else
        {h3->next=qq;
        qq=qq->next;
        h3=h3->next;
        }
    }
    
    if ((pp==NULL)&&(qq!=NULL))
    {
        while (qq!=NULL)
    {h3->next=qq;
        qq=qq->next;
        h3=h3->next;
    }
    }
    else if ((qq==NULL)&&(pp!=NULL))
    {
        while (pp!=NULL)
    {h3->next=pp;
        pp=pp->next;
        h3=h3->next;
    }
    }
    return head;
}

node* moveoddfirst(node* head)
{node* pp=head;
node* head2=pp->next;
node* qq=head->next;
while((pp->next!=NULL)&&(qq->next!=NULL))
{
    pp->next=qq->next;
pp=pp->next;
qq->next=pp->next;
qq=qq->next; 
}
pp->next=head2;
return head;
}

int main()
{node* h1=new node(1);
h1->next=new node(3);
h1->next->next=new node(5);
h1->next->next->next=new node(7);
h1->next->next->next->next=new node(9);
node* h2=new node(2);
h2->next=new node(4);
h2->next->next=new node(6);
cout<<endl<<"linlist1=";
displaylinked(h1);
cout<<endl<<"linlist2=";
displaylinked(h2);
//node* h3=mergesortedlinlist(h1,h2);
node* h3=mergingrecursion(h1,h2);
cout<<endl<<"mergedlinlist=";displaylinked(h3);
h3=moveoddfirst(h3);
cout<<endl;
displaylinked(h3);

return 0;
}
