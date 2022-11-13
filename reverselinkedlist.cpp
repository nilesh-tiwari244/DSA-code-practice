#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int a){
        data=a;
        next=NULL;
    }
};
void addtolink(node* &h,int a)
{if (h==NULL)
{h=new node(a);
return;
}
node* pp=h;
while (pp->next!=NULL){
    pp=pp->next;
}
pp->next=new node(a);
return ;
}

void displaylink(node* h){
if (h==NULL)
return;
while(h!=NULL){
    cout<<h->data<<" ";
    h=h->next;
}
return;
}

node* reverselink(node* h){
node* pp=h;
if(pp->next==NULL)
return pp;
pp=h->next;
h->next=NULL;
pp=reverselink(pp);
node* kk;
kk=pp;
while(kk->next!=NULL){
    kk=kk->next;
}
kk->next=h;
return pp;
}
int main(){
    node* head=new node(1);
    addtolink(head,2);
    addtolink(head,3);
    addtolink(head,4);
    addtolink(head,5);
    displaylink(head);
    cout<<endl;
    node* kk=reverselink(head);
    displaylink(kk);
    return 0;
}