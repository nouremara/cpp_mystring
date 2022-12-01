// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Own string Class

/**========================================================================
 * @file      : utilstring.h
 * @brief     : implementation of own string class.
 * @author    : Nour Ahmed
 * @email     : nahmed@stud.hs-bremen.de, nour
 * @repo      : https://github.com/nouremara/cpp_mystring
 * @createdOn : 23.11.2022
 * @version   : 1.0.0
 * @description :
 *
 * This file presents an implementation of a class named string.
 * This class behavior will be similar and compatible to the std::string.
 * This file contains the prototypes for the class, its methods and eventually
 * any macros, constants, or global variables you will need to use it.
 *========================================================================**/

#ifndef UTILSTRING_H
#define UTILSTRING_H

#include <cstddef>
#include <iostream>
#include <string>

namespace util {
// Initially, the class shall provide memory for 10 printable characters
#define INITIAL_SIZE 10

	class string {
		char* internal_buffer;
		size_t buffer_size;
		// size_t string_size;

	public:
		/*================== Constructors ===============*/
		string(size_t intialSize = INITIAL_SIZE); /*!< default constructor with empty initialization */
		string(const char*);        /*!< Constructor with parameter const char* */
		string(const std::string&); /*!< Constructor with parameter std::string */
		string(const string&); /*!< Copy constructor: Creates a deep copy of a passed string */

		/*================== Destructor =================*/
		~string(void);

		/*================== Methods ====================*/

		void intialize_string(size_t length = 0);
		void deepCopy(const char* rawChar, size_t startPosition = 0);
	
		// Returns a pointer to an array that contains a null-terminated
		// sequence of characters(i.e., a C-string) representing the current
		// value of the string object.
		// Returns a substring object of type util::string which
		// starts at pos. Parameter length specifies the amount of
		// characters of the new util::string to be returned.
		string substr(size_t pos, size_t length);

		// Allows raw access to the internal C-string (through its char* pointer)
		char* c_str() const;

		//bool compare(const char* charArray) const;
		static int compare(const char* s1, const char* s2);

		/** 
		 * Clears your string object
		 * Erases the contents of the string, which becomes an empty string(with
		 * a length of 0 characters).
		 */
		void clear();


		/**
         * Get the amount of characters of a raw char* string excluding the terminating \0.
		 */
		static size_t rawSize(const char* rawChar); 

		/** 
		 * Returns the amount of characters of your string excluding \0.
		 * Might be smaller than the actual reserved memory. 
		*/
		size_t length() const;
		size_t size() const; /*!< Get the length of the string synonyme to length()*/

		/**
		 * Returns the size of the storage space currently allocated for the 
		 * string, expressed in terms of bytes.
		 */
		size_t capacity() const;


		/*================== Operators ====================*/

		/**
		* Operator + such that string, std::string and (const) char* can be added
		*/
		string operator+(const string& rhsString);
		string operator+(const std::string& rhsString);
		string operator+(const char* strInstance);

		string& operator+=(const string& rhsString);
		string& operator+=(const std::string& rhsString);
		string& operator+=(const char* strInstance);

		string& operator=(const string& rhsString);
		string& operator=(const char* rhsCharArray);
		string& operator=(const std::string& rhsString);

		bool operator==(const string& rhsString);
		bool operator==(const std::string& rhsString);
		bool operator==(const char* charArray);

		bool operator!=(const string& rhsString);
		bool operator!=(const std::string& rhsString);
		bool operator!=(const char* charArray);

		const char operator[](size_t position);

		/*=========================================================================*
		 *             Non-member function overloads                               *
		 *=========================================================================*/
		 // Free operator methods for the cases util::string is on the rhs
		 // Friendship enables access to private members
		friend std::ostream& operator<<(std::ostream& iostream, const util::string& myString);

		friend bool operator==(const std::string& lhsString, const util::string& rhsString);
		friend bool operator==(const char* lhsCharArray, const util::string& rhsString);

		friend bool operator!=(const std::string& lhsString, const util::string& rhsString);
		friend bool operator!=(const char* lhsCharArray, const util::string& rhsString);
	};

	/*=========================================================================*
	 *             Some Utility functions                                      *
	 *=========================================================================*/
	//void concat(char* rawCharTarget, char* rawCharSource, size_t startPosition = -1);

	void deepCopy(char* rawCharTarget, const char* rawCharSource,
		size_t destStartPosition = -1, size_t srcEndPosition = -1);

	//-----------------------------------------------
	void printHeader(const char* text);
	void printSubHeader(const char* text);
	void printTestCase(const char* text);


} // namespace util

#endif /* UTILSTRING_H */
