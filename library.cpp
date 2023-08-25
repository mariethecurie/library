#include "library.h"

int Library::m_trackLibraryIDs = 0;
int Library::m_totalBooks = 0;

Library::Library()
    : m_libraryID {m_trackLibraryIDs} {
        ++m_trackLibraryIDs;
}

int Library::libraryID() const {
    return m_libraryID;
}

const int& Library::administratorID() const {
    return m_administratorID;
}

void Library::setAddress(const std::string& address) {
    m_address = address;
}

std::string Library::address() const {
    return m_address;
}

void Library::setContactInfo(const std::string &info) {
    m_contactInfo = info;
}

std::string Library::contactInfo() const {
    return m_contactInfo;
}

void Library::displayLibrary() const {
    std::cout << "Information about library: " << std::endl;
    std::cout << "ID: " << libraryID() << std::endl;
    std::cout << "Administrator ID: " << administratorID() << std::endl;
    std::cout << "Address: " << address() << std::endl;
    std::cout << "Contact Info: " << contactInfo() << std::endl;
    std::cout << "Total number of books: " << totalBooks() << std::endl;
}

int Library::totalBooks() {
    return m_totalBooks;
}

void Library::addBook(Book &book) {
    m_books.push_back(&book);
    ++m_totalBooks;
}

void Library::addBook(const std::string& title, const std::string& author, const std::string& ISBN, const std::string& genre) {
    m_books.push_back(new Book(title, author, ISBN, genre));
    ++m_totalBooks;
}

void Library::removeBook(const Book& book) {
    for (size_t i = 0; i < m_books.size(); ++i) {
        if (book.ISBN() == m_books[i]->ISBN()) {
            m_books.erase(m_books.begin() + i);
            --m_totalBooks;
            break;
        }
    }
}

const std::string Library::Book::m_genres[NUMBER_OF_GENRES] = {
        "Fiction",
        "Non-Fiction",
        "Mystery",
        "Science Fiction",
        "Fantasy",
        "Historical",
        "Romance",
        "Thriller",
        "Horror",
        "Biography"
};

Library::Book::Book(const std::string& title, const std::string& author, const std::string& isbn, const std::string& genre) {
    setTitle(title);
    setAuthor(author);
    setISBN(isbn);
    setGenre(genre);
}

void Library::Book::setTitle(const std::string &title) {
    m_title = title;
}

std::string Library::Book::title() const {
    return m_title;
}

void Library::Book::setAuthor(const std::string &author) {
    m_author = author;
}

std::string Library::Book::author() const {
    return m_author;
}

void Library::Book::setISBN(const std::string& isbn) {
    m_ISBN = isbn;
}

std::string Library::Book::ISBN() const {
    return m_ISBN;
}

void Library::Book::setGenre(const std::string& genre) {
    for (int i = 0; i < NUMBER_OF_GENRES; ++i) {
        if (genre == m_genres[i]) {
            m_genreIndex = i;
            return;
        }
    }

    throw std::runtime_error("No such genre");
}

std::string Library::Book::genre() const {
    return m_genres[m_genreIndex];
}

