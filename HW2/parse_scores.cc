// Copyright Jesse Estry 2019 CSCE 240
#include "parse_scores.h"

bool check_corrupt(const std::string values[], int size) {
  std::vector<string> values_dup;  // Create and copy array into a vector
  for (int k = 0; k < size; ++k) {
    values_dup.push_back(values[k]);
  }
  if (values_dup.empty())  // Check for empty array
    return true;
  int number_of_students = stoi(values[0]);  // Read the number of students
  unsigned int num_student_grades = 0;
  std::vector<double> current_student_grades;
  // Check each student for correct number of grades and record
  int index = 1;
  for (int i = 0; i < number_of_students; ++i) {
    ++index;
    num_student_grades = stoi(values[index]);
    ++index;
    for (unsigned int j = 0; j < num_student_grades; ++j) {
      if (index < size) {
        current_student_grades.push_back(stod(values[index]));
        ++index;
      }
    }
    if (current_student_grades.size() != num_student_grades) {
     // cout << "Corrupt Data at student ID: " << current_ID << endl;
      return true;
    }
    current_student_grades.clear();
  }
  return false;
}

int find_student(int id, const std::string values[], int size) {
  // finds index of stuent in given array
  if (check_corrupt(values, size)) {
    return -10;
  } else {
    int found_student = -1;  // find the ID
    for (int j = 0; j < size; ++j) {
      if (values[j].compare(std::to_string(id)) == 0) {
        found_student = j + 1;
        break;
      }
    }
    return found_student;
  }
}

int get_num_grades(int id, const std::string values[], int size) {
  // check to see if format is correct for all data
  if (check_corrupt(values, size)) {
    return -10;
  }
  if (find_student(id, values, size) > 0) {
    return std::stoi(values[find_student(id, values, size)]);
    // Find index of ID and return next value
  } else {
    return (find_student(id, values, size));
  }
}

int get_grades(int id, const std::string values[], int size, double grades[]) {
  if (check_corrupt(values, size)) {  // check to see if format is correct
    return -10;
  }
  if (find_student(id, values, size) > 0) {  // Check for student ID
    int index = find_student(id, values, size);
    for (int i = 0; i < get_num_grades(id, values, size); ++i) {
      // Record grades for ID
      grades[i] = stod(values[index + 1]);
      ++index;
    }
    return get_num_grades(id, values, size);
  } else {
    return find_student(id, values, size);
  }
}

double get_grade(int id, int grade_index,
                 const std::string values[], int size) {
      if (check_corrupt(values, size)) {  // check format
        return -10;
      }
      if (find_student(id, values, size) == -1) {  // check for student
        return -1;
      }
      int start_grade_index = find_student(id, values, size) + 1;
      int num_student_grades = get_num_grades(id, values, size);
      if (num_student_grades < grade_index || num_student_grades == 0) {
        // Check to make sure there is a grade at index
        return -2;
      }
      return (std::stod(values[(grade_index + start_grade_index)]));
}

int get_max_grade_id(const std::string values[], int size) {
  double max_grade = 0.0;
  int max_grade_id = 0;
  int total_number_of_grades = 0;
  std::vector<string> values_dup;  // Create and copy array into a vector
  for (int k = 0; k < size; ++k) {
    values_dup.push_back(values[k]);
  }
  if (values_dup.empty())  // Check for empty array
    return -1;
  int number_of_students = stoi(values[0]);
  // Read the number of students and check for 0
  if (number_of_students == 0)
    return -1;
  int current_id = 0;
  unsigned int num_student_grades = 0;
  std::vector<double> current_student_grades;
  // Check each student for correct number of grades and record
  int index = 1;
  for (int i = 0; i < number_of_students; ++i) {
    current_id = stoi(values[index]);
    ++index;
    num_student_grades = stoi(values[index]);
    total_number_of_grades += num_student_grades;
    ++index;
    for (unsigned int j = 0; j < num_student_grades; ++j) {
      if (index < size) {
        current_student_grades.push_back(stod(values[index]));
        if (stod(values[index]) > max_grade) {
          max_grade_id = current_id;
          max_grade = stod(values[index]);
        }
        ++index;
      }
    }
    if (current_student_grades.size() != num_student_grades) {
      cout << "Corrupt Data at student ID: " << current_id << endl;
      return -10;
    }
    current_student_grades.clear();
  }
  if (total_number_of_grades == 0) {
    return -2;
  }
  return max_grade_id;
}

double get_max_grade(const std::string values[], int size) {
  int max_id = get_max_grade_id(values, size);
  double max_grade = 0.0;
  if (max_id == -1 || max_id == -2 || max_id == -10)
    return static_cast<double>(max_id);
  int index = find_student(max_id, values, size);
  for (int i = 0; i < get_num_grades(max_id, values, size); ++i) {
    if (stod(values[index + 1]) > max_grade)
      max_grade = stod(values[index + 1]);
    ++index;
  }
  return max_grade;
}

int get_student_ids(const std::string values[], int size, int ids[]) {
  if (check_corrupt(values, size))  // Check format
    return -10;
  int array_position_tracker = 0;
  ids[array_position_tracker] = stoi(values[1]);
  // first value after # of id's is first id, store
  ++array_position_tracker;
  int index = 2;  // 3rd value will be # of grades in first value
  int curr_number_of_grades = stoi(values[index]);
  // Set how many elements to skip
  while (index < size) {
    index += curr_number_of_grades + 1;  // Moves to next id
    ids[array_position_tracker] = stoi(values[index]);
  }
  return (array_position_tracker - 1);
  // Array_pos_track will always be the first null element
}



