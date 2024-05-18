//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int diff=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(abs(arr[i]-k)<=diff)
            {
                diff=abs(arr[i]-k);
                if(arr[i]>maxi)
                {
                    maxi=arr[i];
                }
            }
            
        }
        return maxi;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends