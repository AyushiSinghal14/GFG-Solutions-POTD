//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
    vector<int> rank, par, size;
    public:
        DisjointSet(int n) {
            rank.resize(n , 0);
            par.resize(n);
            size.resize(n);
            
            for (int i = 0; i < n; i++) {
                par[i] = i;
                size[i] = 1;
            }
        }
    
        void unionByRank(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            
            if (rank[pa] < rank[pb]) {
                par[pa] = pb;
            }
            else if (rank[pb] < rank[pa]) {
                par[pb] = pa;
            }
            else {
                par[pb] = pa;
                rank[pa]++;
            }
        }
    
        void unionBySize(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            
            if (size[pa] < size[pb]) {
                par[pa] = pb;
                size[pb] += size[pa];
            }
            else {
                par[pb] = pa;
                size[pa] += size[pb];
            }
        }
        int find(int x) {
            if (x == par[x])    return x;
            return par[x] = find(par[x]);
        }
};

class Solution {
    public:
        vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
            int n = details.size();

            unordered_map<string, int> mailIndex;
            DisjointSet ds(n);
            
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < details[i].size(); j++) {
                    string mail = details[i][j];
                    
                    //not contains
                    if (mailIndex.find(mail) == mailIndex.end()) {
                        mailIndex[mail] = i;
                    }
                    else {
                        ds.unionBySize(i, mailIndex[mail]);
                    }
                    
                }
            }
    
            vector<string> mergeAccounts[n];
            
            for (auto it : mailIndex) {
                string mail = it.first;
                int index = it.second;
                int par = ds.find(index);
                
                mergeAccounts[par].push_back(mail);
            }
            
    
            vector<vector<string>> ans;
    
            for (int i = 0; i < n; i++) {
                //empty account
                if (mergeAccounts[i].size() == 0) continue;
                
                
                //mails sorting required
                sort(mergeAccounts[i].begin(), mergeAccounts[i].end());
                
                
                vector<string> temp;
                
                //add name
                temp.push_back(details[i][0]);
                //add mails
                temp.insert(temp.end(), mergeAccounts[i].begin(), mergeAccounts[i].end());
                
                ans.push_back(temp);
            }
            
            return ans;
            
        }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends