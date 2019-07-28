public class LabelBreak {
    public static void main (String[] args) {
        int cnt = 0;
        //label:
        out:
        for(int i = 0; i < 10; ++i) {
            for(int j = 0; j < 10; ++j) {
                if(i == 1) {
                    break out; //break label;
                }
                ++cnt;
            }
        }
        System.out.println(cnt);
        //output : 10
    }
}
