//17. WAP to demonstrate asynchronous programming in C# 
// using async and await keywords.

using System.Threading.Tasks;
using LabSharedLibrary;


class AsyncAwaitTest{
    static async Task Main(string[] args){
           Console.WriteLine("Asynchronous Programming.");
           
            Task<String> labno =  Method1(); 
            Method2();
            var result = await labno;

            PrintName.printName(result);
    }

    static async Task<String> Method1(){
       Console.WriteLine("Long Process Started");
       await Task.Delay(2000);
       Console.WriteLine("Long Process Completed");
       return "17";
    } 

    static void Method2(){
    Console.WriteLine("Short Process Started");
    Console.WriteLine("Short Process Completed");
    }
}
