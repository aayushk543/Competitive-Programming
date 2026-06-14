#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n;
        cin >> s;

        int o = 0;
        int e = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') o++;
            else e++;
        }

        int total = 0;
        int i = s.length() - 1;
        vector<int> ans;

        for(int i = 0; i < s.length(); i++){
            if(i <= o-1 && s[i] == '1'){
                ans.push_back(i+1);
            }
            else if(i > o-1 && s[i] == '0'){
                ans.push_back(i+1);
            }
        }

        if(ans.size() == 0){
            cout << "Bob" << '\n';
        }
        else {
            cout << "Alice" << '\n';
            cout << ans.size() << '\n';

            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}