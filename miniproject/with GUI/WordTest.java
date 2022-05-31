
import java.io.BufferedReader;
import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

/**
 * All the operations about the word
 * 
 */
public class WordTest {
    /**
     * the key word to be guess
     */
    private String keyWord;
    /**
     * the list of valid words
     */
    private ArrayList<String> wordlist = new ArrayList<>();
    /**
     * the colors of a word
     */
    private java.awt.Color[] colors = new java.awt.Color[5];

    /**
     * while it is initialized
     * it reads a .csv file which contains the words get by the Spider wordlist.py
     * get from https://www.wordunscrambler.net/word-list/wordle-word-list
     * 
     */
    WordTest() {
        try (BufferedReader br = Files.newBufferedReader(Paths.get("wordlist.csv"))) {
            String word;
            while ((word = br.readLine()) != null) {
                wordlist.add(word);
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }

    }

    /***
     * find the whether it is a valid word
     * 
     * @param guess the input guess
     * @return whether it is a valid word
     */
    public boolean isValid(String guess) {
        String s = guess.trim().toLowerCase();
        for (String word : wordlist) {
            if (s.equals(word)) {
                return true;
            }
        }
        return false;
    }

    /**
     * return the key word
     * 
     * @return keyword
     */
    public String getKeyword() {

        return keyWord;
    }

    /**
     * to get a random keyword
     */
    public void setKeyword() {
        int index = (int) (Math.random() * wordlist.size());
        keyWord = wordlist.get(index).trim().toUpperCase();
        System.out.print("\n\n\nkey word is " + keyWord + "\n\n\n");
    }

    /**
     * compare the guess word and the key word
     * then call the printguess() to print the feedback
     * 
     * @param guess the string "guess"
     * @return the boolean
     */
    public boolean compare(String guess) {

        if (guess.equals(keyWord)) {
            for (int i = 0; i < 5; i++) {
                colors[i] = java.awt.Color.GREEN;
            }
            return true;
        } else {
            for (int i = 0; i < 5; i++) {
                char c = guess.charAt(i);
                if (c == keyWord.charAt(i)) {
                    colors[i] = (java.awt.Color.GREEN);
                } else if (keyWord.indexOf(c) != -1) {
                    colors[i] = (java.awt.Color.ORANGE);
                } else {
                    colors[i] = (java.awt.Color.GRAY);
                }
            }

        }
        return false;

    }

    /**
     * get the colors of the input word
     * 
     * @return color[]
     */
    public java.awt.Color[] getColors() {
        return colors.clone();
    }

}
