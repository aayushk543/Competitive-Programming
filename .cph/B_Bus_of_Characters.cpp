#include<bits/stdc++.h>
using namespace std;

int size(vector<vector<int>>& adj, int index, vector<int>& sz) {
    int curr = 1;
    sz[index] = -2;

    //cout << index << '\n';

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(sz[node] == -1) curr += size(adj, node, sz);
    }

    //cout << index << " " << curr << '\n';
    sz[index] = curr;
    return curr;
}

int check(vector<vector<int>>& adj, int index, vector<int>& sz, int parent) {
    int score = 0;

    for(int i = 0; i < adj[index].size(); i++) {
        int node = adj[index][i];

        if(node == parent) continue;

        if(sz[node] == 0) score += 1 + check(adj, node, sz, index);
        else score += check(adj, node, sz, index);
    }

    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;
    cin >> n;

    vector<int> w(n);

    for(int i = 0; i < n; i++) cin >> w[i];

    string s;
    cin >> s;

    priority_queue<pair<int,int>> pq1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;

    for(int i = 0; i < n; i++) {
        pq2.push({w[i], i + 1});
    }

    for(int i = 0; i < 2*n; i++) {

        if(s[i] == '0') {
            auto [w, index] = pq2.top();
            pq2.pop();
            cout << index << " ";

            pq1.push({w, index});
        }
        else if(s[i] == '1') {
            auto [w, index] = pq1.top();
            pq1.pop();

            cout << index << " ";
        }
    }

    cout << '\n';
    
    return 0;
}