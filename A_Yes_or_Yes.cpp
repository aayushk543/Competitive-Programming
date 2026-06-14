#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'Y'){
                count++;
                if(count == 2){
                    cout << "NO" << '\n';
                    break;
                }
            }
            if(i == s.length() - 1){
                cout << "YES" << '\n';
            }
        }
        
    }
    return 0;
}