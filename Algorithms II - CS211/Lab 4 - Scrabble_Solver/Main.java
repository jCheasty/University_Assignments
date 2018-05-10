import java.io.*;
import java.util.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

class valid_words{

    private String word;
    private int score;

    valid_words(String word, int score){

        this.word = word;
        this.score = score;
    }
    public static Comparator<valid_words> compare_score = Comparator.comparingInt(o -> o.score);

    protected void print(){
        System.out.printf("%15s:(%-2s) | ", this.word, this.score);
    }
}

/**
 * Advanced Exercise Brief:
 * Add in more features to make the program more usable for Scrabble,
 * such as specifying letters that MUST be used, thus allowing the word to
 * be connected with another on the board.
 *
 * Class Summary:
 * The purpose of the {@code Main} class is to extract valid words from a modified dictionary
 * for use in a game of Scrabble. The user can specify a space tile or wildcard by inputting
 * an underscore when prompted for their letters. A prefix or/and a suffix can also be used to
 * join eligible words with words already in play.
 * The results table features any valid words of variable lengths which are prioritised by the
 * maximum possible score according to the rules of Scrabble.
 * (See example test cases below code.)
 *
 * @author John Cheasty
 * @version 1.1
 *
 * Updates from version 1.0:
 * -Integrated wildcard functionality.
 * -Added prefix/suffix feature.
 * -Created {@code valid_words} to manage sorting.
 * -Improved output formatting.
 *
 */
public class Main{

    private static final HashMap<Character, Integer> scores = new HashMap<>();

    public static void main(String[] args){

        ArrayList<String> ll = new ArrayList<>();
        try(Stream<String> st = Files.lines(Paths.get("scrabble_dict.txt"))){
            st.forEach(ll::add);
        }
        catch (IOException e){e.printStackTrace();}

        Scanner sc = new Scanner(System.in);
        populate_map();

        String [] arr = ll.toArray(new String[ll.size()]);
        System.out.print("Enter letters(use underscore for a wildcard): ");
        String letters = sc.nextLine();

        System.out.print("Include an active/in play prefix? (y/n): ");
        String pre = "";
        if(sc.nextLine().equals("y")) {
            System.out.print("Enter prefix: ");
            pre= sc.nextLine();
        }

        System.out.print("Include an active/in play suffix? (y/n): ");
        String suf = "";
        if(sc.nextLine().equals("y")) {
            System.out.print("Enter suffix: ");
            suf = sc.nextLine();
        }


        int blanks = letters.length() - letters.replace("_", "").length();
        letters=letters.replace("_","");
        int lim = letters.length()+blanks+pre.length()+suf.length();

        List<List<valid_words>> res = new ArrayList<>(lim);
        for(int i=0; i<lim;++i){
            res.add(new ArrayList<>());
        }

        boolean isEmpty = true;
        for(int i=0; i<arr.length && arr[i].length()<=lim; i++){
            if(isValid(letters, blanks, arr[i], suf, pre)) {
                res.get(arr[i].length() - 2).add(new valid_words(arr[i], getScore(arr[i])));
                isEmpty = false;
            }
        }

        if(isEmpty)
            System.out.println("No matching words could be found.");
        else {
            System.out.println("\nFormatting: *valid word:(score)*");
            valid_words temp;
            for (int i = 0; i < lim; i++) {
                res.get(i).sort(valid_words.compare_score.reversed());
                System.out.print((!res.get(i).isEmpty() ? "\n" + (i + 2) + " letter words: " : ""));
                for (int j = 0; j < res.get(i).size() && j < 5; j++) {
                    temp = res.get(i).get(j);
                    temp.print();
                }
            }
        }
    }

    private static boolean isValid(String letters, int wildcards, String word, String suffix, String prefix){

        boolean valid=true;
        int chr_rem=0;

        if(!prefix.equals("")){
            if(word.length()>prefix.length()) {
                if (prefix.equals(word.substring(0, prefix.length())))
                    word = word.substring(prefix.length());
                else
                    return false;
            }else
                return false;
        }

        if(!suffix.equals("")){
            if(word.length()>suffix.length()) {
                if (suffix.equals(word.substring((word.length()) - suffix.length(), word.length())))
                    word = word.substring(0, word.length() - suffix.length());
                else
                    return false;
            }else
                return false;
        }

        for(int i=0;i<letters.length();i++) {
            for(int j = 0; j < word.length(); j++) {
                if(letters.charAt(i) == word.charAt(j)) {
                    word = word.substring(0, j) + '*' + word.substring(j + 1);
                    break;
                }
            }
        }

        for(int i=0; i<word.length();i++) {
            if (Character.isLetter(word.charAt(i)))
                chr_rem++;
        }
        if(wildcards>=chr_rem)
            return true;

        for(int i=0;i<word.length();i++){
            if(word.charAt(i)!='*')
                valid=false;
        }
        return valid;
    }

    private static int getScore(String word){

        int score=0;
        for(int i=0; i<word.length();i++)
            score+=scores.get(word.charAt(i));
        return score;
    }

    private static void populate_map(){

        scores.put('a',1);
        scores.put('e',1);
        scores.put('i',1);
        scores.put('o',1);
        scores.put('u',1);
        scores.put('l',1);
        scores.put('n',1);
        scores.put('r',1);
        scores.put('s',1);
        scores.put('t',1);
        scores.put('d',2);
        scores.put('g',2);
        scores.put('b',3);
        scores.put('c',3);
        scores.put('m',3);
        scores.put('p',3);
        scores.put('f',4);
        scores.put('h',4);
        scores.put('w',4);
        scores.put('v',4);
        scores.put('y',4);
        scores.put('k',5);
        scores.put('j',8);
        scores.put('x',8);
        scores.put('q',10);
        scores.put('z',10);
    }
}

/*---------------Sample Output--------------------
Test 0:

Enter letters(use underscore for a wildcard): sdreletw
Include an active/in play prefix? (y/n): n
Include an active/in play suffix? (y/n): n

Formatting: *valid word:(score)*

2 letter words:              we:(5 ) |              de:(3 ) |              ed:(3 ) |              el:(2 ) |              er:(2 ) |
3 letter words:             dew:(7 ) |             wed:(7 ) |             ewe:(6 ) |             sew:(6 ) |             tew:(6 ) |
4 letter words:            dews:(8 ) |            drew:(8 ) |            lewd:(8 ) |            weds:(8 ) |            weed:(8 ) |
5 letter words:           dwelt:(9 ) |           rewed:(9 ) |           sewed:(9 ) |           swede:(9 ) |           tewed:(9 ) |
6 letter words:          lewder:(10) |          reweds:(10) |          reweld:(10) |          slewed:(10) |          stewed:(10) |
7 letter words:         lewdest:(11) |         rewelds:(11) |         strewed:(11) |         welders:(11) |         wrested:(11) |
8 letter words:        lewdster:(12) |        wrestled:(12) |



Test 1:

Enter letters(use underscore for a wildcard): adnop___
Include an active/in play prefix? (y/n): n
Include an active/in play suffix? (y/n): n

Formatting: *valid word:(score)*

2 letter words:              ax:(9 ) |              ex:(9 ) |              jo:(9 ) |              ox:(9 ) |              xi:(9 ) |
3 letter words:             zax:(19) |             zek:(16) |             fez:(15) |             fiz:(15) |             pyx:(15) |
4 letter words:            jazz:(29) |            razz:(22) |            hajj:(21) |            fozy:(19) |            hazy:(19) |
5 letter words:           pizza:(25) |           zanza:(23) |           zazen:(23) |           zappy:(21) |           qophs:(19) |
6 letter words:          zapped:(20) |          zonked:(20) |          jalopy:(18) |          judoka:(18) |          podzol:(18) |
7 letter words:         hexapod:(20) |         bandbox:(19) |         madzoon:(19) |         opaqued:(19) |         quondam:(19) |
8 letter words:        expandor:(18) |        pandowdy:(18) |        diaphony:(17) |        downplay:(17) |        playdown:(17) |

Test 2:

Enter letters(use underscore for a wildcard): lo_ra_f
Include an active/in play prefix? (y/n): y
Enter prefix: c
Include an active/in play suffix? (y/n): y
Enter suffix: ing

Formatting: *valid word:(score)*

5 letter words:           cling:(8 ) |           cuing:(8 ) |
6 letter words:          coxing:(16) |          caking:(13) |          coking:(13) |          caving:(12) |          cawing:(12) |
7 letter words:         cozying:(22) |         crazing:(19) |         choking:(17) |         coaxing:(17) |         chafing:(16) |
8 letter words:        calquing:(20) |        chaffing:(20) |        cajoling:(18) |        chalking:(18) |        charking:(18) |
9 letter words:       coffering:(18) |       crackling:(18) |       comparing:(16) |       crankling:(16) |       cavorting:(15) |
10 letter words:      calorizing:(22) |      clarifying:(19) |      coalifying:(19) |      conflating:(16) |      caprioling:(15) |

Test 3:

Enter letters(use underscore for a wildcard): geo__
Include an active/in play prefix? (y/n): y
Enter prefix: zoo
Include an active/in play suffix? (y/n): y
Enter suffix: graphical

Formatting: *valid word:(score)*

15 letter words: zoogeographical:(33) |

Test 4:

Enter letters(use underscore for a wildcard): zzz
Include an active/in play prefix? (y/n): n
Include an active/in play suffix? (y/n): n
No matching words could be found.

*/