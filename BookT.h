#pragma once
#include <string>

class BookT{
    public:
        BookT();

        void SetTitle(std::string title);
        void SetAuthor(std::string a);
        void SetPageCount(int pageC);
        void LoanTo(std::string reader);
        void Return();

        std::string GetTitle() const ;
        std::string GetAuthor() const;
        int GetPageCount() const;
        int GetTimesRead() const;
        std::string GetOnLoanTo() const;
        bool Present() const;
        int Count() const;

        void Increment();
        void AddPageCount(int pg);
    private:
        std::string book, author, onLoanTo;
        int pageCount, timesRead, bookID, count; // size_t
        bool present;
};