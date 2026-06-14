
#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            sum += s[i] - '0';
            if (s[i] - '0' == 2){
                count++;
            }
        }

        if (sum % 3 == 1 && count != 0){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}