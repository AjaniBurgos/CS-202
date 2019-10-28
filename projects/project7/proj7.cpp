//Name: Ajani Burgos
//Date: 24 April 2017
//Purpose: To implement both an Array-based queue & a Node-based queue
#include <iostream>
#include "ArrayQueue.h"
#include "NodeQueue.h"

/*																										---FUNCTION DECLARATIONS---																								 */
bool menu();
void array_queue_test();
void node_queue_test();
/*********************************************************************************************************************************/
/*																											-----MAIN FUNCTION-----																									 */
/*********************************************************************************************************************************/
int main()
{
	bool loop_menu=true;
	std::cout << "This program acts as the test driver for Array queues and Node queues." << std::endl;
	while(loop_menu==true)
	{
		loop_menu=menu();
	}
	return 0;
}

/*																										---FUNCTION DEFINITIONS---																								 */
bool menu()
{
	int input;
	std::cout << "=========================================" << std::endl;
	std::cout << "Please select one of the following: " << std::endl;
	std::cout << "(1) - View the Array-based queue" << std::endl;
	std::cout << "(2) - View the Node-based queue" << std::endl;
	std::cout << "(3) - End program" << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "Option: ";
	std::cin >> input;
	std::cout << std::endl;
	switch(input)
	{
		case 1:
		array_queue_test();
		return true;
		break;
		case 2:
		node_queue_test();
		return true;
		break;
		case 3:
		std::cout << "Have a good day!" << std::endl;
		return false;
		break;
		default:
		std::cout << "Invalid option entered." << std::endl;
		return true;
		break;
	}
}
void array_queue_test()
{
	//1
	std::cout << "Testing Default Constructor..." << std::endl;
	ArrayQueue<float> default_array();
	std::cout << "Default Constructor successful!" << std::endl;
	//2
	std::cout << "Testing Parameterized Constructor..." << std::endl;
	ArrayQueue<int> parameterized_array(5,0);
	std::cout << "Parameterized Constructor successful!" << std::endl;
	//3
	std::cout << "Testing Copy Constructor..." << std::endl;
	ArrayQueue<int> copy_array(parameterized_array);
	std::cout << "Copy Constructor successful!" << std::endl;
	//(4)
	std::cout << "Testing Destructor..." << std::endl;
	ArrayQueue<int>* aq_ptr = NULL;
	delete aq_ptr;
	std::cout << "Destructor successful!" << std::endl << std::endl;

	//5
	std::cout << "Testing Assignment(=) Operator..." << std::endl;
	ArrayQueue<int> assignment_array=copy_array;
	std::cout << "Assignment Operator successful!" << std::endl << std::endl;

	//6
	std::cout << "Testing 'front' function..." << std::endl;
	assignment_array.front();
	std::cout << "'front' function successful!" << std::endl;
	//7
	std::cout << "Testing 'back' function..." << std::endl;
	assignment_array.back();
	std::cout << "'back' function successful!" << std::endl << std::endl;

	//8
	std::cout << "Testing 'pop' function..." << std::endl;
	assignment_array.pop();
	std::cout << "'pop' function successful!" << std::endl;
	//9
	std::cout << "Testing 'push' function..." << std::endl;
	assignment_array.push(5);
	assignment_array.push(10);
	assignment_array.push(15);
	std::cout << assignment_array << std::endl;
	std::cout << "'push' function successful!" << std::endl << std::endl;

	//10
	std::cout << "Testing 'size' function..." << std::endl;
	ArrayQueue<float> size_array(5,1.0);
	std::cout << "Size = " << size_array.size() << std::endl;
	std::cout << "'size' function successful!" << std::endl << std::endl;

	//14(xx)
	std::cout << "Testing extraction '<<' operator..." << std::endl;
	std::cout << size_array << std::endl;
	std::cout << "You probably saw that it was successful :^)" << std::endl;
}
void node_queue_test()
{
	NodeQueue<int> q1;
  q1.push(1);
  q1.push(2);
  q1.push(3);
  std::cout << "Q1_size:" << q1.size() << ", Q1:" << q1 << std::endl;

  NodeQueue<int> q2;
  q2.push(4);
  q2.push(5);
  q2.push(6);
  q2.push(7);
  std::cout << "Q2_size:" << q2.size() << ", Q2:" << q2 << std::endl;

  std::cout << "Setting Q2 = Q1" << std::endl;
  q2 = q1;
  std::cout << "Q2_size:" << q2.size() << ", Q2:" << q2 << std::endl;
}
