#include "iomanip"  /**used for formatting.*/

/****************************************************************************************************************/
void StudentDatabase::loadSampleDatabase() {
    shared_ptr<Course> aCourse;
    shared_ptr<Student> aStudent;
    shared_ptr<Transcript> aTranscript;

    aCourse = make_shared<Course>("CSCI2421", "Data Structures");
    this->courses.add(aCourse->getCourseId(), aCourse);
    aCourse = make_shared<Course>("CSCI2511", "Discrete Structures");
    this->courses.add(aCourse->getCourseId(), aCourse);

    aStudent = make_shared<Student>("John", "id001", "john@ucdenver.edu");
    this->students.add(aStudent->getId(), aStudent);
    aStudent = make_shared<Student>("Alice", "id002", "alice@ucdenver.edu");
    this->students.add(aStudent->getId(), aStudent);

    aTranscript = make_shared<Transcript>("id001", "CSCI2421", "A");
    this->transcripts.add(aTranscript);
    aTranscript = make_shared<Transcript>("id001", "CSCI2511", "B+");
    this->transcripts.add(aTranscript);
    aTranscript = make_shared<Transcript>("id002", "CSCI2421", "A");
    this->transcripts.add(aTranscript);
    aTranscript = make_shared<Transcript>("id002", "CSCI2511", "A-");
    this->transcripts.add(aTranscript);
}

/****************************************************************************************************************/
void StudentDatabase::displayStudents() {

    cout << string(60, '=') << endl;
    cout << left <<
         setw(10) << "Student ID" << " -- " <<
         setw(20) << "Student Name" << " -- " <<
         setw(30) << "Student Email" << endl;
    cout << string(60, '=') << endl;
    //TODO: Traverse the student dictionary.

    //YOUR CODE HERE
    this->students.traverse(this->displayStudent);

    cout << string(60, '=') << endl;
}

/****************************************************************************************************************/
void StudentDatabase::displayCourses() {
    cout << string(44, '=') << endl;
    cout << left <<
         setw(10) << "Course ID" << " -- " <<
         setw(30) << "Description" << endl;
    cout << string(44, '=') << endl;
    //TODO: Traverse the courses dictionary.
    this->courses.traverse(this->displayCourse);
    //YOUR CODE HERE


    cout << string(44, '=') << endl;
}

/****************************************************************************************************************/
void StudentDatabase::displayRecords() {
    cout << string(57, '=') << endl;
    cout <<
         setw(10) << "Rec ID" << " -- " <<
         setw(10) << "Student ID" << " -- " <<
         setw(10) << "Course ID" << " -- " <<
         setw(15) << "Final Grade" << endl;
    cout << string(57, '=') << endl;
    /**
     *     TODO: list for each transcript record the raw info.
     *     Some help on formatting es below
     */

    //YOUR CODE HERE

    /* FORMATTING
     cout<<left <<
        setw(10) << transcript Id << " -- " <<
        setw(10) << StudentId << " -- " <<
        setw(10) << CourseId << " -- " <<
        setw(15) << Grade << endl;
    */

     cout << string(57, '=') << endl;
}

/****************************************************************************************************************/
void StudentDatabase::displayTranscript() {
    cout << string(115, '=') << endl;
    cout << left <<
         setw(10) << "RecID" << " -- " <<
         setw(10) << "Student ID" << " -- " << setw(20) << "Student Name" << " -- " <<
         setw(10) << "Course" << " -- " << setw(30) << "Course Description" << " -- " <<
         setw(15) << "Final Grade" << endl;
    cout << string(115, '=') << endl;

    /**
     * TODO: Generate Transcript
     * For each raw record, retrieve the student using the dictionary and the student id in the record.
     * also retrieve the course in similar fashion.
     * Display the transcript. (help on formatting is below.)
     */

    //YOUR CODE HERE

    /* FORMATTING
        cout << left <<
             setw(10) <<  Transcript Id << " -- " <<
             setw(10) <<  Student Id << " -- " << setw(20) << student name << " -- " <<
             setw(10) <<  Course Id << " -- " << setw(30) << Course Description << " -- " <<
             setw(15) <<  Grade << endl;
    */
    cout << string(115, '=') << endl;
}


/****************************************************************************************************************/
void StudentDatabase::displayStudent(shared_ptr<Student> &aStudent) {
    cout << left <<
         setw(10) << aStudent->getId() << " -- " <<
         setw(20) << aStudent->getName() << " -- " <<
         setw(30) << aStudent->getEmail() << endl;
}

/****************************************************************************************************************/
void StudentDatabase::displayCourse(shared_ptr<Course> &aCourse) {
    cout << left <<
         setw(10) << aCourse->getCourseId() << " -- " <<
         setw(30) << aCourse->getDescription() << endl;
}
