#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, p, a[maxn];

int solve(int st, int en){
    if(st == en)
        return a[st];
    int mid = (st + en) / 2;
    int ans = max(solve(st, mid), solve(mid + 1, en));
    int lsum = 0;
    int max_lsum = INT_MIN;
    int rsum = 0;
    int max_rsum = INT_MIN;
    for(int i = mid; i >= st; i--)
        lsum += a[i], max_lsum = max(max_lsum, lsum);
    for(int i = mid + 1; i <= en; i++)
        rsum += a[i], max_rsum = max(max_rsum, rsum);
    return max(ans, max_lsum + max_rsum);
}

int main(){
    cin >> n >> p;
    for(int i = 0; i < n; i++)
        cin >> a[i], a[i] -= p;
    cout << solve(0, n-1) << endl;
}