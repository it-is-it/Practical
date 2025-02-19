//8. WAP program that contains:
//c) Partial Class


using System.ComponentModel.DataAnnotations;
using LabSharedLibrary;

public partial class Coords {
    private int x;
    private int y;
    public Coords(int x, int y){
        this.x = x;
        this.y = y;
    }

}


public partial class Coords {
    public void display(){
        Console.WriteLine("Ordinate:{0},Abscissa:{1}",x,y);
    }

}


class Test{
    public static void Main(string[] args){
        Console.WriteLine("Partial Class Implementation.");
        Coords P = new Coords(2,3);
        P.display();



        PrintName.printName("8c");

    }
}