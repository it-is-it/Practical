//WAP to
// b) to create and use custom attribute in C#.

using LabSharedLibrary;

[AttributeUsage(
    AttributeTargets.Class |
    AttributeTargets.Field |
    AttributeTargets.Method,
    AllowMultiple = true
)]
class DebugInfo : System.Attribute{
    private int bugno;
    private string developer;
    private string lastReview;
    public string message ;

    public DebugInfo(int bg, string dev, string d){
        this.bugno = bg;
        this.developer = dev;
        this.lastReview = d;
    }

    public int BugNo{
        get {return bugno;}
    }

    public string Developer{
        get {return developer;}
    }

    public string LastReview{
        get {return lastReview;}
    }

    public  string Message{
        get {return message;}
        set {message = value;}
    }
}

[DebugInfo(45,"John Doe","12/8/2024",Message ="Unused Variable")]
class Program{
    public int add(int a, int b){
        return a+b;
    }

    [DebugInfo(46,"Robb Stark","13/8/2024",Message ="Return Type mismatch")]
    public int sub(int a, int b){
        return a-b;
    }

    public static void Main(String[] args){
        Console.WriteLine("Custom Attribute");
        Program p = new Program();
        Console.WriteLine($"Addition: {p.add(20, 10)}");
        Console.WriteLine($"Subtraction: {p.sub(20, 15)}");

        PrintName.printName("16b");
    }

    
}