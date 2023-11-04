// Trace the code that performs a certain traversal on a tree

#include <iostream> 
#include <queue> 

template <typename T> 
struct TreeNode
{
    T value; 
    TreeNode* left; 
    TreeNode* right; 

    TreeNode(T val) : value(val), left(nullptr), right(nullptr) { }
};

template<typename T> 
void preorder(TreeNode<T>* node)
{
    if(node != nullptr)
    {
        std::cout << node->value << " "; // prints 1 
        if(node->left != nullptr)
            preorder(node->left); // moves through entire left sub tree 2 4 5
        if(node->right != nullptr)
            preorder(node->right); // moves through entire right sub tree 3
    }
}

template<typename T> 
void postorder(TreeNode<T>* node)
{
    if(node != nullptr)
    {
        postorder(node->left); // prints 4 5 2
        postorder(node->right); // prints 3
        std::cout << node->value << " "; // prints 1 
    }
}

template<typename T> 
void inorder(TreeNode<T>* node)
{
    if(node != nullptr)
    {
        inorder(node->left); // prints 4 5
        std::cout << node->value << " "; // prints 2 1
        inorder(node->right); // prints 3
    }
}

template<typename T> 
void levelorder(TreeNode<T>* root)
{
    std::queue<TreeNode<T>*> q; 
    q.push(root); 

    while(!q.empty())
    {
        TreeNode<T>* current = q.front(); 
        q.pop(); 
        std::cout << current->value << " "; // prints 1

        if(current->left != nullptr)
            q.push(current->left); // prints 2 3
        if(current->right != nullptr)
            q.push(current->right); // prints 4 5
    }
}
int main(int argc, char const *argv[])
{
    TreeNode<int>* root = new TreeNode<int>(1); 
    root->left = new TreeNode<int>(2); 
    root->right = new TreeNode<int>(3); 
    root->left->left = new TreeNode<int>(4); 
    root->left->right = new TreeNode<int>(5); 

    // Preorder Traversal
    std::cout << "Preorder traversal: ";
    preorder(root);
    std::cout << std::endl;

    // Inorder Traversal
    std::cout << "Inorder traversal: ";
    inorder(root);
    std::cout << std::endl;

    // Level Order Traversal
    std::cout << "Level order traversal: ";
    levelorder(root);
    std::cout << std::endl;

    // Postorder Traversal
    std::cout << "Postorder traversal: ";
    postorder(root);
    std::cout << std::endl;

    return 0;
}