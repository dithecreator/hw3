//
//  main.cpp
//  hw3
//
//  Created by Дима on 07.09.23.
//

#include <iostream>
#include <cstring>
using namespace std;

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
    void input(){
        char buffName[50];
        char buffVorname[50];
        char buffHomeNum[50];
        char buffMobileNum[50];
        
        name = new char[strlen(buffName) + 1];
        vorname = new char[strlen(buffVorname) + 1];
        homeNum = new char[strlen(buffHomeNum) + 1];
        mobileNum = new char[strlen(buffMobileNum) + 1];
        
        cout << "enter a name: ";
        cin >> buffName;
        strcpy(name, buffName);
        
        cout << "enter a vorname: ";
        cin >> buffVorname;
        strcpy(vorname, buffVorname);
        
        cout << "enter a home number: ";
        cin >> buffHomeNum;
        strcpy(homeNum, buffHomeNum);
        
        cout << "enter a mobile number: ";
        cin >> buffMobileNum;
        strcpy(mobileNum, buffMobileNum);
        
    }
   char* getVorname(){
        return vorname;
    }
    
    ~Book(){//деструктор
        delete[] name;
        delete[] vorname;
        delete[] homeNum;
        delete[] mobileNum;
    }
    
    
    void print(Book* users, int size){
        for(int i = 0; i < size; i++){
            cout << users[i].name << endl;
            cout << users[i].vorname << endl;
            cout << users[i].homeNum << endl;
            cout << users[i].mobileNum << endl;
        }
    }
    void addUser(Book* users, int size){
        for(int i = 0; i < size; i++){
            users -> input();
        }
    }

    
    void deleteUser(Book* users, int size){
        char buff[100];
        int index = 0;
        cout << "введите фамилию пользователя, которого хотите удалить: ";
        cin >> buff;
        Book* new_users = new Book[size - 1];
        for(int i = 0; i < size; i++){
            if(strcmp(buff, users[i].vorname) == 0){
                index = i;
                break;
        
        }
       
    }
        int k = 0;
        for(int i = 0; i < size - 1; i++){
            if(index != i){
                new_users[i] = users[k];
                k++;
            }
        }
    }
    
   
  
};



//void deleteUser(Book* users, int size){
//    char buff[100];
//    int index = 0;
//    cout << "введите фамилию пользователя, которого хотите удалить: ";
//    cin >> buff;
//    Book* new_users = new Book[size - 1];
//    for(int i = 0; i < size; i++){
//   char* buffVorname = users[i].getVorname();
//        if(strcmp(buff, buffVorname) == 0){
//            index = i;
//            break;
//
//    }
//
//}
//    for(int i = 0; i < size - 1; i++){
//
//    }
//}

int main() {
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
//    deleteUser(users, size);
    users -> deleteUser(users, size);
    users -> print(users, size - 1);
    delete[] users;
}
