public class Main {
	
	public static void main (String []args) {
		int a = 10;
		int b = 5;
		int c = a + b;
		System.out.println("O valor de " + a + " + " + b + " eh " + c);
		
		if (a > b)
			System.out.println("a eh maior que b");
		else
			System.out.println("a naum eh maior que b");
		
		for (int i = 0; i < 10; i++)
			System.out.print(i + " ");
		
		float d = 3.3f;
		float e = 2.711828f;
		
		while (d < 100 && a > b) {
			System.out.println(d);
			d *= e;
		}
	}
}