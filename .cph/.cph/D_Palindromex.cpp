#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(2*n);
        map<int, vector<int>> mp;

        for(int i = 0; i < 2*n; i++) {
            cin >> arr[i];

            mp[arr[i]].push_back(i);
        }

        int ans = 0;

        for(int i = 0; i < 2*n; i++) {

            if(mp[arr[i]][1] == i) continue;
            
            //cout << i << " ";
            

            int l = mp[arr[i]][0];
            int r = mp[arr[i]][1];
            int limit = r;
            int back = i;

            vector<int> arr2;

            while(i < limit) {

                //cout << "entry" << '\n';

                if(l == r || l > r) {
                    if(l == r) arr2.push_back(arr[l]);

                    sort(arr2.begin(), arr2.end());
                    int curr = 0;

                    for(int i = 0; i < arr2.size(); i++) {
                        //cout << curr << " ";
                        if(curr == arr2[i]) curr++;
                        else break;
                    }

                    ans = max(ans, curr);
                    i = limit;
                    break;
                }

                if(mp[arr[i]][0] != l || mp[arr[i]][1] != r) {
                    //cout << i << " ";
                    i = l - 1;
                    break;
                }
                else arr2.push_back(arr[l]);

                i++;
                l++;
                r--;
            }
        }

        cout << max(ans, 1) << '\n';
    }
    return 0;
}