#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    string field;
    string inputFile;
    string outputFile;

    if (argc < 4 || argc >4) {
        cout<<"Bad number of arguments. Expected 3, got "<<argc<<endl;
        return 1;
    }

    field = argv[1];
    inputFile = argv[2];
    outputFile = argv[3];

    cout<<"1: "<<field<<" 2: "<<inputFile << " 3: "<<outputFile<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}