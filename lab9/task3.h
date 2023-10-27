#ifndef TASK3_H
#define TASK3_H
#include <string>
using namespace std;

union Value {
    int data;
    char op;

    Value() : data('\0') {}
    ~Value() {}
};

struct Node_ {
    Value data;
    Node_ *lchild;
    Node_ *rchild;

    Node_() : lchild(nullptr), rchild(nullptr) {}

    ~Node_() {
        if (data.op != '\0') {

        }
    }
};

class ExpressionTree {
    Node_ *root;
    int num_nodes;
public:
    ExpressionTree() : num_nodes(0), root(nullptr) {}

    ExpressionTree(Value data) : num_nodes(1) {
        this->root = new Node_;
    }

    Node_ *initialize_node(Value data);
    int get_num_nodes();
    bool isOperator(char c);
    string evaluate(string a, string b, char o);
    string evaluate_tree(Node_ *root);
    void inorder(struct Node_* root);
    void preorder(struct Node_* root);
    void postorder(struct Node_* root);
    Node_ *generate(string postfix);
};

#endif
