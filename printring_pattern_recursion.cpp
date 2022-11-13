#include<bits/stdc++.h>
using namespace std;
void pattern(int n)
{if (n==1)
{cout<<n<<" "<<endl;
return;
}
int i;
for (i=1;i<n+1;i++)
cout<<i<<" ";
cout<<endl;
pattern(n-1);

return;


}

int main()
{int i;
cout<<"enter the no. of rows=";
cin>>i;
pattern(i);
    return 0;
}