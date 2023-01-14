package CC_221047005;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Scanner;

public class Jdbcmain {
    static Connection connection;
    public static void main(String[] args)throws Exception {
       
        String connectionUrl = "jdbc:sqlserver://172.16.51.44;" +
        "databaseName=221047005;integratedSecurity=false;user=Sadhana;password=sadhana#1";
        connection = DriverManager.getConnection(connectionUrl);    
        String sql="create table prod1"+"(PID integer,Productname varchar(100),Productunitprice float,Quantities integer, PRIMARY KEY(PID))"; 
        PreparedStatement preparedStatement=connection.prepareStatement(sql);
        //Execute the query
        int n=preparedStatement.executeUpdate();
        if(n==1) {
            System.out.println("table not created");
        }
        else {
            System.out.println("table created");
        }
        preparedStatement.close();
        connection.close();

 

        Jdbcimpl p=new Jdbcimpl();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter your choice 1.insert 2.delete 3.display");
        int  n1=sc.nextInt();
        if(n1==1) {
            p.insertvalues();
        }
        else if(n1==2) {
            p.deletevalues();
        }
        else if(n1==3) {
            p.displayval();
        }
    }
}
