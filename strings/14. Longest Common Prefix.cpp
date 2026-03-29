class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        for (int i = 0; i < strs[0].size(); i++){
            char currentChar = strs[0][i];
            for (int j = 1; j < strs.size(); j++){
                if (i >= strs[j].size() || strs[j][i] != currentChar){
                    string result = "";
                    for (int k = 0; k < i; k++){
                        result += strs[0][k];
                    }
                    return result;
                }
            }
        }
        return strs[0];
    }
};
