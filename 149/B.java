import java.util.*;

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String line = in.nextLine();
    String[] parts = line.split(":");

    parts[0] = parts[0].replaceAll("^0+", "");
    parts[1] = parts[1].replaceAll("^0+", "");

    if (parts[0].length() <= 1 && parts[1].length() <= 1) {
      char c = (parts[0].length() == 0) ? '0' : parts[0].charAt(0);
      char d = (parts[1].length() == 0) ? '0' : parts[1].charAt(0);
      if ((c >= '0' && c <= '9') || (c <= ('A' + 13))) {
        if ((d >= '0' && d <= '9') || (d <= ('A' + 13))) {
          System.out.println(-1);
          return;
        }
      }
    }

    if (parts[0].length() == 0) {
      parts[0] = "0";
    }
    if (parts[1].length() == 0) {
      parts[1] = "0";
    }

    int good = 0;
    for (int i = 2; i < 36; i++) {
      try {
        int h = Integer.parseInt(parts[0], i);
        int s = Integer.parseInt(parts[1], i);

        if (h <= 23 && s <= 59) {
          System.out.print(i + " ");
          good++;
        }
      } catch (Exception e) {
      }
    }

    if (good == 0) {
      System.out.print(0);
    }
    System.out.println();
  }
}
