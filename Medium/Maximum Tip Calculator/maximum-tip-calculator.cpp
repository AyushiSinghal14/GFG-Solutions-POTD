//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int>& arr, vector<int>& brr) {
        vector<pair<int, int>> diffIndex;

        // Create a vector of pairs where each pair contains the absolute difference
        // between the tips from arr and brr and the index of that tip.
        for (int i = 0; i < n; ++i) {
            diffIndex.push_back({abs(arr[i] - brr[i]), i});
        }

        // Sort the pairs by the absolute difference in descending order
        sort(diffIndex.begin(), diffIndex.end(), greater<pair<int, int>>());

        long long ans = 0;
        int countA = 0, countB = 0;

        // Iterate through the sorted pairs and select tips
        for (int i = 0; i < n; ++i) {
            int idx = diffIndex[i].second;

            // Prefer the higher tip if possible and allowed
            if ((arr[idx] >= brr[idx] && countA < x) || countB == y) {
                ans += arr[idx];
                countA++;
            } else {
                ans += brr[idx];
                countB++;
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends