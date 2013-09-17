#include "FileGenerator.h"

#include <fstream>
using std::fstream;

#include <ctime>
using std::time;

#include <cstdlib>
using std::rand;
using std::srand;
    
#include <cstdio>
using std::sprintf;

#define RAND_FILES 10
#define NAME_LEN 30

FileGenerator::FileGenerator(){
}

FileGenerator::~FileGenerator(){
}

bool FileGenerator::writeFile( int quantity, int type ){
    bool success;
    
    switch( type ){
        case RANDOM:
            success = writeRandom( quantity );
            break;
        case ASCENDING:
            success = writeAscending( quantity );
            break;
        case DESCENDING:
            success = writeDescending( quantity );
            break;
    }
    
    return success;
}

bool FileGenerator::writeAscending( int q ){
    bool ok = false;
    fstream file( "asc.txt", fstream::out );
    
    if( file.is_open() ){
        for( int i = 1; i <= q; i++ ){
            file << i << " ";
        }
        ok = true;
        file.close();
    }
    
    return ok;
}

bool FileGenerator::writeDescending( int q ){
    bool ok = false;
    fstream file( "dsc.txt", fstream::out );
    
    if( file.is_open() ){
        for( int i = q; i >= 1; i-- ){
            file << i << " ";
        }
        ok = true;
        file.close();
    }
    
    return ok;
}

bool FileGenerator::writeRandom( int q ){
    bool ok = true;
    fstream file;
    char filename[NAME_LEN];
    
    srand( time( 0 ) );
    for( int i = 1; i <= RAND_FILES and ok; i++ ){
        sprintf( filename, "rand%d.txt", i );
        file.open( filename, fstream::out );
        if( file.is_open() ){
            for( int j = 0; j < q; j++ ){
                file << rand() << " ";
            }
            file.close();
        }
        else{
            ok = false;
        }
    }
    
    return ok;
}
