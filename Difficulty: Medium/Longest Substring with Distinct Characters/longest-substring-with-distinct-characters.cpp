class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int maxlen = 0, left = 0, right = 0;
        vector<int> hash(256, -1);
        
        while(right < s.size()){
            if(hash[s[right]] != -1){
                if(left <= hash[s[right]]) left = hash[s[right]] + 1;
            }
            int len = right - left + 1;
            maxlen = max(len, maxlen);
            
            hash[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};
