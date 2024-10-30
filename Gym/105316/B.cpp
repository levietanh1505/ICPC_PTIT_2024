#include<bits/stdc++.h>
using namespace std;
map<long long, long long> mp;
map<long long,vector<map<long long, long long>>> v;
map<pair<map<long long, long long>, long long>, long long> true_mp;
set<vector<long long>> ms[34];
map<long long, long long> check;
long long arr[10][34][10];
vector<long long> vv(10);
void kt(){
    for(long long i=1;i<=9;i++){
        arr[i][0][i]=1;
        for(long long j=1;j<=33;j++){
            arr[i][j][1]=arr[i][j-1][4]+arr[i][j-1][5]+arr[i][j-1][6]+arr[i][j-1][7];
            arr[i][j][2]=arr[i][j-1][7]+arr[i][j-1][4]+arr[i][j-1][8]+arr[i][j-1][9];
            arr[i][j][3]=arr[i][j-1][1];
            arr[i][j][4]=arr[i][j-1][8];
            arr[i][j][5]=arr[i][j-1][5];
            arr[i][j][6]=arr[i][j-1][2];
            arr[i][j][7]=arr[i][j-1][9];
            arr[i][j][8]=arr[i][j-1][6];
            arr[i][j][9]=arr[i][j-1][3];
        }
    }
}
long long ceck(map<long long, long long> mp1){
    long long cnt=0;
    long long ans=0;
    for(long long i=1;i<=9;i++){
        if(mp1[i]>check[i]+1) return 0;
        else if(mp1[i]<check[i]) return 0;
        else if(mp1[i]==check[i]+1){
            cnt++;
            ans=i;
            if(cnt==2) return 0;
        }
    }
    if(cnt==0) return 0;
    return ans;
}
int main(){

    kt();
    v.clear();
    for(long long x=1;x<10;x++){
        for(long long y=x;y<10;y++){
            for(long long z=y;z<10;z++){
                for(long long k=1;k<=33;k++) {
                    mp.clear();

                    for(long long i=1;i<10;i++){
                        mp[i]=arr[x][k][i]+arr[y][k][i]+arr[z][k][i];
                        vv[i]=mp[i];
                    }

          //     true_mp[{mp,k}]=1;
          ms[k].insert(vv);
                }
            }
        }
    }
    int t; cin>>t;
    while (t--) {
        mp.clear();
       long long n,m; cin>>n>>m;
       check.clear();
       for(long long i=1;i<=m;i++){
           long long x; cin>>x;
           check[x]++;
       }
       for(long long i=1;i<=9;i++){
          check[i]++;
     vector<long long> vvv(10);
     for(long long i=1;i<=9;i++) vvv[i]=check[i];
          if(ms[n].find(vvv)!=ms[n].end()){
              cout<<i<<endl;
              break;
          }
          check[i]--;
       }
    }
}
/*
2
2 7
1 8 1 5 6 2 1
2 7
1 8 1 5 6 2 1
 0 3 1 1 0 1 1 0 1 0
 */