#pragma once
#include "ReaderT.h"

const int MAX_READERS{50};
class ReaderList {
    public:
        ReaderList();
        ~ReaderList();

        ReaderList(const ReaderList & other);
        ReaderList & operator =(const ReaderList & other);

        void AddReader(std::string reader);
        void Loanee(std::string book);
        void Return(int pageC);
        int ReaderCount() const;

        void FirstReader();
        void NextReader();
        bool PastLastReader();

        void FindReader(std::string reader);

        ReaderT GetReader();
        void SetReader(ReaderT reader);
        void ReturnReader(int readerid, ReaderT reader);
    private:
        ReaderT * readers;
        int current;
        int size; //number of readers
        int capacity;//max readers
};