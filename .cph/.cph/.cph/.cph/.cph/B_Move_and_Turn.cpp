#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long k = n / 2;

    if(n % 2) cout << 2LL*(k + 1LL)*(k + 2LL) << '\n';
    else cout << (k + 1LL)*(k + 1LL) << '\n';  

}