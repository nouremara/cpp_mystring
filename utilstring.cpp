// Nour Ahmed
// Matrikal-Nr.: 5200991
// Assignment 1 – Own String Class

/**========================================================================
 * @file           :  utilstring.cpp
 * @author         :  Nour Ahmed
 * @email          :  nahmed@stud.hs-bremen.de, nourbrm02@gmail.com
 * @repo           :  https://github.com/nouremara/cpp_mystring
 * @createdOn      :  23.11.2022
 * @description    :  implementation of own string class
 *
 * this file presents an implementation of a class named string.
 * This class behavior will be similar to the std::string and both
 * std::string and this string class are compatible.
 *========================================================================**/

#include "utilstring.h"

namespace util {
    /*=========================================================================*
     *                         Constructors                                    *
     *=========================================================================*/

     /** Default Constructor */
    string::string(size_t intialSize) {
        intialize_string(intialSize);
    }
    //-------------------------------------------------------------


    /** Constructor with char* */
    string::string(const char* data) {
        intialize_string(rawSize(data));  // ensure string is initialized before using it
        deepCopy(data);		// copy passed array to the string
    }
    //-------------------------------------------------------------

    /** Constructor with parameter std::string */
    string::string(const std::string& data) {
        intialize_string(rawSize(data.c_str()));  // ensure string is initialized before using it
        deepCopy(data.c_str());		// copy passed array to the string
    }
    //-------------------------------------------------------------

    /** Copy constructor: Creates a deep copy of a passed string */
    string::string(const string& data) {
        intialize_string(rawSize(data.c_str()));  // ensure string is initialized before using it
        deepCopy(data.c_str());		// copy passed array to the string
    }


    /*=========================================================================*
     *                         Destructor                                      *
     *=========================================================================*/
    string::~string(void) {
        delete[] internal_buffer;
    }


    /*=========================================================================*
     *                         Methods                                         *
     *=========================================================================*/

    void string::intialize_string(size_t length) {
        internal_buffer = new char[length + 1];
        buffer_size = length + 1;

        // initialize an empty string
        internal_buffer[0] = '\0';
    }
    //-------------------------------------------------------------

    size_t string::size() const {
        return rawSize(internal_buffer);
    }

    size_t string::length() const {
        return rawSize(internal_buffer);
    }
    //-------------------------------------------------------------

    size_t string::rawSize(const char* rawChar) {
        size_t length = 0;
        while (rawChar[length] != '\0') {
            length++;
        }

        return length;
    }
    //-------------------------------------------------------------


    /**
     * Design and implementation of a concept to extend the internal memory
     * if util::string has to store more than the default INITIAL_SIZE characters
     * note that the function copy the passed char array starting from the
     * startPosition (i.e. it can write starting from any position in the internal string buffer)
     * startPosition default is 0
     */
    void string::deepCopy(const char* rawChar, size_t startPosition) {
        //check if internalData is of enough size to accommodate the passed array
        size_t rawCharSize = rawSize(rawChar);
        if (rawCharSize > size()) { // more space is needed
            //delete current internalData
            delete[] internal_buffer;

            // re-initialize the string with the required size
            intialize_string(rawCharSize);
        }

        //copy the passed array to the newly allocated internalData
        int j = startPosition;
        while (rawChar[j] != '\0') {
            internal_buffer[j] = rawChar[j];
            j++;
        }

        internal_buffer[j] = '\0';		// ensure destination string is null terminated
        //string_size = rawCharSize;		// set string size to the new one
    }
    //-------------------------------------------------------------


    char* string::c_str() const {
        return internal_buffer;
    }
    //-------------------------------------------------------------


    // Returns a pointer to an array that contains a null-terminated
        // sequence of characters(i.e., a C-string) representing the current
        // value of the string object.
        // Returns a substring object of type util::string which
        // starts at pos. Parameter length specifies the amount of
        // characters of the new util::string to be returned.
    string string::substr(size_t pos, size_t length) {
        string substring(length);

        util::deepCopy(substring.c_str(), internal_buffer+ pos, 0, length);


        return substring;
    }

    //-------------------------------------------------------------

    /**
     * Compares two char * strings lexicographically
     * This function is my own implementation of the std::strcmp() function.
     * Note this function performs a binary comparison of the ASCII code of the characters.
     *
     * @param str1  primitive C string to be compared.
     * @param str2  primitive C string to be compared with.
     * @return      an integral value indicating the relationship between the strings:
     *				<0	: the first character that does not match has a lower value in ptr1 than in ptr2
     *				0	: the contents of both strings are equal
     *				>0	: the first character that does not match has a greater value in ptr1 than in ptr2
     */
    int string::compare(const char* lhsCharArray, const char* rhsCharArray)
    {
        // convert both pointers from `char*` to `unsigned char*`
        // needed for the difference calculations
        const unsigned char* p1 = (const unsigned char*)lhsCharArray;
        const unsigned char* p2 = (const unsigned char*)rhsCharArray;

        // check if characters differ, or end of the first string (a terminating null) is reached
        while (*p1 && *p1 == *p2) {
            // proceed to the next pair of characters
            ++p1, ++p2;
        }

        // return the ASCII difference
        return (*p1 > *p2) - (*p2 > *p1);
    }


    /*=========================================================================*
     *                         Operators                                       *
     *=========================================================================*/



     //-------------------------------------------------------------

    string& string::operator=(const string& rhsString) {
        deepCopy(rhsString.c_str());
        return *this;
    }

    string& string::operator=(const char* rhsCharArray) {
        deepCopy(rhsCharArray);
        return *this;
    }

    string& string::operator=(const std::string& rhsString) {
        deepCopy(rhsString.c_str());
        return *this;
    }
    //-------------------------------------------------------------


    bool string::operator==(const string& rhsString) {
        //if (string_size != rhsString.size()) return false;
        // note that compare returns 0 when the two strings are equal
        return	!compare(internal_buffer, rhsString.c_str());
    }

    bool string::operator==(const std::string& rhsString) {
        //if (string_size != rhsString.size()) return false;

        // note that compare returns 0 when the two strings are equal
        return	!compare(internal_buffer, rhsString.c_str());
    }

    bool string::operator==(const char* charArray) {
        //if (string_size != rhsString.size()) return false;

        // note that compare returns 0 when the two strings are equal
        return	!compare(internal_buffer, charArray);
    }
    //-------------------------------------------------------------

    bool string::operator!=(const string& rhsString) {
        //if (string_size != rhsString.size()) return false;
        // note that compare returns 0 when the two strings are equal
        return	compare(internal_buffer, rhsString.c_str());
    }

    bool string::operator!=(const std::string& rhsString) {
        //if (string_size != rhsString.size()) return false;

        // note that compare returns 0 when the two strings are equal
        return	compare(internal_buffer, rhsString.c_str());
    }

    bool string::operator!=(const char* charArray) {
        //if (string_size != rhsString.size()) return false;

        // note that compare returns 0 when the two strings are equal
        return	compare(internal_buffer, charArray);
    }
    //-------------------------------------------------------------

    const char string::operator[](size_t position) {
        if (position > size()) return '\0';
        return internal_buffer[position];
    }
    //-------------------------------------------------------------


    string& string::operator+(const string& rhsString) {
        size_t total_size = size() + rhsString.size() + 1;
        char* temp = new char[total_size];

        util::deepCopy(temp, internal_buffer,0);
        util::deepCopy(temp, rhsString.c_str(), size());

        delete[] internal_buffer;

        internal_buffer = temp;
        buffer_size = total_size;
        std::cout << "\n\nbuffer_size " << buffer_size << std::endl;
        std::cout << "(size: " << size() << ") : " << internal_buffer << std::endl;

        return *this;
    }
    //-------------------------------------------------------------


    /**
     *	concatenating util::string and const char*

     */
    string& string::operator+(const char* rhsString) {


        // a temporary object to fill it with the concatenated strings
        // total size of the two strings combined
        size_t rhsSize = rawSize(rhsString);
        char* tempData = new char[size() + rhsSize + 1];

        // copy the passed array to the newly allocated tempData
        // copy the lhs string from the beginning of the string then the rhs string there after
        // ----------------------------------------------------------
        // |0| ... |lhs size| ...  |lhs size|rhs size + lhs size + 1|
        // |   lhs string   |   rhs string  | \0 |
        // ----------------------------------------------------------
        // note that at the given position the lhs \0 termination will be overwritten as this copy starts at its position

        int j = 0;
        while (internal_buffer[j] != '\0') {
            tempData[j] = internal_buffer[j];
            j++;
        }

        int i = 0;
        while (rhsString[i] != '\0') {
            tempData[j] = rhsString[i];
            j++;
            i++;
        }
        tempData[j] = '\0'; // ensure destination string is null terminated

        std::cout << " > [tempData] : " << tempData << std::endl;

        util::string temp;
        //delete[] tempData;

        return temp;
    }



    /*====================================================================================*
     * non-member functions and operator methods for the cases util::string is on the rhs *
     *====================================================================================*/

    std::ostream& operator<<(std::ostream& iostream, const util::string& myString) {
        return (iostream << myString.c_str());
    }

    //-------------------------------------------------------------


    bool operator==(const std::string& lhsString, const util::string& rhsString) {
        // note that compare returns 0 when the two strings are equal
        return	!util::string::compare(lhsString.c_str(), rhsString.c_str());
    }

    bool operator==(const char* lhsCharArray, const util::string& rhsString) {
        // note that compare returns 0 when the two strings are equal
        return	!util::string::compare(lhsCharArray, rhsString.c_str());
    }
    //-------------------------------------------------------------

    bool operator!=(const std::string& lhsString, const util::string& rhsString) {
        // note that compare returns 0 when the two strings are equal
        return	util::string::compare(lhsString.c_str(), rhsString.c_str());
    }

    bool operator!=(const char* lhsCharArray, const util::string& rhsString) {
        // note that compare returns 0 when the two strings are equal
        return	util::string::compare(lhsCharArray, rhsString.c_str());
    }
    //-------------------------------------------------------------


    /**
    * fill rawCharTarget with rawCharSource starting from startPosition
    *
    * Notes:
    *	> rawCharTarget contents will be changed
    *	> the rawCharTarget is assumed to be big enough to hold the rawCharSource
    *	 (i.e., its size is larger than or equal to that of the rawCharSource)
    */
    void concat(char* rawCharTarget, char* rawCharSource, size_t startPosition) {
        // if the startPosition is not given (we have its default -1)
        // do a normal concatenation of the two strings)
        // note that at the given position the lhs \0 termination will be
        // overwritten as this copy starts at its position
        if (startPosition == -1) {
            startPosition = util::string::rawSize(rawCharTarget);
        }

        // deep copy rawCharSource into rawCharTarget beginning at startPosition
        for (size_t j = 0; rawCharSource[j] != '\0'; ++j, ++startPosition) {
            rawCharTarget[startPosition] = rawCharSource[j];
        }

        // ensure destination string is null terminated
        rawCharTarget[startPosition] = '\0';
    }


    // destStartPosition  default is to first location of the destRawChar
    // srcEndPosition	  default is to last character (before the \0) of the srcRawChar
    void deepCopy(char* rawCharTarget, const char* rawCharSource, size_t destStartPosition, size_t srcEndPosition){
        // check and adjust for default values
        destStartPosition = (destStartPosition == -1) ? util::string::rawSize(rawCharTarget) : destStartPosition;
        srcEndPosition = (srcEndPosition == -1) ? util::string::rawSize(rawCharSource): srcEndPosition;

        // deep copy rawCharSource into rawCharTarget beginning at startPosition
//		for (size_t j = 0; rawCharSource[j] != '\0'; ++j, ++destStartPosition) {
        for (size_t j = 0; j < srcEndPosition; ++j, ++destStartPosition) {
            rawCharTarget[destStartPosition] = rawCharSource[j];
        }

        // ensure destination string is null terminated
        rawCharTarget[destStartPosition] = '\0';

    }
    //-------------------------------------------------
    void printHeader(const char* text){
        size_t spaces_needed = (80 - util::string::rawSize(text))/2 -2;

        std::cout << "\033[96m"; // set text and background colors
        std::cout << "-------------------------------------------------------------------------------\n-";
        for (int i = 0; i < spaces_needed; ++i) { std::cout << " "; }
        std::cout << text;
        for (int i = 0; i < spaces_needed; ++i) { std::cout << " "; }
        std::cout << " -\n";
        std::cout << "-------------------------------------------------------------------------------\n";
        std::cout << "\033[0m"; // reset text and background colors

    }

    void printSubHeader(const char* text) {
        std::cout << "\033[32m"; // set text and background colors
        std::cout << text;
        std::cout << "\033[0m\n"; // reset text and background colors
    }


}  // namespace util
