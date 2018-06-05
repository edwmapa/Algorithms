#include<bits/stdc++.h>
#define llong long long
#define INF 1e9
using namespace std;

int N,D;
llong d[55][55];

llong floyd(){
    llong ans = -INF;
    for(int k = 0 ; k < N;k++)
        for(int i = 0 ; i < N; i++)
            for(int j = 0 ; j< N; j++)
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    for(int i = 0 ; i < N; i++)
        for(int j = 0 ; j< N; j++)
            ans = max(ans,d[i][j]);
    return (ans==INF)?-1:ans;
}


int main(){
    cin>>N>>D;
    string str;
    for(int i = 0 ; i<N;i++){
        cin>>str;
        for(int j = 0 ; j <N; j++){
            d[i][j] = (str[j]=='Y')?D:INF;
        }
    }
    cout<<floyd();
}
