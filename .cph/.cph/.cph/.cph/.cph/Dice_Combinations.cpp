#include<bits/stdc++.h>
using namespace std;

vector<long long> memo;

long long f(long long n) {
    if(n == 0) return 1;
    else if(n < 0) return 0;

    if(memo[n] != -1) return memo[n];

    long long ans = 0;

    for(int i = 1; i <= 6; i++) {
        ans = (ans + f(n - i)) % 1000000007;
    }

    return memo[n] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    memo.assign(n + 1, -1);

    cout << f(n) % 1000000007 << '\n';

    return 0;
}