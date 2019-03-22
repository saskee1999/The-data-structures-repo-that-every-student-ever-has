#include<iostream>
#include"avl.hpp"
/**
 * This is an implementatation of AVL trees. It was also partialy an attempt
 * to write well documented and professional-ish code
 * I will do my best to explain what is happening
 * I have only used 1 header file because i am not very good at modularisation yet and i thought
 * i just wanted one header to import and nothing else. I thought this would be more
 * convinient.
 * 
 * 
 * 
 * AVL Trees are trees are binary search trees that maintain a certain property. This property
 * is that the left and right sub-trees should not have a height difference greater than two.
 * It achieves this by repeatedly self balancing itself whenever it vioaltes that property.
 **/



using namespace avl; //namespace created in header to group all avl operations


void printTree(avlNode* head) //standard printing of binary search trees. In-order traversal
{
    if(head == NULL)
        return;

    printTree(head->left);
    std::cout<<head->data<<" ";
    printTree(head->right);
}

int main()
{
    avlNode* root = new avlNode; //Initialising a root node. Although it is not needed, avlInsert works just fine.
    avlInit(root); //An init function meant to be used for debugging. 
    for(int i=0;i<10;i++)
    {
        int val;
        std::cin>>val;
        avlInsert(val, root); //Insert node into tree
    }
    printTree(root); //print tree in order after all insertions are done
}
