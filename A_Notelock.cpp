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
        int n,k;
        cin >> n >> k;

        

        string str;
        cin >> str;
        vector<int> s;
        for (int i = 0; i < n; i++){
            s.push_back(str[i]-'0');
        }
    

        int count = 0;

        if(s[0] == 1){
            count++;
        }
        

        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == 1){
                bool p = false;
                count ++;
                int c = max(0,i-k+1);
                int j = max(0,i-1);
                while (j >= c){
                    if(s[j] == 1){  
                        p = true;
                        break;                 
                    }
                    j--;
                }
                if(p){
                    count--;
                }
                
            }
        }

        cout << count << '\n';
    }
    return 0;
}
