// https://leetcode.com/problems/subsets/description/
// LC: 78. Subsets

// TC: O(2^n* n)
class Solution {
public:
    void subset(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& final_ans){
        if(i==nums.size()){
            final_ans.push_back(ans);
            return ;
        }
        //include
        ans.push_back(nums[i]);
        subset(nums,i+1,ans,final_ans);
        //exclude while backtracking
        ans.pop_back();
        subset(nums,i+1,ans,final_ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> final_ans;
        vector<int> ans;
        int i=0;
        subset(nums,i,ans,final_ans);
        return final_ans;
        
    }
};