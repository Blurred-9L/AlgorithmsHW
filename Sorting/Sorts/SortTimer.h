#ifndef SORT_TIMER_H
#define SORT_TIMER_H

#include <ctime>
using std::clock_t;

class SortTimer{
    private:
        long long comparisons_;
        long long assignments_;
        clock_t timerStart_;
        clock_t timerEnd_;
        double seconds_;
        
        void swap( int& x, int& y );
        void bubble( int* array, int n );
        void insertion( int* array, int n );
        void selection( int* array, int n );
        void shell( int* array, int n );
        void quick( int* array, int izq, int der );
        
    public:
        enum Sort{
            Bubble = 0,
            Insertion,
            Selection,
            Shell,
            Quick
        };
    
        explicit SortTimer();
        ~SortTimer();
        long long comparisons() const;
        long long assignments() const;
        double seconds() const;
        void getStats( int* array, int n, int sort, bool output = true );
        void reset();
};

#endif //SORT_TIMER_H
