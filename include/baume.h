#ifndef FUNCTIONS
#define FUNCTIONS

#ifdef BUILDING
    #define PUBLIC __attribute__((visibility ("default")))
#else
    #define PUBLIC
#endif

typedef struct Node Node;
struct Node {
	int  value;
	Node *right;
    Node *left;
};

PUBLIC Node *nodeNew(int value);
PUBLIC void nodeDelete(Node **node);

PUBLIC Node *preorder(int);

#endif
