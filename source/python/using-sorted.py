#!/usr/bin/python3

class Student:
    def __init__(self, name, grade, age):
        self.name = name
        self.grade = grade
        self.age = age
    def __repr__(self):
        return repr({'name': self.name, 'grade': self.grade, 'age': self.age})
        return repr((self.name, self.grade, self.age))

student_objects = [
    Student('李华', 'A', 15),
    Student('张丽', 'B', 12),
    Student('王红', 'B', 10),
]

from operator import itemgetter, attrgetter
sorted_students = sorted(student_objects, key=attrgetter('age'))
print(sorted_students)
