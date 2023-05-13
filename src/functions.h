#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct  Node Node;
struct Node {
	int  value;
	Tree *right;
    Tree *left;
};

Node* newNode (int value);

#endif