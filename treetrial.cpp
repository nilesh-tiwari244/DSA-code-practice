#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class node{
	public:
		node* left;
		node* right;
		int data;
		node(int a){
			left=NULL;
			right=NULL;
			data=a;
		}
};

void preorder(node* head){
	if (head==NULL)
	return;
	preorder(head->left);
	cout<<head->data<<" ";
	preorder(head->right);
	return;
}

void lvlwise(node* head){
	node* pp;
	queue<node*> qt;
	qt.push(head);
	qt.push(NULL);
	while (!qt.empty()){
		pp=qt.front();
		qt.pop();
		if (pp==NULL){
			if (qt.empty())
			return ;
			qt.push(NULL);
		}
		else{
			cout<<pp->data<<" ";
			if (pp->left!=NULL)
			qt.push (pp->left);
			if (pp->right!=NULL)
			qt.push (pp->right);			
		}
	}
	return;
}

int diameter(node* head,int &h){
	if (head==NULL)
	{h=0;
	return 0;
	}
	int k1,k2,hl=0,hr=0;
	k1=diameter(head->left,hl);
	k2=diameter(head->right,hr);
	h=max(hl,hr)+1;
	return (max(k1,max(k2,hl+hr+1)));
}

int checkbalanced(node* head,int &h){
	if (head==NULL){
		h=0;
		return 1;
	}
	int k1,k2,hl=0,hr=0;
	k1=checkbalanced(head->left,hl);
	k2=checkbalanced(head->right,hr);
	h=max(hl,hr)+1;
	if (abs(hl-hr)>1)
	return 0;
	if (k1==0 || k2==0)
	return 0;
	return 1;
}

void rightview(node* head){
	node* pp;
	queue<node*> qt;
	qt.push(head);
	int n,i;
	while (!qt.empty()){
		n=qt.size();
		for (i=0;i<n;i++){
			pp=qt.front();
			qt.pop();
			if(i==n-1)
			cout<<pp->data<<" ";
			if (pp->left!=NULL)
			qt.push (pp->left);
			if (pp->right!=NULL)
			qt.push (pp->right);			
		}	
	}
	return;
}
vector<node*> position(node* head,int a){
	vector<node*> v;
	if (head==NULL)
	return v;
	if (head->data==a)
	{v.push_back(head);
	return v;
	}
	v=position(head->left,a);
	if (v.size()!=0)
	{v.push_back(head);
	return v;
	}
	v=position(head->right,a);
	if (v.size()!=0)
	{v.push_back(head);
	return v;
	}
	return v;
}
node* leastancestor(node* head,int a,int b){
	if (head==NULL)
	return NULL;
	if (head->data==a || head->data==b)
	return head;
	node* lc;
	node* rc;
	lc=leastancestor(head->left,a,b);
	rc=leastancestor(head->right,a,b);
	if (lc==NULL && rc==NULL)
	return NULL;
	if (lc==NULL)
	return rc;
	if (rc==NULL)
	return lc;
	return head;
}
void printdistn_k_subtrees(node* ro,int k){
	if (ro==NULL)
	return;
	if (k==0){
		cout<<ro->data<<" ";
		return;
	}
	if (k<0)
	return;
	printdistn_k_subtrees(ro->left,k-1);
	printdistn_k_subtrees(ro->right,k-1);
	return;
}
void printatdistancek(node* head,node* ro,int k){
	printdistn_k_subtrees(ro,k);
	vector<node*> posi=position(head,ro->data);
	int n=posi.size();
	int i=1;
	while(i<n && i<=k){
		if(posi[i]->left==posi[i-1]){
			printdistn_k_subtrees(posi[i]->right,k-i-1);
		}
		else{
			printdistn_k_subtrees(posi[i]->left,k-i-1);
		}
		if (i==k)
		cout<<posi[i]->data<<" ";
		i++;	
	}
	return;
	}
/*
							1
				2						3
		4				5		6				7
			8						9

*/
int main(){
	node* head=new node(1);
	head->left=new node(2);
	head->right=new node(3);
	head->left->left=new node(4);
	head->left->right=new node(5);
	head->right->left=new node(6);
	head->right->right=new node(7);
	head->left->left->right=new node(8);
	head->right->left->right=new node(9);	
	cout<<"levelwise= ";
	lvlwise(head);
	cout<<endl;
	cout<<"preorder= ";
	preorder(head);
	cout<<endl;
	int hh=0;
	cout<<"diameter= "<<diameter(head,hh);
	cout<<endl<<"height= "<<hh;
	cout<<endl;
	int kp=0;
	cout<<"height balanced or not= "<<checkbalanced(head,kp);
	cout<<endl<<"right view of tree= ";
	rightview(head);
	vector<node*> vv=position(head,8);
	int i;
	cout<<endl<<"position of 8= ";
	for (i=0;i<vv.size();i++)
	cout<<vv[i]->data<<" ";
	cout<<endl;
	node *leastance=leastancestor(head,5,8);
	cout<<"least ancestor of 5 and 8 = "<<leastance->data;
	cout<<endl<<"nodes at distance 2 of node 2= ";
	printatdistancek(head,head->right,1);
	return 0;
}
