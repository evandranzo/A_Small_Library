#pragma once
#include "BookT.h"

const int MAX_BOOKS{1000};

class BookList {
    public:
        BookList();
        ~BookList();

        BookList(const BookList & other);
        BookList & operator =(const BookList & other);

        void AddBook(std::string bookName, std::string author, int pageCount);
        void LoanTo(std::string reader);
        void Return();
        int BookCount() const;

        void FirstBook();
        void NextBook();
        bool PastLastBook();

        void FindBook(std::string book);

        BookT GetBook();
        void SetBook(BookT book);

    private:
        BookT * books;
        int current;
        int size; //number of books
        int capacity;//max books
};