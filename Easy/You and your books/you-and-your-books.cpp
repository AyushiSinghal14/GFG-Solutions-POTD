//{ Driver Code Starts
#include <algorithm>
#include <cstdio>
#include <iostream>
//#include<Windows.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are requried to complete this method */
    

long long max_Books(int arr[], int n, int k) {
        // Your code here
         long maxi=0;
        long ans=0;
        int i=0;
        while(i<n)
        {
            if(arr[i]<=k)
            {
                ans=0;
                while(i<n && arr[i]<=k)
                {
                    ans+=arr[i];
                    i++;
                }
                maxi = max(ans,maxi);
            }
            
            else
            {
                i++;
            }
            
        }
        return maxi;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends