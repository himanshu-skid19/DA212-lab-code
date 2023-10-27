#include <bits/stdc++.h>
#include "task3.h"
#include <stack>

using namespace std;

Node_* ExpressionTree::initialize_node(Value data) {
    if (data.data != -1e8){
        Node_* newnode = new Node_;
        newnode->data.data = data.data;
        newnode->lchild = nullptr;
        newnode->rchild = nullptr;
        return newnode;
    }
    else{
        Node_* newnode = new Node_;
        newnode->data.op = data.op;
        newnode->lchild = nullptr;
        newnode->rchild = nullptr;
        return newnode;
    }
}

bool ExpressionTree::isOperator(char c){
    string op = "+-*/";
    for (int i = 0; i < op.length(); i++){
        if (op[i] == c){
            return 1;
        }
    }
    return 0;
}

Node_* ExpressionTree::generate(string postfix){
    stack<Node_*> s;
    for (int i = 0; i < postfix.length(); i++){
        Value d;
        d.op = postfix[i];

        if (isOperator(postfix[i]) == 0){
                Node_* newnode = new Node_;
                newnode->data.op = d.op;
                newnode->lchild = nullptr;
                newnode->rchild = nullptr;

                s.push(newnode);

        }
        else{
            Node_* newnode = new Node_;
            newnode->data.op = d.op;
            if (s.size() >= 2) {
                newnode->rchild = s.top();
                s.pop();
                newnode->lchild = s.top();
                s.pop();
                s.push(newnode);
            }
            else{
                cout << "Error\n";
            }
        }
    }
    return s.top();
}

string ExpressionTree::evaluate(string a, string b, char o) {
    int x = stoi(a);
    int y = stoi(b);
    int res = 0; // Initialize to a character '0'.
    switch (o) {
        case '+':
            res = x + y;
            break;
        case '-':
            res = x - y;
            break;
        case '*':
            res = x * y;
            break;
        case '/':
            if (y != 0) {
                res = x / y;
            }
            break;
    }
    return to_string((res));
}

string ExpressionTree::evaluate_tree(Node_ *root) {
    if (isOperator(root->data.op) == 0) {
        return string(1,root->data.op);
    } else {
        string x = evaluate((evaluate_tree(root->lchild)), (evaluate_tree(root->rchild)), root->data.op);
        return x;
    }
}



void ExpressionTree::inorder(struct Node_* root){
    if (root != nullptr) {
        bool needBrackets = false;

        int currentPrecedence = 0;
        int leftPrecedence = 0;

        if (root->lchild) {
            // Check the precedence of the current operator and its left child
            switch (root->data.op) {
                case '+':
                case '-':
                    currentPrecedence = 1;
                    break;
                case '*':
                case '/':
                    currentPrecedence = 2;
                    break;
            }

            switch (root->lchild->data.op) {
                case '+':
                case '-':
                    leftPrecedence = 1;
                    break;
                case '*':
                case '/':
                    leftPrecedence = 2;
                    break;
            }

            if (currentPrecedence > leftPrecedence) {
                // If the current operator has higher precedence, we need brackets
                needBrackets = true;
            }
        }

        if (needBrackets) {
            cout << "(";
        }

        inorder(root->lchild);
        cout << root->data.op;

        if (root->rchild) {
            // Check the precedence of the current operator and its right child
            int rightPrecedence = 0;

            switch (root->rchild->data.op) {
                case '+':
                case '-':
                    rightPrecedence = 1;
                    break;
                case '*':
                case '/':
                    rightPrecedence = 2;
                    break;
            }

            if (currentPrecedence >= rightPrecedence) {
                // If the current operator has higher or equal precedence, we need brackets
                needBrackets = true;
            }
        }

        inorder(root->rchild);

        if (needBrackets) {
            cout << ")";
        }
    }
}


void ExpressionTree::preorder(struct Node_* root){
    if (root != nullptr){
        cout << root->data.op;
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void ExpressionTree::postorder(struct Node_* root){
    if (root != nullptr){
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->data.op;
    }
}


