#ifndef FILE_GENERATOR_H
#define FILE_GENERATOR_H

class FileGenerator{
    private:
        bool writeAscending( int q );
        bool writeDescending( int q );
        bool writeRandom( int q );
        
    public:
        enum OrderType{
            RANDOM = 0,
            ASCENDING,
            DESCENDING
        };
        
        explicit FileGenerator();
        ~FileGenerator();
        bool writeFile( int quantity, int type );
};

#endif //FILE_GENERATOR_H
