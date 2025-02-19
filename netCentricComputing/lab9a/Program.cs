//9. WAP to illustrate the concept of:
//a) Delegate


using LabSharedLibrary;

class SampleDelegate{
    public delegate void Addnum(int a, int b);
    public delegate void Subnum(int a, int b);

    public void sum(int a, int b){
        Console.WriteLine("The sum of {0} and {1} = {2}",a,b,a+b);
    }
    public void diff(int a, int b){
        Console.WriteLine("the difference of {0} and {1} = {2}",a,b,a-b);
    }

    public static void Main(){
        SampleDelegate obj = new SampleDelegate();
        Addnum del_obj1 = new Addnum(obj.sum);
        Subnum del_obj2 = new Subnum(obj.diff);
        Console.WriteLine("Delegate Implementation\n");
        del_obj1(4,5);
        del_obj2(100,40);

        PrintName.printName("9a");



    }
}