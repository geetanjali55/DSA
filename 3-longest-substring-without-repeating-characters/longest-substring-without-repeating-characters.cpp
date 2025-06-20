class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ;
        int r = 0 ;
        int maxlen = 0 ;
        int hash[256] ;
        for (int i = 0 ;i < 256 ;i++) {
            hash[i] = -1 ;
        }
        int n = s.size() ;
        while(r < n) {
            if (hash[s[r]] != -1) {
                l = max(l ,hash[s[r]] + 1) ;
            }
            maxlen = max(r - l + 1 ,maxlen) ;
            hash[s[r]] = r ;
            r++ ;
        }
        return maxlen ;
    }
};