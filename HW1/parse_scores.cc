// "Copyright 2019 Jesse Estry"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::stod;

int main(int argc, char* argv[]) {
  static const string DELIM = " ";
  int num_of_students;
  int student_id;
  int num_of_grades;
  double curr_grade;
  double max_grade;
  int max_id;

  cin >> num_of_students;  // intake number of students
  cout << "{" << endl;
  cout << "  \"students\" : [" << endl;
  for (int i = 0; i < num_of_students-1; ++i) {
    /*for i number of students, 
    intake id and number of grades */
    cin >> student_id;
    cout << "    { \"id\" : " << student_id << ", \"grades\" : [ ";
    cin >> num_of_grades;
    for (int j = 0; j < num_of_grades-1; ++j) {
      // intake number of grades for current student
      cin >> curr_grade;
      if (max_grade < curr_grade) {
        // check to see if current grade is higher than max
        max_id = student_id;
        max_grade = curr_grade;
      }
      cout << curr_grade << ", ";
    }
    cin >> curr_grade;
    // repeat for last value but remove "," at end of bracket
    if (max_grade < curr_grade) {
      max_id = student_id;
      max_grade = curr_grade;
    }
    cout << curr_grade << " ] }," << endl;
  }
  cin >> student_id;
  cout << "    { \"id\" : " << student_id << ", \"grades\" : [ ";
    cin >> num_of_grades;
  for (int j = 0; j < num_of_grades - 1; ++j) {
    // repeat previous process to remove "," from end of last line
    cin >> curr_grade;
    if (max_grade < curr_grade) {
      max_id = student_id;
      max_grade = curr_grade;
    }
    cout << curr_grade << ", ";
  }
  cin >> curr_grade;
  if (max_grade < curr_grade) {
    max_id = student_id;
    max_grade = curr_grade;
  }
  cout << curr_grade << " ] }" << endl;
  cout << "  ]," << endl;
  cout << "  \"max_id\" : " << max_id << "," << endl;
  cout << "  \"max_score\" : " << max_grade << endl;
  cout << "}";

  return 0;
}
