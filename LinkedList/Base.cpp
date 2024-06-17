#include <iostream>
#include <vector>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;

    Node(int data,Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};
int main()
{
    vector<int> vect;
    for(int i =1;i<=4;i++)
    {
        vect.push_back(i);
    }
    Node* one = new Node(vect[0]);
    Node* two = new Node(vect[1],one);
    cout << (two->next->data)<<endl;
    return 0;
}