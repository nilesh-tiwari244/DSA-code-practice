#include<iostream>
using namespace std;
int nthcatalan(int a)
{if ((a==0)||(a==1))
    return 1;
    if(a<0)
    return 0;
    int s=0,i=0;
    while(i<a)
    {s+=nthcatalan(i)*nthcatalan(a-1-i);
    i++;
    }
    return s;
}

int main()
{int k;
cin>>k;
cout<<nthcatalan(k);
return 0;
}