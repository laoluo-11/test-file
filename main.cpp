//图书管理系统
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int available;
};

void display_menu();
void add_book(struct Book books[], int* num_books);
void search_book(struct Book books[], int num_books);
void update_book(struct Book books[], int num_books);
void delete_book(struct Book books[], int* num_books);
void display_books(struct Book books[], int num_books);
//登陆函数
int login() ;
int main() {
    struct Book books[MAX_BOOKS];
    int num_books = 0;
    //登录成功则继续执行，否则打印密码或账号错误，继续执行登录函数
    int login_result = login();
    while (login_result != 1) {
            printf("Password or account error. Please try again.\n");
            login_result = login();
    }
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book(books, &num_books);
                break;
            case 2:
                search_book(books, num_books);
                break;
            case 3:
                update_book(books, num_books);
                break;
            case 4:
                delete_book(books, &num_books);
                break;
            case 5:
                display_books(books, num_books);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
    // Unreachable code
    // free(books);


}

void display_menu() {
    printf("1. Add book\n");
    printf("2. Search book\n");
    printf("3. Update book\n");
    printf("4. Delete book\n");
    printf("5. Display all books\n");
    printf("6. Exit\n");
}

void add_book(struct Book books[], int* num_books) {
    if (*num_books >= MAX_BOOKS) {
        printf("Cannot add more books. Maximum limit reached.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &books[*num_books].id);

    printf("Enter book title: ");
    scanf("%s", books[*num_books].title);

    printf("Enter book author: ");
    scanf("%s", books[*num_books].author);

    books[*num_books].available = 1;
    (*num_books)++;
}

void search_book(struct Book books[], int num_books) {
    if (num_books == 0) {
        printf("No books available.\n");
        return;
    }

    printf("Enter book ID to search: ");
    int id;
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (books[i].id == id) {
            printf("Title: %s\nAuthor: %s\nAvailable: %s\n", books[i].title, books[i].author, books[i].available? "Yes" : "No");
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void update_book(struct Book books[], int num_books) {
        if (num_books == 0) {
            printf("No books available.\n");
            return;
        }

        printf("Enter book ID to update: ");
        int id;
        scanf("%d", &id);

        int found = 0;
        for (int i = 0; i < num_books; i++) {
            if (books[i].id == id) {
                printf("Enter new title: ");
                scanf("%s", books[i].title);

                printf("Enter new author: ");
                scanf("%s", books[i].author);

                printf("Book updated successfully.\n");
                found = 1;
            }
        }

        if (!found) {
            printf("Book not found.\n");
        }
}

void delete_book(struct Book books[], int* num_books) {
    if (num_books == 0) {
        printf("No books available.\n");
        return;
    }

    printf("Enter book ID to delete: ");
    int id;
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < *num_books; i++) {
        if (books[i].id == id) {
            for (int j = i; j < *num_books - 1; j++) {
                books[j] = books[j + 1];
            }
            (*num_books)--;
            printf("Book deleted successfully.\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void display_books(struct Book books[], int num_books) {
    if (num_books == 0) {
        printf("No books available.\n");
        return;
    }

    printf("ID\tTitle\tAuthor\tAvailable\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d\t%s\t%s\t%s\n", books[i].id, books[i].title, books[i].author, books[i].available? "Yes" : "No");
    }
}
int login() {
    User user={"admin","admin"};
    User input={"",""};
    printf("Username:");
    while(getchar()!='\n'){
        //continue getting input until newline
        input.username.pop_back();
    }
    printf("Password:");
    while(getchar()!='\n'){
        //continue getting input until newline
        input.password.pop_back();
    }
    if(user.username==input.username &&user.password==input.password){
        return 1;
    }
    return 0;
}