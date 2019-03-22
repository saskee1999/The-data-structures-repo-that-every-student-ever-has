#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED //protecting against multiple includes although not really needed in this case. 
#include<iostream>
#define max(x, y) ((x>y)?(x):(y))  //macro function to find max

/**
 * Please comment and tell what all i could optimise. I am following a book called
 * Data structures in c++ by Mark allen Weiss.
 * A lot of the code here regarding rotations
 * and insertion is completely taken from it. I have just 
 * implented it for a better understanding for myself and others. 
 **/



namespace avl
{
    //structure definition
    struct avlNode
    {
        int data;
        struct avlNode* left;
        struct avlNode* right;
        int height;
    };

    typedef struct avlNode avlNode; //line not needed but force of habit from C programming.

    void avlInit(avlNode* & head) //debugging function, not meant to be part of final release. 
    {
        head->left=NULL;
        head->right=NULL;
        std::cin>>head->data;
    }

    /**
     * Although i don't think the following height function is really neccesarry because
     * all its acting like is a glorified getter function, it does help in abstracting 
     * what exactly is happening. So i think the definition might just justified for the mental
     * convinence of it all. 
     **/ 
    int height(avlNode* & head) 
    {
        return (head==NULL)?-1:head->height;
    }

    /**
     *  ROTATE WITH LEFT CHILD
     * 
     *        k2
     *       /  \
     *      k1   A
     *     /  \
     *    B     C
     *   /
     *  D
     * 
     *  BECOMES
     * 
     *        k1
     *       /  \
     *      B   k2
     *     /   /  \ 
     *    D   C     A
     **/

    void rotateWithLeftChild(avlNode* & k2)
    {
        avlNode* k1= k2->left;
        k2->left=k1->right;
        k1->right=k2;
        k2->height = max(height(k2->left), height(k2->right)) +1 ;
        k1->height=max(height(k1->left), k2->height)+1;
        k2=k1;
    }

    //case of right child is symmetrical

    void rotateWithRightChild(avlNode* &k2)
    {
        avlNode* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right))+1;
        k1->height = max(height(k2), height(k1->right))+1;
        k2=k1;
    }

    /**
     *  DOUBLE ROTATE WITH LEFT CHILD
     *                k3
     *              /    \
     *            k2       A
     *           /  \
     *          B    k1
     *              /  \
     *             D     C
     *  BECOMES
     *                 k1
     *              /      \
     *            k2         k3
     *           /  \       /   \
     *         B     D    C      A
     * 
     * 
     * The above change is equivalent to performaing a right rotation on k2
     * then a left rotation on k3
     * This is exactly what the code looks like also.
     * 
     **/

    void doubleWithLeftChild(avlNode* & k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    //case of right child is symmetrical

    void doubleWithRightChild(avlNode* & k3)
    {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    //main insert function

    void avlInsert(const int & val, avlNode* & in) //its important to pass the node by refrence
    {
        if(in==NULL)  
        {
            in = new avlNode; //since node has been passed by refrence we may allocate memory dynamically from inside the func
            in->data=val;
            in->right=NULL;
            in->left=NULL;
        }
        else if(val < in->data) //if the val to insert is less call recursively on left node
        {
            avlInsert(val, in->left); //call recursively until first base case is reached where node == Null
            if(height(in->left)-height(in->right) == 2) //in case tree is unbalnced, balance it
                if(val < in->left->data) //if i have inserted it to the left of left then single rotate
                    rotateWithLeftChild(in);
                else                     //otherwise double ie rotateright(left) + rotateleft(current)
                    doubleWithLeftChild(in);
        }
        else if(val > in->data) //same if right
        {
            avlInsert(val, in->right);
            if(height(in->right) - height(in->left) == 2)
                if(val > in->right->data)
                    rotateWithRightChild(in);
                else
                    doubleWithRightChild(in);
        }
        in->height=max(height(in->left), height(in->right))+1; //this line gets executed eveytime func is called
        //so height is constantly updated.
    }
}




#endif // AVL_H_INCLUDED
