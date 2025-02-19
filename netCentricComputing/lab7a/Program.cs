//7. WAP to illustrate the concept of
//a) Abstract class
using LabSharedLibrary;


abstract class Shape{
    abstract public int getArea();

}

class Rectangle: Shape{
    private int length;
    private int breadth;

    public Rectangle(int l , int b){
        this.length = l;
        this.breadth = b;
    }

    public override int getArea(){
        return length*breadth;
    }

}

class Test{
    public static void Main(string[] args){
        Rectangle obj = new Rectangle(10,12);
        Console.WriteLine("Abstract Class Implementation");
        Console.WriteLine("The area of rectangle is {0}",obj.getArea());
        PrintName.printName("7a");
    }
}
