//8. WAP program that contains:
//a) Structure (struct)
// b) Enumeration (enum) 
// c) Partial class 

using LabSharedLibrary;
using System;

// (a) Structure (struct)
struct Student
{
    public string name;
    public int rollNo;
    public Grade grade;  // Using enum inside struct

    // Constructor
    public Student(string name, int rollNo, Grade grade)
    {
        this.name = name;
        this.rollNo = rollNo;
        this.grade = grade;
    }

    // Method to display student details
    public void DisplayInfo()
    {
        Console.WriteLine("Student Name: {0}", name);
        Console.WriteLine("Roll No.: {0}", rollNo);
        Console.WriteLine("Grade: {0}", grade);
    }
}

// (b) Enumeration (enum)
enum Grade
{
    A, B, C, D, F
}

// (c) Partial Class (Dividing a class into multiple files)
partial class Vehicle
{
    public string Brand { get; set; }
    public string Model { get; set; }

    public Vehicle(string brand, string model)
    {
        Brand = brand;
        Model = model;
    }
}

// Second part of the partial class (adding more functionality)
partial class Vehicle
{
    public void DisplayInfo()
    {
        Console.WriteLine("Vehicle Brand: {0}", Brand);
        Console.WriteLine("Vehicle Model: {0}", Model);
    }
}

// Main Program
class Test
{
    public static void Main(string[] args)
    {
        Console.WriteLine("=== Structure Demonstration ===");
        Student s1 = new Student("Ishwor", 41, Grade.A);
        s1.DisplayInfo();

        Console.WriteLine("\n=== Enumeration Demonstration ===");
        Grade myGrade = Grade.B;
        Console.WriteLine("Selected Grade: {0}", myGrade);

        Console.WriteLine("\n=== Partial Class Demonstration ===");
        Vehicle car = new Vehicle("Toyota", "Corolla");
        car.DisplayInfo();

        PrintName.printName("8");
    }
}
