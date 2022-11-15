import java.util.ArrayList;
import java.util.List;
import java.util.Random;
 
public class Test1 {
    public static void main(String[] args) {
        String[] str={"科特迪瓦","阿根廷","澳大利亚","塞尔维亚","荷兰","尼日利亚","日本",
                "美国","中国","新西兰","巴西","比利时","韩国","喀麦隆","洪都拉斯","意大利"};
        List list=new ArrayList();
        List list1=new ArrayList();
        for(int i=0;i<str.length;i++){
            list.add(str[i]);
        }
        while(true){
            list1.clear();
            while (true) {
                Random random = new Random();
                int index = random.nextInt(list.size());
                Object s = list.get(index);
                list1.add(s);
                list.remove(index);
                if (list1.size() == 4) {
                    for (Object o : list1) {
                        System.out.print(o + " ");
                    }
                    break;
                }
            }
            System.out.println();
            if (list.size() == 0) {
                break;
            }
        }
    }
}