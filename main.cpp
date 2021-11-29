#include "std_lib_facilities.h"	

//vector to store the numbers
vector<string> numbers;

//Prototype Functions Here
int get_number();
void initialize_numbers();


int main()
try{
    //initialize numbers by calling the function
	initialize_numbers();
    //display message for the user to enter input
	cout<< "Enter two floating-point values separated by an operator\n Enter any operator included on this list: (+ - * / %): ";
	//run the program until something unexpected is entered by the user, or it fails to do the operation
	while (true) {
        //declare variables here
        //get value1
		int value1 = get_number();
		char operation = 0;
        //get operation
		cin>>operation;
        //get value2
		int value2 = get_number();
        //string to be used for printing
		string oper;
		double result;
        //check each case for operation and perform tasks accordingly
		switch (operation) {
		case '+':
            //add operation
			oper = "the result of the sum of ";
			result = value1+value2; 
			break;
		case '-':
            //subtract operation
			oper = "the result of the difference between ";
			result = value1-value2; 
			break;
		case '*':
            //multiply operation
			oper = "the product of ";
			result = value1*value2; 
			break;
		case '/':
            //division operation
			oper = "the result of the division of ";
			if (value2==0) error("trying to divide by zero");
			result = value1/value2; 
			break;
		case '%':
            //remainder operation
			oper = "the remainder of ";
            //check if the second value is zero
			if (value2==0){
                //second value is zero
                //display error message
                error("trying to divide by zero (%)");
            }
			result = value1%value2; 
			break;
		default:
            //display error message
			error("you entered an invalid operator");
		}
        //display result
		cout << oper << value1 << " and " << value2 << " is " << result << '\n';
        //try again
		cout << "Try again: ";
	}
}
//display error messages
catch (runtime_error e) {
	cout << e.what() << '\n';
	keep_window_open("~");
}
//produce error messages
catch (...) {
	cout << "exiting\n";
	keep_window_open("~");
}
//method to get the number entered by the user
int get_number(){
    //declare variables here
	const int not_symbol = numbers.size();
    string s;
	int value = not_symbol;
    //try to read a digit
	if (cin>>value){
        //is digit, so return value
        return value;
    }
    //clear string to read an integer
	cin.clear();
    //read input
	cin>>s;
	for (int i=0; i<numbers.size(); ++i){
        //check if the string is a number by checking the vector
        if (numbers[i]==s){
            //the string is a number
            //value gets the number
            value = i;
        }
    }
    //check if the value is not a number
	if (value==not_symbol){
        //value is not a number
        //display error message
        error("number string is not a single-digit number: ", s);
    }
    //return value
	return value;
}
//method to initialize the numbers from 'zero' to 'ten'
void initialize_numbers(){
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");
	numbers.push_back("ten");
}