#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
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
void predis(node* head){
	cout<<"hello";
	if (head==NULL)
	return;
	cout<<head->data<<" ";
	predis(head->left);
	predis(head->right);
	cout<<"bye";
	return;
}
node* maketree(vector<int> in,vector<int> pre){
	int n=in.size();
	node* head=new node(pre[0]);
	if (n==1){
		return head;
	}
	int i,j,k;
	vector<int>vlin;
	vector<int>vrin;
	vector<int> vlpre;
	vector<int> vrpre;	
	for (i=0;i<n;i++){
		if (in[i]==pre[0])
		{j=i;
		break;
		}
	}

	for (i=0;i<n;i++){
		if (i<j)
		vlin.push_back(in[i]);
		else if (i>j)
		vrin.push_back(in[i]);
	}
	for (i=1;i<n;i++){
		if (i<=j)
		vlpre.push_back(in[i]);
		else 
		vrpre.push_back(in[i]);
	}
	node* l1=maketree(vlin,vlpre);
	node* re=maketree(vrin,vrpre);
	head->left=l1;
	head->right=re;
	return head;
}
/*
								1
					2					3
				4		5			6		7
			8				9					10




*/
int main(){
	int i,j,k;
	vector<int> in;
	for(i=0;i<10;i++){
		cin>>j;
		in.push_back(j);
	}
	//8 4 2 5 9 1 6 3 7 10 1 2 4 8 5 9 3 6 7 10
	//1 2 4 8 5 9 3 6 7 10
	vector<int> pre;
		for(i=0;i<10;i++){
		cin>>j;
		pre.push_back(j);
	}
	node* head=maketree(in,pre);
	cout<<"required preordered seq will be= ";
	predis(head);
	return 0;
}
