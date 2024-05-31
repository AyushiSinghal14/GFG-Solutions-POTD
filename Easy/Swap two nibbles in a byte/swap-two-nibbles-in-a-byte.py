#User function Template for python3


 

class Solution:
    def swapNibbles (self, n):
        

         ###Conversion of n into binary form

        a=""
        while n>0:
            a=str(n%2)+a
            n=n//2
        if len(a)<8:
            m=8-len(a)
            a="0"*m+a

       ###Exchange of the two half-byte
        a=a[4:8]+a[0:4]
        solution=0
        base=1

       

       ###Transformation of binary code into decimal

      
        for i in range(len(a)):
            if a[len(a)-i-1]=="1":
                solution+=base
            base=base*2
            
        return solution

#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        print(ob.swapNibbles(n))

# } Driver Code Ends