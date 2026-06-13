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
    int removeStones(vector<vector<int>>& st) {
        int n = st.size();
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i=0;i<=n;i++){
            par[i] = i;
        }

        for(int i=0;i<n;i++){
            for(int j = i;j<n;j++){
                if(st[i][0] == st[j][0] || st[i][1] == st[j][1]){
                    Union(i, j);
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j = i;j<n;j++){
        //         if(st[i][0] == st[j][0] || st[i][1] == st[j][1]){
        //             Union(i + 1, j + 1);
        //         }
        //     }
        // }
        
        // int ans = 0;
        // set<int> s;
        // for(auto x : sz) cout << x << " ";
        // cout << endl;
        int comp = 0;

        for(int i = 0; i < n; i++) {
            if(find(i) == i)
                comp++;
        }

        return n - comp;
        

    }
};