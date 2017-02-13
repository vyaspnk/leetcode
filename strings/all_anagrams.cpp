class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
  		vector<int> smap(26,0);
  		vector<int> pmap(26,0);
  		vector<int> ans;

  		if(s.size()==0 || p.size()==0 || s.size() < p.size()) 
  			return ans;
  		for(size_t b=0;b<p.size();b++){
  			pmap[p[b]-'a']++;
  			smap[s[b]-'a']++;
  		}
  		for(auto b=0,e=b+p.size()-1;e<s.size();++b,++e){
  			if(b!=0){//skip for the first window
  				smap[s[b-1] - 'a']--;
  				smap[s[e]   - 'a']++;
  			}
  			if(smap == pmap) ans.push_back(b);
  		}
  		return ans;

    }
};