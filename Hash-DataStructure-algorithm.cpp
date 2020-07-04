#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//start the program 
class Database {
  struct Staff {
    int index;
    int id;
    string name;
    string position;
    Staff *next;
    Staff *prev;
    Staff *next_chain;
    Staff *prev_chain;
  };

private:
  Staff *head, *tail, *found;
  const int table_size = 100;

public:
  Database() { 
    head = NULL;
    tail = NULL;
    found = NULL;
    makeTable(); 
  }

  void makeTable() {
    for(int i = 0; i < table_size; i++) {
      Staff *n = new Staff; //n stand for new
      n->index = i;
      Staff *t = head; //t stand for traversal
      if (head == NULL) {
        head = n;
        n->prev = NULL;
        n->next = NULL;
        tail = n;
      }
      else {
        while (t->next != NULL) {
          t = t->next;
        }
        t->next = n;
        n->prev = t;
        n->next = NULL;
        tail = n;
      }
      n->next_chain = NULL;
      n->prev_chain = NULL;
      n->id = 0;
    }  
  }

  int menu() {
    int c; //c stands for choice;
    cout << "-----------------------------------------" << endl;
    cout << setw(27) << "SECTION: MENU" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Data Input" << endl;
    cout << "2. Data Location" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
    cin >> c;
    return c;
  }

  int trunc(int num) {
    int trunc_num = num % table_size;
    return trunc_num;
  }

  void newData() {
    cout << "-----------------------------------------" << endl;
    cout << setw(30) << "SECTION: DATA INPUT" << endl;
    cout << "-----------------------------------------" << endl;
    int c; //c stands for choice;
    int number;
    cout << "Enter Staff ID" << setw(10) << ": ";
    cin >> number;
    int trunc_id = trunc(number);
    Staff *current = newStaff(trunc_id);
    current->id = number;
    cout << "Enter Staff Name" << setw(8) << ": ";
    cin.ignore();
    getline (cin, current->name);
    cout << "Choose Staff Position"<< setw(3) << ": " << endl;
    cout << setw(17) << "1. Dean" << endl;
    cout << setw(24) << "2. Deputy Dean" << endl;
    cout << setw(31) << "3. Head of Department" << endl;
    cout << setw(28) << "4. Head of Program" << endl;
    cout << setw(21) << "5. Lecturer" << endl;
    cout << "Enter choice: ";
    cin >> c;
    switch (c) {
    case 1:
      current->position = "Dean";
      break;
    case 2:
      current->position = "Deputy Dean";
      break;
    case 3:
      current->position = "Head of Department";
      break;
    case 4:
      current->position = "Head of Program";
      break;
    case 5:
      current->position = "Lecturer";
      break;
    }
    cout << "You choose " << current->position << "." << endl;
  }

Staff* newStaff(int num) {
    Staff *t = head;
    while (t->index != num) {
      t = t->next;
    }
    if (t->id != 0) {
      t = makeChain(t);
    }
    return t;
  }

  Staff* makeChain(Staff *first) {
    Staff *n = new Staff; //n stand for new
    n->index = first->index;
    Staff *t = first; //t stand for traversal
    while (t->next_chain != NULL) {
      t = t->next_chain;
    }
    t->next_chain = n;
    n->prev_chain = t;
    n->next_chain = NULL;
    n->next = NULL;
    n->prev = NULL;
    return n;
  }

  void showLocation() {
    int number;
    cout << "----------------------------------------" << endl;
    cout << setw(31) << "SECTION: DATA LOCATION" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Enter ID no" << setw(9) << ": ";
    cin >> number;
    search(number);
    cout << "Result: ";
    if (found == NULL) {
      cout << "Invalid ID. No such data stored." << endl;
    }
    else {
      cout << endl;
      cout << "Staff ID" << setw(12) << ": " << found->id << endl;
      cout << "Staff Name" << setw(10) << ": " << found->name << endl;
      cout << "Staff Position" << setw(6) << ": " << found->position << endl;
      cout << "Storage Location" << setw(10) << ": Index " << found->index << endl;
    }
  }

  void search(int num) {
    found = NULL;
    int trunc_id = trunc(num);
    Staff *t = head;
    while (t->index != trunc_id) {
      t = t->next;
    }
    while (t != NULL) {
      if (t->id == num) {
        found = t;
        break;
      }
      t = t->next_chain;
    }
  }

};

int main() {
  int choice;
  Database uni10;
  do {
    choice = uni10.menu();
    switch (choice) {
      case 1:
        uni10.newData();
        break;
      case 2:
        uni10.showLocation();
        break;
    }
  } while (choice != 3);
  cout << "Thank You and Goodbye.";
  return 0;
}