#include <iostream>     // std::cin, std::cout

using namespace std;

int main()
{
    char first_name[256], last_name[256];

    cout << "Please enter your first name: ";
    cin.getline(first_name, 256);

    cout << "Please enter your last name: ";
    cin.getline(last_name, 256);

    cout << "Hello, " << first_name << " " << last_name << endl;
}
