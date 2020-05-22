#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool match(const string& input, int p, const string& word) {
    if (p + word.length() > input.length()) {
	return false;
    }
    for (int i = 0; i < word.length(); i++) {
	char c1 = input[p + i];
	char c2 = word[i];
	if (c1 != c2 && !(c1 == ' ' && c2 == 'e')) {
	    return false;
	}
    }
    return true;
}

void search(const string& input, vector<string>& dict,
	    const string& output, vector<string>* results) {
    if (output.length() == input.length()) {
	results->push_back(output);
	return;
    }

    for (const string& word: dict) {
	if (match(input, output.length(), word)) {
	  search(input, dict, output + word, results);
	}
    }
}
int main() {
    string input = "I lik   to   xplor   univ rs ";
    string _dict[] = {"I", "like", "explore", "toe", "universe", "rse", "to", "xplor"};
    int dict_len = sizeof(_dict) / sizeof(_dict[0]);
    
    vector<string> dict;
    for (int i = 0; i < dict_len; i++) {
	dict.push_back(_dict[i]);
    }
    dict.push_back(" ");
    vector<string> results;
    search(input, dict, string(""), &results);
    for (const string& result: results) {
	cout<<result<<endl;
    }

    return 0;
    
}

