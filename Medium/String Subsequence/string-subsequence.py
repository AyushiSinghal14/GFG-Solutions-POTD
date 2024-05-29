class Solution:
    def countWays(self, s1 : str, s2 : str) -> int:
        MOD = int(1e9 + 7)
        n, m = len(s1), len(s2)
        dp = [1] * (n + 1)

        for i in range(1, m + 1):
            new_dp = [0] * (n + 1)
            for j in range(1, n + 1):
                new_dp[j] = new_dp[j - 1]
                if s2[i - 1] == s1[j - 1]:
                    new_dp[j] = (new_dp[j] + dp[j - 1]) % MOD
            dp = new_dp
        
        return dp[n]


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        s1 = (input())

        s2 = (input())

        obj = Solution()
        res = obj.countWays(s1, s2)

        print(res)

# } Driver Code Ends