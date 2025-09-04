class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(z-x); //distance between x and z
        int b = abs(z-y); //distance between y and z
        if(a<b){
            return 1; // if x is near to z
        }else if(a>b){
            return 2; // if y is near to z
        }
        return 0; //if both are at equal distance from z;
    }
};