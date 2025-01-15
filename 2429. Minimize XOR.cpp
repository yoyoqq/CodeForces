class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // count bits from n2
        int num2bits = 0;
        while (num2 > 0){
            if ((num2 & 1) == 1) num2bits++;
            num2 >>= 1;
        }
        // find x 
        // from num1, take off leftmost bits 
        vector<bool> num1bits(33, 0);
        int idx = 0;
        while (num1 > 0){
            if ((num1 & 1) == 1){
                num1bits[idx] = 1;
            } 
            else num1bits[idx] = 0;
            num1 >>= 1;
            idx++;
        }
        // match bits with num2bits
        vector<bool> numXbits(32, 0);
        for (int i=32; i>=0; i--){
            if (num2bits && num1bits[i]){
                num2bits--;
                numXbits[i] = true;
            }
        }
        // use remaining num2bits
        for (int i=0; i<33; i++){
            if (num2bits && numXbits[i] == false){
                num2bits--;
                numXbits[i] = true;
            }
        }
        // get output 
        int x = 0;
        for (int i=0; i<33; i++){
            // x = x * 2 + (numXbits[i]);
            if (numXbits[i]){
                x += pow(2, i);
            }
        }
        return x;
        
        // for (int i=0; i<33; i++){
        //     cout << num1bits[i] << " " ;
        // }cout << endl;
        // // take off the ones         
        // vector<bool> used(33, 0);
        // for (int i=32; i>=0; i--){
        //     if (num1bits[i] && num2bits){
        //         num1bits[i] = 0;
        //         used[i] = 1;
        //         num2bits--;
        //     }
        // }
        // for (int i=0; i<33; i++){
        //     cout << num1bits[i] << " " ;
        // }cout << endl;
        // // remaining 
        // for (int i=0; i<33; i++){
        //     if (used[i] == 0 && num2bits){
        //         num1bits[i] != num1bits[i];
        //         num2bits--;
        //     }
        // }
        // for (int i=0; i<33; i++){
        //     cout << num1bits[i] << " " ;
        // }
        // // get output 
        // int x = 0;
        // for (int i=0; i<33; i++){
        //     if (num1bits[i]){
        //         x += pow(2, i);
        //     }
        // }
        // return x;
    }
};