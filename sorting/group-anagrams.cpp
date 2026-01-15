class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> ,vector<string>> mp;
        for(auto word:strs){
            vector<int> v(26,0);
            for(auto ch:word){
                v[ch-'a']++;
            }
            mp[v].push_back(word);
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            vector<string> s;
            for(auto st:i.second){
                s.push_back(st);
            }
            ans.push_back(s);
        }
        return ans;
    }
};