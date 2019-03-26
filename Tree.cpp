/**
 * exercise on binary trees
 *
 * @author Ortal and Tomer
 *
 * http://www.cplusplus.com/forum/beginner/118562/
 */
#include <iostream>
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

Node* Tree::minNodeValue(Node *n){
    Node *temp=n;
    
    while(temp->getLeft()!=nullptr){
         minNodeValue(temp->getLeft());
    }
    return temp;
}

void Tree::remove(int i) {
	if(!contains(i)){
	     throw runtime_error("there is no such key");
	}
	else{
	    Node *n=treeRoot;
	    while(n!=nullptr){
	        if(i>n->getKey()){
	            n=n->getRight();
	        }
	        else if(i<n->getKey()){
	            n=n->getLeft();
	        }
	        else{
	            if(n->getLeft()==nullptr){
	                Node *temp=n->getRight();
	                
	            }
	        }
	    }
	        
	}
	    
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
  return NULL;
}


int Tree::left(int i) {
	if(!contains(i)){
	   throw runtime_error("there no such key");
	}
	Node *n=treeRoot;
	else{
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
	        else
	        n=n->getLeft();
        }
    }
    return NULL;
}
int Tree::right(int i) {
	if(!contains(i)){
	   throw runtime_error("there no such key");
	}
	Node *n=treeRoot;
	else{
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
    return NULL;
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
