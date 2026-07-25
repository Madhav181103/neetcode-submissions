class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> need(26, 0);
        vector<int> window(26, 0);
        int n = s1.size();
        for(char c : s1){
          need[c-'a']++;
        }
        int m = s2.size();
        int left=0;
        if(n>m)return false;
        for(int right=0;right<m;right++){
          window[s2[right]-'a']++; 
          if(right-left+1>n){
            window[s2[left]-'a']--;
            left++;
          }
          if((right-left+1)==n && window==need)return true;
        }
        return false;
    }
};
