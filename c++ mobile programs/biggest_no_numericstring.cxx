#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{int i=0,m=1,su=0,k;
string a;
getline(cin,a);
sort(a.begin(),a.end());
while(a[i]!='\0')
{k=int(a[i]);
k-=48;
su=su+ (k*m);
m=m*10;
i++;
}
cout<<su;	
	return 0;
	
	
}