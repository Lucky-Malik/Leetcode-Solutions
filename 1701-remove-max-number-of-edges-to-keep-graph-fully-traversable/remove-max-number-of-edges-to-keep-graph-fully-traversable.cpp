class DSU {
public:
    vector<int> par, sz;

    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            par[i] = i;
        }
    }

    int find(int idx) {
        if(par[idx] == idx) {
            return idx;
        }

        return par[idx] = find(par[idx]);
    }

    bool Union(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);

        if(x_par == y_par) {
            return false;
        }

        if(sz[x_par] > sz[y_par]) {
            par[y_par] = x_par;
            sz[x_par] += sz[y_par];
        }
        else if(sz[x_par] < sz[y_par]) {
            par[x_par] = y_par;
            sz[y_par] += sz[x_par];
        }
        else {
            par[y_par] = x_par;
            sz[x_par] += sz[y_par];
        }

        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU a(n), b(n);

        int used = 0;

        for(auto &e : edges) {
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 3) {
                bool x = a.Union(u, v);
                bool y = b.Union(u, v);

                if(x || y) {
                    used++;
                }
            }
        }

        for(auto &e : edges) {
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 1) {
                if(a.Union(u, v)) {
                    used++;
                }
            }
        }

        for(auto &e : edges) {
            int type = e[0];
            int u = e[1];
            int v = e[2];

            if(type == 2) {
                if(b.Union(u, v)) {
                    used++;
                }
            }
        }

        int compa = 0;
        int compb = 0;

        for(int i = 1; i <= n; i++) {
            if(a.find(i) == i) {
                compa++;
            }

            if(b.find(i) == i) {
                compb++;
            }
        }

        if(compa > 1 || compb > 1) {
            return -1;
        }

        return edges.size() - used;
    }
};