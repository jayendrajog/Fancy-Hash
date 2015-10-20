/*
 *
 *  KPCB Fellows Application
 *  Jayendra Jog, B.S. Computer Science UCLA
 *  Hashmap
 *
 */

#ifndef HashTable_HashMap_h
#define HashTable_HashMap_h


#include <iostream>
#include <string>
using namespace std;

/* 
 *    Hashmap mapping string keys to arbitrary data object references
 *    Collision resolution achieved by moving to an empty data cell
 *    A self-balancing binary search tree is used internally
 *    to store the key values of remapped values
 *
 *    Once hashmap is full, no new entries can be added (stylistic decision
 *    based off the fact that you want 'set' to return boolean value indicating
 *    success)
 */

class BST{
public:
    BST()
    {
        m_head = nullptr;
    }
    ~BST()
    {
        FreeBST(m_head);
    }
    void insert_node(string key, int val)
    {
        //initialize the new node
        Node* added = new Node();
        added->left = nullptr;
        added->right = nullptr;
        added->m_key = key;
        added->index = val;
        added->height = 1;
        //empty BST case
        if (m_head == nullptr)
        {
            added->height = 0;
            m_head = added;
            return;
        }
        Node* cur = m_head;
        bool right;
        Node* next;
        if(key.compare(cur->m_key) > 0)
        {
            next = m_head->right;
            right = true;
        }
        else
        {
            next = m_head->left;
            right = false;
        }
        while(next != nullptr)
        {
            cur = next;
            if(key.compare(cur->m_key) > 0)
            {
                next = next->right;
                right = true;
            }
            else
            {
                next = next->left;
                right = false;
            }
            added->height++;
        }
        if(right)
        {
            cur->right = added;
        }
        else
        {
            cur->left = added;
        }
    }
    bool remove_node(string key)
    {
        //start iterating from the head
        Node* cur = m_head;
        if (cur == nullptr)
        {
            return false;
        }
        bool right = false;
        Node* next;
        //case go right
        if(key.compare(cur->m_key) > 0)
        {
            next = m_head->right;
            right = true;
        }
        else if (key.compare(cur->m_key) == 0)
        {
            if(cur->right != nullptr)
            {
                next = m_head->right;
            }
            else if(cur->left != nullptr)
            {
                next = m_head->left;
            }
        }
        //case go left
        else{
            next = m_head->left;
        }
        while(next != nullptr && next->m_key != key && cur->m_key != key)
        {
            cur = next;
            if(key.compare(cur->m_key) > 0)
            {
                next = next->right;
                right = true;
            }
            else
            {
                next = next->left;
                right = false;
            }
        }
        if((next == nullptr) && !(cur->m_key == key && cur == m_head))
            return false;
        //case: no leaves, head node being deleted
        else if(next == nullptr && cur->m_key != key)
        {
            delete cur;
            m_head = nullptr;
        }
        //case: one leaf, head node being deleted
        else if (cur == m_head && cur->m_key == key && (cur->left == nullptr || cur->right == nullptr))
        {
            m_head = next;
            delete cur;
        }
        //case: no leaves
        else if(next->left == nullptr && next->right == nullptr)
        {
            if(right)
            {
                cur->right = nullptr;
            }
            else
            {
                cur->left = nullptr;
            }
            delete next;
        }
        //case: one leaf under node
        else if (next->right == nullptr || next->left == nullptr)
        {
            if(next->right != nullptr)
            {
                if(right)
                {
                    cur->right = next->right;
                    delete next;
                }
                else{
                    cur->left = next->right;
                    delete next;
                }
            }
            else if (next->left != nullptr)
            {
                if(right)
                {
                    cur->right = next->left;
                    delete next;
                }
                else{
                    cur->left = next->left;
                    delete next;
                }
            }
        }
        //case: two leaves under node
        else{
            //replace with the node that is greater than all other nodes in the left subtree
            Node* beforegreatest = new Node;
            Node* greatestFromLeft = getGreatestFromLeft(cur, right, beforegreatest, key);
            //case no leaves
            if(greatestFromLeft->left == nullptr && greatestFromLeft->right == nullptr)
            {
                if(right)
                {
                    cur->right = greatestFromLeft;
                    if(beforegreatest->right->right == greatestFromLeft)
                    {
                        if(greatestFromLeft->left != nullptr)
                            beforegreatest->right = greatestFromLeft->left;
                        else if (greatestFromLeft->right != nullptr)
                            beforegreatest->right = greatestFromLeft->right;
                        else beforegreatest->right = nullptr;
                    }
                    else if(beforegreatest->right->left == greatestFromLeft)
                    {
                        if(greatestFromLeft->left != nullptr)
                            beforegreatest->left = greatestFromLeft->left;
                        else if (greatestFromLeft->right != nullptr)
                            beforegreatest->left = greatestFromLeft->right;
                        else beforegreatest->left = nullptr;
                    }
                }`
                else{
                    cur->left = greatestFromLeft;
                    if(beforegreatest->left->right == greatestFromLeft)
                    {
                        if(greatestFromLeft->left != nullptr)
                            beforegreatest->right = greatestFromLeft->left;
                        else if (greatestFromLeft->right != nullptr)
                            beforegreatest->right = greatestFromLeft->right;
                        else beforegreatest->right = nullptr;
                    }
                    else if(beforegreatest->left->left == greatestFromLeft)
                    {
                        if(greatestFromLeft->left != nullptr)
                            beforegreatest->left = greatestFromLeft->left;
                        else if (greatestFromLeft->right != nullptr)
                            beforegreatest->left = greatestFromLeft->right;
                        else beforegreatest->left = nullptr;
                    }

//                    if(beforegreatest->left->right == greatestFromLeft)
//                    {
//                        
//                    }
//                    else if(beforegreatest->left->left == greatestFromLeft)
//                    {
//                        
//                    }
                    
                }
//                if(beforegreatest->right == greatestFromLeft)
//                    beforegreatest->right = nullptr;
//                else
//                    beforegreatest->left = nullptr;
            }
            //case lowestfromleft
//            else if(greatestFromLeft->right == nullptr)
//            {
//                if(beforegreatest->right == greatestFromLeft)
//                    beforegreatest->right = greatestFromLeft->left;
//                else
//                    beforegreatest->left = greatestFromLeft->left;
//            }
//            //case greatestfromright
//            else if(greatestFromLeft->left == nullptr)
//            {
//                if(beforegreatest->left == greatestFromLeft)
//                    beforegreatest->left = greatestFromLeft->right;
//                else
//                    beforegreatest->right = greatestFromLeft->right;
//            }
            if(cur == m_head)
            {
                greatestFromLeft->left = cur->left;
                greatestFromLeft->right = cur->right;
                m_head = greatestFromLeft;
                delete cur;
                return true;
            }
            if (next->left != greatestFromLeft)
                greatestFromLeft->left = next->left;
            if (next->right != greatestFromLeft)
                greatestFromLeft->right = next->right;
            delete next;

        }
        return true;
    }
    
    void refactor();
    void print()
    {
        Node *start = m_head;
        inorder(start);
    }
       int find(string key);
private:
    struct Node{
        string m_key;
        int index;
        int height;
        Node* left;
        Node* right;
    };
    Node* m_head;
    void inorder(Node * n)
    {
        if(n == nullptr)
            return;
        inorder(n->left);
        cout << "key is " << n->m_key << " value is " << n->index << " height is " << n->height << endl;
        inorder(n->right);
    }
    Node * getGreatestFromLeft(Node* start, bool rightNode, Node* &beforegreatest, string key)
    {
        if (start == nullptr)
            return nullptr;
        beforegreatest = start;
        if (rightNode)
            start = start->right;
        else start = start->left;
        if(start->left != nullptr)
        {
            start = start->left;
            while(start != nullptr)
            {
                // cout << "node is " << start->m_key << endl;
                if(start->right != nullptr)
                {
                    if(start->m_key != key)
                        beforegreatest = start;
                    
                    start = start->right;
                   cout << "node is " << start->m_key << " and before node is " << beforegreatest->m_key << endl;
                }
                if(start->right == nullptr)
                    return start;
            }
        }
        //if no nodes on the left, then get the smallest node from the right side
        else if (start->right != nullptr)
        {
            start = start->right;
            while(start != nullptr)
            {
                if(start->left != nullptr)
                {
                    if(start->m_key != key)
                        beforegreatest = start;
                    
                    start = start->left;
                    cout << "node is " << start->m_key << " and before node is " << beforegreatest->m_key << endl;
                }
                if(start->left == nullptr)
                    return start;
            }
        }
        return nullptr;
    }
    void FreeBST(Node* n)
    {
        if(n != nullptr)
        {
            if (n->left != nullptr)
            {
                FreeBST(n->left);
            }
            if (n->right != nullptr)
            {
                FreeBST(n->right);
            }
            delete n;
            n = nullptr;
        }
        return;
    }
//    Node * getNodeBeforeGreatest(Node* start)
//    {
//        if (start == nullptr)
//            return nullptr;
//        if(start->left != nullptr)
//        {
//            start = start->left;
//            while(start != nullptr)
//            {
//                if(start->right->right != nullptr)
//                    start = start->right;
//                if(start->right->right == nullptr)
//                    return start;
//            }
//        }
//        //if no nodes on the left, then get the smallest node from the right side
//        else if (start->right != nullptr)
//        {
//            start = start->right;
//            while(start != nullptr)
//            {
//                if(start->left->left != nullptr)
//                    start = start->left;
//                if(start->left->left == nullptr)
//                    return start;
//            }
//        }
//        return nullptr;
//
//    }

};


template <typename ValueType>
class HashMap{
public:
    HashMap(unsigned int size);
    ~HashMap();
    bool set(const string& key, ValueType& value);
    ValueType * get(const string &key);
    //remove corresponds to the delete function specified by KPCB application
    ValueType * remove (const string &key);
    float load();
private:
    //Hashmaps shouldn't be copied or assigned, hence the respective operators
    //have been declared private
    HashMap(const HashMap&);
    HashMap& operator=(const HashMap&);
    ValueType** m_buckets;
    unsigned int m_numBuckets;
    //keeps track of number of filled buckets
    unsigned int m_numItems;
    unsigned int computeHash(const string& key);
    unsigned int getIndex(const string& key);
    
    //self balancing binary search tree
//    class BST{
//        public:
//        BST()
//        {
//            m_head = nullptr;
//        }
//        ~BST();
//        void insert_node(string key, int val)
//        {
//            Node* added = new Node();
//            added->left = nullptr;
//            added->right = nullptr;
//            added->m_key = key;
//            added->index = val;
//            added->height = 0;
//            if (m_head == nullptr)
//            {
//                m_head = added;
//                return;
//            }
//            Node* cur = m_head;
//            bool right;
//            Node* next;
//            if(key.compare(cur->m_key) > 0)
//            {
//                next = m_head->right;
//                right = true;
//            }
//            else
//            {
//               next = m_head->left;
//               right = false;
//            }
//            while(next != nullptr)
//            {
//                //if key > m_key
//                if(key.compare(cur->m_key) > 0)
//                {
//                    cur = cur->right;
//                }
//                else{
//                    cur = cur->left;
//                }
//                if(key.compare(cur->m_key) > 0)
//                {
//                    next = m_head->right;
//                    right = true;
//                }
//                else
//                {
//                    next = m_head->left;
//                    right = false;
//                }
//                added->height++;
//            }
//            if(right)
//            {
//                cur->right = added;
//            }
//            else
//            {
//                cur->left = added;
//            }
//        }
//        void remove_node(string key);
//        void refactor();
//        int find(string key);
//        private:
//        struct Node{
//            string m_key;
//            int index;
//            int height;
//            Node* left;
//            Node* right;
//        };
//        Node* m_head;
//        
//    };
};

template <typename ValueType>
unsigned int HashMap<ValueType>::computeHash(const string& key)
{
    //Using prime numbers to compute the hash function
    int hash = 7;
    unsigned long strlen = key.length();
    for (unsigned long letter = 0; letter < strlen; letter++)
    {
        hash = hash*31 + key[letter];
    }
    return hash;
}

/* 
 * Since hash might be larger than the number of buckets, this
 * turns the hash value into an array index
 */
template <typename ValueType>
unsigned int HashMap<ValueType>::getIndex(const string& key)
{
    unsigned int index = computeHash(key);
    index %= m_numBuckets;
    return index;
}

template <typename ValueType>
HashMap<ValueType>::HashMap(unsigned int size)
{
    //initializes all buckets with nullptrs
    m_buckets = new ValueType*[size]();
    m_numBuckets = size;
    m_numItems = 0;
}

template <typename ValueType>
HashMap<ValueType>::~HashMap()
{
    delete[] m_buckets;
}

/* 
 * Puts a value into the hashtable. If a value exists already in that spot, then
 * the old value gets overwritten. There's no reason this can fail, hence
 * it always returns true. 
 */
template <typename ValueType>
bool HashMap<ValueType>::set(const string& key, ValueType& value)
{
    unsigned int index = getIndex(key);
    //if an object exists already, then delete it
    if(m_buckets[index] != nullptr)
    {
        m_buckets[index] = nullptr;
        m_numItems--;
    }
    m_buckets[index] = &value;
    m_numItems++;
    return true;
}

template <typename ValueType>
ValueType * HashMap<ValueType>::get(const string& key)
{
    unsigned int index = getIndex(key);
    return m_buckets[index];
}

template <typename ValueType>
ValueType * HashMap<ValueType>::remove(const string& key)
{
    unsigned int index = getIndex(key);
    ValueType *temp = m_buckets[index];
    // only set to nullptr if there's something to delete
    if(temp != nullptr)
    {
        m_numItems--;
        m_buckets[index] = nullptr;
    }
    return temp;
}

template <typename ValueType>
float HashMap<ValueType>::load()
{
    float buckets = m_numBuckets;
    return m_numItems/buckets;
}


#endif
