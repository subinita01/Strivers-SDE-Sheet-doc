// LC: 46. Permutations
// https://leetcode.com/problems/permutations/description/

class Solution {
public:
    void permutation(vector<int>& nums, int idx, vector<vector<int>>& out){
        if(idx==nums.size()-1){
            out.push_back(nums);
            return ;
        }
        
        for(int j=idx; j<=nums.size()-1; j++){
            swap(nums[idx],nums[j]); // choice
            //explore
            permutation(nums,idx+1,out);
            swap(nums[idx],nums[j]); // backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        int idx=0;
        permutation(nums,idx,out);
        return out;
        
    }
};