#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    
	    vector<int> arr(n + 1);
	    
	    for(int i = 1; i <= n; i++) cin >> arr[i];
	    
	    vector<int> same;
        int ans = 1;

        vector<vector<int>> arr2;

        for(int i = 1; i <= n; i++) {
            int l = 1;
            int j = i;

            while(i < n && arr[i] == arr[i+1]) {
                l++;
                i++;
            }

            if(l >= 0) {
                arr2.push_back({arr[i], l, j});
                //cout << (arr[i]) << " " << l << " " << j << '\n'; 
            }
        }

        int total = 0;

        for(int i = 1; i < n; i++) {
            if(arr[i] == arr[i+1]) total++;
        }

        bool flag2 = false;
        bool flag3 = false;

        int count = 0;

        set<pair<int, int>> s;

        for(int i = 0; i < arr2.size(); i++) {

            
            if(i + 3 < arr2.size() && arr2[i][0] == arr2[i+1][0] + 1 && arr2[i+2][0] + 1 == arr2[i+3][0]) {
                total += 2;
                flag3 = true;
                break;
            }
            else if(i + 2 < arr2.size() && arr2[i][0] == arr2[i+2][0] && arr2[i][1] + arr2[i][2] == arr2[i+1][2] && arr2[i+1][1] + arr2[i+1][2] == arr2[i+2][2] && (arr2[i][0] - arr2[i+1][0] == 1))  {
                //cout << arr2[i+2][2] + arr2[i+2][1] - arr2[i][2] << " " << "stage1" << '\n';
                total += 2;
                flag3 = true;
                break;
            }
            else if(i + 4 < arr2.size() && arr2[i][0] == arr2[i+1][0] + 1 && arr2[i+3][0] + 1 == arr2[i+4][0]) {
                total += 2;
                flag3 = true;
                break;
            }
            if(i + 1 < arr2.size() && abs(arr2[i+1][0] - arr2[i][0]) == 1) {
                s.insert({min(arr2[i+1][0], arr2[i][0]), max(arr2[i+1][0], arr2[i][0])});
                count++;
                flag2 = true;
            
            }
            ans = max(ans, arr2[i][1]);

            //cout << ans << '\n';
        }
	    































































































        
        if(n == 1) cout << 0 << '\n';
	    else if(flag3) cout << total << '\n';
        else if(count != s.size()) cout << total + 2 << '\n';
        else if(flag2) cout << total + 1 << '\n';
        else cout << total << '\n';
	}

}
