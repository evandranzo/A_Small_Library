This was a project from 230, Principles of Programming at Edinboro

Here is the requirements for the assignment

Project 3, A small library.
Short Description:
Write a program that maintains information about books and readers in a small library.

Goals
When you finish this homework, you should have:

    Worked with arrays
    Worked with classes. 

Formal Description
You have been hired to write a simple database for a small library. This library has a collection of books and a set of readers. Readers are identified by their full name and books are identified by their title. The library wishes to track the who is borrowing the books and how often the books are being read. In addition, the library wishes to know how many books and pages each reader has read.

The library holds no more than 1000 books, and has no more than 50 readers. Your program should ensure that these conditions are enforced. Also, your program should be flexible and these limits should be easy to change.

A book consists of the following:

    A title. This string can contain spaces but never contains a :
    An Author. This string can contain spaces but never contains a :
    A page count. This is a positive integer. 

At any time the library might wish to know this information as well as if the book is present in the library, who has the book if it is checked out, and the number of times the book has been read, not counting the current reader if there is one.

A reader consists of a name. At any time the library might wish to know the if the reader has a book, and if so, what book, as well as the number of books and pages the reader has read excluding the current book.

The library wishes to allow the following actions

    CHECKOUT title:reader
    RETURN title
    REPORT reader
    STATS title
    PRINT BOOK|PEOPLE 

CHECKOUT: this will allow a reader to check out the given title from the library as long as the title exists, the reader exists, the book is present and the reader does not currently have a book.

Note the statistics on the reader and the book do not change when the book is checked out.

    If the reader is not in the reader list, you should print the following message and stop processing the command.

    Error: unknown reader name.  

    If the title is not in the list of books, you should print the following message and stop processing the command.

    Error: unknown book title.  

    If the book is already checked out, you should print the following message and stop processing the command.

    Error: title is already checked out.  

    If the reader already has a book checked out, you should print the following message and stop processing the command.

    Error: name already has a book. 

    Otherwise, you should print the message

    Loaning title to name.

RETURN: this will allow a reader to return a book. This will remove the book from the reader and place it back in the library. The stats for both the reader and the library should be updated at this point.

    If the title is not in the list of books, you should print the following message and stop processing the command.

    Error: unknown book title.  

    If the title is currently in the library, IE not checked out, you should print the following message and stop processing the command

    Error: title has not been checked out.

    Otherwise return the book and print the following message.

    name has returned title.

REPORT: produce a report on the reader.

    If the reader is not in the reader list, you should print the following message and stop processing the command.

    Error: unknown reader name.  

    Otherwise print the following report,
        The persons name (newline)
        A tab
        Books read:
        the book count
        a period and a newline.
        A tab
        Pages read:
        the page count.
        a period and a newline.
        If the user has a book checked out
            A tab.
            The current book is:
            The title.
            a period and a new line. 
    Examples:

    Dora Lindsay
            Books read: 1.
            Pages read: 1225.
            The current book is: Kidnapped.

    Alden Marquez
            Books read: 0.
            Pages read: 0.
       

STATS: print the statistics for a book.

    If the title is not in the list of books, you should print the following message and stop processing the command.

    Error: unknown book title.  

    Otherwise print the following report:
        The book title and a newline
        a tab
        by
        the author's name
        A period and a newline
        a tab
        Pages:
        The pages in the book.
        A period and a newline
        a tab
        Total Reads:
        the total number of people who have read the book.
        A period and a newline
        If the book is not present in the library print the following
            A tab
            On loan to
            The name of the reader who has the book.
            A period and a newline. 
    Example output

    War and Peace
            by Leo Tolstoy.
            Pages: 1225.
            Total Reads: 0.
            On loan to: Dora Lindsay.

    Kidnapped
            by Robert Louis Stevenson.
            Pages: 136.
            Total Reads: 1.
         

PRINT: this will print the list of all books or readers depending on the argument.

    Depending on the argument, either print all of the books or all of the readers in the databases.
    Output should be in the order the items were inserted into the database.
    If an argument other than PEOPLE or BOOKS is encountered, print the following message

    Error: unknown report type type.

    Use the formats described in REPORT and STATS
    For books, first print

    There are bookcount books in the library.
    They are:

    For people, first print

    There are personcount people using the library.
    They are:

    Examples:

    Executing PRINT BOOKS.
    There are 3 books in the library.
    They are:
    War and Peace
            by Leo Tolstoy.
            Pages: 1225.
            Total Reads: 2.
    Kidnapped
            by Robert Louis Stevenson.
            Pages: 136.
            Total Reads: 2.
    Watership Down
            by Richard Adams.
            Pages: 413.
            Total Reads: 1.

    Executing PRINT PEOPLE.
    There are 4 people using the library.
    They are:
    Dora Lindsay
            Books read: 3.
            Pages read: 1774.
    Alden Marquez
            Books read: 1.
            Pages read: 136.
    Ignacia Pace
            Books read: 1.
            Pages read: 1225.
    Hayes Schroeder
            Books read: 0.
            Pages read: 0.
        

The program should work as follows:

    Prompt the user for a configuration file.
        The prompt should be

            Enter the name of the configuration file => 

            There should be a space following the >
            After the user enters the file name, print an endl
            Then print

            Opening filename.

            You may use the following code

            do {
                cout << "Enter the name of the configuration file => ";
                cin >> name;
                cout << endl;
                cout << "Opening " << name  << "." << endl; 
                inFile.open(name);
            } while (not inFile); 

            If the program was unable to open the file, repeat the prompt process. Do not print an error message. 
        This file will be format error free and will contain three file names.
            The name of the file containing books.
            The name of the file containing readers.
            The name of a file containing the actions to perform. 
        An example configuration file.

            books.dat
            names.dat
            commands.dat 

    Read in the data from the books file.
        This file contains one line per book.
        Each line contains a title, author and page count separated by :
        This file will be format error free.
        An example file is

            War and Peace:Leo Tolstoy:1225
            Kidnapped:Robert Louis Stevenson:136
            Watership Down:Richard Adams:413 

        Set the stats for all books 0.
        When reading the book file, print the following message

        Reading books from fileName.

        If the number of books is larger than the given limit, for each book that can not be inserted into the array, print the following message

        Error: can not add title to the library.  It is full.  

        If the book file does not exist print the error

        Error: unable to open the book file filename.  

    Read in the data from the readers file.
        This file contains one reader per line.
        There are no errors in this file.
        An example file is

            Dora Lindsay
            Alden Marquez
            Ignacia Pace
            Hayes Schroeder 

        When reading the readers file, print the message

        Reading people from filename.

        If the reader file does not exist print

        Error: unable to open reader file filename.

        If the number of readers is larger than the given limit for each reader that can not be inserted into the reader array print the following message

        Error: reader list is full.  Unable to add name.

    Process the actions in the action file.
        When an action is executed, print the following

        Executing action.  

        For example if the command is "REPORT Alden Marquez", your program should print

        Executing REPORT Alden Marquez.  

        Once the action has been executed, your program should print a blank line.
        This file contains one action per line as described above.
        The file is format error free
        An example of this file is

            PRINT BOOKS
            PRINT PEOPLE
            CHECKOUT War and Peace:Dora Lindsay
            REPORT Dora Lindsay
            STATS War and Peace
            RETURN War and Peace
            CHECKOUT Kidnapped:Dora Lindsay
            CHECKOUT Kidnapped:Alden Marquez
            REPORT Dora Lindsay
            REPORT Alden Marquez
            STATS Kidnapped
            RETURN Kidnapped
            REPORT Dora Lindsay
            REPORT Alden Marquez
            STATS Kidnapped
            CHECKOUT Watership Down:Dora Lindsay
            CHECKOUT Kidnapped:Alden Marquez
            CHECKOUT War and Peace:Ignacia Pace
            STATS Kidnapped
            STATS War and Peace
            STATS Watership Down
            RETURN Watership Down
            RETURN Kidnapped
            RETURN War and Peace
            REPORT Dora Lindsay
            REPORT Alden Marquez
            REPORT Ignacia Pace
            PRINT BOOKS
            PRINT PEOPLE 

        If a bad action is encountered, print the following message and continue processing the file

        Error: unknown action action.

Sample Data Files

    case1.dat a configuration file.
    books.dat a sample library file.
    names.dat a sample reader file.
    commands.dat a sample commands file.
    output.txt a sample of what the output should be. Note, the output should be to standard out, not a file. 

Please note

    All input, except for the configuration file name, is from a file.
    Files have a newline character (\n) at the end of the line, but not carriage return (\r)
    All output should be to standard output.
    All output should have a newline at the end (\n), this is produced by endl.
    There should be no extra spaces in the output, especially at the end of lines. 

Notes

    Your program should be written so that additional actions can be added easily.
    Your code must be modular in design, with small functions.
    You should create four classes
        A reader class, ReaderT, that is responsible for actions related to readers.
        A book class, BookT, that is responsible for actions related to books.
        An reader list class, ReaderListT, that is responsible for storing and retrieving readers.
        An book list class, BookListT, that is responsible for storing and retrieving books. 
    If you wish you may create additional classes. 

Other Requirements

    The code must employ at least one enumeration type.
    This code must compile without errors or warnings on cslab103.
    The code must be compiled with the following compiler flags

     -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -std=c++17

    The project must include a Makefile,
        The makefile must
            Build the entire project
            Contain a clean target which removes object files and executables. 
        You may use this Makefile
            Save it in your project directory.
            Your source code should be called library.C or library.cpp 
        This will produce an executable called library 
    Your code should follow the Local Programming Style Guild for C++ 

Required Files
A single tar or zip file containing the source code and makefile for this program. Your tar file should not contain executable code (library) or any object files (*.o).

Submission
Submit your tar file to the D2L assignment folder Project 3 by the due date. 
