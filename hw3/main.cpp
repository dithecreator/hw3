//
//  main.cpp
//  hw3
//
//  Created by Дима on 07.09.23.
//

#include <iostream>
#include <cstring>
#include "funcs.hpp"
using namespace std;

int main() {
    FILE* file;
    int size = 1;
    Book* users = new Book[size];
    int answer;
    cout << "хотите добавить пользователя?" << endl;
    cout << "1 - да" << endl;
    cout << "0 - нет" << endl;
    cin >> answer;
    if(answer == 1){
        cout << "введите число пользователей, которое вы хотите добавить: ";
        cin >> size;
        users -> addUser(users, size);
    }
    int answer1;
    cout << "выберите действие: ";
    cout << "1 - осуществить поиск по фамилии" << endl;
    cout << "2 - удалить пользователя" << endl;
    cout << "3 - сохранить данные в файл" << endl;
    cout << "4 - считать данные из файла" << endl;
    cin >> answer1;
    
    switch(answer1){
        case 1:
            users -> search(users, size);
            break;
            
        case 2:
                users -> deleteUser(users, size);
            break;
            
        case 3:
            users -> save(file, users, size);
            break;
            
        case 4:
            users -> read(file, users, size);
            break;
    }

    delete[] users;

}
