package jackson;

import javax.swing.JOptionPane;

public class NumerosPrimosFor {

    public static void main(String[] args) {
        usaFor();
    }
     public static void usaFor(){
		int n = Integer.parseInt(JOptionPane.showInputDialog("Digite um número"));
                JOptionPane.showMessageDialog(null, "Os números apareceram no terminal!");
		for(int i = 0; i < n; i++){
                    int d = 0;
		    for(int j = i; j > 0; j --){
		        if(i % j == 0){
		            d++;
		        }
		    }
		    if(d == 2){
		        System.out.println (i);
                    }
        }
    }
}
