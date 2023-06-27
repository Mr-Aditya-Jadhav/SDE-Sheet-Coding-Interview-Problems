//https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    class node{
        public:
        int key;
        int value;
        node *next;
        node *prev;
        node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }

    };

    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int, node*>map;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        head->prev = NULL;
        tail->next = NULL;    
    }
    void addnode(node *newnode){
        node *temp = head->next;
        head->next = newnode;
        newnode->next = temp;
        newnode->prev = head;
        temp->prev = newnode;
    }
    void deletenode(node *delnode){
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;        
    }

    int get(int key_) {
        if(map.find(key_) != map.end()){
            node *resnode = map[key_];
            int res = resnode->value;
            map.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            map[key_] = head->next;
            return res;

        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(map.find(key_) != map.end()){
            node *existingnode = map[key_];
            map.erase(key_);
            deletenode(existingnode);
        }

        if(map.size() == cap){
            node * recnode = tail->prev;
            map.erase(recnode->key);
            deletenode(recnode);
        }

        node * toput = new node(key_, value);
        addnode(toput);
        map[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */