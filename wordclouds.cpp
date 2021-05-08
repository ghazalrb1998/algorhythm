#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 3;
int n, W, w[maxn], h[maxn], dp[maxn];

int cdp(int i){
    if(dp[i] != -1)
        return dp[i];
    if(i == n)
        return dp[i] = 0;
    int sum_w = 0, max_h = 0, ans = INT_MAX;
    for(int j = i; j < n; j++){
        sum_w += w[j];
        if(sum_w <= W){
            max_h = max(max_h, h[j]);
            ans = min(ans, cdp(j + 1) + max_h);
        }
        else
            break;
    }
    return dp[i] = ans;
}

int main(){
    cin >> n >> W;
    for(int i = 0; i < n; i++)
        cin >> w[i] >> h[i];
    for(int i = 0; i <= n; i++)
        dp[i] = -1;
    cout << cdp(0) << endl;
}