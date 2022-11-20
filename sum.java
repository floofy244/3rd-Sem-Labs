// take integer input from user until -1 is pressed and display sum

import java.util.Scanner;

public class sum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        int n = sc.nextInt();
        while (n != -1) {
            sum += n;
            n = sc.nextInt();
        }
        System.out.println(sum);
    }
}
