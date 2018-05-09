import java.io.*;
import java.util.NoSuchElementException;

public class Bin_IO {

    private static BufferedInputStream in;
    protected static BufferedOutputStream out;
    protected static int in_buffer;
    private static int in_count;
    private static int out_buffer;
    private static int out_count;

    protected static void readFile(String file) {
        try{
            File f = new File(file);
            FileInputStream fi= new FileInputStream(f);
            in = new BufferedInputStream(fi);
            populateIn();
        }
        catch(IOException e) {
            System.out.println("File not Found.");
        }
    }

    protected static boolean readBoolean(){
        if (in_buffer ==-1) throw new NoSuchElementException("Reading from empty input stream");
        in_count--;
        boolean bit = ((in_buffer >> in_count) & 1) == 1;
        if (in_count == 0) populateIn();
        return bit;
    }

    protected static char readChar() {
        if (in_buffer ==-1) throw new NoSuchElementException("Reading from empty input stream");

        if (in_count == 8) {
            int x = in_buffer;
            populateIn();
            return (char) (x & 0xff);
        }

        int x = in_buffer;
        x <<= (8 - in_count);
        int oldN = in_count;
        populateIn();
        if (in_buffer ==-1) throw new NoSuchElementException("Reading from empty input stream");
        in_count = oldN;
        x |= (in_buffer >>> in_count);
        return (char) (x & 0xff);
    }

    protected static int readInt() {
        int x = 0;
        for (int i = 0; i < 4; i++) {
            char c = readChar();
            x <<= 8;
            x |= c;
        }
        return x;
    }

    protected static void writeBit(boolean b){
        out_buffer <<=1;
        if(b){ out_buffer |= 1;}
        out_count++;
        if(out_count ==8){
            clearOut();
        }
    }

    protected static void writeChar(char ch){
        if(ch>=256) throw new IllegalArgumentException("Character not recognised.");
        writeByte(ch);
    }

    protected static void writeInt(int i){
        writeByte((i >>> 24) & 0xff);
        writeByte((i >>> 16) & 0xff);
        writeByte((i >>>  8) & 0xff);
        writeByte((i) & 0xff);
    }

    private static void writeByte(int x){

        if (out_count == 0) {
            try {
                out.write(x);
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return;
        }

        for (int i = 0; i < 8; i++) {
            boolean bit = ((x >>> (8 - i - 1)) & 1) == 1;
            writeBit(bit);
        }
    }

    private static void populateIn(){
        try{
            in_buffer = in.read();
            in_count =8;
        }
        catch (IOException e){
            System.out.println("End of File.");
            in_buffer = -1;
            in_count =-1;
        }
    }

    protected static void clearOut() {
        if (out_count == 0) return;
        if (out_count > 0) out_buffer <<= (8 - out_count);
        try {
            out.write(out_buffer);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        out_count = 0;
        out_buffer = 0;
    }
}
