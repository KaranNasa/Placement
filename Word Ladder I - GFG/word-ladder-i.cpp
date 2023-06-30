//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        queue<pair<string,int>> q;
        q.push({startWord,1});
        unordered_set<string>  st(wordList.begin(),wordList.end());
        st.erase(startWord);
        
        while(!q.empty())
        {
            string word=q.front().first;
            int level=q.front().second;
            
            q.pop();
            if(word==targetWord)
            {
                return level;
            }
            // for every character change it from a-z
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end()) {
                        st.erase(word);
                        q.push({word,level+1});
                    }
                }
                word[i]=original;   // replace with the correct character
                
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends