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
	if(treeRoot==nullptr){
	    treeRoot=new Node(i);
	}
	else{
	    Node *n = treeRoot;
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
    if(n==NULL)
    return NULL;

    while(n->getRight() != NULL)
    {
        n = n->getRight();
    }
    return n;
}
Node* Tree::_remove(Node* n ,int data){
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
            n = NULL;   
        }
        //One child 
        else if(n->getRight() == NULL)
        {
            Node* temp = n;
            n= n->getLeft();
            delete temp;
        }
        else if(n->getLeft() == NULL)
        {
            Node* temp = n;
            n= n->getRight();
            delete temp;
        }
        //two child
        else
        {
            Node* temp = maxNodeValue(n->getLeft());
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
        sizeOf--;
    }
	}	    


int Tree::size() {
	return sizeOf;
}

bool Tree::contains(int i) {
    if(treeRoot==nullptr){
        return false;
    }
    Node *n=treeRoot;
    while (n!=nullptr){
      if(i>n->getKey()){
	            n=n->getRight();
	        }
	    else if(i<n->getKey()){
	        n=n->getLeft();
	    }
	    else{
	        return true;
	    }  
    }
    return false;
}

int Tree::root() {
    if(treeRoot!=nullptr){
    return treeRoot->getKey();
    }
    throw runtime_error("the tree is empty");
}
bool Tree::isempty(){
    if(treeRoot==nullptr){
        return true;
    }
    return false;
}

int Tree::parent(int i) {
	if((!contains(i)) && (i==treeRoot->getKey())){
	    throw runtime_error("there no such key");
	}
	
	else{
	    Node *n=treeRoot;
	    while(1){
	    if(i>n->getKey()){
	        if(n->getRight()->getKey()==i){
	            return n->getKey();
	        }
	        else n=n->getRight();
	    }
	    else {
	        if(n->getLeft()->getKey()==i){
	            return n->getKey();
	        }
	        else n=n->getLeft();
	    }
	}
  }
  return 0;
}


int Tree::left(int i) {
	if(!contains(i)){
	   throw runtime_error("there no such key");
	}
	
	else {
		Node *n=treeRoot;

	    while(n!=nullptr){
	        if(i==n->getKey()){
	            if(n->getLeft()==nullptr){
	                throw runtime_error("there no such key");
	            }
	            else return n->getLeft()->getKey();
	        }
	        else if(i>n->getKey()){
	            n=n->getRight();
	        }
	        else{
	        n=n->getLeft();
			}
        }
    }
    return 0;
}
int Tree::right(int i) {
	if(!contains(i)){
	   throw runtime_error("there no such key");
	}
	else{
		Node *n=treeRoot;

	    while(n!=nullptr){
	        if(i==n->getKey()){
	            if(n->getRight()==nullptr){
	                throw runtime_error("there no such key");
	            }
	            else return n->getRight()->getKey();
	        }
	        else if(i>n->getKey()){
	            n=n->getRight();
	        }
	        else
	        n=n->getLeft();
        }
    }
    return 0;
}
//Inorder print LVR
void Tree::printInOrder(Node *n) {
    if(n==nullptr) return;

	printInOrder(n->getLeft());
	cout<<n->getKey()<<" ";
	printInOrder(n->getRight());

}


void Tree::print() {
   printInOrder(treeRoot);
	
}
