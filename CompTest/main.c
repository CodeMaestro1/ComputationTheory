#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lambdalib.h"

typedef struct
{
    char* street;
    int number;
    char* city;

    void (*setAddress)(struct Address *self, char* s, int n, char* c);
    void Address setAddress(struct Address *self, char* s, int n, char* c)
    {

        self->street = s;
        self->number = n;
        self->city = c;


    }
    void (*printAddress)(struct Address *self);
    void Address printAddress(struct Address *self)
    {

        write("Address: %s %d, %s\n", self->street, self->number, self->city);


    }
} Address;

void (*setAddress)(struct Address *self, char* s, int n, char* c);
void Address setAddress(struct Address *self, char* s, int n, char* c)
{

    self->street = s;
    self->number = n;
    self->city = c;


}
void (*printAddress)(struct Address *self);
void Address printAddress(struct Address *self)
{

    write("Address: %s %d, %s\n", self->street, self->number, self->city);


}
typedef struct
{
    char* firstName, lastName;
    char* email;
    int phone;
    Address address;

    void (*setPerson)(struct Person *self, char* fn, char* ln, char* email, int phone, Address addr);
    void Person setPerson(struct Person *self, char* fn, char* ln, char* email, int phone, Address addr)
    {

        self->firstName = fn;
        self->lastName = ln;
        self->email = email;
        self->phone = phone;
        self->address = addr;


    }
    void (*printPersonInfo)(struct Person *self);
    void Person printPersonInfo(struct Person *self)
    {

        write("%s %s, email: %s phone: %d\n", self->firstName, self->lastName, self->email, self->phone);
        self->address.printAddress();


    }
} Person;

void (*setPerson)(struct Person *self, char* fn, char* ln, char* email, int phone, Address addr);
void Person setPerson(struct Person *self, char* fn, char* ln, char* email, int phone, Address addr)
{

    self->firstName = fn;
    self->lastName = ln;
    self->email = email;
    self->phone = phone;
    self->address = addr;


}
void (*printPersonInfo)(struct Person *self);
void Person printPersonInfo(struct Person *self)
{

    write("%s %s, email: %s phone: %d\n", self->firstName, self->lastName, self->email, self->phone);
    self->address.printAddress();


}
typedef struct
{
    char* title, isbn;
    Person author;
    int numOfCopies;
    double price;

    void (*setBook)(struct Book *self, char* t, Person a, int numOfCopies, double price);
    void Book setBook(struct Book *self, char* t, Person a, int numOfCopies, double price)
    {

        self->title = t;
        self->author = a;
        self->numOfCopies = numOfCopies;
        self->price = price;


    }
    void (*printBook)(struct Book *self);
    void Book printBook(struct Book *self)
    {

        write("Title: %s\n", self->title);
        writeStr("Author:");
        self->author.printPersonInfo();
        write("Price:%f\n", self->price);
        write("Number of available copies: %d\n", self->numOfCopies);


    }
} Book;

void (*setBook)(struct Book *self, char* t, Person a, int numOfCopies, double price);
void Book setBook(struct Book *self, char* t, Person a, int numOfCopies, double price)
{

    self->title = t;
    self->author = a;
    self->numOfCopies = numOfCopies;
    self->price = price;


}
void (*printBook)(struct Book *self);
void Book printBook(struct Book *self)
{

    write("Title: %s\n", self->title);
    writeStr("Author:");
    self->author.printPersonInfo();
    write("Price:%f\n", self->price);
    write("Number of available copies: %d\n", self->numOfCopies);


}
typedef struct
{
    int orderNum;
    Book book;
    int quantity;
    Address shippingAddress;
    int delivered;

    void (*setOrder)(struct Order *self, int orNum, Book b, int q, Address sh, int del);
    void Order setOrder(struct Order *self, int orNum, Book b, int q, Address sh, int del)
    {

        self->orderNum = orNum;
        self->book = b;
        self->quantity = q;
        self->shippingAddress = sh;
        self->delivered = del;


    }
    void (*printOrder)(struct Order *self);
    void Order printOrder(struct Order *self)
    {

        write("Order Num: %d\n", self->orderNum);


    }
} Order;

void (*setOrder)(struct Order *self, int orNum, Book b, int q, Address sh, int del);
void Order setOrder(struct Order *self, int orNum, Book b, int q, Address sh, int del)
{

    self->orderNum = orNum;
    self->book = b;
    self->quantity = q;
    self->shippingAddress = sh;
    self->delivered = del;


}
void (*printOrder)(struct Order *self);
void Order printOrder(struct Order *self)
{

    write("Order Num: %d\n", self->orderNum);


}
typedef struct
{
    char* name;
    Book self->listOfBooks[100];
    int numOfBooks;
    Order self->listOfOrders[100];
    int numOfOrders;

    void (*putOrder)(struct Bookstore *self, Order o);
    void Bookstore putOrder(struct Bookstore *self, Order o)
    {

        self->listOfOrders[self->numOfOrders] = o;
        self->numOfOrders += 1;


    }
    void (*addBook)(struct Bookstore *self, Book b);
    void Bookstore addBook(struct Bookstore *self, Book b)
    {

        self->listOfBooks[self->numOfBooks] = b;
        self->numOfBooks += 1;


    }
    void (*printBookStoreBooks)(struct Bookstore *self);
    void Bookstore printBookStoreBooks(struct Bookstore *self)
    {

        for(int i = 0; i < self->numOfBooks; i++)
        {
            self->listOfBooks[i].printBook();
        }


    }
    double (*calculateTotalOrdersIncome)(struct Bookstore *self);
    double Bookstore calculateTotalOrdersIncome(struct Bookstore *self)
    {

        double total;
        total = 0;
        for(int i = 0; i < self->numOfOrders; i++)
        {
            if(self->listOfOrders[i].self->delivered)
            {
                total = total + self->listOfOrders[i].self->quantity * self->listOfOrders[i].self->book.self->price;

            }
        }

        return total;
    }
} Bookstore;

void (*putOrder)(struct Bookstore *self, Order o);
void Bookstore putOrder(struct Bookstore *self, Order o)
{

    self->listOfOrders[self->numOfOrders] = o;
    self->numOfOrders += 1;


}
void (*addBook)(struct Bookstore *self, Book b);
void Bookstore addBook(struct Bookstore *self, Book b)
{

    self->listOfBooks[self->numOfBooks] = b;
    self->numOfBooks += 1;


}
void (*printBookStoreBooks)(struct Bookstore *self);
void Bookstore printBookStoreBooks(struct Bookstore *self)
{

    for(int i = 0; i < self->numOfBooks; i++)
    {
        self->listOfBooks[i].printBook();
    }


}
double (*calculateTotalOrdersIncome)(struct Bookstore *self);
double Bookstore calculateTotalOrdersIncome(struct Bookstore *self)
{

    double total;
    total = 0;
    for(int i = 0; i < self->numOfOrders; i++)
    {
        if(self->listOfOrders[i].self->delivered)
        {
            total = total + self->listOfOrders[i].self->quantity * self->listOfOrders[i].self->book.self->price;

        }
    }

    return total;
}


int orderId;


Address createAddress(char* s, int n, char* c)
{

    Address a;
    a.setAddress(s, n, c);

}

Person createPerson(char* fn, char* ln, char* email, int phone, Address addr)
{

    Person p;
    p.setPerson(fn, ln, email, phone, addr);

}

Book createBook(char* t, Person a, int numOfCopies, double price)
{

    Book b;
    b.setBook(t, a, numOfCopies, price);

}

Order createOrder(int orNum, Book b, int q, Address sh, int del)
{

    Order ord;
    ord.setOrder(orNum, b, q, sh, del);

}

Bookstore createBookstore(char* n)
{

    Bookstore bs;
    bs.self->name = n;
    bs.self->numOfBooks = 0;
    bs.self->numOfOrders = 0;

}
int main()
{

    orderId = 0;
    Order ord;
    Address a, a1;
    a = createAddress("Stadiou", 10, "Stadiou");
    Person author;
    author = createPerson("Christos", "Papadimitriou", "cpap@gmail.com", 12345, a);
    Book b;
    b = createBook("Computation Theory", author, 34.299999, 100);
    Bookstore bs;
    bs = createBookstore("Papasotiriou");
    bs.addBook(b);
    a = createAddress("Wall Street", 10, "NY");
    author = createPerson("Dennis", "Richie", "richie@gmail.com", 54321, a);
    b = createBook("C Programming", author, 10.300000, 100);
    bs.addBook(b);
    bs.printBookStoreBooks();
    ord = createOrder(orderId, b, 2, a, 0);
    orderId += 1;
    bs.putOrder(ord);
    write("Bookstore orders income: %.2f\n", bs.calculateTotalOrdersIncome());

    return 0;
}
