#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct Node Node;
struct Node {
	int  value;
	Node *right;
    Node *left;
};

Node *newNode(int value);

Node *preorder(int);

#endif
