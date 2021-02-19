import java.util.*;

public class CRC {
	public static int n;
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		CRC crc = new CRC();
		String orig, copy, revData, zero = "0000000000000000";
		System.out.println("Enter message: ");
		orig = in.nextLine();
		n = orig.length();
		copy = orig;
		orig += zero;
		orig = crc.divide(orig);
		System.out.println("\nMessage: " +copy);
		copy = copy.substring(0,n) + orig.substring(n);
		System.out.println("CRC: ");
		System.out.println(orig.substring(n));
		System.out.println("Transmitted data: "+copy);
        System.out.println("\nEnter recieved data: ");
        revData = in.nextLine();
        
        if(zero.equals(crc.divide(revData).substring(n)))
        	System.out.println("\n\nRECIEVED DATA MATCHES :):) ");
        else
        	System.out.println("\n\nRECIEVED DATA CONTAINS ERROR(S) !!!");
        
        in.close();
        }
	
	
	public String divide(String str){
		int i,j;
		char x;
		String div = "10001000000100001";
		
		for(i = 0; i <n; i++){
			x = str.charAt(i);
			
			for(j=0; j <17; j++){
				if(x == '1'){
					if(str.charAt(i+j)!= div.charAt(j))
						str = str.substring(0,i+j)+"1"+str.substring(i+j+1);
					else
						str = str.substring(0,i+j)+"0"+str.substring(i+j+1);
					}
				}
			}
		return str;
		}
}