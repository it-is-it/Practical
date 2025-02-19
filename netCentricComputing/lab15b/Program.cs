// WAP
// b) deal with throw keyword in exception handling

using LabSharedLibrary;

class ThrowImplementation{

    public static void Main(){
        int a=25;
        int b=0;
        Console.WriteLine("Throw keyword in Exception Handling.");
        try{
            if(b==0){
                throw new DivideByZeroException("Invalid Division");
                
            }
    
            Console.WriteLine("{0}/{1}:{2}",a,b,a/b);
            
        }
        catch(DivideByZeroException){
            Console.WriteLine("Exception");
        }
        finally{
            PrintName.printName("15b");
        }
    }
}
