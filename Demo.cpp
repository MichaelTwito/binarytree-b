/**
 * Demo file for the exercise on binary tree
 *
 * @author Erel Segal-Halevi
 * @since 2021-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "BinaryTree.hpp"
const int max_rand = 1000;
using namespace ariel;

enum class _order {
    inorder,
    postorder,
    preorder,
};

template <typename T>
BinaryTree<T> create_dummy(int adder = 0) {
    BinaryTree<T> tree;

    // create the following tree
    //                    1
    //              2          3
    //         4        5
    //               10   11
    //             20       23
    tree.add_root(1 + adder);
    tree.add_left(1 + adder, 2 + adder);
    tree.add_right(1 + adder, 3 + adder);
    tree.add_left(2 + adder, 4 + adder);
    tree.add_right(2 + adder, 5 + adder);
    tree.add_left(5 + adder, 10 + adder);
    tree.add_right(5 + adder, 11 + adder);
    tree.add_left(10 + adder, 20 + adder);
    tree.add_right(11 + adder, 23 + adder);

    return tree;
}
class myString {
public:
    string val;
    myString(int a) {
        val = std::to_string(a);
    }

    myString &operator+(const myString &other) {
        val += other.val;
        return *this;
    }

    myString &operator+(int other) {
        val += to_string(other);
        return *this;
    }

    myString &operator+(double other) {
        val += to_string(other);
        return *this;
    }

    bool operator==(const myString &other) {
        return this->val == other.val;
    }

    // need to define this for maps...
    friend bool operator<(const myString &t, const myString &other) {
        return t.val < other.val;
    }

    friend std::ostream &operator<<(std::ostream &os, const myString &c) {
        return (os << c.val);
    }
};

int NextInt() {
    return (rand() % max_rand);
}

int main() {
        BinaryTree<bool> t_bool;
        /* Add true as the root of the tree */
        t_bool.add_root(true);
        for (int i = 0; i < 50; i++)
        {
            /* Create a tree of only true values */
            t_bool.add_left(true, true);
       
            t_bool.add_right(true, true);
     
        }
        /* Since there is no false value in the tree, trying to add any left or right sons of true
        // should throw an exception */
        // CHECK_THROWS(t_bool.add_left(false, true));
        // CHECK_THROWS(t_bool.add_right(false, true));
        // bool check = true;
        // for (auto it = t_bool.begin_inorder(); it != t_bool.end_inorder(); it++)
        // {
        //     check &= *it;
        // }
        // /* Since all tree value are true, &'ing them should be true */
        // CHECK(check);
        // /* Replace tree root with false */
        // t_bool.add_root(false);
        // /* Now trying to add right and left sons of false should not throw exception
        // since the root of the tree is false */
        // CHECK_NOTHROW(t_bool.add_left(false, true));
        // CHECK_NOTHROW(t_bool.add_right(false, true));
        // check = true;
        // for (auto it = t_bool.begin_inorder(); it != t_bool.end_inorder(); it++)
        // {
        //     check &= *it;
        // }
        // /* Since thre root of the tree is false, &'ing him with true's should be false */
        // CHECK_FALSE(check);
        // BinaryTree<bool> t_bool_2;
        // for (int i = 0; i < 50; i++)
        // {
        //     /* Adding sons, left or right to a tree with no root, should throw and exception */
        //     CHECK_THROWS(t_bool_2.add_left(true, true));
        //     CHECK_THROWS(t_bool_2.add_right(true, true));
        //     CHECK_THROWS(t_bool_2.add_left(false, true));
        //     CHECK_THROWS(t_bool_2.add_right(false, true));
        // }































//    BinaryTree<bool> t_bool;
//         /* If the tree is empty, begin() and end() iterators should be the same; */
//         bool h = (t_bool.begin() ==  t_bool.end());
//         cout << h;
//         // cout << (t_bool.begin_inorder() == t_bool.end_inorder());
        // cout << (t_bool.begin_postorder() == t_bool.end_postorder());
        // cout << (t_bool.begin_preorder() == t_bool.end_preorder());
        // t_bool.add_root(true);
        // /* After adding root to the tree, begin() and end() iterators shouldn't be the same; */
        // CHECK_FALSE((t_bool.begin() == t_bool.end()));
        // CHECK_FALSE((t_bool.begin_inorder() == t_bool.end_inorder()));
        // CHECK_FALSE((t_bool.begin_postorder() == t_bool.end_postorder()));
        // CHECK_FALSE((t_bool.begin_preorder() == t_bool.end_preorder()));
        // auto it = t_bool.begin();
        // auto it_in = t_bool.begin_inorder();
        // auto it_post = t_bool.begin_postorder();
        // auto it_pre = t_bool.begin_preorder();
        // /* In post increment, begin() and end() iterators shouldn't be the same; */
        // CHECK_FALSE((it++ == t_bool.end()));
        // CHECK_FALSE((it_in++ == t_bool.end_inorder()));
        // CHECK_FALSE((it_post++ == t_bool.end_postorder()));
        // CHECK_FALSE((it_pre++ == t_bool.end_preorder()));
        // CHECK((it == t_bool.end()));
        // CHECK((it_in == t_bool.end_inorder()));
        // CHECK((it_post == t_bool.end_postorder()));
        // CHECK((it_pre == t_bool.end_preorder()));
        // it = t_bool.begin();
        // it_in = t_bool.begin_inorder();
        // it_post = t_bool.begin_postorder();
        // it_pre = t_bool.begin_preorder();
        // /* In pre increment, begin() and end() iterators shouldn't be the same; */
        // CHECK((++it == t_bool.end_inorder()));
        // CHECK((++it_in == t_bool.end_inorder()));
        // CHECK((++it_post == t_bool.end_postorder()));
        // CHECK((++it_pre == t_bool.end_preorder()));
        /* At the end of the for loop, the iterator should be pointing to the end of the tree*/
}
    // const int max_val = 20;
    // BinaryTree<myString> tree;

    // tree.add_left(0, 5);
    // tree.add_left(0, 10);


//     BinaryTree<int> tree_of_ints;
//     tree_of_ints.add_root(1);
//     tree_of_ints.add_right(1, 2);
//     tree_of_ints.add_right(2, 3);
//     tree_of_ints.add_right(3, 4);
//     tree_of_ints.add_right(4, 5);
//     tree_of_ints.add_right(5, 6);
//     tree_of_ints.add_right(6, 7);
//     tree_of_ints.add_right(7, 8);
//     tree_of_ints.add_right(8, 9);
//     tree_of_ints.add_right(9, 10); // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)

//  vector<int> tempVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     auto itPre = tree_of_ints.begin_preorder();
//     unsigned int i = 0;
//     while (itPre != tree_of_ints.end_preorder())
//     {
//       cout << "\n itPre : " << *itPre << " tempVector : " << tempVector[i];
//       // *itPre == tempVector[i];
//         i++;
//         itPre++;
//     }


//     tempVector = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     auto itIn = tree_of_ints.begin_inorder();
//     i = 0;
//     while (itIn != tree_of_ints.end_inorder())
//     {
//         CHECK((*itIn) == tempVector[i]);
//         i++;
//         itIn++;
//     }
//   cout << tree_of_ints << endl;  /* Prints the tree in a reasonable format. For example:
//         1
//         |--------|
// //         2        3
// //         |---|
// //         4   5
// //   */

//   for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 1 2 4 5 3
//   cout << "\n";
//   for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 2 5 1 3 
//   cout << "\n" ;
//   for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 5 2 3 1

//   // for (int element: tree_of_ints) {  // this should work like inorder
//   //   cout << element << " " ;
//   // }  // prints: 4 2 5 1 3 


// //   // The same should work with other types, e.g. with strings:
  
//   BinaryTree<string> tree_of_strings;
//   tree_of_strings.add_root("1")     
//   .add_left("1", "9")      // Now 9 is the left child of 1
//   .add_left("9", "4")      // Now 4 is the left child of 9
//   .add_right("9", "5")     // Now 5 is the right child of 9
//   .add_right("1", "3")     // Now 3 is the right child of 1
//   .add_left("1", "2");     // Now 2 is the left child of 1, instead of 9 (the children of 9 remain in place)
//   cout << tree_of_strings << endl; 

//   for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 1 2 4 5 3
//   for (auto it=tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 2 5 1 3 
//   for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: 4 5 2 3 1

  // // demonstrate the arrow operator:
  // for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
  //   cout << it->size() << " " ;
  // }  // prints: 1 1 1 1 1 


//   for (const string& element: tree_of_strings) {  // this should work like inorder
//     cout << element << " " ;
//   }   // prints: 4 2 5 1 3 

