#include<bits/stdc++.h>
using namespace std;

class HashTable {
    int capacity;
    list<pair<int, int>> *table;
public:
    string books[20] = {
        "The God of Small Things by Arundhati Roy",
        "Midnight's Children by Salman Rushdie",
        "A Suitable Boy by Vikram Seth",
        "The Namesake by Jhumpa Lahiri",
        "The White Tiger by Aravind Adiga",
        "Interpreter of Maladies by Jhumpa Lahiri",
        "The Palace of Illusions by Chitra Banerjee Divakaruni",
        "Train to Pakistan by Khushwant Singh",
        "The Inheritance of Loss by Kiran Desai",
        "The Guide by R.K. Narayan",
        "Shantaram by Gregory David Roberts",
        "The Lowland by Jhumpa Lahiri",
        "The Invention of Wings by Sue Monk Kidd (features an Indian character)",
        "The Immortals of Meluha by Amish Tripathi"
        "The Ministry of Utmost Happiness by Arundhati Roy",
        "The Palace of Illusions by Kavita Kane",
        "A Fine Balance by Rohinton Mistry",
        "The Glass Palace by Amitav Ghosh",
        "The Shadow Lines by Amitav Ghosh",
        "The Hungry Tide by Amitav Ghosh"
    };
    int book_id[20] = {
        101,
        102,
        103,
        104,
        105,
        106,
        107,
        108,
        109,
        110,
        111,
        112,
        113,
        114,
        115,
        116,
        117,
        118,
        119,
        120
    };
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    int searchKey(int key);
    int checkPrime(int n);
    int getPrime(int n);
    int hashFunction(int key);
    void displayHash();
    void displayBooks();
    int bookThere(int id);
};

HashTable::HashTable(int c) {
    int size = getPrime(c);
    this->capacity = size;
    table = new list<pair<int, int>>[capacity];
}

void HashTable::insertItem(int key, int data) {
    int index = hashFunction(key);
    table[index].push_back(make_pair(key, data));
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    int found_item = searchKey(key);
    if (found_item != -1)
    {
        list<pair<int, int>>& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                cout << "The book has been returned."<<endl;
                return;
            }
        }
    }
    else{
        cout << "There were no issued book under this PRN."<<endl;
        return;
    }
    
    
}

int HashTable::searchKey(int key) {
    int index = hashFunction(key);
    list<pair<int, int>>& bucket = table[index];
    for (const pair<int, int>& item : bucket) {
        if (item.first == key) {
            return item.second;
        }
    }
    return -1; // Key not found
}

void HashTable::displayHash() {
    for (int i = 0; i < capacity; ++i) {
        cout << "table[" << i << "]";
        for (const pair<int, int>& item : table[i]) {
            cout << " --> Key: " << item.first << ", Value: " << item.second;
        }
        cout << endl;
    }
}

int HashTable::checkPrime(int n) {
    if (n == 1 || n == 0) {
        return 0;
    }
    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int HashTable::getPrime(int n) {
    if (n % 2 == 0) {
        n++;
    }
    while (!checkPrime(n)) {
        n += 2;
    }
    return n;
}

int HashTable::hashFunction(int key) {
    return (key % capacity);
}


void HashTable::displayBooks(){
    
    int count = sizeof(book_id)/sizeof(int);
    for (int i = 0; i < count; i++)
    {
        cout << books[i] << ": " << book_id[i]<< endl;
    }
    return;
}
int HashTable::bookThere(int id){
    int found = 0;
    int loc = 0;
    int count = sizeof(book_id)/sizeof(int);
    for (int i = 0; i < count; i++)
    {
        if (id == book_id[i])
        {
            found = 1;
            loc = i;
        }
        
    }
    if (found==1)
    {   
        char ch;
        cout << "Do you want to issue{Y}/{N}: " << books[loc]<< endl;
        cin>>ch;
        if(ch == 'y' || ch == 'Y'){
            cout<<"Your book has been issued"<<endl;
            return 1;
        }else if(ch == 'n' || ch == 'N'){
            return 0;
        }else{
            cout<<"Please Enter a appropriate option"<<endl;
            bookThere(id);
        }
        
    }
    else{
        cout << "Book Not Found"<< endl;

        return 0;
    }
}
int main() {
    HashTable h(7); 

    while (true) {
        int choice;
        cout << "--------------------Library Management System--------------------\n";
        cout << "1. Display Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search for Student\n";
        cout << "5. Display Hash Table\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            h.displayBooks();
        }
        
        else if (choice == 2) {
            int key; 
            int value, found;
            cout << "Enter Student PRN: ";
            cin >> key;
            cout << "Enter Book ID: ";
            cin >> value;
            found = h.bookThere(value);
            if (found ==1)
            {
                h.insertItem(key, value);
            }else{
                continue;
            }
            
            
        } else if (choice == 3) {
            int key;
            cout << "Enter PRN: ";
            cin >> key;
            h.deleteItem(key);
            
            // if(ans){
            //     cout<<"Book has been successfully returned"<<endl;
            // }
            // else{
            //     cout<<"You have not issued a book yet!!!"<<endl;
            // }
        } else if (choice == 4) {
            int key;
            cout << "Enter PRN to Search: ";
            cin >> key;
            int foundValue = h.searchKey(key);
            if (foundValue != -1) {
                cout << "Student found. Book ID: " << foundValue << endl;
            } else {
                cout << "Student not found." << endl;
            }
        } else if (choice == 5) {
            h.displayHash();
        } else if (choice == 6) {
            break; 
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
