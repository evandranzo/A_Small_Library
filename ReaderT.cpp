#include <iostream>
#include "ReaderT.h"

ReaderT::ReaderT() {
    name = "";
    booksRead = 0;
    pagesRead = 0;
    readerID = 0; // size_t
    hasBook = 0;
    loanedBook = "";
}
void ReaderT::SetReaderName(std::string n){
    name = n;
}

void ReaderT::Loanee(std::string book){
    loanedBook = book;
    hasBook = 1;
}
void ReaderT::Return(int pageC){
    pagesRead = pagesRead + pageC;
    ++booksRead;
    hasBook = 0;
}

bool ReaderT::CheckedOut()const {
    return hasBook;
}
std::string ReaderT::Name() const {
    return name;
}
std::string ReaderT::Book() const {
    return loanedBook;
}
int ReaderT::GetBooksRead() const {
    return booksRead;
}
int ReaderT::GetPagesRead() const {
    return pagesRead;
}

void ReaderT::NextReader() {
    readerID++;
}