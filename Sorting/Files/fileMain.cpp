#include "FileGenerator.h"

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main( int argc, char* argv[] ){
    FileGenerator f;
    int quantity;
    
    printf( "Quantity: " );
    scanf( "%d", &quantity );
    cout << f.writeFile( "sorting", quantity, FileGenerator::RANDOM ) << endl;
    cout << f.writeFile( "sorting", quantity, FileGenerator::ASCENDING ) << endl;
    cout << f.writeFile( "sorting", quantity, FileGenerator::DESCENDING ) << endl;
    
    return 0;
}
