#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode (int a)
		{left=NULL;
		right=NULL;
		val=a;
		}	
};
 vector<TreeNode*> position(TreeNode* a,int x){
     vector<TreeNode*> v;
     if (a==NULL)
     return v;
     if (a->val==x){
         v.push_back(a);
         return v;
     }
     vector<TreeNode*> kv;
     kv=position(a->left,x);
     if (kv.size()!=0){
        kv.push_back(a); 
     }
     else {
        kv=position(a->right,x);
        if (kv.size()!=0)
            kv.push_back(a);
            else
            kv.clear();
     }
    return kv;
 }
 int height(TreeNode* A){
     if (A==NULL){
         return 0;
     }
     int lh,rh;
     lh=height(A->left);
     rh=height(A->right);
     return (max(lh,rh)+1);
 }
int solve(TreeNode* A, int B) {
    vector<TreeNode*> v;
    v=position(A,B);
    int n=v.size();
    int i,h,s=0,g=B;
    for (i=1;i<n;i++){
        if (v[i]->left->val==g)
            h=height(v[i]->right);
        else
            h=height(v[i]->left);
        h=h+i;
        s=max(s,h);
        g=v[i]->val;
    }
    return s;
}
int main()
{TreeNode* head=new TreeNode(1);
head->left=new TreeNode(2);
head->right =new TreeNode(3);
head->left->left=new TreeNode(4);
head->right->left=new TreeNode(5);
head->right->right=new TreeNode(6);
cout<<solve(head,4);
return 0;	
}
