#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode(int value);
	bool search(int rollno, Node** Fakhruddin, Node** Abdurrafi);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode(int rollno) {
	Node* newNode = new Node();

	if (LAST == NULL) {
		LAST = newNode;
		LAST->next = newNode;
	}
	else {
		newNode->next = LAST->next;
		LAST->next = newNode;
		LAST = newNode;
	}

	cout << "Node dengan nilai " << rollno << " ditambahkan." << endl;
}

bool CircularLinkedList::search(int rollno, Node** Fakhruddin, Node** Abdurrafi) {
	if (LAST == NULL) {
		return false;
	}

	*Fakhruddin = LAST->next;
	*Abdurrafi = LAST->next;

	while (*Abdurrafi != LAST) {
		if (rollno == (*Abdurrafi)->rollNumber) {
			return true;
		}
		*Fakhruddin = *Abdurrafi;
		*Abdurrafi = (*Abdurrafi)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() {
	if (LAST == NULL) {
		return false;
	}

	Node* Fakhruddin = LAST;
	Node* Abdurrafi = LAST->next;

	if (Abdurrafi->next == NULL) {
		if (Abdurrafi == Abdurrafi->next) {
			delete Abdurrafi;
			LAST = nullptr;
		}
		else {
			Fakhruddin->next = Abdurrafi->next;
			delete Abdurrafi;
			LAST = Fakhruddin;
		}
		return true;
	}

	while (Abdurrafi != LAST->next) {
		if (Abdurrafi->next == NULL) {
			Fakhruddin->next = Abdurrafi->next;
			delete Abdurrafi;
			return true;
		}
		Fakhruddin = Abdurrafi;
		Abdurrafi = Abdurrafi->next;
	}

	return false;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* AbdurrafiNode = LAST->next;
		while (AbdurrafiNode != LAST) {
			cout << AbdurrafiNode->rollNumber << " " << AbdurrafiNode->name << endl;
			AbdurrafiNode = AbdurrafiNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}