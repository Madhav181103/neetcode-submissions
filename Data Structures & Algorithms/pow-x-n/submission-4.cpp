class Solution {
public:
    double f(double x,long long n){

        if(n==0)return 1;
        else if(n==1)return x;
        
        double half = f(x,n/2);
        if(n%2==1){
            return half*half*x;
        }
        else return half*half;
    }
    double myPow(double x, int n) {
        long long N = n ;
        if(n<0){
            x = 1/x;
             N = -n;
        }
       
        return f(x,N);
        
    }
};
