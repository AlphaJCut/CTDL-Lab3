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
	if (p == nullptr)
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
	if (IsEmpty(S))
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
bool Pop(Stack& S, int& popdata)
{
	if (IsEmpty(S))
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
void PrintStack(const Stack& S)
{
	Node* current = S.head;
	while (current != nullptr)
	{
		cout << current->data << "\t";
		current = current->next;
	}
	cout << endl;
}

//Chuyen doi nhi phan//
void DecimaltoBinary(int number)
{
	Stack s;
	while (number > 0)
	{
		int remain = number % 2;
		Push(s, remain);
		number = number / 2;
	}
	while (!IsEmpty(s))
	{
		int NhiPhan;
		Pop(s, NhiPhan);
		cout << NhiPhan;
	}
	cout << endl;
}

int main()
{
	int so;
	do
	{
		cout << "Nhap so ban muon thanh nhi phan: ";
		cin >> so;
		if (so < 0)
			cout << "Moi ban nhap so nguyen duong. " << endl;
	} while (so < 0);
	DecimaltoBinary(so);
	system("pause");
	return 0;
}