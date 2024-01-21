#include <bits/stdc++.h>
using namespace std;

class Grade
{
public:
    string subject;
    int grade;

    Grade(const string &subj, int grd) : subject(subj), grade(grd) {}
};

class Student
{
public:
    string name;
    vector<Grade> grades;

    Student(const string &n, const vector<Grade> &grd) : name(n), grades(grd) {}
};

vector<float> calculateAverageGrades(const vector<Student> &students)
{
    std::vector<float> averageGrades;

    for (const auto &student : students)
    {
        float sum = 0.0;
        for (const auto &grade : student.grades)
        {
            sum += static_cast<float>(grade.grade);
        }
        float average = sum / student.grades.size();
        averageGrades.push_back(average);
    }

    return averageGrades;
}

vector<float> calculateAverageSubjects(const std::vector<Student> &students)
{
    std::vector<float> averageSubjects;

    unordered_map<string, int> subjectCounts;
    unordered_map<string, float> subjectSums;

    for (const auto &student : students)
    {
        for (const auto &grade : student.grades)
        {
            subjectCounts[grade.subject]++;
            subjectSums[grade.subject] += static_cast<float>(grade.grade);
        }
    }

    // Calculate averages for each subject
    for (const auto &pair : subjectCounts)
    {
        float average = subjectSums[pair.first] / pair.second;
        averageSubjects.push_back(average);
    }

    return averageSubjects;
}

float calculateOverallAverage(const vector<Student> &students)
{
    float overallSum = 0.0;
    int overallCount = 0;

    for (const auto &student : students)
    {
        for (const auto &grade : student.grades)
        {
            overallSum += static_cast<float>(grade.grade);
            overallCount++;
        }
    }

    return overallSum / overallCount;
}

float calculateStandardDeviation(const vector<Student> &students)
{
    float overallAverage = calculateOverallAverage(students);
    float squaredDifferences = 0.0;
    int totalGrades = 0;

    for (const auto &student : students)
    {
        for (const auto &grade : student.grades)
        {
            squaredDifferences += pow(static_cast<float>(grade.grade) - overallAverage, 2);
            totalGrades++;
        }
    }

    float variance = squaredDifferences / totalGrades;
    return sqrt(variance);
}

int main()
{
    // Example data
    vector<Student> students = {
        {"John Doe", {{"Math", 90}, {"English", 85}, {"Science", 92}, {"History", 88}, {"Art", 95}}},
        {"Jane Smith", {{"Math", 88}, {"English", 92}, {"Science", 87}, {"History", 90}, {"Art", 93}}},
        {"Bob Johnson", {{"Math", 78}, {"English", 85}, {"Science", 80}, {"History", 88}, {"Art", 82}}}
        // Add more students as needed
    };

    vector<float> averageGrades = calculateAverageGrades(students);
    vector<float> averageSubjects = calculateAverageSubjects(students);
    float overallAverage = calculateOverallAverage(students);
    float stdDeviation = calculateStandardDeviation(students);

    cout << "Average Grades for each student:{";
    for (int i = 0; i < students.size(); ++i)
    {
        cout << averageGrades[i] << ",";
    }
    cout << "}" << endl;

    cout << "\nAverage Grades for each subject: {";
    for (int i = 0; i < averageSubjects.size(); ++i)
    {
        cout << averageSubjects[i] << ",";
    }
    cout << "} " << endl;

    cout << "\nOverall Average Grade: " << overallAverage << endl;
    cout << "Standard Deviation: " << stdDeviation << endl;

    return 0;
}
