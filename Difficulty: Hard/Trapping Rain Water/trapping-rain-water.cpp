//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>leftToright(n,0);
        vector<int>rightToleft(n,0);
        int max_val=INT_MIN;
        for(int i=0;i<n;i++){
            max_val=max(max_val,arr[i]);
            leftToright[i]=max_val;
        }
        max_val=INT_MIN;
        for(int i=n-1;i>=0;i--){
            max_val=max(max_val,arr[i]);
            rightToleft[i]=max_val;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(leftToright[i],rightToleft[i]))-arr[i];
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
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends