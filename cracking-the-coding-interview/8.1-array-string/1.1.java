/**
 * method 1: use additional array to store a mark
 * method 2: use bit vector to store a mark
 * method 3: naive for O(n^2), compare each two charecters
 * method 4: use in-place sort, like quicksort, then compare
 */

/**
 * suppose that we got 256 characters
 */
public boolean isUniqueChars1(String str)
{
    if (str.length() > 256) return false;

    boolean[] char_set = new boolean[256];
    for (int i = 0; i < str.length(); i++)
    {
        int val = str.charAt(i);
        if (char_set[val]) {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

/**
 * suppose we just got 26 lower case characters
 * namely the English alphabet 
 */
public boolean isUniqueChars2(String str)
{
    if(str.length() > 26) return false;

    int checker = 0;
    for (int i = 0; i < str.length(); i++)
    {
        int val = str.charAt(i);
        if((checker & (1 << val)) > 0)
        {
            return false;
        }

        checker |= 1 << val;
    }

    return true;
}

public boolean isUniqueChars3(String str)
{
    if(str.length() > 256) return false;

    for (int i = 0; i < str.length() - 1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if(str.charAt(i) == str.charAt(j))
                return false;
        }
    }
    
    return true;
}

public boolean isUniqueChars4(String str)
{
    if(str.length() > 256) return false;

    //java.util.quicksort str
    //

    for (int i = 0; i < str.length() - ; i++)
    {
        if(str.charAt(i) == str.charAt(i+1))
            return false;
    }

    return true;
}

