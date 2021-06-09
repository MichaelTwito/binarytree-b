#pragma once
#include <vector>
#include <stack>
#include <memory>
#include <iostream>
#include <queue>

using namespace std;

namespace ariel{

template<typename T> class BinaryTree{

public:

struct Node{
T value;
shared_ptr<Node> left;
shared_ptr<Node> right;

Node(const T & value)
	: value(value), left(nullptr), right(nullptr){}

Node (Node &other): value(other.value){
    if (other.left != nullptr){left = new Node(other.left->value);}
    if (other.right != nullptr){right = new Node(other.right->value);}
}
Node(Node &&other) noexcept : value(other.value)
            {
                if (other.left != nullptr)
                {
                    left = new Node(other.left->value);
                }
                if (other.right != nullptr)
                {
                    right = new Node(other.right->value);
                }
                other.left = nullptr;
                other.right = nullptr;
            }

~Node(){
      if (left != nullptr)
                {
                    // delete left;
                }
                if (right != nullptr)
                {
                    // delete right;
                }
}
Node &operator=(const Node other){
    value = other.value;
    if (other.left != nullptr){left = new Node(left->value);}
    if (other.right != nullptr){right = new Node(right->value);}
    return *this;
}

Node &operator=(Node && other) noexcept{
    value = other.value;
    if (other.left != nullptr){left = new Node(left->value);}
    if (other.right != nullptr){right = new Node(right->value);}
    other.left = nullptr;
    other.right = nullptr; 
    return *this;
}
};

shared_ptr<Node> root;
// ------------------------------------------------------------------------------------PREORDER---------------------------------------------------------------------------------
class preorder_iterator{

        public:
            shared_ptr<Node> current;
            std::stack<shared_ptr<Node>> order_stack;

            preorder_iterator():current(nullptr){}
            preorder_iterator(shared_ptr<Node> ptr): current(ptr){
                if (current->right != nullptr) {order_stack.push(current->right);}
                if (current->left != nullptr) {order_stack.push(current->left);}
            }
            
            T& operator*() const{return current->value;}
            T* operator->() const {return &(current->value);}
            
            bool operator!=(const preorder_iterator& other) {return current != other.current;}
            bool operator==(const preorder_iterator& other) {return current == other.current;}
            preorder_iterator& operator++(){

                if (order_stack.empty())
                    {current = nullptr;
                    return *this;}

                current = order_stack.top();
                
                order_stack.pop();

                if (current->right != nullptr)
                    {order_stack.push(current->right);}

                if (current->left != nullptr)
                    {order_stack.push(current->left);}
                
                return *this;
                }

            preorder_iterator operator++(int){
                preorder_iterator tmp = *this;
                
                if (order_stack.empty())
                    {current = nullptr;
                    return tmp;}
                
                current = order_stack.top();
                
                order_stack.pop();

                if (current->right != nullptr)
                    {order_stack.push(current->right);}

                if (current->left != nullptr)
                    {order_stack.push(current->left);}
                
                return tmp;
                }    

            };

// ----------------------------------------------------------------INORDER---------------------------------------------------------------------------
class inorder_iterator{

        public:
            shared_ptr<Node> current;
            std::stack<shared_ptr<Node>> order_stack;

            inorder_iterator():current(nullptr){}
            inorder_iterator(shared_ptr<Node> ptr):current(ptr){
                while (current!=nullptr){
                    order_stack.push(current);
                    current = current->left;
                }
                current = order_stack.top();
                order_stack.pop();
            }
            
            T& operator*() const{return current->value;}
            T* operator->() const {return &(current->value);}
            
            bool operator!=(const inorder_iterator& other) {return current != other.current;}
            bool operator==(const inorder_iterator& other) {return current == other.current;}
            
            inorder_iterator& operator++(){
                
                current = current->right;

                if (order_stack.empty() & current==nullptr)
                    {current = nullptr;
                     return *this;}

                while (current != nullptr){
                    order_stack.push(current);
                    current = current->left;
                }

                current = order_stack.top();
                order_stack.pop();
                
                return *this;
                }

            inorder_iterator operator++(int){
                
                inorder_iterator tmp = *this;
                current = current->right;

                if (order_stack.empty() & current==nullptr)
                    {current = nullptr;
                    return tmp;}

                while (current != nullptr){
                    order_stack.push(current);
                    current = current->left;
                }

                current = order_stack.top();
                order_stack.pop();
                
                return tmp;
                }

            };
// --------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------POSTORDER---------------------------------------------------------------------------
class postorder_iterator{

        public:
            shared_ptr<Node> current;
            std::stack<shared_ptr<Node>> order_stack, order_stack_1;

            postorder_iterator():current(nullptr){}
            postorder_iterator(shared_ptr<Node> ptr):current(ptr){
                order_stack.push(current);
                while (!order_stack.empty()){
                    current = order_stack.top();
                    order_stack.pop();
                    order_stack_1.push(current);
                    if (current->left) {order_stack.push(current->left);}
                    if (current->right) {order_stack.push(current->right);}
                }
                current = order_stack_1.top();
                order_stack_1.pop();
            }
            
            T& operator*() const{return current->value;}
            T* operator->() const {return &(current->value);}
            
            bool operator!=(const postorder_iterator& other) {return current != other.current;}
            
            bool operator==(const postorder_iterator& other) {return current == other.current;}
            postorder_iterator& operator++(){
                if (order_stack_1.empty()){
                    current = nullptr;
                    return *this;
                }
                
                current = order_stack_1.top();
                order_stack_1.pop();
                return *this;
                }

             postorder_iterator operator++(int){
                postorder_iterator tmp = *this;
                if (order_stack_1.empty()){
                    current = nullptr;
                    return tmp;}
       
                current = order_stack_1.top();
                order_stack_1.pop();
                return tmp;
                }

            };
// --------------------------------------------------------------------------------------------------------------------------------------------
BinaryTree() : root(nullptr){};
BinaryTree(BinaryTree &other){

    queue<shared_ptr<Node>> tmp;

    shared_ptr<Node> new_root(new Node(other.root->value));
    
    root = new_root;
    
    tmp.push(other.root);
    
    while(!tmp.empty()){
        shared_ptr<Node> current = tmp.front();
        tmp.pop();
        if (current->left !=nullptr)
        {
            this->add_left(current->value, current->left->value);
            tmp.push(current->left);
        }
        
        if (current->right !=nullptr)
        {
            this->add_right(current->value, current->right->value);
            tmp.push(current->right);
        }
    }
}
 ~BinaryTree()
        {
            // if (root != nullptr)
            // {
            //     cout << root;
            // }
        };


BinaryTree(BinaryTree &&other) noexcept{
    root = other.root;
    other.root = nullptr;
}

 BinaryTree &operator=(BinaryTree other)
        {
            queue<shared_ptr<Node>> tmp;
            shared_ptr<Node> new_root(new Node(other.root->value));

            root = new_root;

            tmp.push(other.root);
            while (!tmp.empty())
            {
                shared_ptr<Node> current = tmp.front();
                tmp.pop();
                if (current->left != nullptr)
                {
                    this->add_left(current->value, current->left->value);
                    tmp.push(current->left);
   
                }
                if (current->right != nullptr)
                {
                    this->add_right(current->value, current->right->value);
                    tmp.push(current->right);

                }
            }
            return *this;
        }

        BinaryTree &operator=(BinaryTree &&other) noexcept
        {
            root = other.root;
            other.root = nullptr;
            return *this;
        }
BinaryTree& add_root(T value){
if (root != nullptr)
    {root->value = value;}
else
    {shared_ptr<Node> shared_root(new Node{value});
     root = shared_root;}
return *this;
}

BinaryTree& add_left(T parent,T value){ 
    if (root == nullptr) {throw std::logic_error("No root");}
    bool flag = false;
    for (auto it=(*this).begin_preorder(); it!=(*this).end_preorder(); ++it){

        if((*it) == parent)
            { 
                if (it.current->left != nullptr)
                    {
                        it.current->left->value = value;
                    flag = true;
                   
                }
                else 
                    {
                        shared_ptr<Node> left_node (new Node(value));
                     it.current->left = left_node;
                     flag = true;
                     }
             break;
            }     
    }
    if (!flag) {throw std::logic_error("Node not found");}   
        return *this;
}

BinaryTree& add_right(T parent,T value){
  bool flag = false;
    for (auto it=(*this).begin_preorder(); it!=(*this).end_preorder(); ++it){
       
       if((*it) == parent)
            {
   
                if (it.current->right != nullptr)
                    {it.current->right->value = value;
                    flag = true;}
                else 
                    {shared_ptr<Node> right_node (new Node(value));
                     it.current->right = right_node;
    
                     flag = true;
               }
            }   
    }
    if (!flag) {throw std::logic_error("Node not found");}

    return *this;
}

preorder_iterator begin_preorder(){
     if(root == nullptr) {
		return preorder_iterator();
    }
    return preorder_iterator(root);}
    
preorder_iterator end_preorder(){
    return preorder_iterator();
}

inorder_iterator begin(){
    if(root == nullptr) {
		return inorder_iterator();
    }
    return inorder_iterator(root);
    }

inorder_iterator end(){
    return inorder_iterator();
    }


inorder_iterator begin_inorder(){
     if(root == nullptr) {
		return inorder_iterator();
    }

    return inorder_iterator(root);}
    

inorder_iterator end_inorder(){
    return inorder_iterator();
    }

postorder_iterator begin_postorder(){
     if(root == nullptr) {
		return postorder_iterator();
    }

return postorder_iterator(root);}
    

postorder_iterator end_postorder(){
    return postorder_iterator();
    }

friend ostream& operator<<(ostream& os, BinaryTree& b_tree){
    
    if (b_tree.root == nullptr){
        os << "null";
    }
    else{
    int counter = 0;
    
    shared_ptr<Node> curr = b_tree.root;
    queue <shared_ptr<Node>> n_queue;
    n_queue.push(curr);
    
    while(curr->left)
    {
     curr = curr->left;
     counter++;
    }
    
    while(n_queue.empty() == false)
    {
        int node_count = n_queue.size();
        while (node_count > 0)
        {
            shared_ptr<Node> node = n_queue.front();
            os << node->value << " ";
            n_queue.pop();
            
            if (node->left != NULL)
                {n_queue.push(node->left);}
            
            if (node->left != NULL)
                {n_queue.push(node->left);}
            node_count--; 
        }
        os << endl;
    }

    }

    return os;
    };


};

}