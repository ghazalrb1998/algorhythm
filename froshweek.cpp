#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e6 + 3;
int n, a[maxn], b[maxn];

num inversion_indx(int st, int en){
    if(st == en)
        return 0;
    int mid = (st + en) / 2;
    num ans = inversion_indx(st, mid) + inversion_indx(mid + 1, en);
    int lptr = st, rptr = mid + 1, ptr = st;
    while(lptr <= mid || rptr <= en){
        if(lptr == mid + 1)
            b[ptr++] = a[rptr++];
        else if(rptr == en + 1)
            b[ptr++] = a[lptr++];
        else if(a[lptr] > a[rptr])
            ans += mid - lptr + 1, b[ptr++] = a[rptr++];
        else 
            b[ptr++] = a[lptr++];
    }
    for(int i = st; i <= en; i++)
        a[i] = b[i];
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << inversion_indx(0, n - 1) << endl;
}