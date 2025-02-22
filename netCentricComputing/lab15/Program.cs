//15. WAP to
//a) demonstrate exception handling in C# using try, catch and finally blocks.

using LabSharedLibrary;
using System;

// Custom Exception Class
class CustomException : Exception
{
    public CustomException(string message) : base(message) { }
}

class ExceptionHandlingDemo
{
    // Demonstrating try, catch, and finally
    static void TryCatchFinallyDemo()
    {
        try
        {
            Console.WriteLine("Enter a number:");
            int num = Convert.ToInt32(Console.ReadLine());

            int result = 100 / num; // May cause DivideByZeroException
            Console.WriteLine("100 / {0} = {1}", num, result);
        }
        catch (DivideByZeroException e)
        {
            Console.WriteLine("Exception Caught: Cannot divide by zero.");
        }
        catch (FormatException e)
        {
            Console.WriteLine("Exception Caught: Invalid input. Please enter a number.");
        }
        finally
        {
            Console.WriteLine("Finally block executed.\n");
        }
    }

    // Demonstrating throw keyword
    static void ThrowKeywordDemo()
    {
        try
        {
            Console.WriteLine("Enter a positive number:");
            int num = Convert.ToInt32(Console.ReadLine());

            if (num < 0)
                throw new ArgumentException("Negative numbers are not allowed!");

            Console.WriteLine("You entered: {0}", num);
        }
        catch (ArgumentException e)
        {
            Console.WriteLine("Exception Caught: " + e.Message);
        }
    }

    // Demonstrating Custom Exception Handling
    static void CustomExceptionDemo()
    {
        try
        {
            Console.WriteLine("\nEnter age:");
            int age = Convert.ToInt32(Console.ReadLine());

            if (age < 18)
                throw new CustomException("You must be at least 18 years old!");

            Console.WriteLine("Access granted!");
        }
        catch (CustomException e)
        {
            Console.WriteLine("Custom Exception Caught: " + e.Message);
        }
    }

    public static void Main(string[] args)
    {
        Console.WriteLine("Demonstrating Exception Handling in C#\n");

        TryCatchFinallyDemo();   // Part (a)
        ThrowKeywordDemo();      // Part (b)
        CustomExceptionDemo();   // Part (c)

        Console.WriteLine("\nLab No.: 15\nName: Ishwor Timalsina\nRoll No.: 41\nSection: B");
    }
}
