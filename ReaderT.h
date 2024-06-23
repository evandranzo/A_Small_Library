#pragma once
#include <string>

class ReaderT{
    public:
        ReaderT();
        //~ReaderT();

        void SetReaderName(std::string n);
        void Loanee(std::string book);
        void Return(int pageC);

        std::string Name() const ;
        std::string Book() const ;

        int GetBooksRead() const;
        int GetPagesRead() const;
        bool CheckedOut() const;

        void NextReader();
    private:
        std::string name, loanedBook;
        int booksRead, pagesRead;
        int readerID; // size_t
        bool hasBook;
};