#include<iostream>
#include<vector>

using namespace std;

class Node
{
    public:
    int val;
    Node* next;
    Node(int val, Node* next = nullptr)
    {
        this->val = val;
        this->next = next;
    }
};
Node* convertArr(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}
void Insert(Node* &head, int val, int pos)
{
    Node* newNode = new Node(val);   
    if(head == nullptr)
    {
        if(pos == 0)
        {
            head = newNode;
        }
        else
        {
            delete newNode;
            return;
        }
    }
    else
    {
        if(pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            int count = 0;
            Node* temp = head;
            while(temp != nullptr && count < pos - 1)
            {
                temp = temp->next;
                count++;
            }

            if(temp == nullptr)
            {
                delete newNode;  
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void Display(Node* head)
{
    Node* temp = head;
    while(temp!=nullptr)
    {
        cout<< temp->val<<" ";
        temp= temp->next;
    }
    cout<<endl;
}
void Delete(Node*& head, int val)
{
    if(head->val == val)
    {
        Node* tem = head;
        head = head->next;
        delete tem;
        return;
    }
    Node* temp = head;
    while(temp!=nullptr)
    {
        if(temp->next!=nullptr && temp->next->val == val)
        {
            Node* delt = temp->next;
            temp->next = temp->next->next;
            delete delt;
        }
        else
        {
            temp = temp->next;
        }
    }
}
int main()
{
    vector<int> vect = {1,2,3,4};
    Node* head = convertArr(vect);
    cout << "Before Deletion"<<endl;
    Display(head);
    cout << "After Deletion"<<endl;
    Delete(head,1);
    Display(head);
}