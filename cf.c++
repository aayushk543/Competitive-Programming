#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int k;
        long long x;
        vector<int> ans;

        cin >> k >> x;

        long long c = x;
        long long v = pow(2,k) - x;

        while (c != v){
            if (c < v){
                v /= 2;
                c += v;
                ans.push_back(1);

            }
            else{
                c /= 2;
                v += c;
                ans.push_back(2);
            }
        }
        
        cout << ans.size() << endl;
        for(int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " ";
        }
        cout << endl;
        
    }
    return 0;
}


