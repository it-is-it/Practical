// WAP to illustrate the concept of 
// a) Abstract class 
// b) Interface 
// c) Multiple inheritance using interface in C#
using LabSharedLibrary;
using System;

// (a) Abstract Class
abstract class Animal
{
    // Abstract method (must be overridden in derived class)
    public abstract void MakeSound();

    // Concrete method (already implemented)
    public void Sleep()
    {
        Console.WriteLine("Animal is sleeping...");
    }
}

// (b) Interface
interface IMovable
{
    void Move();  // Method declaration (no implementation)
}

// Another interface for demonstration of multiple inheritance
interface IPlayable
{
    void Play();
}

// (c) Multiple Inheritance using Interface
class Dog : Animal, IMovable, IPlayable
{
    private string name;

    // Constructor
    public Dog(string name)
    {
        this.name = name;
    }

    // Overriding abstract method from Animal class
    public override void MakeSound()
    {
        Console.WriteLine($"{name} barks: Woof! Woof!");
    }

    // Implementing Move() from IMovable interface
    public void Move()
    {
        Console.WriteLine($"{name} runs energetically!");
    }

    // Implementing Play() from IPlayable interface
    public void Play()
    {
        Console.WriteLine($"{name} is playing with a ball!");
    }
}

// Main Program
class Test
{
    public static void Main(string[] args)
    {
        // Creating an object of Dog class
        Dog myDog = new Dog("Buddy");

        // Calling methods
        myDog.MakeSound(); // Overridden method from Animal class
        myDog.Sleep();     // Inherited concrete method from Animal class
        myDog.Move();      // Implemented method from IMovable interface
        myDog.Play();      // Implemented method from IPlayable interface

        PrintName.printName("7");
    }
}
