#include<iostream>
#include<vector>
using namespace std;
void nqueenposs(int n)
{int i,j;
    vector <vector <int>> a(n,vector<int> (n,2));
 //   vector <int> b(n,2);
//    for (i=0;i<n;i++)
  //  a.push_back(b);
for (i=0;i<n;i++)
{for (j=0;j<n;j++)
{cout<<a[i][j]<<" ";
}
cout<<endl;
}


return;
}
int main()
{int n=5;
nqueenposs(n);
return 0;
}