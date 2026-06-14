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

        int count1 = 0;
        int count0 = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '1') count1++;
            else count0++;
        }

        
        if(count0 == 0 || count1 == 0){
            cout << "Bob\n";
            continue;
        }

        
        int first1 = -1, first0_after_1 = -1;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '1' && first1 == -1){
                first1 = i;
            }
            if(first1 != -1 && s[i] == '0'){
                first0_after_1 = i;
                break;
            }
        }

        
        if(first0_after_1 == -1){
            cout << "Bob\n";
        }
        else{
            cout << "Alice\n";
            cout << 2 << '\n';
            cout << first1 + 1 << " " << first0_after_1 + 1 << '\n';
        }
    }
    return 0;
}