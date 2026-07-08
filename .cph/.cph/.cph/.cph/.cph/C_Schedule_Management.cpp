#include <iostream>
#include <vector>
#include <climits>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& tasks, int limit) {
    long long help = 0, pending = 0;

    for(int i = 1; i < tasks.size(); i++) {
        if(limit > tasks[i]) help += (limit - tasks[i])/2;
        else pending += (tasks[i] - limit);
    }

    return pending <= help;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        vector<int> tasks(n + 1, 0);

        for(int i = 0; i < m; i++) {
            int a;
            cin >> a;

            tasks[a]++;
        }

        int l = 0, r = 2*m;

        while(l < r) {
            int mid = (l + r) / 2;

            if(check(tasks,mid)) r = mid;
            else l = mid + 1;

        }

        cout << r << '\n';
    }
    return 0;
}   