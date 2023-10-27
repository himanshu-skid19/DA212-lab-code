#include <iostream>
#include "binary_search_tree.h"
#include "task3.h"
#include <stack>

using namespace std;


void run(){

    cout << "WARNING: It might take a very long time for a specific algorithm to sort an array so be on a lookout for that.\n";
    int input = -1;
    int r;
    cout << "Enter the value of the root node: \n";
    cin >> r;
    BST t(r);
    ExpressionTree E;
    Node_* root = nullptr;
    while (input != 15){
		cout << "Enter 1 to insert a node in the BST \n";
		cout << "Enter 2 to get the number of nodes in BST \n";
		cout << "Enter 3 to do inorder traversal of the BST \n";
		cout << "Enter 4 to do preorder traversal of the BST \n";
		cout << "Enter 5 to do postorder traversal of the BST \n";
		cout << "Enter 6 to search for an element in the BST \n";
		cout << "Enter 7 to find the minimum element in the BST'\n";
        cout << "Enter 8 to find the maximum element in the BST'\n";
        cout << "Enter 9 to find the parent of an element in the BST'\n";
        cout << "Enter 10 to find the successor of an element in the BST'\n";
        cout << "Enter 11 to delete an element in the BST'\n";
        cout << "Enter 12 to construct an expression tree'\n";
        cout << "Enter 13 to evaluate the expression tree\n";
        cout << "Enter 14 to print the expression tree in infix notation'\n";
		cout << "Enter 15 to exit the program\n";

		cin >> input;
		switch (input){

            case 1:
                int val;
                cout << "Enter the value: \n";
                cin >> val;
                t.insert(val);
                break;

            case 2:
                cout << t.get_num_nodes() << endl;
                break;
            case 3:
                t.do_inorder();
                break;
            case 4:
                t.do_preorder();
                break;
            case 5:
                t.do_postorder();
                break;
            case 6:
                int v;
                cout << "Enter the value to be searched: \n";
                cin >> v;
                cout << t.search(v)->data << endl;
                break;
            case 7:
                cout << t.min_of_root() << endl;
                break;
            case 8:
                cout << t.max_of_root() << endl;
                break;

            case 9:
                int c;
                cout << "Enter the value of the node you want to find the parent of: \n";
                cin >> c;
                if (c == r){
                    cout << "that is the root node which has has no parent\n";
                    break;
                }

                cout << t.find_parent(c)->data << endl;
                break;

            case 10:
                int s;
                cout << "Enter the value of the node you want to find the successor of: \n";
                cin >> s;
                cout << t.successor(s)->data << endl;
                break;

            case 11:
                int d;
                cout << "Enter the value of the node you want to delete: \n";
                cin >> d;
                t.delete_node(d);
                break;

            case 12:{
                string postfix;
                cout << "Enter the postfix expression: \n";
                cin.ignore();
                getline(cin, postfix);
                root = E.generate(postfix);

                break;
            }
            case 13:
                cout << E.evaluate_tree(root) << endl;
                break;

            case 14:
                E.inorder(root);
                cout << endl;
                break;

		}

    }


}
