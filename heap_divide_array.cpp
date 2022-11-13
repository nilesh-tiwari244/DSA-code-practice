#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int,vector<int>> pma;
priority_queue<int,vector<int>,greater<int>> pmi;

double mediann(){
    if (pma.size()==pmi.size()){
    return (pma.top()+pmi.top())/2.0;
    }
    if (pma.size()>pmi.size()){
    return pma.top();
    }
    return pmi.top();
    }

void insert(int a){

    if (pma.size()==pmi.size()){
     if (pma.size()==0)
    {pma.push(a);
     return;
    }
     else if (pma.top()>a)
    pma.push(a);
     else
    pmi.push(a);
     return;
    }

    if(pma.size()<pmi.size()){
   if(pmi.top()>a){
   pma.push(a);
   return;
    }
    else{
    pmi.push(a);
    pma.push(pmi.top());
    pmi.pop();
    }
   return;
    }
    
    else{
if(pma.top()<a){
   pmi.push(a);
   return;
    }
    else{
    pma.push(a);
    pmi.push(pma.top());
    pma.pop();
    }
   return;
    }
}

int main()
{int i,cc;
cout<<"enter value= ";
for (i=0;i<6;i++){
    cin>>cc;
    insert(cc);
cout<<endl<<"median ="<<mediann()<<" "<<endl;
}
    return 0;
}
