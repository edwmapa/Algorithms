#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename Type>
Type fibo(Type n){
	Type a=0,b=1,temp;
	for(Type i = 0 ;i<n;i++){
		temp = b;//temp swap
		b = a+b;
		a = temp;
	}
	return a;
}
template<typename Type>
bool overflow(Type n){
	return n<0;
}

int main(){
	ll n;
	cout<<"Fibo tester, input number > ";
	cin>>n;
	cout<<"fibo("<<n<<") = "<<fibo(n)<<'\n';
	cout<<"-----Testing Basic Overflows------\n";
	
	for(short i = 0 ; i<=SHRT_MAX;i++){
		if(overflow(fibo(i))){
			cout<<"> short overflows at: "<<i<<'\n';
			break;
		}
	}
	for(int i = 0 ; i<=INT_MAX;i++){
		if(overflow(fibo(i))){
			cout<<"> int overflows at: "<<i<<'\n';
			break;
		}
	}
	for(ll i = 0 ; i<=LLONG_MAX;i++){
		if(overflow(fibo(i))){
			cout<<"> long long overflows at: "<<i<<'\n';
			break;
		}
	}
	
	cout<<"-----Testing Unsigned Overflows------\n";
	unsigned short last=0;
	for(unsigned short i = 0 ; i<=USHRT_MAX;i++){
		unsigned short cur = fibo(i);
		if(cur<last){
			cout<<"> unsigned short overflows at: "<<i<<'\n';
			break;
		}
		last = cur;
	}
	unsigned int last1=0;
	for(unsigned int i = 0 ; i<=UINT_MAX;i++){
		unsigned int cur = fibo(i);
		if(cur<last1){
			cout<<"> unsigned int overflows at: "<<i<<'\n';
			break;
		}
		last1 = cur;
	}
	unsigned ll last2=0;
	for(unsigned ll i = 0 ; i<=ULLONG_MAX;i++){
		unsigned ll cur = fibo(i);
		if(cur<last2){
			cout<<"> unsigned short overflows at: "<<i<<'\n';
			break;
		}
		last2 = cur;
	}
	
}
