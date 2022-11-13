#include<bits/stdc++.h>

using namespace std;

int repeatedNumber(const vector<int> &A) 
{int count1,count2,num1,num2,size;
   size = A.size();
   count1=count2=0;
   num1=num2=-1;


   for(int i=0;i<size;i++){
    if(A[i]==num1)count1++;
    else if(A[i]==num2)count2++;
    else if(count1==0){count1=1; num1 = A[i];}
    else if(count2==0){count2=1; num2 = A[i];}
    else{count1--; count2--;}
   }

   count1=count2=0;
   for(int i=0;i<size;i++){
       if(A[i]==num1)count1++;
       if(A[i]==num2)count2++;
   }

   if(count1>size/3)return num1;
   if(count2>size/3)return num2;

   return -1;



/*vector<int> b(n);
for (i=0;i<n;i++)
b[i]=A[i];
sort(b.begin(),b.end());
for (i=0;i<n;i++)
{for(j=0;j<k2;j++)
{if(b[i]!=b[i+j])
break;
}
if (j==k2)
return b[i];
}

return -1;
}
*/
/*
vector<int> b(INT_MAX,0);
for (i=0;i<n;i++)
b[A[i]]+=1;
for (i=0;i<INT_MAX;i++)
{if (b[i]>=k2)
{return i;
}
}
return -1;
*/
}

int main()
{int o;
vector<int> a{1,2,2,1,7,7,7,2};
o=repeatedNumber(a);
cout<<endl;
cout<<"required output is= "<<o<<endl;
return 0;




}