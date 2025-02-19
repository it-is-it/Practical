//WAP to demonstrate Indexer in C#:
//a) When index is of int type
//b) When index is of other than int type.
using System.Collections.Generic;
using LabSharedLibrary;

class IntIndexer{
    private string[] names = new string[10];
    public string this[int i]{
        get{
            return names[i];
        }
        set{
            names[i] = value;
        }
    }
}

class StringIndexer{
    private Dictionary<string,string> sounds = new Dictionary<string,string>();
    public string this[string key]{
        get{
            return sounds[key];
        }
        set{
            sounds[key] = value;
        }
    }
}
class IndexerTester{
    public static void Main(string[] args ){

        Console.WriteLine("Indexer with index of integer type");
        IntIndexer members = new IntIndexer();
        members[0] = "Hari";
        members[1] = "Ram";
        members[2] = "Sita";
        members[3] = "Gita";
        members[4] = "Shyam";
        

        for(int i=0;i<5;i++){
            Console.WriteLine(members[i]);
        }

        Console.WriteLine("\nIndexer with index of string type.");
        StringIndexer animals = new StringIndexer();
        animals["Cow"] = "Moo";
        animals["Dog"] = "Bark!";
        
        Console.WriteLine("Cow goes like {0}",animals["Cow"]);
        Console.WriteLine("Dog goes like {0}",animals["Dog"]);

        PrintName.printName("4");

    }
}