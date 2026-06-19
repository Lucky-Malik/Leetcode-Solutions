class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        for(int i=0;i<(1 << n); i++){
            int cnt = __builtin_popcount(i);
            if(cnt == k){
                vector<int> v;
                for(int j=0;j<n;j++){
                    if(i & (1 << j)){
                        v.push_back(j + 1);
                    }
                }

                ans.push_back(v);
            }
        }
        return ans;
    }
};