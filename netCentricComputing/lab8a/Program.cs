//8. WAP program that contains:
//a) Structure (struct)
using LabSharedLibrary;


public struct Book{
    public string title;
    public float price;
    public string author;


    public void display(){
        Console.WriteLine("Title: {0}\nAuthor: {1}\nPrice:{2}",title,author,price);
    }
}

class Test{
    public static void Main(string[] args){
        Console.WriteLine("Structure Implementation.");
        Book book;
        book.title = "NCC";
        book.author = "Ram Prasad";
        book.price = 200;

        book.display();
        PrintName.printName("8a");
    }
}
