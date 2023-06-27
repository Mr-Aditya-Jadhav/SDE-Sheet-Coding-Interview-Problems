//https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        
        double toret = 1.00;
        long nn = abs(n);

        while(nn > 0){
            if(!(nn % 2)){
                x = x * x;
                nn = nn/2;
            }
            else{

                toret = toret * x;
                nn--;
            }
        }

        if(n < 0)return (double)(1.0)/(double)(toret);

        return toret;




        
    }
};