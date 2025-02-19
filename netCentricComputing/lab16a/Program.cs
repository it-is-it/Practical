//16. WAP
//a) to use built-in attributes in C#.


using LabSharedLibrary;

class Program{
     
    [Obsolete("Deprecated method",false)]
    public void oldmethod(){
        Console.WriteLine("Old method");

    }
    public void newmethod(){
        Console.WriteLine("New method");

    }

    public static void Main(string[] args){
        Program P = new Program();
        Console.WriteLine("Built-In Attribute Obsolete.");
        P.oldmethod();
        P.newmethod();

        PrintName.printName("16a");
    }
}
