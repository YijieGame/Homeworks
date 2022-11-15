public class Book implements Comparable{  
    String name;  
    double price;  
 public Book(String name,double price) {  
 this.name=name;  
 this.price=price;  

  
 }  
    public int compareTo(Object b) {  
         Book book=( Book)b;  
        return (int) (this.price-book.price);  

          
    }     
} 
import java.util.Collections;  
import java.util.Iterator;  
import java.util.LinkedList;  

import java.util.List;  
  
public class Main {
	public static void main(String[] args) {  
	    List<Book>list=new LinkedList<Book>();  

	    list.add(new Book("Java",25));  
	    list.add(new Book("数据库技术",30));  
	    list.add(new Book("C++",29));  
	    Book book1=new Book("计算机网络技术",29);  

	    Iterator<Book> it=list.iterator();//通过迭代器读取书名  
	   System.out.println("新书：计算机网络技术与下列图书：");  
	    while(it.hasNext()){  
	        Book book=it.next();  

	        if(book1.price==book.price)//比较两书的价格  
	        System.out.println(book.name);  
	    }  
	      
	      System.out.println("具体价格为："+book1.price);  
	  }  
	}  
 