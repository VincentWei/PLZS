#include <iostream>     // std::cout
#include <fstream>      // std::ofstream and std::ifstream

using namespace std;

int main()
{
    ofstream ofs;
    ofs.open("test.txt", ofstream::out);
    ofs << "The first line" << endl;
    ofs << "The second line" << endl;
    ofs.close();

    ifstream ifs;
    ifs.open("test.txt", ifstream::in);

    while (true) {
        char c = ifs.get();
        if (c == EOF)
            break;
        cout << c;
    }

    ifs.close();
}
