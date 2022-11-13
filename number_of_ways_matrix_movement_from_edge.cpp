#include<bits/stdc++.h>
using namespace std;

int waystogo(int a1,int b1,int a2,int b2) //trust your function
{if ((a1==a2) && ((b2-b1)==1))
return 1;
if ((b1==b2) && ((a2-a1)==1))
return 1;
if ((a1>a2) || (b1>b2))
return 0;

   int s=waystogo(a1,b1+1,a2,b2)+waystogo(a1+1,b1,a2,b2);
   return s;
}

int main()
{int i1,k1,k2,i2,k;
cout<<"enter the initial position coordinates=";
cin>>i1>>k1;
cout<<"enter the final position coordinates=";
cin>>i2>>k2;
k=waystogo(i1,k1,i2,k2);
cout<<endl<<"numbers of ways for doing so are= "<<k;
    return 0;
}