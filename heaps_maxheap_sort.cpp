#include<iostream>
#include<vector>
using namespace std;

void swap(int & a,int & b){
    int temp;
    temp=a;
    a=b;
    b=temp;
    return;
}

void heapify(vector<int> &a,int st,int en){ //using max heap
    int i,l,al,r,ar,maxi=st;
    l=st*2 + 1;
    r=st*2 + 2;
    if ((l<en) && (a[l]>a[st]))
    maxi=l;
    if ((r<en) && (a[r]>a[maxi]))
    maxi=r;
    if (maxi!=st){
        swap(a[maxi],a[st]);
        cout<<a[maxi]<<" "<<a[st]<<endl;
        heapify(a,maxi,en);
    }
}

void heapsort(vector<int> &a){
    //a={1,3,6,9,5,8,10,13,15};
    int i;
    int n=a.size();
    for (i=n/2 -1;i>=0;i--){
        heapify(a,i,a.size());
    }  
    for (i=a.size()-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
    return;
}

/*
void heapify(vector<int> &a,int st,int en){ //using min heap
    int i,l,al,r,ar,maxi=st;
    l=st*2 + 1;
    r=st*2 + 2;
    if ((l<en) && (a[l]<a[st]))
    maxi=l;
    if ((r<en) && (a[r]<a[maxi]))
    maxi=r;
    if (maxi!=st){
        swap(a[maxi],a[st]);
        //cout<<a[maxi]<<" "<<a[st]<<endl;
        heapify(a,maxi,en);
    }
}

void heapsort(vector<int> &a){
    //a={1,3,6,9,5,8,10,13,15};
    int i;
    int n=a.size();
    for (i=n/2 -1;i>=0;i--){
        heapify(a,i,a.size());
    }  
    
    for (i=n-1;i>=0;i--){
        cout<<a[0]<<" ";
        a[0]=INT_MAX;
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
    
    return;
}
*/

int main(){
    int i;
    vector<int> a={1,3,6,9,5,8,13,10,15};
    /*    
              1
        3           6   
    9      5     8     10
13    15

    */
    heapsort(a);
    for(i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
