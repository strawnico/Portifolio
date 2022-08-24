package matriz;
public class Matriz {

    public static void main(String[] args) {
        int [][] matriz = {{1,2,3},{4,5,6},{7,8,9}};
        for(int linha = 0; linha < 3; linha++){
            for(int coluna =0; coluna < 3; coluna++){
                System.out.print(matriz[linha][coluna]+ "  ");
            } 
            System.out.println();
        }
        determinante(matriz);
    }
    public static void determinante(int[][] matriz) {
        int resultado = (  (matriz[0][0]*matriz[1][1]*matriz[2][2])+
                           (matriz[0][1]*matriz[1][2]*matriz[2][0])+
                           (matriz[0][2]*matriz[1][0]*matriz[2][1]))-
                        (  (matriz[2][0]*matriz[1][1]*matriz[0][2])+
                           (matriz[2][1]*matriz[1][2]*matriz[0][0])+
                           (matriz[2][2]*matriz[1][0]*matriz[0][1]));
                   
            System.out.println("A determinante dessa matriz é: "+ resultado);
    }
}
