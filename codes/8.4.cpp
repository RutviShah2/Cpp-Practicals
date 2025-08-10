#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int score;
};

void sortStudents(std::vector<Student>& students) {
    for (size_t i = 0; i < students.size(); ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].score < students[j].score) {
                std::swap(students[i], students[j]);
            }
        }
    }
}

int main() {
    std::vector<Student> students;
    int n;

    std::cout << "Enter the number of students: ";
    std::cin >> n;

    std::cout << "Enter student names and their scores:\n";
    for (int i = 0; i < n; ++i) {
        Student student;
        std::cin >> student.name >> student.score;
        students.push_back(student);
    }

    sortStudents(students);

    std::cout << "Ranked Students based on their scores:\n";
    int rank = 1;
    for (const auto& student : students) {
        std::cout << "Rank " << rank++ << ": " << student.name << " - " << student.score << std::endl;
    }

    return 0;
}
