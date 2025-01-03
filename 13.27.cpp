//
// Created by donsimon on 1/1/25.
//
#include<vector>
#include<iostream>

class TreeNode {
public:
    std::string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const std::string& val = "") : value(val), left(nullptr), right(nullptr) {}

    TreeNode(const TreeNode& other) : value(other.value), left(nullptr), right(nullptr) {
        if (other.left) {
            left = new TreeNode(*other.left);
        }
        if (other.right) {
            right = new TreeNode(*other.right);
        }
    }

    TreeNode& operator=(const TreeNode& other) {
        if (this != &other) {
            value = other.value;
            delete left;
            delete right;
            left = right = nullptr;
            if (other.left) {
                left = new TreeNode(*other.left);
            };
            if (other.right) {
                right = new TreeNode(*other.right);
            };
        }
        return *this;
    }

    ~TreeNode() {
        delete left;
        delete right;
    }
};

class BinStrTree {
private:
    TreeNode* root;
    int count;

    TreeNode* copySubtree(const TreeNode* otherRoot) {
        if (!otherRoot) {
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(otherRoot->value);
        newNode->left = copySubtree(otherRoot->left);
        newNode->right = copySubtree(otherRoot->right);
        return newNode;
    }

    void deleteSubtree(TreeNode* node) {
        if (node) {
            deleteSubtree(node->left);
            deleteSubtree(node->right);
            delete node;
        }
    }

public:
    BinStrTree() : root(nullptr), count(0) {}

    BinStrTree(const BinStrTree& other) : root(nullptr), count(other.count) {
        root = copySubtree(other.root);
    }
    BinStrTree& operator=(const BinStrTree& other) {
        if (this != &other) {
            deleteSubtree(root);
            root = copySubtree(other.root);
            count = other.count;
        }
        return *this;
    }
    ~BinStrTree() {
        deleteSubtree(root);
    }
};
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0){*use=1;}
    HasPtr(const HasPtr& ptr) {
        this->i=i;
        this->ps=ptr.ps;
        ++*use;
    }
    HasPtr operator=(const HasPtr& ptr) {
        this->i=i;
        this->ps=ptr.ps;
        this->use=ptr.use;
        ++*use;

        return *this;
    }
    ~HasPtr () {
        delete(ps);
        delete(use);
    }
    std::string *ps;
private:
    int *use=new int;
    int i;
};