class Solution {
public:
    string addStrings(string num1, string num2) {
    	if(num1.size()==0)
    		return num2;
    	if(num2.size()==0)
    		return num1;

        string& small = (num1.size() <  num2.size()?num1:num2);
        string& big   = (num1.size() >= num2.size()?num1:num2);
        int carry = 0;
        for(string::reverse_iterator bit = big.rbegin(), sit = small.rbegin(); bit!=big.rend(); bit++) {
        	int small_val = 0;
        	int sum = 0;
        	if(sit!=small.rend()) { small_val = *sit-'0';sit++;}
        	sum = (*bit-'0')+small_val+carry;
        	carry = sum/10;
        	*bit = sum%10+'0';
        }
        if(carry)
        	return "1"+big;
        else
        	return big;
    }	
};