#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 3;
int m, n, t, dp[maxn];

int main(){
    while(cin >> m >> n >> t){
        for(int i = 0; i <= t; i++){
            if(i == 0)
                dp[i] = 0;
            else{
                dp[i] = -1;
                if(i >= n && dp[i - n] != -1)
                    dp[i] = dp[i - n] + 1;
                if(i >= m && dp[i - m] != -1)
                    dp[i] = max(dp[i], dp[i - m] + 1);
            }
        }
        int k = 0;
        while(dp[t - k] == -1)
            k++;
        cout << dp[t - k];
        if(k)
            cout << " " << k;
        cout << endl;
    }
}