class Solution {
public:
    int longestPalindrome(string s) {
        int pairs=0,sum=0;
        vector<int> smap(58,0); //a-z [ / ] ^ _ ` A-Z
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;
        for(int b=0; b < s.size(); b++){
            smap[s[b]-'A']++;
            smap[s[b]-'A']%=2;
            sum++;
            if(smap[s[b]-'A']==0) {
                pairs++;
                sum= sum-2;
            }
        }
        if(sum>1)
            sum = 1;
        return (pairs*2)+sum;
        
    }
};