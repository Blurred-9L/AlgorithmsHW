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
            timerEnd_ = clock();
            break;
        case Selection:
            timerStart_ = clock();
            timerEnd_ = clock();
            break;
        case Shell:
            timerStart_ = clock();
            timerEnd_ = clock();
            break;
        case Quick:
            timerStart_ = clock();
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
