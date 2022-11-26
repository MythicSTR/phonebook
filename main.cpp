#include <iostream>
#include <cstring>

using namespace std;

class Node {
	public:
		char name[50];
		char address[50];
		char gmail[40];
		char number[20];
		Node * prev, * next;

		Node(char name[], char address[], char gmail[], char number[]) {
			strcpy(this->name, name);
			strcpy(this->address, address);
			strcpy(this->gmail, gmail);
			strcpy(this->number, number);

			prev = NULL;
			next = NULL;
		}

	friend class Phonebook;
};

class Phonebook {
	public:
		Node * head, * temp, * ptr;
		Node * ptr1, * ptr2, * ptr3;
	
		Phonebook() {
			head = NULL;
			temp = NULL;
			ptr = NULL;
			ptr1 = NULL;
			ptr2 = NULL;
			ptr3 = NULL;
		}

		void displayContacts();
		void insertContact();
		void deleteContact(char number[20]);
		void searchByName(char name[50]);
		void searchByNumber(char number[20]);
		void searchByGmail(char gmail[40]);
		void sortContacts();
		void updateContact(char number[20]);
};

// simple function for drawing lines between operations
void drawline() {
	cout << "-----------------------------------------------------------------------------------" << endl;
}

// Display all the contacts in the phonebook
void Phonebook::displayContacts() {
	ptr = head;
	int contactNo = 1;

	if(ptr == NULL) {
		cout << "Phonebook is empty. No records found!" << endl;
	}

	while(ptr != NULL) {
		cout << "Contact No. " << contactNo << endl;
		cout << "Name: " << ptr->name << endl;
		cout << "Address: " << ptr->address << endl;
		cout << "Gmail: " << ptr->gmail << endl;
		cout << "Number: " << ptr->number << endl;
		cout << endl;
		contactNo++;

		ptr = ptr->next;
	}
}

// Insert new contact to the phonebook
void Phonebook::insertContact() {
	char tempName[50];
	char tempAddress[50];
	char tempGmail[40];
	char tempNumber[20];

	cout << "Enter full name: "; cin.getline(tempName, 50);
	cout << "Enter address: "; cin.getline(tempAddress, 50);
	cout << "Enter gmail: "; cin.getline(tempGmail, 40);
	cout << "Enter number: "; cin.getline(tempNumber, 20);

	temp = new Node(tempName, tempAddress, tempGmail, tempNumber);
	if(head == NULL) {
		head = temp;
	} else {
		ptr = head;
		while(ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->prev = ptr;
	}

	cout << "Added new contact: " << tempNumber << endl;
}

// Delete the contact with given number
void Phonebook::deleteContact(char number[20]) {
	ptr = head;
	bool contactFound = false;

	while(ptr != NULL) {
		if(!strcmp(number, ptr->number)) {
			contactFound = true;
			break;
		}
		ptr = ptr->next;
	}
	
	if(!contactFound) {										// Contact is not in the list
		cout << "We didn't found any contact with the given number!" << endl;
	} else {
		if(ptr == head) {									// Contact is in the head of the list
			head = head->next;
			delete(ptr);
			cout << "Successfully deleted contact: " << number << endl;
		} else if(ptr->next == NULL) {						// Contact is in the end of the list
			ptr->prev->next = NULL;
			ptr->prev = NULL;
			delete(ptr);
			cout << "Successfully deleted contact: " << number << endl;
		} else if(ptr != head && ptr->next != NULL) {		// Contact is in between the list
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			delete(ptr);
			cout << "Successfully deleted contact: " << number << endl;
		}
	}
}

// Search contact by given name
void Phonebook::searchByName(char name[50]) {
	ptr = head;
	while(ptr != NULL) {
		if(!strcmp(ptr->name, name)) {				// Check if the given name is equal to the contact name
			cout << "Name: " << ptr->name << endl;
			cout << "Address: " << ptr->address << endl;
			cout << "Gmail: " << ptr->gmail << endl;
			cout << "Number: " << ptr->number << endl;
			cout << endl;

			return;									// exit out of the function if the contact is found
		}

		ptr = ptr->next;
	}
	
	cout << "Didn't found the contact with the given name" << endl;
}

// Search contact by given number 
void Phonebook::searchByNumber(char number[20]) {
	ptr = head;
	while(ptr != NULL) {
		if(!strcmp(ptr->number, number)) {				// Check if the given name is equal to the contact name
			cout << "Name: " << ptr->name << endl;
			cout << "Address: " << ptr->address << endl;
			cout << "Gmail: " << ptr->gmail << endl;
			cout << "Number: " << ptr->number << endl;
			cout << endl;

			return;									// exit out of the function if the contact is found
		}

		ptr = ptr->next;
	}
	
	cout << "Didn't found the contact with the given number" << endl;
}

// Search contact by the given gmail
void Phonebook::searchByGmail(char gmail[40]) {
	ptr = head;
	while(ptr != NULL) {
		if(!strcmp(ptr->gmail, gmail)) {				// Check if the given name is equal to the contact name
			cout << "Name: " << ptr->name << endl;
			cout << "Address: " << ptr->address << endl;
			cout << "Gmail: " << ptr->gmail << endl;
			cout << "Number: " << ptr->number << endl;
			cout << endl;

			return;									// exit out of the function if the contact is found
		}

		ptr = ptr->next;
	}
	
	cout << "Didn't found the contact with the given gmail" << endl;
}

void swap(Node * node1, Node * node2) {
	cout << "Swapping..." << endl;
	
	char tempName[50];
	char tempAddress[50];
	char tempGmail[40];
	char tempNumber[20];

	strcpy(tempName, node2->name);
	strcpy(tempAddress, node2->address);
	strcpy(tempGmail, node2->gmail);
	strcpy(tempNumber, node2->number);

	strcpy(node2->name, node1->name);
	strcpy(node2->address, node1->address);
	strcpy(node2->gmail, node1->gmail);
	strcpy(node2->number, node1->number);

	strcpy(node1->name, tempName);
	strcpy(node1->address, tempAddress);
	strcpy(node1->gmail, tempGmail);
	strcpy(node1->number, tempNumber);
}

void Phonebook::sortContacts() {
	int swapped;

	if(head == NULL) {
		cout << "The phonebook is empty!" << endl;
		return;
	}

	do {
		swapped = 0;
		ptr1 = head;
		ptr2 = NULL;

		while(ptr1->next != ptr2) {
			if(strcmp(ptr1->name, ptr1->next->name) > 0) {
				swap(ptr1, ptr1->next);

				swapped = 1;
			}
			ptr1 = ptr1->next;
		}

		ptr2 = ptr1;
	} while(swapped);
}

void Phonebook::updateContact(char number[20]) {
	char tempName[50];
	char tempAddress[50];
	char tempGmail[40];
	char tempNumber[20];
	ptr = head;	

	while(ptr != NULL) {
		if(!strcmp(number, ptr->number)) {
			break;
		}
		ptr = ptr->next;
	}

	if(ptr == NULL) {
		cout << "Contact not found!" << endl;
		return;
	}

	cout << "Name: "; cin.getline(tempName, 50);	
	cout << "Address: "; cin.getline(tempAddress, 50);	
	cout << "Gmail: "; cin.getline(tempGmail, 40);	
	cout << "Number: "; cin.getline(tempNumber, 20);	

	if(strlen(tempName) != 0) {
		strcpy(ptr->name, tempName);
	}
	if(strlen(tempAddress) != 0) {
		strcpy(ptr->address, tempAddress);
	}
	if(strlen(tempGmail) != 0) {
			strcpy(ptr->gmail, tempGmail);
	}
	if(strlen(tempNumber) != 0) {
			strcpy(ptr->number, tempNumber);
	}
}

int main() {
	Phonebook phonebook;
	char name[50];
	char address[50];
	char gmail[40];
	char number[20];
	bool exit = false;
	int option;
	
	drawline();
	cout << "\t\tWELCOME TO C++ PHONEBOOK USING DOUBLY LINKED LIST" << endl;
	drawline();

	do {
		cout << "What do you want to do?" << endl;
		cout << "1. Insert Contact" << endl;
		cout << "2. Delete Contact" << endl;
		cout << "3. Display Contact" << endl;
		cout << "4. Search by Name" << endl;
		cout << "5. Search by Number" << endl;
		cout << "6. Search by Gmail" << endl;
		cout << "7. Sort Contacts (Ascending)" << endl;
		cout << "8. Update Contact" << endl;
		cout << "9. Exit Application" << endl;

		cout << "::"; cin >> option;
		cin.ignore();
		switch(option) {
			case 1:
				drawline();
				phonebook.insertContact();
				break;
			case 2:
				cout << "Enter the number you want to delete: "; cin.getline(number, 20);
				drawline();
				phonebook.deleteContact(number);
				break;
			case 3:
				drawline();
				phonebook.displayContacts();
				break;
			case 4:
				cout << "Enter the name of the contact: "; cin.getline(name, 50);
				drawline();
				phonebook.searchByName(name);
				break;
			case 5:
				cout << "Enter the number of the contact: "; cin.getline(number, 20);
				drawline();
				phonebook.searchByNumber(number);
				break;
			case 6:
				cout << "Enter the gmail of the contact: "; cin.getline(gmail, 40);
				drawline();
				phonebook.searchByGmail(gmail);
				break;
			case 7:
				drawline();
				phonebook.sortContacts();
				break;
			case 8:
				drawline();
				cout << "Enter the number of the contact: "; cin.getline(number, 20);
				phonebook.updateContact(number);
				break;
			case 9:
				drawline();
				exit = true;
				break;
		}
		drawline();
	} while(!exit);
}
