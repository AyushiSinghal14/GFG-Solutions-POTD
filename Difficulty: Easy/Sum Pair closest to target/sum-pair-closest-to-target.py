#User function Template for python3
class Solution:
    def sumClosest(self, arr, target):
        arr.sort()
        ans=[0,float("inf")]
        l,h=0,len(arr)-1
        while l<h:
            val=arr[l]+arr[h]
            if abs(sum(ans)-target)>abs(val-target):
                ans[0],ans[1]=arr[l],arr[h]
            if target<val:
                h-=1
            else:
                l+=1
        return ans if len(arr)!=1 else []



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input().strip())
    while t > 0:
        arr = list(map(int, input().strip().split()))
        target = int(input().strip())
        ob = Solution()
        ans = ob.sumClosest(arr, target)
        if not ans:
            print("[]")
        else:
            print(*ans)
        print("~")
        t -= 1

# } Driver Code Ends