//7. WAP to illustrate the concept of
//c) Multiple inheritance using interface in C#
using LabSharedLibrary;

public interface IHardware {
    void  assembleHardware();

}

public interface ISoftware{
    void installSoftware();

}


public class Device: IHardware,ISoftware   {
    bool hardware_assemble= false;
    bool install_software = false;

    public void assembleHardware(){
        hardware_assemble = true;
        Console.WriteLine("Assembling Hardware...");
    }
     
       public void installSoftware(){
        install_software = true;
        Console.WriteLine("Installing Software...");
    }

    public void IsDeviceReady(){
        if( hardware_assemble && install_software){
             Console.WriteLine("Device is ready.");
        }
        else{
            Console.WriteLine("Device is not ready yet.");
        }

    }

}

class Test{
 public static void Main(string[] args){
    Console.WriteLine("Multiple Inhertiance using interfaces");
    Device phone = new Device();
    phone.assembleHardware();
    phone.IsDeviceReady();
    phone.installSoftware();
    phone.IsDeviceReady();

    PrintName.printName("7c");
 }
}