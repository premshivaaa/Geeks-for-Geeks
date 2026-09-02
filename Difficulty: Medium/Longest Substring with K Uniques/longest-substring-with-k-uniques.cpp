class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int left = 0, right = 0, maxlen = 0;
        unordered_map<char,int> mp;
        
        while(right < s.size()){
            mp[s[right]]++;
            if(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        
        if(mp.size() < k) return -1;
        
        return maxlen;
    }
};