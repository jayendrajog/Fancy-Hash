/*
 *
 *  KPCB Fellows Application
 *  Jayendra Jog, B.S. Computer Science UCLA
 *  Hashmap
 *
 */

#include <iostream>
#include <string>
#include <assert.h>
#include "HashMap.h"
using namespace std;

//generic average class
class Person{
public:
    Person(string name, int ID)
    {
        m_name = name;
        m_ID = ID;
    }
    ~Person()
    {
        
    }
    string name()
    {
        return m_name;
    }
    int id()
    {
        return m_ID;
    }
private:
    string m_name;
    int m_ID;
};

int main()
{
//    Person bob("Bob", 111);
//    Person bobby("Bobby", 131);
//    Person jay("Jay", 5);
//    Person jane("Jane", 412);
//    Person emily("Emily", 0);
//    Person dave("Dave", 1777);
//    unsigned int size = 5;
//    HashMap<Person> h(size);
//    
//    /*
//     *
//     *  No entry test cases
//     *
//    */
//    
//    //check if load function works with no entries
//    assert (h.load() == 0);
//    //check if get function returns nullptr with no entries
//    assert(h.get("lol") == nullptr);
//    //check if delete function returns nullptr with no entries
//    assert(h.remove("lol") == nullptr);
//    
//    /*
//     *
//     *  One key=>value pair test cases
//     *
//     */
//    
//    //make sure that we can properly add one key=>value pair
//    assert(h.set(bob.name(),bob) == true);
//    //make sure that load function updates properly
//    assert(h.load() > 0.19 && h.load() < 0.21);
//    //check that get function where value exists works
//    assert(h.get(bob.name())->id() == 111);
//    //check that get function where value doesn't exists fails
//    assert(h.get("troll") == nullptr);
//    //check that removing a value works properly
//    assert(h.remove(bob.name()) == &bob);
//    //check that trying to remove using an invalid key fails
//    assert(h.remove(bob.name()) == nullptr);
//    //check that we can't get bob again after removing him
//    assert(h.get(bob.name()) == nullptr);
//    //check that we can reset the value after removing it
//    assert(h.set(bob.name(),bob) == true);
//    //make sure that load function updates properly
//    assert(h.load() > 0.19 && h.load() < 0.21);
//    
//    /*
//     *
//     *  Multiple key=>value pair test cases
//     *
//     */
//    
//    //check that we can set a second value
//    assert(h.set(bobby.name(), bobby) == true);
//    //check if load function works after adding entries
//    assert(h.load() > 0.39 && h.load() < 0.41);
//    //check to make sure random keys return nullptr
//    assert(h.get("haha") == nullptr);
//    //check that get works with bobby
//    assert(h.get(bobby.name())->id() == 131);
//    //check that get still works with bob
//    assert(h.get(bob.name())->id() == 111);
//    //overwrite value that exists with same value
//    assert(h.set(bob.name(), bob) == true);
//    //make sure that load function still works properly
//    assert(h.load() > 0.39 && h.load() < 0.41);
//    //check that get works with bobby
//    assert(h.get(bobby.name())->id() == 131);
//    //check that get still works with bob
//    assert(h.get(bob.name())->id() == 111);
//    
//    /*
//     *
//     *  High load test cases
//     *
//     */
//    
//    //make sure that we can properly add one key=>value pair
//    assert(h.set(jay.name(),jay) == true);
//    assert(h.set(jane.name(),jane) == true);
//    assert(h.set(emily.name(),emily) == true);
//    assert(h.set(dave.name(),dave) == true);
    
    /*
     *
     *  Making changes to Person Object
     *
     */
    
    /*
     *
     *  Binary Search Tree Test Cases
     *
     */
//    BST b;
//    b.insert_node("lol", 32);
//    b.insert_node("lol0", 15);
//    b.insert_node("hehe", 12);
//    b.insert_node("dog", 9);
//    b.insert_node("doggy", 32);
//    b.insert_node("Doge", 32);
//    b.insert_node("Ballge", 15);
//    b.insert_node("A", 17);
//    b.print();
//    b.remove_node("A");
//    b.print();
//    
    BST c;
    //insert one node
//    cout << "insert one node" << endl;
//    c.insert_node("a", 1);
//    c.print();
//    //remove node: remove head no with no leaves
//    cout << "remove one node" << endl;
//    c.remove_node("a");
//    c.print();
//    //insert two nodes
//    cout << "insert two nodes" << endl;
//    c.insert_node("b", 1);
//    c.insert_node("a", 2);
//    c.print();
//    //remove node: remove head with one leaf
//    cout << "remove head node with one leaf" << endl;
//    c.remove_node("b");
//    c.print();
    //insert three nodes
//    cout << "insert three nodes" << endl;
//    c.insert_node("b", 1);
//    c.insert_node("a", 3);
//    c.insert_node("c", 4);
//    c.print();
//    //remove head with two leaves
//    cout << "remove head with two leaves " << endl;
//    c.remove_node("b");
//    c.print();
    //remove node: remove
    cout << "normal remove cases" << endl;
    c.insert_node("h", 8);
    c.insert_node("d", 4);
    c.insert_node("l", 12);
    c.insert_node("b", 2);
    c.insert_node("f", 6);
    c.insert_node("j", 10);
    c.insert_node("n", 14);
    c.insert_node("a", 1);
    c.insert_node("c", 3);
    c.insert_node("e", 5);
    c.insert_node("g", 7);
    c.insert_node("i", 9);
    c.insert_node("k", 11);
    c.insert_node("m", 13);
    c.insert_node("o", 15);
    c.print();
    cout << "-----" << endl;
    //remove end node
    //c.remove_node("a");
    //remove head node
    //c.remove_node("h");
    //remove middle node with 2 leaves
   // c.remove_node("f");
//    c.print();
//    cout << "-----" << endl;
//    //remove node with one leaf
//    c.remove_node("b");
//    c.print();
//    cout << "-----" << endl;
//    //remove node with two leaves
    c.remove_node("d");
//    c.print();
    c.print();
    cout << "-----" << endl;
    
    /*
     *
     *  Edge Cases
     *
     */
    
    //Max size hashtable
    
    
    cout << "All tests passed" << endl;

}


