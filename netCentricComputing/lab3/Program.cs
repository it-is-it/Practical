//WAP to demonstrate jagged array.

using LabSharedLibrary;

class JaggedArray{


    public static void Main(string[] args){

        //initialize array
        int[][] my_arr = new int[4][];
        my_arr[0] = new int[1]{0};
        my_arr[1] = new int[2]{0,1};
        my_arr[2] = new int[3]{0,1,2};
        my_arr[3] = new int[4]{0,1,2,3};
        
        Console.WriteLine("Jagged Array");

        //print array
        for( int i=0;i<my_arr.Length;i++){
            Console.Write("Row {0}: ",i);
            for(int j=0;j<my_arr[i].Length;j++){
                Console.Write("{0} ",my_arr[i][j]);
            }
            Console.WriteLine();
        }

        //print name
        PrintName.printName("3");
    }
}