#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[30];
    char author[30];
    int publication_year;
    float price;
} library;

void display(library books[], int size);
void book_search(library books[], int size);
void author_search(library books[], int size);

int main()
{
    int option;
    library books[5] = {
        {"Life Of Pi", "Yann Martel", 2001, 49.99},
        {"The Kite Runner", "Khaled Hosseini", 2003, 59.99},
        {"A Tale Of Two Cities", "Yann Martel", 1859, 69.99},
        {"The Alchemist", "Paulo Coehlo", 1988, 79.99},
        {"Diary Of A Wimpy Kid", "Jeff Kinney", 2010, 39.99}};

    while (1)
    {
        printf("\nMenu:-\n1: Display all books\n2: Search for a book by title\n3: List book by a specific author\n4: Exit\n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            display(books, 5);
            break;
        case 2:
            book_search(books, 5);
            break;
        case 3:
            author_search(books, 5);
            break;
        case 4:
            printf("Exiting the program...");
            return 0;
        default:
            printf("Invalid input. Please enter again.");
        }
    }
    return 0;
}

void display(library books[], int size)
{
    printf("\nAvailable Books\n");
    for (int i = 0; i < size; i++)
    {
        printf("Book number %d\n", i + 1);
        printf("Title: %s\t", books[i].title);
        printf("Author: %s\t", books[i].author);
        printf("Publication Year: %d\t", books[i].publication_year);
        printf("Price: %.2f\t", books[i].price);
        printf("\n");
    }
}

void book_search(library books[], int size)
{
    char input[50];
    printf("Enter the title of the book to be searched: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    int i, flag = 0;
    for (i = 0; i < size; i++)
    {
        if (strcmp(books[i].title, input) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Book searched is available.\n");
        printf("Title: %s\t", books[i].title);
        printf("Author: %s\t", books[i].author);
        printf("Publication Year: %d\t", books[i].publication_year);
        printf("Price: %.2f\t", books[i].price);
        printf("\n");
    }
    else
    {
        printf("Book searched is not available.\n");
    }
}

void author_search(library books[], int size)
{
    char input[50];
    printf("Enter the author: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    int i, flag = 0;
    for (i = 0; i < size; i++)
    {
        if (strcmp(books[i].author, input) == 0)
        {
            flag = 1;
            printf("Book Title: %s\n", books[i].title);
        }
    }

    if (flag == 0)
    {
        printf("No book available by the author %s.", input);
    }
}
