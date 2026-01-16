class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;
        set<int> st;
        long long area=-1;
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                st.insert(hFences[j]-hFences[i]);
            }
        }

        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                long long side=vFences[j]-vFences[i];
                if(st.find(side)!=st.end()){
                    area=max(area,side*side);
                }
            }
        }


        if(area<=0) return -1;
        return area%MOD;

    }
};