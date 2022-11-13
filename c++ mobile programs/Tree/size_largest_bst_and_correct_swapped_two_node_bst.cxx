#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int a){
        data=a;
        left=NULL;
        right=NULL;
    }
};
class info{
    public:
    int size;
    int ans;
    int min;
    int max;
    bool isbst;
    info(){
        size=0;
        ans=0;
        min=INT_MAX;
        max=INT_MIN;
        isbst=false;
    }
    info(int s,int a,int mi,int ma,bool is){
        size=s;
        ans=a;
        min=mi;
        max=ma;
        isbst=is;
    }
};
info largestbst(node* root){
    if (root==NULL){
          info anw=info(0,0,INT_MAX,INT_MIN,true);
        return anw;
    }
    if (root->left==NULL  &&  root->right==NULL){
          info anw=info(1,1,root->data,root->data,true);
        return anw;
    }
    info leff=largestbst(root->left);
    info rigg=largestbst(root->right);
    
    if (leff.isbst   &&   rigg.isbst  &&  root->data>leff.max  &&root->data<rigg.min){
       info anw= info(leff.size+rigg.size+1,leff.ans+rigg.ans+1,leff.min,rigg.max,true);return anw;
    }
      info anw=info(leff.size+rigg.size+1,max(leff.ans,rigg.ans),INT_MAX,INT_MAX,false);
    return anw;    
}
vector<node*> inlineway(node* root){
    vector<node*> v;
    vector<node*> ll;
    vector<node*> rr;
    
    if (root==NULL)
    return v;
    int i;
    ll=inlineway(root->left);
    ll.push_back(root);
    rr=inlineway(root->right);
    for(i=0;i<rr.size();i++)
    ll.push_back(rr[i]);
    return ll;
}

node* swapnodes(node* root,node* a,node* b)  
{int pp;
pp=a->data;
a->data=b->data;
b->data=pp;
  return root;
}

node* correcttwoswapped(node* root){
    node* kk;
    int i;
    if (root==NULL)
        return root;
    if ((root->left==NULL) &&  (root->right==NULL))
    return root;
    vector<node*> v;
    v=inlineway(root);
    int n=v.size();
    node *ro1=NULL;
    node *ro2=NULL;
    for (i=0;i<n-1;i++)
    {if (ro1==NULL)
    {if (v[i]->data>v[i+1]->data)
        {ro1=v[i];
       }
    }
        else
        {if (ro1->data<v[i+1]->data)
        {ro2=v[i];
        break;
        }
        }
    }
    if ((i==n-1)&&(ro1!=NULL))
    ro2=v[n-1];
    if (ro1==NULL)
    return root;
    root=swapnodes(root,ro1,ro2);    
    return root;  
}

int main(){
    node* root=new node(10);
    root->left=new node(2);
    root->right=new node(15);
    root->left->left=new node(8);
    root->left->right=new node(9);
    //largest bst size
    info ret=largestbst(root);
    cout<<"size of largest bst= "<<ret.ans;
    cout<<endl;
    int i;
    vector<node*> kkk;
    cout<<endl;
    kkk=inlineway(root);
    cout<<"before correction= ";
   for (i=0;i<kkk.size();i++)
   cout<<(kkk[i])->data<<" ";
   cout<<endl;
   //correct two swapped node data in bst
    root=correcttwoswapped(root);
    kkk=inlineway(root);
    cout<<"after correction= ";
   for (i=0;i<kkk.size();i++)
   cout<<kkk[i]->data<<" ";
   cout<<endl;
    return 0;
};
    
    