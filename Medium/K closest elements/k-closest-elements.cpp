//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  static bool cmp (pair<int,int>a,pair<int,int>b){
      if(a.first==b.first)
          return a.second>b.second;
      return a.first<b.first;      
  }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
             v.push_back({abs(arr[i]-x),arr[i]});
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            if(v[i].second==x)
             continue;
             ans.push_back(v[i].second);
        }
        if(ans.size()<k){
            ans.push_back(v[k].second);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends