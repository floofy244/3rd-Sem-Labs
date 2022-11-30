import java.io.*;
import java.util.*;

class FileOperation
{
    public void WriteStudentDetails()
    {
        try
        {
            FileWriter fw = new FileWriter("student.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the number of students: ");
            int n = sc.nextInt();
            for(int i=0; i<n; i++)
            {
                System.out.println("Enter the name of the student: ");
                String name = sc.next();
                System.out.println("Enter the roll number of the student: ");
                int roll = sc.nextInt();
                System.out.println("Enter the OOPS mark of the student: ");
                int mark = sc.nextInt();
                pw.println(name + " " + roll + " " + mark);
            }
            pw.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
    public void ReadStudentDetails()
    {
        try
        {
            FileReader fr = new FileReader("student.txt");
            BufferedReader br = new BufferedReader(fr);
            String line;
            while((line = br.readLine()) != null)
            {
                String[] arr = line.split(" ");
                int mark = Integer.parseInt(arr[2]);
                if(mark > 80)
                {
                    System.out.println("Name: " + arr[0]);
                    System.out.println("Roll number: " + arr[1]);
                    System.out.println("OOPS mark: " + arr[2]);
                }
            }
            br.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}

class Thread1 extends Thread
{
    FileOperation f;
    Thread1(FileOperation f)
    {
        this.f = f;
    }
    public void run()
    {
        f.WriteStudentDetails();
    }
}

class Thread2 extends Thread
{
    FileOperation f;
    Thread2(FileOperation f)
    {
        this.f = f;
    }
    public void run()
    {
        f.ReadStudentDetails();
    }
}

public class sum
{
    public static void main(String[] args)
    {
        FileOperation f = new FileOperation();
        Thread1 t1 = new Thread1(f);
        Thread2 t2 = new Thread2(f);
        t1.start();
        t2.start();
    }
}
