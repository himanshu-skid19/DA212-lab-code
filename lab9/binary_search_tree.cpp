#include <bits/stdc++.h>
#include "binary_search_tree.h"
#include <string>

using namespace std;

        Node *BST::initialize_node(int data){
			Node *newnode = new Node;
			newnode->data = data;
			newnode->lchild = NULL;
			newnode->rchild = NULL;
			return newnode;
		}

		int BST::get_num_nodes(){
			return num_nodes;
		}

		void  BST::insert(int data){
			Node *newnode = initialize_node(data);
			Node *x = root;
			Node *y = NULL;
			int ctr = -1;
			while (x != NULL){
				y = x;
				if (data < x->data){
					ctr = 0;
					x = x->lchild;

				}

				else{
					ctr = 1;
					x = x->rchild;
				}
			}

			if (ctr == 0){
				y->lchild = newnode;
			}
			else{
				y->rchild = newnode;

			}
			num_nodes++;


		}

		void BST::inorder(struct Node* root){
			if (root != NULL){
				inorder(root->lchild);
				cout << root->data << ", ";
				inorder(root->rchild);
			}
		}

		void BST::do_inorder(){
			inorder(root);
		}


		void BST::preorder(struct Node* root){
			if (root != NULL){
				cout << root->data << ", ";
				preorder(root->lchild);
				preorder(root->rchild);
			}
		}

		void BST::do_preorder(){
			preorder(root);
		}

		void BST::postorder(struct Node* root){
			if (root != NULL){
				postorder(root->lchild);
				postorder(root->rchild);
				cout << root->data << ", ";
			}
		}

		void BST::do_postorder(){
			postorder(root);
		}

		Node *BST::search(int data){
			Node *curr = root;
			while ((curr != NULL) && (curr->data != data)){
				if (data < curr->data){
					curr = curr->lchild;
				}
				else{
					curr = curr->rchild;
				}

			}

			return curr;
		}

		Node* BST::minimum(Node *root){
			Node *curr = root;
			while (curr->lchild !=NULL){
				curr = curr->lchild;
			}
			return curr;
		}
		int BST::min_of_root(){
			return minimum(root)->data;
		}

		Node* BST::maximum(Node *root){
			Node *curr = root;
			while (curr->rchild !=NULL){
				curr = curr->rchild;
			}
			return curr;
		}

		int BST::max_of_root(){
			return maximum(root)->data;
		}

		Node *BST::find_parent(int data){
			Node *curr = root;
			Node *prev = NULL;


			while ((curr != NULL) && (curr->data != data)){
				prev = curr;
				if (data < curr->data){
					curr = curr->lchild;
				}
				else{
					curr = curr->rchild;
				}


			}
			return prev;
		}

		Node *BST::successor(int data){
			Node *curr = search(data);
			if (curr->rchild != NULL){
				return minimum(curr->rchild);
			}
			else{
				Node *succ = find_parent(data);
				while (succ != NULL && curr == succ->rchild){
					curr = succ;
					succ = find_parent(succ->data);

				}
				return succ;
			}
		}

		void BST::delete_leaf(int data, Node *curr){
			Node *parent = find_parent(data);

				if (parent == nullptr){
					if (curr->lchild == nullptr && curr->rchild == nullptr) {
						delete curr;
						root = nullptr;
					}
				}

				else if (parent->lchild == curr){
					parent->lchild = nullptr;
					delete curr;
				}
				else{
					parent->rchild = nullptr;
					delete curr;
				}
		}

		void BST::delete_with_one_child(int data, Node *curr){

			Node *parent = find_parent(data);

				if (parent == nullptr){
					if (curr->lchild == nullptr && curr->rchild == nullptr) {
						delete curr;
						root = nullptr;
					}
				}

				else if (parent->lchild == curr){
					if (curr->rchild != nullptr){
						parent->lchild = curr->rchild;
						delete curr;
					}
					else{
						parent->lchild = curr->lchild;
						delete curr;
					}

				}
				else{

					if (curr->rchild != nullptr){
						parent->rchild = curr->rchild;
						delete curr;
					}
					else{
						parent->rchild = curr->lchild;
						delete curr;
					}

				}
			}

		void BST::delete_with_2_child(int data, Node *curr){
			Node *succ = successor(data);
			Node *parent = find_parent(succ->data);

			if (parent != curr){
				parent->lchild = succ->rchild;
			}
			else{
				curr->rchild = succ->rchild;
			}
			curr->data = succ->data;
			delete succ;


		}

		void BST::delete_node(int data){
			Node *curr = search(data);
			num_nodes--;
			 if (curr == nullptr) {
			// Node not found in the tree
				return;
			}

			if ((curr->lchild == NULL) && (curr->rchild == NULL)){
				delete_leaf(data, curr);

			}

			else if ((curr->lchild != nullptr) && (curr->rchild != nullptr)){
				delete_with_2_child(data, curr);
			}

			else{
				delete_with_one_child(data, curr);

			}
		}

