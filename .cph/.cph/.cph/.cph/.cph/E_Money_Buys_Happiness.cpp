#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> memo;

long long f(vector<vector<long long>>& h, int index, long long curr, long long x) {
    int m = h.size();
    if(index == m) return memo[curr][index] = 0;

    if(memo[curr][index] != -1) return memo[curr][index];

    if(h[index][0] <= curr) return memo[curr][index] = max(h[index][1] + f(h, index + 1, curr + x - h[index][0], x), f(h, index + 1, curr + x, x));

    return memo[curr][index] = f(h, index + 1, curr + x, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        
        long long m,x;

       cin >> m >> x;

       vector<vector<long long>> h(m);

       long long sum = 0;

       for(int i = 0; i < m; i++) {
        long long m1, m2;
        cin >> m1 >> m2;

        sum += m1;

        h[i] = {m1, m2};
       }

       memo.assign(sum + 1, vector<long long>(m + 1, -1));

       cout << f(h, 0, 0, x) << '\n';
    }
    return 0;
}   