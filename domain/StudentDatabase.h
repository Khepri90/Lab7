#ifndef CSCI2421_STUDENTDATABASE_H
#define CSCI2421_STUDENTDATABASE_H

#include "iostream"
#include "Student.h"
#include "Course.h"
#include "Transcript.h"
#include "../dictionary/ArrayDictionary.h"
#include "../bag/LinkedBag.h"

using namespace std;

/**
 * Represents the Student database. Or at least a very simplified version of it.
 **/
class StudentDatabase {
private:
    ArrayDictionary<string, shared_ptr<Student>> students;  //Dict to store students as k->v: studentId -> student
    ArrayDictionary<string, shared_ptr<Course>> courses;    //Dict to store courses as k->v: courseId -> course
    LinkedBag<shared_ptr<Transcript>> transcripts;          //Bag that stores the transcript raw records.

    static void displayStudent(shared_ptr<Student>&);     /**Helper for traverse */
    static void displayCourse(shared_ptr<Course>&);       /**Helper for traverse */

public:
    explicit StudentDatabase() = default;

    void loadSampleDatabase();

    void displayStudents(); /** Displays the student data*/

    void displayCourses(); /** Displays the course data */

    void displayRecords(); /** Displays the raw transcript data, no join*/

    void displayTranscript(); /** Displays the transcript, joining records, student and course data */

};
#include "./StudentDatabase.cpp"

#endif
