class Solution {
public:

int dp[10][2][1000];

int f(int i,bool restricted,int count,string &upperbound){
    if(i==upperbound.size()){
        return count;
    }
    if(dp[i][restricted][count]!=-1) return dp[i][restricted][count];

    int max_digit;
    if(restricted){
        max_digit=upperbound[i]-'0';
    }
    else{
        max_digit=9;
    }

    int total_ones_from_here=0;

    for(int d=0;d<=max_digit;d++){
        bool next_restriction= (restricted)&&(d==max_digit);
        int updated_ones=0;
        if(d==1){
            updated_ones=count+1;
        }
        else{
            updated_ones=count;
        }
        total_ones_from_here+=f(i+1,next_restriction,updated_ones,upperbound);
    }
    return dp[i][restricted][count]=total_ones_from_here;
}

    int countDigitOne(int n) {
        string str=to_string(n);
        memset(dp, -1, sizeof(dp));
        return  f(0,1,0,str);
    }
};