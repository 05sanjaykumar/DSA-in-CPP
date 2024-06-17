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
int main()
{
    vector<int> vect = {1,2,3,4};
    Node* head = convertArr(vect);
    cout << head->next->val;
}