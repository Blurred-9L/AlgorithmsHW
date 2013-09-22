#include "SortTimer.h"

#include <fstream>
using std::fstream;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define FILENAME "../Files/sorting"
#define FILENAME_LEN 75
#define QUANTITIES_LEN 6
#define FILES 12

int main(){
    SortTimer s;
    fstream file;
    char filename[FILENAME_LEN];
    int quantities[QUANTITIES_LEN] = { 5, 10, 100, 1000, 10000, 100000 };
    int* array;
    
    for( int i = 0; i < QUANTITIES_LEN; i++ ){
        array = new int[ quantities[i] ];
        for( int j = 0; j < FILES; j++ ){
            sprintf( filename, "%s%d_%d.txt", FILENAME, j, quantities[i] );
            file.open( filename, fstream::in );
            if( file.is_open() ){
                for( int k  = 0; k < quantities[i]; k++ ){
                    file >> array[k];
                }
                cout << filename << endl;
                s.getStats( array, quantities[i], SortTimer::Shell );
                cout << endl;
                file.close();
            }
            else{
                return 1;
            }
        }
        delete[] array;
    }
    
    return 0;
}
