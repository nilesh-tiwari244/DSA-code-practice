#include<iostream>
#include<string>
using namespace std;
int main()
{int p,i=0;
char ch;
string a;
getline(cin,a);
while(a[i]!='\0')
{p=int(a[i]);
if (p>=97)
    p-=32;
ch=(char)p;
a[i]=ch;
i++;
}
cout<<endl;
cout<<a; 
return 0;	
}