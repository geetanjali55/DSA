class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size(), m = list2.size();
        unordered_map<string, int> map;
        for (int i = 0; i < n; ++i) map[list1[i]] = i;
        vector<string> result;
        int min = INT_MAX;
        for (int i = 0; i < m; ++i) {
            const string& word = list2[i];
            if (map.find(word) == map.end()) continue;
            int sum = i + map[word];
            if (sum < min) {
                result = {word};
                min = sum;
            } 
            else if (sum == min) result.push_back(word);
        }
        return result;
    }
};