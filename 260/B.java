import java.util.*;

public class B {
  public static void main(String[] args) {
    HashMap<String, Integer> eod = new HashMap();

    int[] dom = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    Scanner in = new Scanner(System.in);
    String s;
    s = in.nextLine();

    for (int i = 0; i <= s.length() - 10; i++) {
      String t = s.substring(i, i + 10);
      if (t.matches("\\d\\d-\\d\\d-\\d\\d\\d\\d")) {
        String[] parts = t.split("-");
        int day = Integer.parseInt(parts[0]);
        int mon = Integer.parseInt(parts[1]);
        int year = Integer.parseInt(parts[2]);

        if (year < 2013 || year > 2015) {
          continue;
        }

        if (mon < 1 || mon > 12) {
          continue;
        }

        mon--;
        if (day < 1 || day > dom[mon]) {
          continue;
        }

        //System.out.println(">" + t);

        if (eod.get(t) == null) {
          eod.put(t, 1);
        } else {
          eod.put(t, eod.get(t) + 1);
        }
      }
    }

    String best = "";
    int cnt = 0;

    for (Map.Entry<String, Integer> entry : eod.entrySet()) {
      String key = entry.getKey();
      int value = entry.getValue().intValue();

      if (value > cnt) {
        best = key;
        cnt = value;
      }
    }

    System.out.println(best);
  }
}
