#include<iostream>
using namespace std;
int main (){
int n,sp,maxi,cm,i;
cout<<"ENTER SIZE OF AARAY=";
cin>>n;

char a[n+1];
cout<<"enter the character array=";
cin.ignore();
cin.getline(a,n);
cin.ignore();

sp=-1;
maxi=0;
cm=0;
i=0;
while(a[i]!='\0')
{if (a[i]==' ')
{cm=i-sp-1;
sp=i;
if (cm>maxi)
maxi=cm;
}
i++;
}
cm=i-sp-1;
if (cm>maxi)
maxi=cm;
cout<<endl;
cout<<"maximum word size= "<<maxi;
return 0;
}