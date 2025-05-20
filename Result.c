#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lambdalib.h"


typedef struct Address {
char* street;
int number;
char* city;

void (*setAddress)(struct Address *self, char* s, int n, char* c);
void (*printAddress)(struct Address *self);
} Address;



void setAddress(struct Address *self, char* s, int n, char* c) {

self->street = s;
self->number = n;
self->city = c;


}

void printAddress(struct Address *self) {

write("Address: %s %d, %s\n", self->street, self->number, self->city);


}
// Initialize struct with function pointers
const Address ctor_Address = {
    .setAddress = setAddress ,
    .printAddress = printAddress 
};

typedef struct Person {
char* firstName, lastName;
char* email;
int phone;
Address address;

void (*setPerson)(struct Person *self, char* fn, char* ln, char* email, int phone, Address addr);
void (*printPersonInfo)(struct Person *self);
} Person;



void setPerson(struct Person *self, char* fn, char* ln, char* email, int phone, Address addr) {

self->firstName = fn;
self->lastName = ln;
self->email = email;
self->phone = phone;
self->address = addr;


}

void printPersonInfo(struct Person *self) {

write("%s %s, email: %s phone: %d\n", self->firstName, self->lastName, self->email, self->phone);
self->address.printAddress(&self->address);


}
// Initialize struct with function pointers
const Person ctor_Person = {
    .setPerson = setPerson ,
    .printPersonInfo = printPersonInfo 
};

typedef struct Book {
char* title, isbn;
Person author;
int numOfCopies;
double price;

void (*setBook)(struct Book *self, char* t, Person a, int numOfCopies, double price);
void (*printBook)(struct Book *self);
} Book;



void setBook(struct Book *self, char* t, Person a, int numOfCopies, double price) {

self->title = t;
self->author = a;
self->numOfCopies = numOfCopies;
self->price = price;


}

void printBook(struct Book *self) {

write("Title: %s\n", self->title);
writeStr("Author:");
self->author.printPersonInfo(&self->author);
write("Price:%f\n", self->price);
write("Number of available copies: %d\n", self->numOfCopies);


}
// Initialize struct with function pointers
const Book ctor_Book = {
    .setBook = setBook ,
    .printBook = printBook 
};

typedef struct Order {
int orderNum;
Book book;
int quantity;
Address shippingAddress;
int delivered;

void (*setOrder)(struct Order *self, int orNum, Book b, int q, Address sh, int del);
void (*printOrder)(struct Order *self);
} Order;



void setOrder(struct Order *self, int orNum, Book b, int q, Address sh, int del) {

self->orderNum = orNum;
self->book = b;
self->quantity = q;
self->shippingAddress = sh;
self->delivered = del;


}

void printOrder(struct Order *self) {

write("Order Num: %d\n", self->orderNum);


}
// Initialize struct with function pointers
const Order ctor_Order = {
    .setOrder = setOrder ,
    .printOrder = printOrder 
};

typedef struct Bookstore {
char* name;
Book listOfBooks[100];
int numOfBooks;
Order listOfOrders[100];
int numOfOrders;

void (*putOrder)(struct Bookstore *self, Order o);
void (*addBook)(struct Bookstore *self, Book b);
void (*printBookStoreBooks)(struct Bookstore *self);
double (*calculateTotalOrdersIncome)(struct Bookstore *self);
} Bookstore;



void putOrder(struct Bookstore *self, Order o) {

self->listOfOrders[self->numOfOrders] = o;
self->numOfOrders += 1;


}

void addBook(struct Bookstore *self, Book b) {

self->listOfBooks[self->numOfBooks] = b;
self->numOfBooks += 1;


}

void printBookStoreBooks(struct Bookstore *self) {

for(int i = 0; i < self->numOfBooks; i++) {
self->listOfBooks[i].printBook(&self->listOfBooks[i]);
}


}

double calculateTotalOrdersIncome(struct Bookstore *self) {

double total;
total = 0;
for(int i = 0; i < self->numOfOrders; i++) {
if(self->listOfOrders[i].delivered) {
total = total + self->listOfOrders[i].quantity * self->listOfOrders[i].book.price;

}
}

return total;
}
// Initialize struct with function pointers
const Bookstore ctor_Bookstore = {
    .putOrder = putOrder ,
    .addBook = addBook ,
    .printBookStoreBooks = printBookStoreBooks ,
    .calculateTotalOrdersIncome = calculateTotalOrdersIncome 
};



int orderId;


Address createAddress(char* s, int n, char* c) {

Address a = ctor_Address;
a.setAddress(&a, s, n, c);

return a;
}

Person createPerson(char* fn, char* ln, char* email, int phone, Address addr) {

Person p = ctor_Person;
p.setPerson(&p, fn, ln, email, phone, addr);

return p;
}

Book createBook(char* t, Person a, int numOfCopies, double price) {

Book b = ctor_Book;
b.setBook(&b, t, a, numOfCopies, price);

return b;
}

Order createOrder(int orNum, Book b, int q, Address sh, int del) {

Order ord = ctor_Order;
ord.setOrder(&ord, orNum, b, q, sh, del);

return ord;
}

Bookstore createBookstore(char* n) {

Bookstore bs = ctor_Bookstore;
bs.name = n;
bs.numOfBooks = 0;
bs.numOfOrders = 0;

return bs;
}
int main() {

orderId = 0;
Order ord = ctor_Order;
Address a, a1 = ctor_Address;
a = createAddress("Stadiou", 10, "Stadiou");
Person author = ctor_Person;
author = createPerson("Christos", "Papadimitriou", "cpap@gmail.com", 12345, a);
Book b = ctor_Book;
b = createBook("Computation Theory", author, 34.299999, 100);
Bookstore bs = ctor_Bookstore;
bs = createBookstore("Papasotiriou");
bs.addBook(&bs, b);
a = createAddress("Wall Street", 10, "NY");
author = createPerson("Dennis", "Richie", "richie@gmail.com", 54321, a);
b = createBook("C Programming", author, 10.300000, 100);
bs.addBook(&bs, b);
bs.printBookStoreBooks(&bs);
ord = createOrder(orderId, b, 2, a, 0);
orderId += 1;
bs.putOrder(&bs, ord);
write("Bookstore orders income: %.2f\n", bs.calculateTotalOrdersIncome(&bs));

    return 0;
}
