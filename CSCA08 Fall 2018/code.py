def build_marks_dict(input_file):
    input_line = input_file.readline()
    student_to_marks = {}
    
    while (not input_line.startswith("---")):
        input_line = input_line.strip()
        
        (student, course, grade) = input_line.split(',')
        course_to_grade = {}
        if (student in student_to_marks):
            student_to_marks = student_to_marks[student]
        else:
            student_to_marks[student] = course_to_grade
    
        course_to_grade[course] = float(grade)
        input_line = input_file.readline()
        
    return student_to_marks

input_file = open("grades.txt", "r")
student_to_marks = build_marks_dict(input_file)
print(student_to_marks)


def inc(L):
    for item in L:
        item += 1
    return L

def inc2(L):
    for i in range(len(L)):
        hello = L[i]
        hello += 1
    return L