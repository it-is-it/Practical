using System;
using System.Reflection;

// (a) Using Built-in Attributes
class BuiltInAttributes
{
    // Marks this method as obsolete (discouraged)
    [Obsolete("Use NewMethod() instead")]
    public void OldMethod()
    {
        Console.WriteLine("This is an old method.");
    }

    public void NewMethod()
    {
        Console.WriteLine("This is the new recommended method.");
    }
}

// (b) Creating a Custom Attribute
[AttributeUsage(AttributeTargets.Class | AttributeTargets.Method)]
class CustomInfoAttribute : Attribute
{
    public string Developer { get; }
    public string Version { get; }

    public CustomInfoAttribute(string developer, string version)
    {
        Developer = developer;
        Version = version;
    }
}

// Applying Custom Attribute
[CustomInfo("Ishwor Timalsina", "1.0")]
class CustomAttributeDemo
{
    [CustomInfo("Ishwor Timalsina", "1.1")]
    public void Display()
    {
        Console.WriteLine("Custom Attribute Applied!");
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("(a) Demonstrating Built-in Attributes:");
        BuiltInAttributes obj = new BuiltInAttributes();
        obj.OldMethod();  // Compiler warning: "Use NewMethod() instead"
        obj.NewMethod();

        Console.WriteLine("\n(b) Demonstrating Custom Attribute:");
        CustomAttributeDemo demo = new CustomAttributeDemo();
        demo.Display();

        // Reflection to Read Custom Attribute
        Type type = typeof(CustomAttributeDemo);
        object[] attributes = type.GetCustomAttributes(typeof(CustomInfoAttribute), false);

        foreach (CustomInfoAttribute attr in attributes)
        {
            Console.WriteLine($"Class Developer: {attr.Developer}, Version: {attr.Version}");
        }

        MethodInfo method = type.GetMethod("Display");
        attributes = method.GetCustomAttributes(typeof(CustomInfoAttribute), false);

        foreach (CustomInfoAttribute attr in attributes)
        {
            Console.WriteLine($"Method Developer: {attr.Developer}, Version: {attr.Version}");
        }
        Console.WriteLine("\nLab No.: 16\nName: Ishwor Timalsina\nRoll No.: 41\nSection: B");
    }
}
