#include<bits/stdc++.h>
using namespace std;

int f(vector<int> arr, int i, int k){
    int n = arr.size();
    int ans = 0;
    int c = 0;
    while(c < k){
            ans += floor(arr[i+c]/arr[n-k+c]);
            arr[i+c] = 0;
            arr[n-k+c] = 0;
            c++;
        }
        for(int i = 0; i < n; i++){
            ans += arr[i];
        }
        return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        vector<int> a(n,0);
        vector<int> b(n,0);
        vector<int> c(2*n + 2, 0);
        vector<int> d(2*n, 0);

        for(int i = 0; i < n; i++){
            cin >> a[i];
            c[a[i]]++;
            d[i] = a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            c[b[i]]++;
            d[n + i] = b[i];
        }

        sort(d.begin(), d.end());

        



    }
    return 0;
}