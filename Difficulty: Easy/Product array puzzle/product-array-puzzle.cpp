//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int mul=1, n=arr.size(), mul1=1, count=0;
        for(int i=0; i<n; i++)
        {
            mul = mul*arr[i];
            if(arr[i]!=0)
             mul1 = mul1*arr[i];
            
            if(arr[i]==0)
             count++;
        }
        
        vector<int>res;
        
        for(int i=0; i<n; i++)
        {
            if(arr[i]!=0)
            {
                res.push_back(mul/arr[i]);
            }
            else if(count<=1)
              res.push_back(mul1);
            else 
             res.push_back(0);
        }
        
        return res;
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends