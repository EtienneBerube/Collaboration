#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 3 || argc >3) {
        cout<<"Bad number of arguments. Expected 3, got "<<argc<<endl;
        return 1;
    }
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}