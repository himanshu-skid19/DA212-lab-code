#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <string>

struct Node{
	int data;
	Node *lchild;
	Node *rchild;

};


class BST{
    Node *root;
	int num_nodes;
    public:
        BST(int data){
		root = new Node;
		root->data = data;
		root->lchild = nullptr;
		root->rchild = nullptr;
		this->num_nodes = 1;
		}

		Node *initialize_node(int data);
        int get_num_nodes();
        void insert(int data);
        void inorder(struct Node* root);
        void do_inorder();
        void preorder(struct Node* root);
        void do_preorder();
        void postorder(struct Node* root);
        void do_postorder();
        Node *search(int data);
        Node* minimum(Node *root);
        int min_of_root();
        Node* maximum(Node *root);
        int max_of_root();
        Node *find_parent(int data);
        Node *successor(int data);
        void delete_leaf(int data, Node *curr);
        void delete_with_one_child(int data, Node *curr);
        void delete_with_2_child(int data, Node *curr);
        void delete_node(int data);


};

#endif
