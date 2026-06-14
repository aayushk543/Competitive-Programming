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
        bool c1 = false;
        bool c2 = false;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'u'){
                c1 = true;
                break;
            } 
            else if(i == s.length() - 1){
                count = 0;
            }
        }
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 's'){
                c2 = true;
                break;
            }
            else if(i == s.length()-1){
                count = s.length()/2 + 1;
            }
        }
        if(c1 && c2){
            int i = 0;
            while (i < s.length()){
                if(s[i] == 'u' && (i == 0 || i == s.length()-1)){
                    if(i == 0) s[i] = 's';
                    count++;
                }
                else if(s[i] == 'u'){
                    if(s[i-1] == 'u') count++;
                    if(s[i+1] == 'u') {
                        s[i+1] = 's';
                        count++;
                    }
                    i = i+1;
                }
                i = i + 1;
            }
        }
        cout << count << '\n';
        
    }
    return 0;
}