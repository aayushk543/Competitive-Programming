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

        int count = 0;
        bool e = false;
        

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') count++;
            else count--;

            if(count < 0){
                e = true;
                break;
            }
            
        }

        if(!e){
            cout << -1 << '\n';
        }
        else {

        }
    }
    return 0;
}