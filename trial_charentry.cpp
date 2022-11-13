#include<iostream>
#include<vector>
using namespace std;
int main(){
	char ch;
	int i;
	vector<char> v;
	for (i=0;i<7;i++){
		cin>>ch;
		v[i]=ch;
	}
	cout<<"data entry complete";
	for (i=0;i<7;i++){
		cout<<v[i]<<" ";
	}	
	return 0;
}
