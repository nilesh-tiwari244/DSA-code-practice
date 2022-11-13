#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

string dectohex(int a)
{int p=1,k,c;
string hh="";
while (p<a)
{p=p*16;
}
p=p/16;
while(a>0)
{
    c=a/p;
if (c<=9)
{
    hh.push_back((char)(c+48));
}
else
{
 hh.push_back((char)(c+64-9));
}
a=a-(p*c);
p=p/16;
}
return hh;
}


int main()
{int a;
cin>>a;
    cout<<dectohex(a);
}