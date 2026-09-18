class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0 ;
        int maxlen = 0 ;
        unordered_map<char,int> mp;
        for(int right = 0 ; right < n ; right++){
            char c = s[right];
            if(mp.count(c) && mp[c]>=left){

                left = mp[c] + 1 ;
            }
            mp[c] = right;
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen ;
    }
};
