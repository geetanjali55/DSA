class Solution {
public:
    void backtrack(std::vector <string> &v ,string digits ,int ind ,string l ,string mpp[]) {
        if (ind == digits.size()) {
            v.push_back(l) ;
            return ;
        }
        int digit = digits[ind] - '0' ;
        for (int i = 0 ;i < mpp[digit].size() ;i++) {
            string l1 = l + mpp[digit][i] ;
            backtrack(v,digits,ind + 1,l1,mpp) ;
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {} ;
        }
        string mpp[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
            string s = "" ;
            std::vector <string> ans ;
            backtrack(ans,digits,0,s,mpp) ;
               return ans ;                                                                                             
    }
};