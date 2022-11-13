#include<bits/stdc++.h>
using namespace std;
int waystogo(int b,int a) //trust your function
{int i;
if (b<=a)
return 0;
int s=0;
for (i=1;i<=6;i++)
{if (b==(a+i))
    s++;
else if (b>(a+i))
    s+=(waystogo(b,a+i));
}
return s;
}

int main()
{int i,k;
cout<<"enter the final position=";
cin>>i;
k=waystogo(i,0);
cout<<endl<<"numbers of ways for doing so are= "<<k;
    return 0;
}