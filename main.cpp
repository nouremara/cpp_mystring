// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Own string Class

/**============================================================================
 * @file        : main.cpp
 * @brief       : test of own implementation of string class
 * @author      : Nour Ahmed
 * @email       : nahmed@stud.hs-bremen.de, nour
 * @repo        : https://github.com/nouremara/cpp_mystring
 * @repo        :
 * @createdOn   : 23.11.2022
 * @version     : 1.0.0
 * @description : 
 *
 * Defines the entry point for the NourUtilString application
 * In this application the class util::string is used and tested.
 * Each method and operator is tested with all possible uasges (e.g.,
 * concatenating different strings etc.)
 * Note: For this task no error handling is required.Example: Accessing
 * an invalid index by using operator []
 *==========================================================================**/

#include "utilstring.h"

#include <iostream>

int main() {
	char charArray[] = "text in a const char array";
	std::string stdString("another text in a std::string");

	// instantiate objects
	util::string string1;
	util::string string2("initializing with const char array");
	util::string string3(charArray);
	util::string string4(stdString);
	util::string string5(string4);

	util::printHeader("NourUtilString Application");
	std::cout << "\033[1;30;106m- Nour Ahmed                                                                  -" << std::endl;
	std::cout << "- Matrikal-Nr.: 5200991                                                       -" << std::endl;
	std::cout << "- Assignment 1 - Own string Class                                             -" << std::endl;
	std::cout << "-------------------------------------------------------------------------------\033[0m\n\n";

	// Test Object Instantiation ----------------------------------------------
	util::printSubHeader("Variable used for testing and their values");
	std::cout << "Variable used for testing and their values" << std::endl;

	util::printTestCase("charArray");
	std::cout << "charArray (size: " << util::string::rawSize(charArray) << ")  : " << charArray << std::endl;
	
	util::printTestCase("stdString");
	std::cout << "charArray (size: " << stdString.length() << ")  : " << stdString << std::endl;

	std::cout << "-------------------------------------------------------------------------------\n\n";

	util::printSubHeader("Test object constructors and initialization");

	util::printTestCase("default constructor");
	std::cout << "\tstring1 (size: " << string1.size() << ")  : " << string1 << std::endl;
	
	util::printTestCase("constructor with const char*");
	std::cout << "string2 (size: " << string2.size() << ") : " << string2 << std::endl;
	
	util::printTestCase("constructor with std::string");
	       std::cout << "string3 (size: " << string3.size() << ") : " << string3 << std::endl;
	
	util::printTestCase("constructor with char array");
	std::cout << "string4 (size: " << string4.size() << ") : " << string4 << std::endl;
	
	util::printTestCase("constructor with util::string");
	std::cout << "string5 (size: " << string5.size() << ") : " << string4 << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";


	// Test member methods ---------------------------------------------------------
	util::printSubHeader("Test Member Methods");


	util::printTestCase("length()");
	std::cout << "string2 (size: " << string2.size() << ", capacity: " << string2.capacity() << ") : " << string2 << std::endl;
	
	util::printTestCase("size()");
	std::cout << "string2 (size: " << string2.size() << ", capacity: " << string2.capacity() << ") : " << string2 << std::endl;

	util::printTestCase("capacity()");
	std::cout << "string2 (size: " << string2.size() << ", capacity: " << string2.capacity() << ") : " << string2 << std::endl;

	util::string temp = string2.substr(3, 5);
	util::printTestCase("substr()");
	std::cout << "string2.substr(3,5) \t -> " << temp << std::endl;

	util::printTestCase("c_str()");
	std::cout << "string2.c_str() \t -> " << string2.c_str() << std::endl;

	string2.clear();
	util::printTestCase("clear()");
	std::cout << "string2.clear() -> string2 (size: " << string2.size() << ", capacity: " << string2.capacity() << ") : content: " << string2 << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

	// Test operators ---------------------------------------------------------
	util::printSubHeader("Test operators");

	util::printTestCase("operator <<");
	std::cout << "std::cout << util::string << int << std::string << char *:\n"
		<< "    string3 (size: " << string3.size() << ", capacity: " << string3.capacity() << ") : content: " << string3
		<< stdString << ", "
		<< charArray
		<< std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

	util::printTestCase("operator +");
	std::cout << "\n\tutil::string + util::string \t: string2 + string3 -> " << string2 + string3 << std::endl;

	string5 = string5 + " see how + operator with char * works";
	std::cout << "\tutil::string + const char* \t: string5 = string5 + const char* -> (size: "	<< string5.size() << ") : " << string5;
	std::cout << "\n-------------------------------------------------------------------------------\n\n";

	string4 += string3;
	util::printTestCase("operator +=");
	std::cout << "\n\twith util::string\t: string4 += string3 -> (size: " << string4.size() << ") : " << string4 << std::endl;

	string4 += " here += operator is used to add more text in char *";
	std::cout << "\twith const char* \t: string4 += const char* -> (size: " << string4.size() << ") : " << string4 << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";


	string1 = string4;
	string2 = "more text for testing";
	string3 = std::string("text for std::string assignment");

	util::printTestCase("operator =");
	std::cout << "\n\tutil::string = util::string\t string1 = string4 -> string1 (size: " << string1.size() << "): " << string1 << std::endl;
	std::cout << "\tutil::string = const char* \t string2 = \"...\" -> string2 (size: " << string2.size() << "): " << string2 << std::endl;
	std::cout << "\tutil::string = std::string \t string3 = std::string(\"...\") -> string3 (size: " << string3.size() << "): " << string3 << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

	string1 = string2;
	util::printTestCase("operator ==");
	std::cout << "\n\tutil::string == util::string \t string1   == string2   -> " << ((string1 == string2) ? "true" : "false") << std::endl;
	std::cout << "\tutil::string == std::string  \t string1   == stdString -> " << ((string1 == stdString) ? "true" : "false") << std::endl;
	std::cout << "\tstd::string  == util::string \t stdString == string1   -> " << ((stdString == string1) ? "true" : "false") << std::endl;
	std::cout << "\tutil::string == const char*  \t string1   == charArray -> " << ((string1 == charArray) ? "true" : "false") << std::endl;
	std::cout << "\tconst char*  == util::string \t charArray == string1   -> " << ((charArray == string1) ? "true" : "false") << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

	util::printTestCase("operator !=");
	std::cout << "\n\tutil::string != util::string \t string1   != string2   -> " << ((string1 != string2) ? "true" : "false") << std::endl;
	std::cout << "\tutil::string != std::string  \t string1   != stdString -> " << ((string1 != stdString) ? "true" : "false") << std::endl;
	std::cout << "\tstd::string  != util::string \t stdString != string1   -> " << ((stdString != string1) ? "true" : "false") << std::endl;
	std::cout << "\tutil::string != const char*  \t string1   != charArray -> " << ((string1 != charArray) ? "true" : "false") << std::endl;
	std::cout << "\tconst char*  != util::string \t charArray != string1   -> " << ((charArray != string1) ? "true" : "false") << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

	util::printTestCase("operator []");
	std::cout << "\n\tstring1: " << string1 << "-> string1[0]: " << string1[0] << std::endl;
	std::cout << "\tstring2: " << string2 << "-> string2[3]: " << string2[3] << std::endl;
	std::cout << "\tstring3: " << string3 << "-> string3[50]: " << string3[50] << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

    // Test utility functions
	util::printSubHeader("Test utility functions");
	
	char s1[100] = "programming ", s2[] = "is awesome";
	std::cout << "\ts1 (size: " << util::string::rawSize(s1) << ", capacity: 100) : content: " << s1 << std::endl;
	std::cout << "\ts2 (size: " << util::string::rawSize(s2) << ", capacity: "<< util::string::rawSize(s2)+1 <<") : content: " << s2 << std::endl;

	util::printTestCase("util::deepCopy()");
	util::deepCopy(s1, s2);
	std::cout << "\n\tdeepCopy(s1, s2) -> s1 (size: " << util::string::rawSize(s1) << ", capacity: 100) : content: " << s1 << std::endl;

	util::printTestCase("util::rawSize()");
	std::cout << "\n\tutil::string::rawSize(s1) -> " << util::string::rawSize(s1) << std::endl;

	util::printTestCase("util::string::compare()");
	std::cout << "\n\tutil::string::compare(s1,s2) -> " << util::string::compare(s1, s2) << std::endl;
	std::cout << "\tutil::string::compare(s1,s1) -> " << util::string::compare(s1, s1) << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

	util::printSubHeader("Test utility functions");
	util::printTestCase("util::printHeader()");		std::cout << std::endl;
	util::printTestCase("util::printSubHeader()");  std::cout << std::endl;
	util::printTestCase("util::printTestCase()");   std::cout << std::endl;
	std::cout << "\tThese functions are used to print the above colored headers :)" << std::endl;
	std::cout << "-------------------------------------------------------------------------------\n\n";

	return 0;
}
