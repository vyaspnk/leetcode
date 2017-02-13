class Solution {
public:
    bool isPalindrome(string s) {
    	if( s.size()==0 )
            return true;
        if( s.size()==1)
    		return true;
    	
        int begin = 0;
        int end = s.size()-1;
        
        while(begin < end )	{
        		if( s[begin] <'0'  || (s[begin]>'9'&& s[begin] <'A')  || s[begin]>'z' || (s[begin]> 'Z'  && s[begin]<'a')) {
        		    cout << "here1";
        			begin++;
        			continue;
        		}
				if( s[end] <'0'  || (s[end]>'9' && s[end] <'A')  || s[end]>'z' || (s[end]> 'Z'  && s[end]<'a') ){
				    cout << "here2";
        			end--;
        			continue;
        		}
        		if( s[begin] == s[end] 
        		    || ( ( s[begin]>='A' && s[begin]<='Z' || s[begin]>='a' && s[begin]<='z' ) &&
        		        (  s[end]>='A' && s[end]<='Z' || s[end]>='a' && s[end]<='z' ) &&
        			 ( (s[begin]-'a') == (s[end]-'A') 
        			|| (s[begin]-'A') == (s[end]-'a') ) ) ){
        			    cout << "here ";
                    	begin++;        
                    	end--;        			    
        			} else 
        			    return false;
        }
        if(begin >= end || (begin+1==end && s[begin]==s[end] ))
        		return true;
        else
        	return false;
    }
};