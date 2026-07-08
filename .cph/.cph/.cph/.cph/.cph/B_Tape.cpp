#include <iostream>
#include <vector>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        long long n,m,k;
        cin >> n >> m >> k;

        priority_queue <pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        long long first;
        cin >> first;

        for(int i = 1; i < n; i++) {
            long long second;
            cin >> second;

            pq.push({second - first + 1, i - 1});
            first = second;
        }

        vector<long long> vis(n, 0);
        long long ans = 0;
        int count = n;

        while(!pq.empty() && count > k) {
            int index = pq.top().second;
            vis[index] = pq.top().first;
            vis[index+1] = pq.top().first;

            if(index > 0 && vis[index - 1] != 0 && index < n - 2 && vis[index + 1] != 0) {
                // ans += (pq.top().first - 2);
                count++;
            }
            else if(index > 0 && vis[index - 1] != 0) {
                ans += (pq.top().first - 1);
            }
            else if(index < n - 2 && vis[index + 1] != 0) {
                ans += (pq.top().first - 1);
            }
            else {
                ans += pq.top().first;
            }

            pq.pop();
            count--;


        }

        int mark = 0;

        for(int i = 0; i < n-1; i++) {
            if(vis[i] != 0) mark++;
        }

        ans += n - 1 - mark;

        cout << ans << '\n';
    return 0;
}   