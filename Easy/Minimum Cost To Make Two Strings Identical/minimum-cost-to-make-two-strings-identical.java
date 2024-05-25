//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GfG {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String X = sc.next();
            String Y = sc.next();
            int costX = sc.nextInt();
            int costY = sc.nextInt();

            Solution ob = new Solution();
            System.out.println(ob.findMinCost(X, Y, costX, costY));
        }
    }
}
// } Driver Code Ends


class Solution {
    private int f(int i1,int i2,String x,String y,int costX,int costY,int [][]dp)
    {
        if(i1<0)
        {
            return costY*(i2+1);
        }
        else if(i2<0)
            return costX*(i1+1);
         
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        if(x.charAt(i1)==y.charAt(i2))
        {
            return dp[i1][i2]=f(i1-1,i2-1,x,y,costX,costY,dp);
        }
        return dp[i1][i2]=Math.min(costX+f(i1-1,i2,x,y,costX,costY,dp),costY+f(i1,i2-1,x,y,costX,costY,dp));
    }
    
    public int findMinCost(String x, String y, int costX, int costY) {
        int n=x.length();
        int m=y.length();
        int [][]dp=new int[n][m];
        for(int []val:dp)
            Arrays.fill(val,-1);
        return f(n-1,m-1,x,y,costX,costY,dp);
    }
}
