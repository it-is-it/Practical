//10. WAP which use any
//b)  Generic collection


using System.Collections.Generic;
using LabSharedLibrary;

class Program{
    public static void Main(string[] args){
        Stack<int> stack = new Stack<int>();
        Console.WriteLine("Generic stack implementation.");
        Console.WriteLine("Pushing items into stack");
        stack.Push(23);
        stack.Push(33);
        stack.Push(12);
        stack.Push(55);
        stack.Push(46);

        Console.WriteLine("Count: {0}\n",stack.Count());
        Console.WriteLine("Top of the stack: {0}",stack.Peek());
        

        //Popping elements
        Console.WriteLine("Popping top of the stack");
        stack.Pop();
        Console.WriteLine("Top of the stack: {0}",stack.Peek());
        Console.WriteLine("Count: {0}\n",stack.Count());
        
        PrintName.printName("10b");



    }

}