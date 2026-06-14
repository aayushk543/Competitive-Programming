#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1,s2;
        cin >> s1 >> s2;
        vector<int>arr (28, -1);

        for(int i = 0; i < n; i++){
            arr[s1[i] - 'a']++;
        }
        for(int i = 0; i < n; i++){
            if (arr[s2[i]-'a'] == -1){
                cout << "NO" << '\n';
                break;
            }
            else if(i == n-1){
                cout << "YES" << '\n';
            }
            arr[s2[i]-'a']--;
        }
    }
    return 0;
}
