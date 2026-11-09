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

    
    if (1){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int l = s.length();

        bool flag = false;


        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(s[i] == '1') q.push(i);
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr > 0 && s[curr-1] == '1') {
                flag = true;
                break;
            }
            if(curr < n - 1 && s[curr+1] == '1') {
                flag = true;
                break;
            }
        }

        if(flag == false) {
            if(n >= 2 && ((s[0] == '0' && s[1] == '0') || (s[n-1] == '0' && s[n-2] == '0'))) {
                flag = true;
            }
            else {
                int curr = 0;
                for(int i = 0; i < n; i++) {

                    if(s[i] == '1') {
                        if(curr >= 3) {
                            flag = true;
                            break;
                        }
                        curr = 0;
                    }
                    else curr++;
                }
            }

        }

        if(flag || (l == 1 && s[0] == '0')) {
            cout << "No" << '\n';
        }
        else cout << "Yes" << '\n';
    }
    
    return 0;
}