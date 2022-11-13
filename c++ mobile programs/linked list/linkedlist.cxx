#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int a)
    {data=a;
    next=NULL;
    }       // class ke object ka pointer se attribute ke acces karne ke liye -> use karo
};

void insertatend(node* &head,int val)
{node* p=new node(val);
if (head==NULL)
{head=p;
return;
}
node* tt=head;
while (tt->next!=NULL)
{tt=tt->next;
}
tt->next=p;
return;
}

void displaylinked(node* head)//no need for reference call, call by reference will also do
{while (head->next!=NULL)
{cout<<head->data<<" -> ";
    head=head->next;
}
cout<<head->data<<" null ";    
}

void insertatstart(node* &head,int val)
{node* tt=new node(val);
tt->next=head;
head=tt;  
}

void deletenthnode(node* &head,int n,int m)
{int k=1,i;
node* tt=head;
int s=1;
while (tt->next!=NULL)
{s++;
tt=tt->next;
}
cout<<"size="<<s<<endl;
tt=head;
if (n+m-1>s)
{cout<<"NOT POSSIBLE"<<endl;
return;
}

if (n<=0)
{ cout<<"n<0 wala se"<<endl;
cout<<"not possible";
    return;
}

if (n==1)
{   for (i=1;i<=m;i++)
        {head=head->next;
        delete tt;
        tt=head;
        }
        cout<<"n=1 wala se\n";
        return;   
}
node* pp;
node* jjj;
while (k<=n)
{if (k==n-1)
{pp=tt;
jjj=pp;
    for (i=1;i<=m;i++)
{
pp=pp->next;
}
tt->next=pp->next;
 for (i=1;i<=m;i++)
 {pp=jjj->next;
   jjj=jjj->next;
   delete pp;  
     
 }
return;
}
k=k+1;
tt=tt->next;
}
       
}

void reverselinked(node* &head)
{//function ko trust karo
//head ko reverse kardega
    
    if (head->next==NULL)
    return;
    
    node* pp;
    node* xx;
    pp=head;
    
    xx=head->next;
    
    reverselinked(xx);
    
    head=xx;
    node* kk=head;
    while (kk->next!=NULL)
    {kk=kk->next;    
    }
    pp->next=NULL;
    kk->next=pp;  
    return;
    
}

void reverseknode(node* &head,int n,int k)
{int s=1;
node* pp;
node* jj;
pp=head;

while(pp->next!=NULL)
{s++;
pp=pp->next;    
}
pp=head;

if (n>s)
return;

if(n+k-1>s)
{cout<<"NOT POSSIBLE"<<endl;
return;
}

node* hh;
node* gg;

if (n==1)
{
gg=pp->next;

while (k>1)
{k--;
hh=gg->next;
gg->next=pp;
pp=gg;
gg=hh;
}
head->next=gg;
head=pp;
cout<<"s1";
reverseknode(head,n+k,k);
cout<<"s2";
return;
    
    
}

while(n>1)
{n--;
jj=pp;//pehle wala node
pp=pp->next;//node jaha se reverse karna hai
}

gg=pp->next;

while (k>1)
{k--;
hh=gg->next;
gg->next=pp;
pp=gg;
gg=hh;
}
jj->next->next=gg;
jj->next=pp;


//reverseknode(head,n+k,k);
return;
}


int main()
{node* head=NULL;
    insertatstart(head,1);
    insertatend(head,2);
      insertatend(head,3);
        insertatend(head,4);
         insertatend(head,5);
      insertatend(head,6);
        insertatend(head,7);
        displaylinked(head); 
        cout<<endl;
       // deletenthnode(head,4,2);
      // reverselinked(head);
      reverseknode(head,1,2);
    displaylinked(head); 
    return 0;
}