#ifndef NODE_H_
#define NODE_H_

#include <vector>

class Node {
private:
	Node* suffixLink;
	Node* parent;
	std::vector<Node*> children;
	int idxStart;
	int idxEnd;

public:
	Node* getSuffixLink();
	Node* getParent();
	void setParent(Node* parent);

	std::vector<Node*> getChildren();
	void addChild(Node* child);
	int getIdxStart();
	int getIdxEnd();
	void setIdxStart(int idx);
	void setIdxEnd(int idx);
};

#endif /* NODE_H_ */
