#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct Node Node;
struct Node {
	int  value;
	Node *right;
    Node *left;
};

Node *nodeNew(int value);
void nodeDelete(Node **node);

Node *preorder(int *, int);

#endif
