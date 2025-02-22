using System;
using System.Collections;  // Required for Non-Generic Collections
using System.Collections.Generic;  // Required for Generic Collections

class Program
{
    static void Main()
    {
        Console.WriteLine("(a) Non-Generic Collection (ArrayList)");
        
        // (a) Non-Generic Collection - ArrayList
        ArrayList nonGenericList = new ArrayList();
        nonGenericList.Add(10);
        nonGenericList.Add("Hello");  // ArrayList allows mixed data types
        nonGenericList.Add(20.5);
        
        foreach (var item in nonGenericList)
        {
            Console.WriteLine(item);
        }

        Console.WriteLine("\n(b) Generic Collection (List<T>)");

        // (b) Generic Collection - List<int>
        List<int> genericList = new List<int>();
        genericList.Add(10);
        genericList.Add(20);
        genericList.Add(30);
        
        foreach (int num in genericList)
        {
            Console.WriteLine(num);
        }

        PrintName.printName("10");
    }
}

// Helper Class to Print Name
public class PrintName
{
    public static void printName(string labno)
    {
        Console.WriteLine("\nLab No.:{0}\nName:Ishwor Timalsina\nRoll No.:41\nSection:B", labno);
    }
}
