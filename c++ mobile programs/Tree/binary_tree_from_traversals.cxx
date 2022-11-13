#include<iostream>
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

node* binarytreefrompreandin(int a[],int b[],int n){
 
 if (n==0)
 return NULL;

 node* root=new node(a[0]);
 
 int i=0,kk;
 while(i<n)
 {if (b[i]==a[0])
 break;
 i++;
 }// give postn of root in inorder form
 
 cout<<endl<<i;
 
 int c[i];  // wil contain left preorder
 int d[i];  //will contain left inorder
 int e[n-i-1];//preorder of right part
 int f[n-i-1]; //inorder of right part
 
 for (kk=0;kk<i;kk++)
 d[kk]=b[kk]; 
  for (kk=0;kk<i;kk++)
 c[kk]=a[kk+1]; // as 0th postn is covered
 root->left=binarytreefrompreandin(c,d,i);

  for (kk=0;kk<n-i-1;kk++)
 f[kk]=b[kk+i+1]; //upto ith is covered
  for (kk=0;kk<n-i-1;kk++)
 e[kk]=a[kk+i+1]; //upto ith is covered
 root->right=binarytreefrompreandin(e,f,n-i-1);
 
 return root;    
}

node* binarytreefrominandpost(int a[],int b[],int n)
{
    if (n==0)
return NULL;

 node* root=new node(b[n-1]);
 
  int i=0,kk;
 while(i<n)
 {if (a[i]==b[n-1])
 break;
 i++;
 }// give postn of root in inorder form
 
    
 int c[i];  //left part inorder
 int d[i]; //left part postorder
 int e[n-i-1]; //right part inorder
 int f[n-i-1]; //right part postorder
 
 for (kk=0;kk<i;kk++)
 c[kk]=a[kk]; 
  for (kk=0;kk<i;kk++)
 d[kk]=b[kk]; 
 root->left=binarytreefrominandpost(c,d,i);
  
    for (kk=0;kk<n-i-1;kk++)
 e[kk]=a[kk+i+1]; //upto ith is covered
  for (kk=0;kk<n-i-1;kk++)
 f[kk]=b[kk+i]; //upto (i-1)th is not covered
 root->right=binarytreefrominandpost(e,f,n-i-1);
 
 return root;        
}

/*
                               1
                      
                   2                       3
                         
             4        5             6          7
                                                 
*/

int main()
{int n=7;
int a[]={1,2,4,5,3,6,7};
int b[]={4,2,5,1,6,3,7};
int c[]={4,5,2,6,7,3,1};
node* root;
//root=binarytreefrompreandin(a,b,n);
root=binarytreefrominandpost(b,c,n);

cout<<endl;
preorderdisplay(root);
cout<<endl;
inorderdisplay(root);
cout<<endl;
postorderdisplay(root);
return 0;
}