#include <iostream>
#include <vector>
using namespace std;

struct Node {
	string data;
	Node* link;
};

void Insert(Node*& head,string a) {
	Node* newNode = new Node();
	newNode->data = a;
	newNode->link = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node* current = head;
		while (current->link != nullptr) {
			current = current->link;
		}
		current->link = newNode;
	}
}

Node* getTheList(string abc) {
	Node* head = new Node();
	head->link = nullptr;
	for (int i = 0; i < abc.length(); i++) {
		if (i == 0) {
			head->data = abc.substr(i, 1);
		}
		else {
			Insert(head, abc.substr(i, 1));
		}
	}
	return head;
}

void Reserve(Node*& head) {
	Node* prev = nullptr;
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->link;
		current->link = prev;
		prev = current;
		current = nextNode;
	}
	head = prev;
}

void showList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		cout << current->data;
		current = current->link;
	}
	cout << endl;
}



int main() {
	int N = 0;
	while (cin >> N) {
		vector<string> stringArr(N);
		vector<Node*> listArr(N);
		for (int i = 0; i < N; i++) {
			cin >> stringArr[i];    //一开始输入的字符串将其存储为数组 stringArr[0]为第一个输入的字符串.
		}
		for (int i = 0; i < N; i++) {
			listArr[i] = getTheList(stringArr[i]);//将输入的字符串全部转换为链表.这个链表的每个头结点都会被存储.
			Reserve(listArr[i]);
		}
		for (int i = 0; i < N; i++) {
			showList(listArr[i]);
		}
	}
}