#include <bits/stdc++.h>
using namespace std;

#define num long long int

num dp[65 + 3][65 + 3][2 + 3];

num cdp(int i, int j, int l){
    if(dp[i][j][l] != -1)
        return dp[i][j][l];
    if(i < j)
        return dp[i][j][l] = 0;
    if(i == 0)
        return dp[i][j][l] = (j == 0);
    if(l){
        if(j == 0)
            return dp[i][j][l] = cdp(i-1, j, 0);
        return dp[i][j][l] = cdp(i-1, j-1, 1) + cdp(i-1, j, 0);
    }
    return dp[i][j][l] = cdp(i-1, j, 1) + cdp(i-1, j, 0);
}

int main(){
    for(int i = 0; i < 65 + 3; i++)
        for(int j = 0; j < 65 + 3; j++)
            for(int l = 0; l < 2 + 3; l++)
                dp[i][j][l] = -1;
    while(1){
        int n, s;
        cin >> n >> s;
        if(n + s < 0)
            break;
        cout << cdp(n, s, 1) << endl;
    }
}