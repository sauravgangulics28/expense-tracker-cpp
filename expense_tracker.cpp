#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Structure to store one expense
struct Expense
{
    string category;
    string description;
    double amount;
};

// Function to clear invalid input
void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to add an expense
void addExpense(vector<Expense>& expenses)
{
    Expense newExpense;

    cout << "\n--- Add Expense ---\n";

    cout << "Enter category: ";
    getline(cin, newExpense.category);

    while (newExpense.category.empty())
    {
        cout << "Category cannot be empty. Enter again: ";
        getline(cin, newExpense.category);
    }

    cout << "Enter description: ";
    getline(cin, newExpense.description);

    while (newExpense.description.empty())
    {
        cout << "Description cannot be empty. Enter again: ";
        getline(cin, newExpense.description);
    }

    cout << "Enter amount: ";

    while (!(cin >> newExpense.amount) || newExpense.amount <= 0)
    {
        cout << "Invalid amount. Please enter a positive number: ";
        clearInput();
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    expenses.push_back(newExpense);

    cout << "Expense added successfully!\n";
}

// Function to display all expenses
void listExpenses(const vector<Expense>& expenses)
{
    cout << "\n--- All Expenses ---\n";

    if (expenses.empty())
    {
        cout << "No expenses recorded yet.\n";
        return;
    }

    for (int i = 0; i < expenses.size(); i++)
    {
        cout << "\nExpense " << i + 1 << endl;
        cout << "Category: " << expenses[i].category << endl;
        cout << "Description: " << expenses[i].description << endl;
        cout << "Amount: Rs. " << expenses[i].amount << endl;
    }
}

// Function to calculate total for a category
void categoryTotal(const vector<Expense>& expenses)
{
    string category;
    double total = 0;

    cout << "\n--- Category Total ---\n";
    cout << "Enter category: ";
    getline(cin, category);

    for (const Expense& expense : expenses)
    {
        if (expense.category == category)
        {
            total += expense.amount;
        }
    }

    cout << "Total for " << category << ": Rs. " << total << endl;
}

// Function to calculate overall total
void overallTotal(const vector<Expense>& expenses)
{
    double total = 0;

    for (const Expense& expense : expenses)
    {
        total += expense.amount;
    }

    cout << "\n--- Overall Total ---\n";
    cout << "Total expenses: Rs. " << total << endl;
}

// Main function
int main()
{
    vector<Expense> expenses;

    int choice;

    cout << "====================================\n";
    cout << "        EXPENSE TRACKER\n";
    cout << "====================================\n";

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Expense\n";
        cout << "2. List Expenses\n";
        cout << "3. Category Total\n";
        cout << "4. Overall Total\n";
        cout << "5. Exit\n";
        cout << "===========================\n";

        cout << "Enter your choice: ";

        while (!(cin >> choice))
        {
            cout << "Invalid choice. Please enter a number from 1 to 5: ";
            clearInput();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
                addExpense(expenses);
                break;

            case 2:
                listExpenses(expenses);
                break;

            case 3:
                categoryTotal(expenses);
                break;

            case 4:
                overallTotal(expenses);
                break;

            case 5:
                cout << "\nThank you for using Expense Tracker!\n";
                break;

            default:
                cout << "Invalid choice. Please select 1 to 5.\n";
        }

    } while (choice != 5);

    return 0;
}