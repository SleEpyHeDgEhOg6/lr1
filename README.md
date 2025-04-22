#Нужно создать класс Group, в нём создать вектор студентов, организовать добавление студентов в группу и удаление студентов из группы и поиск студентов в группе, реализация методов на ваше усмотрение. Так же необходимо реализовать всё функции из задания помимо связанных с группами.
Пусть есть структура Student

struct Student
{
  std::string Name;
  std::string GroupId;
  std::vector<unsigned> Ratings;
  std::vector<std::string> Subjects;
};
В поле Ratings представлены оценки по соответсвующему предмету из поля Subjects. Предположим есть список студентов std::vector<Student> students. Ваше задание состоит в реализации ряда функций. Все прототипы функций необходимо разместить в файле include/header.hpp.

Реазилуйте функции, которые выполяют следующие действия с этим списком:

отсортирует всех студентов по именам. Прототип:

void SortByName(std::vector<Student>&);

отсортирует всех студентов по средней оценке;

void SortByRating(std::vector<Student>&);

вернет количество студентов имеющих неудовлетворительную оценку хотя бы по одному предмету;

size_t CountTwoness(const std::vector<Student>&);

определит, сколько студентов сдали все экзамены на 5.

size_t CountExcellent(const std::vector<Student>&);

создаст массив std::vector<Student>, в который войдут студенты имеющие отметку отлично, по предмету "Math";

std::vector<Student> VectorMathExcellent(const std::vector<Student>&);
