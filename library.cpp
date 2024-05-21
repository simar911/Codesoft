#include <iostream>
#include <string.h>
using namespace std;
class Library {
  public:
    char book[50];
    char author[50];
    int pages;
    int load_price;

    void add_book() {
      cout << "Enter book name: ";
      cin.getline(book, 50);
      cout << "Enter author name: ";
      cin.getline(author, 50);
      cout << "Enter number of pages: ";
      cin >> pages;
      cin.ignore();
      cout << "Enter load price: ";
      cin >> load_price;
      cin.ignore();
    }

    void display_book() {
      cout << "\nBook Information:\n";
      cout << "Book name: " << book << "\n";
      cout << "Author name: " << author << "\n";
      cout << "Number of pages: " << pages << "\n";
      cout << "Load price: " << load_price << "\n";
    }

    static void list_books_by_author(Library *books, int num_books, char *author) {
      int i;
      int count = 0;
      for (i = 0; i < num_books; i++) {
        if (strcmp(books[i].author, author) == 0) {
          books[i].display_book();
          count++;
        }
      }
      if (count == 0) {
        cout << "No books found by this author.\n";
      }
    }

    static int total_cost(Library *books, int num_books, char *author, int price) {
      int i;
      int count = 0;
      for (i = 0; i < num_books; i++) {
        if (strcmp(books[i].author, author) == 0) {
          count++;
        }
      }
      return count * price;
    }
};

int main() {
  Library books[100];
  int num_books = 0;
  int choice;

  while (1) {
    cout << "\nWelcome to e-library\n";
    cout << "1. Add book\n";
    cout << "2. Display book information\n";
    cout << "3. List all books of given author\n";
    cout << "4. Account of the books in the library\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        books[num_books].add_book();
        num_books++;
        break;
      case 2:
        books[num_books - 1].display_book();
        break;
      case 3:
        {
          char author[50];
          cout << "Enter author name: ";
          cin.getline(author, 50);
          Library::list_books_by_author(books, num_books, author);
          break;
        }
      case 4:
        {
          char author[50];
          int num_books_author;
          int price;
          cout << "Enter author name: ";
          cin.getline(author, 50);
          cout << "Enter number of books of this author in the library: ";
          cin >> num_books_author;
          cin.ignore();
          cout << "Enter price of one book: ";
          cin >> price;
          cin.ignore();
          cout << "Total cost: " << Library::total_cost(books, num_books, author, price) << "\n";
          break;
        }
      case 5:
        exit(0);
      default:
        cout << "Invalid choice\n";
    }
  }

  return 0;
}