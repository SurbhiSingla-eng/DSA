class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(areEqual(s1,s2)){
            return true;
        }

            swap(s1[0],s1[2]);
            if(areEqual(s1,s2))
            return true;

            swap(s1[1],s1[3]);
            if(areEqual(s1,s2))
            return true;

            swap(s1[0],s1[2]);
            if(areEqual(s1,s2))
            return true;

            // swap(s1[2],s1[4]);
            // if(areEqual(s1,s2))
            // return true;
        
            return false;
    }
    bool areEqual(string a, string b){
        for (int i = 0; i < 4; i++){
            if (a[i] != b[i]){
                return false;
                }
            }
            return true;
    }
};
