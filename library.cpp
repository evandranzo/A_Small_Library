/*
	Program 3:  Library
	Programmer: Evan Dranzo, with help provided to the cremlin
	Class:		CSCI230, Spring 2022
	Short Description:	Program that maintains information about books and readers in a small library.

	Dynamic Memory was used
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "BookT.h"
#include "BookList.h"
#include "ReaderT.h"
#include "ReaderList.h"
#include "Parser.h"
using namespace std;

struct LibraryT {
	ReaderList readers;
	BookList books;
    CommandT cmd;
};

string OpenFiles (ifstream & inFile, LibraryT & lib);
void ProcessCommand (LibraryT & lib);

ReaderList ReaderFile(string fileName);
void PrintReader(ReaderList & readers);

BookList BookFile(string fileName);
void PrintBook(BookList & books);

void CheckOut(LibraryT & lib, string title, string name);
void Return(LibraryT & lib, string title);

int main(){
	LibraryT lib;
	string name;
    ifstream inFile, cmdFile;

	do {
		cout << "Enter the name of the configuration file => ";
		cin >> name;
		cout << endl << "Opening " << name  << "." << endl;
		inFile.open(name);
	} while (not inFile);

	cmdFile.open(OpenFiles(inFile, lib));
	inFile.close();

	lib.cmd = ParseNextLine(cmdFile);
    while(lib.cmd.op != OperatorT::NONE){
		ProcessCommand(lib);
        lib.cmd = ParseNextLine(cmdFile);
    }
	cmdFile.close();
    return 0;
}
string OpenFiles (ifstream & inFile, LibraryT & lib){
	ReaderT reader;
	BookT book;
	string file;

	inFile >> file;
	while (file != ""){
		if (file == "books.dat"){
			lib.books = BookFile("books.dat");
			cout << "Reading books from " << file << ".\n";
		} else if (file == "names.dat"){
			lib.readers = ReaderFile("names.dat");
			cout << "Reading people from " << file << ".\n";
		} else if (file == "commands.dat"){
			return file;
		}
		inFile >> file;
	}
	return file;
}
void ProcessCommand (LibraryT & lib){
	ReaderT reader;
	BookT book;
	
	if (lib.cmd.operandCount == 1){
		cout << "Executing " << lib.cmd.command << " " << lib.cmd.operand[0] << ".\n";
	} else if (lib.cmd.operandCount == 2){
		cout << "Executing " << lib.cmd.command << " " << lib.cmd.operand[0] << ":" <<
		lib.cmd.operand[1] <<  ".\n";
	}
	if (lib.cmd.op == OperatorT::CHECKOUT){
		CheckOut(lib, lib.cmd.operand[0], lib.cmd.operand[1]);
	} else if (lib.cmd.op == OperatorT::RETURN){
		Return(lib, lib.cmd.operand[0]);
	} else if (lib.cmd.op == OperatorT::REPORT){
		lib.readers.FindReader(lib.cmd.operand[0]);
		reader = lib.readers.GetReader();
		PrintReader(lib.readers);
	} else if (lib.cmd.op == OperatorT::STATS){
		lib.books.FindBook(lib.cmd.operand[0]);
		book = lib.books.GetBook();
		PrintBook(lib.books);
	} else if (lib.cmd.op == OperatorT::PRINT){
		if (lib.cmd.operand[0] == "PEOPLE"){
			lib.readers.FirstReader();
			reader = lib.readers.GetReader();
			cout << "There are " << lib.readers.ReaderCount() << " people using the library.\n"
				 << "They are:\n";
			while (not lib.readers.PastLastReader()) {
				PrintReader(lib.readers);
				lib.readers.NextReader();
			} 
		} else if (lib.cmd.operand[0] == "BOOKS"){
			lib.books.FirstBook();
			book = lib.books.GetBook();
			cout << "There are " << lib.books.BookCount() << " books in the library.\n"
				 << "They are:\n";
			while (not lib.books.PastLastBook()) {
				PrintBook(lib.books);
				lib.books.NextBook();
			}
    	}
	} else {
		lib.cmd.op = OperatorT::NONE;
	}
	cout << endl;
}
ReaderList ReaderFile(string fileName){
    ifstream inFile(fileName);
    string reader;
    ReaderList readers;
    ReaderT entry;

    getline(inFile, reader);
    while (inFile) {
        if (reader != "") {
            readers.FindReader(reader);
            if (readers.PastLastReader()) {
                readers.AddReader(reader);
            }
        }
        getline(inFile, reader);
    }
    return readers;
}
void PrintReader(ReaderList & readers){
    ReaderT reader;

	reader = readers.GetReader();
	cout << reader.Name()
		<< "\n\tBooks read: " << reader.GetBooksRead()
		<< ".\n\tPages read: " << reader.GetPagesRead() << ".\n";
	if (reader.CheckedOut() == 1){
		cout << "\tThe current book is: " << reader.Book() << ".\n";
	}
	return;
}
BookList BookFile(string fileName){
    ifstream inFile(fileName);
    BookList books;
    BookT entry;
    string book, bookName, a;
	int pageC;
	size_t pos, posTwo;

    getline(inFile, book);
    while (inFile) {
        if (book != "") {
           	books.FindBook(book);
           	if (books.PastLastBook()) {
				pos = book.find(':');
				bookName = book.substr(0,pos);
				a = book.substr(pos+1);
				posTwo = a.find(':');
				pageC = stoi(a.substr(posTwo + 1));
				a = book.substr(pos+1, posTwo);

				books.AddBook(bookName, a, pageC);
			} else {
				entry = books.GetBook();
				entry.Increment();
				books.SetBook(entry);
			}
        }
        getline(inFile, book);
    }
    return books;
}
void PrintBook(BookList & books){
    BookT book;

	book = books.GetBook();
	cout << book.GetTitle()
		 << "\n\tby " << book.GetAuthor()
		 << ".\n\tPages: " << book.GetPageCount()
		 << ".\n\tTotal Reads: " << book.GetTimesRead() << ".\n";
	if (book.Present() == 0){
		cout << "\tOn loan to: " << book.GetOnLoanTo() << ".\n";
	}
	return;
}
void CheckOut(LibraryT & lib, string title, string name){
	ReaderT reader;
	BookT book;
	lib.readers.FindReader(name);
	lib.books.FindBook(title);
	book = lib.books.GetBook();
	reader = lib.readers.GetReader();

	if (reader.CheckedOut() == 0){
		if (book.Present()){
			cout << "Loaning " << book.GetTitle() << " to " << reader.Name() << ".\n";
			lib.books.LoanTo(name);
			lib.readers.Loanee(title);
		} else {
			cout << "Error: " << book.GetTitle() << " is already checked out.\n";
		}
	} else {
		cout << "Error: " << reader.Name() << " already has a book.\n"; 
	}
}
void Return(LibraryT & lib, string title){
	BookT book;
	ReaderT reader;
	lib.books.FindBook(title);
	book = lib.books.GetBook();
	lib.readers.FindReader(book.GetOnLoanTo());
	reader = lib.readers.GetReader();

	if (not book.Present()){
		cout << book.GetOnLoanTo() <<" has returned " << book.GetTitle() << ".\n";
		lib.books.Return();
		lib.readers.Return(book.GetPageCount());
	} else {
		cout << "Error: " << book.GetTitle() << " is already checked out.\n";
	}
}