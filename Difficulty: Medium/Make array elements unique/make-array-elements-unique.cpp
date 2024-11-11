//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map<int,int> mp;
        int maxi=arr[0];
        mp[arr[0]]=1;
        int ans=0;
        for(int i=1;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                ans += maxi+1-arr[i];
                maxi++;
                mp[maxi]=1;
            }
            else{
                mp[arr[i]]=1;
                maxi=arr[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends