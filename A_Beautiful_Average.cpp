
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
        vector<int> ans;
        int maxi = 0;

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            ans.push_back(m);
            maxi = max(maxi,m);
        }
        cout << maxi << '\n';
    }
    return 0;
}