#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class Contact 
{
 	public:
    int entryNumber;
    string firstName;
    string lastName;
    string address;
    string contactNumber;
    Contact()  
	{
	       entryNumber=0;
	       firstName="";
	       lastName="";
	       address="";
	       contactNumber="";
	}
    Contact(int entry,string first,string last,string addr,string contact)
	{
		entryNumber=entry;
		firstName=first;
		lastName=last;
		address=addr;
		contactNumber=contact;
	}
    void display() const
	{
        cout<<setw(3)<<entryNumber<<setw(18)<<firstName<<setw(25)<<lastName<<setw(25)<<address<<setw(30)<<contactNumber<<endl;
    }
    int getEntryNumber() const
	{
        return entryNumber;
    }
    friend ostream& operator<<(ostream& os,Contact contact);
};
ostream& operator<<(ostream& os,Contact contact)
{
    os <<contact.entryNumber<<" "<<contact.firstName<<" "<<contact.lastName<<" "<<contact.address<<" "<<contact.contactNumber;
    return os;
}
class AddressBook
{
	private:
    vector<Contact>contacts;
	public:
    AddressBook() 
	{
        loadFromFile();
    }
    void addContact()
	{
        Contact newContact;
        cout << "----------------------Address Book-----------------------------" << endl << endl;
        cout << "Enter 'quit' at First name to quit" << endl << endl;
        cout << "Enter First Name: ";
        getline(cin,newContact.firstName);
        if (newContact.firstName == "quit")
            return;
        cout << "Enter Last Name: ";
        getline(cin, newContact.lastName);
        cout << "Enter Address: ";
        getline(cin, newContact.address);
        cout << "Enter Contact Number: ";
        getline(cin, newContact.contactNumber);
        bool isDuplicate = false;
        for (const Contact& contact : contacts)
		{
        	if (contact.contactNumber == newContact.contactNumber) 
			{
            	isDuplicate = true;
            	break;
        	}
        }
        if (isDuplicate) 
		{
        	cout << "Duplicate found. Contact cannot be inserted." << endl;
        } 
		else 
		{
        	if (contacts.size() >= 100) 
			{
            	cout << "Invalid! Maximum number of contacts reached (100)." << endl;
            	return;
        	}
        	newContact.entryNumber = contacts.size() + 1;
        	contacts.push_back(newContact);
        	cout << "Contact added successfully." << endl;
    	}
    }
      
    void deleteContact(int entryNumber)
	{
        auto it = find_if(contacts.begin(),contacts.end(),[&](const Contact& contact)
		{
            return contact.entryNumber == entryNumber;
        }
		);
        if (it != contacts.end())
		{
            contacts.erase(it);
            cout << "Contact with entry number " << entryNumber << " deleted successfully." << endl;
            for(int i = 0; i < contacts.size(); i++)
			{
                contacts[i].entryNumber = i + 1;
            }
        } 
		else
		{
            cout<<"Contact with entry number "<<entryNumber<<" not found."<<endl;
        }
    }
    void displayAllContacts() const 
	{
        cout << "----------------------Address Book-----------------------------" << endl;
        cout << setw(3) << "No." << setw(18) << "First Name" << setw(25) << "Last Name"
                  << setw(25) << "Address" << setw(30) << "Contact Number" << endl;

        for (const Contact& contact : contacts)
		{
            contact.display();
        }
    }
	void searchContact() const 
	{
        int choice;
        cout << "1.) First name" << endl;
        cout << "2.) Last name" << endl;
        cout << "3.) Address" << endl;
        cout << "4.) Contact " << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        string searchTerm;
        cout << "Enter search term: ";
        cin >> searchTerm;
        cout << "Search Results:" << endl;
        switch (choice) 
		{
            case 1:
                searchByFirstName(searchTerm);
                break;
            case 2:
                searchByLastName(searchTerm);
                break;
            case 3:
                searchByAddress(searchTerm);
                break;
            case 4:
                searchByContact(searchTerm);
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    void searchByFirstName(const string& term) const 
	{
        for (const Contact& contact : contacts) 
		{
            if (contact.firstName == term) 
			{
                contact.display();
            }
        }
    }

    void searchByLastName(const string& term) const 
	{
        for (const Contact& contact : contacts) 
		{
            if (contact.lastName == term) 
			{
                contact.display();
            }
        }
    }

    void searchByAddress(const string& term) const 
	{
        for (const Contact& contact : contacts) 
		{
            if (contact.address == term) 
			{
                contact.display();
            }
        }
    }

    void searchByContact(const string& term) const 
	{
        for (const Contact& contact : contacts) 
		{
            if (contact.contactNumber == term) 
			{
                contact.display();
            }
        }
    }
    void editContact() 
	{
       int choice;
        cout << "Please type the Entry number that you wish to edit: ";
        cin >> choice;
        cout << endl;
		auto it = find_if(contacts.begin(), contacts.end(), [choice](const Contact& contact) 
		{
        return contact.getEntryNumber() == choice;
    	});

    	if (it != contacts.end()) 
		{
            it->display();
            cout << "Is this the contact that you wish to edit? (y or n) ";
            char choice3;
            cin >> choice3;
            cout << endl;
            if (choice3 == 'y'||choice3=='Y') 
			{
                cout << "Enter New First name: ";
                cin >> it->firstName;
                cout << "Enter New Last name: ";
                cin >> it->lastName;
                cout << "Enter New Address: ";
                cin >> it->address;
                cout << "Enter New Contact: ";
                cin >> it->contactNumber;
                saveToFile();
                cout << "Contact edited successfully!" << endl;
            } 
			else 
			{
                cout << "Editing canceled." << endl;
            }
        } 
		else 
		{
            cout << "Entry not found." << endl;
        }
    }
    void loadFromFile()
	{
        ifstream file("Addressbook.txt");
        if (file.is_open())
		{
            int entry;
            string first, last, addr, contact;
            while (file >> entry >> first >> last >> addr >> contact) 
			{
                Contact newContact(entry, first, last, addr, contact);
                contacts.push_back(newContact);
            }
            file.close();
        }
    }

    void saveToFile() 
	{
        ofstream file("Addressbook.txt");
        if (file.is_open()) 
		{
            for (const Contact& contact : contacts) 
			{
                file << contact << endl;
            }
            file.close();
            cout << "Address book saved to file." << endl;
        } 
		else 
		{
            cout << "Error saving address book to file." << endl;
        }
    }
};

int main() 
{
    AddressBook addressBook;
    while (true) 
	{
        cout << endl;
        cout << "----------------------Address Book-----------------------------" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Delete Contact" << endl;
        cout <<	"4. Edit Contact"<< endl;
        cout << "5. Search for contact"<< endl;
        cout << "6. Save Address Book" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) 
		{
            case 1:
                cin.ignore();
                addressBook.addContact();
                break;
            case 2:
                addressBook.displayAllContacts();
                break;
            case 3:
                int entryNumber;
                cout << "Enter the entry number of the contact to delete: ";
                cin >> entryNumber;
                addressBook.deleteContact(entryNumber);
                break;
            case 4:
            	addressBook.editContact();
            	break;
            case 5:
            	addressBook.searchContact();
            	break;
            case 6:
                addressBook.saveToFile();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}