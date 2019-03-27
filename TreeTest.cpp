/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree bigTree;
  ariel::Tree miniTree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  bigTree.insert(65);
  bigTree.insert(288);
  bigTree.insert(89);
  bigTree.insert(3);
  bigTree.insert(77);
  bigTree.insert(4567);
  bigTree.insert(55);
  bigTree.insert(87);
  bigTree.insert(56);
  bigTree.insert(123);

  miniTree.insert(23);
  miniTree.insert(6);
  
  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.insert(9))
  .CHECK_OK    (threetree.insert(-3))
  .CHECK_OK    (threetree.insert(8))
  .CHECK_OK    (threetree.insert(0))
  .CHECK_EQUAL (threetree.size(), 7)
  .CHECK_EQUAL (threetree.parent(8), 9)
  .CHECK_EQUAL (threetree.parent(0), -3)
  //.CHECK_OK    (threetree.print())


  .CHECK_OK(threetree.remove(0)) // leaf
  .CHECK_EQUAL(threetree.contains(0),false) // leaf

  .CHECK_OK(threetree.remove(3)) // one child
  .CHECK_EQUAL(threetree.contains(3),false) // one child

  .CHECK_OK(threetree.remove(5)) // two child
  .CHECK_EQUAL(threetree.contains(5),false) // two child

  .CHECK_THROWS(threetree.insert(8))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (bigTree.size(),10)
  .CHECK_OK    (bigTree.remove(288))
  .CHECK_THROWS(bigTree.remove(288))
  .CHECK_EQUAL (bigTree.root(),65)
  .CHECK_EQUAL (bigTree.parent(3), 65)
  .CHECK_OK    (bigTree.remove(4567))
  .CHECK_EQUAL (bigTree.size(),8)
  .CHECK_OK    (bigTree.insert(288))
  .CHECK_THROWS(bigTree.left(56))
  .CHECK_OK    (bigTree.remove(65))//remove the root
  .CHECK_EQUAL (bigTree.root(),77)//check if the root is 56 as it should be
  .CHECK_OK    (bigTree.print())
  
  .CHECK_EQUAL (miniTree.size(),2)
  .CHECK_THROWS(miniTree.remove(4))
  .CHECK_OK    (miniTree.remove(23))
  .CHECK_EQUAL (miniTree.size(),1)
  .CHECK_EQUAL (miniTree.root(),6)
  .CHECK_THROWS(miniTree.parent(6))
  .CHECK_OK    (miniTree.remove(6))
  .CHECK_EQUAL (miniTree.size(),0)
  .CHECK_OK    (miniTree.print())
  
  
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}

















// /**
// * Examples of automatic tests for the exercise on binary trees.
// *
// * @author Erel Segal-Halevi
// * @since 2019-02
// */

// #include <iostream>
// using namespace std;
// #include "badkan.hpp"
// #include "Tree.hpp"

// int main() {
//   ariel::Tree emptytree;
//   ariel::Tree threetree;  

//   threetree.insert(5);
//   threetree.insert(7);
//   threetree.insert(3);
 
//   ariel::Tree mytree;  
//   ariel::Tree mytree2;  
//   mytree.insert(5);
//   mytree.insert(7);
//   mytree.insert(3);
//   mytree.insert(2);
//   mytree.insert(1);
//   mytree.insert(10);
//   mytree.insert(8);
//   mytree.insert(40);
//   mytree.insert(30);
//   mytree.insert(6);
  
//   mytree2.insert(20);
//   mytree2.insert(10);
//   mytree2.insert(30);
//   mytree2.insert(15);
//   mytree2.insert(5);
//   mytree2.insert(25);
//   mytree2.insert(40);
  
//   badkan::TestCase tc("Binary tree");
//   tc
//   .CHECK_EQUAL (emptytree.size(), 0)
//   .CHECK_OK    (emptytree.insert(5))
//   .CHECK_EQUAL (emptytree.size(), 1)
//   .CHECK_EQUAL (emptytree.contains(5), true)
//   .CHECK_OK    (emptytree.remove(5))
//   .CHECK_EQUAL (emptytree.contains(5), false)
//   .CHECK_THROWS(emptytree.remove(5))
//   .CHECK_EQUAL (emptytree.size() ,0)
  
//   .CHECK_EQUAL (threetree.size(), 3)
//   .CHECK_EQUAL (threetree.root(), 5)
//   .CHECK_EQUAL (threetree.parent(3), 5)
//   .CHECK_EQUAL (threetree.parent(7), 5)
//   .CHECK_EQUAL (threetree.left(5), 3)
//   .CHECK_EQUAL (threetree.right(5), 7)
//   .CHECK_THROWS(threetree.insert(3))
//   .CHECK_THROWS(threetree.left(6))
//   .CHECK_OK    (threetree.print())
//   //.print();
  
//   //mytree test
//   .CHECK_EQUAL (mytree.size(),10)
//   .CHECK_EQUAL (mytree.root(),5)
//   .CHECK_EQUAL (mytree.contains(2),true)
//   .CHECK_EQUAL (mytree.contains(40),true)
//   .CHECK_EQUAL (mytree.contains(7),true)
//   .CHECK_EQUAL (mytree.contains(30),true)
//   .CHECK_EQUAL (mytree.contains(58),false)
//   .CHECK_EQUAL (mytree.contains(26),false)
//   .CHECK_OK    (mytree.remove(3))
//   .CHECK_OK    (mytree.remove(6))
//   .CHECK_OK    (mytree.remove(30))
//   .CHECK_EQUAL (mytree.right(10), 40)
//   .CHECK_EQUAL (mytree.left(5), 2)
//   .CHECK_THROWS(mytree.remove(3))
//   .CHECK_THROWS(mytree.remove(100))
//   .CHECK_EQUAL (mytree.contains(3),false)
//   .CHECK_EQUAL (mytree.parent(10),7)
//   .CHECK_EQUAL (mytree.parent(1),2)
//   .CHECK_EQUAL (mytree.parent(2),5)
//   .CHECK_EQUAL (mytree.right(5), 7)
//   .CHECK_EQUAL (mytree.left(2), 1)
//   .CHECK_EQUAL (mytree.right(7), 10)
//   .CHECK_THROWS(mytree.left(7))
//   .CHECK_THROWS(mytree.left(40))
//   .CHECK_THROWS(mytree.left(1))
//   .CHECK_EQUAL (mytree.left(10), 8)
//   .CHECK_OK    (mytree.remove(8))
//   .CHECK_OK    (mytree.remove(40))
//   .CHECK_OK    (mytree.remove(10))
//   .CHECK_OK    (mytree.remove(7))	  
//   .CHECK_EQUAL (mytree.isempty(),false)
//   .CHECK_OK    (mytree.remove(1)) 
//   .CHECK_OK    (mytree.remove(2))
//   .CHECK_OK    (mytree.remove(5))
//   .CHECK_EQUAL (mytree.contains(5),false)
//   .CHECK_EQUAL (mytree.isempty(),true)
  
//   //mytree2 test
  
//   .CHECK_EQUAL (mytree2.root(),20)
//   .CHECK_EQUAL (mytree.contains(15),true)
//   .CHECK_EQUAL (mytree.contains(7),false)
//   .CHECK_OK    (mytree.remove(30))
//   .CHECK_EQUAL (mytree.right(20), 25)
//   .CHECK_EQUAL (mytree.right(10), 15)
//   .CHECK_EQUAL (mytree.left(10), 5)
//   .CHECK_THROWS(mytree.left(30));
//   //.print;
  
//   cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
// }
