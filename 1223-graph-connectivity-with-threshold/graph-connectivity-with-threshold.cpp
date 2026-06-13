class Solution {
public:
    vector<int> par, sz, rank;

    int find(int idx){
        if(par[idx] == idx){
            return idx;
        }

        return par[idx] = find(par[idx]);
    }

    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);

        if(x_par != y_par){
            if(sz[x_par] > sz[y_par]){
                par[y_par] = x_par;
                sz[x_par] += sz[y_par];
            }
            else if(sz[x_par] < sz[y_par]){
                par[x_par] = y_par;
                sz[y_par] += sz[x_par];
            }
            else{
                par[y_par] = x_par;
                sz[x_par] += sz[y_par];
            }
        }
    }
    vector<bool> areConnected(int n, int th, vector<vector<int>>& que) {
        par.resize(n + 1);
        sz.assign(n + 1, 1);

        for(int i=1;i<=n;i++){
            par[i] = i;
        }

        for(int i = th + 1; i <= n; i++){
            for(int j = i; j <=n; j += i){
                Union(i, j);
            }
        }
        vector<bool> ans;
        for(auto x : que){
            if(find(x[0]) != find(x[1])){
                ans.push_back(false);
            }
            else ans.push_back(true);
        }
        return ans;
    }
};