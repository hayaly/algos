#include <iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

int nthFromLast(Node *head, int n, int& value)
{
	if (NULL == head)
	{
		return 0;
	}
	
	int position = 1 + nthFromLast(head->next, n, value);
	
	if (position == n)
	{
		value = head->data;
	}
	
	return position;
}

int main()
{
	int nodeData[5] = {5, 3, 1, 2, 4};
	Node *head = NULL;

	Node *node0 = new Node();
	Node *node1 = new Node();
	Node *node2 = new Node();
	Node *node3 = new Node();
	Node *node4 = new Node();
	
	node0->data = nodeData[0];
	node1->data = nodeData[1];
	node2->data = nodeData[2];
	node3->data = nodeData[3];
	node4->data = nodeData[4];

	node0->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	
	head = node0;
	
	int value = -1;
	nthFromLast(head, 4, value);
	
	cout << "nth from end's data = " << value;
	
	return 0;
}