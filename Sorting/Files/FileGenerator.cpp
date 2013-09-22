#include "FileGenerator.h"

#include <fstream>
using std::fstream;
using std::endl;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;
using std::srand;
    
#include <cstdio>
using std::sprintf;

#include <algorithm>
using std::swap;

#define RAND_FILES 10
#define ASC 10
#define DESC 11
#define FILENAME_LEN 30

FileGenerator::FileGenerator(){
    srand( time( 0 ) );
}

FileGenerator::~FileGenerator(){
}

bool FileGenerator::writeFile( const char* prefix, int quantity, int type ){
    bool success = false;
    
    switch( type ){
        case RANDOM:
            success = writeRandoms( prefix, quantity );
            break;
        case ASCENDING:
            success = writeAscending( prefix, quantity );
            break;
        case DESCENDING:
            success = writeDescending( prefix, quantity );
            break;
    }
    
    return success;
}

bool FileGenerator::writeAscending( const char* prefix, int q ){
    fstream file;
    char filename[FILENAME_LEN];
    bool ok = false;
    
    sprintf( filename, "%s%d_%d.txt", prefix, ASC, q );
    file.open( filename, fstream::out );
    if( file.is_open() ){
        for( int i = 1; i <= q; i++ ){
            file << i << endl;
        }
        file.close();
        ok = true;
    }
    
    return ok;
}

bool FileGenerator::writeDescending( const char* prefix, int q ){
    fstream file;
    char filename[FILENAME_LEN];
    bool ok = false;
    
    sprintf( filename, "%s%d_%d.txt", prefix, DESC, q );
    file.open( filename, fstream::out );
    if( file.is_open() ){
        for( int i = q; i > 0; i-- ){
            file << i << endl;
        }
        file.close();
        ok = true;
    }
    
    return ok;
}

bool FileGenerator::writeRandoms( const char* prefix, int q ){
    fstream file;
    char filename[FILENAME_LEN];
    int* numbers;
    int index;
    int i;
    bool ok = true;
    
    numbers = new int[q];
    for( int j = 0; j < RAND_FILES && ok; j++ ){
        sprintf( filename, "%s%d_%d.txt", prefix, j, q );
        for( i = 0; i < q; i++ ){
            numbers[i] = i + 1;
        }
        for( i = 0; i < q; i++ ){
            index = rand() % q;
            swap( numbers[i], numbers[index] );
        }
        
        file.open( filename, fstream::out );
        if( file.is_open() ){
            for( i = 0; i < q; i++ ){
                file << numbers[i] << endl;
            } 
            file.close();
        }
        else{
            ok = false;
        }
    }
    delete[] numbers;
    
    return ok;
}
