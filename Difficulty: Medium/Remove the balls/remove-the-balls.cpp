class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int,int>> st;
        int n = color.size();
        
        for(int i = 0; i < n; i++){
            
            if(!st.empty())
            {
                if((st.top().first==color[i]) and (st.top().second==radius[i])){
                    st.pop();
                }
                else{
                    st.push(pair<int,int>{color[i],radius[i]});
                }
            }
            else{
                st.push(pair<int,int>{color[i],radius[i]});
            }
            
        }
        
        return st.size();
    }
};