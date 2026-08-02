class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0 ;
        int maxlen = 1 ;
        for(int i = 0 ; i < n ; i++ ){
        expand(s,i,i,start,maxlen);
        expand(s,i,i+1,start,maxlen);
        } 
        return s.substr(start,maxlen);
    }
    void expand(string &s , int left ,int right ,int& start ,int& maxlen){
    while( left>=0 && right<s.size() && s[left]==s[right]){
        if(right-left+1>maxlen){
            maxlen = right - left + 1 ;
            start=left ;
        }
        left--;
        right++;
    }
    return ; 
    }
};
