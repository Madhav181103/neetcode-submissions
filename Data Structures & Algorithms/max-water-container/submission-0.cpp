class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int area = 0;
        int ans=0;
        while(l<r){
        int length = min(heights[l],heights[r]);
        int width  = r-l;
        area=length*width;
        ans=max(ans,area);
        if(length==heights[l])l++;
        else r--;
        }
        return ans;
    }
};
