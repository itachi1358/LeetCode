class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s; 
        vector<vector<char>> v(numRows,vector<char> (1000,'-'));
        int idx=0,i=0,j=0;
        bool diagonal=0;
        while(idx<s.size()){
            v[i][j]=s[idx];
            if(diagonal){
                j++;
                i--;
            }
            else{
                i++;
            }

            if(i==numRows-1){
                diagonal=true;
            }

            if(i==0) diagonal=false;
            idx++;
        }
        string ans="";
        for(auto row:v){
            for(auto ch:row){
                if(ch!='-')ans+=ch;
            }
        }

        return ans;
    }
};