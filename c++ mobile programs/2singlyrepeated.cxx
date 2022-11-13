#include<iostream>
using namespace std;

int geb(int a,int pos)
{return (a & (1<<pos));
}

int main()
{
    int a,b,su=0,i;
    int n=6;
    int x[6]={1,5,8,4,4,1};
    for (i=0;i<n;i++)
    su=su^x[i];
   
   if (su==0)
  { cout<<"no such";
   return 0;
}
i=0;
    while (su)
  {  if (geb(su,i))
  break;
  i++;
  }
  int kk=i;
  int sumo=0;
   for (i=0;i<n;i++)
  {if (geb(x[i],kk))
  {sumo=sumo^x[i];
  }}
  cout<<endl<<sumo<<endl;
  b=sumo^su;
  cout<<b;
  
   
    return 0;
}