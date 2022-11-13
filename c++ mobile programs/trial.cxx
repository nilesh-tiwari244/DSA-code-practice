#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{int i;
vector <int> a;
a.push_back(2);
a.push_back(1);
a.push_back(3);
sort(a.begin(),a.end());
do
{cout<<endl;
for (i=0;i<3;i++)
cout<<a[i]<<" ";
}while(next_permutation(a.begin(),a.end()));					
return 0;	
}