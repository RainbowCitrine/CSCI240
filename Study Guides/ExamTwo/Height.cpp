#include <iostream>
#include <algorithm>

template <typename T> 
struct TreeNode 
{
    T val; 
    TreeNode* left; 
    TreeNode* right; 

    TreeNode(T v) : val(v), left(nullptr), right(nullptr) { }
};

template <typename T> 
int getHeight(TreeNode<T>* root)
{
    if(root == nullptr) return -1; 
    
    int leftHeight = getHeight(root->left); 
    int rightHeight = getHeight(root->right); 
    
    return 1 + std::max(leftHeight, rightHeight);

    // O(n) where "n" is the number of nodes within the tree
}   

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1); 
    root->left = new TreeNode<int>(2); 
    root->right = new TreeNode<int>(3); 
    root->left->left = new TreeNode<int>(4); 
    root->left->right = new TreeNode<int>(5); 

    int height = getHeight(root); 
    std::cout << "Height: " << height; 
}