package CC_221047005;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

class Jdbcimpl {
    static Connection connection;
void insertvalues() throws SQLException, ClassNotFoundException 
{
    Scanner sc=new Scanner(System.in);
   
    String connectionUrl = "jdbc:sqlserver://172.16.51.44;" +
            "databaseName=221047005;integratedSecurity=false;user=Sadhana;password=sadhana#1";
            connection = DriverManager.getConnection(connectionUrl);   
    String sql="insert into prod1 values (?,?,?,?)"; 
    PreparedStatement pS=connection.prepareStatement(sql);
    System.out.println("Enter PID");
    int pid=sc.nextInt();
    pS.setInt(1, pid);
    System.out.println("Enter Product name");
    String pname=sc.next();
    pS.setString(2,pname);
    System.out.println("Enter Price");
    float price=sc.nextFloat();
    pS.setFloat(3,price);
    System.out.println("Enter Quantity");
    int quantity=sc.nextInt();
    pS.setInt(4,quantity);
    //Execute the query
    int n=pS.executeUpdate();
    if(n==1) {
    System.out.println("record inserted");
    }
    else {
    System.out.println("record not inserted");
    }
    //closing
    pS.close();
    connection.close();
    }
void deletevalues() throws SQLException, ClassNotFoundException{
    Scanner sc=new Scanner(System.in);
        
    String connectionUrl = "jdbc:sqlserver://172.16.51.44;" +
            "databaseName=221047005;integratedSecurity=false;user=Sadhana;password=sadhana#1";
            connection = DriverManager.getConnection(connectionUrl);   
    String sql="Delete from prod1 where PID=?";
    PreparedStatement pS=connection.prepareStatement(sql);
    System.out.println("Enter PID to delete Product");
    int delpid=sc.nextInt();
    pS.setInt(1,delpid);
    int n=pS.executeUpdate();
    if(n==1) {
    System.out.println("deleted");
    }
    else {
        System.out.println("not deleted");
    }
    pS.close();
    connection.close();
}
void displayval() throws SQLException, ClassNotFoundException {
    Scanner sc=new Scanner(System.in);
         
    String connectionUrl = "jdbc:sqlserver://172.16.51.44;" +
            "databaseName=221047005;integratedSecurity=false;user=Sadhana;password=sadhana#1";
            connection = DriverManager.getConnection(connectionUrl);   
    String sql="Select * from prod1";
    PreparedStatement pS=connection.prepareStatement(sql);
    ResultSet resultSet=pS.executeQuery();
    while(resultSet.next()) {
    System.out.println(resultSet.getInt("PID")+" "+resultSet.getString("Productname")+" "+resultSet.getFloat("Productunitprice")+" "+resultSet.getInt("Quantities"));
    }
    resultSet.close();
    pS.close();
    connection.close();
    }
}



