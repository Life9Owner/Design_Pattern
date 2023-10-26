#include<iostream>
using namespace std;
class LibraryVisitor;
class LibraryItemInterface{
    public:
    // (1);
    virtual void accept(LibraryVisitor* visitor)=0;
};
class Article: public LibraryItemInterface{
    private:
        string m_title;//Paper title
        string m_author;
        int m_start_page;
        int m_end_page;
    public:
        Article(string p_author, string p_title, int p_start_page,int p_end_page );
        int getNumberOfPages();
        void accept(LibraryVisitor* visitor);

};
class Book:public LibraryItemInterface{
    private:
        string m_title;//book name;
        string m_author; //author
        int m_pages; //page number
    public:
        Book(string p_author,string p_title,int p_pages);
        int getNumberOfPages();
        void accept(LibraryVisitor* visitor);

};
class LibraryVisitor{
    public: 
        // (2);
        virtual void visit(Book* p_book)=0;
        // (3);
        virtual void visit(Article* p_article)=0;
        virtual void printSum()=0;
};
class LibrarySumPrintVisitor:public LibraryVisitor//print total pages
{
    private:
        int sum;
    public:
        LibrarySumPrintVisitor();
        void visit(Book* p_book);
        void visit(Article* p_article);
        void printSum();
};
//visitor.cpp
int Article::getNumberOfPages(){
    return m_end_page-m_start_page;
}
void Article::accept(LibraryVisitor* visitor)
{
    // (4);
    visitor->visit(this);
}
Book::Book(string p_author,string p_title,int p_pages)
{
    m_title=p_title;
    m_author=p_author;
    m_pages=p_pages;
}
int Book::getNumberOfPages(){
    return m_pages;
}
void Book::accept(LibraryVisitor* visitor)
{
    // (5);
    visitor->visit(this);
    
}