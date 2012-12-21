import java.util.*;
import java.io.*;

public class B {

  public static void main(String[] args) {
    //String[] map = new String[1000000];
    //char[] lets = { '0', '0', '0', '0', '0', 'A' };
    //map[1] = "A";
    //for (int i = 2; i < 1000000; i++) {
    //}



    Scanner in = new Scanner(System.in);
    int n = Integer.parseInt(in.nextLine());

    for (int i = 0; i < n; i++) {
      String line = in.nextLine();
      if (line.matches("R\\d+C\\d+")) {
        int row = Integer.parseInt(line.substring(1, line.indexOf('C')));
        int col = Integer.parseInt(line.substring(line.indexOf('C') + 1, line.length()));
        col--;

        int len = 1;
        int ans = 26;
        while (col < ans) {
          len++;
          ans *= 26;
        }

        System.out.println(row + "<>" + col);
      } else {
        int didx = -1;
        for (int j = 0; j < line.length(); j++) {
          if (line.charAt(j) >= '0' && line.charAt(j) <= '9') {
            didx = j;
            break;
          }
        }

        int[] digs = new int[didx];
        for (int j = 0; j < didx; j++) {
          digs[j] = line.charAt(j) - 'A';
        }
        digs[0]++;

        int answer = 0;
        int pow = 1;
        for (int j = didx - 1; j >= 0; j--) {
          answer += digs[j] * pow;
          pow *= 26;
        }
        answer++;
        System.out.println("R" + line.substring(didx, line.length()) + "C" + answer);
      }
    }

  }
}
