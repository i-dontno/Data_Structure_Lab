#include <bits/stdc++.h>
using namespace std;

struct TrieNode {

	// pointer array for child nodes of each node
	TrieNode* childNode[26];
	int wordCount;

	TrieNode()
	{
		// constructor
		// initialize the wordCnt variable with 0
		// initialize every index of childNode array with
		// NULL
		wordCount = 0;
		for (int i = 0; i < 26; i++) {
			childNode[i] = NULL;
		}
	}
};

void insert_key(TrieNode* root, string& key)
{
	// Initialize the currentNode pointer
	// with the root node
	TrieNode* currentNode = root;

	// Iterate across the length of the string
	for (auto c : key) {

		// Check if the node exist for the current
		// character in the Trie.
		if (currentNode->childNode == NULL) {

			// If node for current character does not exist
			// then make a new node
			TrieNode* newNode = new TrieNode();

			// Keep the reference for the newly created
			// node.
			currentNode->childNode = newNode;
		}

		// Now, move the current node pointer to the newly
		// created node.
		currentNode = currentNode->childNode;
	}

	// Increment the wordEndCount for the last currentNode
	// pointer this implies that there is a string ending at
	// currentNode.
	currentNode->wordCount++;
}

bool search_key(TrieNode* root, string& key)
{
	// Initialize the currentNode pointer
	// with the root node
	TrieNode* currentNode = root;

	// Iterate across the length of the string
	for (auto c : key) {

		// Check if the node exist for the current
		// character in the Trie.
		if (currentNode->childNode == NULL) {

			// Given word does not exist in Trie
			return false;
		}

		// Move the currentNode pointer to the already
		// existing node for current character.
		currentNode = currentNode->childNode;
	}

	return (currentNode->wordCount > 0);
}

bool delete_key(TrieNode* root, string& word)
{
	TrieNode* currentNode = root;
	TrieNode* lastBranchNode = NULL;
	char lastBrachChar = 'a';

	for (auto c : word) {
		if (currentNode->childNode == NULL) {
			return false;
		}
		else {
			int count = 0;
			for (int i = 0; i < 26; i++) {
				if (currentNode->childNode[i] != NULL)
					count++;
			}

			if (count > 1) {
				lastBranchNode = currentNode;
				lastBrachChar = c;
			}
			currentNode = currentNode->childNode;
		}
	}

	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (currentNode->childNode[i] != NULL)
			count++;
	}

	// Case 1: The deleted word is a prefix of other words
	// in Trie.
	if (count > 0) {
		currentNode->wordCount--;
		return true;
	}

	// Case 2: The deleted word shares a common prefix with
	// other words in Trie.
	if (lastBranchNode != NULL) {
		lastBranchNode->childNode[lastBrachChar] = NULL;
		return true;
	}
	// Case 3: The deleted word does not share any common
	// prefix with other words in Trie.
	else {
		root->childNode[word[0]] = NULL;
		return true;
	}
}

// Driver code
int main()
{
	// Make a root node for the Trie
	TrieNode* root = new TrieNode();

	// Stores the strings that we want to insert in the
	// Trie
	vector<string> inputStrings
		= { "and", "ant", "do", "geek", "dad", "ball" };

	// number of insert operations in the Trie
	int n = inputStrings.size();

	for (int i = 0; i < n; i++) {
		insert_key(root, inputStrings[i]);
	}

	// Stores the strings that we want to search in the Trie
	vector<string> searchQueryStrings
		= { "do", "geek", "bat" };

	// number of search operations in the Trie
	int searchQueries = searchQueryStrings.size();

	for (int i = 0; i < searchQueries; i++) {
		cout << "Query String: " << searchQueryStrings[i]
			<< "\n";
		if (search_key(root, searchQueryStrings[i])) {
			// the queryString is present in the Trie
			cout << "The query string is present in the "
					"Trie\n";
		}
		else {
			// the queryString is not present in the Trie
			cout << "The query string is not present in "
					"the Trie\n";
		}
	}

	// stores the strings that we want to delete from the
	// Trie
	vector<string> deleteQueryStrings = { "geek", "tea" };

	// number of delete operations from the Trie
	int deleteQueries = deleteQueryStrings.size();

	for (int i = 0; i < deleteQueries; i++) {
		cout << "Query String: " << deleteQueryStrings[i]
			<< "\n";
		if (delete_key(root, deleteQueryStrings[i])) {
			// The queryString is successfully deleted from
			// the Trie
			cout << "The query string is successfully "
					"deleted\n";
		}
		else {
			// The query string is not present in the Trie
			cout << "The query string is not present in "
					"the Trie\n";
		}
	}

	return 0;
}
