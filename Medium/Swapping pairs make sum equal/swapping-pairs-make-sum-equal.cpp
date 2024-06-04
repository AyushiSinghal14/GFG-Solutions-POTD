//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++) sum1+=a[i];
        for(int i=0;i<m;i++) sum2+=b[i];
        sort(a,a+n);
        sort(b,b+m);
        if(sum1<sum2){
            int i=0 ,j=m-1;
            while(i<n && j>=0 && b[j]-a[i] >0){
                int x=b[j]-a[i];
                if(sum1+x == sum2-x) return 1;
                i++;
                j--;
            }
        }
        else if(sum1>sum2){
            int i=0,j=n-1;
            while(i<m && j>=0 && a[j]-b[i]>0){
                int x=a[j]-b[i];
                if(sum1-x == sum2+x) return 1;
                i++;
                j--;
            }
        }
        if(sum1==sum2) return 1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends