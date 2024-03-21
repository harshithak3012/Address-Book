This code implements a basic address book application in C++. Here's a brief explanation of its functionality and structure:

Classes:

Contact: Represents a single contact with attributes like first name, last name, address, and contact number. It provides methods to display contact details and retrieve the entry number.
AddressBook: Manages a collection of Contact objects. It allows adding, deleting, editing, searching, displaying all contacts, and saving the address book to a file.
Main Function:

The main function initializes an AddressBook object.
It presents a menu-driven interface allowing users to perform various operations on the address book.
Options include adding a contact, displaying all contacts, deleting a contact by entry number, editing a contact, searching for contacts by different criteria, saving the address book to a file, and exiting the program.
Functionality:

Adding Contact: Prompts the user to input contact details and adds a new contact to the address book.
Displaying Contacts: Shows all contacts currently stored in the address book.
Deleting Contact: Allows the user to delete a contact by specifying its entry number.
Editing Contact: Enables editing an existing contact's details such as first name, last name, address, and contact number.
Searching Contacts: Supports searching for contacts by first name, last name, address, or contact number.
Saving Address Book: Writes the current state of the address book to a file named "Addressbook.txt".
File I/O:

The address book data is saved to and loaded from a text file named "Addressbook.txt".
When the program starts, it loads existing contacts from this file into memory.
When the user saves the address book, it writes the contacts back to the file.
Overall, this code provides a simple yet functional address book application allowing users to manage their contacts efficiently.
