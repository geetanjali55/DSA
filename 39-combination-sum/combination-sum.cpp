class Solution {
public:
    void func1(std::vector <vector<int>> &ans ,std::vector <int> &a ,std::vector <int> v ,int target,int i)  {
        if (i == 0 || target == 0) {
            if (target == 0) {
                ans.push_back(v) ;
            }
            return ;
        }
        if (a[i - 1] <= target) {
            v.push_back(a[i - 1]) ;
            func1(ans,a,v,target - a[i - 1],i) ;
            v.pop_back() ;
        }
        func1(ans,a,v,target,i - 1) ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector <vector<int>> ans ;
        std::vector <int> v ;
        int n = candidates.size() ;
        func1(ans,candidates,v,target,n) ;
        return ans ;
    }
};