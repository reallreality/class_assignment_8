/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* Header file for bintree.cpp
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

//Including data.h to be able to use it
#include "data.h"
#include <iostream>
#include <algorithm>


using std::cout;
using std::endl;
using std::max;

//Class stub
class BinTree {

    public:

        //Constructor
        BinTree();

        //Destructor
        ~BinTree();

        //Public methods
        bool isEmpty();

        
        int getCount();

        
        bool getRootData(Data*);

        
        bool addNode(int, const string*);


        void displayInOrder();

        
        void displayPreOrder(); 
        
        
        void displayPostOrder();

        
        void displayTree();

        
        int getHeight(); 

        
        bool contains(int);

        
        bool getNode (Data*, int);
        
        
        void clear();

        
        bool removeNode(int);

        // Given inorder successor prototype
        DataNode* minValueNode(DataNode*);
        

    private:

        DataNode *root;     
                            //Only two attributes
        int count;


        //Private overloaded methods
        bool addNode(DataNode*, DataNode**);

        
        void displayInOrder(DataNode*);

        
        void displayPreOrder(DataNode*);

         
        void displayPostOrder(DataNode*);

        
        int getHeight(DataNode*);


        bool contains(int, DataNode*);

        
        bool getNode(Data*, int, DataNode*);

        
        void clear(DataNode*);

        
        DataNode* removeNode(int, DataNode*);

};


#endif /* BINTREE_BINTREE_H */

