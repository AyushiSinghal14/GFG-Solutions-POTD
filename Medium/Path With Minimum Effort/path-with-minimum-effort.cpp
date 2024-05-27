//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int row, int col, vector<vector<int>> &heights) {
        // code here
        // return solver(0,0,heights);
        int arr[4]={-1,1,0,0};
        int brr[4]={0,0,1,-1};
        vector<vector<int>>vis(row+1,vector<int>(col,1e9));
        queue<pair<int,pair<int,int>>>qt;
        vis[0][0]=0;
        qt.push({0,{0,0}});
        while(!qt.empty()){
            auto temp=qt.front();
            qt.pop();
            for(int i=0;i<4;i++){
                int x=arr[i]+temp.second.first;
                int y=brr[i]+temp.second.second;
                // cout<<x<<" "<<y<<" "<<temp.first<<endl;
                if(x>=0 && y>=0 && x<row && y<col && max(temp.first,abs(heights[x][y]-heights[temp.second.first][temp.second.second]))<vis[x][y]){
                    vis[x][y] = max(temp.first,abs(heights[x][y]-heights[temp.second.first][temp.second.second]));
                    qt.push({ vis[x][y] , {arr[i]+temp.second.first,brr[i]+temp.second.second}});
                }
            }
        }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return vis[row-1][col-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends