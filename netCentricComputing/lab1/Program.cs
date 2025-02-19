//Write a program in C# to implement five types of constructor in C#
using LabSharedLibrary;
class Person{
    string name="Ishwor";
    int age=20;

    static string creator;

    static int callCount;

    //Default Constructor
    public Person(){
        callCount ++;
        creator = "default";
    }

    //Parameterized constructor
    public Person(String name,int age){
        this.name = name;
        this.age = age;
        callCount++;
        creator = "parameterized";
    }
    
    //Copy constructor
    public Person(Person p){
        callCount++;
        this.name = p.name;
        this.age = p.age;
        creator = "copy";

    }

    //Static Constructor
    static Person(){
        callCount = 0;
        creator = "static";
        Console.WriteLine("This is static constructor.");   

    }

    //Private Constructor
    private Person(string name){
        callCount ++;
        this.name = name;
        creator = "private";

    }

    public static void printCount(){
        Console.WriteLine("There are {0} objects.",callCount);
        
    }

    public static void callPrivateConstructor(){
        Person p1 = new Person("Roman");
        p1.display();

    }
    public void display(){
        Console.WriteLine("The person's name is {0}. And age is {1}. It is created by {2} constructor.",name,age,creator);
        
    }


}

class Tester{
    public static void Main(String[] args){
        Person p1 = new Person();
        p1.display();
        Person p2 = new Person("Dean",15);
        p2.display();
        Person p3 = new Person(p2);
        p3.display();
        Person.callPrivateConstructor();
        Person.printCount(); 
        PrintName.printName("1");       
    }
}