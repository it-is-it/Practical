//14. WAP to
//a) demonstrate Lamda Expressions in C#.
using LabSharedLibrary;


class LambdaAndLinq
{
    delegate int Del(int i);

    static void DemonstrateLambda()
    {
        Console.WriteLine("Lambda Expression in C#");
        
        // Lambda expression to square a number
        Del myDelegate = x => x * x;
        int result = myDelegate(5);
        
        Console.WriteLine("5 * 5 = {0}", result);
    }

    static void DemonstrateLinqWithLambda()
    {
        Console.WriteLine("\nLINQ with Lambda Expression in C#");

        List<int> scores = new List<int>() { 98, 87, 34, 23, 89 };

        // LINQ with Lambda to find the average of scores greater than 80
        double average = scores.Where(num => num > 80).Average();

        Console.WriteLine("Average score greater than 80 is {0}", average);
    }

    public static void Main(string[] args)
    {
        DemonstrateLambda();
        DemonstrateLinqWithLambda();
        
        // Print lab details only once
        PrintName.printName("14");
    }
}
