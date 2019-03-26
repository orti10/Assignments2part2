/*
*
*
* http://www.cplusplus.com/forum/beginner/118562/
*/
#include <iostream>
namespace ariel

{
    
using namespace std;

	class Node {
	private:
		int key;
		Node *left;
		Node *right;

	public:
	  
		Node(int data) {
			key = data;
		}
		int getKey() {
			return key;
		}
		void setKey(int key) {
			this->key=key;
		}
		Node *getRight() {
			return right;
		}
		Node *getLeft() {
			return left;
		}
		void *setRight(Node *node) {
			this->right = node;
		}
		void *setLeft(Node *node) {
			this->left = node;
		}

	};

	class Tree {
	private:
		Node *treeRoot;
		int sizeOf;

	public:
		Tree();
		~Tree();
		void insert(int i);
	    void deleteTree(Node *n);
		void remove(int i);
		Node* minNodeValue(Node *n);
		int size();
		bool contains(int i);
		int root();
		bool isempty();
		int parent(int i);
		int left(int i);
		int right(int i);
	    void printInOrder(Node *n);
		void print();
	};
}