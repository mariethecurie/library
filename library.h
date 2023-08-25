#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <stdexcept>
#include <vector>

class Library {
public:
    class Book {
    public:
        Book() = default;
        Book(const std::string& title, const std::string& author, const std::string& isbn, const std::string& genre);
        void setTitle(const std::string& title);
        std::string title() const;
        void setAuthor(const std::string& author);
        std::string author() const;
        void setISBN(const std::string& isbn);
        std::string ISBN() const;
        void setGenre(const std::string& genre);
        std::string genre() const;

    private:
        std::string m_title;
        std::string m_author;
        std::string m_ISBN;
        static const int NUMBER_OF_GENRES = 10;
        static const std::string m_genres[NUMBER_OF_GENRES];
        int m_genreIndex;
    };

    Library();
    int libraryID() const;
    const int& administratorID() const;
    void setAddress(const std::string& address);
    std::string address() const;
    void setContactInfo(const std::string& info);
    std::string contactInfo() const;
    static int totalBooks();
    void addBook(Book& book);
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN, const std::string& genre);
    void removeBook(const Book& book);
    void displayLibrary() const;

private:
    static int m_trackLibraryIDs;
    const int m_libraryID;
    const int& m_administratorID = m_libraryID;
    std::string m_address;
    std::string m_contactInfo;
    static int m_totalBooks;
    std::vector<Book*> m_books;
};

#endif