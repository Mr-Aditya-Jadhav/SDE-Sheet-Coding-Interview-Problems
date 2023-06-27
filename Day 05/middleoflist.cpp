//https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_8230764?challengeSlug=striver-sde-challenge&leftPanelTab=1

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    int count = 0;
    Node *curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;

    }
    
    

    int middle = (count/2)+1;

    Node *toret = head;
    
    for(int i = 0 ; i < middle-1; i++){
        toret = toret->next;
    }

    return toret;
}

