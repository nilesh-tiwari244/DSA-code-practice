#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool check(vector<vector<int> > &A,int xma,int xmi,int yma,int ymi,int xs,int ys, int B,int n) {
    cout<<"check = "<<n<<endl;
    int i,j,co;
    bool kkk;
     for (i=0;i<A.size();i++){// 2 3   9 4   10 3
         co=0;
         for (j=0;j<A.size();j++){
             if ((abs(A[i][0]-A[j][0])+abs(A[i][1]-A[j][1]))<=n){
                 co++;
                 if (co>=B){
                     cout<<"true"<<endl;
                    return true;
                 }
             }
         }
     }
     cout<<"false"<<endl;
   return false;
}
/*
bool fill(map<vector<int>,int> &ma,int x,int y,int xmi,int ymi,int xs,int ys,int n,int B){
int ux,uy;
x=x-xmi;
y=y-ymi;

int uys=y-n;
int uye=y+n;

if (uye>=ys)
uye=ys-1;
if (uys<0)
uys=0;

int p,suu,enn;
for(uy=uys;uy<=uye;uy++){
p=abs(n-abs(uy-y));
enn=x+p;
suu=x-p;
if(suu<0)
suu=0;
if(enn>=xs)
enn=xs-1;
for (ux=suu;ux<=enn;ux++){
    ma[{uy,ux}]+=1;
        if(ma[{uy,ux}]>=B)
            return true;
}
}
return false;
}

bool check(vector<vector<int> > &A,int xma,int xmi,int yma,int ymi,int xs,int ys, int B,int n) {

    int i,j;
    bool kkk;
    //vector<vector<int>> ma(ys,vector<int> (xs,0));
    map<vector<int>,int> ma;
     for (i=0;i<A.size();i++){
      kkk=fill(ma,A[i][0],A[i][1],xmi,ymi,xs,ys,n,B);
       if (kkk)
     return true;
     }
          if (kkk)
     return true;
   return false;
}
*/
/*
bool fill(vector<vector<int>> &ma,int x,int y,int xmi,int ymi,int xs,int ys,int n,int B){
int ux,uy;
x=x-xmi;
y=y-ymi;

int uys=y-n;
int uye=y+n;

if (uye>=ys)
uye=ys-1;
if (uys<0)
uys=0;

int p,suu,enn;
for(uy=uys;uy<=uye;uy++){
p=abs(n-abs(uy-y));
enn=x+p;
suu=x-p;
if(suu<0)
suu=0;
if(enn>=xs)
enn=xs-1;
for (ux=suu;ux<=enn;ux++){
    ma[uy][ux]+=1;
        if(ma[uy][ux]>=B)
            return true;
}
}
return false;
}

bool check(vector<vector<int> > &A,int xma,int xmi,int yma,int ymi,int xs,int ys, int B,int n) {

    int i,j;
    bool kkk;
    vector<vector<int>> ma(ys,vector<int> (xs,0));
     for (i=0;i<A.size();i++){
      kkk=fill(ma,A[i][0],A[i][1],xmi,ymi,xs,ys,n,B);
       if (kkk)
     return true;
     }
          if (kkk)
     return true;
   return false;
}
*/
int solve(vector<vector<int> > &A,int B) {
   int n=A.size();
    int xma,xmi,yma,ymi,xs,ys,i,j;
    xma=A[0][0];
    yma=A[0][1];
    xmi=xma;
    ymi=yma;
    for (i=0;i<n;i++)
    {xmi=min(A[i][0],xmi);
    xma=max(A[i][0],xma);
    ymi=min(A[i][1],ymi);
    yma=max(A[i][1],yma);
    }
    xs=xma-xmi+1;
    ys=yma-ymi+1;
    int st,en,midd;
    st=0;
    en=xs+ys;
    while(st<=en){
        cout<<"st and en = "<<st<<"  "<<en<<endl;
        if (check(A,xma,xmi,yma,ymi,xs,ys,B,st)){
            return st;
        }
        midd=(st+en)/2;
        if (check(A,xma,xmi,yma,ymi,xs,ys,B,midd))
            {
            en=midd;
            }
        else{ 
        st=midd+1;
        }
    }
    return -1;
}

int main(){
   /*
    vector<vector<int> > A={{8,5},{0,4},{3,6}};
    int B=3;
*/
    
    vector<vector<int> > A={{2,3},{9,4},{10,3}};
    int B=2;
    
    cout<<solve(A,B);
    return 0;
}
