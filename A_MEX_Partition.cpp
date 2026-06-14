
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

        int m = 0;
        vector<int> ans (104,0);

        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            ans[p]++;
        }

        for(int i = 0; i < 103; i++){
            if (ans[i] == 0){
                cout << i << '\n';
                break;
            }
        }



    }
    return 0;
}