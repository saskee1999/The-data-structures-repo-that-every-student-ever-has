#include<iostream>
#include"hashMap.hpp"
#include<string>
using namespace std;

/**
 * Originally this project started as just a simple implentation of seperate chaining hash tables but now 
 * i'm starting to incorporate open-adressing into the class also.   
 **/

int main()
{
    hashMap<int, int> m(100); //constructor takes size of hashtable as the argument, i've set it to 100 as a start.
    int tableSize=100; //defined an int here because i am using a macro in in the header file called get_index.
    while(1)
    {
        int k, v;
        cin>>k>>v;
        hashNode<int, int>* tmp = new hashNode<int, int> (k, v);
        m.linearInsert(tmp);
        m.printMap();
        int key = tmp->key;
        int index=get_index;
        cout<<"index originally = "<<index<<endl;
        m.getLinearVal(tmp->key); //linear probing example, put 2 and 7 as keys to find collison.
    }
    
    
}