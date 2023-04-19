#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Function prototypes
void optionOne(map<string, int>& data);
void optionTwo(map<string, int>& data);
void optionThree(map<string, int>& data);
void saveData(map<string, int>& data);

int main()
{
    map<string, int> data; // Data structure to store purchase records
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    // Read purchase records from input file and store in data structure
    if (inputFile.is_open())
    {
        string item;
        int count;
        while (inputFile >> item >> count) // Read each item and its count from input file 
        {
            data[item] = count; // add item and its count to data structure
        }
        inputFile.close();
    }
    else
    {
        cout << "Error: input file not found" << endl;
        return 1;
    }

    // Main program loop
    int choice = 0;
    while (choice != 4)
    {
        // Display menu options
        cout << "Menu Options:" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print the frequency of all items" << endl;
        cout << "3. Print a histogram of item frequencies" << endl;
        cout << "4. Exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                optionOne(data);
                break;
            case 2:
                optionTwo(data);
                saveData(data);
                break;
            case 3:
                optionThree(data);
                saveData(data);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
// Function to search for an item
void optionOne(map<string, int>& data)
{
    string item;
    cout << "Enter the item you wish to search for: ";
    cin >> item;

    if (data.count(item) > 0)
    {
        cout << "The frequency of " << item << " is " << data[item] << endl;
    }
    else
    {
        cout << "Item not found" << endl;
    }
}
// Function to print frequency of all items
void optionTwo(map<string, int>& data)
{
    for (auto& pair : data)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}
// Function to print histogram of item frequencies
void optionThree(map<string, int>& data)
{
    for (auto& pair : data)
    {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void saveData(map<string, int>& data)
{
    ofstream outputFile("frequency.dat");

    if (outputFile.is_open())
    {
        for (auto& pair : data)
        {
            outputFile << pair.first << " " << pair.second << endl;
        }
        outputFile.close();
    }
    else
    {
        cout << "Error: could not create output file" << endl;
    }
}