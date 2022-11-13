#include<iostream>
#include<vector>
#include<string>
using namespace std;
int seats(string A) {
    int c=0,i,j,k,n=A.size();

    for(i=0;i<n;i++){
        if (A[i]=='x')
            c++;
    }

    int zz,cou;
    vector<vector<int>> b;
    i=0;
    while(i<n){
         if (A[i]=='x'){
             zz=i;
             cou=0;
             while((A[i]=='x')&&(i<n)){
                cou++;
                i++;
             }
             b.push_back({cou,zz});
         }
         else
         i++;
    }
    cout<<n<<"  "<<c<<"  "<<b.size()<<endl;
    cou=0;
    int ans=0;
    int pc=0,pi=0;
    if (b.size()==1)
    return 0;
    i=0;
        cou+=b[i][0];

        // if (cou<(c-cou)){//0 1  2 2
            if (cou<=b[i+1][0]){
           ans+= abs((b[i][0] * (b[i+1][1]-b[i][1]-b[i][0])));
           pc=b[i][0] +b[i+1][0];
           pi=b[i][1]+(b[i+1][1]-b[i][1]-b[i][0]);
        }
        else{
            ans+= abs((b[i+1][0] * (b[i+1][1]-b[i][1]-b[i][0])));
            pc=b[i][0] +b[i+1][0];
            pi=b[i][1];
        }
    if (b.size()==2)
    return ans;
    cout<<endl<<"after 2 index= "<<pc<<"  "<<pi<<endl;
    i=2;
    
   while(pc<(c-pc)){
            ans+= abs((pc * (b[i][1]-pi-pc)));
           pc+=b[i][0];
           pi=b[i][1]+(b[i][1]-pi-pc);
           i++;
          // if (pc+b[i][0]>(c-pc-b[i][0]))
    }
cout<<"after c/2 == "<<pc<<" "<<pi<<endl;

    while(i<b.size()){
        ans+= abs((b[i][0] * (b[i][1]-pi-pc)));
            pc+=b[i][0];
            i++;
    }

/*
while(i<b.size()){
    if (pc<b[i][0]){
        ans+= abs((pc * (b[i][1]-pi-pc)));
           pc+=b[i][0];
           pi=b[i][1]+(b[i][1]-pi-pc);
           i++;
    }
    else{
        ans+= abs((b[i][0] * (b[i][1]-pi-pc)));
            pc+=b[i][0];
            i++;

    }
}
*/
return ans;
}
int main(){
string st="xx.....xx.x..xxxx..xxxx.xx..xx..x.xxxx"; //0 1  2 2
int p=seats(st);
cout<<endl<<"ans=  "<<p;
}

//  ....x..xx...x..


