/*********************
* Michael Johan Rupprecht
* COSC-2436-002
* An example program introducing the basics of BST
**********************/

#include "bintree.h"

//Constructor
BinTree::BinTree() {

    count = 0;

    root = NULL;

}


//Destructor
BinTree::~BinTree() {

    this->clear();

}


//isEmpty method
bool BinTree::isEmpty() {

    bool empty = false;

    if (root == NULL) {

        empty = true;
    }

    return empty;
}


//getCount method
int BinTree::getCount() {

    return count;

}


//getRootData method
bool BinTree::getRootData(Data *fillerStruct) {

    bool hasData = false;

    if (root != NULL) {

        fillerStruct->id = root->data.id;

        fillerStruct->information = root->data.information;

        hasData = true;

    }

    else {

        fillerStruct->id = -1;

        fillerStruct->information = "";

    }

    return hasData;


}


//displayTree method
void BinTree::displayTree() {

    bool full = false;

    if (root) {

        full = true;

    }

    if (full) {

        cout << "Tree is NOT empty" << endl;

        cout << "Height: " << this->getHeight() << endl;

        cout << "Count: " << this->getCount() << endl;
        

        cout << endl << "Pre-Order Traversal" << endl;
        this->displayPreOrder();


        cout << endl << "In-Order Traversal" << endl;
        this->displayInOrder();


        cout << endl << "Post-Order Traversal" << endl;
        this->displayPostOrder();

        cout << endl;

    }

    else {

        cout << "Tree IS empty\n" << endl;
    }
}




//addNode method (gateway to private addNode method)
bool BinTree::addNode(int idToAdd, const string *stringToAdd) {

    bool added = false;

    //Verifying the input data is valid
    if (idToAdd > 0 && *stringToAdd != "") {

        //Dynamic allocation of new node
        DataNode *newNode = new DataNode;

        //Filling the new node pointer with data
        newNode->data.id = idToAdd;

        newNode->data.information = *stringToAdd;

        newNode->left = NULL;

        newNode->right = NULL;


        // cout << this->addNode(newNode, &root) << ": value is bool of addNode operation" << endl;


        //If statement to set bool and count
        if (this->addNode(newNode, &root)) {

            added = true;

            count++;
        }

    
    }

    return added;

}


//Private addNode method
bool BinTree::addNode(DataNode *nodeIn, DataNode **newRoot) {

    bool added = false;

    //If root is empty
    if (!(*newRoot)) {

        *newRoot = nodeIn;

        added = true;

    }



    //If the input ID is greater than the current root ID
    else if (nodeIn->data.id > (*newRoot)->data.id) {

        this->addNode(nodeIn, &((*newRoot)->right));

        added = true;

    }



    //If the input ID is less than the curren root ID
    else if (nodeIn->data.id < (*newRoot)->data.id) { 

        this->addNode(nodeIn, &((*newRoot)->left));

        added = true;

    }

    return added;
}




//displayInOrder method
void BinTree::displayInOrder() {
    
    this->displayInOrder(root);

}


//Private displayInOrder method
void BinTree::displayInOrder(DataNode *temproot) {

    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }

    return;
    
}




//displayPreOrder method
void BinTree::displayPreOrder() {

    displayPreOrder(root);

}


//Private displayPreOrder method
void BinTree::displayPreOrder(DataNode *temproot) {

    if (temproot) {

        //Since it's preorder the node data gets printed first
        cout << temproot->data.id << " " << temproot->data.information << endl;

        if (temproot->left) {
            displayPreOrder(temproot->left);
        }
        
        if (temproot->right) {
            displayPreOrder(temproot->right);
        }

    }

    return;


}




//displayPostOrder method
void BinTree::displayPostOrder() {

    displayPostOrder(root);

}


//Private displayPostOrder method
void BinTree::displayPostOrder(DataNode *temproot) {

    if (temproot) {

        if (temproot->left) {
            displayPostOrder(temproot->left);
        }
        
        if (temproot->right) {
            displayPostOrder(temproot->right);
        }

        //Since it's preorder the node data gets printed first
        cout << temproot->data.id << " " << temproot->data.information << endl;

    }

    return;


}




//getHeight method
int BinTree::getHeight() {

    return ((this->getHeight(root)) + 1);
    
}


//Private getHeight method
int BinTree::getHeight(DataNode *temproot) {

    int leftHeight = 0;

    int rightHeight = 0;


    if (temproot) {

        if (temproot->left) {

            leftHeight = this->getHeight(temproot->left) + 1;

        }

        if (temproot->right) {

            rightHeight = this->getHeight(temproot->right) + 1;
        }


    }


    return ((max(rightHeight, leftHeight)));

    
}




//contains method
bool BinTree::contains(int searchId) {

    bool contained = false;
    
    if (searchId > 0) {

        contained = this->contains(searchId, root);

    }
    
    return contained;

}


//Private contains method
bool BinTree::contains(int searchIdCopy, DataNode *temproot) {

    bool contained = false;

    if (temproot) {

        if (searchIdCopy == temproot->data.id) {

            contained = true;

        }

        else if (searchIdCopy > temproot->data.id) {

            contained = this->contains(searchIdCopy, temproot->right);

        }

        else if (searchIdCopy < temproot->data.id) {

            contained = this->contains(searchIdCopy, temproot->left);

        }
        
    }

    return contained;

}




//getNode method
bool BinTree::getNode(Data *fillerStruct, int searchId) {

    bool gotten = false;

    if (searchId > 0) {

        gotten = this->getNode(fillerStruct, searchId, root);

    }

    return gotten;
}


//Private getNode method
bool BinTree::getNode(Data *fillerStructCopy, int searchIdCopy, DataNode *temproot) {

    bool exists = false;

    if (temproot) {

        if (searchIdCopy == temproot->data.id) {

            fillerStructCopy->id = temproot->data.id;

            fillerStructCopy->information = temproot->data.information;

            exists = true;

        }

        else if (searchIdCopy > temproot->data.id) {

            exists = this->contains(searchIdCopy, temproot->right);

        }

        else if (searchIdCopy < temproot->data.id) {

            exists = this->contains(searchIdCopy, temproot->left);

        }
        
    }

    return exists;
    
}




//clear method
void BinTree::clear() {

    if (root) {

        this->clear(root);

        //Resetting count and root after clearing tree
        count = 0;

        root = NULL;
    }
}


//Private clear method
void BinTree::clear(DataNode *temproot) {
    
    if (temproot) {
        if (temproot->left) {
            this->clear(temproot->left);
        }
        
        if (temproot->right) {
            this->clear(temproot->right);
        }


        temproot->left = NULL;

        temproot->right = NULL;

        delete temproot;

    }

}




//removeNode method
bool BinTree::removeNode(int idToRemove) {

    int tempcount = count;

    bool removed = false;

    root = removeNode(idToRemove, root);

    if (count < tempcount) {

        removed = true;

    }


    return removed;
}


//Private removeNode method
DataNode* BinTree::removeNode(int removeId, DataNode *temproot) {

    DataNode *returnNode = temproot;
    
    if (temproot) {

        //Executes when ID to remove is less than temproot ID
        if (removeId < temproot->data.id) {

            temproot->left = this->removeNode(removeId, temproot->left);

        }

        //Executes when ID to remove is greater than temproot ID
        else if (removeId > temproot->data.id) {

            temproot->right = this->removeNode(removeId, temproot->right);

        }

        //Executes when ID to remove is EQUAL TO temproot ID
        else {

            //Temporary DataNode Pointer
            DataNode *temp;

            //This node has ONLY 1 CHILD or NO CHILD
            if (temproot->left == NULL) {

                //Save the right
                temp = temproot->right;

                //Delete the root
                delete temproot;

                //Set the root to the node you saved
                temproot = temp;

                //Decrement count
                count--;

            }

            //This node has ONLY 1 CHILD or NO CHILD
            else if (temproot->right == NULL) {

                //Save the right
                temp = temproot->left;

                //Delete the root
                delete temproot;

                //Set the root to the node you saved
                temproot = temp;

                //Decrement count
                count--;

            }

            //This is a node with TWO CHILDREN
            else {

                //Going right
                temp = minValueNode(temproot->right);

                temproot->data.id = temp->data.id;

                temproot->data.information = temp->data.information;

                temproot->right = this->removeNode(temp->data.id, temproot->right);


            }

        }

        

    }

    return temproot;

}




//Given inorder successor definition
DataNode* BinTree::minValueNode(DataNode* node) {

    DataNode* current = node;

    while (current && current->left != NULL) {

        current = current->left; 

    }

    return current; 
}

