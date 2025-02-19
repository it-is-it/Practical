//14. WAP to
//a) demonstrate Lamda Expressions in C#.
using LabSharedLibrary;

class LamdaExpression{
    delegate int Del(int i);
    public static void Main(string[] args){
        Console.WriteLine("Lambda Expression in C#");
        Del myDelegate = x => x*x;
        int i = myDelegate(5);
        
        Console.WriteLine("5*5 = {0}",i);

        PrintName.printName("14a");
    }
}