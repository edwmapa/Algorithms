#include <bits/stdc++.h>
#define ll long long
#define pdd pair<double,double>
#define eps 1e-9
#define MAX 10010 
using namespace std;

int A[MAX][MAX],B[MAX][MAX]; // A - ones, B - twos
int ans[MAX][MAX];

void init(int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            A[i][j]=1;
            B[i][j]=2;
            ans[i][j]=0;
        }
    }
}

void showM(int M[][MAX],int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<M[i][j]<< ' ';
        }
        cout<<'\n';
    }
}


void product(int n){
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<n ; j++)
            for(int k = 0 ; k<n ; k++)
                ans[i][j] = ans[i][j] + (A[i][k] * B[k][j]);
}
pdd prodTime(int n){
    double add=0,product=0;
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<n ; j++)
            for(int k = 0 ; k<n ; k++){
                auto start = chrono::system_clock::now();
                int pd = (A[i][k] * B[k][j]);
                auto end = chrono::system_clock::now();
                product += (chrono::duration<double>(end - start)).count();
                start = chrono::system_clock::now();
                ans[i][j] = ans[i][j] + pd;
                end = chrono::system_clock::now();
                add += (chrono::duration<double>(end - start)).count();
            }
    return pdd(add,product);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout
    int n;
    cout<<"Testing function - insert a value 0 <= n < 10010: ";
    cin>>n;
    init(n);
    cout<<"A:\n";showM(A,n);
    cout<<"B:\n";showM(B,n);
    auto start = chrono::system_clock::now();
    product(n);
    auto end = chrono::system_clock::now();   
    
    cout<<"ans: \n";showM(ans,n);
    cout<<"time elapsed > "<<(chrono::duration<double>(end - start)).count()<<" seconds.\n";
    
    cout<<"---- C++ time performance analysis - each 10 steps----\n";
    cout<<" n \t avg(10) \t add_avg(10) \t prod_avg(10) \n";
    for (int i = 0 ; i <= 200;i+=10){
        init(i);//reset values of matrices
        double avg = 0, add_avg=0,prod_avg = 0;
        for(int j = 0;j<10;j++){
            start = chrono::system_clock::now();
            pdd ot = prodTime(i);
            end = chrono::system_clock::now();
            avg += (chrono::duration<double>(end - start)).count();
            add_avg += ot.first;
            prod_avg += ot.second;
        }
        avg/=10.0;
        add_avg/=10.0;
        prod_avg/=10.0;
        cout<<i<<'\t'<<avg<<'\t'<<add_avg<<'\t'<<prod_avg<<'\n';
    }
}
