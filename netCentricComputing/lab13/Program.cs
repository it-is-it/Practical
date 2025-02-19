//13. WAP to demonstrate the concept of LINQ
using LabSharedLibrary;

class LinqImplementation{
    public static void Main(string[] args){

        int[] marks = new int[]{88,77,45,67,95,76};
        Console.WriteLine("LINQ implementation.");
        Console.WriteLine("Selecting marks greater than 75...");

        var result = from mark in marks 
                     where mark > 75
                     select mark;

        Console.WriteLine("The marks selected are:");
        foreach(int i in result){
            Console.WriteLine(i);
        }

        PrintName.printName("13");
    }
}