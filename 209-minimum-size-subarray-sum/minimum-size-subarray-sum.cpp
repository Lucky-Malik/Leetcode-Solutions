class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int cur_sum = 0;
        int l = 0, r = 0;
        int best_len = INT_MAX;
        while(r < n){
            cur_sum += nums[r];
            if(cur_sum >= target){
                best_len = min(best_len, r - l + 1);
                while(l <= r && cur_sum >= target){
                    best_len = min(best_len , r - l + 1);
                    cur_sum -= nums[l];
                    l++;
                }
          }
          r++;
        }

        return ((best_len == INT_MAX) ? 0 : best_len);
    }
};