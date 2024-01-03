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
// Offers utilities for formatting output.
#include <iomanip>
// Handles input/output stream operations.
#include <iostream>
// Provides iterator manipulation utilities.
#include <iterator>
// Implements a doubly-linked list data structure.
#include <list>
// Offers utilities for string manipulation.
#include <string>

// Creating a function that will display the elements at
// odd positions in a list.
std::list<int>
ElementsAtOddPositions(const std::list<int>& listOfElements) {
    // Declaring an empty list for odd elements.
    std::list<int> oddElementList;

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

    // Creating a function that will display the individual digits inside
    // a number using lists.
    std::list<int> ListOfNumbers(int wholeNumber) {
        // Declaring a list to hold the individual elements.
        std::list<int> listOfDigits;
        // Converting the number inputted by the user into a string
        // using the std::to_string function, to iterate through its characters.
        // This function takes an integer as input and returns a string
        // representation of the integer.
        std::string wholeNumberString = std::to_string(wholeNumber);
        // Using a For Each loop to get the individual elements.
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

    // Main function that will allow for user input/output and also
    // error check.
    int main() {
        // Declaring variables.
        std::string listAsString;
        std::string wholeNumberAsString;
        int repeatProgram;

        // Using a While true loop, to allow for the user to repeat my
        // program.
        while (true) {
            // Getting user inputs.
            // Using std::getline() function to read the input and store it in
            // the string variable listAsString. Using std::cin object to read
            // the input and ignore any leading whitespace characters
            // in the input. Using std::ws manipulator to skip any
            // remaining whitespace characters in the input.
            std::cout <<
            "Please enter a string of integers separated by spaces: ";
            std::getline
            (std::cin >> std::ws, listAsString);
            std::cout << "Please enter a positive whole number: ";
            std::getline(std::cin >> std::ws, wholeNumberAsString);

            // Using try catch to catch any errors.
            try {
                // Using a stringstream to parse the string into integers.
                // Using std::istringstream to read input from a string as
                // if it were a stream. Creating a new object called
                // inputStream with the contents of the string variable
                // listAsString. This object is then used to extract
                // integers from the input.
                std::istringstream inputStream(listAsString);
                std::list<int> listAsInteger;

                int wholeNumberAsInteger = std::stoi(wholeNumberAsString);

                // Parsing the string into integers.
                // Extract integers from the input stream and store
                // them in the integer variable num. Using a while loop
                // to extract integers from the input stream and add them
                // to the end of the list.
                int num;
                while (inputStream >> num) {
                    listAsInteger.push_back(num);
                }

                // Checking if either the whole number or
                // any element in the list is negative.
                // Using the std::any_of() function to return true
                // if any element in the range listAsInteger.begin(),
                // listAsInteger.end()) is less than 0.
                if (wholeNumberAsInteger < 0 ||
                std::any_of(listAsInteger.begin(),
                listAsInteger.end(), [](int num) { return num < 0; })) {
                    // If there is a negative then display an error message.
                    std::cout << "Please enter a positive number." << std::endl;
                    // Continue through the loop after displaying error message.
                    continue;
                // Else they're positive so call functions.
                } else {
                    std::list<int> odd_elements =
                    ElementsAtOddPositions(listAsInteger);
                    std::list<int> separated_digits =
                    ListOfNumbers(wholeNumberAsInteger);

                    // Displaying the digits of the user's number.
                    std::cout << "The digits of your numbers are: ";
                    // Using For Each loop to iterate through the
                    // elements in the number.
                    for (int digit : separated_digits) {
                        std::cout << digit << " \n";
                    }

                    // Displaying the elements at odd positions from the list.
                    std::cout <<
                    "The elements in your list at odd positions are: ";
                    // Using For Each loop to iterate through the elements
                    // and displays the elements at odd positions from the list.
                    for (int element : odd_elements) {
                        std::cout << element << " \n";
                    }
                }
            // Catching any errors.
            } catch (std::invalid_argument) {
                std::cout << "Invalid input. Please try again\n";
            }

            // Asking the user if they want to repeat my program.
            std::cout <<
            "Do you want to repeat my program? (1 - Yes or 2 - No): ";
            std::cin >> repeatProgram;

            // If they don't enter 1 then break out of loop.
            if (repeatProgram != 1) {
                break;
            }
        }
    }
