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

PUBLIC Node *tree_search_node(const Node *const tree, const Node *const node);

PUBLIC Node *nodeNew(int value);
PUBLIC void nodeDelete(Node **node);

PUBLIC void postorder(const Node *const root);
PUBLIC void inorder (Node *tree);
PUBLIC Node *preorder(int);

#endif
