#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, k, a[maxn], b[maxn];

void merge_sort(int st, int en){
    if(st == en)
        return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid + 1, en);
    int lptr = st;
    int rptr = mid + 1;
    int ptr = st;
    while(lptr <= mid || rptr <= en){
        if(lptr == mid + 1)
            b[ptr++] = a[rptr++];
        else if(rptr == en + 1)
            b[ptr++] = a[lptr++];
        else if(a[lptr] <= a[rptr])
            b[ptr++] = a[lptr++];
        else
            b[ptr++] = a[rptr++];
    }
    for(int i = st; i <= en; i++)
        a[i] = b[i];
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    // merge_sort(0, n-1);
    sort(a, a + n);
    int m = 0;
    int ptr = 0;
    while(k--){
        while(ptr < n && a[ptr] - m == 0)
            ptr++;
        if(ptr == n)
            cout << 0 << endl;
        else{
            cout << a[ptr] - m << endl;
            m += a[ptr] - m;
        }
    }
}