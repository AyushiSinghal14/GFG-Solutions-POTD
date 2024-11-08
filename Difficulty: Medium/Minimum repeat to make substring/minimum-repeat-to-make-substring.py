from math import ceil

class Solution:
    def minRepeats(self, s1, s2):
        n1 = len(s1)
        n2 = len(s2)
        
        # Initial check to see if s2 is already a substring of s1
        if kmp_search(s1, s2):
            return 1
        
        # Calculate the minimum number of repeats required based on lengths
        repeat_count = ceil(n2 / n1)
        
        # Repeat s1 the calculated number of times
        repeated_s1 = s1 * repeat_count
        
        # Check if s2 is a substring in the current repeated s1
        if kmp_search(repeated_s1, s2):
            return repeat_count
        
        # If not, try adding one more repeat of s1
        repeated_s1 += s1
        if kmp_search(repeated_s1, s2):
            return repeat_count + 1
        
        # If s2 is not a substring after the additional repeat, return -1
        return -1

def build_lps(pattern):
    """
    Builds the LPS (Longest Prefix Suffix) array for the given pattern.
    LPS[i] stores the length of the longest proper prefix of the substring pattern[0:i+1]
    which is also a suffix of this substring.
    """
    m = len(pattern)
    lps = [0] * m
    j = 0  # length of the previous longest prefix suffix

    # The loop calculates lps[i] for i from 1 to m-1
    for i in range(1, m):
        while j > 0 and pattern[i] != pattern[j]:
            j = lps[j - 1]

        if pattern[i] == pattern[j]:
            j += 1
            lps[i] = j
        else:
            lps[i] = 0
    return lps

def kmp_search(text, pattern):
    """
    KMP search algorithm to find the pattern in the given text.
    Returns True if the pattern is found in the text, otherwise False.
    """
    n = len(text)
    m = len(pattern)
    
    if m == 0:
        return True  # empty pattern matches any text
    
    # Step 1: Build the LPS array for the pattern
    lps = build_lps(pattern)
    
    # Step 2: Search pattern in the text
    i = 0  # index for text
    j = 0  # index for pattern
    
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
            
        if j == m:  # A match is found
            return True  # pattern found in text
            
        elif i < n and text[i] != pattern[j]:  # mismatch after j matches
            if j != 0:
                j = lps[j - 1]  # move j to last matched prefix position
            else:
                i += 1

    return False  # pattern not found in text
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        A = input()
        B = input()

        ob = Solution()
        print(ob.minRepeats(A, B))

# } Driver Code Ends