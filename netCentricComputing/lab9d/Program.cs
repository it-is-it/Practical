// WAP to illustrate concept of
// d) Action Delegate

using System.Net;
using LabSharedLibrary;

class ActionDelegate{
    static void Sub(int a, int b){
        Console.WriteLine("The difference of {0} and {1} is {2}",a,b,a-b);
    }

    public static void Main(string[] args){
        Action<int,int> a = Sub;
        Console.WriteLine("Action Delegate..");
        a(7,3);

        PrintName.printName("9d");
    }
}