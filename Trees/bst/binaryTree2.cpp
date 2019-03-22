#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

typedef struct BinaryTreeNode Node;

Node* treeMax(Node* head)
{
    while(head->right != NULL)
        head=head->right;
    return head;
}

Node* treeMin(Node* head)
{
    while(head->left != NULL)
        head=head->left;
    return head;
}


void insertNode(Node* head, Node* in)
{
    if(head==NULL) //if head does not exist
        return;

    if(in->data < head->data)
    {
        if(head->left != NULL)
            insertNode(head->left, in);
        else
            head->left=in;
    }
    else if(in->data > head->data)
    {
        if(head->right != NULL)
            insertNode(head->right, in);
        else
            head->right=in;
    }
    else
        return;

}


void printTree(Node* head)
{
    if(head==NULL)
        return;
/*
    pre order traversal to print all data in sorted order
*/

    printTree(head->left);
    cout<<head->data<<" ";
    printTree(head->right);

}


void init(Node* head)
{
    cout<<"please enter value at this new node"<<endl;
    cin>>head->data;
    head->left=NULL;
    head->right=NULL;

}



void deleteNode(Node * & head, const int & x )
{
    if(head==NULL) //node does not exist
        return;
    if(x < head->data)
        deleteNode(head->left, x);
    else if(x > head->data)
        deleteNode(head->right, x);
    else if(head->left != NULL && head->right != NULL) //case of two children
    {
        head->data = treeMin(head->right)->data;
        deleteNode(head->right, head->data); //recursively call function to delete the node from which we copied the data
    }
    else //basically the idea is to keep doing above method until we get to only one child or no child
    {
        Node* tmp = head;
        head = (head->left != NULL)?(head->left):(head->right);
        delete tmp;
    }
}


bool bstSearch(Node* root, const int cmp)
{
    if(root==NULL)
        return false;

/*
        We use the method in which we constructed binary tree to find the element
        this searching operation gives a bool value of 1 or 0
        Time complexity is O(log(n))
*/

    if(cmp < root->data)
        return bstSearch(root->left, cmp);
    else if(cmp > root->data)
        return bstSearch(root->right, cmp);
    else
        return true;
}


void bstDestroy(Node* & head)
{
    if(head == NULL)
        return;

/*
            We will use post order traversal to delete the entire tree
*/

    bstDestroy(head->left);
    bstDestroy(head->right);
    delete head;
}



int main()
{
    Node* root = new Node; //Initialise root
    init(root);
/*
    Comment back in to debug


    //if(root->left==NULL) cout<<"yes!"<<endl;
    //if(root->right==NULL) cout<<"yes!"<<endl;


*/
    while(1)
    {
        int choice;
        cin>>choice;
        if(choice == 1) //Insert new node into the tree
        {
            Node* someNode = new Node;
            init(someNode);
            insertNode(root, someNode);
        }
        else if(choice == 2) //Delete a node
        {
            int comp;
            cin>>comp;
            deleteNode(root, comp);
        }
        else if(choice == 3) //search for an element
        {
            int cmp;
            cin>>cmp;
            cout<<bstSearch(root, cmp)<<endl;
        }
        else if(choice == 4) //destroy the tree
        {
            cout<<"You have chosen to destroy the tree and must create another root to continue"<<endl;
            bstDestroy(root);
            Node* root = new Node;
            init(root);
        }
        printTree(root);
        cout<<endl;
    }


}
