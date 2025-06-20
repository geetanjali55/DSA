class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return 0 ;
        map <char,int> mpp1 ;
        map <char,int> mpp2 ;
        for (int i = 0 ;i < s1.size() ;i++) {
            mpp1[s1[i]]++ ;
            mpp2[s2[i]]++ ;
        }
        int i = 0 ;
        int j  = s1.size() ;
        if (mpp1 == mpp2) return 1 ;
        while(j < s2.size()) {
            mpp2[s2[i]]-- ;
            mpp2[s2[j]]++ ;
            if (mpp2[s2[i]] == 0) {
    mpp2.erase(s2[i]);
}
            i++ ;
            j++ ;
            if (mpp1 == mpp2) return 1 ;
        }
        return 0 ;
    }
};