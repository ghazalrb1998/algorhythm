#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = (1 << 17) + 3;
int n, a[maxn];

num solve(int st, int en){
    if(st == en)
        return a[st];
    int mid = (st + en) / 2;
    num subleft = solve(st, mid);
    int maxright = *max_element(a + mid + 1, a + en + 1);
    num subright = solve(mid + 1, en);
    int maxleft = *max_element(a + st, a + mid + 1);
    return max(subleft + maxright, subright + maxleft); 
}

int main(){
    cin >> n;
    n = (1 << n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << solve(0, n - 1) << endl;
}