//
//  funcs.hpp
//  hw3
//
//  Created by Дима on 10.09.23.
//

#ifndef funcs_hpp
#define funcs_hpp
#include <stdio.h>



class Book{
private:
    char* name;
    char* vorname;
    char* homeNum;
    char* mobileNum;
    
public:
    Book(){ //конструктор
        name = nullptr;
        vorname = nullptr;
        homeNum = nullptr;
        mobileNum = nullptr;
    }
    void  input();
    char*  getVorname();
    void  print(Book* users, int size);
    void  addUser(Book* users, int size);
    void  search(Book* users, int size);
    void save(FILE* file, Book* users, int size);
    void  read(FILE* file, Book* users, int size);
    void deleteUser(Book* users, int size);
    ~Book();
                                
};



#endif /* funcs_hpp */
