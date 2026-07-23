class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        unordered_map<char,int> mp;
        int maxlen=0;
        int left=0;
        for(int right =0;right<n;right++){
            char c=s[right];
            if(mp.count(c)){
               if(mp[c]>=left){
                left=mp[c]+1;
               }
            }
                mp[c]=right;
              
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};
