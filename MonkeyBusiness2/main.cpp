//
//  main.cpp
//  MonkeyBusiness2
//
//  Created by Mina Park on 4/30/17.
//  Copyright © 2017 Mina Park. All rights reserved.
//

#include <iostream>
#include <limits>

using namespace std;

int numberOfMonkeys;
const int days = 7;

void getAverage(const int arr[][days], int);
void getExtreme(int arr[][days], string);

int main() {
    int choice, tempCin;
    cout << "Welcome to Monkey Data!" << endl << endl;
    cout << "Please enter the number of monkeys in your zoo: ";
    cin >> numberOfMonkeys;
    cout << endl;
    cout << "Please enter the data of your monkeys." << endl;
    int monkeyData[numberOfMonkeys][days]; // Creates array of days per monkey.
    for (int count = 0; count < numberOfMonkeys; count++) // Increments # of monkeys.
    {
        for(int count2 = 0; count2 < days; count2++) // Increments # of days.
        {
            tempCin = -1;
            while (tempCin < 0)
            {
                cout << "Please enter the amount of food given to Monkey " << count+1;
                cout << " on day " << count2+1 << " : ";
                cin >> tempCin;
                if (tempCin < 0)
                    cout << "Please enter a valid amount of food." << endl;
            }
            monkeyData[count][count2] = tempCin;
        }
    }
    cout << endl;
    
    do
    {
        cout << "Please enter 1, 2, 3 or 4 according to the following menu!" << endl;
        cout << "1: Find the average amount of food eaten by all the monkeys per day." << endl;
        cout << "2: Find the least amount of food eaten by one monkey during the week." << endl;
        cout << "3: Find the greatest amount of food eaten by one monkey during the week." << endl;
        cout << "4: Quit the program." << endl;
        cout << "Enter your choice here: ";
        cin >> choice;
        cout << endl;
        if (choice < 1 || choice > 4) // Asks for a valid input.
        {
            cout << "Please enter a valid choice: ";
            cin >> choice;
        }
    
        switch(choice) // Different menu options that were given.
        {
            case 1:
                for (int count = 0; count < days; count++) // Gets average food eaten per day.
                {
                    cout << "The average amount of food eaten by all the monkeys on day " << count+1 << " is: ";
                    getAverage(monkeyData, count);
                    cout << endl;
                }
                break;
            case 2:
                getExtreme(monkeyData,"lowest"); // Gets the lowest amount food eaten.
                break;
            case 3:
                getExtreme(monkeyData,"highest"); // Gets the highest amount food eaten.
                break;
            case 4:
                cout << "Thank you for using Monkey Data!" << endl;
                break;
        }
    }
    while (choice != 4); // Returns to menu if user did not quit.
    return 0;
}

void getAverage(const int arr[][days], int day)
/*
    Description: Gets average food eaten by monkeys on specific day.
    Input: monkeyData array, day #.
    Output: average.
*/
{
    double avg = 0, total = 0;
    for (int count2 = 0; count2 < numberOfMonkeys; count2++) // Sums total food for monkeys on day.
    {
        total += arr[count2][day];
    }
    avg = (total / numberOfMonkeys);
    cout << avg << endl;
}

void getExtreme(int arr[][days], string extreme)
/*
    Description: Gets least or most food eaten by one monkey during week.
    Input: monkeyData.
    Output: Lowest or highest amount of food.
*/
{
    int compVal;
    if (extreme == "lowest")
        compVal = numeric_limits<int>::max();
    else
        compVal = -1;
    int monkeyNum;
    cout << "Enter the monkey number you wish to see the lowest amount of food eaten during the week: ";
    cin >> monkeyNum;
    for (int count = 0; count < days; count++)
        {
            if (extreme == "lowest") // Compares monkeyData to find lowest value.
            {
                if (arr[(monkeyNum-1)][count] < compVal)
                    compVal = arr[(monkeyNum-1)][count];
            }
            else // Compares monkeyData to find highest value.
            {
                if (arr[(monkeyNum-1)][count] > compVal)
                    compVal = arr[(monkeyNum-1)][count];
            }
        }
    cout << "The " << extreme << " amount of food Monkey " << monkeyNum;
    cout << " ate during the week is: " << compVal << endl << endl;
}
