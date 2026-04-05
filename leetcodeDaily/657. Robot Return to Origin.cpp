class Solution {
public:
    bool judgeCircle(string moves) {
        // if (moves == "UD" || moves == "DU" || moves == "LR" || moves == "RL" || moves == "UD"){
        //     return true;
        // }
        // else{
        //     return false;
        // }
        // vector<int> postiton = {0,0};

        int x = 0, y = 0;
        for (char move : moves){
            if (move == 'U'){
                x++;
            }
            else if (move == 'D'){
                x--;
            }
            else if (move == 'R'){
                y++;
            }
            else if (move == 'L'){
                y--;
            }
        }
        if ( x == 0 && y == 0){
            return true;
        }
        else {
            return false;
        }
    }
};
