//9. WAP to illustrate the concept of:
// c) Func Delegate

using LabSharedLibrary;

class FuncDelegate{
    static int Add(int a, int b){
        return a+b;
    }

    public static void Main(string[] args){
        Func<int,int,int> f = Add;
        Console.WriteLine("Func Delegate in C#.");
        Console.WriteLine("The sum of 2 and 3 is:{0}",f(2,3)); 

        PrintName.printName("9c");
    }
}