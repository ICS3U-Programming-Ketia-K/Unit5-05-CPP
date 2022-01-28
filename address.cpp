// Copyright (c) 2022 Ketia Gaelle Kaze All rights reserved.
//
// Created by: Ketia Gaelle Kaze
// Created on: Jan. 25, 2022
// This program asks the user for their address
// and prints it back in a proper format.

#include <iostream>
#include <string>
#include <cstring>


// properly formats an address following the Canadian post standard
std::string formatAddress(std::string name, std::string streetNum,
                          std::string streetName, std::string city,
                          std::string province, std::string postalCode,
                          std::string aptNum = "", std::string answer = "") {
    // declare variables
    std::string canPostAddress, CanPostAddress, userStringUpper;
    std::string userStringUpperA, userStringUpperB;
    std::string userStringUpperC, userStringUpperD, userStringUpperE;

    // get length of string
    int nameLength = name.length();
    // declare char as length of string
    char char_array[nameLength + 1];
    strcpy(char_array, name.c_str());
    // converts each letter to uppercase
    for (int counter = 0; counter < nameLength; counter++) {
        userStringUpper += std::toupper(char_array[counter]);
    }

    // gets length of string
    int streetNameLength = streetName.length();
    // declare char as length of string
    char char_array1[streetNameLength + 1];
    strcpy(char_array1, streetName.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < streetNameLength; counter++) {
        userStringUpperA += std::toupper(char_array1[counter]);
    }

    // gets length of string
    int cityLength = city.length();
    // declare char as length of string
    char char_array2[cityLength + 1];
    strcpy(char_array2, city.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < cityLength; counter++) {
        userStringUpperB += std::toupper(char_array2[counter]);
    }

    // gets length of string
    int provinceLength = province.length();
    // declare char as length of string
    char char_array3[provinceLength + 1];
    strcpy(char_array3, province.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < provinceLength; counter++) {
        userStringUpperC += std::toupper(char_array3[counter]);
    }

    // gets length of string
    int postalCodeLength = postalCode.length();
    // declare char as length of string
    char char_array4[postalCodeLength + 1];
    strcpy(char_array4, postalCode.c_str());

    // converts each letter to uppercase
    for (int counter = 0; counter < postalCodeLength; counter++) {
        userStringUpperD += std::toupper(char_array4[counter]);
    }

    if (answer == "y") {
        // gets length of string
        int aptNumLength = aptNum.length();
        // declare char as length of string
        char char_array5[aptNumLength + 1];
        strcpy(char_array5, aptNum.c_str());

        // converts each letter to uppercase
        for (int counter = 0; counter < aptNumLength; counter++) {
            userStringUpperE += std::toupper(char_array5[counter]);
        }

        CanPostAddress = userStringUpper + "\n";
        CanPostAddress += userStringUpperE + "-" + \
                          streetNum + " " + userStringUpperA + "\n";
        CanPostAddress += userStringUpperB + " " + \
                          userStringUpperC + " " + userStringUpperD;

        return CanPostAddress;
    }

    canPostAddress = userStringUpper + "\n";
    canPostAddress += streetNum + " " + userStringUpperA + "\n";
    canPostAddress += userStringUpperB + " " + \
                      userStringUpperC + " " + userStringUpperD;

    return canPostAddress;
}


int main() {
    // displays opening message
    std::cout << "This program formats an address to a ";
    std::cout << "Canadian mailing address.";
    std::cout << std::endl;
    std::cout << std::endl;

    // declaring variables
    std::string nameUser;
    std::string streetNumUser;
    std::string streetNameUser;
    std::string cityUser;
    std::string provinceUser;
    std::string postalCodeUser;
    std::string aptNumUser = "";
    std::string answerUser = "";
    std::string userAddress;

    // gets input from the user
    std::cout << "Enter your full name: ";
    getline(std::cin, nameUser);
    std::cout << "Do you live in an apartment? (y/n): ";
    getline(std::cin, answerUser);

    // checks if user lives in an apartment
    if (answerUser == "y") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, aptNumUser);
    }
    // gets input from the user
    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumUser);
    std::cout << "Enter your street name and type: ";
    getline(std::cin, streetNameUser);
    std::cout << "Enter your city: ";
    getline(std::cin, cityUser);
    std::cout << "Enter your province (as an abbreviation): ";
    getline(std::cin, provinceUser);
    std::cout << "Enter your postal code: ";
    getline(std::cin, postalCodeUser);
    std::cout << std::endl;

    // assign variable to function that formats the address
    if (aptNumUser != "") {
        userAddress = formatAddress(nameUser, streetNumUser,
                                    streetNameUser, cityUser, provinceUser,
                                    postalCodeUser, aptNumUser, answerUser);
        std::cout << userAddress;
    } else {
        userAddress = formatAddress(nameUser, streetNumUser,
                                    streetNameUser, cityUser, provinceUser,
                                    postalCodeUser);
        std::cout << userAddress;
    }
}
