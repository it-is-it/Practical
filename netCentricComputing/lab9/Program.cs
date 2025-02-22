using System;
using LabSharedLibrary;

// (a) Delegate
delegate void MyDelegate(string message);

// (b) Multicast Delegate
delegate void MultiDelegate();

// (f) Event
class EventPublisher
{
    public delegate void Notify();  // Event Delegate
    public event Notify OnProcessCompleted; // Event declaration

    public void StartProcess()
    {
        Console.WriteLine("Process Started...");
        System.Threading.Thread.Sleep(2000);
        Console.WriteLine("Process Completed!");
        
        // Raise Event
        OnProcessCompleted?.Invoke();
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("\n(a) Single Delegate");
        MyDelegate del = new MyDelegate(DisplayMessage);
        del("Hello, Ishwor!");

        Console.WriteLine("\n(b) Multicast Delegate");
        MultiDelegate multiDel = FirstMethod;
        multiDel += SecondMethod;
        multiDel();  // Calls both methods

        Console.WriteLine("\n(c) Func Delegate");
        Func<int, int, int> addFunc = (x, y) => x + y;
        Console.WriteLine("Sum: " + addFunc(10, 20));

        Console.WriteLine("\n(d) Action Delegate");
        Action<string> printMessage = (msg) => Console.WriteLine("Message: " + msg);
        printMessage("Hello from Action Delegate!");

        Console.WriteLine("\n(e) Anonymous Method");
        MyDelegate anonymousDel = delegate (string msg)
        {
            Console.WriteLine("Anonymous Method says: " + msg);
        };
        anonymousDel("Hi, this is an anonymous method!");

        Console.WriteLine("\n(f) Event in C#");
        EventPublisher publisher = new EventPublisher();
        publisher.OnProcessCompleted += ProcessCompletedHandler;
        publisher.StartProcess();
        PrintName.printName("9");
    }

    static void DisplayMessage(string message)
    {
        Console.WriteLine("Message from Delegate: " + message);
    }

    static void FirstMethod()
    {
        Console.WriteLine("First Method Executed.");
    }

    static void SecondMethod()
    {
        Console.WriteLine("Second Method Executed.");
    }

    static void ProcessCompletedHandler()
    {
        Console.WriteLine("Event Triggered: Process Completed Successfully!");
    }

}
