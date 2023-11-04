#include <iostream> 

PositionList inorder() 
{
    PositionList pl; 
    inorder(_root, pl);
    return PositionList(pl); 
}
void inorder(PositionList pl, Node* v)
{
    if(v != nullptr)
    {
        inorder(v->left, pl); 
        std::cout << v->value << " "; 
        inorder(v->right, pl); 
    }
}