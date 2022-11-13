#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int a)
    {data=a;
    next=NULL;
    }
    void display(node* head){
        node* i=head;
        while(i!=NULL)
        {cout<<i->data<<"  ";
        i=i->next;
        }
        return;
    }
    void insert(node* &head,int a);
    node* reverse(node* head);
    void reverseiter(node* &head);
};
void node:: insert(node* &head,int a){
    node* i=head;
    while(i->next!=NULL)
    i=i->next;
    i->next=new node(a);
    return;
}
node* node:: reverse(node* head){//recursive way
    if (head->next==NULL)
        return head;
    node* pp=reverse(head->next);
    node* i=pp;
    while(i->next!=NULL)
    i=i->next;
    head->next=NULL;
    i->next=head;
    return pp;
}
void node:: reverseiter(node* &head){//iterative way
    if ((head==NULL)||(head->next==NULL))
        return;
    node *i,*j,*k,*pp=NULL;
    i=head;
    while(i!=NULL){
        j=i->next;
        k=j->next;
        i->next=pp;
        j->next=i;
        i=k;
        pp=j;
    }
    head= pp;
}
int main(){
    node* head=new node(1);
    head->next=new node(2);
    head->insert(head,3);
    head->insert(head,4);
    head->insert(head,5);
    head->insert(head,6);
    head->display(head);
    cout<<endl;
    head=head->reverse(head);
    head->display(head);
    cout<<endl;
    head->reverseiter(head);
    head->display(head);

    return 0;
}