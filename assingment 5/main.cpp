#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include <list>

using namespace std;


//*****************************COMPARATORS******************************

//https://stackoverflow.com/questions/26444216/is-it-possible-to-use-stdsort-with-a-sort-function-that-takes-extra-arguments?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

struct CompareEdges
{
    bool operator()( const Item* i1, const Item* i2 ) const {
        //TODO finish
    }
};
//*****************************COMPARATORS******************************

int main(int argc, char* argv[]) {
    list items;
    
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