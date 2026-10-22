#include <bits/stdc++.h>
using namespace std;

long long num9(vector<int>& n) {
    
    long long curr = 0;
    
    long long cycle = 1;
    
    for(int i = 0; i < n.size(); i++) {
        curr += cycle * n[i];
        cycle *= 10;
    }
    
    return curr;
}

long long f1(long long n, int d) {

    //cout << "hi" << '\n';
    
    long long curr = n;
    bool flag = false;
    
    vector<int> num;
    vector<int> vis;
    
    while(curr > 0) {
        int ld = curr % 10;
        
        if(ld == 9) {
            
            num.push_back(0);
            vis.push_back(0);
            
            flag = true;
        }
        else if(ld == 8) {

            if(flag) {
                num.push_back(0);
                vis.push_back(0);
            }
            else {
                num.push_back(8);
                vis.push_back(1);

                flag = false;
            }
        }
        else {
            if(flag) {
                num.push_back(ld+1);
                vis.push_back(1);
            }
            else {
                num.push_back(ld);
                vis.push_back(0);
            }

            flag = false;
        }
        
        curr /= 10;
    }

    //for(int i = 0; i < num.size(); i++) cout << num[i] << " ";
    
    if(flag == true) {

        num.push_back(1);

        for(int i = num.size() - 1; i >= 0; i--) {
            if(num[i] > 0) {

                i--;
                while(i >= 0) num[i--] = 0;
            }
        }
    }
    else {

        for(int i = num.size() - 1; i >= 0; i--) {
            if(num[i] != 9 && vis[i] == 1) {
                i--;
                while(i >= 0) num[i--] = 0;
            }
        }
    }
    //std::reverse(num.begin(), num.end());
    
    return num9(num);
}

long long f2(long long n, int d) {
    
    long long curr = n;
    bool flag = false;
    
    vector<int> num;
    
    while(curr > 0) {
        int ld = curr % 10;
        
        num.push_back(ld);
        
        curr /= 10;
    }
    
    for(int i = num.size() - 1; i >= 0; i--) {
        
        if(num[i] == d) {
            
            num[i] = d + 1;
            i--;

            if(d == 0) while(i >= 0) num[i--] = 1;
            else {
                while(i >= 0) num[i--] = 0; 
            }
        }
        //else if(num[i] == d && d == 0) num[i] = 1;
    }
    //std::reverse(num.begin(), num.end());
    
    return num9(num);
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    long long n;
	    int d;

        cin >> n >> d;
	    
	    if(d == 9) cout << f1(n, d) << '\n';
	    else cout << f2(n, d) << '\n';
	}
}
