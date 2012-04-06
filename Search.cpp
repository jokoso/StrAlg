#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include "SuffixTree.h"

using namespace std;

int main(int argc, char *argv[]) {
//	string filename = argv[0];
//	string searchString = argv[1];
	string sentinel = "$";
        string content = "mississippi" + sentinel;
	

/*	ifstream file(filename);
	if (file.is_open()) {
		string tmp;
		while (file.good()) {
			getline(file, tmp);
			content << tmp;
		}
	}*/
	std::cout << content << endl;
	std::cout << content.length() << endl;
	SuffixTree* suffixTree = new SuffixTree();
	if (!content.empty()) {
		suffixTree->buildTree(content, sentinel);
	}
	Node* child = suffixTree->getRoot()->getChildren()[0];
	int startIdx = child->getIdxStart();
	int endIdx = child->getIdxEnd();
	std::cout << startIdx << " : " << endIdx << endl;
	return 0;
}
