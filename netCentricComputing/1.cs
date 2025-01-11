// Write a C# program to demonstrate five types of constructor in C#.

// 1. Default Constructor  
// 2. Parameterized Constructor  
// 3. Copy Constructor  
// 4. Static Constructor  
// 5. Private Constructor

using System;
class ConstructorDemo
{
    // Default Constructor
    public ConstructorDemo()
    {
        Console.WriteLine("Default Constructor Called");
    }

    // Parameterized Constructor
    public ConstructorDemo(string message)
    {
        Console.WriteLine($"Parameterized Constructor Called: {message}");
    }

    // Copy Constructor
    public ConstructorDemo(ConstructorDemo other)
    {
        Console.WriteLine("Copy Constructor Called");
    }

    // Static Constructor
    static ConstructorDemo()
    {
        Console.WriteLine("Static Constructor Called");
    }

    // Private Constructor
    private ConstructorDemo(int secret)
    {
        Console.WriteLine($"Private Constructor Called with secret: {secret}");
    }

    // Method to demonstrate Private Constructor
    public static ConstructorDemo CreateInstanceWithPrivateConstructor(int secret)
    {
        return new ConstructorDemo(secret);
    }

    static void Main(string[] args)
    {
        Console.WriteLine("Demonstrating Constructors in C#:\n");

        // Default Constructor
        ConstructorDemo defaultDemo = new ConstructorDemo();

        // Parameterized Constructor
        ConstructorDemo paramDemo = new ConstructorDemo("Hello, World!");

        // Copy Constructor
        ConstructorDemo copyDemo = new ConstructorDemo(defaultDemo);

        // Using Static Constructor
        ConstructorDemo staticDemo = new ConstructorDemo();

        // Using Private Constructor
        ConstructorDemo privateDemo = ConstructorDemo.CreateInstanceWithPrivateConstructor(42);

        Console.WriteLine("\nAll constructors demonstrated successfully.");
    }
}


// # Explanation:
// 1. Default Constructor:
//    - Automatically called when an object is created without any parameters.
// 2. Parameterized Constructor:
//    - Accepts arguments to initialize the object with specific values.
// 3. Copy Constructor:
//    - Initializes a new object by copying an existing object.
// 4. Static Constructor:
//    - Automatically called to initialize static data or perform actions that only need to be done once.
// 5. Private Constructor:
//    - Restricts object creation externally; typically used in singleton patterns or factory methods.

// # Output:
// Demonstrating Constructors in C#:

// Static Constructor Called
// Default Constructor Called
// Parameterized Constructor Called: Hello, World!
// Copy Constructor Called
// Default Constructor Called
// Private Constructor Called with secret: 42

// All constructors demonstrated successfully.
