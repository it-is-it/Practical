//WAP that contains
//b) Enums

using LabSharedLibrary;

class Test{
    enum Days {Sun,Mon,Tue,Wed,Thu,Fri,Sat};
    public static void Main(string[] args){
        int weekDayStart = (int)Days.Mon;
        int weekDayEnd = (int)Days.Fri;
        Console.WriteLine("Enums in C#");
        Console.WriteLine("Monday:{0}",weekDayStart);
        Console.WriteLine("Friday:{0}",weekDayEnd);

        PrintName.printName("8b");

    }
}


