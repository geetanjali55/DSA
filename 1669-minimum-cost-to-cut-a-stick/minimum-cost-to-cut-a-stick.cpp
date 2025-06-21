class Solution {
public:
    int func1(std::vector <int> &a ,int i2 ,int j2 ,std::vector <vector<int>> &dp) {
        if (i2 > j2) return 0 ;
        // if (i2 == j2) return j1 - i1 ;
        if (dp[i2][j2] != -1) {
            return dp[i2][j2] ;
        }
        int mini = INT_MAX ;
        for (int k = i2 ;k <= j2 ;k++)  {
            int temp = a[j2 + 1] - a[i2 - 1] + func1(a,i2,k - 1,dp) + func1(a,k + 1,j2,dp) ;
            mini = min(temp ,mini) ;
        }
        return dp[i2][j2] = mini ;
    }
    int minCost(int n, vector<int>& cuts) {
        int i1 = 0 ;
        int j1 = n ;
        int i2 = 1 ;
        int j2 = cuts.size() ;
        cuts.push_back(n) ;
        cuts.insert(cuts.begin() ,0) ;
        if (cuts.size() == 1) return j1 ;
        sort(cuts.begin() ,cuts.end()) ;
        std::vector <vector<int>> dp(j2 + 1 ,std::vector <int> (j2 + 1 ,-1)) ;
        return func1(cuts,i2,j2,dp) ;
    }
};