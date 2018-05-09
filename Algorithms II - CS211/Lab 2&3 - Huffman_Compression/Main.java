/*The advanced programming challenge is to finish your algorithm off by creating a
real viable compressor application which reads in a file and compresses it into a
smaller file. You will have to store the translation table in the compressed file in
order to be able to decompress it, and store the 1s and 0s as true binary, rather than
ASCII symbols!*/


import java.io.File;
import java.io.IOException;
import java.util.Objects;

public class Main {

    public static void main(String[] args) throws IOException {

        File dir = new File("tests");

        if (dir.isDirectory()) {
            for (final File f : Objects.requireNonNull(dir.listFiles()))
                    getReport(f.toString());
        }
    }

    private static void getReport(String filepath) throws IOException {

        System.out.println("\n------------------------------");
        File test0 = new File(filepath);
        System.out.println("Testing: "+filepath);
        long olen = test0.length();
        System.out.println("Original File Length: "+olen+" bytes.");
        Huffman.Encode(filepath);
        long clen = test0.length();
        System.out.println("Compressed File Length: "+clen+" bytes.");
        if(clen>=olen)
            System.out.println("No Space Improvement");
        else
            System.out.println(100-(long)((float)clen/olen*100)+"% Space Improvement");
        Huffman.Decode(filepath);
        System.out.println("------------------------------\n");
    }
}

/*----------------Sample Output-----------------

Testing: tests/test_2_fr_long_seg.txt
Original File Length: 3869 bytes.
Compressed File Length: 2110 bytes.
46% Space Improvement

Testing: tests/test_3_de_long_seg.txt
Original File Length: 4103 bytes.
Compressed File Length: 2280 bytes.
45% Space Improvement

Testing: tests/test_4_warOfTheWorlds_Chap1.txt
Original File Length: 12674 bytes.
Compressed File Length: 6978 bytes.
45% Space Improvement

Testing: tests/test_0_en_long_nonseg.txt
Original File Length: 2817 bytes.
Compressed File Length: 1610 bytes.
43% Space Improvement

Testing: tests/test_1_small_en.txt
Original File Length: 17 bytes.
Compressed File Length: 23 bytes.
No Space Improvement
------------------------------------------------*/