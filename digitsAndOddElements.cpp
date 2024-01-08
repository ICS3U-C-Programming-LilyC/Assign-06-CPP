// Copyright (c) 2023 Lily Carroll All rights reserved.
//
// Created by: Lily Carroll
// Created on: Dec/26/2023
// This program will get user input for a list of
// integers, and display the integers in the list
// at the odd index. Additionally my program will
// get another input of an integer and will display
// the digits of the integers separated by commas.

// The following libraries are included for various functionalities:
// Provides algorithmic operations on sequences.
#include <algorithm>
// Allows for use of std and its functions.
#include <iomanip>
// Allows for inputs and outputs.
#include <iostream>
// Allows for iterator manipulation.
#include <iterator>
// Allows for usage of doubly-linked list data structures.
#include <list>
// Allows for string manipulation.
#include <sstream>
// Allows for the usage of strings.
#include <string>
// Allows for a dynamic array-like container.
#include <vector>

// Function that displays all the elements adds odd positions of a list.
std::vector<int> ElementsAtOddPositions(
    const std::vector<int>& listOfElements) {
    // Declaring list.
    std::vector<int> oddElementList;
    // Using a For loop to get the odd elements from the list.
    for (int index = 0; index < listOfElements.size(); ++index) {
        // Checking if the element's index is odd.
        if (index % 2 == 1) {
            // Appending the odd element to the list.
            // Using std::next to advance the iterator
            // in the list by 'index' positions.
            // This creates an iterator 'it' pointing
            // to the element at the 'index' position.
            auto list = std::next(listOfElements.begin(), index);

            // Appending the element at the current position to
            // the list of odd elements.
            // Using a * as a pointer to add the value of the element
            // to the list instead of the memory address of the element.
            // Since list is a pointer to the first element in the list,
            // not the value of the first element itself.
            oddElementList.push_back(*list);
        }
    }
    // Returning the odd element in the list to the function.
    return oddElementList;
}
// Function that tells the user the individual digits in their number.
std::vector<int> ListOfNumbers(int wholeNumber) {
    // Declaring list.
    std::vector<int> listOfDigits;
    // Converting the number inputted by the user into a string
    // using the std::to_string function, to iterate through its characters.
    // This function takes an integer as input and returns a string
    // representation of the integer.
    std::string wholeNumberString = std::to_string(wholeNumber);
    for (char digit : wholeNumberString) {
        // Appending the individual digits to the list.
        // Using the number 1 specifies the length of the
        // new string, and the digit variable specifies the character
        // to be copied into the new string.
        // Then the string is passed as an argument to the std::stoi()
        // function, which converts the string to an integer.
        // Then the integer is added to the end of listOfDigits using
        // the push_back() function.
        listOfDigits.push_back(std::stoi(std::string(1, digit)));
    }
    // Returning the list to the function.
    return listOfDigits;
}

int main() {
    // Declaring variables.
    std::string listAsString;
    std::vector<int> listAsInteger;
    int wholeNumberAsInteger;

    // Explaining my program to the user.
    std::cout <<
    "Welcome to my program in C++! My program will get a list of numbers from";
    std::cout <<
    " the user and will display the elements at odd positions in the list.";
    std::cout <<
    " It will also ask for a number and will display the digits in that ";
    std::cout << "number separated by commas.\n";

    // Using a While True loop to allow the user to run my
    // program again.
    while (true) {
        // Using a Do While loop which will continue until
        // the user enters a valid string of integers.
        do {
            // Getting user input.
            std::string listAsString;
            std::cout <<
            "\nPlease enter a string of integers separated by spaces: ";
            std::getline(std::cin, listAsString);
            // Creating a string stream from the user's input.
            std::istringstream iss(listAsString);
            // Declaring a string to hold each integer in the user's input.
            std::string integer;

            // Using try catch to catch any errors.
            try {
                // Using a while loop to continue until all integers
                // have been processed.
                // This returns a reference to the string stream iss,
                // which is converted to a boolean value so that it can
                // be evaluated by the while loop.
                // If the extraction was successful, meaning the string stream
                // is valid then the boolean value is true.
                // But if the extraction failed, meaning it is invalid the
                // boolean value is false.
                while (iss >> integer) {
                    // Declaring a variable that is an  unsigned integer type
                    // that is used for sizes.
                    // The pos variable is used to hold the position of the
                    // first character in the string that could not be
                    // converted to an integer.
                        size_t pos;
                    // Converting from string to an integer.
                    int num = std::stoi(integer, &pos);

                    // Checking if the entire list has a valid integers
                    // or if there is a negative integer.
                    // Checking if the entire list was converted to an integer.
                    // If not, this means the string contains a non-integer.
                    // character. It also checks if there is a negative integer.
                    if (pos != integer.size() || num < 0) {
                        // If there is an invalid input, then throw an exception
                        // to the catch statement which will display the error
                        // message.
                        throw std::invalid_argument("");
                    }

                    // Adding the valid integers to the list.
                    listAsInteger.push_back(num);
                }
                // If there is no exception, then break out of
                // the loop.
                break;
            // Catching any errors.
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input. Please try again.\n";
            }
        } while (true);

        // Using another do while loop which will continue until
        // the user enters a valid positive whole number.
        do {
            // Getting user input for a positive whole number.
            std::string wholeNumberAsString;
            std::cout << "\nPlease enter a positive whole number: ";
            std::getline(std::cin, wholeNumberAsString);

            // Using a try catch to catch any errors.
            try {
                // Convert the string to an integer
                wholeNumberAsInteger = std::stoi(wholeNumberAsString);

                // Check if the number is negative or a decimal.
                // Using npos expression to represent the maximum
                // size of a string.
                // This value is returned by the std::string::find
                // function to check if the user’s input contains
                // a decimal point.
                if (wholeNumberAsInteger < 0 ||
                wholeNumberAsString.find('.') != std::string::npos) {
                    // If it does contain either negatives or decimals,
                    // throw an exception to the catch statement which will
                    // display the error message.
                    throw std::invalid_argument("");
                }
                // If there is no exception, then break out of the loop.
                break;
            // Catch any errors.
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input. Please try again.\n";
            }
        } while (true);

        // Calling functions.
        std::vector<int> oddElements = ElementsAtOddPositions(listAsInteger);
        std::vector<int> separatedDigits = ListOfNumbers(wholeNumberAsInteger);

        // Using a For Each loop to display the elements at odd positions.
        std::cout << "The elements in your list at odd positions are: ";
        for (int element : oddElements) {
            std::cout << element << ", ";
        }
        std::cout << "\n";

        // Using a For Each loop to display the digits of the user's number.
        std::cout << "The digits of your numbers are: ";
        for (int digit : separatedDigits) {
            std::cout << digit << ", ";
        }
        std::cout << "\n";

        // Asking the user if they want to run my program again.
        int repeatProgram;
        std::cout <<
        "\nDo you want to repeat my program? (1 - Yes or 2 - No): ";
        std::cin >> repeatProgram;

        // Ignoring the input buffer (keystrokes -like hitting the enter key)
        // that aren't specified to the maximum number of characters.
        // This is necessary since after repeating the program it leaves a
        // newline character in the input buffer, which would be read by
        // the next input statement if it was not ignored.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Using an if statement to check if they didn't input 1,
        // then break out of the loop.
        if (repeatProgram != 1) {
            break;
        }
    }
}
