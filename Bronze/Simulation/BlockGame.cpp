// USACO 2016 December Contest, Bronze
// Problem 2. Block Game

#include <iostream>
#include <string>
using namespace std;

int alphabetCount[26];

int maxOf(string word, char ch) {
    int charCount = 0;
    for(int i = 0; i < word.size(); i++) {
        if(word[i] == ch) 
            charCount++;
    }
    return charCount;
}

int main()
{
     freopen("blocks.in","r",stdin);
    // reuse standard in to read from "blocks.in"
     freopen("blocks.out","w",stdout);
    // reuse standard out to write to "blocks.out"
    
    int n;
    cin >>  n;
    string front[n], back[n];

    for(int i = 0; i < n; i++) {
        cin >> front[i] >> back[i];
    }

    for(int i = 0; i < 26; i++) {
        int totalMax = 0;
        for(int j = 0; j < n; j++) {
            //take the word with maximum occurence of particular character
            int mx = max(maxOf(front[j], 'a' + i), maxOf(back[j], 'a' + i));
            totalMax += mx;
        }
        cout << totalMax << "\n";
    }
}
