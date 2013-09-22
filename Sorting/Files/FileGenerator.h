#ifndef FILE_GENERATOR_H
#define FILE_GENERATOR_H

class FileGenerator{
    private:
        bool writeAscending( const char* prefix, int q );
        bool writeDescending( const char* prefix, int q );
        bool writeRandoms( const char* prefix, int q );
        
    public:
        enum OrderType{
            RANDOM = 0,
            ASCENDING = 1,
            DESCENDING = 2
        };
        
        explicit FileGenerator();
        ~FileGenerator();
        bool writeFile( const char* prefix, int quantity, int type );
};

#endif //FILE_GENERATOR_H
