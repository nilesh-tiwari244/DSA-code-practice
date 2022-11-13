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

void preorderdisp(node* hh){
    if (hh==NULL){
        return;
    }
    cout<<hh->data<<" ";
    preorderdisp(hh->left);
    preorderdisp(hh->right);
    return;
}

vector<node*> possiblebst(int st,int en){
    vector<node*> pos,lh,rh;
    if(st>en){
        pos.push_back(NULL);
        return pos;
    }
    node *root;
    int ii,i,j,k;
    for (i=st;i<=en;i++){
        lh=possiblebst(st,i-1);
        rh=possiblebst(i+1,en);
        for (j=0;j<lh.size();j++){
            for(k=0;k<rh.size();k++){
                root=new node(i);
                root->left=lh[j];
                root->right=rh[k];
                pos.push_back(root);
            }
        }   
    }
    return pos;
}

int main(){
    vector<node*> kk=possiblebst(1,3);
    int i;
    for (i=0;i<kk.size();i++){
        preorderdisp(kk[i]);
        cout<<endl;
    }
    return 0;
}
        
        
        