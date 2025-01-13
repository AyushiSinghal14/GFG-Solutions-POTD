

class Solution:
    def maxWater(self, arr):
        ans=0
        n=len(arr)
        left=0
        right=n-1
        
        while (left<right):
            curr=min(arr[left],arr[right])*(right-left)
            ans=max(ans,curr)
            if arr[left]<arr[right]:
                left+=1
            else:
                right-=1
                
        return ans


#{ 
 # Driver Code Starts
#Initial template for Python 3

import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxWater(arr))

        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends