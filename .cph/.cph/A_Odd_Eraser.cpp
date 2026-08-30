#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if(a > b) return gcd(b, a);

    if(a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;

       cin >> n;
       vector<long long> arr(n);

       for(int i = 0; i < n; i++) cin >> arr[i];

       cout << gcd(arr[0], arr[n - 1]) << '\n';


    }
    return 0;
}