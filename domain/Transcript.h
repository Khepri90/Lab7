#ifndef CSCI2421_TRANSCRIPT_H
#define CSCI2421_TRANSCRIPT_H

#include <utility>

#include "utility"
#include "string"

using namespace std;

/**
 * Records a transcript database record. i.e. the grade obtained by a student in a course.
 * Note that as database record, there are not referenced objects!
 */
class Transcript {
private:
    static int idCounter;
    int transcriptID;
    string studentID;
    string courseID;
    string grade;
public:
    Transcript(string studentId, string courseId, string grade) : studentID(std::move(studentId)),
                                                                  courseID(std::move(courseId)),
                                                                  grade(std::move(grade)) {
        this->transcriptID = ++Transcript::idCounter;
    }

    int getTranscriptId() const {
        return transcriptID;
    }

    const string &getStudentId() const {
        return studentID;
    }

    void setStudentId(const string &studentId) {
        studentID = studentId;
    }

    const string &getCourseId() const {
        return courseID;
    }

    void setCourseId(const string &courseId) {
        courseID = courseId;
    }

    const string &getGrade() const {
        return grade;
    }

    void setGrade(const string &aGrade) {
        Transcript::grade = aGrade;
    }

    friend bool operator==(const Transcript &lhs, const Transcript &rhs) {
        return lhs.studentID == rhs.studentID && lhs.courseID == rhs.courseID;
    }

};

int Transcript::idCounter = 0;
#endif //CSCI2421_TRANSCRIPT_H
