#include <iostream>
using namespace std;

#define NAME_SIZE (50)

class Person {
    int id;
    char name[NAME_SIZE];

  public:
    Person() { cout << "Person() called"<<endl; this->id = -1; strcpy(this->name,"John Doe");}
    Person(int id,char name[NAME_SIZE]) { this->id = id; strcpy(this->name,name);}
    virtual void aboutMe() {cout << "I am a person with ID " << this->id << " and name "<<this->name<< endl;}
    char * getName() { return name; }
    int getId() { return id; }
    void setName(char name[NAME_SIZE]) { strcpy(this->name,name);}
    virtual ~Person() { cout << "Deleting a person" << endl;}
};

class Student : public Person {
  public:
    Student(int id,char name[NAME_SIZE]) { cout<<"Student(id,name) called"<<endl;this->setName(name);}
    void aboutMe() {cout << "I am a student named " <<this->getName() << " with ID "<<this->getId() << endl;}
    ~Student() { cout << "Deleting a student" << endl;}
};

int main(){
   Person *p = new Student(3,"Chris");
   p->aboutMe();
   delete p;
   return 0;
  
}
