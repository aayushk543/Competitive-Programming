
#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        

        vector<int> ans (104,0);

        for (int i = 0; i < n; i++){
            int m;
            cin >> m;
            ans[m]++;
        }

        int count = 0;

        for(int i = 0; i < 101; i++){
            if(ans[i] != 0){
                count++;
            }
        }

        cout << 2*count - 1 << '\n';

    }
    return 0;
}