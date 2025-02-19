//10. WAP which use any
//a) Non generic collection

using System.Collections;
using LabSharedLibrary;

class Program{
    public static void Main(string[] args){
        ArrayList array = new ArrayList(10);
        Console.WriteLine("Non-Generic Array.");
        Console.WriteLine("Adding elements.");
        array.Add(23);
        array.Add("hello");
        array.Add(34);
        array.Add(28);
        
        Console.WriteLine("Capacity:{0}\nCount:{1}",array.Capacity,array.Count);
        Console.WriteLine("Elements of array are:");
        foreach(object i in array){
            Console.WriteLine(i);
        }
        PrintName.printName("10a");
        
    }
}