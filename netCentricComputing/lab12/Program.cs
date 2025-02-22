//12. WAP to take input from keyboard and write them to a file
using System.IO;
using System;
using LabSharedLibrary;
class Program{
    public static void Main(){
        StreamWriter writer = new StreamWriter("./hello.txt");
        Console.WriteLine("Writing into the file...");
        Console.WriteLine("Enter the text to write in a file.");
        string str = Console.ReadLine();
        writer.WriteLine(str);
        writer.Flush();
        writer.Close();
        
        StreamReader reader = new StreamReader("./hello.txt");
        Console.WriteLine("Reading the file...");
        str = reader.ReadLine();
        while(str!=null){
            Console.WriteLine(str);
            str = reader.ReadLine();
        }
        reader.Close(); 

        PrintName.printName("12");
    }
}