#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<long long> pq;

    for(int i = 0; i < n; i++) {
        long long m;
        cin >> m;
        pq.push(abs(arr[i] - m));
    }

    bool flag = true;

    for(int i = 1; i <= k1 + k2; i++) {
        long long top = pq.top();

        top -= 1;

        if(top < 0) top *= -1;

        pq.pop();
        pq.push(top);
    }

    long long sum = 0;

    while(!pq.empty()) {
        long long curr = pq.top();
        pq.pop();

        sum += curr * curr;
    }

    cout << sum << '\n';

    return 0;
}