#ifndef FUNCTIONS
#define FUNCTIONS

#ifdef BUILDING
    #define PUBLIC __attribute__((visibility ("default")))
#else
    #define PUBLIC
#endif

typedef struct NodeAVL NodeAVL;
struct NodeAVL {
	int value;
    int fe;
    int height;
	NodeAVL *right;
    NodeAVL *left;
};

PUBLIC NodeAVL *avlInsertNode(NodeAVL **tree, NodeAVL *node);
PUBLIC NodeAVL *tree_search_node(const NodeAVL *const tree, const NodeAVL *const node);
PUBLIC void tree_print(const NodeAVL *const tree);
PUBLIC NodeAVL *tree_extract_node(NodeAVL **const tree,
        const NodeAVL *const node);
PUBLIC int tree_height(struct NodeAVL* node);
PUBLIC int fe(NodeAVL *node);

PUBLIC NodeAVL  *nodeNewAVL(int value);
PUBLIC void     avlNodeDelete(NodeAVL **node);
PUBLIC NodeAVL *RotationLeft(NodeAVL *node);
PUBLIC NodeAVL *RotationRight(NodeAVL *node);


PUBLIC void inorder (NodeAVL *tree);
PUBLIC void postorder(const NodeAVL *const root);
PUBLIC void preorder(const NodeAVL *const root);

#endif
