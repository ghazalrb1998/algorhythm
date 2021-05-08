#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, m, k, a[maxn];

bool judge(int i){
    int boxes = m-1;
    int rem = k;
    for(int j = i; j < n; j++){
        if(a[j] <= rem)
            rem -= a[j];
        else if(boxes > 0){
            boxes--;
            rem = k - a[j];
        }
        else
            return false;
    }
    return true;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int lo = 0, hi = n-1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << n - lo << endl;
}