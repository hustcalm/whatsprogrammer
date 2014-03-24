/**
 * method 1: sort the two strings and compare
 * method 2: count the occurences of each letter
 */

public String sort(String s)
{
    char[] content = s.toCharArray();
    java.util.Arrays.sort(content);
    return new String(content);
}

public boolean permutation1(String s, String t)
{
    if(s.length() != t.length())
        return false;

    return sort(s).equals(sort(t));
}

public boolean permutation2(String s, String t)
{
    if(s.length() != t.length())
        return false;

    int[] letters = new int[256];

    char[] s_array = s.toCharArray();
    for (char c : s_array) {
        letters[c]++;
    }

    for (int i = 0; i < t.length(); i++)
    {
        int c = (int) t.CharAt(i);
        if(--letters[c] < 0) {
            return false;
        }
    }

    return true;
}

