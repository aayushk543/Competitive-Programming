#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin >> t;
	
	while(t--) {
	    long long x,y,n;
	    cin >> x >> y >> n;
	    
	    long long ans = 0;
	    
	    vector<pair<long long, long long>> vec;
	    
	    for(long long i = 0; i <= n; i++) {
	        vec.push_back({i ^ x, (i ^ y) + 1});

            cout << (i^x) << '\n';
            cout << (i^y + 1) << '\n';
	    }
	    
	    sort(vec.begin(), vec.end());
	    long long prev = 0;
	    
	    for(int i = 0; i < vec.size(); i++) {
	        
	        ans += vec[i].second;
	        
	        ans += max(0LL, prev - vec[i].first);
	        
	        prev = (vec[i].first + vec[i].second);
	    }
	    
	    cout << ans << '\n';
	}
}
