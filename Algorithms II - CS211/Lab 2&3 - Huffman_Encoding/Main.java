import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {

        //todo: Add checkIfCompressed method to avoid nested compression.
        //todo: Add a UI/UX interface to Main.java

        Huffman.Encode("test_1_small_en.txt");
        Huffman.Decode("test_1_small_en.txt");
    }
}