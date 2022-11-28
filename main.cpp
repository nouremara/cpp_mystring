// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Own string Class

/**============================================================================
 * @file           :  main.h
 * @author         :  Nour Ahmed
 * @email          :  nahmed@stud.hs-bremen.de, nour
 * @repo           :
 * @createdOn      :  23.11.2022
 * @description    :  Defines the entry point for the application
 *
 *
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

    // header -----------------------------------------------------------------
  /*  for (int k = 1; k < 255; k++)
    {
        std::cout << "\n";
        std::cout << k << "\x1B[" << k << "m  Texting\033[0m\t\t";
    }*/


    util::printHeader("NourUtilString Application");
    std::cout << "- Nour Ahmed                                                     -" << std::endl;
    std::cout << "- Matrikal-Nr.: 5200991                                          -" << std::endl;
    std::cout << "- Assignment 1 - Own string Class                                -" << std::endl;
    std::cout << "-------------------------------------------------------------------------------\n\n";

    // Test Object Instantiation ----------------------------------------------
    util::printSubHeader("Variable used for testing and their values");
    std::cout << "Variable used for testing and their values" << std::endl;

    std::cout << " > [charArray]  charArray (size: " << util::string::rawSize(charArray) << ")  : " << charArray << std::endl;
    std::cout << " > [stdString]  charArray (size: " << stdString.length() << ")  : " << stdString << std::endl;

    std::cout << "-------------------------------------------------------------------------------\n\n";

    util::printSubHeader("Test object constructors and initialization");
    std::cout << " > [test with default constructors]  string1 (size: " << string1.size() << ")  : " << string1 << std::endl;
    std::cout << " > [test with const char*]           string2 (size: " << string2.size() << ") : " << string2 << std::endl;
    std::cout << " > [test with std::string]           string3 (size: " << string3.size() << ") : " << string3 << std::endl;
    std::cout << " > [test with char array]            string4 (size: " << string4.size() << ") : " << string4 << std::endl;
    std::cout << " > [test with util::string]          string5 (size: " << string5.size() << ") : " << string4 << std::endl;
    std::cout << "-------------------------------------------------------------------------------\n\n";


    // Test member methods ---------------------------------------------------------
    util::printSubHeader("Test Member Methods");
    util::string temp = string2.substr(3, 5);
    std::cout << " > [test substr()]           string2 (size: " << string2.size() << ") : " << string2 << std::endl;
    std::cout << " > [test substr()]           substr(3,5) (size: " << temp.size() << ") : " << temp << std::endl;



    std::cout << "-------------------------------------------------------------------------------\n\n";

    // Test operators ---------------------------------------------------------
    util::printSubHeader("Test operators");

    string1 = string2;
    string2 = "more text for testing";
    string3 = std::string("text for std::string assignment");

    std::cout << "[test = operator util::string = util::string]\n\t string1 = string2 -> string1 (size: " << string1.size() << "): " << string1 << std::endl;
    std::cout << "[test = operator util::string = const char*]\n\t string2 = \"...\" -> string2 (size: " << string2.size() << "): " << string2 << std::endl;
    std::cout << "[test = operator util::string = std::string]\n\t string3 = std::string(\"...\") -> string3 (size: " << string3.size() << "): " << string3 << std::endl;

    std::cout << "-------------------------------------------------------------------------------\n\n";

    string1 = string2;
    std::cout << "[test == operator util::string == util::string]\n\t string1 == string2   -> " << ((string1 == string2)?"true":"false") << std::endl;

    std::cout << "[test == operator util::string == std::string]\n\t string1 == stdString -> " << ((string1 == stdString) ? "true" : "false") << std::endl;
    std::cout << "[test == operator std::string == util::string]\n\t stdString == string1 -> " << ((stdString == string1) ? "true" : "false") << std::endl;

    std::cout << "[test == operator util::string == const char*]\n\t string1 == charArray -> " << ((string1 == charArray) ? "true" : "false") << std::endl;
    std::cout << "[test == operator const char* == util::string]\n\t charArray == string1 -> " << ((charArray == string1) ? "true" : "false") << std::endl;

    std::cout << "-------------------------------------------------------------------------------\n\n";

    std::cout << "[test != operator util::string != util::string]\n\t string1 != string2   -> " << ((string1 != string2) ? "true" : "false") << std::endl;

    std::cout << "[test != operator util::string != std::string]\n\t string1 != stdString -> " << ((string1 != stdString) ? "true" : "false") << std::endl;
    std::cout << "[test != operator std::string != util::string]\n\t stdString != string1 -> " << ((stdString != string1) ? "true" : "false") << std::endl;

    std::cout << "[test != operator util::string != const char*]\n\t string1 != charArray -> " << ((string1 != charArray) ? "true" : "false") << std::endl;
    std::cout << "[test != operator const char* != util::string]\n\t charArray != string1 -> " << ((charArray != string1) ? "true" : "false") << std::endl;
    std::cout << "-------------------------------------------------------------------------------\n\n";

    std::cout << "[test [] operator util::string[]]" << std::endl;
    std::cout << "\tstring1: " << string1 << "-> string1[0]: " << string1[0]<< std::endl;
    std::cout << "\tstring2: " << string2 << "-> string2[3]: " << string2[3] << std::endl;
    std::cout << "\tstring3: " << string3 << "-> string3[50]: " << string3[50] << std::endl;
    std::cout << "-------------------------------------------------------------------------------\n\n";

    //std::cout << " > [util::string + const char*]  string4 + charArray: " << string4 + charArray << std::endl;
    string2= string2 + string3;
    std::cout << "string2 (size: " << string2.size() << ") : " << string2 << std::endl;
    std::cout << "string3 (size: " << string3.size() << ") : " << string3 << std::endl;
    std::cout << " > [util::string + util::string]  string2 + string3: " << string2 + string3
         << "\nstring2 (size: " << string2.size() << ") : " << string2 << std::endl;


    std::cout << "-------------------------------------------------------------------------------\n\n";

    std::cout << "[test << operator std::cout << util::string << int << std::string << char *]:\n\t"
        << string1 << ", "
        << "size: "
        << string1.size() << ", "
        << stdString << ", "
        << charArray
        << std::endl;



    //std::cout << " > [util::string + const char*]  string4 + charArray: " << string4 + charArray << std::endl;

    //util::string string6(string4 + charArray);

    //std::cout << " > [test with util::string]          string6 (size: " << string6.size() << ") : " << string6 << std::endl;

    std::cout << "-------------------------------------------------------------------------------\n\n";

   //std::cout << " > [util::string + const char*]: " << util::concat(string4.c_str(), charArray) << std::endl;

    std::cout << "-------------------------------------------------------------------------------\n\n";

    char s1[100] = "programming ", s2[] = "is awesome";
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    /*util::concat(s1, s2, 2);
    std::cout << "s1: " << s1 << std::endl;

    util::concat(s1, s2);
    std::cout << "s1: " << s1 << std::endl;

    util::deepCopy(s1, s2, 3 , 10);
    std::cout << "s1: " << s1 << std::endl;*/

    util::deepCopy(s1, s2);
    std::cout << "s1: " << s1 << std::endl;


 /*
    delete[] a;
    delete[] b;*/

    //MyString::String string1;
    //MyString::String string2("Welt");


    //string1.setText("Hallo ");
    //////string2.add("!");

    ////MyString::String pstring = string1 + string2 + " with character array added";

    //std::cout << "String1 and String2: " << string1 << string2 << std::endl;
    //std::cout << "String1 + String2: " << pstring << std::endl;
    //std::cout << "Comparing 1 with 2: " << (string1 == string2) << std::endl;
    //std::cout << "Comparing 1 with 1: " << (string1 == string1) << std::endl;
    //std::cout << "Get: " << string1[0] << std::endl;

    //MyString::It<char> it = pstring.begin();
    //while (it != pstring.end()) {
    //    std::cout << *it << std::endl;
    //    ++it;
    //}


    return 0;
}
