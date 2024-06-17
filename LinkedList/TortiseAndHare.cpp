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
int findMiddle(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast->next!=nullptr)
    {
        if(fast->next->next!= nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        else
        {
            break;
        }
    }
    return slow->val;
}
int main()
{
    vector<int> even = {1,2,3,4};
    vector<int> odd = {1,2,3,4,5};
    Node* headO = convertArr(odd);
    Node* headE = convertArr(even);
    int valE = findMiddle(headE);
    int valO = findMiddle(headO);
    cout << "The value of even is :"<<valE<<endl;
    cout << "The value of odd is :"<<valO<<endl;
}