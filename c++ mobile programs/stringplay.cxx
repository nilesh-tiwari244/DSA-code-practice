#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{string k="ab xd ghfs";
string :: iterator it;
it=k.begin();
/*string s="herobanega";
k=s.find("ban");
sort(s.begin(),s.end());
cout<<s;
cout<<endl;
//cout<<s.begin();
*/
/*
k=(char)49;
cout<<k;
cout<<endl;
int p= int(k);
cout<<p;
*/
//transform(it,k.end(),it+3,::toupper);
sort(it,k.end(),greater<int>());
cout<<k;

	return 0;
	
}