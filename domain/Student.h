#ifndef CSCI2421_STUDENT_H
#define CSCI2421_STUDENT_H

#include "utility"
#include "string"

using namespace std;

/**
 * Records a student database record. i.e. the student data.
 * Note that as database record, there are not referenced objects!
 */
class Student {
private:
    string name;
    string id;
    string email;

public:
    Student(string name, string id, string email) : name(move(name)), id(move(id)), email(move(email)) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &aName) {
        Student::name = aName;
    }

    const string &getId() const {
        return id;
    }

    void setId(const string &anId) {
        Student::id = anId;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &anEmail) {
        Student::email = anEmail;
    }

    friend bool operator==(const Student &lhs, const Student &rhs) {
        return lhs.id == rhs.id;
    }
};

#endif