#include<iostream>
#include<vector>
using namespace std;

vector<int> poss(vector<int> a,int d,int k){
  //return k elements with minm distn between any pair >=d
  //return empty vector if  not possible
      vector<int> v;
    int n=a.size();
    
     if (k>n){
        return v;
    }  
    
    if (k==1){
        v.push_back(a[0]);
        return v;
    }
    
    if (k==2){
        if ((a[n-1]-a[0])>=d){
            v.push_back(a[0]);
            v.push_back(a[n-1]);
            return v;
        }
        else
            return v;
    }
    int lo,hi;
    lo=a[0]+d;
    hi=a[n-1]-d;
    int i;
    vector<int> b,c;
    for (i=1;i<n-1;i++){
        if((a[i]>=lo)&&(a[i]<=hi)){
            b.push_back(a[i]);
        }
    }
    c=poss(b,d,k-2);
    if (c.size()>0){
        v.push_back(a[0]);
        i=0;
        while(i<c.size()){
            v.push_back(c[i]);
            i++;
        }
        v.push_back(a[n-1]);
        return v;
    }
    return v;   
} //easy way of checking could have been  in in O(n) where keep a flag which if reach k then d possible
//pos=a[0] and if a[i]-pos>=d then pos=a[i] and flag++  for i>0 to n-1

int maxdist(vector<int> a,int k){
    int n=a.size();
    int ansi=0;
    
    if (k>n)
    return 0;
    
    sort(a.begin(),a.end());
    
    int lo=0,hi=(a[n-1]-a[0])/(k-1);
    int ch=hi;
    
    vector<int> dd;
     dd=poss(a,ch,k);
        if (dd.size()>0){
            return ch;
        }
        hi=ch;
        ch=(hi+lo)/2;
    while ((ch!=hi)&&(lo!=ch)){
         dd=poss(a,ch,k);
        if (dd.size()>0){
            lo=ch;
            ansi=ch;
        }
        else{
            hi=ch;
        }
        ch=(hi+lo)/2;    
    }
    return ansi;
}

int main(){
    int k=13;
    int d=5;
    vector<int> a={1,18,3,4,14,21,27,83,54,33,45,82,66,55,44,33,2,3};
    sort(a.begin(),a.end());
  //  vector<int> ans=poss(a,d,k);
   int pp=maxdist(a,k);
    cout<<pp;
    cout<<endl;
/*    int i;
    for (i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
*/   
    return 0;
}