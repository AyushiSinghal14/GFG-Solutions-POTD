
from typing import List


class Solution:
    def countPartitions(self, n : int, d : int, arr : List[int]) -> int:
        # code here
        arr_sum = sum(arr)
        if (arr_sum + d) % 2 != 0:
            return 0
    
        s1 = (arr_sum + d) // 2
        n = len(arr)
        mod = 10**9 + 7
    
        # Initialize a 1D dp array with all 0's
        dp = [0] * (s1 + 1)
        dp[0] = 1  # There's one way to get sum 0: include no elements
    
        # Iterate over each element in arr
        for num in arr:
            # Update the dp array in reverse to avoid overwriting values we need to use
            for j in range(s1, num - 1, -1):
                dp[j] = (dp[j] + dp[j - num]) % mod
    
        return dp[s1]


#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        d = int(input())
        
        
        arr=IntArray().Input(n)
        
        obj = Solution()
        res = obj.countPartitions(n, d, arr)
        
        print(res)
        

# } Driver Code Ends