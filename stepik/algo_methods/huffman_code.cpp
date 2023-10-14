//https://stepik.org/lesson/13239/step/5?unit=3425

#include<iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>

using namespace std;

pair<string, int> min_freq(unordered_map<string, int> *freq) {
	pair<string, int> min_freq = *(*freq).begin();
	for (auto item : *freq) {
		if (item.second < min_freq.second) {
			min_freq = { item.first, item.second };
		}
	}
	(*freq).erase(min_freq.first);
	return min_freq;
}

void parse_tree (
	unordered_map<string, vector<string>> tree, 
	int deep, 
	string root, 
	string code,
	unordered_map<string, string> *prefix
) {
	if (tree.find(root) == tree.end()) {
		(*prefix)[root] = code;
		return;
	}
	parse_tree(tree, deep + 1, tree[root][0], code + "0", prefix);
	parse_tree(tree, deep + 1, tree[root][1], code + "1", prefix);
}

void haffman_code() {
	string s;
	cin >> s;

	unordered_map<string, int> freq;
	for (auto ch : s) {
		string key = "";
		freq[key + ch]++;
	}
	int size = freq.size();

	unordered_map<string, vector<string>> tree;
	while (freq.size() > 1) {
		auto temp_1 = min_freq(&freq);
		auto temp_2 = min_freq(&freq);
		freq[temp_1.first + temp_2.first] = temp_1.second + temp_2.second;
		tree[temp_1.first + temp_2.first] = { temp_1.first, temp_2.first };
	}
	
	auto temp = min_freq(&freq);
	unordered_map<string, string> prefix;
	if (size == 1) {
		prefix[temp.first] = "0";
	}
	else {
		parse_tree(tree, 0, temp.first, "", &prefix);
	}

	string res = "";
	for (auto ch : s) {
		string letter = "";
		res += prefix[letter + ch];
	}
	
	cout << size << " " << res.size() << endl;
	for (auto item : prefix) {
		cout << item.first << ": " << item.second << endl;
	}
	cout << res << endl;
}

int main() {
	haffman_code();
	return 0;
}