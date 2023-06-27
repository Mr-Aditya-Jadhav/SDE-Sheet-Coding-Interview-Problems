//https://leetcode.com/problems/lfu-cache/description/

class node{
    public:
    int val,key,cnt;
    node * prev;
    node * next;
    node(int k,int v){
        key = k;
        val = v;
        cnt = 1;
    }
};

class List{
        public:
        int size;
        node * head;
        node * tail;
        List(){
            head = new node(0,0);
            tail = new node(0,0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addnode(node * newnode){
            node * temp = head->next;
            head->next = newnode;
            newnode->prev = head;
            newnode->next = temp;
            temp->prev = newnode;
            size++;
        }
        void delnode(node * del_node){
            node * delprev = del_node->prev;
            node * delnext = del_node->next;
            delnext->prev = delprev;
            delprev->next = delnext;
            size--;
        }
    };

class LFUCache{
    public:


    map<int,node*>mp;
    map<int,List*>li;
    int maxSize,currSize,minFr;

    LFUCache(int cap){
        maxSize = cap;
        currSize = 0;
        minFr=0;
    }

    void update(node * currnode){
        mp.erase(currnode->key);
        li[currnode->cnt]->delnode(currnode);
        if(currnode->cnt == minFr && li[currnode->cnt]->size == 0) minFr++;

        List * currList = new List();
        if(li.find(currnode->cnt+1) != li.end()) currList = li[currnode->cnt+1];
        currnode->cnt+=1;
        currList->addnode(currnode);
        mp[currnode->key]=currnode;
        li[currnode->cnt]=currList;
    }

    int get(int key){
        if(mp.find(key)!=mp.end()){
            node * resnode = mp[key];
            int res = resnode->val;
            update(resnode);
            return res;
        }
        return -1;
    }

    void put(int key,int value){
        if(maxSize == 0) return;
        else if(mp.find(key) != mp.end()){
            node * newnode = mp[key];
            newnode->val = value;
            update(newnode);
        }
        else{
            if(currSize == maxSize){
                List * list = li[minFr];
                mp.erase(list->tail->prev->key);
                li[minFr]->delnode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFr = 1;
            node * newnode = new node(key,value);
            List * minList = new List();
            if(li.find(minFr) != li.end()){
                minList = li[minFr];
            }
            minList->addnode(newnode);
            mp[key]=newnode;
            li[minFr]=minList;
        }
    }
};
