import java.util.*;
import java.io.*;


class SalesMan extends HumanBeing implements Worker{

    static {
        System.loadLibrary("SalesMan");
    }
    
public native int my_dijkestras(int dist[][],int num_cities,int src,int dst);
    
public int doWork(){
    int num_cities = 6;
    int src = 0;
    int dst = 4;
    int shortest_distance;
    
    int distances[][] =
    {
        {0,4,0,8,0},
        {4,0,3,0,0},
        {0,3,0,4,0},
        {8,0,4,0,7},
        {0,0,0,7,0}
    };
    
    System.out.println("Source : "+ src);
    System.out.println("Destination : "+ dst);
    
    if((src<0)||(src>num_cities)){
        System.out.println("Invalid Source");
        return 0;
    }else if(dst>num_cities){
         System.out.println("Invalid Destination");
        return 0;
    }else{
        return new SalesMan().my_dijkestras(distances,num_cities,src,dst);
    }
    
}


public static void main(String[] args) {
    int shortest_distance;
    SalesMan salesmanref = new SalesMan();
    shortest_distance = salesmanref.doWork();
    System.out.println("Shortest Distance : "+ shortest_distance);
}

}
