#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 3;

int n, row1[maxn], row2[maxn];
vector<int> a, b;

bool judge(int w){
    a.clear();
    b.clear();
    for(int i = 0; i < n; i++)
        if(row1[i] > w)
            a.push_back(row1[i]);
    for(int i = 0; i < n; i++)
        if(row2[i] > w)
            b.push_back(row2[i]);
    if(a.size() % 2 == 1)
        return false;
    if(b.size() % 2 == 1)
        return false;
    for(int i = 0; i < a.size(); i += 2)
        if(a[i] != a[i + 1])
            return false;
    for(int i = 0; i < b.size(); i += 2)
        if(b[i] != b[i + 1])
            return false;
    return true;
}

int main(){
    cin >> n;
    int max_w = 0;
    for(int i = 0; i < n; i++)
        cin >> row1[i], max_w = max(max_w, row1[i]);
    for(int i = 0; i < n; i++)
        cin >> row2[i], max_w = max(max_w, row2[i]);
    int lo = 0, hi = max_w;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}