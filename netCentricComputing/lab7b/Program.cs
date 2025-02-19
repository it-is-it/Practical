//7. WAP to illustrate the concept of
//b) Interface
using LabSharedLibrary;

public interface IVehicle{

    void start();
    void stop();
    void check_fuel();

}

public class Car: IVehicle{
      int fuel=0;

      public void start(){
        Console.WriteLine("Starting the car...");
      }

      public void stop(){
        Console.WriteLine("Stopping the car...");
      }

      public void check_fuel(){
        Console.WriteLine("The fuel is {0}",fuel);
      }

      public void add_fuel(){
        fuel=100;
        Console.WriteLine("Filling the fuel...");
      }

}

public class Test{
    public static void Main(string[] args){

        Car car = new Car();
        car.start();
        car.check_fuel();
        car.stop();
        car.add_fuel();
        car.check_fuel();

        PrintName.printName("7b");
    }
}
