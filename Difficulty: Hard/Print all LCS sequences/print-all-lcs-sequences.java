import java.util.stream.Collectors;
class Solution {
    public List<String> allLCS(String s1, String s2) {
        // Code here
        int l1=s1.length(),l2=s2.length();
        HashSet<String>[][] dp= new HashSet[l1+1][l2+1];
        for(int i=0;i<=l1;i++)
            dp[i][0]=new HashSet<>(Arrays.asList(""));
        for(int i=0;i<=l2;i++)
            dp[0][i]=new HashSet<>(Arrays.asList(""));
        
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                char c1=s1.charAt(i-1),c2=s2.charAt(j-1);
                HashSet<String> currSet=new HashSet<>();
                if(c1==c2){
                    for(String cs:dp[i-1][j-1]){
                        currSet.add(cs+c1);
                    }
                }
                else{
                    int lTop=dp[i-1][j].iterator().next().length();
                    int lLeft=dp[i][j-1].iterator().next().length();
                    int maxN = Math.max(lTop,lLeft);
                    if(maxN==lTop){
                        for(String cs:dp[i-1][j])
                            currSet.add(cs);
                    }
                    if(maxN==lLeft){
                        for(String cs:dp[i][j-1])
                            currSet.add(cs);
                    }
                }
                dp[i][j]=currSet;
            }
        }
        return dp[l1][l2].stream().sorted().collect(Collectors.toList());
    }
}