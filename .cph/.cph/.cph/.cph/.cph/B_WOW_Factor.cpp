#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; 
    cin >> s;

    vector<int> o;
    int count = 0;
    long long t_count = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'o') {
            o.push_back(max(0, count - 1));
            t_count += o[o.size() - 1];
            count = 0;
        }
        else count++;
    }

    t_count += max(0, count - 1);
    long long ans = 0;
    long long prefix = 0;
    long long prev = 0;

    for(int i = 0; i < o.size(); i++) {
        if(o[i] == 0) {
            ans += prev;
            continue;
        } 
        prefix += o[i];
        t_count -= o[i];

        prev = prefix*t_count;

        ans += prev;
    }

    cout << ans << '\n';

    return 0;
}