import java.io.*;
import java.util.Comparator;
import java.util.HashMap;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

class Huffman{

    private static HashMap<Character, String> ref = new HashMap<>();

    public static void Encode(String file) throws IOException {

        Bin_IO.readFile(file);

        if(Bin_IO.in_buffer ==-1) throw new NoSuchElementException("Reading from empty input stream");

        StringBuilder sb = new StringBuilder();
        while(Bin_IO.in_buffer !=-1){
            char c = Bin_IO.readChar();
            sb.append(c);
        }

        char[] cin = sb.toString().toCharArray();
        int[] freq = new int[256];
        for (char ch : cin)
            freq[ch]++;

        HuffNode root = buildTree(freq);
        buildCodes(root, "");


        try{
            OutputStream os = new FileOutputStream(file);
            Bin_IO.out = new BufferedOutputStream(os);
        }
        catch(IOException e) {
            e.printStackTrace();
        }

        encodeHuffTree(root);
        Bin_IO.writeInt(cin.length);

        for (char c : cin){
            String code = ref.get(c);
            for (int j = 0; j < code.length(); j++){
                if (code.charAt(j) == '0')
                    Bin_IO.writeBit(false);
                else if (code.charAt(j) == '1')
                    Bin_IO.writeBit(true);
                else throw new IllegalStateException("Illegal state");
            }
        }
        Bin_IO.clearOut();
        Bin_IO.out.close();
    }

    public static void Decode(String file) throws IOException{

        Bin_IO.readFile(file);

        try{
            OutputStream os = new FileOutputStream(file);
            Bin_IO.out = new BufferedOutputStream(os);
        }
        catch(IOException e){
            e.printStackTrace();
        }

        HuffNode root = decodeHuffTree();
        int len = Bin_IO.readInt();


        for (int i = 0; i < len; i++) {
            HuffNode h = root;
            while (!h.isLeaf()) {
                boolean bit = Bin_IO.readBoolean();
                if (bit) h = h.right;
                else     h = h.left;
            }
            Bin_IO.writeChar(h.ch);
        }
        Bin_IO.out.flush();
        Bin_IO.out.close();
    }

    private static HuffNode buildTree(int[] freqs){

        PriorityQueue<HuffNode> hq = new PriorityQueue<>(Comparator.comparingInt(h -> h.freq));

        for(int i=0; i<256; ++i) {
            if (freqs[i] > 0) {
                hq.add(new HuffNode((char) i, freqs[i], null, null));
            }
        }

        HuffNode root = null;
        while(hq.size()>1){
            HuffNode a = hq.peek();
            hq.poll();
            HuffNode b = hq.peek();
            hq.poll();
            HuffNode c = new HuffNode('-',a.freq+b.freq,a,b);
            root=c;
            hq.add(c);
        }
        return root;
    }

    private static void buildCodes(HuffNode root, String s){

        if(root.isLeaf())
            ref.put(root.ch, s);
        else{
            buildCodes(root.left, s + "0");
            buildCodes(root.right, s + "1");
        }
    }

    private static void encodeHuffTree(HuffNode root){

        if (root.isLeaf()) {
            Bin_IO.writeBit(true);
            Bin_IO.writeChar(root.ch);
            return;
        }
        Bin_IO.writeBit(false);
        encodeHuffTree(root.left);
        encodeHuffTree(root.right);
    }

    private static HuffNode decodeHuffTree(){

        boolean isLeaf = Bin_IO.readBoolean();
        if (isLeaf) {
            return new HuffNode(Bin_IO.readChar(), 0, null, null);
        }
        else {
            return new HuffNode('-', 0, decodeHuffTree(), decodeHuffTree());
        }
    }
}