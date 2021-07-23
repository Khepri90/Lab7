#ifndef CSCI2421_COURSE_H
#define CSCI2421_COURSE_H

#include <utility>

#include "utility"
#include "string"

using namespace std;

/**
 * Records a Cours database record. i.e. the course data.
 * Note that as database record, there are not referenced objects!
 */
class Course {
private:
    string courseID;
    string description;
public:
    Course(string courseId, string description) : courseID(move(courseId)), description(move(description)) {}

    const string &getCourseId() const {
        return courseID;
    }

    void setCourseId(const string &courseId) {
        courseID = courseId;
    }

    const string &getDescription() const {
        return description;
    }

    void setDescription(const string &aDescription) {
        Course::description = aDescription;
    }

    friend bool operator==(const Course &lhs, const Course &rhs) {
        return lhs.courseID == rhs.courseID;
    }
};


#endif
