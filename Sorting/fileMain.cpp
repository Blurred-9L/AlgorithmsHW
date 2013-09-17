#include "FileGenerator.h"

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main( int argc, char* argv[] ){
    FileGenerator f;
    int quantity;
    int type;
    
    if( argc == 3 ){
        sscanf( argv[1], "%d", &quantity );
        if( strcmp( argv[2], "-a" ) == 0 ){
            type = FileGenerator::ASCENDING;
        }
        else if( strcmp( argv[2], "-d" ) == 0 ){
            type = FileGenerator::DESCENDING;
        }
        else if( strcmp( argv[2], "-r" ) == 0 ){
            type = FileGenerator::RANDOM;
        }
        else{
            cout << "Incorrect type argument." << endl;
            return 1;
        }
        f.writeFile( quantity, type );
    }
    else{
        cout << "Incorrect number of arguments." << endl;
        return 1;
    }
    
    return 0;
}
