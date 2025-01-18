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
     //������ ����Ʈ ������ �� ���ڿ� ����
    Contact(const string& n = "", const string& phone = "", 
            const string& em = "", const string& addr = "")
         :name(n), phoneNumber(phone), email(em), address(addr) {}

     //����ó ���� ���� �Լ�
    void setName(const string& n) { name = n; }
    void setPhoneNumber(const string& phone) { phoneNumber = phone; }
    void setEmail(const string& em) { email = em; }
    void setAddress(const string& addr) { address = addr; }

    // ����ó ���� ��ȸ �Լ�
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }

     //����ó ���� ��� �Լ�
    void displayContact() const {
    std::cout << "�̸�: " << name << "\n"
        << "��ȭ��ȣ: " << phoneNumber << "\n"
        << "�̸���: " << email << "\n"
        << "�ּ�: " << address << "\n";
}
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
     //�� ����ó �߰�
    void addContact() {
    string name, phone, email, address;

    cin.ignore(); // �Է� ���� �����

    std::cout << "�̸� �Է�: ";
    std::getline(cin, name);

    std::cout << "��ȭ��ȣ �Է�: ";
    std::getline(cin, phone);

    std::cout << "�̸��� �Է�: ";
    std::getline(cin, email);

    std::cout << "�ּ� �Է�: ";
    std::getline(cin, address);

    contacts.emplace_back(name, phone, email, address);
    std::cout << "����ó �߰� �Ϸ�!" << endl;
}

     //����ó �˻�
    void searchContact() {
    if (contacts.empty()) {
        std::cout << "�ּҷ��� ����ֽ��ϴ�." << endl;
        return;
    }

    string searchName;
    std::cout << "�˻��� �̸� �Է�: ";
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
        std::cout << "��ġ�ϴ� ����ó�� ã�� �� �����ϴ�." << std::endl;
    }
}

     // ����ó ����
 void editContact() {
     if (contacts.empty()) {
         std::cout << "�ּҷ��� ����ֽ��ϴ�." << endl;
         return;
     }

     string searchName;
     std::cout << "������ ����ó �̸� �Է�: ";
     cin.ignore();
     getline(cin, searchName);

     for (auto& contact : contacts) {
         if (contact.getName() == searchName) {
             string newPhone, newEmail, newAddress;

             std::cout << "�� ��ȭ��ȣ �Է� (�̺���� Enter): ";
             getline(cin, newPhone);
             if (!newPhone.empty()) contact.setPhoneNumber(newPhone);

             std::cout << "�� �̸��� �Է� (�̺���� Enter): ";
             getline(cin, newEmail);
             if (!newEmail.empty()) contact.setEmail(newEmail);

             std::cout << "�� �ּ� �Է� (�̺���� Enter): ";
             getline(cin, newAddress);
             if (!newAddress.empty()) contact.setAddress(newAddress);

             std::cout << "����ó ���� �Ϸ�!" << endl;
             return;
         }
     }

     std::cout << "��ġ�ϴ� ����ó�� ã�� �� �����ϴ�." << endl;
 }

    // ����ó ����
    void deleteContact() {
    if (contacts.empty()) {
        cout << "�ּҷ��� ����ֽ��ϴ�." << endl;
        return;
    }
    string searchName;
    cout << "������ ����ó�� �̸� �Է�: ";
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
        cout <<searchName<< "����ó ���� �Ϸ�!" << endl;
    } else {
        cout << "��ġ�ϴ� ����ó�� ã�� �� �����ϴ�." << endl;
    }
}
    // ��ü ����ó ���
    void displayAllContacts() {
        if (contacts.empty()) {
            cout << "�ּҷ��� ����ֽ��ϴ�." << endl;
            return;
        }

        cout << "=== ��ü ����ó ===\n";
        for (const auto& contact : contacts) {
            contact.displayContact();
            cout << "------------------------\n";
        }
    }

 // �޴�
 void run() {
     while (true) {
         cout << "\n=== �ּҷ� ���� ���α׷� ===\n"
                   << "1. ����ó �߰�\n"
                   << "2. ����ó �˻�\n"
                   << "3. ����ó ����\n"
                   << "4. ����ó ����\n"
                   << "5. ��ü ����ó ����\n"
                   << "6. ����\n"
                   << "���� > ";

         int choice;
         cin >> choice;

         switch (choice) {
             case 1: addContact(); break;
             case 2: searchContact(); break;
             case 3: editContact(); break;
             case 4: deleteContact(); break;
             case 5: displayAllContacts(); break;
             case 6: 
                 std::cout << "���α׷��� �����մϴ�." << endl;
                 return;
             default: 
                 cout << "�߸� �����ϼ̽��ϴ�." << endl;
         }
     }
 }
};

int main() {
    AddressBook addressBook;
    addressBook.run();
    return 0;
}