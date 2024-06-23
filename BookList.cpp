#include <iostream>
#include "BookList.h"
#include "BookT.h"

BookList::BookList(){
    capacity = 10;
    books = new BookT[capacity];
    size = 0;
    current = 0;
}
BookList::~BookList(){
    delete [] books;
    books = nullptr;
}
BookList::BookList(const BookList & other){
    int i;
    books = new BookT[other.capacity];
    for(i =0; i < other.size; ++i) {
        books[i] = other.books[i];
    }
    size = other.size;
    current = other.current;
    capacity = other.capacity;
}
//overloaded assignment operator
BookList & BookList::operator =(const BookList & other){
    int i;

    if (this != &other) {
        delete[] books;
        books = new BookT[other.capacity];
        for(i =0; i < other.size; ++i) {
            books[i] = other.books[i];
        }
        size = other.size;
        current = other.current;
        capacity = other.capacity;
    }
    return *this;
}
void BookList::AddBook(std::string bookName, std::string author, int pageCount){
    BookT * tmp{nullptr};
    int i;
    if (size == capacity && capacity < MAX_BOOKS) {
        capacity *= 2;
        tmp = new BookT[capacity];

        for (i = 0; i < size; ++i) {
           tmp[i] = books[i];
        }

        delete [] books;
        books = tmp;
        tmp = nullptr;
    }
    books[size].SetTitle(bookName);
    books[size].SetAuthor(author);
    books[size].SetPageCount(pageCount);
    size++;
}
void BookList::LoanTo(std::string reader){
    books[current].LoanTo(reader);
}
void BookList::Return(){
    books[current].Return();
}
int BookList::BookCount() const{
    return size;
}
void BookList::FirstBook(){
    current = 0;
}
void BookList::NextBook(){
    if (current < size) {
       current ++;
    }
}
bool BookList::PastLastBook(){
    return current >= size;
}
void BookList::FindBook(std::string book) {
    current = 0;
    while (current < size and books[current].GetTitle() != book) {
       current ++;
    }
}
void BookList::SetBook(BookT book) {
    if (current < size) {
        books[current] = book;
    } else {
        std::cout << "Current is invalid, not setting Book" << std::endl;
    }
    return;
}
BookT BookList::GetBook(){
    BookT book;
    if (current < size) {
        book = books[current];
    } else {
        std::cout << "Current is invalid, returning blank Book" << std::endl;
    }
    return book;//  VALGRIND, test for memory leak
}