#include<bits/stdc++.h>
#define llong long long

using namespace std;

llong dp[50];
llong t1,t2;

llong fibonacciModified(llong n) {
    if(dp[n]!=-1)return dp[n];
    if(n == 1)return t1;
    if(n == 2)return t2;

    llong a = dp[n-1] = fibonacciModified(n-1);
    llong b = dp[n-2] = fibonacciModified(n-2);

    return dp[n] = a*a + b;
}


int main(){
    llong n;
    for(int i = 0 ; i <50;i++)dp[i] = -1;
    cin>>t1>>t2>>n;
    cout<<fibonacciModified(n);
}
