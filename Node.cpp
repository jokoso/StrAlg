#include "Node.h"

using namespace std;

/*Node::Node() {
	// TODO Auto-generated constructor stub
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}*/

Node* Node::getSuffixLink() {
	return suffixLink;
}

void Node::setSuffixLink(Node* link) {
  suffixLink = link;
}

Node* Node::getParent() {
	return parent;
}

void Node::setParent(Node* p) {
	parent = p;
}

vector<Node*> Node::getChildren() {
	return children;
}

void Node::addChild(Node* child) {
	children.push_back(child);
}

int Node::getIdxStart() {
	return idxStart;
}

int Node::getIdxEnd() {
	return idxEnd;
}

void Node::setIdxStart(int idx) {
	idxStart = idx;
}

void Node::setIdxEnd(int idx) {
	idxEnd = idx;
}
