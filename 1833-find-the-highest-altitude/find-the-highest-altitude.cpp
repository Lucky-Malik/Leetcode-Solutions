class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> pre(gain.size()+1,0);
        int ans = 0;
        for(int i = 1;i<=gain.size();i++){
            pre[i] = pre[i-1]+gain[i-1];
            ans = max(ans,pre[i]);
        }
    return ans;
    }

};