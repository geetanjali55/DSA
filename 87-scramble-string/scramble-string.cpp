class Solution {
public:
    int func1(std::string s1 ,std::string s2 , map <string,int> &mpp) {
        if (s1.compare(s2) == 0) return 1 ;
        string val = s1 + "_" + s2 ;
        if (mpp.find(val) != mpp.end()) return mpp[val] ;
        for (int k = 1 ;k <= s1.size() - 1 ;k++) {
            if (func1(s1.substr(0,k),s2.substr(0,k),mpp) && func1(s1.substr(k,s1.size() - k),s2.substr(k,s1.size() - k),mpp)) {
                return mpp[val] = 1 ;
            }
            if (func1(s1.substr(0,k),s2.substr(s1.size() - k,k),mpp) && func1(s1.substr(k,s1.size() - k),s2.substr(0,s1.size() - k),mpp)) {
                return mpp[val] = 1 ;
            }
        }
        return mpp[val] = 0 ;
    }
    bool isScramble(string s1, string s2) {
        int i = 0 ;
        int j = s1.size() - 1 ;
        if (s1.size() != s2.size()) return 0 ;
        map <string,int> mpp ;
        return func1(s1,s2,mpp) ;
    }
};