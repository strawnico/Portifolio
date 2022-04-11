import java.util.Scanner;
public class Main

{
	public static void main(String[] args) {
		Scanner bofao = new Scanner(System.in);
		System.out.println("Digite um número");
		int n = bofao.nextInt();
		int i = 0;
		while(i < n){
		    int j = i;
		    int d = 0;
		    while(j > 0){
		        if(i % j == 0){
		            d++;
		        }
		        j--;
		    }
		    if(d == 2){
		        System.out.println(i);
		    }
		    i ++;
		}
	}
}
