class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int tar) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int cur = 0;
            for(int j=i;j<n;j++){
                if(nums[j] == tar){
                    cur++;
                }
                if(cur > (j - i + 1) / 2) ans++;
            }
        }
        return ans;
    }
};