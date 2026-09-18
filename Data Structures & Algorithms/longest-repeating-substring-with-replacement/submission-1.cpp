class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26] = {0};
        int left = 0;
        int maxlen = 1;
        int maxfreq = INT_MIN;
        for(int right = 0 ; right < n ; right++ ){
            freq[s[right]-'A']++;
            maxfreq = max(maxfreq,freq[s[right]-'A']);
            while((right-left+1) - maxfreq > k){
                freq[s[left]-'A']--;
                
                left++;

            }
            maxlen = max(maxlen , right - left + 1);
        }
        return maxlen;
    }
};
