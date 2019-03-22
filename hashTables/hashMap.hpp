#include<iostream>
#include<string>
#define get_index (hashCode(key)%tableSize+tableSize)%tableSize
using namespace std;
template<typename K , typename V> 

struct hashNode
{
    K key;
    V val;
    hashNode *next =NULL;

    hashNode()
    {
        next=NULL;
    }

    hashNode(int key, int val)
    {
        this->key = key;
        this->val = val;
    }

    hashNode(string key, int val)
    {
        this->key = key;
        this->val = val;
    }


};
/**
 * first attempt at polymorphism
 * Same func diff arguments
 **/
int hashCode(int x)
{
    return ((x*x)*37 + (x*7) + 7); //random qudratic function i thought up don't think too deeply about this. 
}

int hashCode(string s)
{
    int tot=0;
    int ctr=0;
    while(ctr<s.size()) //sum of ascii
    {
        tot+=(int)s[ctr];
        ctr++;        
    }
    return tot;
}
template<typename S, typename T> 
//simple insertion of node in iinked list
void insertHashNode(hashNode<S, T> * head, hashNode<S, T> * & ins)
{
    while(head->next != NULL)
        head = head->next;
    head ->next = ins;
}


template<typename P, typename Q>
class hashMap
{
private:
    hashNode<P, Q> **arr; //the array of nodes
    int tableSize; //the size of the table

public:

    //constructor
    hashMap(int tableSize) 
    {
        this->tableSize=tableSize;
        arr = new hashNode<P, Q>* [tableSize];
        for(int i=0;i<tableSize;i++)
        {
            arr[i]=NULL;
        }
    }

    //return size of map
    int sizeofMap()
    {
        return this->tableSize;
    }

    //seperate chaining insert method
    void insert(hashNode<P, Q> * & ins)
    {
        /**
         * This is chaining method of dealing with collisons
        **/
        P key = ins->key;
        int index = get_index;
        if(arr[index] == NULL)
        {
            arr[index] = ins;
        }
        else
        {
            insertHashNode(arr[index], ins);
        }
    }

    //open adressing insert method
    void linearInsert(hashNode<P, Q>* & ins)
    {
        /**
         * keep moving onto the next place until you find null 
         * This is linear probing method of dealing with collisons
         **/
        P key = ins->key;
        int index = get_index;
        while(arr[index]!=NULL)
            index=(index+1)%tableSize;
        arr[index]=ins;
    }

    //show map
    void printMap()
    {
        for(int i=0;i<tableSize;i++)
        {
            if(arr[i]!=NULL)
            {
                hashNode<P, Q> * nav=arr[i];
                while(nav!=NULL)
                {
                    cout<<"key = "<<nav->key<<" val = "<<nav->val<<endl;
                    nav=nav->next;
                }
            }
        }
    }

    //seperate chaining getter func
    Q getVal(P key)
    {
        int index=get_index;
        hashNode<P, Q>* nav = arr[index];
        while(nav!=NULL)
        {
            if(nav->key == key)
                return nav->val;
            nav=nav->next;
        }
        return -1;

    }

    /** 
     * Trying to make linear probing and chaining into same class. 
     **/
    //linear probing getter func
    Q getLinearVal(P key)
    {
        int index=get_index;
        while(arr[index]->key != key)
            index++;
        cout<<"Currently at index "<<index<<endl;
        return arr[index]->val;
    }

};
