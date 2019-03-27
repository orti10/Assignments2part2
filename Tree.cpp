/**
 
 * exercise on binary trees
 *
 * @author Ortal and Tomer
 *
 * http://www.cplusplus.com/forum/beginner/118562/
 * https://stackoverflow.com/questions/31715769/c-delete-a-node-from-binary-search-tree
 */
#include <iostream>
#include <stdexcept>
#include "Tree.hpp"
using namespace ariel;
using namespace std;

Tree::Tree() {
    treeRoot=nullptr;
    sizeOf=0;
}
Tree::~Tree() {
    deleteTree(treeRoot);
}
void Tree::deleteTree(Node *n){
    if(n){
        deleteTree(n->getLeft());
        deleteTree(n->getRight());
        delete n;
    }
}

void Tree::insert(int i) {
	Node *n;
	 if(treeRoot==nullptr){
	    treeRoot=new Node(i);
	}
	else{
	    n =new Node(i);
	    n=treeRoot;
	    while(n!=nullptr){
	        if(i>n->getKey()){
	            n=n->getRight();
	        }
	    else if(i<n->getKey()){
	        n=n->getLeft();
	    }
	    else{
	        throw runtime_error("the value already exist");
	    }
	  }
	  n=new Node(i);  
	}
	++sizeOf;
}

Node* Tree::maxNodeValue(Node *n){
    if(n==nullptr)
    return NULL;

    while(n->getRight() != NULL)
    {
        n = n->getRight();
    }
    return n;
}
Node* Tree::_remove(Node* n ,int data){
Node *temp=new Node(data);	
if(n==NULL) return n;
    else if(data<=n->getKey()) 
        n->setLeft( _remove(n->getLeft(), data));
    else if (data> n->getKey())
        n->setRight( _remove(n->getRight(), data)) ;
    else
    {
        //No child
        if(n->getRight() == NULL && n->getLeft() == NULL)
        {
            delete n;
            n = nullptr;   
        }
        //One child 
        else if(n->getRight() == NULL)
        {
             
	    temp=n;
            n= n->getLeft();
            delete temp;
            temp=nullptr;
        }
        else if(n->getLeft() == NULL)
        {
             
	    temp=n;
            n= n->getRight();
            delete temp;
            temp=nullptr;
        }
        //two child
        else
        {
	    Node *Maxtempdata=maxNodeValue(n->getLeft());
            temp = new Node (Maxtempdata->getKey());
            n->setKey(temp->getKey()) ;
            n->setLeft(_remove(n->getLeft(), temp->getKey()));
        }
    }
    return n;
}
void Tree::remove(int i) {
	// if tree is empty - throw exeption
    if (!treeRoot) {
        throw runtime_error("Tree is empty");
    }
    // if tree doesn't contains value - throw exeption
    else if(!contains(i)){
        throw invalid_argument(" not found");
    }
    // else call recursive remove method
    else {
        _remove(treeRoot, i);
        if(sizeOf>0)sizeOf--;
