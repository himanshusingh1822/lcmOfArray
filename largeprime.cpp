#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

vector<int> getprime(int n){
    vector<bool> isprime(n,true);
    for(int i=2;i<n;i++){
        if(isprime[i]){
            for(int j=i;j*i<n;j++){
                isprime[i*j]=false;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(isprime[i]){
            prime.push_back(i);
        }
    }
    return prime;

}

int main(){
    int l,r;
    cin >> l >> r;
    int n=1e6+1;
    getprime(n);
    vector<bool> range(r-l+1,true);
    for(int i=0;i<prime.size();i++){
        int k = ceil((1.0*l)/prime[i]);
        for(int j=max(k,2);j*prime[i]<=r;j++){
            range[prime[i]*j-l]=false;
        }
    }
    for(int i=0;i<r-l+1;i++){
        if(range[i])
        cout << l+i << " ";
    }
    return 0;
}