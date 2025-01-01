//{ Driver Code Starts
import java.util.*;


// } Driver Code Ends
class Solution {
    public ArrayList<ArrayList<String>> anagrams(String[] arr) {
        // code here
        LinkedHashMap<String,ArrayList<String>> hm=new LinkedHashMap<>();
        for(String i:arr){
            ArrayList<Character> temp=new ArrayList<>();
            for(char c:i.toCharArray())temp.add(c);
            Collections.sort(temp);
            String s="";
            for(char p:temp)s+=p;
            if(hm.containsKey(s)){
                hm.get(s).add(i);
            }
            else{
                hm.put(s,new ArrayList<>());
                hm.get(s).add(i);
            }
        }
       ArrayList<ArrayList<String>> res=new ArrayList<>();
       for(String s:hm.keySet()){
           res.add(hm.get(s));
       }
        return res;
    }
}


//{ Driver Code Starts.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Ignore the newline after the test case input
        while (t-- > 0) {
            String inputLine = sc.nextLine();
            String[] arr = inputLine.split(" ");

            Solution ob = new Solution();
            ArrayList<ArrayList<String>> result = ob.anagrams(arr);
            result.sort(Comparator.comparing(a -> a.get(0)));
            for (ArrayList<String> group : result) {
                for (String word : group) {
                    System.out.print(word + " ");
                }
                System.out.println();
            }
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends