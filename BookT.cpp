#include <iostream>
#include "BookT.h"

BookT::BookT() {
    book = "", author = "";
    pageCount = 0, timesRead = 0;
    bookID = 0;
    count = 0;
    present = 1;
    onLoanTo = "";
}

void BookT::SetTitle(std::string t){
    book = t;
}
void BookT::SetAuthor(std::string a){
    author = a;
}
void BookT::SetPageCount(int pageC){
    pageCount = pageC;
}
void BookT::LoanTo(std::string reader){
    onLoanTo = reader;
    present = 0;
}
void BookT::Return(){
    ++timesRead;
    onLoanTo = "";
    present = 1;
}

std::string BookT::GetTitle() const {
    return book;
}
std::string BookT::GetAuthor() const{ 
    return author;
}
int BookT::GetPageCount() const{
    return pageCount;
}
int BookT::GetTimesRead() const{
    return timesRead;
}
std::string BookT::GetOnLoanTo() const{
    return onLoanTo;
}
bool BookT::Present() const{
    return present;
}
int BookT::Count() const {
    return count;
}

void BookT::Increment() {
    count++;
}
void BookT::AddPageCount(int pg){
    pageCount = pageCount + pg;
}
