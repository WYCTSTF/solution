import java.util.ArrayList;

class person {
  String _name, _id;
  person(String name, String id) {
    _name = name;
    _id = id;
  }
  ArrayList<String> _course = new ArrayList<String>();
  void addCourse(String _class) { _course.add(_class); }
  String askClass(int pos) { return _course.get(pos - 1); }
}

class Teacher extends person {
  String _PersonnalRanks;
  Teacher(String name, String id, String PersonnalRanks) {
    super(name, id);
    _PersonnalRanks = PersonnalRanks;
  }
}

class Student extends person {
  String _major;
  int _grade;
  Student(String name, String id, int grade, String major) {
    super(name, id);
    _grade = grade;
    _major = major;
  }
}

public class Main {
  public static void main(String[] args) {
    Teacher t1 = new Teacher("ss", "ff", "iii");
    Student s1 = new Student("bb", "dd", 8, "major");
    t1.addCourse("BB");
    System.out.println(t1.askClass(1));
    System.out.println(s1._id);
  }
}