//Program to show a) method overriding and method hiding/shadowing in C#
using hiding;
using LabSharedLibrary;
using overriding;


namespace overriding{
 class Animal{
    public virtual void eat(){
        Console.WriteLine("I eat");
    }
 }

 class Cat:Animal{
    public override void eat()
    {
        Console.WriteLine("I eat fish.");
    }
}

}

namespace hiding{
    class Shape{
        public void getArea(){
            Console.WriteLine("Hide me.");
        }
    }

    class Rectangle:Shape{
        public new void getArea(){
            Console.WriteLine("Area:length*width");
        }
    }
}

class Test{
    public static void Main(string[] args){
        Console.WriteLine("Method overriding");
        Animal cat   = new Cat();
        cat.eat();

        Console.WriteLine();

        Console.WriteLine("Method hiding");
        Rectangle r1 = new Rectangle();
        r1.getArea();

        PrintName.printName("6a");

        

    }

}