class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int ptr = 0;
        for (int i = 1; i <= n; i++){
            if ( target.size() == ptr){
                break;
            }
            if (i == target[ptr]){
                operations.push_back("Push");
                ptr++;
            }
            else{
                operations.push_back("Push");
                operations.push_back("Pop");
                // ptr++;
            }
        }
        return operations;
    }
};
