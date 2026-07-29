class Solution {
public:
    vector<string> ans;
    void generate(int n , int low, int high,string s){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(low<n)generate(n,low+1,high,s+'(');
        if(high<low)generate(n,low,high+1,s+')');
    }
    vector<string> generateParenthesis(int n) {
        generate(n,0,0,"");
        return ans;
    }
};
