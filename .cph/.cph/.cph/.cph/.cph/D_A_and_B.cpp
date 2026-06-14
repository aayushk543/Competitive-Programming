#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int count = 0;

        int a = 0, b = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a'){
                a++;
            }
            else b++;
        }

        if(s.length() <= 2){
            cout << 0 << '\n';
        }
        else {
            for(int i = 0; i < s.length(); i++){
                
            }
        }
    }
    return 0;
}