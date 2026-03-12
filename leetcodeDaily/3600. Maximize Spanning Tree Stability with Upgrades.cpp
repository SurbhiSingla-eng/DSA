#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> parent;
    int components;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    bool isPossible(int n, int mid, int k, const vector<vector<int>>& edges) {
        DSU dsu(n);
        int mandatoryCount = 0;
        int upgradesUsed = 0;

        // 1. Process Mandatory Edges
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < mid) return false; // Mandatory edge fails stability
                if (!dsu.unite(e[0], e[1])) return false; // Cycle with mandatory edges
                mandatoryCount++;
            }
        }

        // 2. Process Free Optional Edges (s >= mid)
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= mid) {
                dsu.unite(e[0], e[1]);
            }
        }

        // 3. Process Upgradeable Optional Edges (2*s >= mid)
        // Only use these if they actually help connect the graph
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < mid && 2 * e[2] >= mid) {
                if (dsu.find(e[0]) != dsu.find(e[1])) {
                    if (upgradesUsed < k) {
                        dsu.unite(e[0], e[1]);
                        upgradesUsed++;
                    }
                }
            }
        }

        // Must form a single component and use exactly n-1 edges
        // (If components == 1, DSU logic ensures it's a tree if we started with no cycles)
        return dsu.components == 1 && (mandatoryCount <= n - 1);
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low = 1, high = 200000;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(n, mid, k, edges)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
