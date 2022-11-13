#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int a)
    {data=a;
    left=NULL;
    right=NULL;
    }
    };

void preorderdisplay(node* root)
{   if (root==NULL)
    return;
        cout<<root->data<<" ";
            preorderdisplay(root->left);
                preorderdisplay(root->right);
                    return;
                    }

void inorderdisplay(node* root)
{ if (root==NULL)
    return;
        inorderdisplay(root->left);
            cout<<root->data<<" ";
                inorderdisplay(root->right);
                    return;
                    }

void postorderdisplay(node* root)
{ 
if (root==NULL)
    return;
        postorderdisplay(root->left);
            postorderdisplay(root->right);
                 cout<<root->data<<" ";
                     return;
                     }

void levelwisedisplay(node* root)
{queue <node*> q;
node* pp;
q.push(root);
q.push(NULL);
while(!q.empty())
{pp=q.front();
q.pop();
if (pp==NULL)
{if(q.empty())
    return;
    }
    else
    {cout<<pp->data<<" ";
    if (pp->left!=NULL)
    q.push(pp->left);
    if (pp->right!=NULL)
    q.push(pp->right);    
    }   
    }    
    return;
    }

vector<int> sumatkthlevel(node* root)
{queue <node*> q;
q.push(root);
q.push(NULL);
vector<int> a;
node* pp;
int s=0;
while(!q.empty())
{pp=q.front();
q.pop();
if (pp==NULL)
{a.push_back(s);
s=0;
    if (q.empty())
        break;   
            else
                q.push(NULL);
                }
                else
                {s+=pp->data;
                if (pp->left!=NULL)
                   {q.push(pp->left);
                      }
                      if (pp->right!=NULL)
                      {q.push(pp->right);    
                      }
                      }   
                      }
                      return a;    
                      }

int totalnodes(node * root)
{if (root==NULL)
return 0;
return (totalnodes(root->left)+totalnodes(root->right)+1);    
}


int sumofall(node* root)
{if (root==NULL)
return -1;
int ss=0;
if (root->left!=NULL)
 ss+= sumofall(root->left);
  if (root->right!=NULL)
   ss+= sumofall(root->right);
   return ss+root->data;
   }

int heightoftree(node* root)
{if (root==NULL)
return 0;
return (max(heightoftree(root->left),heightoftree(root->right))+1);    
}


int diameteroftree(node* root)
{if (root==NULL)
return 0;
int sr,sl,st;
sr=diameteroftree(root->right);
sl=diameteroftree(root->left);
st=(heightoftree(root->left)+heightoftree(root->right)+1);    
return max(sr,max(sl,st));
}


int diameterefficient(node* root,int* ht)
{// gives both height and dia in O(n)
    if (root==NULL)
    return 0;
    int sl,sr,st;
    int hl=0,hr=0;
    sl=diameterefficient(root->left,& hl);
    sr=diameterefficient(root->right,&hr);
    st=hl+hr+1;
    *ht=max(hl,hr)+1;
    return max(sl,max(sr,st));    
    }

node* sumreplacement(node* k)
{if (k==NULL)
return NULL;
if ((k->left==NULL)&&(k->right==NULL))
{
return k;
}
else if ((k->left!=NULL)&&(k->right==NULL))
{k->left=sumreplacement(k->left);
k->data=k->data+k->left->data;
}
else if ((k->left==NULL)&&(k->right!=NULL))
{
k->right=sumreplacement(k->right);
k->data=k->data+k->right->data;
}
else
{k->left=sumreplacement(k->left);
k->right=sumreplacement(k->right);
k->data=k->data+k->right->data+k->left->data;    
}
return k;    
}


int checkbalanced(node* root,int* h) 
{if (root==NULL)
return 1;
int lh=0,lr=0;
if (checkbalanced(root->left,&lh)==0)
return 0;
if (checkbalanced(root->right,&lr)==0)
return 0;
*h=max(lr,lh)+1;
if(abs(lr-lh)<=1) //condition for nodes should satisfy fo balamced tree
return 1;
else
return 0;    
}

void rightviewoftree(node* root)
{// different way of accesing levels
queue <node*> q;
q.push(root);
node* pp;
int i,n;
while(!q.empty())
{
n=q.size();
for (i=1;i<=n;i++)
{pp=q.front();
if (i==n)
cout<<pp->data<<" ";
if (pp->left!=NULL)
q.push(pp->left);
if (pp->right!=NULL)
q.push(pp->right);
q.pop();
}
}
return;    
}


void leftviewoftree(node* root)
{queue <node*> q;
q.push(root);
q.push(NULL);
node* pp;
cout<<root->data<<" ";
while(!q.empty())
{pp=q.front();
if (pp==NULL)
{q.pop();
if (q.empty())
break;
else
{cout<<q.front()->data<<" ";
q.push(NULL);
}
}
else
{if (pp->left!=NULL)
q.push(pp->left);
if (pp->right!=NULL)
q.push(pp->right);
q.pop();
}    
}
return;    
}

vector<int> position(node* root,int a)
{vector<int> v,b;
int i;

if (root==NULL)
return v;

if (root->data==a)
{v.push_back(a);
    return v;
    }
b=position(root->left,a);
if (b.size()==0)
{   b=position(root->right,a);
    if (b.size()==0)
        return v;
    else
        {  b.push_back(root->data);
        return b;
        }
}
else
    {b.push_back(root->data);
    return b;
    }
}

int leastancestor(node* root,int a,int b)
{vector<int> c,d;
c=position(root,a);
d=position(root,b);
int k1,k2;
k1=c.size()-1;
k2=d.size()-1;
if ((k1<0)||(k2<0))
return -1;

while ((c[k1]==d[k2])&&(k1>=0)&&(k2>=0))
{k1--;
k2--;  
}
if (c[k1+1]==d[k2+1])
return c[k1+1];
else
return -1;
}


node* leastancopti(node* root,int a,int b)
{//without using position fuction
if (root==NULL)
return NULL;

if ((root->data==a)||(root->data==b))
return root;

node* lc=leastancopti(root->left,a,b);
node* rc=leastancopti(root->right,a,b);
if ((lc!=NULL)&&(rc!=NULL))
return root;
else if ((lc==NULL)&&(rc==NULL))
return NULL;
else if (lc==NULL)
return rc;
else
return lc;
}


int distance(node* root,int a,int b)
{node* c=leastancopti(root,a,b);
vector<int> d,e;
d=position(c,a);
e=position(c,b);
return (d.size()+e.size()-2);
}


void displaylinked(node* head)
{while (head!=NULL)
{cout<<head->data<<" ";
head=head->right;
}
return;
}

node* converttolinked(node* root)
{if (root==NULL)
return NULL;
node* pl;
node* pr;
node* kk;
pl=root->left;
pr=root->right;
root->left=NULL;
pl=converttolinked(pl);
pr=converttolinked(pr);
if (pl!=NULL)
{kk=pl;
while (kk->right!=NULL)
kk=kk->right;
kk->right=pr;
root->right=pl;
}
else 
root->right=pr;
return root;
}


void printatdistancek(node* root,int n,int k) //using distance function not optimum
{if (root==NULL)
return;
if (k==0)
{cout<<n<<" ";
return;
}
queue <node*> q;
node* pp;
q.push(root);
while(!q.empty())
{pp=q.front();
q.pop();
if(distance(root,pp->data,n)==k)
cout<<pp->data<<" ";
    if (pp->left!=NULL)
        q.push(pp->left);
            if (pp->right!=NULL)
                q.push(pp->right);    
                } 
                    return;
                    }
void printsubtree(node* root,int k)
{if (root==NULL)
return;
if (k==0)
{cout<<root->data<<" ";
return;}
if (k<0)
return;
printsubtree(root->left,k-1);
printsubtree(root->right,k-1);
return;
}

vector<node*> pathofnodes(node* root,node* n) //similar to position but return vector of nodes instead of values
{vector<node*> v,kl,kr;
if (root==NULL)
return v;
if (root==n)
{v.push_back(n);
return v;}
kl=pathofnodes(root->left,n);
kr=pathofnodes(root->right,n);
if (kl.size()==0 && kr.size()==0)
return v;
if (kl.size()>0)
{kl.push_back(root);
return kl;}
kr.push_back(root);
return kr;
}

void printallatdistancek(node* root,node* n,int k) 
{printsubtree(n,k);
vector<node*> pp=pathofnodes(root,n);
int i=1,leng=pp.size()-1;
while((k-i>=0)&&(leng>=i))
{if (k-i==0)
{cout<<pp[i]->data<<" ";
return;}
if (pp[i]->left==pp[i-1])
{printsubtree(pp[i]->right,k-i-1);
}
else 
{printsubtree(pp[i]->left,k-i-1);
}
i++;
}
return;
}
/*
                                   1
                 2                                 3
       4                  5            6                       7
                    8                            9
*/
int main()
{int i;
node* root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);
root->right->left=new node(6);
root->right->right=new node(7);
root->left->right->left=new node(8);
root->right->left->right=new node(9);
cout<<endl<<"preorder= ";
preorderdisplay(root);
cout<<endl<<"inorder= ";
inorderdisplay(root);
cout<<endl<<"postorder= ";
postorderdisplay(root);
cout<<endl<<"levelwise= ";
levelwisedisplay(root);
cout<<endl;
vector<int> a=sumatkthlevel(root);
cout<<endl;
cout<<"sum in each levels= ";
for(i=0;i<a.size();i++)
cout<<a[i]<<" ";
cout<<endl;
cout<<"total number of nodes= "<<totalnodes(root);
cout<<endl<<"sum of all nodes= "<<sumofall(root);
cout<<endl<<"height of tree O(n)= "<<heightoftree(root);
cout<<endl<<"diameter of tree O(n^2)= "<<diameteroftree(root);
int ht=0;
cout<<endl<<"diameter of tree O(n)= "<<diameterefficient(root,&ht);
cout<<endl<<"height using diameter functiion= "<<ht;
//cout<<endl;
//node* root1=sumreplacement(root);
//cout<<"Levelwise after sum replacement=";
//levelwisedisplay(root1);
cout<<endl<<endl;
int h=0;
cout<<"balanced= "<<checkbalanced(root,&h);
cout<<endl;
cout<<"right view of tree= ";
rightviewoftree(root);
cout<<endl;
cout<<"left view of tree= ";
leftviewoftree(root);
cout<<endl<<endl;

vector<int> c=position(root,9);
cout<<"Position of 9= ";
for (h=0;h<c.size();h++)
cout<<c[h]<<" ";
cout<<endl<<endl;

cout<<"Least ancestor of 2 & 7 = "<<leastancestor(root,5,7);
cout<<endl;
cout<<"least ancestor 2 & 7 OPTIMUM= "<<leastancopti(root,2,7)->data;
cout<<endl;
cout<<endl<<"leastdistance betwn 5 & 9 =";h=distance(root,5,9);
cout<<h;

//node* head=converttolinked(root);
//cout<<endl<<"converted linkedlist= ";
//displaylinked(head);

cout<<endl;
cout<<"nodes at distance k= ";
printatdistancek(root,5,1);
cout<<endl;
cout<<"nodes at distance k OPTIMUM= ";
printallatdistancek(root,root->left->right,1);
cout<<endl<<endl;
return 0;
}