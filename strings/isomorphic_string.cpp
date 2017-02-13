class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int length = s.size();
        if(!length)
        	return true;
        if(length==1 ) {        	
        		return true;        	
        }
        int diff = s[0]-t[0];
        
        while(--length) {
        	if((s[length]-t[length]) != diff)
        		return false;
        }
        return true;
    }
};