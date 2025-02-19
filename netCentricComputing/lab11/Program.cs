//11. Program to demonstrate the use of Generic Class with Generic field and method.

using System.Collections.Generic;
using LabSharedLibrary;
class ListImplementation<E>{
    List<E> array = new List<E>();

    public void Add(E e){
        array.Add(e);
    }

    public void display(){
        foreach(E e in array){
            Console.WriteLine(e);
        }
    }
}

class Test{
    public static void Main(string[] args){
        Console.WriteLine("Generic class with generic field and method:\n");
        ListImplementation<int> mylist = new ListImplementation<int>();
        Console.WriteLine("Adding elements...");
        mylist.Add(40);
        mylist.Add(30);
        mylist.Add(98);
        Console.WriteLine("Elements of list are:");
        mylist.display();

        PrintName.printName("11");
    }
}