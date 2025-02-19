//WAP to illustrate
//b) LINQ with Lambda Expression in C#

using LabSharedLibrary;

class LamdaLinq{
    public static void Main(string[] args){
        Console.WriteLine("LINQ with Lambda expression in C#");
        List<int> scores = new List<int>(){98,87,34,23,89};

        double average = scores.Where(num => num>80).Average();
        Console.WriteLine("Average score greater than 80 is {0}",average);

        PrintName.printName("14b");
    }
}