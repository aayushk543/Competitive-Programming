
#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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

        vector<long long int> ans;

        for(int i = 0; i < n; i++){
            long long int m;
            cin >> m;
            ans.push_back(m);
        }

        vector<long long int> ans2(n,0);
        ans2[0] = 1;

        int p = 0;


        for (int i = 1; i < n; i++){
            p += ans[i-1];
            if (ans[i] - p == 1 || ans[i] - p == 0){
                ans2[i] = ans2[i-1];
            }
            else if (ans[i] - p == 2){
                ans2[i] = i + 1;
            }
            
        } 
        
        

        for(int i = 0; i < n; i++){
            cout << ans2[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}