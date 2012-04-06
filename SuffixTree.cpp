#include "SuffixTree.h"

using namespace std;

/*SuffixTree::SuffixTree() {
	// TODO Auto-generated constructor stub

}

SuffixTree::~SuffixTree() {
	// TODO Auto-generated destructor stub
}*/

Node* SuffixTree::getRoot() {
	return root;
}

void SuffixTree::setRoot(Node* r) {
	root = r;
}

Node* SuffixTree::createFirstChild(string content, Node* root) {
	Node* child = new Node();
	child->setIdxStart(0);
	child->setIdxEnd(content.length() + 1);
	child->setParent(root);

	return child;
}

int SuffixTree::buildTree(string content, string sentinel) {
	root = new Node();
	Node* child = SuffixTree::createFirstChild(content, root);
	root->addChild(child);

	Node* u;
	Node* v;
	for (int i = 0; i < (int) content.length(); i++) {
	  
	}
	return 0;
}

string SuffixTree::search(string searchString) {
	return "";
}
