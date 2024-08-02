#include <iostream>
using namespace std;
//Khai bao Node//
struct Node
{
	int data;
	Node* next;
};
//Khai bao Stack//
struct Stack
{
	Node* head;
	Stack() : head(nullptr) {}
};
//Kiem tra Stack rong//
bool IsEmpty(Stack S) 
{
	return S.head == nullptr;
}
//Tao Node//
Node* CreateNode(int data) 
{
	Node* p = new Node();
	if(p ==nullptr)
	{
		return nullptr;
	}
	p->data = data;
	p->next = nullptr;
	return p;
}
//Them phan tu vao dau//
void Push(Stack& S, int data) {
	Node* ptr = CreateNode(data);
	//Kiem tra//
	if(IsEmpty(S))
	{
		S.head = ptr;
	}
	else
	{
		ptr->next = S.head;
		S.head = ptr;
	}
}
//Xoa nut//
bool Pop(Stack &S,int& popdata)
{
	if(IsEmpty(S))
	{
		cout << "Khong co danh sach stack. " << endl;
		return false;
	}
	Node* temp = S.head;
	popdata = temp->data;
	S.head = S.head->next;
	delete temp;
	return true;
}
//In stack//
void PrintStack(const Stack &S)
{
	Node* current = S.head;
	while (current!=nullptr)
	{
		cout << current->data << "\t";
		current = current->next;
	}
	cout << endl;
}

int main()
{
	Stack s; int value;
	while (true)
	{
		cout << "Nhap gia tri ban muon them vao nut (nhan -1 de stop): ";
		cin >> value;
		if (value == -1)
		{
			break;
		}
		Push(s, value);
		PrintStack(s);
	}
	cout << "Nhap gia tri ban muon xoa: ";
	int popvalue;
	if (Pop(s, popvalue)) {
		cout << "Gia tri da xoa: " << popvalue << endl;
	}
	else {
		cout << "Khong the xoa phan tu." << endl;
	}
	PrintStack(s);
	PrintStack(s);
	system("pause");
	return 0;
}