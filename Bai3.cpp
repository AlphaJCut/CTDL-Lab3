#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int d) : data(d), next(nullptr) {}
};
struct Queue
{
	Node* top;
	Node* rear;
	int size;
	const int MAX = 100;
	//Constructor//
	Queue():top(nullptr),rear(nullptr),size(0){}
};
//Dieu kien//
bool IsEmpty(Queue &q)
{
	return q.top = nullptr;
}
bool IsFull(Queue &q)
{
	return q.size >= q.MAX;
}
//Them vao//
bool AddQueue(Queue&q, int data)
{
	if(IsFull(q))
	{
		cout << "Queue hien tai da day." << endl;
		return false;
	}
	Node* NewNode = new Node(data);
	if(IsEmpty(q))
	{
		q.top = q.rear = NewNode;
	}else
	{
		q.rear->next=NewNode;
		q.rear = NewNode;
	}
	++q.size;
	return true;
}
