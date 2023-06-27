//https://www.codingninjas.com/codestudio/problems/linked-list-cycle-ii_8230823?challengeSlug=striver-sde-challenge&leftPanelTab=0

/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.

    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    int flag = 0;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            flag = 1;
            break;
        }
    }

    if(flag){
        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
    return NULL;
}
