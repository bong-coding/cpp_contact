#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
private:
    string name;
    string phoneNumber;
    string email;
    string address;

public:
     //생성자 디폴트 값으로 빈 문자열 생성
    Contact(const string& n = "", const string& phone = "", 
            const string& em = "", const string& addr = "")
         :name(n), phoneNumber(phone), email(em), address(addr) {}

     //연락처 정보 변경 함수
    void setName(const string& n) { name = n; }
    void setPhoneNumber(const string& phone) { phoneNumber = phone; }
    void setEmail(const string& em) { email = em; }
    void setAddress(const string& addr) { address = addr; }

    // 연락처 정보 조회 함수
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }

     //연락처 정보 출력 함수
    void displayContact() const {
    std::cout << "이름: " << name << "\n"
        << "전화번호: " << phoneNumber << "\n"
        << "이메일: " << email << "\n"
        << "주소: " << address << "\n";
}
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
     //새 연락처 추가
    void addContact() {
    string name, phone, email, address;

    cin.ignore(); // 입력 버퍼 지우기

    std::cout << "이름 입력: ";
    std::getline(cin, name);

    std::cout << "전화번호 입력: ";
    std::getline(cin, phone);

    std::cout << "이메일 입력: ";
    std::getline(cin, email);

    std::cout << "주소 입력: ";
    std::getline(cin, address);

    contacts.emplace_back(name, phone, email, address);
    std::cout << "연락처 추가 완료!" << endl;
}

     //연락처 검색
    void searchContact() {
    if (contacts.empty()) {
        std::cout << "주소록이 비어있습니다." << endl;
        return;
    }

    string searchName;
    std::cout << "검색할 이름 입력: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& contact : contacts) {
        if (contact.getName().find(searchName) != string::npos) {
            contact.displayContact();
            std::cout << "------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "일치하는 연락처를 찾을 수 없습니다." << std::endl;
    }
}

     // 연락처 수정
 void editContact() {
     if (contacts.empty()) {
         std::cout << "주소록이 비어있습니다." << endl;
         return;
     }

     string searchName;
     std::cout << "수정할 연락처 이름 입력: ";
     cin.ignore();
     getline(cin, searchName);

     for (auto& contact : contacts) {
         if (contact.getName() == searchName) {
             string newPhone, newEmail, newAddress;

             std::cout << "새 전화번호 입력 (미변경시 Enter): ";
             getline(cin, newPhone);
             if (!newPhone.empty()) contact.setPhoneNumber(newPhone);

             std::cout << "새 이메일 입력 (미변경시 Enter): ";
             getline(cin, newEmail);
             if (!newEmail.empty()) contact.setEmail(newEmail);

             std::cout << "새 주소 입력 (미변경시 Enter): ";
             getline(cin, newAddress);
             if (!newAddress.empty()) contact.setAddress(newAddress);

             std::cout << "연락처 수정 완료!" << endl;
             return;
         }
     }

     std::cout << "일치하는 연락처를 찾을 수 없습니다." << endl;
 }

    // 연락처 삭제
    void deleteContact() {
    if (contacts.empty()) {
        cout << "주소록이 비어있습니다." << endl;
        return;
    }
    string searchName;
    cout << "삭제할 연락처의 이름 입력: ";
    cin.ignore(); 
    getline(cin, searchName);

    bool found = false;
    for (auto it = contacts.begin(); it != contacts.end(); ) {
        if (it->getName() == searchName) {
            it = contacts.erase(it); 
            found = true;
        } else {
            ++it; 
        }
    }
    if (found) {
        cout <<searchName<< "연락처 삭제 완료!" << endl;
    } else {
        cout << "일치하는 연락처를 찾을 수 없습니다." << endl;
    }
}
    // 전체 연락처 출력
    void displayAllContacts() {
        if (contacts.empty()) {
            cout << "주소록이 비어있습니다." << endl;
            return;
        }

        cout << "=== 전체 연락처 ===\n";
        for (const auto& contact : contacts) {
            contact.displayContact();
            cout << "------------------------\n";
        }
    }

 // 메뉴
 void run() {
     while (true) {
         cout << "\n=== 주소록 관리 프로그램 ===\n"
                   << "1. 연락처 추가\n"
                   << "2. 연락처 검색\n"
                   << "3. 연락처 수정\n"
                   << "4. 연락처 삭제\n"
                   << "5. 전체 연락처 보기\n"
                   << "6. 종료\n"
                   << "선택 > ";

         int choice;
         cin >> choice;

         switch (choice) {
             case 1: addContact(); break;
             case 2: searchContact(); break;
             case 3: editContact(); break;
             case 4: deleteContact(); break;
             case 5: displayAllContacts(); break;
             case 6: 
                 std::cout << "프로그램을 종료합니다." << endl;
                 return;
             default: 
                 cout << "잘못 선택하셨습니다." << endl;
         }
     }
 }
};

int main() {
    AddressBook addressBook;
    addressBook.run();
    return 0;
}