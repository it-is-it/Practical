//WAP to illustrate 
// f) Event Handling

using System.Security.Cryptography.X509Certificates;
using LabSharedLibrary;

//Declare a delegate
public delegate void Notify();
public class Button{
    //Declare an event
    public event Notify Click;

    public void clickButton(){
        Console.WriteLine("Clicking...");
        Onclick();
    }
    
    //raise an event
    protected virtual void Onclick(){
        Click?.Invoke();
    }


}

public class Test{
    public static void Main(String[] args){
        Console.WriteLine("Event Handling.");
        Button b1 = new Button();
        b1.Click +=ButtonClicked;
        b1.clickButton();
        PrintName.printName("9f");

    }

    //Handling the event
    public static void ButtonClicked(){
        Console.WriteLine("Button Clicked.");
    }
}

