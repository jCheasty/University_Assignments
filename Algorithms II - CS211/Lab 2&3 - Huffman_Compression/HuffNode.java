public class HuffNode{

    protected char ch;
    protected int freq;
    protected HuffNode left;
    protected HuffNode right;

    HuffNode(char ch, int freq, HuffNode left, HuffNode right){

        this.ch=ch;
        this.freq=freq;
        this.left=left;
        this.right=right;
    }

    public boolean isLeaf(){
        return(left==null && right==null);
    }
}