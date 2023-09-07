//
//  main.cpp
//  hw3
//
//  Created by Дима on 07.09.23.
//

#include <iostream>
using namespace std;

class Book{
private:
    char* name;
    char* vorname;
    char* homeNum;
    char* mobileNum;
    
public:
    Book(){
        name = nullptr;
        vorname = nullptr;
        homeNum = nullptr;
        mobileNum = nullptr;
    }
};
void input(){
    char buffName[50];
    char buffVorname[50];
    char buffHomeNum[50];
    char buffMobileNum[50];
    cout << "enter a name: ";
    cin >> buffName;
    
    cout << "enter a vorname: ";
    cin >> buffVorname;
    
    
    cout << "enter a home number: ";
    cin >> buffHomeNum;
    
    cout << "enter a mobile number: ";
    cin >> buffMobileNum;
    
    
}

int main() {

}
