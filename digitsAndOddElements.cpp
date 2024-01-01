// Copyright (c) 2023 Lily Carroll All rights reserved.
//
// Created by: Lily Carroll
// Created on: Dec/26/2023
// This program will get user input for a list of
// integers, and display the integers in the list
// at the odd index. Additionally my program will
// get another input of an integer and will display
// the digits of the integers separated by commas.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
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
        // Using a For Each loop to get the individual elements.
        for (char digit : wholeNumberString) {
            // Appending the individual digits to the list.
            // Converting the character to an integer using std::stoi.
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

        while (true) {
            // Getting user inputs.
            std::cout <<
            "Please enter a string of integers separated by spaces: ";
            std::getline
            (std::cin >> std::ws, listAsString);

            std::cout << "Please enter a positive whole number: ";
            std::getline(std::cin >> std::ws, wholeNumberAsString);

            try {
                // Using a stringstream to parse the string into integers.
                std::istringstream iss(listAsString);
                std::list<int> listAsInteger;

                int wholeNumberAsInteger = std::stoi(wholeNumberAsString);

                // Parsing the string into integers.
                int num;
                while (iss >> num) {
                    listAsInteger.push_back(num);
                }

                // Checking if either the whole number or
                // any element in the list is negative.
                if (wholeNumberAsInteger < 0 ||
                std::any_of(listAsInteger.begin(),
                listAsInteger.end(), [](int num) { return num < 0; })) {
                    // If there is a negative then display an error message.
                    std::cout << "Please enter a positive number." << std::endl;
                    continue;
                } else {
                    std::list<int> odd_elements =
                    ElementsAtOddPositions(listAsInteger);
                    std::list<int> separated_digits =
                    ListOfNumbers(wholeNumberAsInteger);

                    // Displaying the digits of the user's number.
                    std::cout << "The digits of your numbers are: ";
                    for (int digit : separated_digits) {
                        std::cout << digit << " ";
                    }
                    std::cout << std::endl;

                    // Displaying the elements at odd positions from the list.
                    std::cout <<
                    "The elements in your list at odd positions are: ";
                    for (int element : odd_elements) {
                        std::cout << element << " ";
                    }
                    std::cout << std::endl;
                }
            } catch (std::invalid_argument) {
                std::cout << "Invalid input. Please try again" << std::endl;
            }

            std::cout <<
            "Do you want to repeat my program? (1 - Yes or 2 - No): ";
            std::cin >> repeatProgram;

            if (repeatProgram != 1) {
                break;
            }
        }
    }
