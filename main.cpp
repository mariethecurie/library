#include "library.h"

int main() {
    Library lib;
    lib.setAddress("address");
    lib.setContactInfo("contacts");

    Library::Book book1 {"title", "author", "isbn", "Romance"};
    Library::Book book2 {"title2", "author2", "isbn2", "Horror"};
    Library::Book book3 {"title3", "author3", "isbn3", "Horror"};

    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);
    lib.removeBook(book2);

    lib.displayLibrary();
}