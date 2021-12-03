#include "WordCounter.h"
#include "CommonWordList.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string cleanWord(string);
void removeCommonWords(WordCounter &); 

const char APOSTROPHE_CHAR = '\''; 	// apostrophe character used in cleanWord
const char HYPHEN_CHAR = '-'; 		// hyphen/dash character used in cleanWord

int main() {

	// populate common words
//	CommonWordList::populateWords();

    WordCounter wc(5);
    wc.addWord("Hello");
    wc.addWord("World");
    wc.addWord("End");
    wc.addWord("Program");
    wc.to_string();
    return 0;
}

string cleanWord(string s) {
   string result = "";                  // Keep track of the cleaned result.
   unsigned i = 0, length = s.length(); // Input for the for loop.
   for (; i < length; i++) {
      if (isalnum(s[i])) 
         result += tolower(s[i]);
      else if (s[i] == APOSTROPHE_CHAR) {
         if (i > 0 && isalnum(s[i-1]))
            result += s[i];
      } else if (s[i] == HYPHEN_CHAR) {
         if (i > 0 && i < (length-1) && isalnum(s[i-1]) && isalnum(s[i+1]))
            result += s[i];
			// If a word ends in a hyphen, we assume it is residue that needs to
			// be paired with the next word. Return the word with the hyphen as a
			// signal to the caller to retain it as residue.
         else if (i > 0 && i == (length-1) && isalnum(s[i-1]))
            result += s[i];
      }
   }
   return result;
}

void removeCommonWords(WordCounter &wc) {
   for (string &s : CommonWordList::getWords())
      wc.removeWord(s);
}
