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
	root->setSuffixLink(root);

	Node* u;
	//	Node* v;
	int vStart; //since v is a label I have used the start and end idx in content
	int vEnd; //this defines to label
	std::vector<Node*> head1(content.length(), 0);
	for (int i = 0; i < (int) content.length(); i++) {
	  // first get u
	  if(head[i] == 0) {
	    u = 0;
	    vStart = 0;
		vEnd = 0;
	  }
	  else {
	    u = head[i]->getParent();
		vStart = u->getIdxEnd();
		vEnd = head[i]->getIdxEnd(); //label(u, head(i)) / the label on the edge from u to head
	  }
	  Node* w;
	  if(u != 0) {
	    w = fastScan(u->getSuffixLink(), vStart, vEnd);
	  }
	  else {
	    w = new Node();
		w->setIdxStart(i+1);
		w->setIdxEnd(content.length());
		head[i+1] = w;
	  
	  }
	}  
	return 0;
}

string SuffixTree::search(string searchString) {
	return "";
}

//fastscan(s(u), v) v is the label from u to head[i]
//
Node* SuffixTree::fastScan(Node* suffixLink, int startIdx, int endIdx) {
    
  std::vector<Node*> children = suffixLink->getChildren();
  for(int i = 0; i < (int) children.size(); i++) {
	//if startIdx matches the first char in one of the children, we call fastscan 
	//on this child
	string vChar = content.substr(startIdx, 1);
	string childChar = content.substr(children[i]->getIdxStart());
	if(vChar.compare(childChar) == 0) {
	  //do we need another if statement - one for equality, this returns children[i]. One for gt this returns children[i]->getParent() ??
	  //might need to go over an example to figure this out! look at the slides!
	  if(endIdx =< children[i]->getIdxEnd()) {
		return children[i];
	  }
	  else {
		return fastScan(children[i], startIdx+1, endIdx);
	  }
	}
  }
  return 0;
}
	
/*
scan all children of w. check for each child if their edge matches tail. If one 
is found, return this child. else return 0
 */
Node* SuffixTree::slowScan(Node* w, std::string tail) {
  std::vector<Node*> children = w->getChildren();
  for(int i = 0; i < (int) children.size(); i++) {
	int startIdx = children[i]->getIdxStart();
	//	int endIdx = children[i]->getIdxEnd();
	int check = 0;
	for(int j = 0; j < (int) tail.length(); j++) {
      /*if(tail > (endIdx - startIdx) {
		 return slowScan(children[i], tail.substr((endIdx - startIdx),tail.length()));
	  }
	  else*/  //does not occur, since we will allways have this edge when
	  //we slowscan.... right?
	  if(tail.compare(content.substr(startIdx+j,1)) == 0) {
		check++;
	  }
	  else {
		break; //look at the next child
	  }
	}
	if(check == ((int)tail.length())) {
	  return children[i];
	}
  }
  return 0;
}
