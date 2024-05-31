//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {

            String s;
            s = br.readLine();

            Solution obj = new Solution();
            String res = obj.oddEven(s);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends



class Solution {
    public static String oddEven(String s) {
        // code here
        HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<s.length();i++)
        {
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
        int ans=0;
        for(Character key:map.keySet())
        {
            int num=key-'a'+1;
            if((num&1)==0) 
            {
                if((map.get(key)&1)==0)
                    ans++;
            }
            else
            {
                if((map.get(key)&1)!=0)
                    ans++;
            }
            
        }
        if((ans&1)==0)
            return "EVEN";
        return "ODD";
    }


}
