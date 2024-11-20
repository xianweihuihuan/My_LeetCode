int lengthOfLongestSubstring(char* s) {
    if(s[0]=='\0'){
        return 1;
    }
    int max = 0;
    int fast = 0;
    int slow  = 0;
    int tmp = 0;
    while(s[fast]!='\0'){
        fast++;
        int i =slow;
        for(;i<fast;i++){
            if(s[i]==s[fast]){
                tmp = fast - slow;
                slow = fast;
                break;
            }
            if(tmp>max){
                max = tmp;
            }
        }
    }
    return  max;
}