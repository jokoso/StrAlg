#ifndef SUFFIXTREE_H_
#define SUFFIXTREE_H_

#include <string>
#include "Node.h"

class SuffixTree {
private:
	std::string content;
	Node* root;

public:
	Node* getRoot();
	void setRoot(Node* r);

	int buildTree(std::string content, std::string sentinel);

	std::string search(std::string searchString);

	Node* createFirstChild(std::string content, Node* root);
};

#endif /* SUFFIXTREE_H_ */
