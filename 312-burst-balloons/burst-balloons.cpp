class Solution {
public:
    int func1(std::vector <int> &a ,int i ,int j ,std::vector <vector<int>> &dp) {
        if (i > j) {
            return 0 ;
        }
        if (dp[i][j] != -1) {
            return dp[i][j] ;
        }
        int maxi = INT_MIN ;
        for (int k = i ;k <= j ;k++) {
            int temp = 0 ;
            temp = a[k] * a[i - 1] * a[j + 1] + func1(a,i,k - 1,dp) + func1(a,k + 1,j,dp) ;
            maxi = max(temp ,maxi) ;
        }
        return dp[i][j] = maxi ;
    }
    int maxCoins(vector<int>& nums) {
        int i = 0 ;
        nums.insert(nums.begin() ,1) ;
        nums.push_back(1) ;
        int j = nums.size() - 2 ;
        std::vector <vector<int>> dp (nums.size() ,std::vector <int> (nums.size() ,-1)) ;
        return func1(nums,1,j,dp) ;
    }
};