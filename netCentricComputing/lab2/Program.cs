//WAP in C# to demonstrate concept of auto Property and Read-Only Property.
using LabSharedLibrary;

class Dog{
    private int age;

    public Dog(int age){
        this.age = age;
    }
    //Auto property
    public string Name{
        get;
        set;
    }
    
    //Read-only Property
    public int Age{
        get{ return age;}
    }


}


class PropertyTester{
    public static void Main(string[] args){
        Dog d = new Dog(3);
        Console.WriteLine("Enter Name:");
        string name = Console.ReadLine();
        d.Name = name;
        Console.WriteLine("Name is {0}.Age is: {1}",d.Name,d.Age);
        PrintName.printName("2");


    }
}

