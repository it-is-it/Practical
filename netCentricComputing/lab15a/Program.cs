//15. WAP to
//a) demonstrate exception handling in C# using try, catch and finally blocks.

using LabSharedLibrary;

class ExceptionHandling{

    public static void Main(string[] args){
        int x = 5;
        int y = 0;
        
        Console.WriteLine("Exception Handling in C#");
        try{
            int div = x/y;
            Console.WriteLine("{0}/{1}:{2}",x,y,div);
        }
        catch(DivideByZeroException){
            Console.WriteLine("Exception occured. Can't divide by zero.");
        }
        finally{
            Console.WriteLine("Execution Completed");
        }
        PrintName.printName("15a");
    }
}