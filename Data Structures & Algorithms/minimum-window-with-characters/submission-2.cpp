class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n)return "";
        int need[256]={0};
        for(char c : t){
            need[c]++;
        }
        int minlen = INT_MAX;
        int start = 0 ;
        int left = 0 ;
        int matched = 0 ;
        int freq[256] = {0};
        for(int right = 0 ; right < n ; right++){
            freq[s[right]]++;
            if(freq[s[right]]<=need[s[right]]){
                matched++;
            }
            while(matched==m){
                if(right-left+1 < minlen){
                    minlen = right - left + 1 ;
                    start = left ;
                }
                freq[s[left]]--;
                if(freq[s[left]]<need[s[left]]){
                    matched--;
                }
                left++;
            }
        }
        if(minlen == INT_MAX)return "";
        return s.substr(start,minlen);
    }
};
