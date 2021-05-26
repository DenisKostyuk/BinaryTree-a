#include "doctest.h"
#include <iostream>
#include "BinaryTree.hpp"
#include <string>
using namespace std;
using namespace ariel;
/*author Denis Kostyuk*/


TEST_CASE("Binary Tree with Integer values"){
    /*Building a binary tree of ints and randomly adds or to the left or to the right*/
    BinaryTree<int> iTree;
    CHECK_NOTHROW(iTree.add_root(0););
    for(int i = 1;i<=20;i++){
        int rnd = rand() % 2;
        if(rnd == 0){
            CHECK_NOTHROW(iTree.add_right(i,i-1));
        }else{
            CHECK_NOTHROW(iTree.add_left(i,i-1));
        }
    }
    SUBCASE("Printing the Tree in all orders"){
        for(auto it = iTree.begin_inorder();it!= iTree.end_inorder();it++){
            std::cout<<*it<<endl;
        }
        for(auto it = iTree.begin_postorder();it!= iTree.end_postorder();it++){
            std::cout<<*it<<endl;
        }
        for(auto it = iTree.begin_preorder();it!= iTree.end_preorder();it++){
            std::cout<<*it<<endl;
        }
    }
    /*Override the elements that already had been signed in the previous loop , to new numbers 
    as left and right childs of the Integer Binary Tree*/
    for(int i=1;i<=10;i++){
        int rnd = rand() % 2;
        if(rnd == 0){
            if(rnd == 0){
                CHECK_NOTHROW(iTree.add_right(i , i+100));
            }
        }
    }
    SUBCASE("Printing the Tree in all orders"){
        for(auto it = iTree.begin_inorder();it!= iTree.end_inorder();it++){
            std::cout<<*it<<endl;
        }
        for(auto it = iTree.begin_postorder();it!= iTree.end_postorder();it++){
            std::cout<<*it<<endl;
        }
        for(auto it = iTree.begin_preorder();it!= iTree.end_preorder();it++){
            std::cout<<*it<<endl;
        }
    }
}
TEST_CASE("Checking Pre-order , In-order , Post-order"){
    /*Build a tree and checking the inorder , preoder , postorder*/
    BinaryTree<std::string> sTree;
    /*     (a)__________
            |           |
           (b)____     (c)
            |     |     
           (d)   (e)
    */
    sTree.add_root("a");
    sTree.add_left("a","b");
    sTree.add_right("a","c");
    sTree.add_left("b","d");
    sTree.add_right("b","e");
    SUBCASE("Pre-Order equation between supposed output and real output"){
        std::string pre_order_string = "";
        std::string pre_order_supposted_answer = "abdec";
        for(auto it = sTree.begin_preorder();it!=sTree.end_preorder();++it){
            pre_order_string+=*it;
        }
        CHECK_EQ(pre_order_string , pre_order_supposted_answer);
    }
    SUBCASE("In-Order equation between supposed output and real output"){
        std::string in_order_string = "";
        std::string in_order_supposted_answer = "dbeac";
        for(auto it = sTree.begin_inorder();it!=sTree.end_inorder();++it){
            in_order_string+=*it;
        }
        CHECK_EQ(in_order_string , in_order_supposted_answer);
    }
    SUBCASE("Post-Order equation between supposed output and real output"){
        std::string post_order_string = "";
        std::string post_order_supposted_answer = "debca";
        for(auto it = sTree.begin_postorder();it!=sTree.end_postorder();++it){
            post_order_string+=*it;
        }
        CHECK_EQ(post_order_string , post_order_supposted_answer);
    }
}