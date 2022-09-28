#include <string>
using namespace std;
#include <tuple>
#include <algorithm> 
#include <queue>
#include <list>
#include <unordered_map>

class LRUCache_USEstl
{
public:
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    LRUCache_USEstl(int capacity) : capacity{ capacity }
    {
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        li.splice(li.begin(), li, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            li.splice(li.begin(), li, mp[key]);
            mp[key]->second = value;
            return;
        }
        if (mp.size() == capacity)
        {
            int del_key = li.back().first;
            mp.erase(del_key);
            li.pop_back();
        }
        li.emplace_front(key, value);
        mp[key] = li.begin();
    }
};

//do not use STL
class LRUCache
{
    //https://www.youtube.com/watch?v=7ABFKPK2hD4
    //https://leetcode.com/problems/lru-cache/discuss/2405496/C%2B%2B-oror-Double-Linked-List-%2B-HashMap
    //https://leetcode.com/problems/lru-cache/discuss/2435409/Two-Different-C%2B%2B-approaches-fully-commented-code
public:
    class Node
    {
    public:
        int Key;
        int Value;
        Node* Prev;
        Node* Next;

        Node(int key, int value)
        {
            Key = key;
            Value = value;
        }

    };


    unordered_map<int, Node*> mp;
    int Capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache(int capacity)
    {
        Capacity = capacity;
        head->Next = tail;
        tail->Prev = head;

    }

    int get(int key)
    {
        if (mp.find(key) == mp.end()) return -1;

        Node* cur = mp[key];
        int foundVal = cur->Value;
        //if found, delete it first and add to head again for most recent accessed
        //head's next points to most recent used. tail points to least recent used
        //put current's next to head's next to be next least used
        //delete current
        //then add current to tail's prev
        mp.erase(key);
        deleteNode(cur);
        //addNode(new Node(key,foundVal));
        addNode(cur);
        mp[key] = head->Next;

        return foundVal;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
            delete node;
        }

        if (mp.size() == Capacity)
        {
            //remove the least recent used one
            Node* leastUsed = tail->Prev;
            mp.erase(leastUsed->Key);
            deleteNode(leastUsed);
            delete leastUsed;
        }


        //add the new value, set as latest updated
        addNode(new Node(key, value));
        mp[key] = head->Next;
    }

    void deleteNode(Node* node)
    {
        Node* r = node->Next;
        Node* l = node->Prev;
        l->Next = r;
        r->Prev = l;
        //delete node;
    }

    void addNode(Node* curr)
    {
        curr->Next = head->Next;
        curr->Prev = head;
        curr->Next->Prev = curr;
        head->Next = curr;
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */