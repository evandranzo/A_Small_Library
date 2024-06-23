#include <iostream>
#include "ReaderList.h"
#include "ReaderT.h"

const bool DEBUG{0};

ReaderList::ReaderList(){
    capacity = 10, size = 0, current = 0;
    readers = new ReaderT[capacity];
}
ReaderList::~ReaderList(){
    delete [] readers;
    readers = nullptr;
}
ReaderList::ReaderList(const ReaderList & other){
    int i;
    readers = new ReaderT[other.capacity];
    for(i =0; i < other.size; ++i) {
        readers[i] = other.readers[i];
    }
    size = other.size;
    current = other.current;
    capacity = other.capacity;
}
//overloaded assignment operator
ReaderList & ReaderList::operator =(const ReaderList & other){
   int i;
   if (this != &other) {
       delete[] readers;
       readers = new ReaderT[other.capacity];
       for(i =0; i < other.size; ++i) {
           readers[i] = other.readers[i];
       }
       size = other.size;
       current = other.current;
       capacity = other.capacity;
   }
   return *this;
}
void ReaderList::AddReader(std::string reader){
    ReaderT * tmp{nullptr};
    int i;
    if (size == capacity && capacity <= MAX_READERS) {
        capacity *= 2;
        tmp = new ReaderT[capacity];

        for (i = 0; i < size; ++i) {
           tmp[i] = readers[i];
        }
        delete [] readers;
        readers = tmp;
        tmp = nullptr;
    }
    readers[size].SetReaderName(reader);
    size++;
}
void ReaderList::Loanee(std::string book){
    readers[current].Loanee(book);
}
void ReaderList::Return(int pageC){
    readers[current].Return(pageC);
}
int ReaderList::ReaderCount() const{
    return size;
}
void ReaderList::FirstReader(){
    current = 0;
}
void ReaderList::NextReader(){
    if (current < size) {
       current ++;
    }
}
bool ReaderList::PastLastReader(){
    return current >= size;
}
void ReaderList::FindReader(std::string reader) {
    current = 0;
    while (current < size and readers[current].Name() != reader) {
       current ++;
    }
}
void ReaderList::SetReader(ReaderT reader) {
    if (current < size) {
        readers[current] = reader;
    } else {
        std::cout << "Current is invalid, not setting Reader" << std::endl;
    }
}
ReaderT ReaderList::GetReader(){
    ReaderT reader;
    if (current < size) {
        reader = readers[current];
    } else {
        std::cout << "Current is invalid, returning blank Reader" << std::endl;
    }
    return reader;
}