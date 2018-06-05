#include<bits/stdc++.h>
#define llong long long

using namespace std;

int c[100];
llong dp[300];
llong coinChange(int n,int m){//m coins
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i = 0 ; i <m;i++){
        for(int j = 1;j<=n;j++){
            dp[j] += (j-c[i]>=0)?dp[j-c[i]]:0;
            //cout<<dp[j]<<' ';
        }
        //cout<<endl;
    }
    return dp[n];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>c[i];
    }
    sort(c,c+m);
    llong ans = coinChange(n,m);
    cout<<ans;
}
