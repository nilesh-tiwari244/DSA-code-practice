#include<iostream>
#include<vector>
#include<map>
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

node* maketree(int a[],int n,int ro){ // returns tree having root at index ro of array
    if(ro>=n)
    return NULL;
    node* root=new node(a[ro]);
    node* pp=root;
    int l,r;
    l=2*ro + 1;
    r=2*ro + 2;
    pp->left=maketree(a,n,l);
    pp->right=maketree(a,n,r);
    return root;
}
void printtreevertically(node* root,int ba,map<int,vector<int>> &mp){ //make map of elements at perpendicular distances from root 
//                                                                     root is at zero distance column
    if (root==NULL)
    return;
    mp[ba].push_back(root->data);
    printtreevertically(root->left,ba-1,mp);
    printtreevertically(root->right,ba+1,mp);
    return;
}
int main(){
    int n=9,i;
    vector<int> v;
    int a[]={1,2,3,4,5,6,7,8,9};
    node* root=maketree(a,n,0);
    map<int,vector<int>> mp;
    printtreevertically(root,0,mp);
    map<int,vector<int>>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {cout<<it->first<<" -  ";
    for(i=0;i<(it->second).size();i++)
    cout<<(it->second)[i]<<" ";
    cout<<endl;
    }
    return 0;
}