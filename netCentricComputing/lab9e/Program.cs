// WAP to illustrate :
// e) Anonymous method

using LabSharedLibrary;

class AnonymousMethod{
   public delegate void MyDelegate(string message);

   public static void Main(string[] args){
            MyDelegate delg = delegate(string message){
                Console.WriteLine(message);


            };
            Console.WriteLine("Anonymous Method..");
            delg.Invoke("Hello World!");

            PrintName.printName("9e");

   }
}