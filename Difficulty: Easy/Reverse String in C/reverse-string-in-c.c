void reverseString(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    while (left < right) {
        // Swap characters
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        // Move indexes toward the center
        left++;
        right--;
    }
    
    printf(str);
}