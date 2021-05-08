#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int mod = 1000000000 + 7;
int t;
num d;

num fast_power(int b, num p){
    if(!p)
        return 1;
    if(p % 2 == 0){
        num subp = fast_power(b, p / 2);
        return (subp * subp) % mod;
    }
    return (b * fast_power(b, p - 1)) % mod;
}

int main(){
    cin >> t;
    while(t--){
        cin >> d;
        cout << (8 * fast_power(9, d - 1)) % mod << endl;
    }
}