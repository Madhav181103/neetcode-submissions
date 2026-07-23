class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprofit=INT_MIN;
        for(int price : prices){
            minprice=min(price,minprice);
            maxprofit=max(maxprofit,price-minprice);
        }
        return maxprofit;
    }
};
