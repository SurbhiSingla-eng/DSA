class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indicesMap;
        for (int i = 0; i < nums.size(); i++) {
            indicesMap[nums[i]].push_back(i);
        }
        int distance = INT_MAX;
        int indistance = distance;
        for (auto& pair : indicesMap) {
            vector<int>& pos = pair.second;
            if (pos.size() < 3) continue;
            for (int i = 0; i <= (int)pos.size() - 3; i++) {
                int current = 2 * (pos[i+2] - pos[i]);
                if (current < distance) {
                    distance = current;
                }
            }
        }
        return (distance == indistance) ? -1 : distance;
    }
};
