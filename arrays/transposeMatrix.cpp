// for sqaure matrix
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int temp;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = i; j < matrix.size(); j++){
                //swap
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return matrix;
    }
};

// for any matrix
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> result(cols, vector<int>(rows));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
};

// second one consumes extra space
