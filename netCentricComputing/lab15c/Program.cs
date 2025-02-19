//WAP to
//c) demonstrate custom exception handling

using LabSharedLibrary;

class MyException: Exception{
    public MyException(string s){
        Console.WriteLine(s);
    }
}

class Program{
    public static void Main(){
        Console.WriteLine("Custom Exception Handling..");
        try{
          throw new MyException("Exception Occured");
        }
        catch(Exception){
            Console.WriteLine("Exception Caught");
        }
        finally{
            PrintName.printName("15c");
        }

    }
}