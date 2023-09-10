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
   char* getVorname(){
        return vorname;
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
    
    void search(Book* users, int size){
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
    
    void save(FILE* file, Book* users, int size){
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
    
    void read(FILE* file, Book* users, int size){
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

    
    
    
    void deleteUser(Book* users, int size){
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
        for(int i = 0; i < newSize; i++){
            newUsers[k].name = users[i].name;
            newUsers[k].vorname = users[i].vorname;
            newUsers[k].homeNum = users[i].homeNum;
            newUsers[k].mobileNum = users[i].mobileNum;
            k++;
        }
    }

 
    ~Book(){//деструктор
        delete[] name;
        delete[] vorname;
        delete[] homeNum;
        delete[] mobileNum;
    }
    
};





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
