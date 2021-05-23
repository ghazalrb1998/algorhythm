#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;
int n, m, t[maxn], l[maxn];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    for(int j = 0; j < m; j++)
        cin >> l[j];
    sort(t, t + n);
    sort(l, l + m);
    int itr = 0;
    for(int i = 0; i < m; i++){
        if(t[itr] <= l[i])
            itr++;
        if(itr == n)
            break;
    }
    cout << itr << endl;
}