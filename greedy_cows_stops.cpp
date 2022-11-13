#include<iostream>
#include<vector>
#include <queue>
#include<map>
using namespace std;
int main(){
    int n=4,cc=0;
    int p=10,l=22;
    int o[4]={6,6,4,4};
    int d[4]={10,14,18,21};
    priority_queue<int,vector<int>> pp;
    int le;
    pp.push(o[0]);
    le=p-d[0];
    if(le<0)
    {
        cout<<"not possible 11";
        return 0;
    }
    int i=1;
    while (i!=n+1){

        if(i<n)
        {
        le=le-d[i]+d[i-1];
        }
        else
        le=le-l+d[i-1];

        if (le<0){
            while(le<0){
                if(pp.empty())
                {cout<<"not possible"<<i;
                return 0;
                }
            le=le+pp.top();
            cc++;
            cout<<"stops at= "<<pp.top()<<endl;
            pp.pop();
            }
        }if(i<n)
        pp.push(o[i]);
        i++; 
    }
    cout<<"answer is= "<<cc;
    return 0;  
    }