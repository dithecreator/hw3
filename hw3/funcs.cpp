//
//  funcs.cpp
//  hw3
//
//  Created by Дима on 10.09.23.
//
#include <iostream>
#include <cstring>
#include "funcs.hpp"
using namespace std;





void Book:: input(){
        char buffName[50];
        char buffVorname[50];
        char buffHomeNum[50];
        char buffMobileNum[50];
        
     

        
        
        cout << "enter a name: ";
        cin >> buffName;
        name = new char[strlen(buffName) + 1];
        strcpy(name, buffName);
        
        cout << "enter a vorname: ";
        cin >> buffVorname;
        vorname = new char[strlen(buffVorname) + 1];
        strcpy(vorname, buffVorname);
        
        cout << "enter a home number: ";
        cin >> buffHomeNum;
        homeNum = new char[strlen(buffHomeNum) + 1];
        strcpy(homeNum, buffHomeNum);
        
        cout << "enter a mobile number: ";
        cin >> buffMobileNum;
        mobileNum = new char[strlen(buffMobileNum) + 1];
        strcpy(mobileNum, buffMobileNum);
        
    }
char* Book:: getVorname(){
        return vorname;
    }
    
   
    
void Book:: print(Book* users, int size){
        for(int i = 0; i < size; i++){
            cout << users[i].name << endl;
            cout << users[i].vorname << endl;
            cout << users[i].homeNum << endl;
            cout << users[i].mobileNum << endl;
        }
    }
void Book:: addUser(Book* users, int size){
        for(int i = 0; i < size; i++){
            users[i].input();
        }
    }
    
void Book:: search(Book* users, int size){
        char buffer[100];
        cout << "введите фамилию для поиска: ";
        cin >> buffer;
        int index = 0;
        for(int i = 0; i < size; i++){
            if(strcmp(buffer, users[i].vorname) == 0){
                index = i;
                break;
            }
        }
        
            cout << users[index].name << endl;
            cout << users[index].vorname << endl;
            cout << users[index].homeNum << endl;
            cout << users[index].mobileNum << endl;
        
    }
    
void Book:: save(FILE* file, Book* users, int size){
        file = fopen("txt", "w");
        if(file == 0){
            cout << "error" << endl;
        }
        else{
            for (int i = 0; i < size; i++) {
                fputs(users[i].name, file);
                fputs(users[i].vorname, file);
                fputs(users[i].homeNum, file);
                fputs(users[i].mobileNum, file);
            }
            cout << "данные записаны успешно!" << endl;
            fclose(file);
        }
    }
    
void Book:: read(FILE* file, Book* users, int size){
        file = fopen("txt", "r");
        if(file == 0){
            cout << "error" << endl;
        }
        else{
            char buffer[100];
            while (!feof(file)) {
                fgets(buffer, 100, file);
            }
            fclose(file);
            cout << buffer << endl;

            
        }
        
    }

    

Book* Book:: deleteUser(Book* users, int size){
         char buffer[100];
         cout << "введите фамилию, которую хотите удалить: ";
         cin >> buffer;
         int index;
         for(int i = 0; i < size; i++){
             if(strcmp(users[i].vorname, buffer) == 0){
                 index = i;
                 break;
             }
     }
         int newSize = size - 1;
         Book* newUsers = new Book[newSize];
         int k = 0;
         for(int i = 0; i < size; i++){
             if(index != i){
//                 newUsers[k] = users[i];
                 newUsers[k].name = new char[strlen(users[i].name) + 1];
                 strcpy(newUsers[k].name, users[i].name);
                 
                 newUsers[k].vorname = new char[strlen(users[i].vorname) + 1];
                 strcpy(newUsers[k].vorname, users[i].vorname);
                 
                 newUsers[k].homeNum = new char[strlen(users[i].homeNum) + 1];
                 strcpy(newUsers[k].homeNum, users[i].homeNum);
                 
                 newUsers[k].mobileNum = new char[strlen(users[i].mobileNum) + 1];
                 strcpy(newUsers[k].mobileNum, users[i].mobileNum);
                k++;
             }
         }

         for(int i = 0; i < newSize; i++){
         cout << newUsers[i].name << endl;
         cout << newUsers[i].vorname << endl;
         cout << newUsers[i].homeNum << endl;
         cout << newUsers[i].mobileNum << endl;
         }
         delete[] users;
    return newUsers;

     }

 
Book::~Book(){//деструктор
//        delete[] name;
//        delete[] vorname;
//        delete[] homeNum;
//        delete[] mobileNum;
    }
    





