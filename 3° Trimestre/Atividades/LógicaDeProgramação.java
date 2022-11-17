// Atividade que o usuário converta temperatura de Celsius para Fahrenheit e vice versa (ele decide qual será a conversão 
// efetuada através de uma estrutura de decisão e Scanner)

// Escolhi essa atividade porque achei legal de fazer! 

import java.util.Scanner;

public class Ex4 {
    public static void main(String[] args) {
        int decision, number;
        Double conversion;

        Scanner input = new Scanner(System.in);

        System.out.println("Você deseja converter para qual temperatura?\n1 - Celsius\n2 - Fahrenheit");
        decision = input.nextInt();

        if (decision == 1) {
            System.out.println("Que número você deseja converter(número em Fahrenheit)?");
            number = input.nextInt();

            conversion = Double.valueOf(((number-32)*5/9));
            System.out.println(conversion + " celsuius");
        }
        else if (decision == 2) {
            System.out.println("Que número você deseja converter(número em celsius)?");
            number = input.nextInt();

            conversion = (number*1.8+32);
            System.out.println(conversion + " fahrenheit");
        }
        else {
            System.out.println("Essa opção é inválida :(");
        }
    }
}
