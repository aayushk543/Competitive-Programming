#include <bits/stdc++.h>
using namespace std;

long long limit;

long long f(vector<int>& size, long long w) {
    long long curr = 0;

    for(int i = 0; i < size.size(); i++) {
        curr += (size[i] + 2LL*w)*(size[i] + 2LL*w);
        if(curr > limit) break;
    }

    return curr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long c;

        cin >> n >> c;
        limit = c;

        vector<int> size(n);

        for(int i = 0; i < n; i++) cin >> size[i];

        long long l = 1, r = 1e9;
        long long mid = 0;

        while(r >= l) {
            mid = (l + r) / 2;

            if(f(size, mid) == c) break;
            else if(f(size, mid) > c) r = mid - 1;
            else l = mid + 1;
        }

        cout << mid << '\n';
    }

    return 0;
}
