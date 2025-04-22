#include<string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    std::string Name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;
    double cp() {
        double summa = 0;
        for (unsigned rat : Ratings) {
            summa += rat;
        }
        return summa / Ratings.size();
    }
};

class Group{
private:
    std::vector<Student> students;
public:
    void AddSt(const Student& student) {//функция для добавления студента
        students.push_back(student);
    }
    bool findStudent(const std::string& studentName) const {
        return std::any_of(students.begin(), students.end(), [&](const Student& student) {//any_of - работает по типу существует хотя бы один такой элемент, что
            return student.Name == studentName; // Проверяем, есть ли студент с таким именем
        });
    }
    void RemoveS(const std::string studentName){//функция для удаления студентов
        for(auto ot=students.begin();ot!=students.end();++ot){
            if(ot->Name==studentName){
                students.erase(ot);
                break;
            }
        }
    }
    void SortByName(std::vector<Student>& students) {//сортировка по имени студента
        int len = students.size();
        for (int i = 0; i < len - 1; ++i) {//пузырьковая сортировка
            for (int p = 0; p < len - 1 - i; ++p) {
                if (students[p].Name > students[p + 1].Name) {
                    auto rt = students[p].Name;
                    students[p].Name = students[p + 1].Name;
                    students[p + 1].Name = rt;
                }
            }
        }
    }
    void SortByRating(std::vector<Student>& students) {//сортировка по успеваемости
        int len = students.size();
        for (int i = 0; i < len - 1; ++i) {
            for (int p = 0; p < len - 1 - i; ++p) {
                if (students[p].cp() > students[p + 1].cp()) {
                    auto rt = students[p].Ratings;
                    students[p].Ratings = students[p + 1].Ratings;
                    students[p + 1].Ratings = rt;
                }
            }
        }
    }
    size_t CountTwoness(const std::vector<Student>&students) {//функция, которая будет считать количество студентов с неудовлетворительной оценкой
        int count = 0; //буду считать,что неудовлетворительная оценка это меньше 3
        for (auto rt : students) {
            for(unsigned rat: rt.Ratings){
                if (rat < 3) {
                    count += 1;
                }
            }
        }
        return count;
    }
    size_t CountExcellent(const std::vector<Student>&students) {//функция, которая будет считать количество студентов с отличной оценкой по всем предметам
        int count = 0;
        for (auto rt : students) {
            bool pro = true;//флажок для проверки
            for (unsigned rat : rt.Ratings) {
                if (rat != 5) {//если хотя одна оценка равна не 5,то меняем значение флажка
                    pro = false;
                }
            }
            if (pro == true) {
                count += 1;
            }
        }
        return count;
    }
    std::vector<Student> VectorMathExcellent(const std::vector<Student>&students) {//функция, которая будет считать количество студентов с отличной оценкой по математике
        std::vector<Student> math5;
        for (int i = 0; i < students.size(); ++i) {//поиск под каким по счету стоит название предмета
            int mathindex = -1;//-1 так как на 0 индексе что-то есть
            for (int p = 0; p < students[i].Subjects.size(); ++p) {
                if(students[i].Subjects[p] == "Math") {
                    mathindex = p;
                }
            }
            if (mathindex != -1 && students[i].Ratings[mathindex] == 5) {
                math5.push_back(students[i]);
            }
        }
        return math5;
    }
};
