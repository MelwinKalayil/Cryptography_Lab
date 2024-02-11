import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;


public class AES {

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n------- Melwin Biju Kalayil [21BCE3295] -------");

        System.out.print("\nEnter text: ");
        String plainText = scanner.nextLine();
        
        System.out.print("\nEnter key of 32 Length (hexadecimal): ");
        String key = scanner.nextLine();
        
        byte[] textBytes = plainText.getBytes("UTF8");
        byte[] keyBytes = hexStringToByteArray(key); 
        
        
        SecretKeySpec secretKeySpec = new SecretKeySpec(keyBytes, "AES");
        
        
        Cipher cipher = Cipher.getInstance("AES/ECB/PKCS5Padding");
        
        
        cipher.init(Cipher.ENCRYPT_MODE, secretKeySpec);
        byte[] eBytes = cipher.doFinal(textBytes);
        String eHex = bytesToHex(eBytes);
        System.out.println("\nEncrypted: " + eHex);
        
        
        cipher.init(Cipher.DECRYPT_MODE, secretKeySpec);
        byte[] dBytes = cipher.doFinal(eBytes);
        String dText = new String(dBytes, "UTF8");
        System.out.println("\nDecrypted: " + dText);
        
        scanner.close();
      }
      
      
      private static String bytesToHex(byte[] bytes) {
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
          sb.append(String.format("%02X", b));
        }
        return sb.toString();  
      }
      
      private static byte[] hexStringToByteArray(String s) {
        int len = s.length();
        byte[] data = new byte[len / 2];
        for (int i = 0; i < len; i += 2) {
          data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
          + Character.digit(s.charAt(i+1), 16));
        }
        return data;
      }
    }
