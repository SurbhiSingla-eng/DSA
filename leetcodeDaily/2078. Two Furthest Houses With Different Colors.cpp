class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = 0;
        int color = colors[0];
        for (int i = 1; i < colors.size(); i++){
            if (colors[i] != color){
                int dist = i;   
                if (dist > maxDist){
                    maxDist = dist;
                }
            }
        }
        color = colors[colors.size() - 1];
        for (int i = 0; i < colors.size() - 1; i++){
            if (colors[i] != color){
                int dist = (colors.size() - 1) - i;
                if (dist > maxDist){
                    maxDist = dist;
                }
            }
        }
        return maxDist;
    }
};
