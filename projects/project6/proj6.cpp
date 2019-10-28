//Name: Ajani Burgos
//Purpose: To implement our understanding of list-based dynamic data structures
//Date: 14 April 2017
#include "ArrayList.h"
#include "NodeList.h"

/**********************************************************************************************************************/
/*                                                  -----MAIN FUNCTION-----                                           */
/**********************************************************************************************************************/
int main () {
  DataType test_data(5,5.0);

	cout << "ARRAY LIST:" << endl;
  cout << "Creating an ArrayList using default constructor" << endl;
  ArrayList al_default;
  cout << "Default constructor completed successfully" << endl;

  cout << "Creating an ArrayList using parameterized constructor" << endl;
  ArrayList al_paramaterized(5, test_data);
  cout << "Parameterized constructor completed successfully" << endl;

  cout << "Creating an ArrayList using copy constructor" << endl;
  ArrayList al_copy(al_paramaterized);
  cout << "Copy constructor completed successfully" << endl;

  cout << "Deleting an ArrayList using destructor" << endl;
	ArrayList* al_delete = new ArrayList();
  delete al_delete;
  al_delete = NULL;
  cout << "Deconstructor completed successfully" << endl;

  cout << "Testing assignment (=) operator" << endl;
	ArrayList al_assignment = al_copy;
	cout << "Assignment operator completed successfully" << endl;

	cout << "Testing extraction (<<) operator" << endl;
	cout << al_assignment << endl;
	cout << "I assume you saw that it worked :^)" << endl;

	cout << "Testing 'first' function" << endl;
	al_assignment.first();
	cout << "First element found successfully" << endl;

	cout << "Testing 'last' function" << endl;
	al_assignment.last();
	cout << "Last element found successfully" << endl;

	cout << "Testing 'find' function" << endl;
	DataType* previous=NULL;
	DataType find_data(1,1.0);
	ArrayList al_find(10, test_data);
	cout << al_find.find(find_data, previous) << endl;
	cout << "Specific element found successfully" << endl;


	//SEND NODES
	cout << "\nNODE LIST:" << endl;
	cout << "Creating a NodeList using default constructor" << endl;
	NodeList nl_default;
	cout << "Default constructor completed successfully" << endl;

	cout << "Creating a NodeList using parameterized constructor" << endl;
	NodeList nl_parameterized(3, test_data);
	cout << "Parameterized constructor completed successfully" << endl;

	cout << "Creating a NodeList using copy constructor" << endl;
	NodeList nl_copy(nl_parameterized);
	cout << "Copy constructor completed successfully" << endl;
  return 0;
}
