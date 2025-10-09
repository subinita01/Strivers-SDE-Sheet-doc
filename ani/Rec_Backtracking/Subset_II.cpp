// https://leetcode.com/problems/subsets-ii/description/
// LC: 90. Subsets II
// exclude duplicates
//TC (nlogn + 2^n * n) SC: O(n)

class Solution {
public:
    void subset(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& final_ans){
        sort(nums.begin(),nums.end());
        if(i==nums.size()){
            final_ans.push_back(ans);
            return ;
        }
        //include
        ans.push_back(nums[i]);
        subset(nums,i+1,ans,final_ans);

        //exclude while backtracking
        ans.pop_back();

        // skip duplicates
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx=idx+1;
        }
    
        subset(nums,idx,ans,final_ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> final_ans;
        vector<int> ans;
        int i=0, idx=0;
        subset(nums,i,ans,final_ans);
        return final_ans;        
        
    }
};