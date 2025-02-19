//5. WAP to demonstrate:a) The use of base keyword to access base class fields
//b) The use of base keyword to call base class methods
//c) The use of base keyword to call base class constructor
using LabSharedLibrary;

class Animal{
    protected string color;
    protected int age;

    public Animal(string color,int age){
        this.color = color;
        this.age = age;
    }

    public void eat(){
        Console.WriteLine("Eating...");
    }
}

class Dog:Animal{
    string name;
    public Dog(string name,string color,int age):base(color,age){
        Console.WriteLine("Base class constructor called using base keyword.");
        this.name = name;
    }

    public void showColor(){
        Console.WriteLine("Base class field color accessed using base keyword.");
        Console.WriteLine("I am a {0} dog.",base.color);
    }

    public void eat(){
        Console.WriteLine("Base class method eat() called using base keyword.");
        base.eat();
    }
}

class Test{
    public static void Main(){
        Dog d1 = new Dog("Tommy","Black",2);
        d1.eat();
        d1.showColor();
        PrintName.printName("5");
    }
}



