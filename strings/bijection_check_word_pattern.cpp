class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> mymap;
        string::iterator pit = pattern.begin();
        char *tok = strtok((char *)str.c_str(), " ");
        mymap.insert(*pit,tok);
        pit++;
        tok = strtok(NULL, (char *)delim.c_str());
        map<char,string>::iterator it;
        while(pit!=pattern.end() && !tok){
        	if((it=mymap.find(pit))==mymap.end()){
        		mymap.insert(*pit,string(tok));	        	
        	} else if(*it->second!=tok)
        			return false;

        	pit++;
        	tok = strtok(NULL, (char *)delim.c_str());
        }
        if((pit==pattern.end() && tok!=NULL )|| ( pit!=pattern.end() && !tok) )
        	return false;
        else
        	return true;
    }
};