# 연락처 관리 프로그램
c++을 배우고 난 후 미니 프로젝트를 진행해보고 싶어 만들게 되었음
## 개요
이 프로그램은 **연락처를 저장**하고 **관리**할 수 있는 콘솔 기반 주소록
두 개의 클래스로 구성되어 있으며, 각각 다음의 역할을 함:

1. **Contact 클래스**  
   - 연락처 정보(이름, 전화번호, 이메일, 주소)를 저장  
   - set/get 함수 및 display 함수 제공  

2. **AddressBook 클래스**  
   - 여러 개의 **Contact** 객체를 `vector`로 관리  
   - **추가, 검색, 수정, 삭제, 조회** 기능 제공

---

## Contact 클래스

- **멤버 변수**
  - `name` : 이름  
  - `phoneNumber` : 전화번호  
  - `email` : 이메일  
  - `address` : 주소  

- **생성자**  
  - 기본값을 모두 빈 문자열("")로 두어 객체 생성 시 초기화  

- **set 함수**  
  - `setName()`, `setPhoneNumber()`, `setEmail()`, `setAddress()`  
  - 객체 생성 후 값을 **업데이트**할 때 사용  

- **get 함수**  
  - `getName()`, `getPhoneNumber()`, `getEmail()`, `getAddress()`  
  - 저장된 값을 **읽어오기** 위해 사용  

- **display 함수**  
  - 해당 **Contact** 객체에 저장되어 있는 정보를 **출력**하는 함수  

---

## AddressBook 클래스

- **멤버 변수**
  - `vector<Contact> contacts` : 여러 연락처를 동적으로 관리하기 위해 사용

- **멤버 함수**

  1. **`addContact()`**  
     - 새 연락처를 추가  
     - `cin.ignore()`로 입력 버퍼 정리 후 `getline()`으로 각 항목 입력  
     - `emplace_back()`로 `contacts` 벡터에 새 `Contact` 객체 삽입  

  2. **`searchContact()`**  
     - 입력한 이름(검색어)이 포함된 연락처를 찾아 **displayContact()**로 출력  
     - `contacts.empty()`로 비어있는지 확인  
     - `string::find()`로 이름 검색 (`string::npos` 판별)  

  3. **`editContact()`**  
     - 수정할 **이름**으로 연락처를 찾은 뒤, `set` 함수를 통해 정보 변경  
     - `contacts.empty()`면 수정 불가 메시지 표시  

  4. **`deleteContact()`**  
     - 삭제할 **이름**을 입력받아, 일치하는 연락처를 `vector`에서 `erase()`로 제거  

  5. **`displayAllContacts()`**  
     - 전체 연락처 정보를 순회하며 **display**  

- **전체 실행 흐름**  
  - 메뉴를 통해 **추가**, **검색**, **수정**, **삭제**, **전체 보기**, **종료** 등을 선택  
  - `cin >> choice`로 메뉴 입력 후 `switch`문으로 각 기능 실행  

---

## 주요 함수 및 사용 라이브러리

- **`cin.ignore()`**  
  - `cin`과 `getline()` 혼용 시, 입력 버퍼에 남은 개행 문자 제거  
- **`getline(cin, 변수)`**  
  - 한 줄 전체를 문자열로 입력받을 때 사용  
- **`emplace_back()`**  
  - `vector`의 끝에 새 요소를 직접 생성하여 추가  
- **`find()`**  
  - 문자열에서 검색어를 찾아 인덱스 반환, 찾지 못하면 `string::npos`  
- **`erase()`**  
  - `vector`에서 지정된 위치의 요소 제거  

---

## 정리

- **Contact**  
  - 연락처 정보 저장/관리  
- **AddressBook**  
  - 여러 `Contact` 객체를 `vector`로 동적 관리하며,  
    - **추가**  
    - **검색**  
    - **수정**  
    - **삭제**  
    - **전체 조회**  
    등 기능을 제공  

- **필수 포인트**  
  - `cin.ignore()`와 `getline()` 조합  
  - `find()` + `string::npos`로 검색  
  - `erase()`로 연락처 삭제  

**메인 함수**에서 `AddressBook` 객체를 생성, `run()` 호출로 프로그램을 실행  
