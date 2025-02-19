//Dynamic Polymorphism
using LabSharedLibrary;

abstract class Shape{
    public abstract void getArea();
}

class Rectangle:Shape{
   private int length;
   private int width;

   public Rectangle(int l,int w){
    length=l;
    width = w;
   }

   public override void getArea(){
        Console.WriteLine("Area of rectangle is:{0}",length*width);
    }
}

class Test{
    public static void Main(string[] args){
        Rectangle r = new Rectangle(3,4);
        r.getArea();

        PrintName.printName("6b");
    }
}