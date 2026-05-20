class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //感覺可以記有幾個轉折(峰)就好
        if (nums.size() < 2){
            return nums.size();
        }
        int prediff=  nums[1]-nums[0];
        int count;
        if (prediff != 0){
            count = 2;
        }
        else{
            count = 1;
        }//看最開頭兩個是不是一樣的
        for(int i = 2; i<nums.size(); i++){ //前面已經比過所以從index[2]
            int diff = nums[i]-nums[i-1];
            if((prediff <= 0 && diff>0) || (prediff >=0 && diff<0)){ //加等號才能處理相等的東東(平緩)
                count++;
                prediff = diff;
            }
        }
        return count;
     }
};