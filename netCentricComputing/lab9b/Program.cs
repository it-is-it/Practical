//9. WAP to illustrate the concept of:
//b) Multicast delegate

using LabSharedLibrary;

class Rectangle{
    public delegate void Mydelegate(double length, double breadth);

    static void perimeter(double length,double breadth){
        Console.WriteLine("The perimeter of the rectangle is {0}.",2*(length+breadth));
    }

    static void area(double length,double breadth){
        Console.WriteLine("The area of the rectangle is {0}.",length*breadth);
    }

    public static void Main(string[] args){
        Mydelegate deleg = new Mydelegate(perimeter);
        deleg +=area;

        Console.WriteLine("Multicast Delegate Implementation.\n");
        deleg.Invoke(10,12);

        PrintName.printName("9b");
    }


    
}