import java.nio.file.Paths;
import java.util.Scanner;
import java.io.PrintWriter;

public class FileIO {
    public static void main(String[] args) {
        try {
            //may throuw FileNotFoundException
            Scanner in = new Scanner(Paths.get("in.txt"), "utf-8");
            while(in.hasNext()) {
                System.out.println(in.next());
            }
            in.close();
            /*output
                first line!
                second line!
                ...
            */

            //may throuw FileNotFoundException
            PrintWriter writer = new PrintWriter("out.txt", "utf-8");
            writer.write("test file output\n");
            for (int i = 0; i < 6; ++i) {
                writer.append(i + "\n");
            }
            writer.flush();
            writer.close();
            System.out.println("write to 'out.txt' success.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
