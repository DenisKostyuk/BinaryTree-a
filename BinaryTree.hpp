#pragma once

#include <iostream>
using namespace std;
using namespace std;

namespace ariel{

    template<typename T> class BinaryTree{
        

        

        public:
            BinaryTree<T>() : root(nullptr){

            }
            ~BinaryTree<T>(){

            }
            BinaryTree<T> add_root(const T& val){
                return *this;
            }
            BinaryTree<T> add_left(const T& val1, const T& val2){
                return *this;
            }
            BinaryTree<T> add_right(const T& val1, const T& val2){
                return *this;
            }
            friend std::ostream& operator<<(std::ostream& os , const BinaryTree<T> &tree){
                return os;
            }
        private:
            struct BTNode{
                T data;
                BTNode* left;
                BTNode* right;
                BTNode(T val):data(val),left(nullptr),right(nullptr){

                }
            };
        BTNode* root;

        public:
            class iterator{
                private:
                    BTNode* ptr_to_curr_btnode;
                
                public:
                    
                    iterator(BTNode* ptr = nullptr):ptr_to_curr_btnode(ptr){
                    }
                    T& operator*() const{
                        return ptr_to_curr_btnode->data;
                    }
                    T* operator->()const{
                        return &(ptr_to_curr_btnode->data);
                    }
                    iterator& operator++(){
                        return *this;
                    }
                    const iterator operator++(int){
                        iterator tmp = *this;
                        return tmp;
                    }
                    bool operator==(const iterator& izz) const{
                        return ptr_to_curr_btnode==izz.ptr_to_curr_btnode;
                    }
                    bool operator!=(const iterator& izz) const{
                        return ptr_to_curr_btnode!=izz.ptr_to_curr_btnode;
                    }

                
            };
        public:
           
            iterator begin_preorder(){
                return iterator{root};
            }
            iterator end_preorder(){
                return iterator{root};
            }
            iterator begin_inorder(){
                return iterator{root};
            }
            iterator end_inorder(){
                return iterator{root};
            }
            iterator begin_postorder(){
                return iterator{root};
            }
            iterator end_postorder(){
                return iterator{root};
            }
            iterator begin(){
                return iterator{root};
            }
            iterator end(){
                return iterator{root};
            }
            
            
    };
}