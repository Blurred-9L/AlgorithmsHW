#include "SortTimer.h"

#include <iostream>
using std::cout;
using std::endl;

SortTimer::SortTimer() :
    comparisons_( 0 ),
    assignments_( 0 ),
    seconds_( 0 ){
}

SortTimer::~SortTimer(){
}

long long SortTimer::comparisons() const{
    return comparisons_;
}
long long SortTimer::assignments() const{
    return assignments_;
}

double SortTimer::seconds() const{
    return seconds_;
}

void SortTimer::reset(){
    comparisons_ = assignments_ = 0;
}

void SortTimer::getStats( int* array, int n, int sort, bool output ){
    reset();
    
    switch( sort ){
        case Bubble:
            timerStart_ = clock();
            bubble( array, n );
            timerEnd_ = clock();
            break;
        case Insertion:
            timerStart_ = clock();
            insertion( array, n );
            timerEnd_ = clock();
            break;
        case Selection:
            timerStart_ = clock();
            selection( array, n );
            timerEnd_ = clock();
            break;
        case Shell:
            timerStart_ = clock();
            shell( array, n );
            timerEnd_ = clock();
            break;
        case Quick:
            timerStart_ = clock();
            quick( array, 0, n - 1 );
            timerEnd_ = clock();
            break;
    }
    seconds_ = (double)( timerEnd_ - timerStart_ ) / CLOCKS_PER_SEC;
    
    if( output ){
        cout << "No. Elements: " << n << endl
             << "Comparisons: " << comparisons_ << endl
             << "Assignments: " << assignments_ << endl
             << "Time: " << seconds_ << " seconds" << endl;
        /*for( int i = 0; i < n; i++ ){
            cout << array[i] << " ";
        }
        cout << endl;*/
    }
}

void SortTimer::swap( int& x, int& y ){
    int z = x;
    
    x = y;
    y = z;
}

void SortTimer::bubble( int* array, int n ){
    int i, j;
    
    for( i = 0; i < n; i++ ){
        for( j = 0; j < n - 1; j++ ){
            if( array[j] > array[j + 1] ){
                swap( array[j], array[j + 1] );
                assignments_ += 2;
            }
            comparisons_ += 1;
        }
    }
}

void SortTimer::insertion( int* array, int n ){
    int i, j, aux;
    
    for( i = 1; i < n; i++ ){
        j = i;
        aux = array[i];
        while( j > 0 && aux < array[j - 1] ){
            comparisons_++;
            array[j] = array[j - 1];
            assignments_++;
            j--;
        }
        comparisons_++;
        array[j] = aux;
        assignments_++;
    }
}

void SortTimer::selection( int* array, int n ){
    int i, j, menor;
    
    for( i = 0; i < n - 1; i++ ){
        menor = i;
        for( j = i + 1; j < n; j++ ){
            comparisons_++;
            if( array[j] < array[menor] ){
                menor = j;
            }
        }
        swap( array[i], array[menor] );
        assignments_ += 2;
    }
}

void SortTimer::shell( int* array, int n ){
    int i, j, aux, salto;
    
    salto = n / 2;
    while( salto > 0 ){
        for( i = salto; i < n; i++ ){
            j = i;
            aux = array[i];
            while( j >= salto && aux < array[j - salto] ){
                comparisons_++;
                array[j] = array[j - salto];
                assignments_++;
                j -= salto;
            }
            comparisons_++;
            array[j] = aux;
            assignments_++;
        }
        salto /= 2;
    }
}

void SortTimer::quick( int* array, int izq, int der ){
    int i, j, pivote;
    
    i = izq;
    j = der;
    pivote = array[( izq + der ) / 2];
    while( i <= j ){
        comparisons_++;
        while( array[i] < pivote ){
            comparisons_++;
            i++;
        }
        comparisons_++;
        while( array[j] > pivote ){
            comparisons_++;
            j--;
        }
        if( i <= j ){
            swap( array[i], array[j] );
            assignments_ += 2;
            i++;
            j--;
        }
    }
    
    if( izq < j ){
        quick( array, izq, j );
    }
    if( i < der ){
        quick( array, i, der );
    }
}
